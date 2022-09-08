#include <map>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <iostream>
#include <array>

template<std::size_t S>
int solve(std::array<int, S> a0) {
	
	int a = a0.size();
	return 0; // TODO
}



int main(){
		std::array<int, 4> a2 = { 2, 2, 2, 3 };
		int b = solve(a2);// , Equals(7));
	

		std::array<int, 15> a = { 2, 5, 2, 3, 6, 7, 8, 23, 23, 13, 65, 31, 3, 4, 3 };
		b = solve(a);// , Equals(53));
		std::array<int, 27> a1 = { 6,1,7,4,6,7,1,4,7,1,4,6,6,7,4,1,6,4,7,1,4,5,3,2,1,6,9 };
		b = solve(a1);// , Equals(114));
		return 0;
}