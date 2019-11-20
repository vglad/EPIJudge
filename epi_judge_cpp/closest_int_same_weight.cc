#include "test_framework/generic_test.h"
unsigned long long ClosestIntSameBitCount(unsigned long long x) {
// Solution A
//    uint64_t y = x;
//    const uint64_t compare_bit_mask = 0b11;
//    uint64_t final_bit_mask = compare_bit_mask;
//    while (y) {
//        const uint64_t compare_result = y & compare_bit_mask;
//        if (compare_result == 1 || compare_result == 2) {
//            return x ^ final_bit_mask;
//        }
//        y >>= 1ULL;
//        final_bit_mask <<= 1ULL;
//    }

//Solution B (refactored A)
    uint64_t y = x, bit_mask = 0b11;
    while (y) {
        switch (y & 0b11) {
            case 1 ... 2 : return x ^ bit_mask;  //0b01 or 0b10
            default: { y >>= 1ULL; bit_mask <<= 1ULL; }
        }
    }

//Solution C
//    const uint8_t num_bits = 64;
//    for (uint8_t i = 0; i < num_bits - 1; ++i) {
//        if (((x >> i) & 1) != ((x >> (i + 1)) & 1)) { //if nearest bits not equal
//            x ^= (1ULL << i) | (1ULL << (i + 1));     //swap bits
//            return x;
//        }
//    }

    throw std::invalid_argument("All bits of x are 0 or 1");
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "closest_int_same_weight.cc",
                         "closest_int_same_weight.tsv", &ClosestIntSameBitCount,
                         DefaultComparator{}, param_names);
}
