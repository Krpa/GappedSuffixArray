#include <cstdio>
#include <map>
using namespace std;

map<int, int> M1;
map<int, int> M2;

bool check(map<int, int> &_set1, map<int, int> _set2) {
  for (map<int, int>::iterator it = _set1.begin(); it != _set1.end(); it++) {
    if (it->second != _set2[it->first]) {
      printf ("key: %d, in gsa set freq: %d, in brute force set freq: %d\n", it->first, it->second, _set1[it->first]);
      return false;
    }
  }
  return true;
}

void readPositions(FILE *f, int size, map<int, int> &M) {
  for (int i = 0; i < size; i++) {
    int a;
    fscanf(f, "%d", &a);
    M[a]++;
  }
}

bool readFile(FILE *f1, FILE *f2) {
  int size1, size2;
  while(fscanf(f1, "%d", &size1) == 1) {
    readPositions(f1, size1, M1);

    fscanf (f2, "%d", &size2);
    readPositions(f2, size2, M2);

    if (!check(M2, M1)) {
      return false;
    }
    M1.clear();
    M2.clear();
  }

  return true;
}

int main(int argc, char** argv) {
  FILE *f1 = fopen(argv[1], "r");
  FILE *f2 = fopen(argv[2], "r");

  if (readFile(f1, f2)) {
    printf ("CORRECT!\n");
  } else {
    printf ("WA!\n");
    return 1;
  }

  return 0;
}
