#include <cstdio>
#include <cstdlib>

int main(void) {
  for (int i = 0; ; i++) {
    printf ("%d) ", i);
    system ("./gen > input%d.in", i);
    system ("./brute < input%d.in > out%d_b.txt", i, i);
    system ("./main < input%d.in > out%d_u.txt", i, i);
    if (system ("./checker out%d_b.txt out%d_u.txt", i, i)) {
      break;
    }
  }

  return 0;
}
