#ifndef _DISJOINTSET_H_
#define _DISJOINTSET_H_

#include <stddef.h>
#include <stdint.h>

typedef struct {
    size_t* parent;
    int count;
} DisjointSet;

void Initialize(DisjointSet set, int number);


#endif
