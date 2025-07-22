#ifndef __TRAP_H__
#define __TRAP_H__

#include "am.h"
#include "klib-macros.h"
#include "klib.h"
#include <stdint.h>

// strlen() for string constant
#define STRLEN(CONST_STR) (sizeof(CONST_STR) - 1)

// calculate the length of an array
#define ARRLEN(arr) (int) (sizeof(arr) / sizeof(arr[0]))

__attribute__((noinline))
void check(bool cond) {
  if (!cond) halt(1);
}

#define N 32
uint8_t inc[N]; // 1, 2, 3, ... 32

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

__attribute__((noinline)) char* rand_str(char* input, int len)
{
  for (int i = 0; i < len; i++) {
    input[i] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 62];
  }
  input[len] = '\0';
  return input;
}

#endif
