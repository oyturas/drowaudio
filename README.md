# dRowAudio - A JUCE module for high level audio application development.

dRowAudio is a 3rd party JUCE module designed for rapid audio application development. It contains classes for audio processing and gui elements. Additionally there are several wrappers around 3rd party libraries including cURL, FFTReal and SoundTouch. dRowAudio is written in the strict JUCE style, closely following the style guide set out at [JUCE Coding Standards][1].

dRowAudio is hosted on Github at [https://github.com/drowaudio/drowaudio][2]

The online documentation is at [http://drowaudio.co.uk/docs/][3]

A wiki with feature overview and demo screenshots can be found at [http://www.rawmaterialsoftware.com/wiki/index.php/DRowAudio][4]

## Platforms

All platforms supported by JUCE are also supported by dRowAudio. Currently these
platforms include:

- **Windows**: Applications and VST/RTAS/NPAPI/ActiveX plugins can be built 
using MS Visual Studio. The results are all fully compatible with Windows
XP, Vista or Windows 7.

- **Mac OS X**: Applications and VST/AudioUnit/RTAS/NPAPI plugins with Xcode.

- **GNU/Linux**: Applications and plugins can be built for any kernel 2.6 or
later.

- **iOS**: Native iPhone and iPad apps.

- **Android**: Supported.

## Prerequisites

This documentation assumes that the reader has a working knowledge of JUCE.

## External Modules

In order to use the cURL classes you will need to link to the cURL library. This is included as part of Mac OSX, for Windows there pre-built 32-bit binaries or you can download the library yourself for the most recent version. Instructions for linkage are detailed on the [dRowAudio wiki][4].

Although some aspects of dRowAudio rely on other 3rd party modules such as [SoundTouch][5] and [FFTReal][6], these are included as part of the module so no external linking is required. Their use should be transparent to the user.

## Integration

dRowAudio requires recent versions of JUCE. It won't work with versions 2.20 or
earlier. To use the library it is necessary to first download JUCE to a
location where your development environment can find it. Or, you can use your
existing installation of JUCE.

To use the module simply include it, or a symbolic link to it, in your juce/modules folder. Simply them run the Introjucer as normal and tick the dRowAudio module. Config flags are provided to disable some functionality if not required.

## License

Copyright (C) 2010 by David Rowland ([e-mail][0])

Unless otherwise marked, files in dRowAudio are published under the [GNU General
Public License v2][7]. A copy of the licence is contained within each source file.
Commercial licences are available on request please [contact][0] the author for details.

[0]: mailto:dave@drowaudio.co.uk "David Rowland (Email)"
[1]: http://www.rawmaterialsoftware.com/wiki/index.php/Coding_Standards
[2]: https://github.com/drowaudio/drowaudio
[3]: http://drowaudio.co.uk/docs/
[4]: http://www.rawmaterialsoftware.com/wiki/index.php/DRowAudio
[5]: http://www.surina.net/soundtouch/index.html
[6]: http://ldesoras.free.fr/prod.html
[7]: http://www.gnu.org/licenses/gpl-2.0.html