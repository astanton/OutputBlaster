# OutputBlaster
Open source project to add output support to various arcade games for use with Mamehooker (hopefully other apps too)

Credits: Aaron Giles who originally wrote the MAME output code & Supermodel Emulator for use of output code

This code uses GNU GENERAL PUBLIC LICENSE & License is supplied.

Currently supports TeknoParrot Emulator

To use: Place OutputBlaster.dll in game folder and Enable Outputs in game settings (with TeknoParrot)

# Fork Information
This fork is designed to make necessary changes to get outputs working with [Back Force Feeder](https://github.com/njz3/vJoyIOFeederWithFFB) out of the box, without having to use anything like mamehooker.

In order for that to happen, the outputs have to be something that works directly with BFF.  The following outputs work directly with it:

- OutputLampStart
- OutputLampRed
- OutputLampBlue
- OutputLampWhite
- OutputLampGreen
- OutputLampLeader

Since these work directly with it, this fork will be adjusting the existing outputs to those values instead.

# Game specific setup

### Project R
This game will have to be running OutputBlaster in tandem with [my fork of FFBArcadePlugin](https://github.com/astanton/FFBArcadePlugin)

The reason for this is that FFB Arcade Plugin is used to inject OutputBlaster into Project R.

The following files will have to be added to the Project R game directory for outputs to work:

- FFBPlugin.ini
- d8input.dll
- OutputBlaster.dll
- OutputBlaster.ini
- SDL2.dll

After placing them in the folder, rename `d8input.dll` to `winmm.dll`.

Additionally, the game directory must not be in a directory that requires admin access (ie. Program Files).