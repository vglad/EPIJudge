#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
// Given n, return all primes up to and including n.
vector<int> GeneratePrimes(int n) {
	if (n <= 1) return {};
	if (n == 2) return {2};

	std::vector<int> primes{2};

	size_t number = 3;
	while (number <= n) {
		bool is_prime = true;

		if (number % 2 == 0) {
			is_prime = false;
		}
		else {
			const size_t boundary = std::sqrt(number);
			for (size_t i = 3; i <= boundary; i += 2) {
				if (number % i == 0) {
					is_prime = false;
					break;
				}
			}
		}

		if (is_prime) primes.emplace_back(number);

		++number;
	}

  return primes;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n"};
  return GenericTestMain(args, "prime_sieve.cc", "prime_sieve.tsv",
                         &GeneratePrimes, DefaultComparator{}, param_names);
}
