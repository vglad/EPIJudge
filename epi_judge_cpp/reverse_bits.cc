#include "test_framework/generic_test.h"

long long swap_bits(long long x, int i, int j) {
    if (((x >> i) & 1) != ((x >> j) & 1)) {
        const auto bit_mask = (1ULL << i) | (1ULL << j);
        x ^= bit_mask;
    }
    return x;
}
unsigned long long ReverseBits(unsigned long long x) {
//Solution A, copying bits to new variable
//    uint64_t result {0};
//    for (auto i = 0; i <= 63; ++i) {
//        if (x & 1) {
//            result |= 1ULL << (63 - i);
//        }
//        x >>= 1;
//    }
//    return result;

//Solution B, using swap_bits function
    for (uint8_t i = 0; i < 32; ++i) {
        x = swap_bits(x, i, 63 - i);
    }
    return x;
//Solution C, can be done by lookup in array of reverse 16bit ints
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
