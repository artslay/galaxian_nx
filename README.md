# Galaxy on Fire — Nintendo Switch Port

A Nintendo Switch port of the Android version of **Galaxy on Fire**, running on Godot 4.7.

This project is an unofficial fan-made Nintendo Switch port. It loads the original Android engine libraries and provides the required compatibility layer for running them on Nintendo Switch.

## How to install

Create the following folder on your SD card:

```text
/switch/galaxian_nx/
```

Place:

```text
galaxian_nx.nro
libgodot_android.so
libc++_shared.so
config.txt
assets/project.binary...
save/content
save/install.cfg
```

The Android libraries and game data must be obtained from the original Android version.

## Obtaining the game files

APK can be obtained from:

https://github.com/TheWWWorm/galaxian

Download the appropriate APK and launch it at least once on an Android device or Android emulator.

Extract:

```text
content/
install.cfg
```

and copy them to:

```text
/switch/galaxian_nx/save/
```

These files are required to obtain the game data hash.

Original game content is not included in this repository.

## Controls

| Nintendo Switch | Godot         |
| --------------- | ------------- |
| A               | A             |
| B               | B             |
| X               | X             |
| Y               | Y             |
| L               | L1            |
| R               | R1            |
| L3              | L3            |
| R3              | R3            |
| ZL              | Left Trigger  |
| ZR              | Right Trigger |
| Left Stick      | Left Analog   |
| Right Stick     | Right Analog  |
| D-Pad           | D-Pad         |
| +               | Start         |
| -               | Back          |

Default configuration:

```text
deadzone 18
touch_controls 0
```

## Configuration

`config.txt`:

```text
screen_width 1280
screen_height 720
deadzone 18
assetpack 1
enable_vulkan 1
touch_controls 0
rendering_method mobile
```

## Resolution

Default resolution:

```text
1280x720
```

Higher resolutions such as `1920x1080` can also be configured.

## Build

Requires:

* devkitPro
* devkitA64
* libnx
* GNU Make
* Mesa Switch port

The Mesa Switch components required by this project must be built separately.

Mesa for Nintendo Switch:

https://github.com/NaGaa95/mesa-switch

Follow the build instructions in the repository and install/build the required Switch libraries and headers before compiling this project.

Additional dependencies:

```bash
dkp-pacman -S switch-zlib switch-libexpat
```

Build:

```bash
make
```

Clean build:

```bash
make clean
make
```

The build produces:

```text
galaxian_nx.nro
galaxian_nx.nacp
galaxian_nx.elf
```

## Project structure

```text
galaxian_nx/
├── source/
├── Makefile
├── LICENSE
└── README.md
```

## Credits

* TheWWWorm
* Galaxy on Fire
* NaGaa95 — Mesa Switch port
* Delson / delsonazevedo
* NaGaa95
* ChanseyIsTheBest
* TheFloW / fgsfds / Rinnegatamante
* Godot Engine contributors
* Nintendo Switch homebrew community

## Legal

Galaxy on Fire and its assets, trademarks and copyrights belong to their respective rights holders.

This is an unofficial fan-made port and is not affiliated with or endorsed by the original developers or publishers.

Game assets and Android libraries are not included in this repository unless explicitly provided by their respective rights holders.
