#include <vector>

#include "test_framework/generic_test.h"
#include "test_framework/timed_executor.h"
using std::vector;

// Returns the number of valid entries after deletion.
int DeleteDuplicates(vector<int>* A_ptr) {
	auto &A = *A_ptr;
	if (A.empty()) return 0;

	auto curIdx = 1;
	for (int i = 1; i < A.size(); ++i)
	{
		if (A.at(curIdx - 1) != A.at(i)) {
			A.at(curIdx) = A.at(i);
			++curIdx;
		}
	}

	return curIdx;
}

vector<int> DeleteDuplicatesWrapper(TimedExecutor& executor, vector<int> A) {
  int end = executor.Run([&] { return DeleteDuplicates(&A); });
  A.resize(end);
  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"executor", "A"};
  return GenericTestMain(
      args, "sorted_array_remove_dups.cc", "sorted_array_remove_dups.tsv",
      &DeleteDuplicatesWrapper, DefaultComparator{}, param_names);
}
