#include "../include/trap.h"

int main()
{
  int test_round = 10;
  char prefix[] = "He";
  int prefix_len = STRLEN(prefix);

  for (int i = 0; i < test_round; i++) {
    int suffix_len = rand() % 5 + 1;
    char suffix_str[7] = "\0";
    char* suffix = rand_str(suffix_str, suffix_len);
    char concat[10] = "\0";
    memmove(concat, prefix, prefix_len);

    strcat(concat, suffix);

    for (int j = 0; j < prefix_len; j++) {
      assert(concat[j] == prefix[j]);
    }
    for (int j = prefix_len; j < prefix_len + suffix_len; j++) {
      assert(concat[j] == suffix[j - prefix_len]);
    }
    assert(concat[prefix_len + suffix_len] == '\0');
  }
}