
//
// Created by luka on 11/15/15.
//

#include <set>
#include <stdint.h>

#ifndef DNAGSS_IMAPPER_H
#define DNAGSS_IMAPPER_H

class IMapper
{
public:
    virtual std::set<int> lookupMatches(char *seed, unsigned int len) = 0;
};

#endif //DNAGSS_IMAPPER_H
