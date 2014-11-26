#include <cmath>
#include "simpleproc.h"

double d_abs(double in_val) {
    return std::sqrt(in_val*in_val);
}
double c_abs(double rval, double ival) {
    return std::sqrt((rval*rval)+(ival*ival));
}
