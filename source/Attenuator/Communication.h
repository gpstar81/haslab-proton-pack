/**
 *   GPStar Attenuator - Ghostbusters Proton Pack & Neutrona Wand.
 *   Copyright (C) 2023 Michael Rajotte <michael.rajotte@gpstartechnologies.com>
 *                    & Dustin Grau <dustin.grau@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, see <https://www.gnu.org/licenses/>.
 *
 */

#pragma once

/*
 * These enum definitions must be kept in sync across the devices they communicate with, using the same dataype and ordering.
 * Enum values are internally considered integer values and here they are being given a distinct underlying datatype of uint8_t.
 * It is therefore important that the total number of elements per enum must remain below 254 to not overflow that (byte) type.
 */

enum api_messages : uint8_t {
  A_NULL,
  A_HANDSHAKE,
  A_SYNC_START,
  A_SYNC_END,
  A_PACK_BOOTUP,
  A_WAND_ON,
  A_WAND_OFF,
  A_FIRING,
  A_FIRING_STOPPED,
  A_PROTON_MODE,
  A_SLIME_MODE,
  A_STASIS_MODE,
  A_MESON_MODE,
  A_SPECTRAL_MODE,
  A_HOLIDAY_MODE,
  A_SPECTRAL_CUSTOM_MODE,
  A_VENTING_MODE,
  A_SETTINGS_MODE,
  A_OVERHEATING,
  A_OVERHEATING_FINISHED,
  A_WARNING_CANCELLED,
  A_CYCLOTRON_NORMAL_SPEED,
  A_CYCLOTRON_INCREASE_SPEED,
  A_BEEP_START,
  A_POWER_LEVEL_1,
  A_POWER_LEVEL_2,
  A_POWER_LEVEL_3,
  A_POWER_LEVEL_4,
  A_POWER_LEVEL_5,
  A_FIRING_INTENSIFY,
  A_FIRING_INTENSIFY_MIX,
  A_FIRING_INTENSIFY_STOPPED,
  A_FIRING_INTENSIFY_STOPPED_MIX,
  A_FIRING_ALT,
  A_FIRING_ALT_MIX,
  A_FIRING_ALT_STOPPED,
  A_FIRING_ALT_STOPPED_MIX,
  A_FIRING_CROSSING_THE_STREAMS,
  A_FIRING_CROSSING_THE_STREAMS_MIX,
  A_FIRING_CROSSING_THE_STREAMS_STOPPED,
  A_FIRING_CROSSING_THE_STREAMS_STOPPED_MIX,
  A_SILENT_MODE,
  A_VOLUME_REVERT,
  A_YEAR_MODES_CYCLE,
  A_VIDEO_GAME_MODE_COLOUR_TOGGLE,
  A_RESET_PROTON_STREAM,
  A_RESET_PROTON_STREAM_MIX,
  A_VIBRATION_DISABLED,
  A_VIBRATION_ENABLED,
  A_VIBRATION_FIRING_ENABLED,
  A_VIBRATION_CYCLE_TOGGLE,
  A_SMOKE_TOGGLE,
  A_PROTON_MODE_REVERT,
  A_CYCLOTRON_DIRECTION_TOGGLE,
  A_CYCLOTRON_LED_TOGGLE,
  A_OVERHEATING_DISABLED,
  A_OVERHEATING_ENABLED,
  A_MUSIC_TRACK_LOOP_TOGGLE,
  A_VOLUME_SOUND_EFFECTS_INCREASE,
  A_VOLUME_SOUND_EFFECTS_DECREASE,
  A_VOLUME_MUSIC_INCREASE,
  A_VOLUME_MUSIC_DECREASE,
  A_MUSIC_STOP,
  A_MUSIC_START,
  A_MUSIC_NEXT_TRACK,
  A_MUSIC_PREV_TRACK,
  A_VOLUME_DECREASE,
  A_VOLUME_INCREASE,
  A_VOLUME_SYNC,
  A_MENU_LEVEL_CHANGE,
  A_VGA_OVERHEAT_LIGHTS,
  A_DIMMING_TOGGLE,
  A_DIMMING_INCREASE,
  A_DIMMING_DECREASE,
  A_PROTON_STREAM_IMPACT_TOGGLE,
  A_CLEAR_EEPROM_SETTINGS_PACK,
  A_CLEAR_EEPROM_SETTINGS_WAND,
  A_SAVE_EEPROM_SETTINGS_PACK,
  A_SAVE_EEPROM_SETTINGS_WAND,
  A_TOGGLE_CYCLOTRON_LEDS,
  A_TOGGLE_POWERCELL_LEDS,
  A_TOGGLE_INNER_CYCLOTRON_LEDS,
  A_TOGGLE_RGB_INNER_CYCLOTRON_LEDS,
  A_EEPROM_MENU,
  A_CLEAR_CONFIG_EEPROM_SETTINGS,
  A_SAVE_CONFIG_EEPROM_SETTINGS,
  A_EXTRA_WAND_SOUNDS_STOP,
  A_AFTERLIFE_GUN_RAMP_1,
  A_AFTERLIFE_GUN_RAMP_2,
  A_AFTERLIFE_RAMP_LOOP_2_STOP,
  A_AFTERLIFE_GUN_LOOP_1,
  A_AFTERLIFE_GUN_LOOP_2,
  A_AFTERLIFE_GUN_RAMP_DOWN_2,
  A_AFTERLIFE_GUN_RAMP_DOWN_1,
  A_AFTERLIFE_GUN_RAMP_DOWN_2_FADE_OUT,
  A_AFTERLIFE_GUN_RAMP_2_FADE_IN,
  A_VOICE_NEUTRONA_WAND_SOUNDS_ENABLED,
  A_VOICE_NEUTRONA_WAND_SOUNDS_DISABLED,
  A_CYCLOTRON_SIMULATE_RING_TOGGLE,
  A_SPECTRAL_MODES_ENABLED,
  A_SPECTRAL_MODES_DISABLED,
  A_SPECTRAL_INNER_CYCLOTRON_CUSTOM_DECREASE,
  A_SPECTRAL_CYCLOTRON_CUSTOM_DECREASE,
  A_SPECTRAL_POWERCELL_CUSTOM_DECREASE,
  A_SPECTRAL_POWERCELL_CUSTOM_INCREASE,
  A_SPECTRAL_CYCLOTRON_CUSTOM_INCREASE,
  A_SPECTRAL_INNER_CYCLOTRON_CUSTOM_INCREASE,
  A_SPECTRAL_LIGHTS_ON,
  A_SPECTRAL_LIGHTS_OFF,
  A_YEAR_FROZEN_EMPIRE,
  A_YEAR_AFTERLIFE,
  A_YEAR_1989,
  A_YEAR_1984,
  A_ALARM_ON,
  A_ALARM_OFF,
  A_PACK_ON,
  A_PACK_OFF,
  A_TURN_PACK_ON,
  A_TURN_PACK_OFF,
  A_PACK_CONNECTED,
  A_SPECTRAL_COLOUR_DATA,
  A_MUSIC_START_STOP,
  A_TOGGLE_MUTE,
  A_BARREL_EXTENDED,
  A_BARREL_RETRACTED,
  A_MODE_SUPER_HERO,
  A_MODE_ORIGINAL,
  A_MODE_ORIGINAL_RED_SWITCH_ON,
  A_MODE_ORIGINAL_RED_SWITCH_OFF,
  A_MANUAL_OVERHEAT,
  A_MUSIC_TRACK_COUNT_SYNC,
  A_MUSIC_PAUSE_RESUME,
  A_MUSIC_IS_PLAYING,
  A_MUSIC_IS_NOT_PLAYING,
  A_MUSIC_IS_PAUSED,
  A_MUSIC_IS_NOT_PAUSED,
  A_MUSIC_PLAY_TRACK,
  A_BATTERY_VOLTAGE_PACK,
  A_WAND_CONNECTED,
  A_WAND_DISCONNECTED,
  A_REQUEST_PREFERENCES_PACK,
  A_REQUEST_PREFERENCES_WAND,
  A_REQUEST_PREFERENCES_SMOKE,
  A_SEND_PREFERENCES_PACK,
  A_SEND_PREFERENCES_WAND,
  A_SEND_PREFERENCES_SMOKE,
  A_SAVE_PREFERENCES_PACK,
  A_SAVE_PREFERENCES_WAND,
  A_SAVE_PREFERENCES_SMOKE
};