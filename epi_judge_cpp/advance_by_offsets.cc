#include <vector>

#include "test_framework/generic_test.h"
using std::vector;

bool CanReachEnd(const vector<int>& max_advance_steps) {
	auto maxReachIdx = 0;
	auto lastIdx = max_advance_steps.size() - 1;

	for (auto i = 0; i <= maxReachIdx && i < lastIdx; ++i)
	{
		maxReachIdx = std::max(maxReachIdx, i + max_advance_steps.at(i));
	}

	return maxReachIdx >= lastIdx;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"max_advance_steps"};
  return GenericTestMain(args, "advance_by_offsets.cc",
                         "advance_by_offsets.tsv", &CanReachEnd,
                         DefaultComparator{}, param_names);
}
