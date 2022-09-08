

#include <utility>
#include <math.h>
#include <memory>
#include <algorithm>

template <typename T, T ...Values>
constexpr auto seq_max_v =  std::max({Values + ...});

//template<typename... Values1>
//
//void max(Values1... value)
//{
//	return /*  max  */;
//}




int main() {


	int a = 1;
	int b = 2;
	int c = 3;

	int m = std::max({ a, b, c });

    //constexpr int IntArray[] = { 1, 5, 10, 12, 17 };
    //constexpr int min = arrayMin(IntArray);

	auto test = seq_max_v<int, 3, 5, 6, 2, 5>;

//	auto max(3, 5, 6, 2, 7);


    //int test2 = FindMax({4,6,2,3,4,5,55,332,4,214,143,3,42}, 3);
	//auto add = seq_max_v(1, 4.5, 3, 55, 22.34, 51);
	//auto x = add(1, 4.5, 3, 55, 22.34, 51);
	return 0;
}





//
//template <typename T, T... Values>
//constexpr auto seq_max_v = 5;
//
//
//template<typename T, T ... Values1>


//template <typename... T> auto maximumElement(T... Values1) 
//{


//	return 3;
//}

//template<typename T>
//T FindMax(T* arr, size_t n)
//{
//    int max = arr[0];
//
//    for (size_t j = 0; j < n; ++j) {
//        if (arr[j] > max) {
//            max = arr[j];
//        }
//    }
//    return max;
//}

//int FindMax()


//template <typename...T> constexpr auto seq_max_v(T...args) = ... + args;
//
//template <class T>
//constexpr T& constexpr_max(T& a, T& b) {
//    return a < b ? b : a;
//}
//
//template <class T>
//constexpr T& arrayMax_impl(T* begin, T* end) {
//    return begin + 1 == end
//        ? *begin
//        : constexpr_max(*begin, arrayMax_impl(begin + 1, end));
//}
//
//template <class T, std::size_t N>
//constexpr T& arrayMin(T(&arr)[N]) {
//    return arrayMin_impl(arr, arr + N);
//}