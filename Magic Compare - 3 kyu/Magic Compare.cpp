//template <typename T>
//
//class Number {
//
//public:
//	T value;
//
//	/* constructors */
//	Number(T v)
//	{
//		value = v;
//	}; // not shown for brevity. seems to work
//
//	Number(); // not shown, sets value to zero
//
//	operator int() const
//	{
//		return value;
//	}
//};
//
//
//// This if you define operator int() (See above)
//
//// template<typename T>
//// bool operator<(Number<T> const & lhs, Number<T> const & rhs)
//// {
////     return lhs.value < rhs.value;
//// }
//
//
//// These two if you dont define operator int()







#include <iostream>
#include <string>
#include <math.h>
using namespace std;

template <typename T>
class Number
{
	
private:
	T value;
	bool isResult;
public:
	Number(T v);
	Number();
	Number(Number<T>&);
	//Number<T> operator+ (Number<T>& rhs);

	bool operator==(Number<T> const& rhs);


	
	Number<T>& operator++(); //->postfix T++
	Number<T> operator++(int); // prefix
	Number<T>& operator--(); //->postfix T++
	Number<T> operator--(int); // prefix
	
	friend ostream& operator<<(ostream& output, const Number<T>& D) {
		output << D.value;
		return output;
	}

	T getValue()const { return value; }
	bool getResult() const { return isResult; }
	void setValue(T t) { value = t; }
	void setResult(bool b) { isResult = b; }
};

template <typename T>
Number<T>::Number(T v) : value(v) {
	isResult = false;
}

template <typename T>
Number<T>::Number() {
	value = 0;
	isResult = false;
}
template <typename T>
Number<T>::Number(Number<T>& c) {
	value = c.value;
	isResult = false;
}



template<typename T>
Number<T> operator<(const Number<T>& lhs, const T rhs)
{
	if(lhs.getResult()==true)

	//Number<T> temp();
	//temp.setResult(true);
	
	return  (lhs.getValue() < rhs ? lhs.getValue() : 999999);
}

template<typename T>
Number<T> operator<(const T lhs, const Number<T>& rhs)
{
	return (lhs < rhs.getValue() ? rhs.getValue() : 999999);
}
template <typename T>

Number<T> operator<(const Number<T>& lhs, const Number<T>& rhs)
{
	Number<T> temp();
	
	return (lhs.getValue() < rhs.getValue() ? rhs.getValue() : -999999);
}
template <typename T>
T operator<(const T lhs, const T rhs)
{
	return (lhs < rhs ? rhs : 0);
}

template <typename T>
Number<T> Number<T>::operator++ (int){ // postfix
	
	/*Number<T> temp = *this;
	temp.value += 1;*/

	this->value += 1;
	return *this;

}
template <typename T>
Number<T>& Number<T>::operator++() { //prefix
	value++;
	return *this;
} // prefix
template <typename T>
Number<T> Number<T>::operator-- (int) { // postfix

	/*Number<T> temp = *this;
	temp.value += 1;*/

	this->value -= 1;
	return *this;

}
template <typename T>
Number<T>& Number<T>::operator--() { //prefix
	value--;
	return *this;
} // prefix
template <typename T>
Number<T> operator* (const T lhs, const Number<T>& rhs) {

	Number<T> temp(lhs * rhs.getValue());
	return temp;
}
template <typename T>
Number<T> operator* (const Number<T>& lhs, const Number<T>& rhs) {

	Number<T> temp(lhs.getValue() * rhs.getValue());
	return temp;
}
template <typename T>
Number<T> operator* (const Number<T>& lhs, const T rhs) {

	Number<T> temp(lhs.getValue() * rhs);
	return temp;
}
template <typename T>
Number<T> operator+ (const T lhs, const Number<T>& rhs) {

	Number<T> temp(lhs + rhs.getValue());
	return temp;
}
template <typename T>
Number<T> operator+ (const Number<T>& lhs, const Number<T>& rhs) {

	Number<T> temp(lhs.getValue() + rhs.getValue());
	return temp;
}
template <typename T>
Number<T> operator+ (const Number<T>& lhs, const T rhs) {

	Number<T> temp(lhs.getValue() + rhs);
	return temp;
}
template <typename T>
Number<T> operator- (const T lhs, const Number<T>& rhs) {

	Number<T> temp(lhs - rhs.getValue());
	return temp;
}
template <typename T>
Number<T> operator- (const Number<T>& lhs, const Number<T>& rhs) {

	Number<T> temp(lhs.getValue() - rhs.getValue());
	return temp;
}
template <typename T>
Number<T> operator- (const Number<T>& lhs, const T rhs) {

	Number<T> temp(lhs.getValue() - rhs);
	return temp;
}
template <typename T>
Number<T> operator/ (const T lhs, const Number<T>& rhs) {

	Number<T> temp(lhs / rhs.getValue());
	return temp;
}
template <typename T>
Number<T> operator/ (const Number<T>& lhs, const Number<T>& rhs) {

	Number<T> temp(lhs.getValue() / rhs.getValue());
	return temp;
}
template <typename T>
Number<T> operator/ (const Number<T>& lhs, const T rhs) {

	Number<T> temp(lhs.getValue() / rhs);
	return temp;
}


