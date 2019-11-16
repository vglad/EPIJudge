#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {

    //brut-force O(n)
//    uint8_t num_bits {0};
//    while (x) {
//      num_bits += x & 1;
//      x >>= 1;
//    }
//    return num_bits & 1;

    //O(k), where k number of set bits in x
//    uint8_t result {0};
//    while (x) {
//        result ^= 1u;     //^ operator changes the result to odd/even
//        x &= (x-1);       //clears the lowest set bit of x
//    }
//    return result;

    //O(log n), the XOR of a group of bits is its parity
    x ^= x >> 32u;
    x ^= x >> 16u;
    x ^= x >> 8u;
    x ^= x >> 4u;
    x ^= x >> 2u;
    x ^= x >> 1u;
    return x & 1;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
