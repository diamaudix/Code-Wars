#include <vector>
#include <algorithm>

int median(int a, int b, int c) {

	std::vector<int> result = { a,b,c };
	std::sort(result.begin(), result.end());
	return result[1];
}

int main() {

	int test = median(4, 66, -4);
}