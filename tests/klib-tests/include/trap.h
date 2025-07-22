#ifndef __TRAP_H__
#define __TRAP_H__

#include "am.h"
#include "klib-macros.h"
#include "klib.h"
#include <stdint.h>

__attribute__((noinline))
void check(bool cond) {
  if (!cond) halt(1);
}

#define N 32
uint8_t inc[N];

__attribute__((noinline))
void reset() {
  int i;
  for (i = 0; i < N; i ++) {
    inc[i] = i + 1;
  }
}

// 检查[l,r)区间中的值是否依次为val, val + 1, val + 2...
__attribute__((noinline))
void check_seq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(inc[i] == val + i - l);
  }
}

// 检查[l,r)区间中的值是否均为val
__attribute__((noinline))
void check_eq(int l, int r, int val) {
  int i;
  for (i = l; i < r; i ++) {
    assert(inc[i] == val);
  }
}

#endif
