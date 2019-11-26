#include "test_framework/generic_test.h"
int Divide(int x, int y) {
//brut-force solution
//    int counter {0};
//    while (x >= y) {
//      x -= y;
//      ++counter;
//    }
//    return counter;

//doing more in one iteration
    int result {0};
    int power {32};
    //set y to highest possible power
    uint64_t y_pow {static_cast<uint64_t>(y) << power};

    while (x >= y){
        //find actual highest power
        while (y_pow > x) {
            y_pow >>= 1ULL;
            --power;
        }

        result += 1 << power;
        x -= y_pow;
    }
    return result;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "primitive_divide.cc", "primitive_divide.tsv",
                         &Divide, DefaultComparator{}, param_names);
}
