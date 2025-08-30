#include "map.h"

// depth = a0 + a1*xn + a2*yn  (xn,yn in [-1,1])
static float a0=150, a1=-60, a2=40; // diopters*100 (placeholder)
static int   slope=120, bias=512;   // lens code = slope*(D) + bias, D in diopters

void map_init(void){ /* later: load from flash */ }

int16_t depth_from_xy(float x,float y,int w,int h){
  float xn = 2.f*x/w - 1.f, yn = 2.f*y/h - 1.f;
  float d  = a0 + a1*xn + a2*yn;          // diopters*100
  if(d<-300) d=-300; if(d>400) d=400;
  return (int16_t)d;
}
uint16_t lens_from_diopter(int16_t dx100){
  int32_t code = slope*(dx100/100) + bias;
  if(code<0) code=0; if(code>1023) code=1023;
  return (uint16_t)code;
}