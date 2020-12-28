#include "test_framework/generic_test.h"
double Power(double x, int y) {
    double result {1.0};
    long long pow = y;
    if (y < 0) {
        pow= -pow;
        x = 1 / x;
    }
    while (pow) {
        if (pow & 1LL) result *= x;
        x *= x;
        pow >>= 1LL;
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "power_x_y.cc", "power_x_y.tsv", &Power,
                         DefaultComparator{}, param_names);
}
