//
// Created by luka on 11/15/15.
//

#include "ArraySuffixMapper.h"

std::set<int> ArraySuffixMapper::lookupMatches(char *seed, unsigned int len) {
    std::set<int> result;
    for(auto &i : lookupMismatch(seed)) {
        result.insert(i);
    }
    for(auto &i : lookupDeletion(seed)) {
        result.insert(i);
    }
    if(len > array->getShapeLen()) {
        for (auto &i : lookupInsertion(seed)) {
            result.insert(i);
        }
    }
    return result;
}

std::vector<int> ArraySuffixMapper::lookupDeletion(char *seed) {
    std::pair<int, int> p = findDeletionLoHi(seed);
    int lo = p.first;
    int hi = p.second;
    if(hi - lo > 0) {
        std::vector<int> result(hi - lo);
        for (int i = lo; i < hi; i++) {
            result[i - lo] = array->getGSA()[i];
        }
        return result;
    }
    return std::vector<int>();
}

std::vector<int> ArraySuffixMapper::lookupInsertion(char *seed) {
    std::pair<int, int> p = findInsertionLoHi(seed);
    int lo = p.first;
    int hi = p.second;
    if(hi - lo > 0) {
        std::vector<int> result(hi - lo);
        for (int i = lo; i < hi; i++) {
            result[i - lo] = array->getGSA()[i];
        }
        return result;
    }
    return std::vector<int>();
}

std::vector<int> ArraySuffixMapper::lookupMismatch(char *seed) {
    std::pair<int, int> p = findMismatchLoHi(seed);
    int lo = p.first;
    int hi = p.second;
    if(hi - lo > 0) {
        std::vector<int> result(hi - lo);
        for (int i = lo; i < hi; i++) {
            result[i - lo] = array->getGSA()[i];
        }
        return result;
    }
    return std::vector<int>();
}

std::pair<int, int> ArraySuffixMapper::findMismatchLoHi(char *seed) {
    return std::pair<int, int>(array->lowerBound(seed), array->upperBound(seed));
}

std::pair<int, int> ArraySuffixMapper::findInsertionLoHi(char *seed) {
    unsigned int shape_len = array->getShapeLen();
    char query[shape_len];
    int i;
    for(i = 0; i < shape_len && i != array->getDcPos(); i++) {
        query[i] = seed[i];
    }
    query[i] = 'N';
    for(++i; i < shape_len; i++) {
        query[i] = seed[i + 1];
    }
    return std::pair<int, int>(array->lowerBound(query), array->upperBound(query));
}

std::pair<int, int> ArraySuffixMapper::findDeletionLoHi(char *seed) {
    unsigned int shape_len = array->getShapeLen();
    char query[shape_len];
    int i;
    for(i = 0; i < shape_len && i != array->getDcPos(); i++) {
        query[i] = seed[i];
    }
    query[i++] = 'N';
    for(; i < shape_len; i++) {
        query[i] = seed[i-1];
    }
    return std::pair<int, int>(array->lowerBound(query), array->upperBound(query));
}
