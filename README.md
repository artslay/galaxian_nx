# Galaxy on Fire — Nintendo Switch Port

A Nintendo Switch port of the Android version of **Galaxy on Fire**, running on Godot 4.7.

This project is an unofficial fan-made Nintendo Switch port. It loads the original Android game libraries and provides the required compatibility layer for running them on Nintendo Switch.

## How to install

1. Create `/switch/galaxian_nx/` on your SD card.

2. Copy `galaxian_nx.nro` into that folder.

3. Extract the following libraries from the Android version of the game:

```text
lib/arm64-v8a/libgodot_android.so
lib/arm64-v8a/libc++_shared.so
```

Copy them into:

```text
/switch/galaxian_nx/
```

4. Copy the required game data into:

```text
/switch/galaxian_nx/save/
```

Your SD card should contain:

```text
/switch/galaxian_nx/
    galaxian_nx.nro
    config.txt
    libgodot_android.so
    libc++_shared.so
    save/
        content/
        install.cfg
```

The original game libraries and game data are not included in this repository.

## Obtaining the game files

The Android version can be obtained from:

https://github.com/TheWWWorm/galaxian

Download the required Android ARM64 APK.

The APK is a ZIP archive and can be opened with 7-Zip, WinRAR or another archive utility.

The required native libraries are located in:

```text
lib/arm64-v8a/
```

Copy:

```text
libgodot_android.so
libc++_shared.so
```

to:

```text
/switch/galaxian_nx/
```

The original game data is imported from an iOS IPA through the in-game importer.

## IPA import

The Switch port can import a Galaxy on Fire 1 iOS IPA version **1.0.5** directly from the in-game file picker.

Select **Choose your Galaxy on Fire 1 IPA**. On Nintendo Switch, the Android system picker is disabled and the game's own Godot `FileDialog` is used instead.

The importer:

- checks that the selected file exists and is a readable IPA archive;
- requires a compatible archive under 128 MiB;
- locates the Galaxy on Fire 1 application bundle under `Payload/*.app/`;
- reads the bundled executable only as an import-time data source;
- validates and extracts the required game catalogues, meshes, textures, sounds and language files;
- builds a validated content cache identified by the SHA-256 of the IPA.

Imported content is stored under:

```text
/switch/galaxian_nx/save/content/<sha256>/
```

The importer writes a manifest containing the imported file hashes and validates the generated content before activating it.

The original IPA is never modified. The bundled executable is read only as input data during import; it is not installed or executed by the Switch wrapper.

This import flow is based on the original Galaxy on Fire project by **TheWWWorm**. See [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) for licensing information.

## Notes

Do not launch the application from Album/applet mode if the available memory is insufficient.

Use a game override by holding **R** while launching a title, or use a forwarder.

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

## How to build

You need:

* devkitPro
* devkitA64
* libnx
* GNU Make
* Mesa Switch port

Mesa for Nintendo Switch:

https://github.com/NaGaa95/mesa-switch

Build the required Mesa Switch libraries according to the instructions in the repository.

Additional dependencies:

```bash
dkp-pacman -S switch-zlib switch-libexpat
```

Then build:

```bash
make
```

For a clean build:

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

## Third-party notices

See [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) for the third-party licensing notice covering the IPA import flow from **TheWWWorm/galaxian**.

## Credits

* NaGaa95 — custom Mesa and Vulkan work.
* TheWWWorm — Android version / game port source
* Delson (delsonazevedo) — original Godot 4 Nintendo Switch wrapper this project was retargeted from.
* TheFloW (Andy Nguyen), fgsfds & Rinnegatamante — SoLoader lineage used by the wrapper.
* Godot Engine contributors — Godot Engine, licensed under MIT.
* Nintendo Switch homebrew community — tools, libraries and documentation used by the project.

## Legal

Galaxy on Fire and its assets, trademarks and copyrights belong to their respective rights holders.

This is an unofficial fan-made Nintendo Switch port and is not affiliated with or endorsed by the original developers or publishers.

No original game assets, game data or Android libraries are included in this repository.

Users should obtain the original game and required files legally.

Unless specified otherwise, the source code in this repository is licensed under the MIT License. See the accompanying LICENSE file.
