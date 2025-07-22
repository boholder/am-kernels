#include "../include/trap.h"

int main()
{
  uint8_t src_arr[N];
  for (int i = 0; i < N; i++) {
    src_arr[i] = i + 40;
  }

  // same as memcpy when src, dst are not overlapping
  int l, r;
  for (l = 0; l < N; l++) {
    for (r = l + 1; r <= N; r++) {
      reset();
      memmove(data + l, src_arr, r - l);
      check_seq(0, l, 1);
      check_seq(l, r, 40);
      check_seq(r, N, r + 1);
    }
  }

  // when overlapping, guarantee that dst is same as src
  for (l = 0; l < N; l++) {
    for (r = l + 1; r <= N - 1; r++) {
      reset();
      memmove(data + l, data + l + 1, r - l);
      check_seq(0, l, 1);
      check_seq(l, r, l + 2);
      check_seq(r, N, r + 1);
    }
  }
}
