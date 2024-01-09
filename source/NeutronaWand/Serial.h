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

#pragma once

// For pack communication (2 byte ID, 2 byte optional data, 23 byte data payload).
struct __attribute__((packed)) MessagePacket {
  uint16_t i;
  uint16_t d1; // Reserved for values over 255 (eg. current music track)
  uint8_t d[22]; // Reserved for large data packets (eg. EEPROM configs)
};

struct MessagePacket recvData;
struct MessagePacket sendData;

// Pack communication from the wand.
void wandSerialSend(uint16_t i_message, uint16_t i_value) {
  if(b_no_pack != true) {
    sendData.i = i_message;
    sendData.d1 = i_value;

    // Set all elements of the data array to 0
    memset(sendData.d, 0, sizeof(sendData.d));

    switch(i_message) {
      case W_SEND_PREFERENCES_WAND:
        // Sends values from current runtime variables as values in an int array.
        // Any ENUM or boolean types will simply translate as numeric values.
        switch(WAND_BARREL_LED_COUNT) {
          case LEDS_5:
          default:
            sendData.d[0] = 0;
          break;
          case LEDS_29:
            sendData.d[0] = 1;
          break;
          case LEDS_48:
            sendData.d[0] = 2;
          break;
        }
        sendData.d[1] = i_spectral_wand_custom_colour;
        sendData.d[2] = i_spectral_wand_custom_saturation;
        sendData.d[3] = b_spectral_mode_enabled;
        sendData.d[4] = b_holiday_mode_enabled;
        sendData.d[5] = b_overheat_enabled;
        sendData.d[6] = b_cross_the_streams;
        sendData.d[7] = b_cross_the_streams_mix;
        sendData.d[8] = b_extra_pack_sounds;
        sendData.d[9] = b_quick_vent;
        sendData.d[10] = b_vent_light_control;
        sendData.d[11] = b_beep_loop;
        sendData.d[12] = b_wand_boot_errors;
        sendData.d[13] = WAND_YEAR_MODE;
        sendData.d[14] = WAND_YEAR_CTS;
        sendData.d[15] = b_bargraph_invert;
        sendData.d[16] = b_overheat_bargraph_blink;
        sendData.d[17] = BARGRAPH_MODE;
        sendData.d[18] = BARGRAPH_EEPROM_FIRING_ANIMATION;
      break;

      case W_SEND_PREFERENCES_SMOKE:
        // Determines whether overheating is enabled for a power level.
        sendData.d[0] = b_overheat_mode_5;
        sendData.d[1] = b_overheat_mode_4;
        sendData.d[2] = b_overheat_mode_3;
        sendData.d[3] = b_overheat_mode_2;
        sendData.d[4] = b_overheat_mode_1;

        // Time (seconds) before an overheat event takes place by level.
        sendData.d[5] = i_ms_overheat_initiate_mode_5 / 1000;
        sendData.d[6] = i_ms_overheat_initiate_mode_4 / 1000;
        sendData.d[7] = i_ms_overheat_initiate_mode_3 / 1000;
        sendData.d[8] = i_ms_overheat_initiate_mode_2 / 1000;
        sendData.d[9] = i_ms_overheat_initiate_mode_1 / 1000;
      break;

      default:
        // No-op for all other actions.
      break;
    }

    wandComs.sendDatum(sendData);
  }
}
// Override function to handle calls with a single parameter.
void wandSerialSend(uint16_t i_message) {
  wandSerialSend(i_message, 0);
}

