/**
 *   gpstar Neutrona Wand - Ghostbusters Proton Pack & Neutrona Wand.
 *   Copyright (C) 2023 Michael Rajotte <michael.rajotte@gpstartechnologies.com>
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

enum pack_messages {
  P_COM_START,
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
  P_VOLUME_SOUND_EFFECTS_INCREASE,
  P_VOLUME_SOUND_EFFECTS_DECREASE,
  P_VOLUME_INCREASE,
  P_VOLUME_DECREASE,
  P_HANDSHAKE,
  P_MUSIC_REPEAT,
  P_MUSIC_NO_REPEAT,
  P_UNUSED,
  P_VOLUME_SYNC_MODE,
  P_PACK_VIBRATION_ENABLED,
  P_PACK_VIBRATION_DISABLED,
  P_PACK_VIBRATION_FIRING_ENABLED,
  P_VIDEO_GAME_MODE_COLOURS_ENABLED,
  P_VIDEO_GAME_MODE_POWER_CELL_ENABLED,
  P_VIDEO_GAME_MODE_CYCLOTRON_ENABLED,
  P_VIDEO_GAME_MODE_COLOURS_DISABLED,
  P_MODE_AFTERLIFE,
  P_MODE_1989,
  P_MODE_1984,
  P_SMOKE_DISABLED,
  P_SMOKE_ENABLED,
  P_CYCLOTRON_COUNTER_CLOCKWISE,
  P_CYCLOTRON_CLOCKWISE,
  P_CYCLOTRON_SINGLE_LED,
  P_CYCLOTRON_THREE_LED,
  P_MUSIC_START,
  P_MUSIC_STOP,
  P_MASTER_AUDIO_SILENT_MODE,
  P_MASTER_AUDIO_NORMAL,
  P_POWERCELL_DIMMING,
  P_CYCLOTRON_DIMMING,
  P_INNER_CYCLOTRON_DIMMING,
  P_DIMMING,
  P_PROTON_STREAM_IMPACT_ENABLED,
  P_PROTON_STREAM_IMPACT_DISABLED,
  P_POWER_LEVEL_1,
  P_POWER_LEVEL_2,
  P_POWER_LEVEL_3,
  P_POWER_LEVEL_4,
  P_POWER_LEVEL_5,
  P_PROTON_MODE,
  P_SLIME_MODE,
  P_STASIS_MODE,
  P_MESON_MODE,
  P_SPECTRAL_MODE,
  P_HOLIDAY_MODE,
  P_SPECTRAL_CUSTOM_MODE,
  P_VENTING_MODE,
  P_SETTINGS_MODE,
  P_RGB_INNER_CYCLOTRON_LEDS,
  P_GRB_INNER_CYCLOTRON_LEDS,
  P_CYCLOTRON_LEDS_40,
  P_CYCLOTRON_LEDS_20,
  P_CYCLOTRON_LEDS_12,
  P_POWERCELL_LEDS_15,
  P_POWERCELL_LEDS_13,
  P_INNER_CYCLOTRON_LEDS_23,
  P_INNER_CYCLOTRON_LEDS_24,
  P_INNER_CYCLOTRON_LEDS_35,
  P_INNER_CYCLOTRON_LEDS_12,
  P_RIBBON_CABLE_ON,
  P_RIBBON_CABLE_OFF,
  P_CYCLOTRON_SIMULATE_RING_DISABLED,
  P_CYCLOTRON_SIMULATE_RING_ENABLED,
  P_WARNING_CANCELLED,
  P_SYNC_START,
  P_SYNC_END,
  P_COM_END,
};

enum wand_messages {
  W_COM_START,
  W_ON,
  W_OFF,
  W_FIRING,
  W_FIRING_STOPPED,
  W_PROTON_MODE,
  W_SLIME_MODE,
  W_STASIS_MODE,
  W_MESON_MODE,
  W_SPECTRAL_MODE,
  W_HOLIDAY_MODE,
  W_SPECTRAL_CUSTOM_MODE,
  W_VENTING_MODE,
  W_SETTINGS_MODE,
  W_OVERHEATING,
  W_OVERHEATING_FINISHED,
  W_CYCLOTRON_NORMAL_SPEED,
  W_CYCLOTRON_INCREASE_SPEED,
  W_HANDSHAKE,
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
  W_FIRING_CROSSING_THE_STREAMS,
  W_FIRING_CROSSING_THE_STREAMS_MIX,
  W_FIRING_CROSSING_THE_STREAMS_STOPPED,
  W_FIRING_CROSSING_THE_STREAMS_STOPPED_MIX,
  W_SILENT_MODE,
  W_VOLUME_REVERT,
  W_YEAR_MODES_CYCLE,
  W_VIDEO_GAME_MODE_COLOUR_TOGGLE,
  W_RESET_PROTON_STREAM,
  W_RESET_PROTON_STREAM_MIX,
  W_VIBRATION_DISABLED,
  W_VIBRATION_ENABLED,
  W_VIBRATION_FIRING_ENABLED,
  W_VIBRATION_CYCLE_TOGGLE,
  W_SMOKE_TOGGLE,
  W_PROTON_MODE_REVERT,
  W_CYCLOTRON_DIRECTION_TOGGLE,
  W_CYCLOTRON_LED_TOGGLE,
  W_OVERHEATING_DISABLED,
  W_OVERHEATING_ENABLED,
  W_MUSIC_TRACK_LOOP_TOGGLE,
  W_VOLUME_SOUND_EFFECTS_INCREASE,
  W_VOLUME_SOUND_EFFECTS_DECREASE,
  W_VOLUME_MUSIC_INCREASE,
  W_VOLUME_MUSIC_DECREASE,
  W_MUSIC_STOP,
  W_MUSIC_START,
  W_VOLUME_DECREASE,
  W_VOLUME_INCREASE,
  W_MENU_LEVEL_CHANGE,
  W_VGA_OVERHEAT_LIGHTS,
  W_DIMMING_TOGGLE,
  W_DIMMING_INCREASE,
  W_DIMMING_DECREASE,
  W_PROTON_STREAM_IMPACT_TOGGLE,
  W_CLEAR_EEPROM_SETTINGS,
  W_SAVE_EEPROM_SETTINGS,
  W_TOGGLE_CYCLOTRON_LEDS,
  W_TOGGLE_POWERCELL_LEDS,
  W_TOGGLE_INNER_CYCLOTRON_LEDS,
  W_TOGGLE_RGB_INNER_CYCLOTRON_LEDS,
  W_EEPROM_MENU,
  W_CLEAR_CONFIG_EEPROM_SETTINGS,
  W_SAVE_CONFIG_EEPROM_SETTINGS,
  W_EXTRA_WAND_SOUNDS_STOP,
  W_AFTERLIFE_GUN_RAMP_1,
  W_AFTERLIFE_GUN_RAMP_2,
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
  W_COM_END
};
