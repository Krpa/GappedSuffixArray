#include <stdint.h>
#include <iostream>
#include <cstring>
#include "GappedSuffixArray.h"
#include "ArraySuffixMapper.h"

using namespace std;


#define MAXN 1000000
#define QUERY 100000
#define SHAPE 30

char reference[MAXN + 1];
char query[QUERY + 1];
char shape[SHAPE + 1];

void output(int lo, int hi, GappedSuffixArray *index) {
    if (hi - lo > 0) {
        printf("%d\n", hi - lo);
        while(lo < hi) {
            printf("%d\n", index->getGSA()[lo++]);
        }
    } else {
        printf("0\n");
    }
}

int main(int argc, char *argv[]) {
    scanf("%s", reference);
    scanf("%s", shape);
    scanf("%s", query);
    bool time_m = argc > 1;

    unsigned int dcPos;
    unsigned int s_size = strlen(shape);
    for(int i = 0; i < s_size; i++) {
        if(shape[i] == '1') {
            dcPos = i;
            break;
        }
    }

    GappedSuffixArray *index = new GappedSuffixArray(reference, strlen(reference), dcPos, strlen(shape));
    ArraySuffixMapper *mapper = new ArraySuffixMapper(index);

    unsigned int q_size = strlen(query);
    int lo, hi;
    clock_t timeStart = clock();
    for(int i = 0; i + s_size <= q_size; i++) {
        std::pair<int, int> mis = mapper->findMismatchLoHi(query+i);
        lo = mis.first;
        hi = mis.second;
        if(!time_m)
            output(lo, hi, index);

        std::pair<int, int> del = mapper->findDeletionLoHi(query+i);
        lo = del.first;
        hi = del.second;
        if(!time_m)
            output(lo, hi, index);

        if(i + s_size < q_size) {
            std::pair<int, int> ins = mapper->findInsertionLoHi(query + i);
            lo = ins.first;
            hi = ins.second;
            if(!time_m)
                output(lo, hi, index);
        } else {
            if(!time_m)
                printf("0\n");
        }
    }
    clock_t timeEnd = clock();
    if(time_m)
        printf ("%.3f\n", ((double)timeEnd - timeStart) / CLOCKS_PER_SEC);
    return 0;
}
