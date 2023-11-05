/**
 *   GPStar Neutrona Wand - Ghostbusters Proton Pack & Neutrona Wand.
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
 
/* 
 *  SD Card sound files in order. If you have no sound, your SD card might be too slow, try a faster one.
 *  File naming 000_ is important as well. For music, it is 500_ and higher.
 *  Also note if you add more sounds to this list, you need to update the i_last_effects_track variable located at the bottom of this file to the last enum definition.
 *  The WAV Trigger uses this to determine how many music tracks there are if any.
 */

enum sound_fx {
  S_EMPTY, 
  S_BOOTUP,
  S_SHUTDOWN,
  S_IDLE_LOOP,
  S_IDLE_LOOP_GUN,
  S_FIRE_START,
  S_FIRE_START_SPARK,
  S_FIRE_LOOP,
  S_FIRE_LOOP_GUN,
  S_FIRE_LOOP_IMPACT,
  S_FIRING_END,
  S_FIRING_END_GUN,
  S_AFTERLIFE_BEEP_WAND,
  S_AFTERLIFE_GUN_RAMP_LOW,
  S_AFTERLIFE_GUN_RAMP_HIGH,
  S_AFTERLIFE_PACK_STARTUP,
  S_AFTERLIFE_PACK_IDLE_LOOP,
  S_WAND_SHUTDOWN,
  S_AFTERLIFE_BEEP_WAND_S1,
  S_AFTERLIFE_BEEP_WAND_S2,
  S_AFTERLIFE_BEEP_WAND_S3,
  S_AFTERLIFE_BEEP_WAND_S4,
  S_AFTERLIFE_BEEP_WAND_S5,
  S_AFTERLIFE_GUN_RAMP_1,
  S_AFTERLIFE_GUN_LOOP_1,
  S_AFTERLIFE_GUN_RAMP_2,
  S_AFTERLIFE_GUN_LOOP_2,
  S_AFTERLIFE_GUN_RAMP_DOWN_2,
  S_AFTERLIFE_GUN_RAMP_DOWN_1,
  S_IDLE_LOOP_GUN_2,
  S_IDLE_LOOP_GUN_3,
  S_IDLE_LOOP_GUN_4,
  S_IDLE_LOOP_GUN_5,
  S_IDLE_LOOP_GUN_1,
  S_PACK_BEEPING,
  S_PACK_SHUTDOWN,
  S_PACK_SHUTDOWN_AFTERLIFE,
  S_GB2_PACK_START,
  S_GB2_PACK_LOOP,
  S_GB2_PACK_OFF,
  S_CLICK,
  S_VENT,
  S_VENT_SLOW,
  S_VENT_FAST,
  S_VENT_DRY,
  S_VENT_BEEP,
  S_VENT_BEEP_3,
  S_VENT_BEEP_7,
  S_PACK_SLIME_OPEN,
  S_PACK_SLIME_CLOSE,
  S_PACK_SLIME_TANK_LOOP,
  S_SLIME_START,
  S_SLIME_LOOP,
  S_SLIME_END,
  S_STASIS_START,
  S_STASIS_LOOP,
  S_STASIS_END,
  S_MESON_START,
  S_MESON_LOOP,
  S_MESON_END,
  S_BEEP_8,
  S_VENT_SMOKE,
  S_MODE_SWITCH,
  S_BEEPS,
  S_BEEPS_ALT,
  S_SPARKS_LONG,
  S_SPARKS_LOOP,
  S_BEEPS_LOW,
  S_BEEPS_BARGRAPH,
  S_MESON_OPEN,
  S_STASIS_OPEN,
  S_FIRING_END_MID,
  S_FIRING_LOOP_GB1,
  S_CROSS_STREAMS_END,
  S_CROSS_STREAMS_START,
  S_PACK_RIBBON_ALARM_1,
  S_PACK_RIBBON_ALARM_2,
  S_VOICE_1984,
  S_VOICE_1989,
  S_VOICE_2021,
  S_VOICE_VIBRATION_ENABLED,
  S_VOICE_VIBRATION_DISABLED,
  S_VOICE_VIBRATION_FIRING_ENABLED,
  S_VOICE_VIBRATION_FIRING_DISABLED,
  S_VOICE_SMOKE_ENABLED,
  S_VOICE_SMOKE_DISABLED,
  S_VOICE_CYCLOTRON_CLOCKWISE,
  S_VOICE_CYCLOTRON_COUNTER_CLOCKWISE,
  S_VOICE_CROSS_THE_STREAMS,
  S_VOICE_VIDEO_GAME_MODES,
  S_VOICE_SINGLE_LED,
  S_VOICE_THREE_LED,
  S_VOICE_OVERHEAT_ENABLED,
  S_VOICE_OVERHEAT_DISABLED,
  S_VOICE_AFTERLIFE,
  S_GB1_FIRE_LOOP,
  S_GB1_FIRE_START,
  S_GB1_FIRE_START_HIGH_POWER,
  S_GB1_FIRE_HIGH_POWER_LOOP,
  S_GB2_FIRE_LOOP,
  S_GB2_FIRE_START,
  S_VOICE_CROSS_THE_STREAMS_MIX,
  S_VOICE_PROTON_PACK_VIBRATION_ENABLED,
  S_VOICE_PROTON_PACK_VIBRATION_DISABLED,
  S_VOICE_PROTON_PACK_VIBRATION_FIRING_ENABLED,
  S_VOICE_PROTON_PACK_VIBRATION_FIRING_DISABLED,
  S_VOICE_NEUTRONA_WAND_VIBRATION_ENABLED,
  S_VOICE_NEUTRONA_WAND_VIBRATION_DISABLED,
  S_VOICE_NEUTRONA_WAND_VIBRATION_FIRING_ENABLED,
  S_VOICE_NEUTRONA_WAND_VIBRATION_FIRING_DISABLED,
  S_AFTERLIFE_CROSS_THE_STREAMS_START,
  S_AFTERLIFE_CROSS_THE_STREAMS_END,
  S_VOICE_VIDEO_GAME_COLOURS_DISABLED,
  S_VOICE_VIDEO_GAME_COLOURS_ENABLED,
  S_VOICE_VIDEO_GAME_COLOURS_POWERCELL_ENABLED,
  S_VOICE_VIDEO_GAME_COLOURS_CYCLOTRON_ENABLED,
  S_FIRE_SPARKS,
  S_FIRE_SPARKS_2,
  S_FIRE_SPARKS_3,
  S_FIRE_SPARKS_4,
  S_FIRE_SPARKS_5,
  S_VOICE_POWERCELL_BRIGHTNESS,
  S_VOICE_CYCLOTRON_BRIGHTNESS,
  S_VOICE_CYCLOTRON_INNER_BRIGHTNESS,
  S_VOICE_PROTON_MIX_EFFECTS_ENABLED,
  S_VOICE_PROTON_MIX_EFFECTS_DISABLED,
  S_ALARM_LOOP,
  S_RIBBON_CABLE_START,
  S_VOICE_POWERCELL_15,
  S_VOICE_POWERCELL_13,
  S_VOICE_CYCLOTRON_40,
  S_VOICE_CYCLOTRON_20,
  S_VOICE_CYCLOTRON_12,
  S_VOICE_INNER_CYCLOTRON_35,
  S_VOICE_INNER_CYCLOTRON_24,
  S_VOICE_INNER_CYCLOTRON_23,
  S_VOICE_INNER_CYCLOTRON_12,
  S_VOICE_RGB_INNER_CYCLOTRON,
  S_VOICE_GRB_INNER_CYCLOTRON,
  S_VOICE_EEPROM_ERASE,
  S_VOICE_EEPROM_SAVE,
  S_AFTERLIFE_WAND_RAMP_1,
  S_AFTERLIFE_WAND_IDLE_1,
  S_AFTERLIFE_WAND_RAMP_2,
  S_AFTERLIFE_WAND_IDLE_2,
  S_AFTERLIFE_WAND_RAMP_DOWN_1,
  S_AFTERLIFE_WAND_RAMP_DOWN_2,
  S_AFTERLIFE_WAND_RAMP_2_FADE_IN,
  S_AFTERLIFE_WAND_RAMP_DOWN_2_FADE_OUT,
  S_VOICE_NEUTRONA_WAND_SOUNDS_ENABLED,
  S_VOICE_NEUTRONA_WAND_SOUNDS_DISABLED,
  S_VOICE_CYCLOTRON_SIMULATE_RING_ENABLED,
  S_VOICE_CYCLOTRON_SIMULATE_RING_DISABLED,
  S_VOICE_SPECTRAL_MODES_ENABLED,
  S_VOICE_SPECTRAL_MODES_DISABLED,
  S_AFTERLIFE_FIRE_START,
  S_VOICE_QUICK_VENT_ENABLED,
  S_VOICE_QUICK_VENT_DISABLED,
  S_VOICE_VENT_LIGHT_INTENSITY_ENABLED,
  S_VOICE_VENT_LIGHT_INTENSITY_DISABLED,
  S_VOICE_BARGRAPH_INVERTED,
  S_VOICE_BARGRAPH_NOT_INVERTED,
  S_VOICE_BARGRAPH_ALWAYS_RAMPING_ENABLED,
  S_VOICE_BARGRAPH_ALWAYS_RAMPING_DISABLED,
  S_VOICE_OVERHEAT_STROBE_ENABLED,
  S_VOICE_OVERHEAT_STROBE_DISABLED,
  S_VOICE_OVERHEAT_LIGHTS_OFF_ENABLED,
  S_VOICE_OVERHEAT_LIGHTS_OFF_DISABLED,
  S_VOICE_OVERHEAT_FAN_SYNC_ENABLED,
  S_VOICE_OVERHEAT_FAN_SYNC_DISABLED,
  S_VOICE_YEAR_MODE_DEFAULT,
  S_VOICE_VOLUME_RESET,
  S_VOICE_BARREL_LED_5,
  S_VOICE_BARREL_LED_48,
  S_VOICE_BARREL_LED_60,
  S_VOICE_BOOTUP_ERRORS_ENABLED,
  S_VOICE_BOOTUP_ERRORS_DISABLED,
  S_AFTERLIFE_WAND_BARREL_EXTEND,
  S_AIR_RELEASE,
  S_STEAM_LOOP,
  S_STEAM_LOOP_FADE_OUT
};

/*
 * Need to keep track which is the last sound effect, so we can iterate over the effects to adjust the volume gain on them.
 */
const unsigned int i_last_effects_track = S_STEAM_LOOP_FADE_OUT;