int main() {


	//	Number<int> a(10);

	//	bool test1 = a < 20; //works fine

	//	bool test2 = 20 < a; //causes error:cout << sizeof(a) << " " << sizeof(b) << "\n";
	////

	//	Number<int> a(10);

	//	bool test1 = a < 20; //works fine

	//	auto test2 = a * a; //causes error:cout << sizeof(a) << " " << sizeof(b) << "\n";
	//	auto test3 = 5 < a * a;
	//	auto test4 = 5 < a < 30;
	//	auto test5 = 5 < a * a < 30;

	//using Integer = Number<int>;
	//using Float = Number<double>;
	//using Unsigned = Number<unsigned>;
	//using LongLong = Number<long long>;
	//Integer i(3);

	//
	//Integer k(6);
	//Integer h(12);

	////auto d = cos(i);
	//Integer b;
	////b = i + k;
	////Integer c = i * k;
	//auto y = h * k;
	//bool test = i < k;
	////bool test3 = i > k;
	//auto x = h * k + i;
	////x = h * (k + i);
	////auto test3 = k - 6;
	////auto test5 = k < (i * 3);
	//auto test6 = i < k < h;
	//auto test22 = k < i < h;

	////Integer w = i * i*i;

	////bool test7 = i * i < w;
	////Float f = 5.3422;
	////Unsigned g = 55;
	////LongLong l = 2523455463464235234;
	////i++;
	/////** output natural Numbers i,
	//// *  with 0 < i < 5, 5 < i^2 < 17
	//// */
	////++f;
	////test = 6 < i;
	////Integer d = 6 * b;
	//Integer d = 4;
	//bool spungo = 5 < d * d;
	//bool spungo2 = d * d < 17;
	//bool spungo3 = d * d < 15;
	//bool spungo4 = 5 < d * d < 20;
	//bool spungo5 = 5 < d * d < 10;
	//bool spungo6 = 5 < d * d;
	//bool spungo7 = 4 < 5 < 6;
	//bool spungo8 = 6 < 5 < 4;


	//for (Integer j = 0; j < 5; ++j) {
	//	if (5 < j*j < 17) { //< 17
	//		/* will output 3 and 4. */
	//		std::cout << j << std::endl;
	//	}
	//}
	

	return 0;
}







//#include <cmath>
//#include <vector>
//#include <math.h>
//#include <iostream>
//#include <string>
//using namespace std;
//
//
//template <typename... T> auto add(T... args)
//{
//
//    return (... + args);
//
//}
//
//
//template<typename T>
//class Number {
//
//public:
//    T value;
//    Number(T val) :value(val) {
//
//    }
//
//    Number(){
//        value = 0;
//    }
//
//
//    static friend bool operator <(Number<T>& c, Number<T>& d);
//    static friend bool operator >(Number<T>& c, Number<T>& d);
//    static friend Number<T>& operator ++(Number<T>& c);
//    static friend Number<T>& operator --(Number<T>& c);
//    static friend Number<T>& operator *(Number<T>& c);
//    static friend ostream& operator << (ostream& out, Number<T> c);
//};
//
//template <typename T>
//
//Number Number::operator+(T const& lhs, T const& rhs) {
//
//}
//
//
//template <typename T>
//bool operator <(Number<T>& a, T& b) {
//
//    if (a.value < b.value) return true;
//    return false;
//
//}
//
//template <typename T>
//bool operator <(T& b, Number<T>& a ) {
//
//    if (a.value < b.value) return true;
//    return false;
//
//}
//
//
//template <typename T>
//bool operator >(Number<T>& c, T& d) {
//
//    if (c.value > d.value) return true;
//    return false;
//
//}
//template <typename T>
//Number<T>& operator ++(Number<T>&c) {
//
//    c.value = c.value + 1;
//    return *c;
//
//}
//template <typename T>
//Number<T>& operator --(Number<T>&c) {
//
//    c.value = c.value - 1;
//    return *c;
//
//}
//template <typename T>
//Number<T> operator *(Number<T>&c, Number<T>&d) {
//
//    return c.value*d.value;
//
//}
//
//template <typename T>
//ostream& operator << (ostream& out, Number<T> c)
//{
//    return out << c.value;
//}
//
//int main() {
//
//    using Integer = Number<int>;
//    using Integer = Number<int>;
//    using Float = Number<double>;
//    Integer i = 3;
//    Integer k = 6;
//    Integer h = 12;
//
//    Float f = 5.3422;
//    Number<unsigned> g = 55;
//    Number<long long> l = 2523455463464235234;
//
//    Integer b;
//    b = i + k;
// //   bool t = 5 > i;
//   // bool t2 = 5 < i;
//  //  bool  test = (i < 5);
//   // Float f = 13.443;
//  //  Integer j = 5;
//    
//    //j = i * 5;
//
//    //test = (5 > i);
//
//  // std::cout << i << std::endl;
//    //cout << f << endl;
//   /** output natural Numbers i,
//     *  with 0 < i < 5, 5 < i^2 < 17
//     */
//    //for (Integer i = 0; i < 5; ++i) {
//    //    if (5 < (i * i) < 17) {
//    //        /* will output 3 and 4. */
//    //        std::cout << i << std::endl;
//    //    }
//    //}
//    
//    
//    return 0;
//}