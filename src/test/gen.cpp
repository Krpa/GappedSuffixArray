/**
  Reference generator.
  It asks for length of reference N as input and outputs random generated reference.
*/

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define NUMOFBASES 4
#define SHAPE 30

char generateBase() {
  int base = rand() % NUMOFBASES;
  char b;
  switch (base) {
    case 0: return 'A';
    case 1: return 'C';
    case 2: return 'T';
    case 3: return 'G';
  }
}

int main(int args, char** argc) {
  int seed = atoi(argc[1]);
  srand(seed);

  // reference
  int n = 1000000; //scanf ("%d", &n);
  //int n = 1000; //scanf ("%d", &n);
  //int n = 10; //scanf ("%d", &n);

  for (int i = 0; i < n; i++) {
    char base = generateBase();
    printf ("%c", base);
  } printf ("\n");

  // shape
  char shape[] = "00000100000";
  //char shape[] = "00100";
  //scanf ("%s", shape);
  printf ("%s\n", shape);
  int shapeLen = strlen(shape);

  //query
  //printf ("%d\n", n);
  int m = 100000; //scanf ("%d", &m);
  //int m = 500; //scanf ("%d", &m);
  //int m = 7; //scanf ("%d", &m);
  for (int i = 0; i < m; i++) {
    char base = generateBase();
    printf ("%c", base);
  } printf ("\n");

  return 0;
}
