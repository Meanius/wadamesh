#pragma once
// The internal data filesystem (SPIFFS) of this firmware, mounted in one place.
//
// WADAMESH_FS_LABEL names its partition. Unset, it is NULL: the first spiffs partition, the
// upstream behaviour. The dual-boot build (LilyGo_TDeck_companion_radio_touch_dualboot) sets it
// to "mc_fs": in the table it shares with Meshtastic the first spiffs partition is Meshtastic's
// mt_fs, and a format-on-failure there would wipe the other firmware's data.
//
// Every SPIFFS.begin() goes through here. begin() replaces the partition label the SPIFFS object
// keeps for its later format() / totalBytes() calls, so a single unlabelled call anywhere would
// point those at the other partition too.
#if defined(ESP32)
#include <SPIFFS.h>

#ifndef WADAMESH_FS_LABEL
#define WADAMESH_FS_LABEL NULL
#endif

static inline bool wadaSpiffsBegin(bool formatOnFail) {
  return SPIFFS.begin(formatOnFail, "/spiffs", 10, WADAMESH_FS_LABEL);
}
#endif
