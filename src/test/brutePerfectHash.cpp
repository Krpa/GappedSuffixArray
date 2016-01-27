#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

map<string, vector<int>> M;
string reference;
string shape;
string query;
int shapeLen;
int hashLen;
int n;

int calculateHashLen() {
  int len = 0;
  for (int i = 0; i < shapeLen; i++) {
    if (shape[i] == '0') {
      len++;
    }
  }
  return len;
}

void findPositions(void) {
  for (int i = 0; i + shapeLen <= n; i++) {
    string key = "";
    for (int j = 0; j < shapeLen; j++) {
      if (shape[j] == '1') {
        continue;
      }
      key += reference[i + j];
    }
    M[key].push_back(i);
  }
}

string calcMis(int pos, int len) {
  string mis = "";
  for (int i = 0; i < len; i++) {
    if (shape[i] == '1') {
      continue;
    }
    mis += query[pos + i];
  }
  return mis;
}

string calcDel(int pos) {
  string del = "";
  for (int i = 0; i < hashLen; i++) {
    del += query[pos + i];
  }
  return del;
}

string calcInsM(int pos, int len) {
  string insmm = "";
  for (int i = 0, j = 0; i < len; i++, j++) {
    if (shape[i] == '1') {
      j++;
      continue;
    }
    insmm += query[pos + j];
  }
  return insmm;
}

int main(void) {

  cin >> reference;
  cin >> shape;
  cin >> query;

  n = reference.size();
  shapeLen = shape.size();
  hashLen = calculateHashLen();
  int m = query.size();
  int k = shapeLen - hashLen;

  findPositions();

  for (int i = 0; i + shapeLen <= m; i++) {
    /// match + mismatch query
    string mis = calcMis(i, shapeLen);
    int sizeMM = M[mis].size();
    //cout << "mis: " << mis << endl;
    printf ("%d\n", sizeMM);
    for (int j = 0; j < sizeMM; j++) {
      printf ("%d\n", M[mis][j]);
    }

    /// deletion query
    string del = calcDel(i);
    int sizeD = M[del].size();
    //cout << "del: " << del << endl;
    printf ("%d\n", sizeD);
    for (int j = 0; j < sizeD; j++) {
      printf ("%d\n", M[del][j]);
    }

    /// insertion query
    if (i + shapeLen + k <= m) { /// if possible, ie. there are enough characters
      string insmm = calcInsM(i, shapeLen);
      int sizeIM = M[insmm].size();
      //cout << "insmm: " << insmm << endl;
      printf ("%d\n", sizeIM);
      for (int j = 0; j < sizeIM; j++) {
        printf ("%d\n", M[insmm][j]);
      }
    } else {
      printf ("0\n");
    }
  }


  return 0;
}
