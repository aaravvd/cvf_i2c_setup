#pragma once
#include <stdint.h>

void hal_init(void);
void cam_config(int w,int h);
void cam_capture(uint8_t*buf,int len);
void lens_send(uint16_t code);
void mcu_sleep_until_frame(void);