#include <cstdio>
#include <cstdlib>

int main(void) {
  system ("./bin/gen > input.in");
  system ("./bin/brute < input.in > out_b.txt");
  system ("./bin/gsa < input.in > out_u.txt");
  system ("./bin/checker out_b.txt out_u.txt");
  return 0;
}
