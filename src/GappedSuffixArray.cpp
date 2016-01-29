//
// Created by Ivan Krpelnik on 14/11/15.
//
#include <string.h>
#include "GappedSuffixArray.h"

GappedSuffixArray::GappedSuffixArray(const char *_ref, unsigned long _refLen, unsigned int _dcPos , unsigned int _shapeLen) {
    ref = _ref;
    refLen = _refLen;
    shapeLen = _shapeLen;
    dcPos = _dcPos;
    GSA = new int[refLen];

    for(int i = 0; i < refLen; i++) {
        GSA[i] = i;
    }

    std::sort(GSA, GSA+refLen, gCMP(this));

//    printf("Gapped:\n");
//    for(int i = 0; i < refLen; i++) {
//        printf("%d:%d ", i, GSA[i]);
//        for(int j = 0; j + GSA[i] < refLen; j++) {
//            printf("%c", ref[j+GSA[i]]);
//        }
//        printf("\n");
//    }
}

bool GappedSuffixArray::gCMP::operator()(const int &a, const int &b) {
    for(int i = 0; i < sa->shapeLen && a + i < sa->refLen && b + i < sa->refLen; i++) {
        if(i == sa->dcPos) {
            continue;
        }
        if(sa->ref[a+i] != sa->ref[b+i]) {
            return sa->ref[a+i] < sa->ref[b+i];
        }
    }
    return a > b;
}

int GappedSuffixArray::lowerBound(char *query) {
    int first = 0;
    int count = refLen;
    int check, step;
    while(count > 0) {
        step = count / 2;
        check = first + step;
        if(compare(query, check) > 0) {
            first = check + 1;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}

// int GappedSuffixArray::lowerBound(char *query) {
//     int lo = 0, hi = refLen - 1, mid, lcpl = 0, lcpr = 0, i, ind;
//     bool movelo;
//     while(lo < hi) {
//         mid = lo + (hi - lo) / 2;
//         ind = GSA[mid];
//         movelo = false;
//         for(
//             i = lcpl < lcpr ? lcpl : lcpr;
//             i < shapeLen && i + ind < refLen;
//             i++
//         ) {
//             if(i == dcPos) continue;
//             if(query[i] < ref[ind + i]) break;
//             if(query[i] > ref[ind + i]) {
//                 movelo = true;
//                 break;
//             }
//         }
//         if(movelo) {
//             lo = mid + 1;
//             lcpl = i;
//         } else {
//             hi = mid;
//             lcpr = i;
//         }
//     }
//     return lo;
// }

// int GappedSuffixArray::upperBound(char *query) {
//     int lo = 0, hi = refLen - 1, mid, lcpl = 0, lcpr = 0, i, ind;
//     bool movehi;
//     while(lo < hi) {
//         mid = lo + (hi - lo) / 2;
//         ind = GSA[mid];
//         movehi = false;
//         for(
//             i = lcpl < lcpr ? lcpl : lcpr;
//             i < shapeLen && i + ind < refLen;
//             i++
//         ) {
//             if(i == dcPos) continue;
//             if(query[i] > ref[ind + i]) break;
//             if(query[i] < ref[ind + i]) {
//                 movehi = true;
//                 break;
//             }
//         }
//         if(movehi) {
//             hi = mid;
//             lcpr = i;
//         } else {
//             lo = mid + 1;
//             lcpl = i;
//         }
//     }
//     return lo;
// }

int GappedSuffixArray::upperBound(char *query) {
    int first = 0;
    int count = refLen;
    int check, step;
    while(count > 0) {
        step = count / 2;
        check = first + step;
        if(compare(query, check) >= 0) {
            first = check + 1;
            count -= step + 1;
        } else {
            count = step;
        }
    }
    return first;
}

int GappedSuffixArray::compare(char *q, int index) {
    int realIndex = GSA[index];
    int length = shapeLen;
    if(refLen - realIndex < length) {
        length = refLen - realIndex;
    }
    for(int i = 0; i < length; ++i) {
        if (i == dcPos) continue;
        if(q[i] < ref[realIndex + i]) {
            return -1;
        } else if(q[i] > ref[realIndex + i]) {
            return 1;
        }
    }
    return length < shapeLen ? 1 : 0;
}
