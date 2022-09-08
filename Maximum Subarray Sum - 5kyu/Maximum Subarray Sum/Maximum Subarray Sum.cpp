#include <vector>
#include <math.h>
int maxSequence(const std::vector<int>& arr) {
	if (arr.size() == 0) return 0;
	bool negative = true;
	for (int i = 0; i < arr.size(); i++) if (i > 0) negative = false;
	int pivot(0), c(0), maxSum(arr[0]);
	while (pivot < arr.size()&& !negative) {
		c = arr[pivot];
		for (int i = pivot + 1; i < arr.size(); ++i) {
			c += arr[i];
			maxSum = std::max(maxSum, c);
		}
		++pivot;
	}
	return (negative? 0: maxSum);
}


int main() {
	int result;
	result = maxSequence({});// , Equals(0));
	result = maxSequence({ -2, 1, -3, 4, -1, 2, 1, -5, 4 });// , Equals(6));
	return 0;
}