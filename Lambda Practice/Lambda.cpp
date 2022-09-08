#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <functional>

int main() {



	std::vector<int> vecVals = { 3, 4 ,5,66,43,25,243,6,1,3,4,23,2,53,352,522,55,7,5,453,343 };

	int sum = 0;

	std::for_each(vecVals.begin(), vecVals.end(),
		[&](int x) {sum += x; });

	std::cout << "Sum " << sum << std::endl;

	int divisor = 7;

	std::vector<int> vecVals2 = { 3, 4 ,5,66,43,25,243,6,1,3,4,23,2,53,352,522,55,7,5,453,343 };

	std::cout << "List of Values Divisible by: ";
	//std::cin >> divisor;
	std::vector<int> vecDiv;

	std::copy_if(vecVals2.begin(), vecVals2.end(), std::back_inserter(vecDiv), [divisor](int x) { return (x % divisor) == 0; });

	std::vector<int> doubleVec;


	std::for_each(vecVals.begin(), vecVals.end(), [&](int x) {doubleVec.push_back(x * 2); });

	for (auto val : doubleVec) std::cout << val << std::endl;
	std::cout << std::endl;

	std::vector<int> vec1 = { 1,2,3,4,5 };
	std::vector<int> vec2 = { 2,4,6,8,10 };
	std::vector<int> vec3(5);

	transform(vec1.begin(), vec1.end(),
		vec2.begin(), vec3.begin(),
		[](int x, int y) {return x + y; });

	for (auto val : vec3) std::cout << val << std::endl;

	int age = 43;
	bool canIVote = (age >= 18) ? true : false;
	std::cout.setf(std::ios::boolalpha);
	std::cout << "Can Derek Vote? : " << canIVote << std::endl;

	// recursive function within ternary operator

	std::function<int(int)> Fib = [&Fib](int n) { return n < 2 ? n : Fib(n - 1) + Fib(n - 2); };

	std::cout << "Fib 4: " << Fib(4) << std::endl;
	/*

	int fibN;
	std::cout << "How many fibonacci numbers would you like? : ";
	std::cin >> fibN;

	std::function<std::vector<int>(int)> FibGen = [&](int n) { return }
	*/

	std::vector<int> fibSequence = FibGen(10);

	for (auto val : fibSequence) std::cout << val << std::endl;


	#define deb(x) std::cout << #x << " " << x << std::endl;



	return 0;
}
#define deb(x) std::cout << #x << " " << x << std::endl;
template<typename... T>
void read(T&... args) {
    ((std::cin >> args), ...);
}
template<typename... T>
void write(T&... args){
    ((std::cout << args << " "), ...);
}
    template<typename... T>
    void read(T&... args) {
    ((std::cin >> args), ...);
}
 auto dash_fold = [](std::string a, int b) {
                         return std::move(a) + '-' + std::to_string(b);
                     };
