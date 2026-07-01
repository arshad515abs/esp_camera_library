#include "esp_camera_lib.h"

void setup() {
  Serial.begin(115200);
  if (esp_camera_lib_init(CAMERA_MODEL_AI_THINKER)) {
    Serial.println("Camera initialized successfully!");
  } else {
    Serial.println("Camera init failed!");
  }
}

void loop() {
  camera_fb_t *fb = esp_camera_lib_capture();
  if (fb) {
    Serial.printf("Captured image: %d bytes\n", fb->len);
    esp_camera_lib_return_frame(fb);
  }
  delay(5000);
}
