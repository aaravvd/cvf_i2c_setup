#include "hal.h"
#include "pupil.h"
#include "map.h"

#define W 160
#define H 120
static uint8_t buf[W*H];

int main(void){
  hal_init();                // clocks, i2c, camera
  map_init();                // coefficients/tables
  cam_config(W,H);
  for(;;){
    cam_capture(buf, W*H);   // grayscale
    pupil_t p = pupil_find(buf, W, H, /*thr=*/40);
    if(p.valid){
      int16_t d_x100 = depth_from_xy(p.x, p.y, W, H); // diopters*100
      uint16_t code  = lens_from_diopter(d_x100);     // lens DAC/VCM
      lens_send(code);
    }
    mcu_sleep_until_frame(); // duty-cycle for power
  }
}
