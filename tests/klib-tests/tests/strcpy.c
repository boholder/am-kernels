#include "../include/trap.h"

int main()
{
  int test_round = 10;

  for (int i = 0; i < test_round; i++) {
    char buf[6] = "\0";
    int len = rand() % 5 + 1;
    char* new_str = rand_str(buf, len);
    char base[6] = "\0";

    strcpy(base, new_str);

    for (int j = 0; j <= len; j++) {
      assert(base[j] == new_str[j]);
    }
  }
}