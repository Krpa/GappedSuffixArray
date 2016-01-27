//
// Created by Ivan Krpelnik on 14/11/15.
//
#include<algorithm>

#ifndef DNAGSS_GAPPEDSUFFIXARRAY_H
#define DNAGSS_GAPPEDSUFFIXARRAY_H


class GappedSuffixArray {

public:
    int *getGSA() const {
        return GSA;
    }

    unsigned int getDcPos() const {
        return dcPos;
    }

    unsigned int getShapeLen() const {
        return shapeLen;
    }

    GappedSuffixArray(const char *_ref, unsigned long _refLen, unsigned int _dcPos, unsigned int _shapeLen);

    int lowerBound(char *query);
    int upperBound(char *query);
    int compare(char *q, int index);

private:

    class gCMP {
    private:
        GappedSuffixArray *sa;
    public:
        gCMP(GappedSuffixArray *sa) : sa(sa) {}
        bool operator()(const int &a, const int &b);
    };



private:
    int *GSA;
    const char *ref;
    unsigned int refLen;
    unsigned int dcPos;
    unsigned int shapeLen;
};


#endif //DNAGSS_GAPPEDSUFFIXARRAY_H
