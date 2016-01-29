#!/bin/bash

g++ src/*.cpp
mv src/a.out bin/gsa
g++ -o bin/checker src/test/checker.cpp
g++ -o bin/gen src/test/gen.cpp
g++ -o bin/tester src/test/tester.cpp
g++ -o bin/brute src/test/brutePerfectHash.cpp
g++ -o bin/time_test src/test/timeMeasurement.cpp
