#pragma once
#include <stdint.h>

// Init (load calibration coeffs, tables, etc.)
void map_init(void);

// Convert pupil center → depth (diopters*100)
int16_t depth_from_xy(float x, float y, int w, int h);

// Convert depth (diopters*100) → lens actuator code
uint16_t lens_from_diopter(int16_t d_x100);