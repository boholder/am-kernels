#include "../include/trap.h"

int main()
{
  char s[] = "Hello World";
  for (int i = 0; i < 11; i++) {
    assert(strlen(s + i) == 11 - i);
  }
}
