#!/bin/bash

g++ src/*.cpp
mv a.out bin/gsa
g++ -std=c++11 -o bin/checker src/test/checker.cpp
g++ -std=c++11 -o bin/gen src/test/gen.cpp
g++ -std=c++11 -o bin/tester src/test/tester.cpp
g++ -std=c++11 -o bin/brute src/test/brutePerfectHash.cpp
g++ -std=c++11 -o bin/time_test src/test/timeMeasurement.cpp
