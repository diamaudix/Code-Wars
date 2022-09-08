#include <math.h>
#include <vector>
using namespace std;
vector<long long> generateFramework() {
	vector<long long> framework = {0,2,5};
	for (long long k = 3; k <= 58; k ++) {
		long long result = 1 + (k) * ((long long)pow(2,k-1));
		framework.push_back(result);
	}
	return framework;
}

long long f(long long n, vector<long long> &framework) {
	
	long long k = (long long)log2(n);
	long long power = (long long)pow(2, k);

	if (n == 0) return 0;
	if (n == 1) return 1;	
	if ((power!=0) && (n - power == 0)) return framework[k];
	return (n - power) + framework[k] + f(n - power, framework);
	}

long long countOnes(int left, int right)
{
	vector<long long> framework = generateFramework();	
	long long rightAns = f(right, framework);
	long long leftAns = f(left - 1, framework);
	long long ans = rightAns - leftAns;
	return ans;
}

int main() {

	



	long long ans;
	ans = countOnes(4, 7);// , Equals(8));
	ans = countOnes(8, 8);
	ans = countOnes(4, 11);
	ans = countOnes(15, 31);
	 
	
	
	return 0;
}