#include <cstdio>
#include <map>
using namespace std;

map<int, int> M1;
map<int, int> M2;

bool checkIfSubset(map<int, int> &_subset, map<int, int> _set) {
  for (map<int, int>::iterator it = _subset.begin(); it != _subset.end(); it++) {
    if (it->second > _set[it->first]) {
      printf ("key: %d, in subset freq: %d, in set freq: %d\n", it->first, it->second, _set[it->first]);
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

    if (!checkIfSubset(M2, M1)) {
      return false;
    }
    M1.clear();
    M2.clear();
  }

  return true;
}

int main(int argc, char** argv) {
  /// input files should be in same folder
  FILE *f1 = fopen(argv[1], "r"); /// this should be ours output
  FILE *f2 = fopen(argv[2], "r"); /// this should be yours output

  if (readFile(f1, f2)) {
    printf ("CORRECT!\n");
  } else {
    printf ("%s is not subset of %s!\n", argv[2], argv[1]);
    return 1;
  }

  return 0;
}
