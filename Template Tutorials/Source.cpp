#include <iostream>
#include <string>
using namespace std;


template <typename... T> auto add(T... args)
{

	return (... + args);

}

int main() {

	auto x = add(1, 2.44, (4 / 5), 2, -4, -9.449194, 24);


	return 0;
}