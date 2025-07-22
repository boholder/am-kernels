#include "../include/trap.h"

int main()
{
  uint8_t square_wave[N]; // [0,10): 10, [10,20): 40, [20,32]: 10
  uint8_t all_10[N];      // 10, 10, 10, ... 10

  // init
  for (int i = 0; i < N; i++) {
    inc[i] = i + 1;
    all_10[i] = 10;
    square_wave[i] = i >= 10 && i < 20 ? 40 : 10;
  }

  int l, r;
  for (l = 0; l < N; l++) {
    for (r = l + 1; r <= N; r++) {
      // compare [l, r)
      int ret = memcmp(all_10 + l, square_wave + l, r - l);
      if (l < 10) {
        if (r <= 10) {
          assert(ret == 0);
        } else {
          assert(ret < 0);
        }
      } else if (l < 20) {
        assert(ret < 0);
      } else {
        assert(ret == 0);
      }
    }
  }

  // comparison won't stop at zero bytes
  uint8_t a[4] = {1, 0, 0, 1};
  uint8_t b[5] = {1, 0, 0, 0, 1};
  assert(memcmp(a, b, 4) > 0);
}