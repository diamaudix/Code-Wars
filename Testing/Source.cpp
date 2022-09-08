#include <iostream>
using namespace std;

template <typename T>
class Number
{

private:
	T value;
public:
	Number(T v);
	Number();

	Number<T>& operator++(); //->postfix T++
	Number<T> operator++(int); // prefix

	//Number(Number<T>&);
	T getValue() const { return value; }


	operator T() const noexcept {
		return value;
	}
	//Number<T> operator* (const Number<T>&);



	friend ostream& operator<<(ostream& output, const Number<T>& D) {
		output << D.value;
		return output;
	}


};
/* constructors... */
template <typename T>
Number<T>::Number(T v) : value(v) {}

template <typename T>
Number<T>::Number() {
	value = 0;
}
//template <typename T>
//Number<T>::Number(Number<T>& c) {
//	value = c.value;
//}
template <typename T>
Number<T> Number<T>::operator++ (int) { // postfix

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

template<typename T>
bool operator<(const Number<T>& lhs,const T rhs)
{
	return lhs.getValue() < rhs;
} 

template<typename T>
bool operator<(const T lhs,const Number<T>& rhs)
{
	return lhs < rhs.getValue();
} 
template <typename T>

bool operator<(const Number<T>& lhs,const Number<T>& rhs)
{
	return lhs.getValue() < rhs.getValue();
}


template <typename T>
Number<T> operator* (const T lhs,const Number<T>& rhs) {

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



int main() {
	using Integer = Number<int>;

	using Float = Number<double>;
	for (Integer j = 0; j < 5; ++j) {
		if (5 < j * j < 17) { //< 17
			/* will output 3 and 4. */
			std::cout << j << std::endl;
		}
	}

	//for (Float x = 0; x < 1.0; x += 0.01) {
	//	/** find the interval I inside [0, 1),
	//	 *  where x in I -> sin(x) < exp(x) x < cos(x)
	//	 */
	//	if (sin(x) < (exp(x) * x) < cos(x)) {
	//		std::cout << x << std::endl;
	//	}
	//}

	Float x = 0;// x < 1.0; x += 0.01) {
		/** find the interval I inside [0, 1),
		 *  where x in I -> sin(x) < exp(x) x < cos(x)
		 */
		if (sin(x) < (exp(x) * x) < cos(x)) {
			std::cout << x << std::endl;
		}
	


}