#include <cstdio>
#include <cstdlib>

int main(void) {
  for (int i = 0; ; i++) {
    printf ("%d) ", i);
    system ("gen > input.in");
    system ("perfectHash < input.in > out1.txt");
    system ("main < input.in > out2.txt");
    if (system ("checker out1.txt out2.txt")) {
      break;
    }
  }

  return 0;
}
