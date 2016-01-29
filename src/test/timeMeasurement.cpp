#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

#define MEASURES 10

string to_str(int number) {
  string str = "";
  while (number > 0) {
    char digit = (number % 10) + '0';
    str.append(&digit);
    number /= 10;
  }
  reverse(str.begin(), str.end());
  return str;
}

int main(int args, char** argc) {

  double total = 0;
  double minTime = 1000;
  double maxTime = 0;
  for (int i = 0; i < MEASURES; i++) {
    string generator = "./bin/gen > timeM.in";
    system (generator.c_str());
    system ("./bin/gsa 1 < timeM.in > timeM.out");
    FILE *f = fopen("timeM.out", "r");
    double current; fscanf (f, "%lf", &current);
    fclose(f);
    total += current;
    minTime = min(minTime, current);
    maxTime = max(maxTime, current);
  }

  printf ("Total number of measures: %d\n", MEASURES);
  printf ("Minimal time: %.3f s\n", minTime);
  printf ("Maximal time: %.3f s\n", maxTime);
  printf ("Total average time %.3f s\n", total / MEASURES);

  return 0;
}
