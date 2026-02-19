// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file socd_cleaner.h
 * @brief SOCD Cleaner - enhance WASD for fast inputs for gaming
 *
 * For full documentation, see
 * <https://getreuer.info/posts/keyboards/socd-cleaner>
 */

#pragma once

#include "quantum.h"

#ifdef __cplusplus
extern "C" {
#endif

enum socd_cleaner_resolution {
  // Disable SOCD filtering for this key pair.
  SOCD_CLEANER_OFF,
  // Last input priority with reactivation.
  SOCD_CLEANER_LAST,
  // Neutral resolution. When both keys are pressed, they cancel.
  SOCD_CLEANER_NEUTRAL,
  // Key 0 always wins.
  SOCD_CLEANER_0_WINS,
  // Key 1 always wins.
  SOCD_CLEANER_1_WINS,
  // Sentinel to count the number of resolution strategies.
  SOCD_CLEANER_NUM_RESOLUTIONS,
};

typedef struct {
  uint8_t keys[2];  // Basic keycodes for the two opposing keys.
  uint8_t resolution;  // Resolution strategy.
  bool held[2];  // Tracks which keys are physically held.
} socd_cleaner_t;

/**
 * Handler function for SOCD cleaner.
 *
 * This function should be called from process_record_user(). The function may
 * be called multiple times with different socd_cleaner_t instances to filter
 * more than one SOCD key pair.
 */
bool process_socd_cleaner(uint16_t keycode, keyrecord_t* record,
                          socd_cleaner_t* state);

/** Determines globally whether SOCD cleaner is enabled. */
extern bool socd_cleaner_enabled;

#ifdef __cplusplus
}
#endif
