/* config.h -- Galaxy on Fire (Godot 4.7) Switch wrapper configuration.
 * Retargeted from delson's smwr_nx (Godot 4.6) template. MIT license; see LICENSE. */

#ifndef __CONFIG_H__
#define __CONFIG_H__

// The original Android payload is bundled in the NRO ROMFS at build time.
// Development builds still fall back to loose files next to the NRO.
#define SO_NAME "libgodot_android.so"
#define CXX_SO_NAME "libc++_shared.so"
#define CONFIG_NAME "config.txt"
#define LOG_NAME "galaxian_debug.log"

// DATA_ROOT points at the read-only payload bundled in the NRO. SAVE_ROOT holds
// config, saves, shader caches and runtime overrides on writable SD storage.
// The wrapper falls back to the launch directory when no ROMFS payload exists.
#define DEFAULT_DATA_ROOT "romfs:"
#define DEFAULT_SAVE_ROOT "/switch/galaxian_nx/save"

// absolute so the log lands in the app dir regardless of the launch CWD
#define LOG_PATH DEFAULT_DATA_ROOT "/galaxian_debug.log"

// Master debug switch: log file (<data_root>/galaxian_debug.log), boot_stats.txt,
// nxlink stdout, and all debugPrintf/[io]/[audio] output. Set to 1 to diagnose
// on hardware; 0 for release (no log/stats files written, and faster: no
// per-line fflush to the SD card).
#define DEBUG_LOG 0
// Per-file-operation logging (open/stat/access/fopen). Very noisy and slow
// (one fflush per line during asset loading); requires DEBUG_LOG too.
#define VERBOSE_IO 0

extern int screen_width;
extern int screen_height;

// locale reported to the engine via GodotIO.getLocale. The game doesn't follow it:
// it starts in English and keeps its own choice in user://galaxianLanguageSettings.json.
#define DEVICE_LOCALE "en_US"

typedef struct {
  int screen_width;   // render width  (config.txt); with the GPU/vsync this sets
  int screen_height;  // render height (config.txt); the framerate. Default 1280x720.
  int deadzone;       // analog stick deadzone, percent (0 disables); default 18
  int assetpack;      // 1 (default) = fold the loose assets into an on-device pack
                      // (assets.nxpack/.nxidx, built on first boot) for fast SD I/O.
                      // 0 = always read the loose files.
  int enable_vulkan;  // 1 (default) = use Godot's Vulkan renderer (NVK) when the driver
                      // comes up; 0 = force GLES3. Falls back to GLES3 if the probe fails.
  char ui_mode[16];   // "desktop" (default) or "mobile"; controls the game UI/font mode.
                      // Desktop hides mobile touch controls; mobile enables the touch UI.
  char rendering_method[32]; // override the Vulkan render method ("mobile" by default).
  char data_root[256];
  char save_root[256];
} Config;

extern Config config;

int read_config(const char *file);
int write_config(const char *file);

#endif
