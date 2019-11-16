#include "test_framework/generic_test.h"
unsigned long long ReverseBits(unsigned long long x) {
    uint64_t result {0};
    for (auto i = 0; i < 64; ++i) {
        if (x & 1) {
            uint64_t y = 1ULL << (63 - i);
            result |= y;
        }
        x >>= 1;
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "reverse_bits.cc", "reverse_bits.tsv",
                         &ReverseBits, DefaultComparator{}, param_names);
}
