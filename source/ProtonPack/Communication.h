/**
 *   GPStar Proton Pack - Ghostbusters Proton Pack & Neutrona Wand.
 *   Copyright (C) 2023-2024 Michael Rajotte <michael.rajotte@gpstartechnologies.com>
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

enum pack_messages : uint8_t {
  P_NULL,
  P_COM_START,
  P_HANDSHAKE,
  P_SYNC_START,
  P_SYNC_DATA,
  P_SYNC_END,
  P_PACK_BOOTUP,
  P_ON,
  P_OFF,
  P_ALARM_ON,
  P_ALARM_OFF,
  P_VIBRATION_ENABLED,
  P_VIBRATION_DISABLED,
  P_YEAR_1984,
  P_YEAR_1989,
  P_YEAR_AFTERLIFE,
  P_YEAR_FROZEN_EMPIRE,
  P_VOLUME_SOUND_EFFECTS_INCREASE,
  P_VOLUME_SOUND_EFFECTS_DECREASE,
  P_VOLUME_INCREASE,
  P_VOLUME_DECREASE,
  P_VOLUME_SYNC,
  P_PACK_VIBRATION_ENABLED,
  P_PACK_VIBRATION_DISABLED,
  P_PACK_VIBRATION_FIRING_ENABLED,
  P_PACK_VIBRATION_DEFAULT,
  P_VIDEO_GAME_MODE_COLOURS_ENABLED,
  P_VIDEO_GAME_MODE_POWER_CELL_ENABLED,
  P_VIDEO_GAME_MODE_CYCLOTRON_ENABLED,
  P_VIDEO_GAME_MODE_COLOURS_DISABLED,
  P_MODE_FROZEN_EMPIRE,
  P_MODE_AFTERLIFE,
  P_MODE_1989,
  P_MODE_1984,
  P_SMOKE_DISABLED,
  P_SMOKE_ENABLED,
  P_CYCLOTRON_COUNTER_CLOCKWISE,
  P_CYCLOTRON_CLOCKWISE,
  P_CYCLOTRON_SINGLE_LED,
  P_CYCLOTRON_THREE_LED,
  P_MASTER_AUDIO_SILENT_MODE,
  P_MASTER_AUDIO_NORMAL,
  P_POWERCELL_DIMMING,
  P_CYCLOTRON_DIMMING,
  P_INNER_CYCLOTRON_DIMMING,
  P_CYCLOTRON_PANEL_DIMMING,
  P_DIMMING,
  P_PROTON_STREAM_IMPACT_ENABLED,
  P_PROTON_STREAM_IMPACT_DISABLED,
  P_POWER_LEVEL_1,
  P_POWER_LEVEL_2,
  P_POWER_LEVEL_3,
  P_POWER_LEVEL_4,
  P_POWER_LEVEL_5,
  P_RGB_INNER_CYCLOTRON_LEDS,
  P_GRB_INNER_CYCLOTRON_LEDS,
  P_CYCLOTRON_LEDS_40,
  P_CYCLOTRON_LEDS_36,
  P_CYCLOTRON_LEDS_20,
  P_CYCLOTRON_LEDS_12,
  P_POWERCELL_LEDS_15,
  P_POWERCELL_LEDS_13,
  P_INNER_CYCLOTRON_LEDS_23,
  P_INNER_CYCLOTRON_LEDS_24,
  P_INNER_CYCLOTRON_LEDS_26,
  P_INNER_CYCLOTRON_LEDS_35,
  P_INNER_CYCLOTRON_LEDS_36,
  P_INNER_CYCLOTRON_LEDS_12,
  P_RIBBON_CABLE_ON,
  P_RIBBON_CABLE_OFF,
  P_CYCLOTRON_SIMULATE_RING_DISABLED,
  P_CYCLOTRON_SIMULATE_RING_ENABLED,
  P_WARNING_CANCELLED,
  P_OVERHEAT_STROBE_ENABLED,
  P_OVERHEAT_STROBE_DISABLED,
  P_OVERHEAT_LIGHTS_OFF_ENABLED,
  P_OVERHEAT_LIGHTS_OFF_DISABLED,
  P_OVERHEAT_SYNC_FAN_DISABLED,
  P_OVERHEAT_SYNC_FAN_ENABLED,
  P_YEAR_MODE_DEFAULT,
  P_MODE_SUPER_HERO,
  P_MODE_ORIGINAL,
  P_MODE_ORIGINAL_RED_SWITCH_ON,
  P_MODE_ORIGINAL_RED_SWITCH_OFF,
  P_CYCLOTRON_LID_ON,
  P_CYCLOTRON_LID_OFF,
  P_MANUAL_OVERHEAT,
  P_OVERHEATING_FINISHED,
  P_VENTING_FINISHED,
  P_DEMO_LIGHT_MODE_ENABLED,
  P_DEMO_LIGHT_MODE_DISABLED,
  P_CONTINUOUS_SMOKE_5_ENABLED,
  P_CONTINUOUS_SMOKE_4_ENABLED,
  P_CONTINUOUS_SMOKE_3_ENABLED,
  P_CONTINUOUS_SMOKE_2_ENABLED,
  P_CONTINUOUS_SMOKE_1_ENABLED,
  P_CONTINUOUS_SMOKE_5_DISABLED,
  P_CONTINUOUS_SMOKE_4_DISABLED,
  P_CONTINUOUS_SMOKE_3_DISABLED,
  P_CONTINUOUS_SMOKE_2_DISABLED,
  P_CONTINUOUS_SMOKE_1_DISABLED,
  P_SOUND_SUPER_HERO,
  P_SOUND_MODE_ORIGINAL,
  P_SEND_PREFERENCES_WAND,
  P_SEND_PREFERENCES_SMOKE,
  P_SAVE_PREFERENCES_WAND,
  P_SAVE_PREFERENCES_SMOKE,
  P_SAVE_EEPROM_WAND,
  P_TOGGLE_INNER_CYCLOTRON_PANEL_ENABLED,
  P_TOGGLE_INNER_CYCLOTRON_PANEL_DISABLED,
  P_COM_END
};

enum wand_messages : uint8_t {
  W_NULL,
  W_COM_START,
  W_HANDSHAKE,
  W_SYNC_NOW,
  W_SYNCHRONIZED,
  W_ON,
  W_OFF,
  W_FIRING,
  W_FIRING_STOPPED,
  W_BUTTON_MASHING,
  W_PROTON_MODE,
  W_SLIME_MODE,
  W_STASIS_MODE,
  W_MESON_MODE,
  W_SPECTRAL_MODE,
  W_HOLIDAY_MODE,
  W_SPECTRAL_CUSTOM_MODE,
  W_SETTINGS_MODE,
  W_OVERHEATING,
  W_OVERHEATING_FINISHED,
  W_VENTING,
  W_CYCLOTRON_NORMAL_SPEED,
  W_CYCLOTRON_INCREASE_SPEED,
  W_BEEP_START,
  W_POWER_LEVEL_1,
  W_POWER_LEVEL_2,
  W_POWER_LEVEL_3,
  W_POWER_LEVEL_4,
  W_POWER_LEVEL_5,
  W_FIRING_INTENSIFY,
  W_FIRING_INTENSIFY_MIX,
  W_FIRING_INTENSIFY_STOPPED,
  W_FIRING_INTENSIFY_STOPPED_MIX,
  W_FIRING_ALT,
  W_FIRING_ALT_MIX,
  W_FIRING_ALT_STOPPED,
  W_FIRING_ALT_STOPPED_MIX,
  W_FIRING_CROSSING_THE_STREAMS_1984,
  W_FIRING_CROSSING_THE_STREAMS_MIX_1984,
  W_FIRING_CROSSING_THE_STREAMS_STOPPED_1984,
  W_FIRING_CROSSING_THE_STREAMS_STOPPED_MIX_1984,
  W_FIRING_CROSSING_THE_STREAMS_2021,
  W_FIRING_CROSSING_THE_STREAMS_MIX_2021,
  W_FIRING_CROSSING_THE_STREAMS_STOPPED_2021,
  W_FIRING_CROSSING_THE_STREAMS_STOPPED_MIX_2021,
  W_SILENT_MODE,
  W_VOLUME_REVERT,
  W_YEAR_MODES_CYCLE,
  W_VIDEO_GAME_MODE_COLOUR_TOGGLE,
  W_CROSS_THE_STREAMS,
  W_CROSS_THE_STREAMS_MIX,
  W_VIBRATION_DISABLED,
  W_VIBRATION_ENABLED,
  W_VIBRATION_FIRING_ENABLED,
  W_VIBRATION_DEFAULT,
  W_VIBRATION_CYCLE_TOGGLE,
  W_VIBRATION_CYCLE_TOGGLE_EEPROM,
  W_SMOKE_TOGGLE,
  W_VIDEO_GAME_MODE,
  W_CYCLOTRON_DIRECTION_TOGGLE,
  W_CYCLOTRON_LED_TOGGLE,
  W_OVERHEATING_DISABLED,
  W_OVERHEATING_ENABLED,
  W_MUSIC_TRACK_LOOP_TOGGLE,
  W_VOLUME_SOUND_EFFECTS_INCREASE,
  W_VOLUME_SOUND_EFFECTS_DECREASE,
  W_VOLUME_MUSIC_INCREASE,
  W_VOLUME_MUSIC_DECREASE,
  W_MUSIC_TOGGLE,
  W_MUSIC_PLAY_TRACK,
  W_VOLUME_DECREASE,
  W_VOLUME_INCREASE,
  W_MENU_LEVEL_1,
  W_MENU_LEVEL_2,
  W_MENU_LEVEL_3,
  W_MENU_LEVEL_4,
  W_MENU_LEVEL_5,
  W_VGA_OVERHEAT_LIGHTS,
  W_DIMMING_TOGGLE,
  W_DIMMING_INCREASE,
  W_DIMMING_DECREASE,
  W_PROTON_STREAM_IMPACT_TOGGLE,
  W_CLEAR_LED_EEPROM_SETTINGS,
  W_SAVE_LED_EEPROM_SETTINGS,
  W_TOGGLE_CYCLOTRON_LEDS,
  W_TOGGLE_POWERCELL_LEDS,
  W_TOGGLE_INNER_CYCLOTRON_LEDS,
  W_TOGGLE_RGB_INNER_CYCLOTRON_LEDS,
  W_EEPROM_LED_MENU,
  W_EEPROM_CONFIG_MENU,
  W_CLEAR_CONFIG_EEPROM_SETTINGS,
  W_SAVE_CONFIG_EEPROM_SETTINGS,
  W_EXTRA_WAND_SOUNDS_STOP,
  W_AFTERLIFE_GUN_RAMP_1,
  W_AFTERLIFE_GUN_RAMP_2,
  W_AFTERLIFE_RAMP_LOOP_STOP,
  W_AFTERLIFE_RAMP_LOOP_2_STOP,
  W_AFTERLIFE_GUN_LOOP_1,
  W_AFTERLIFE_GUN_LOOP_2,
  W_AFTERLIFE_GUN_RAMP_DOWN_2,
  W_AFTERLIFE_GUN_RAMP_DOWN_1,
  W_AFTERLIFE_GUN_RAMP_DOWN_2_FADE_OUT,
  W_AFTERLIFE_GUN_RAMP_2_FADE_IN,
  W_VOICE_NEUTRONA_WAND_SOUNDS_ENABLED,
  W_VOICE_NEUTRONA_WAND_SOUNDS_DISABLED,
  W_CYCLOTRON_SIMULATE_RING_TOGGLE,
  W_SPECTRAL_MODES_ENABLED,
  W_SPECTRAL_MODES_DISABLED,
  W_SPECTRAL_INNER_CYCLOTRON_CUSTOM_DECREASE,
  W_SPECTRAL_CYCLOTRON_CUSTOM_DECREASE,
  W_SPECTRAL_POWERCELL_CUSTOM_DECREASE,
  W_SPECTRAL_POWERCELL_CUSTOM_INCREASE,
  W_SPECTRAL_CYCLOTRON_CUSTOM_INCREASE,
  W_SPECTRAL_INNER_CYCLOTRON_CUSTOM_INCREASE,
  W_SPECTRAL_LIGHTS_ON,
  W_SPECTRAL_LIGHTS_OFF,
  W_QUICK_VENT_ENABLED,
  W_QUICK_VENT_DISABLED,
  W_BOOTUP_ERRORS_ENABLED,
  W_BOOTUP_ERRORS_DISABLED,
  W_VENT_LIGHT_INTENSITY_ENABLED,
  W_VENT_LIGHT_INTENSITY_DISABLED,
  W_BARREL_LEDS_5,
  W_BARREL_LEDS_48,
  W_BARGRAPH_INVERTED,
  W_BARGRAPH_NOT_INVERTED,
  W_OVERHEAT_STROBE_TOGGLE,
  W_OVERHEAT_LIGHTS_OFF_TOGGLE,
  W_OVERHEAT_SYNC_TO_FAN_TOGGLE,
  W_YEAR_MODES_CYCLE_EEPROM,
  W_BARREL_EXTENDED,
  W_BARREL_RETRACTED,
  W_MUSIC_NEXT_TRACK,
  W_MUSIC_PREV_TRACK,
  W_OVERHEAT_INCREASE_LEVEL_1,
  W_OVERHEAT_INCREASE_LEVEL_2,
  W_OVERHEAT_INCREASE_LEVEL_3,
  W_OVERHEAT_INCREASE_LEVEL_4,
  W_OVERHEAT_INCREASE_LEVEL_5,
  W_OVERHEAT_DECREASE_LEVEL_1,
  W_OVERHEAT_DECREASE_LEVEL_2,
  W_OVERHEAT_DECREASE_LEVEL_3,
  W_OVERHEAT_DECREASE_LEVEL_4,
  W_OVERHEAT_DECREASE_LEVEL_5,
  W_BARGRAPH_OVERHEAT_BLINK_ENABLED,
  W_BARGRAPH_OVERHEAT_BLINK_DISABLED,
  W_MODE_BEEP_LOOP_ENABLED,
  W_MODE_BEEP_LOOP_DISABLED,
  W_DEFAULT_BARGRAPH,
  W_MODE_ORIGINAL_BARGRAPH,
  W_SUPER_HERO_BARGRAPH,
  W_SUPER_HERO_FIRING_ANIMATIONS_BARGRAPH,
  W_MODE_ORIGINAL_FIRING_ANIMATIONS_BARGRAPH,
  W_DEFAULT_FIRING_ANIMATIONS_BARGRAPH,
  W_NEUTRONA_WAND_1984_MODE,
  W_NEUTRONA_WAND_1989_MODE,
  W_NEUTRONA_WAND_AFTERLIFE_MODE,
  W_NEUTRONA_WAND_FROZEN_EMPIRE_MODE,
  W_NEUTRONA_WAND_DEFAULT_MODE,
  W_DEMO_LIGHT_MODE_TOGGLE,
  W_CTS_DEFAULT,
  W_CTS_1984,
  W_CTS_1989,
  W_CTS_AFTERLIFE,
  W_CTS_FROZEN_EMPIRE,
  W_MODE_TOGGLE,
  W_OVERHEAT_LEVEL_5_ENABLED,
  W_OVERHEAT_LEVEL_4_ENABLED,
  W_OVERHEAT_LEVEL_3_ENABLED,
  W_OVERHEAT_LEVEL_2_ENABLED,
  W_OVERHEAT_LEVEL_1_ENABLED,
  W_OVERHEAT_LEVEL_5_DISABLED,
  W_OVERHEAT_LEVEL_4_DISABLED,
  W_OVERHEAT_LEVEL_3_DISABLED,
  W_OVERHEAT_LEVEL_2_DISABLED,
  W_OVERHEAT_LEVEL_1_DISABLED,
  W_CONTINUOUS_SMOKE_TOGGLE_5,
  W_CONTINUOUS_SMOKE_TOGGLE_4,
  W_CONTINUOUS_SMOKE_TOGGLE_3,
  W_CONTINUOUS_SMOKE_TOGGLE_2,
  W_CONTINUOUS_SMOKE_TOGGLE_1,
  W_VOLUME_DECREASE_EEPROM,
  W_VOLUME_INCREASE_EEPROM,
  W_SOUND_OVERHEAT_SMOKE_DURATION_LEVEL_5,
  W_SOUND_OVERHEAT_SMOKE_DURATION_LEVEL_4,
  W_SOUND_OVERHEAT_SMOKE_DURATION_LEVEL_3,
  W_SOUND_OVERHEAT_SMOKE_DURATION_LEVEL_2,
  W_SOUND_OVERHEAT_SMOKE_DURATION_LEVEL_1,
  W_SOUND_OVERHEAT_START_TIMER_LEVEL_5,
  W_SOUND_OVERHEAT_START_TIMER_LEVEL_4,
  W_SOUND_OVERHEAT_START_TIMER_LEVEL_3,
  W_SOUND_OVERHEAT_START_TIMER_LEVEL_2,
  W_SOUND_OVERHEAT_START_TIMER_LEVEL_1,
  W_SOUND_DEFAULT_SYSTEM_VOLUME_ADJUSTMENT,
  W_SEND_PREFERENCES_WAND,
  W_SEND_PREFERENCES_SMOKE,
  W_GB1_WAND_BARREL_EXTEND,
  W_AFTERLIFE_WAND_BARREL_EXTEND,
  W_WAND_BOOTUP_SOUND,
  W_WAND_BOOTUP_SHORT_SOUND,
  W_WAND_SHUTDOWN_SOUND,
  W_WAND_MASH_ERROR_SOUND,
  W_WAND_BEEP_SOUNDS,
  W_WAND_BEEP_BARGRAPH,
  W_MODE_ORIGINAL_HEATUP_STOP,
  W_MODE_ORIGINAL_HEATUP,
  W_MODE_ORIGINAL_HEATDOWN_STOP,
  W_MODE_ORIGINAL_HEATDOWN,
  W_BEEPS_ALT,
  W_WAND_BEEP_STOP,
  W_WAND_BEEP_STOP_LOOP,
  W_WAND_BEEP_START,
  W_WAND_BEEP,
  W_SOUND_NEUTRONA_WAND_SPEAKER_AMP_ENABLED,
  W_SOUND_NEUTRONA_WAND_SPEAKER_AMP_DISABLED,
  W_SMASH_ERROR_LOOP,
  W_SMASH_ERROR_LOOP_STOP,
  W_SMASH_ERROR_RESTART,
  W_BOSON_DART_SOUND,
  W_SHOCK_BLAST_SOUND,
  W_SLIME_TETHER_SOUND,
  W_MESON_COLLIDER_SOUND,
  W_MESON_FIRE_PULSE,
  W_TOGGLE_INNER_CYCLOTRON_PANEL,
  W_WAND_BOOTUP_1989,
  W_COM_SOUND_NUMBER,
  W_COM_END
};

enum api_messages : uint8_t {
  A_NULL,
  A_COM_START,
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
  A_SETTINGS_MODE,
  A_VENTING,
  A_VENTING_FINISHED,
  A_OVERHEATING,
  A_OVERHEATING_FINISHED,
  A_WARNING_CANCELLED,
  A_CYCLOTRON_LID_ON,
  A_CYCLOTRON_LID_OFF,
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
  A_SAVE_PREFERENCES_SMOKE,
  A_COM_END
};