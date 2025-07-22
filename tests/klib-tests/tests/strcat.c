#include "../include/trap.h"

int main()
{
  char hello[] = "Hello";
  int prefix_len = 5;
  char* names[] = {"World", "Alice", "Booob"};
  char test_field[][11] = {"Hello", "Hello", "Hello"};

  for (int i = 0; i < 3; i++) {
    strcat((char*) test_field[i], names[i]);
    for (int j = 0; j < prefix_len; j++) {
      assert(test_field[i][j] == hello[j]);
    }
    for (int j = prefix_len; j < 10; j++) {
      assert(test_field[i][j] == names[i][j - prefix_len]);
    }
    assert(test_field[i][10] == '\0');
  }
}