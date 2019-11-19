#include "test_framework/generic_test.h"
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
    uint64_t y = static_cast<uint64_t>(x);
    u_int64_t compare_bit_mask = 3ULL; //0b11
    u_int64_t final_bit_mask = compare_bit_mask;
    while (y) {
        if ((y & compare_bit_mask) == 1) return x ^= final_bit_mask;
        if ((y & compare_bit_mask) == 2) return x ^= final_bit_mask;
        y <<= 1ULL;
        final_bit_mask <<= 1ULL;
    }

  return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
