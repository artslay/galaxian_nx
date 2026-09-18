# Third-party notices

## TheWWWorm/galaxian

The IPA import flow used by the game comes from the original
[TheWWWorm/galaxian](https://github.com/TheWWWorm/galaxian) project.

The relevant upstream game sources include:

- `game/src/main.gd`
- `game/src/content/ipa_import.gd`
- `game/src/content/native_import.gd`
- `game/src/content/native_data.gd`
- `game/src/content/formats.gd`
- `game/src/content/library.gd`

The Nintendo Switch wrapper does not reimplement the IPA importer. It changes
the compiled `res://src/main.gd` behavior so that the Android native file picker
is disabled and Godot's own `FileDialog` is used on Nintendo Switch.

The upstream project is licensed under the Apache License, Version 2.0.
See the upstream [LICENSE.md](https://github.com/TheWWWorm/galaxian/blob/main/LICENSE.md)
for the complete license text.

This notice does not change the MIT license of the surrounding
`galaxian_nx` project or of independently written Nintendo Switch-specific code.