// Pack communication to the wand.
void checkPack() {
  if(wandComs.available() && b_no_pack != true) {
    wandComs.rxObj(recvData);

    if(!wandComs.currentPacketID()) {
      switch(recvData.i) {
        case P_PACK_BOOTUP:
          // Nothing for now.
        break;

        case P_ON:
          // Pack is on.
          b_pack_on = true;
        break;

        case P_OFF:
          if(b_pack_on == true) {
            // Turn wand off.
            if(WAND_STATUS != MODE_OFF) {
              if(WAND_STATUS == MODE_ERROR) {
                b_wand_mash_error = false;
                wandOff();
              }
              else {
                b_wand_mash_error = false;
                WAND_ACTION_STATUS = ACTION_OFF;
              }
            }
          }

          // Pack is off.
          b_pack_on = false;
        break;

        case P_SYNC_START:
          b_sync = true;
        break;

        case P_SYNC_END:
          b_sync = false;
          b_wait_for_pack = false;

          switchBarrel();

          // Tell the pack the status of the Neutrona Wand barrel. We only need to tell if its extended.
          // Otherwise the switchBarrel() will tell it if it's retracted during bootup.
          if(b_switch_barrel_extended == true) {
            wandSerialSend(W_BARREL_EXTENDED);
          }
        break;

        case P_SEND_PREFERENCES_WAND:
          // The pack wants the latest wand preferences.
          wandSerialSend(W_SEND_PREFERENCES_WAND);
        break;

        case P_SEND_PREFERENCES_SMOKE:
          // The pack wants the latest smoke preferences.
          wandSerialSend(W_SEND_PREFERENCES_SMOKE);
        break;

        case P_SOUND_SUPER_HERO:
          stopEffect(S_VOICE_MODE_SUPER_HERO);
          stopEffect(S_VOICE_MODE_ORIGINAL);
          playEffect(S_VOICE_MODE_SUPER_HERO);
        break;

        case P_SOUND_MODE_ORIGINAL:
          stopEffect(S_VOICE_MODE_SUPER_HERO);
          stopEffect(S_VOICE_MODE_ORIGINAL);
          playEffect(S_VOICE_MODE_ORIGINAL);
        break;

        case P_MODE_SUPER_HERO:
          SYSTEM_MODE = MODE_SUPER_HERO;
        break;

        case P_MODE_ORIGINAL:
          SYSTEM_MODE = MODE_ORIGINAL;
        break;

        case P_OVERHEATING_FINISHED:
          if(WAND_STATUS != MODE_OFF) {
            overHeatingFinished();
          }
        break;

        case P_MODE_ORIGINAL_RED_SWITCH_ON:
          b_pack_ion_arm_switch_on = true;

          // Prep the bargraph for MODE_ORIGINAL. This only preps it when the pack switch is turned on and the wand is still off but all the toggle switches are on for the bargraph to settle at the off position. (0 circle).
          if(WAND_ACTION_STATUS == ACTION_IDLE) {
            switch(WAND_STATUS) {
              case MODE_OFF:
                switch(SYSTEM_MODE) {
                  case MODE_ORIGINAL:
                    if(switch_vent.getState() == LOW && switch_wand.getState() == LOW) {
                      if(b_mode_original_toggle_sounds_enabled == true) {
                        stopEffect(S_WAND_HEATDOWN);
                        stopEffect(S_WAND_HEATUP_ALT);
                        stopEffect(S_WAND_HEATUP);

                        playEffect(S_WAND_HEATUP);
                        playEffect(S_WAND_HEATUP_ALT);
                      }

                      if(b_28segment_bargraph == true) {
                        bargraphPowerCheck2021Alt(false);
                      }

                      prepBargraphRampUp();
                    }
                  break;

                  default:
                    // Do nothing.
                  break;
                }
              break;

              default:
                // Do nothing if we aren't MODE_OFF
              break;
            }
          }
        break;

        case P_MODE_ORIGINAL_RED_SWITCH_OFF:
          b_pack_ion_arm_switch_on = false;

          switch(SYSTEM_MODE) {
            case MODE_ORIGINAL:
              if(switch_vent.getState() == LOW && switch_wand.getState() == LOW && b_mode_original_toggle_sounds_enabled == true) {
                stopEffect(S_WAND_HEATDOWN);
                stopEffect(S_WAND_HEATUP_ALT);
                stopEffect(S_WAND_HEATUP);
                playEffect(S_WAND_HEATDOWN);
              }

              // Start the power on indicator timer if enabled.
              if(b_power_on_indicator == true) {
                ms_power_indicator.start(i_ms_power_indicator);
              }
            break;

            default:
              // Do nothing.
            break;
          }
        break;

        case P_MANUAL_OVERHEAT:
          if(WAND_STATUS == MODE_ON && WAND_ACTION_STATUS != ACTION_SETTINGS && WAND_ACTION_STATUS != ACTION_OVERHEATING) {
            if(b_pack_on == true && b_pack_alarm != true && b_overheat_enabled == true) {
              startVentSequence();
            }
          }
        break;

        case P_MASTER_AUDIO_SILENT_MODE:
          // Remember the current master volume level.
          i_volume_revert = i_volume_master;

          // The pack is telling us to be silent.
          i_volume_master = i_volume_abs_min;
          w_trig.masterGain(i_volume_master);
        break;

        case P_MASTER_AUDIO_NORMAL:
          // The pack is telling us to revert the volume to normal.
          i_volume_master = i_volume_revert;
          w_trig.masterGain(i_volume_master);
        break;

        case P_RIBBON_CABLE_ON:
          b_pack_ribbon_cable_on = true;

          if(WAND_STATUS == MODE_ON && b_pack_alarm != true && WAND_ACTION_STATUS != ACTION_OVERHEATING) {
            soundIdleLoop(true);

            if(getNeutronaWandYearMode() == SYSTEM_AFTERLIFE || getNeutronaWandYearMode() == SYSTEM_FROZEN_EMPIRE) {
              stopEffect(S_BOOTUP);
              playEffect(S_BOOTUP);

              if(switch_vent.getState() == HIGH) {
                afterLifeRamp1();
              }
              else {
                stopAfterLifeSounds();
              }
            }
          }
        break;

        case P_RIBBON_CABLE_OFF:
          b_pack_ribbon_cable_on = false;

          if(WAND_STATUS == MODE_ON && b_pack_alarm == true && WAND_ACTION_STATUS != ACTION_OVERHEATING) {
            switch(getNeutronaWandYearMode()) {
              case SYSTEM_1984:
              case SYSTEM_1989:
                // Nothing for now.
              break;

              case SYSTEM_AFTERLIFE:
              case SYSTEM_FROZEN_EMPIRE:
              default:
                  stopEffect(S_WAND_SHUTDOWN);
                  playEffect(S_WAND_SHUTDOWN);

                if(switch_vent.getState() == HIGH) {
                  stopAfterLifeSounds();
                  playEffect(S_AFTERLIFE_WAND_RAMP_DOWN_1, false, i_volume_effects - 1);

                  if(b_extra_pack_sounds == true) {
                    wandSerialSend(W_EXTRA_WAND_SOUNDS_STOP);
                    wandSerialSend(W_AFTERLIFE_GUN_RAMP_DOWN_1);
                  }
                }
              break;
            }
          }
        break;

        case P_ALARM_ON:
          // Alarm is on.
          b_pack_alarm = true;

          if(WAND_STATUS != MODE_ERROR) {
            if(WAND_STATUS == MODE_ON) {
              digitalWrite(led_hat_2, HIGH); // Turn on hat light 2.
            }

            ms_hat_2.start(i_hat_2_delay); // Start the hat light 2 blinking timer.

            if(WAND_STATUS == MODE_ON && FIRING_MODE == SETTINGS) {
              // If the wand is in settings mode while the alarm is activated, exit the settings mode.
              wandSerialSend(W_PROTON_MODE);
              FIRING_MODE = PROTON;
              WAND_ACTION_STATUS = ACTION_IDLE;
            }

            if(WAND_STATUS == MODE_ON) {
              prepBargraphRampDown();
            }
          }
        break;

        case P_ALARM_OFF:
          if(WAND_STATUS != MODE_ERROR) {
            digitalWrite(led_hat_2, LOW); // Turn off hat light 2.

            ms_hat_2.stop();

            if(WAND_STATUS == MODE_ON) {
              switch(SYSTEM_MODE) {
                case MODE_ORIGINAL:
                  if(switch_vent.getState() == LOW && switch_wand.getState() == LOW && switch_activate.getState() == LOW && b_pack_alarm == true) {
                    b_pack_alarm = false;

                    prepBargraphRampUp();
                  }
                break;

                case MODE_SUPER_HERO:
                default:
                  b_pack_alarm = false;

                  prepBargraphRampUp();
                break;
              }
            }
          }

          // Alarm is off.
          b_pack_alarm = false;
        break;

        case P_WARNING_CANCELLED:
          // Pack is telling wand to cancel any overheat warnings.
          // First, stop the timers which trigger the overheat.
          ms_overheat_initiate.stop();
          ms_overheating.stop();
          ms_hat_1.stop();
          ms_hat_2.stop();

          if(b_firing == true) {
            // Keep both lights on if still firing.
            digitalWrite(led_hat_1, HIGH);
            digitalWrite(led_hat_2, HIGH);
          }

          // Next, reset the cyclotron speed on all devices.
          wandSerialSend(W_CYCLOTRON_NORMAL_SPEED);
          cyclotronSpeedRevert();
        break;

        case P_VOLUME_SOUND_EFFECTS_INCREASE:
          // Increase effects volume.
          increaseVolumeEffects();
        break;

        case P_VOLUME_SOUND_EFFECTS_DECREASE:
          // Decrease effects volume.
          decreaseVolumeEffects();
        break;

        case P_VOLUME_INCREASE:
          // Increase overall volume.
          increaseVolume();
        break;

        case P_VOLUME_DECREASE:
          // Decrease overall volume.
          decreaseVolume();
        break;

        case P_HANDSHAKE:
          // The pack is asking us if we are still here. Respond back.
          wandSerialSend(W_HANDSHAKE);
        break;

        case P_MUSIC_REPEAT:
          // Repeat music track.
          b_repeat_track = true;
        break;

        case P_MUSIC_NO_REPEAT:
          // Do not repeat the music track.
          b_repeat_track = false;
        break;

        case P_VOLUME_SYNC_EFFECTS:
          i_volume_effects_percentage = recvData.d1;
          i_volume_effects = MINIMUM_VOLUME - (MINIMUM_VOLUME * i_volume_effects_percentage / 100);

          adjustVolumeEffectsGain();
        break;

        case P_VOLUME_SYNC_MASTER:
          i_volume_master_percentage = recvData.d1;
          i_volume_master = MINIMUM_VOLUME - (MINIMUM_VOLUME * i_volume_master_percentage / 100);

          i_volume_revert = i_volume_master;

          w_trig.masterGain(i_volume_master);
        break;

        case P_VOLUME_SYNC_MUSIC:
          i_volume_music_percentage = recvData.d1;
          i_volume_music = MINIMUM_VOLUME - (MINIMUM_VOLUME * i_volume_music_percentage / 100);

          w_trig.masterGain(i_volume_master);
        break;

        case P_VIBRATION_ENABLED:
          // Vibration enabled (from Proton Pack vibration toggle switch).
          b_vibration_enabled = true;

          // Only play the voice if we are not doing a Proton Pack / Neutrona Wand synchronisation.
          if(b_wait_for_pack != true) {
            stopEffect(S_BEEPS_ALT);

            playEffect(S_BEEPS_ALT);

            stopEffect(S_VOICE_VIBRATION_ENABLED);
            stopEffect(S_VOICE_VIBRATION_DISABLED);

            playEffect(S_VOICE_VIBRATION_ENABLED);
          }
        break;

        case P_VIBRATION_DISABLED:
          // Vibration disabled (from Proton Pack vibration toggle switch).
          b_vibration_enabled = false;

          // Only play the voice if we are not doing a Proton Pack / Neutrona Wand synchronisation.
          if(b_wait_for_pack != true) {
            stopEffect(S_BEEPS_ALT);

            playEffect(S_BEEPS_ALT);

            stopEffect(S_VOICE_VIBRATION_DISABLED);
            stopEffect(S_VOICE_VIBRATION_ENABLED);

            playEffect(S_VOICE_VIBRATION_DISABLED);
          }

          vibrationOff();
        break;

        case P_PACK_VIBRATION_ENABLED:
          // Proton Pack Vibration enabled.
          stopEffect(S_BEEPS_ALT);

          playEffect(S_BEEPS_ALT);

          stopEffect(S_VOICE_PROTON_PACK_VIBRATION_FIRING_ENABLED);
          stopEffect(S_VOICE_PROTON_PACK_VIBRATION_ENABLED);
          stopEffect(S_VOICE_PROTON_PACK_VIBRATION_DISABLED);

          playEffect(S_VOICE_PROTON_PACK_VIBRATION_ENABLED);
        break;

        case P_PACK_VIBRATION_DISABLED:
          // Proton Pack Vibration disabled.
          stopEffect(S_BEEPS_ALT);

          playEffect(S_BEEPS_ALT);

          stopEffect(S_VOICE_PROTON_PACK_VIBRATION_FIRING_ENABLED);
          stopEffect(S_VOICE_PROTON_PACK_VIBRATION_ENABLED);
          stopEffect(S_VOICE_PROTON_PACK_VIBRATION_DISABLED);

          playEffect(S_VOICE_PROTON_PACK_VIBRATION_DISABLED);
        break;

        case P_PACK_VIBRATION_FIRING_ENABLED:
          // Proton Pack Vibration firing enabled.
          stopEffect(S_BEEPS_ALT);

          playEffect(S_BEEPS_ALT);

          stopEffect(S_VOICE_PROTON_PACK_VIBRATION_FIRING_ENABLED);
          stopEffect(S_VOICE_PROTON_PACK_VIBRATION_ENABLED);
          stopEffect(S_VOICE_PROTON_PACK_VIBRATION_DISABLED);

          playEffect(S_VOICE_PROTON_PACK_VIBRATION_FIRING_ENABLED);
        break;

        case P_MODE_FROZEN_EMPIRE:
          // Play Frozen Empire voice.
          stopEffect(S_VOICE_FROZEN_EMPIRE);
          stopEffect(S_VOICE_AFTERLIFE);
          stopEffect(S_VOICE_1989);
          stopEffect(S_VOICE_1984);

          playEffect(S_VOICE_FROZEN_EMPIRE);
        break;

        case P_MODE_AFTERLIFE:
          // Play Afterlife voice.
          stopEffect(S_VOICE_FROZEN_EMPIRE);
          stopEffect(S_VOICE_AFTERLIFE);
          stopEffect(S_VOICE_1989);
          stopEffect(S_VOICE_1984);

          playEffect(S_VOICE_AFTERLIFE);
        break;

        case P_MODE_1989:
          // Play 1989 voice.
          stopEffect(S_VOICE_FROZEN_EMPIRE);
          stopEffect(S_VOICE_AFTERLIFE);
          stopEffect(S_VOICE_1989);
          stopEffect(S_VOICE_1984);

          playEffect(S_VOICE_1989);
        break;

        case P_MODE_1984:
          // Play 1984 voice.
          stopEffect(S_VOICE_FROZEN_EMPIRE);
          stopEffect(S_VOICE_AFTERLIFE);
          stopEffect(S_VOICE_1989);
          stopEffect(S_VOICE_1984);

          playEffect(S_VOICE_1984);
        break;

        case P_SMOKE_DISABLED:
          // Play smoke disabled voice.
          stopEffect(S_VOICE_SMOKE_DISABLED);
          stopEffect(S_VOICE_SMOKE_ENABLED);

          playEffect(S_VOICE_SMOKE_DISABLED);
        break;

        case P_SMOKE_ENABLED:
          // Play smoke enabled voice.
          stopEffect(S_VOICE_SMOKE_ENABLED);
          stopEffect(S_VOICE_SMOKE_DISABLED);

          playEffect(S_VOICE_SMOKE_ENABLED);
        break;

        case P_CYCLOTRON_COUNTER_CLOCKWISE:
          // Play Cyclotron counter clockwise voice.
          stopEffect(S_VOICE_CYCLOTRON_CLOCKWISE);
          stopEffect(S_VOICE_CYCLOTRON_COUNTER_CLOCKWISE);

          playEffect(S_VOICE_CYCLOTRON_COUNTER_CLOCKWISE);
        break;

        case P_CYCLOTRON_CLOCKWISE:
          // Play Cyclotron clockwise voice.
          stopEffect(S_VOICE_CYCLOTRON_CLOCKWISE);
          stopEffect(S_VOICE_CYCLOTRON_COUNTER_CLOCKWISE);

          playEffect(S_VOICE_CYCLOTRON_CLOCKWISE);
        break;

        case P_CYCLOTRON_SINGLE_LED:
          // Play Single LED voice.
          stopEffect(S_VOICE_THREE_LED);
          stopEffect(S_VOICE_SINGLE_LED);

          playEffect(S_VOICE_SINGLE_LED);
        break;

        case P_CYCLOTRON_THREE_LED:
          // Play 3 LED voice.
          stopEffect(S_VOICE_THREE_LED);
          stopEffect(S_VOICE_SINGLE_LED);

          playEffect(S_VOICE_THREE_LED);
        break;

        case P_VIDEO_GAME_MODE_COLOURS_DISABLED:
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_DISABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_ENABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_POWERCELL_ENABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_CYCLOTRON_ENABLED);

          playEffect(S_VOICE_VIDEO_GAME_COLOURS_DISABLED);
        break;

        case P_VIDEO_GAME_MODE_POWER_CELL_ENABLED:
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_DISABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_ENABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_POWERCELL_ENABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_CYCLOTRON_ENABLED);

          playEffect(S_VOICE_VIDEO_GAME_COLOURS_POWERCELL_ENABLED);
        break;

        case P_VIDEO_GAME_MODE_CYCLOTRON_ENABLED:
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_DISABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_ENABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_POWERCELL_ENABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_CYCLOTRON_ENABLED);

          playEffect(S_VOICE_VIDEO_GAME_COLOURS_CYCLOTRON_ENABLED);
        break;

        case P_VIDEO_GAME_MODE_COLOURS_ENABLED:
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_DISABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_ENABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_POWERCELL_ENABLED);
          stopEffect(S_VOICE_VIDEO_GAME_COLOURS_CYCLOTRON_ENABLED);

          playEffect(S_VOICE_VIDEO_GAME_COLOURS_ENABLED);
        break;

        case P_DIMMING:
          stopEffect(S_BEEPS);
          playEffect(S_BEEPS);
        break;

        case P_CONTINUOUS_SMOKE_5_ENABLED:
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_5_ENABLED);
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_5_DISABLED);
          playEffect(S_VOICE_CONTINUOUS_SMOKE_5_ENABLED);
        break;

        case P_CONTINUOUS_SMOKE_4_ENABLED:
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_4_ENABLED);
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_4_DISABLED);
          playEffect(S_VOICE_CONTINUOUS_SMOKE_4_ENABLED);
        break;

        case P_CONTINUOUS_SMOKE_3_ENABLED:
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_3_ENABLED);
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_3_DISABLED);
          playEffect(S_VOICE_CONTINUOUS_SMOKE_3_ENABLED);
        break;

        case P_CONTINUOUS_SMOKE_2_ENABLED:
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_2_ENABLED);
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_2_DISABLED);
          playEffect(S_VOICE_CONTINUOUS_SMOKE_2_ENABLED);
        break;

        case P_CONTINUOUS_SMOKE_1_ENABLED:
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_1_ENABLED);
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_1_DISABLED);
          playEffect(S_VOICE_CONTINUOUS_SMOKE_1_ENABLED);
        break;

        case P_CONTINUOUS_SMOKE_5_DISABLED:
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_5_DISABLED);
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_5_ENABLED);
          playEffect(S_VOICE_CONTINUOUS_SMOKE_5_DISABLED);
        break;

        case P_CONTINUOUS_SMOKE_4_DISABLED:
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_4_DISABLED);
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_4_ENABLED);
          playEffect(S_VOICE_CONTINUOUS_SMOKE_4_DISABLED);
        break;

        case P_CONTINUOUS_SMOKE_3_DISABLED:
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_3_DISABLED);
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_3_ENABLED);
          playEffect(S_VOICE_CONTINUOUS_SMOKE_3_DISABLED);
        break;

        case P_CONTINUOUS_SMOKE_2_DISABLED:
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_2_DISABLED);
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_2_ENABLED);
          playEffect(S_VOICE_CONTINUOUS_SMOKE_2_DISABLED);
        break;

        case P_CONTINUOUS_SMOKE_1_DISABLED:
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_1_DISABLED);
          stopEffect(S_VOICE_CONTINUOUS_SMOKE_1_ENABLED);
          playEffect(S_VOICE_CONTINUOUS_SMOKE_1_DISABLED);
        break;

        case P_OVERHEAT_STROBE_DISABLED:
          stopEffect(S_VOICE_OVERHEAT_STROBE_DISABLED);
          stopEffect(S_VOICE_OVERHEAT_STROBE_ENABLED);

          playEffect(S_VOICE_OVERHEAT_STROBE_DISABLED);
        break;

        case P_OVERHEAT_STROBE_ENABLED:
          stopEffect(S_VOICE_OVERHEAT_STROBE_ENABLED);
          stopEffect(S_VOICE_OVERHEAT_STROBE_DISABLED);

          playEffect(S_VOICE_OVERHEAT_STROBE_ENABLED);
        break;

        case P_OVERHEAT_LIGHTS_OFF_DISABLED:
          stopEffect(S_VOICE_OVERHEAT_LIGHTS_OFF_DISABLED);
          stopEffect(S_VOICE_OVERHEAT_LIGHTS_OFF_ENABLED);

          playEffect(S_VOICE_OVERHEAT_LIGHTS_OFF_DISABLED);
        break;

        case P_OVERHEAT_LIGHTS_OFF_ENABLED:
          stopEffect(S_VOICE_OVERHEAT_LIGHTS_OFF_ENABLED);
          stopEffect(S_VOICE_OVERHEAT_LIGHTS_OFF_DISABLED);

          playEffect(S_VOICE_OVERHEAT_LIGHTS_OFF_ENABLED);
        break;

        case P_OVERHEAT_SYNC_FAN_DISABLED:
          stopEffect(S_VOICE_OVERHEAT_FAN_SYNC_DISABLED);
          stopEffect(S_VOICE_OVERHEAT_FAN_SYNC_ENABLED);

          playEffect(S_VOICE_OVERHEAT_FAN_SYNC_DISABLED);
        break;

        case P_OVERHEAT_SYNC_FAN_ENABLED:
          stopEffect(S_VOICE_OVERHEAT_FAN_SYNC_ENABLED);
          stopEffect(S_VOICE_OVERHEAT_FAN_SYNC_DISABLED);

          playEffect(S_VOICE_OVERHEAT_FAN_SYNC_ENABLED);
        break;

        case P_POWERCELL_DIMMING:
          stopEffect(S_VOICE_POWERCELL_BRIGHTNESS);
          stopEffect(S_VOICE_CYCLOTRON_BRIGHTNESS);
          stopEffect(S_VOICE_CYCLOTRON_INNER_BRIGHTNESS);

          playEffect(S_VOICE_POWERCELL_BRIGHTNESS);
        break;

        case P_CYCLOTRON_DIMMING:
          stopEffect(S_VOICE_POWERCELL_BRIGHTNESS);
          stopEffect(S_VOICE_CYCLOTRON_BRIGHTNESS);
          stopEffect(S_VOICE_CYCLOTRON_INNER_BRIGHTNESS);

          playEffect(S_VOICE_CYCLOTRON_BRIGHTNESS);
        break;

        case P_INNER_CYCLOTRON_DIMMING:
          stopEffect(S_VOICE_POWERCELL_BRIGHTNESS);
          stopEffect(S_VOICE_CYCLOTRON_BRIGHTNESS);
          stopEffect(S_VOICE_CYCLOTRON_INNER_BRIGHTNESS);

          playEffect(S_VOICE_CYCLOTRON_INNER_BRIGHTNESS);
        break;

        case P_PROTON_STREAM_IMPACT_ENABLED:
          stopEffect(S_VOICE_PROTON_MIX_EFFECTS_ENABLED);
          stopEffect(S_VOICE_PROTON_MIX_EFFECTS_DISABLED);

          playEffect(S_VOICE_PROTON_MIX_EFFECTS_ENABLED);
        break;

        case P_PROTON_STREAM_IMPACT_DISABLED:
          stopEffect(S_VOICE_PROTON_MIX_EFFECTS_ENABLED);
          stopEffect(S_VOICE_PROTON_MIX_EFFECTS_DISABLED);

          playEffect(S_VOICE_PROTON_MIX_EFFECTS_DISABLED);
        break;

        case P_CYCLOTRON_SIMULATE_RING_DISABLED:
          stopEffect(S_VOICE_CYCLOTRON_SIMULATE_RING_DISABLED);
          stopEffect(S_VOICE_CYCLOTRON_SIMULATE_RING_ENABLED);

          playEffect(S_VOICE_CYCLOTRON_SIMULATE_RING_DISABLED);
        break;

        case P_CYCLOTRON_SIMULATE_RING_ENABLED:
          stopEffect(S_VOICE_CYCLOTRON_SIMULATE_RING_DISABLED);
          stopEffect(S_VOICE_CYCLOTRON_SIMULATE_RING_ENABLED);

          playEffect(S_VOICE_CYCLOTRON_SIMULATE_RING_ENABLED);
        break;

        case P_DEMO_LIGHT_MODE_ENABLED:
          stopEffect(S_VOICE_DEMO_LIGHT_MODE_ENABLED);
          stopEffect(S_VOICE_DEMO_LIGHT_MODE_DISABLED);

          playEffect(S_VOICE_DEMO_LIGHT_MODE_ENABLED);
        break;

        case P_DEMO_LIGHT_MODE_DISABLED:
          stopEffect(S_VOICE_DEMO_LIGHT_MODE_DISABLED);
          stopEffect(S_VOICE_DEMO_LIGHT_MODE_ENABLED);

          playEffect(S_VOICE_DEMO_LIGHT_MODE_DISABLED);
        break;

        case P_PROTON_MODE:
          FIRING_MODE = PROTON;
          PREV_FIRING_MODE = SETTINGS;
        break;

        case P_SLIME_MODE:
          FIRING_MODE = SLIME;
          PREV_FIRING_MODE = PROTON;

          setVGMode();
        break;

        case P_STASIS_MODE:
          FIRING_MODE = STASIS;
          PREV_FIRING_MODE = SLIME;

          setVGMode();
        break;

        case P_MESON_MODE:
          FIRING_MODE = MESON;
          PREV_FIRING_MODE = STASIS;

          setVGMode();
        break;

        case P_SPECTRAL_MODE:
          FIRING_MODE = SPECTRAL;
          PREV_FIRING_MODE = PROTON;

          setVGMode();
        break;

        case P_HOLIDAY_MODE:
          FIRING_MODE = HOLIDAY;
          PREV_FIRING_MODE = PROTON;

          setVGMode();
        break;

        case P_SPECTRAL_CUSTOM_MODE:
          FIRING_MODE = SPECTRAL_CUSTOM;
          PREV_FIRING_MODE = PROTON;

          setVGMode();
        break;

        case P_VENTING_MODE:
          FIRING_MODE = VENTING;
          PREV_FIRING_MODE = MESON;

          setVGMode();
        break;

        case P_SETTINGS_MODE:
          FIRING_MODE = SETTINGS;
          PREV_FIRING_MODE = VENTING;

          setVGMode();
        break;

        case P_POWER_LEVEL_1:
          i_power_mode = 1;
          i_power_mode_prev = 1;
        break;

        case P_POWER_LEVEL_2:
          i_power_mode = 2;
          i_power_mode_prev = 2;
        break;

        case P_POWER_LEVEL_3:
          i_power_mode = 3;
          i_power_mode_prev = 3;
        break;

        case P_POWER_LEVEL_4:
          i_power_mode = 4;
          i_power_mode_prev = 4;
        break;

        case P_POWER_LEVEL_5:
          i_power_mode = 5;
          i_power_mode_prev = 5;
        break;

        case P_RGB_INNER_CYCLOTRON_LEDS:
          stopEffect(S_VOICE_RGB_INNER_CYCLOTRON);
          stopEffect(S_VOICE_GRB_INNER_CYCLOTRON);

          playEffect(S_VOICE_RGB_INNER_CYCLOTRON);
        break;

        case P_GRB_INNER_CYCLOTRON_LEDS:
          stopEffect(S_VOICE_GRB_INNER_CYCLOTRON);
          stopEffect(S_VOICE_RGB_INNER_CYCLOTRON);

          playEffect(S_VOICE_GRB_INNER_CYCLOTRON);
        break;

        case P_CYCLOTRON_LEDS_40:
          stopEffect(S_VOICE_CYCLOTRON_40);
          stopEffect(S_VOICE_CYCLOTRON_20);
          stopEffect(S_VOICE_CYCLOTRON_12);

          playEffect(S_VOICE_CYCLOTRON_40);
        break;

        case P_CYCLOTRON_LEDS_20:
          stopEffect(S_VOICE_CYCLOTRON_40);
          stopEffect(S_VOICE_CYCLOTRON_20);
          stopEffect(S_VOICE_CYCLOTRON_12);

          playEffect(S_VOICE_CYCLOTRON_20);
        break;

        case P_CYCLOTRON_LEDS_12:
          stopEffect(S_VOICE_CYCLOTRON_40);
          stopEffect(S_VOICE_CYCLOTRON_20);
          stopEffect(S_VOICE_CYCLOTRON_12);

          playEffect(S_VOICE_CYCLOTRON_12);
        break;

        case P_POWERCELL_LEDS_15:
          stopEffect(S_VOICE_POWERCELL_15);
          stopEffect(S_VOICE_POWERCELL_13);

          playEffect(S_VOICE_POWERCELL_15);
        break;

        case P_POWERCELL_LEDS_13:
          stopEffect(S_VOICE_POWERCELL_15);
          stopEffect(S_VOICE_POWERCELL_13);

          playEffect(S_VOICE_POWERCELL_13);
        break;

        case P_INNER_CYCLOTRON_LEDS_23:
          stopEffect(S_VOICE_INNER_CYCLOTRON_35);
          stopEffect(S_VOICE_INNER_CYCLOTRON_24);
          stopEffect(S_VOICE_INNER_CYCLOTRON_23);
          stopEffect(S_VOICE_INNER_CYCLOTRON_12);

          playEffect(S_VOICE_INNER_CYCLOTRON_23);
        break;

        case P_INNER_CYCLOTRON_LEDS_24:
          stopEffect(S_VOICE_INNER_CYCLOTRON_35);
          stopEffect(S_VOICE_INNER_CYCLOTRON_24);
          stopEffect(S_VOICE_INNER_CYCLOTRON_23);
          stopEffect(S_VOICE_INNER_CYCLOTRON_12);

          playEffect(S_VOICE_INNER_CYCLOTRON_24);
        break;

        case P_INNER_CYCLOTRON_LEDS_35:
          stopEffect(S_VOICE_INNER_CYCLOTRON_35);
          stopEffect(S_VOICE_INNER_CYCLOTRON_24);
          stopEffect(S_VOICE_INNER_CYCLOTRON_23);
          stopEffect(S_VOICE_INNER_CYCLOTRON_12);

          playEffect(S_VOICE_INNER_CYCLOTRON_35);
        break;

        case P_INNER_CYCLOTRON_LEDS_12:
          stopEffect(S_VOICE_INNER_CYCLOTRON_35);
          stopEffect(S_VOICE_INNER_CYCLOTRON_24);
          stopEffect(S_VOICE_INNER_CYCLOTRON_23);
          stopEffect(S_VOICE_INNER_CYCLOTRON_12);

          playEffect(S_VOICE_INNER_CYCLOTRON_12);
        break;

        case P_YEAR_MODE_DEFAULT:
          stopEffect(S_VOICE_YEAR_MODE_DEFAULT);
          stopEffect(S_VOICE_FROZEN_EMPIRE);
          stopEffect(S_VOICE_AFTERLIFE);
          stopEffect(S_VOICE_1984);
          stopEffect(S_VOICE_1989);

          playEffect(S_VOICE_YEAR_MODE_DEFAULT);
        break;

        case P_MUSIC_STOP:
          b_playing_music = false;

          // Stop music
          stopMusic();
        break;

        case P_MUSIC_START:
          if(b_playing_music == true) {
            stopMusic();
          }

          playMusic();
        break;

        case P_MUSIC_PAUSE:
          pauseMusic();
        break;

        case P_MUSIC_RESUME:
          resumeMusic();
        break;

        case P_MUSIC_PLAY_TRACK:
          if(i_music_count > 0 && recvData.d1 >= i_music_track_start) {
            // Music track number to be played.
            i_current_music_track = recvData.d1;
          }
        break;

        case P_SAVE_PREFERENCES_WAND:
          // Writes new preferences back to runtime variables.
          // This action does not save changes to the EEPROM!
          switch(recvData.d[0]) {
            case 0:
            default:
              i_num_barrel_leds = 5;
              WAND_BARREL_LED_COUNT = LEDS_5;
            break;
            case 1:
              i_num_barrel_leds = 29;
              WAND_BARREL_LED_COUNT = LEDS_29;
            break;
            case 2:
              i_num_barrel_leds = 48;
              WAND_BARREL_LED_COUNT = LEDS_48;
            break;
          }

          i_spectral_wand_custom_colour = recvData.d[1];
          i_spectral_wand_custom_saturation = recvData.d[2];
          b_spectral_mode_enabled = recvData.d[3];
          b_holiday_mode_enabled = recvData.d[4];
          b_overheat_enabled = recvData.d[5];
          b_cross_the_streams = recvData.d[6];
          b_cross_the_streams_mix = recvData.d[7];
          b_extra_pack_sounds = recvData.d[8];
          b_quick_vent = recvData.d[9];
          b_vent_light_control = recvData.d[10];
          b_beep_loop = recvData.d[11];
          b_wand_boot_errors = recvData.d[12];

          switch(recvData.d[13]) {
            case 1:
            default:
              WAND_YEAR_MODE = YEAR_DEFAULT;
            break;
            case 2:
              WAND_YEAR_MODE = YEAR_1984;
            break;
            case 3:
              WAND_YEAR_MODE = YEAR_1989;
            break;
            case 4:
              WAND_YEAR_MODE = YEAR_AFTERLIFE;
            break;
            case 5:
              WAND_YEAR_MODE = YEAR_FROZEN_EMPIRE;
            break;
          }

          switch(recvData.d[14]) {
            case 1:
            default:
              WAND_YEAR_CTS = CTS_DEFAULT;
            break;
            case 2:
              WAND_YEAR_CTS = CTS_1984;
            break;
            case 3:
              WAND_YEAR_CTS = CTS_1989;
            break;
            case 4:
              WAND_YEAR_CTS = CTS_AFTERLIFE;
            break;
            case 5:
              WAND_YEAR_CTS = CTS_FROZEN_EMPIRE;
            break;
          }

          b_bargraph_invert = recvData.d[15];
          b_overheat_bargraph_blink = recvData.d[16];

          switch(recvData.d[17]) {
            case 1:
            default:
              BARGRAPH_MODE_EEPROM = BARGRAPH_EEPROM_DEFAULT;
            break;
            case 2:
              BARGRAPH_MODE = BARGRAPH_SUPER_HERO;
              BARGRAPH_MODE_EEPROM = BARGRAPH_EEPROM_SUPER_HERO;
            break;
            case 3:
              BARGRAPH_MODE = BARGRAPH_ORIGINAL;
              BARGRAPH_MODE_EEPROM = BARGRAPH_EEPROM_ORIGINAL;
            break;
          }

          switch(recvData.d[18]) {
            case 1:
            default:
              BARGRAPH_EEPROM_FIRING_ANIMATION = BARGRAPH_EEPROM_ANIMATION_DEFAULT;
            break;
            case 2:
              BARGRAPH_FIRING_ANIMATION = BARGRAPH_ANIMATION_SUPER_HERO;
              BARGRAPH_EEPROM_FIRING_ANIMATION = BARGRAPH_EEPROM_ANIMATION_SUPER_HERO;
            break;
            case 3:
              BARGRAPH_FIRING_ANIMATION = BARGRAPH_ANIMATION_ORIGINAL;
              BARGRAPH_EEPROM_FIRING_ANIMATION = BARGRAPH_EEPROM_ANIMATION_ORIGINAL;
            break;
          }
        break;

        case P_SAVE_PREFERENCES_SMOKE:
          // Writes new preferences back to runtime variables.
          // This action does not save changes to the EEPROM!
          b_overheat_mode_5 = recvData.d[0];
          b_overheat_mode_4 = recvData.d[1];
          b_overheat_mode_3 = recvData.d[2];
          b_overheat_mode_2 = recvData.d[3];
          b_overheat_mode_1 = recvData.d[4];
          i_ms_overheat_initiate_mode_5 = recvData.d[5];
          i_ms_overheat_initiate_mode_4 = recvData.d[6];
          i_ms_overheat_initiate_mode_3 = recvData.d[7];
          i_ms_overheat_initiate_mode_2 = recvData.d[8];
          i_ms_overheat_initiate_mode_1 = recvData.d[9];
        break;

        case P_SAVE_EEPROM_WAND:
          // Commit changes to the EEPROM in the wand controller
          saveLedEEPROM();
          saveConfigEEPROM();
          stopEffect(S_VOICE_EEPROM_SAVE);
          playEffect(S_VOICE_EEPROM_SAVE);
        break;

        default:
          // No-op for anything else.
        break;
      }
    }
  }
}
