#include "../include/trap.h"

int main()
{
  uint8_t src_arr[N];
  for (int i = 0; i < N; i ++) {
    src_arr[i] = i + 40;
  }

  int l, r;
  for (l = 0; l < N; l++) {
    for (r = l + 1; r <= N; r++) {
      reset();
      memcpy(inc + l, src_arr, r - l);
      check_seq(0, l, 1);
      check_seq(l, r, 40);
      check_seq(r, N, r + 1);
    }
  }
}
