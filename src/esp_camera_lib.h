#ifndef ESP_CAMERA_LIB_H
#define ESP_CAMERA_LIB_H

#include "esp_camera.h"

// Common camera models
define CAMERA_MODEL_AI_THINKER 1
#define CAMERA_MODEL_WROVER_KIT 2
#define CAMERA_MODEL_ESP_EYE 3
// Add more as needed

bool esp_camera_lib_init(int model);
camera_fb_t* esp_camera_lib_capture();
void esp_camera_lib_return_frame(camera_fb_t *fb);

#endif
