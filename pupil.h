#pragma once
#include <stdint.h>

typedef struct {
    float x;
    float y;
    int valid;   // 1 if pupil found, 0 otherwise
} pupil_t;

// Find pupil using threshold+centroid
pupil_t pupil_find(const uint8_t *img, int w, int h, uint8_t thr);
