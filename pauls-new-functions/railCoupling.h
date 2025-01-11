#include "railSt.h"
#include "miscFunctions.h"
#include "railProcDefines.h"

enum couplingCalcOption {NONE, BASIC, ITERATIVE};

typedef std::valarray<double> vectorDouble;

int railCalculateCoupling(SingleRailTest *railTestData, couplingCalcOption option);