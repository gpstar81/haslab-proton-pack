/**
 *   gpstar Neutrona Wand - Ghostbusters Proton Pack & Neutrona Wand.
 *   Copyright (C) 2023 Michael Rajotte <michael.rajotte@gmail.com>
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
  P_PACK_BOOTUP,
  P_ON,
  P_OFF,
  P_ALARM_ON,
  P_ALARM_OFF,
  P_VIBRATION_ENABLED,
  P_VIBRATION_DISABLED,
  P_YEAR_1984,
  P_YEAR_AFTERLIFE,
  P_VOLUME_INCREASE,
  P_VOLUME_DECREASE,
  P_HANDSHAKE,
  P_MUSIC_REPEAT,
  P_MUSIC_NO_REPEAT,
  P_UNUSED,
  P_VOLUME_SYNC_MODE,
  P_VIBRATION_FIRING_ENABLED,
  P_VIBRATION_FIRING_DISABLED,
  P_MODE_AFTERLIFE,
  P_MODE_1989,
  P_MODE_1984,
  P_SMOKE_DISABLED,
  P_SMOKE_ENABLED,
  P_CYCLOTRON_COUNTER_CLOCKWISE,
  P_CYCLOTRON_CLOCKWISE,
  P_CYCLOTRON_SINGLE_LED,
  P_CYCLOTRON_THREE_LED,
  P_MUSIC_STOP
};

enum wand_messages {
  W_EMPTY,
  W_ON,
  W_OFF,
  W_FIRING,
  W_FIRING_STOPPED,
  W_PROTON_MODE,
  W_SLIME_MODE,
  W_STASIS_MODE,
  W_MESON_MODE,
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
  W_FIRING_INTENSIFY_STOPPED,
  W_FIRING_ALT,
  W_FIRING_ALT_STOPPED,
  W_FIRING_CROSSING_THE_STREAMS,
  W_FIRING_CROSSING_THE_STREAMS_STOPPED,
  W_YEAR_MODES_CYCLE,
  W_RESET_PROTON_STREAM,
  W_VIBRATION_DISABLED,
  W_VIBRATION_ENABLED,
  W_VIBRATION_FIRING_DISABLED,
  W_VIBRATION_FIRING_ENABLED,
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
  W_VOLUME_INCREASE
};