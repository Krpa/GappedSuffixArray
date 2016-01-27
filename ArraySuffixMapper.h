//
// Created by luka on 11/15/15.
//

#ifndef DNAGSS_ARRAYSUFFIXMAPPER_H
#define DNAGSS_ARRAYSUFFIXMAPPER_H


#include "IMapper.h"
#include "GappedSuffixArray.h"
#include <vector>

class ArraySuffixMapper: public IMapper {

public:
    ArraySuffixMapper(GappedSuffixArray *array) : array(array) { }

public:

    virtual std::set<int> lookupMatches(char *seed, unsigned int len) override;

    std::vector<int> lookupDeletion(char *seed);
    std::vector<int> lookupInsertion(char *seed);
    std::vector<int> lookupMismatch(char *seed);
    std::pair<int, int> findDeletionLoHi(char *seed);
    std::pair<int, int> findInsertionLoHi(char *seed);
    std::pair<int, int> findMismatchLoHi(char *seed);

private:
    GappedSuffixArray *array;
};


#endif //DNAGSS_ARRAYSUFFIXMAPPER_H
