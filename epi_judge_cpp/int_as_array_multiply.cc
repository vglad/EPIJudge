#include <vector>
#include <algorithm>

#include "test_framework/generic_test.h"
using std::vector;


vector<int> Multiply(vector<int> num1, vector<int> num2) {
	if (num1.front() == 0 || num2.front() == 0) return {0};

	auto sign = num1.front() * num2.front() < 0 ? -1 : 1;
	num1.front() = abs(num1.front());
	num2.front() = abs(num2.front());

	vector<int> v (num1.size() + num2.size(), 0);
	for (int i = num1.size() - 1; i >= 0; --i) {
		for (int j = num2.size() - 1; j >= 0; --j) {
			v.at(i + j + 1) += num1.at(i) * num2.at(j);
			v.at(i + j) += v.at(i + j + 1) / 10;
			v.at(i + j + 1) %= 10;
		}
	}

	auto end = std::find_if_not(v.begin(), v.end(), [] (int num) { return num == 0; });
	v.erase(v.begin(), end);

	v.front() *= sign;
	return v;
}


int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, "int_as_array_multiply.cc",
                         "int_as_array_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
