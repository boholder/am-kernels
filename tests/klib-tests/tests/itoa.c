#include "../include/trap.h"
#include <limits.h>

void assert_str_equal(char* s1, char* s2)
{
  assert(strcmp(s1, s2) == 0);
}

int main()
{
  char buf[100];
  assert_str_equal("0", itoa(buf, 0));
  assert_str_equal("1", itoa(buf, 1));
  assert_str_equal("9999", itoa(buf, 9999));
  assert_str_equal("1234", itoa(buf, 1234));
  assert_str_equal("-9999", itoa(buf, -9999));
  assert_str_equal("-1234", itoa(buf, -1234));
  assert_str_equal("-2147483648", itoa(buf, INT_MIN));
}