#include "pupil.h"
pupil_t pupil_find(const uint8_t*img,int w,int h,uint8_t thr){
  uint32_t sx=0, sy=0, n=0;
  for(int y=1;y<h-1;y++){
    int row=y*w;
    for(int x=1;x<w-1;x++){
      uint8_t px=img[row+x];
      if(px < thr){ sx+=x; sy+=y; n++; }
    }
  }
  pupil_t out = {0};
  if(n < (w*h)/200) return out; // not enough dark pixels
  out.x = (float)sx/n; out.y=(float)sy/n; out.valid=1; return out;
}
