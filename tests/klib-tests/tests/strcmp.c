#include "../include/trap.h"

void one_longer()
{
  char str[6] = "\0";
  int len = rand() % 5 + 3;
  rand_str(str, len);

  int p1 = rand() % len;
  char s1[10] = "\0";
  strncpy(s1, str, p1);

  int p2 = rand() % len;
  char s2[10] = "\0";
  strncpy(s2, str, p2);

  int ret = strcmp(s1, s2);

  if (p1 == p2) assert(ret == 0);
  if (p1 < p2) assert(ret < 0);
  if (p1 > p2) assert(ret > 0);
}

void same_string()
{
  char str[6] = "\0";
  int len = rand() % 5 + 1;
  rand_str(str, len);
  int ret = strcmp(str, str);
  assert(ret == 0);
}

int main()
{
  int test_round = 10;

  for (int i = 0; i < test_round; i++) {
    one_longer();
    same_string();
  }
}