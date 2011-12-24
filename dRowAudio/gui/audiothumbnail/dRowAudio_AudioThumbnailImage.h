/*
  ==============================================================================
  
  This file is part of the dRowAudio JUCE module
  Copyright 2004-12 by dRowAudio.
  
  ------------------------------------------------------------------------------
 
  dRowAudio can be redistributed and/or modified under the terms of the GNU General
  Public License (Version 2), as published by the Free Software Foundation.
  A copy of the license is included in the module distribution, or can be found
  online at www.gnu.org/licenses.
  
  dRowAudio is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
  A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
  
  ==============================================================================
*/

#ifndef __DROWAUDIO_AUDIOTHUMBNAILIMAGE_H__
#define __DROWAUDIO_AUDIOTHUMBNAILIMAGE_H__

#include "../../audio/dRowAudio_AudioFilePlayer.h"

//==============================================================================	
/** A class to display the waveform of an audio file.
	
	This will load an audio file and display its waveform. Clicking on the waveform will
	reposition the transport source. You can change the file loaded by the associated 
	AudioFilePlayer by dragging a new file onto the display.
 */
class AudioThumbnailImage : public Timer,
                            public TimeSliceClient,
                            public AudioFilePlayer::Listener
{
public:
    //==============================================================================	
    /**
		Creates the display.
		The file player associated with the display must be passed in.
		To save on the number of threads in your program you can optionally pass in your own
		AudioThumbnailCache. If you pass in your own the caller is responsible for deleting it,
		if not the PositionableWaveform will create and delete its own when not needed.	 
	 */
	explicit AudioThumbnailImage (AudioFilePlayer* sourceToBeUsed,
                                  TimeSliceThread& backgroundThread,
                                  AudioThumbnailCache* cacheToUse = nullptr,
                                  AudioThumbnail* thumbnailToUse = nullptr,
                                  int sourceSamplesPerThumbnailSample = 512);
	
	/** Destructor. */
	~AudioThumbnailImage ();
	
	//====================================================================================
    /** Returns the whole waveform image.
     */
    Image getImage ()                       {   return waveformImage;   }
    
    /** Returns a section of the image at a given time for a given duration.
     */
    Image getImageAtTime (double startTime, double duration);
    
    /** Sets the image resolution in lines per pixel.
     */
    void setResolution (double newResolution);
    
    /** Returns the AudioFilePlayer currently being used.
     */
    AudioFilePlayer* getAudioFilePlayer()   {   return filePlayer;  }
    
    /** Returns true if the Image has finished rendering;
     */
    bool hasFinishedLoading()               {   return renderComplete;  }
    
	//====================================================================================
	/** @internal */
    void resized ();
	
	/** @internal */
	void paint (Graphics &g);

	//====================================================================================
	/** @internal */
	void timerCallback ();
    
	/** @internal */
    int useTimeSlice();
    
	/** @internal */
	void fileChanged (AudioFilePlayer *player);
    
    //==============================================================================
    /** A class for receiving callbacks from an AudioThumbnailImage.
        These are called from the internal buffering thread so be sure to lock the
        message manager if you intend to do any graphical related stuff with the Image.
	 
        @see AudioThumbnailImage::addListener, AudioThumbnailImage::removeListener
	 */
    class  Listener
    {
    public:
        //==============================================================================
        /** Destructor. */
        virtual ~Listener() {}
		
        //==============================================================================
        /** Called when the source file changes and the image starts rendering.
		 */
        virtual void imageChanged (AudioThumbnailImage* audioThumbnailImage) {}
		
        /** Called when the the image is updated.
            This will be continuously called while thewaveform is being generated.
		 */
        virtual void imageUpdated (AudioThumbnailImage* audioThumbnailImage) {}
        
        /** Called when the the image has finished rendering.
            If you are using a scaled version of the Image it might be worth caching 
            your own copy to avoid having to rescale it each time.
         */
        virtual void imageFinished (AudioThumbnailImage* audioThumbnailImage) {}
    };
	
    /** Adds a listener to be notified of changes to the AudioThumbnailImage. */
    void addListener (Listener* listener);
	
    /** Removes a previously-registered listener. */
    void removeListener (Listener* listener);
	    
private:
	//==============================================================================	
	void refreshWaveform();
	
	AudioFilePlayer* filePlayer;
	double fileLength, oneOverFileLength, currentSampleRate, oneOverSampleRate;
	
	// thumbnail classes
    TimeSliceThread& backgroundThread;
	OptionalScopedPointer<AudioThumbnailCache> audioThumbnailCache;
	OptionalScopedPointer<AudioThumbnail> audioThumbnail;
    int sourceSamplesPerThumbnailSample;
	
	Image waveformImage, tempSectionImage;
	
    double lastTimeDrawn, resolution;
    bool renderComplete;
    
    ListenerList <Listener> listeners;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioThumbnailImage);
};

#endif  // __DROWAUDIO_AUDIOTHUMBNAILIMAGE_H__