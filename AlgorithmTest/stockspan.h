#ifndef _STOCKSPAN_H_
#define _STOCKSPAN_H_

#include <stddef.h>
#include <stdbool.h>
#include "arraystack.h"
#include <stdlib.h>

void StockSpanNaiveSolution(size_t* quotes, size_t len, size_t* resultArray);
void StockSpanStackSolution(size_t* quotes, size_t len, size_t* resultArray);

#endif
