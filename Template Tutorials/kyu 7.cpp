////#include <utility>
////#include <limits>
////#include <assert.h>
////
////
////template <typename T, T ...Values>
////constexpr auto seq_max_v(T Values &values ...) {
////
////}
////
////int main() {
////    seq_max_v<int, -9, -1, 2, 3>;// == 3);
////    seq_max_v<unsigned, 0, 1, 3, 8>;// == 8);
////    return 0;
////}
////using namespace std;
//#include <string>
//#include <vector>
//#include <iostream>
//#include <sstream>
//
//
////template <typename T>
////
////string print(const T& t) {
////
////	stringstream ss;
////	ss << t;
////	return ss.str();
////
////}
//
//template <typename T>
//
//std::string to_string_impl(const T& t) {
//
//	std::stringstream ss;
//	ss << t;
//	return ss.str();
//
//}
//
//
//std::vector<std::string> to_string() //exists to provide an overloaded operator for zeroth case to avoid compile error
//{
//	return {};
//}
//
//template <typename P1, typename ... Param> //require at least one parameter
//
//std::vector<std::string> to_string(const P1 &p1, const Param& ... param ) {
//
//
//	std::vector<std::string> s;
//	s.push_back(to_string_impl(p1));
//
//	const auto remainder = to_string(param...);
//
//	s.insert(s.end(), remainder.begin(), remainder.end());
//
//	return s;
//
//}
//
//
//int main() {
//
//	/*cout << print(to_string(1)) << endl;
//	cout << print("Hello World") << endl;
//	cout << print(to_string(5.3)) << endl;
//*/
//	const auto vec = to_string("hello", 1, 5.3);
//
//	for (const auto &o : vec) {
//		std::cout << o << '\n';
//
//	}
//}
//
