#include "test_framework/generic_test.h"
long long SwapBits(long long x, int i, int j) {
    //brut-force, can be done without local variables creation
//    auto bit_i = (x >> i) & 1;
//    auto bit_j = (x >> j) & 1;
//
//    x &= ~(1ULL << i);          //set bit in pos i to 0;
//    auto value = bit_j << i;    //shift bit_j to pos i
//    x |= value;                 //set bit in pos i to bit_j
//
//    x &= ~(1ULL << j);
//    value = bit_i << j;
//    x |= value;

    //do not need to perform swap if bit equals
    if (((x >> i) & 1) != ((x >> j) & 1)) {
        auto bit_mask = (1ULL << i) | (1ULL << j);
        x ^= bit_mask;
    }
    return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
