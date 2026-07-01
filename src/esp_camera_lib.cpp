#include "esp_camera_lib.h"

// Pin configurations for common models
static camera_config_t camera_config;

bool esp_camera_lib_init(int model) {
  // Default config - customize based on model
  camera_config.ledc_channel = LEDC_CHANNEL_0;
  camera_config.ledc_timer = LEDC_TIMER_0;
  camera_config.pin_d0 = 5;
  camera_config.pin_d1 = 18;
  camera_config.pin_d2 = 19;
  camera_config.pin_d3 = 21;
  camera_config.pin_d4 = 36;
  camera_config.pin_d5 = 39;
  camera_config.pin_d6 = 34;
  camera_config.pin_d7 = 35;
  camera_config.pin_xclk = 0;
  camera_config.pin_pclk = 22;
  camera_config.pin_vsync = 25;
  camera_config.pin_href = 23;
  camera_config.pin_sscb_sda = 26;
  camera_config.pin_sscb_scl = 27;
  camera_config.pin_pwdn = -1;
  camera_config.pin_reset = -1;
  camera_config.xclk_freq_hz = 20000000;
  camera_config.pixel_format = PIXFORMAT_JPEG;
  camera_config.frame_size = FRAMESIZE_SVGA;
  camera_config.jpeg_quality = 12;
  camera_config.fb_count = 2;

  // Adjust for specific models if needed
  if (model == CAMERA_MODEL_AI_THINKER) {
    // AI Thinker specific tweaks
  }

  esp_err_t err = esp_camera_init(&camera_config);
  return err == ESP_OK;
}

camera_fb_t* esp_camera_lib_capture() {
  return esp_camera_fb_get();
}

void esp_camera_lib_return_frame(camera_fb_t *fb) {
  esp_camera_fb_return(fb);
}
