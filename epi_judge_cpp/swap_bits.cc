#include "test_framework/generic_test.h"
#include <bitset>

long long SwapBits(long long x, int i, int j) {
    //A) brut-force, can be done without local variables creation
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

    //B) improved solution
    //do not need to perform swap if bit equals
//    if (((x >> i) & 1) != ((x >> j) & 1)) {
//        const auto bit_mask = (1ULL << i) | (1ULL << j);
//        x ^= bit_mask;
//    }

    //C) using <bitset> STL header
    std::bitset<64> b(x);
    //swap bits
    const bool temp = b[i];
    b[i] = b[j];
    b[j] = temp;
    x = b.to_ullong();

    return x;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "i", "j"};
  return GenericTestMain(args, "swap_bits.cc", "swap_bits.tsv", &SwapBits,
                         DefaultComparator{}, param_names);
}
