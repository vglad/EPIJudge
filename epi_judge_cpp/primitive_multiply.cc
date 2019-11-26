#include "test_framework/generic_test.h"

uint64_t bitwise_sum(uint64_t x, uint64_t y) {
    uint64_t bit_mask {1}, sum {0}, carry {0}, x_bit{0}, y_bit{0};
    while ((x || y) || carry) {
        x_bit = x & 1; y_bit = y & 1;

        if (x_bit && y_bit) {
            if (carry) sum |= bit_mask;
            else carry = 1;
        } else if (!x_bit && !y_bit) {
            if (carry) { sum |= bit_mask; carry = 0; }
        } else { //(x_bit ^ y_bit) == 1
            if (!carry) sum |= bit_mask;
        }

        x >>= 1; y >>= 1; bit_mask <<= 1;
    }
    return sum;
}

unsigned long long Multiply(unsigned long long x, unsigned long long y) {
//    if (!x || !y) return 0;
//    if (x == 1) return y;
//    if (y == 1) return x;
    auto result = uint64_t {0};
    while (x) {
        if (x & 1) result = bitwise_sum(result, y);
        x >>= 1; y <<= 1;
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_multiply.cc",
                         "primitive_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
