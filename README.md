# Galaxy on Fire — Nintendo Switch Port

A Nintendo Switch port of the Android version of **Galaxy on Fire**, running on Godot 4.7.

This project is an unofficial fan-made Nintendo Switch port. It loads the original Android engine libraries and provides the required compatibility layer for running them on Nintendo Switch.

## How to install

Create the following folder on your SD card:

```text
/switch/galaxian_nx/
```

Place the following files inside:

```text
/switch/galaxian_nx/
├── galaxian_nx.nro
├── libgodot_android.so
├── libc++_shared.so
├── config.txt
├── assets/
│   ├── project.binary
│   └── ...
└── save/
    ├── content/
    └── install.cfg
```

The Android libraries and game data must be obtained from the original Android version of the game.

## Obtaining the game files

The Android APK required for preparing the game data can be obtained from the **TheWWWorm/galaxian** project:

https://github.com/TheWWWorm/galaxian

Download the appropriate Android APK from the repository. The project provides Android ARM64 and x86-64 builds.

Install the APK on an Android phone or Android emulator on PC and launch the game **at least once**.

After the first launch, locate the game's generated data and extract:

```text
content/
install.cfg
```

These files are required to obtain the game data `hash` and prepare the files for `galaxian_nx`.

After extracting them, copy both `content/` and `install.cfg` into:

```text
/switch/galaxian_nx/save/
```

The resulting structure should be:

```text
/switch/galaxian_nx/save/
├── content/
└── install.cfg
```

Keep the original `content/` directory and `install.cfg` available during the preparation process.

The original game content is not included in the `galaxian` source repository itself.

## Controls

The Nintendo Switch controller is mapped to the Godot input system:

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

Analog stick deadzone can be configured with:

```text
deadzone 18
```

Touch controls are disabled by default:

```text
touch_controls 0
```

## Configuration

The configuration file is:

```text
/switch/galaxian_nx/config.txt
```

Default configuration:

```text
screen_width 1280
screen_height 720
deadzone 18
assetpack 1
enable_vulkan 1
touch_controls 0
rendering_method mobile
```

### Configuration options

| Option           | Description                    |
| ---------------- | ------------------------------ |
| `screen_width`   | Render width                   |
| `screen_height`  | Render height                  |
| `deadzone`       | Analog-stick dead zone         |
| `assetpack`      | Enables the indexed asset pack |
| `enable_vulkan`  | Enables Vulkan rendering       |
| `touch_controls` | Enables touch controls         |

## Resolution

The default resolution is:

```text
screen_width 1280
screen_height 720
```

The resolution can be changed directly in `config.txt`.

For example:

```text
screen_width 1920
screen_height 1080
```

## Build

The project requires:

* devkitPro
* devkitA64
* libnx
* GNU Make

Required portlibs:

```bash
dkp-pacman -S switch-zlib switch-libexpat
```

The renderer uses a custom Mesa build with the NVK Vulkan driver for Nintendo Switch.

The required Mesa SDK is already included in this repository:

```text
mesa-sdk/
```

No separate Mesa SDK download is required.

Build from a devkitPro shell:

```bash
make
```

Clean the build:

```bash
make clean
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
├── mesa-sdk/
├── Makefile
├── LICENSE
└── README.md
```

## Credits

* **TheWWWorm** — Galaxy on Fire engine work and the original `galaxian` project.
* **Galaxy on Fire** — original game and its developers.
* **Delson (delsonazevedo)** — original Godot 4 Nintendo Switch wrapper this project was retargeted from.
* **NaGaa95** — custom Mesa and Vulkan work.
* **TheFloW (Andy Nguyen), fgsfds & Rinnegatamante** — SoLoader lineage used by the wrapper.
* **Godot Engine contributors** — Godot Engine, licensed under MIT.
* **Nintendo Switch homebrew community** — tools, libraries and documentation used by the project.

## Legal

Galaxy on Fire and its related assets, trademarks and copyrights belong to their respective copyright holders.

This project is an unofficial Nintendo Switch port and is not affiliated with or endorsed by the original developers or rights holders.

Game assets and Android libraries are not included in this repository unless explicitly provided by their respective copyright holders.
