#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

#define MEASURES 10

string to_string(int number) {
  string str = "";
  while (number > 0) {
    char digit = (number % 10) + '0';
    str.append(&digit);
    number /= 10;
  }
  reverse(str.begin(), str.end());
  return str;
}

/*
  Commandline arguments:
    1) seed for generator
*/
int main(int args, char** argc) {

  string seedString = argc[1];
  int seed = atoi(seedString.c_str());

  double total = 0;
  double minTime = 1000;
  double maxTime = 0;
  for (int i = 0; i < MEASURES; i++) {
    string generator = "./gen " + to_string(seed + i) + " > timeM.in";
    system (generator.c_str());
    system ("program < timeM.in > timeM.out");
    FILE *f = fopen("out", "r");
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
