//#include <iostream>
//#include <string>
//using namespace std;
//
//
//
//// typename = template parameter
//template<typename VariableName>  //evaluated at compile time.  only created when called.
//
//void Print(VariableName value)  //function doesn't really exist until called
//{
//	cout << value << endl;
//}
//
////template<int N>
//
////class Array
////{
////private:
////
////	//int m_Array[];  // cant do m_Array[size] because stack-allocated array;
////		// templates are evaluated at compile time so they facilitate dynamic allocation
////
////	int m_Array[N];
////public:
////	int getSize() const { return N; }
////};
//template<typename T, int N>
//class Array
//{
//private:
//
//	//int m_Array[];  // cant do m_Array[size] because stack-allocated array;
//		// templates are evaluated at compile time so they facilitate dynamic allocation
//
//	//int m_Array[N];  //variable size at compile time with "N"
//
//	T m_Array[N]; // now TYPE is also variable at compile time!;
//
//public: 
//	
//	T getsize() const { return N; }
//	//int getSize() const { return N; }
//};
//
//
//
////template<typename T>
//
//
//int main() {
//
//
//	// Array<5> array; //5 is the template argument // a version of the class is created which replaces "N" with 5
//	
//	Array <std::string, 5> array;
//	Array <int, 50> array2;
//
//	//cout << array.getSize();
//	std::cin.get();
//
//
//	return 0;
//}
//
//
////where to use:
//
//// lots of different types to avoid overloads
//// uniform buffer with many different types
//
////where to avoid:
//
//// when it gets too complicated
//// when there's a temptation to go crazy
//
//
//// T::size_type*i(T::npos)  - Function Declaration!  
////	T::size type is a type and T::npos is a type 
//	//  returns a pointer to T::size_type
////function i return type T::size_type, name i, and unnamed parameter in parameter list T::npos
//
//
//// T::size_type *i(T::npos);
//// suppose T::size_type is a type and T::npos is a constant, object, or function (anything but a type)
//// now it's an object definition!
//// T::size_type* is the object type, and T::npos is the initializer;
//// this declares "i" as an object of type T::size_type*, initialized with the values T::npos
//// 
//
//// T::size_type * i (T::npos);
//// suppose T::size_type is not a type and T::npos is not a type
//// T::size_type*i(T::npos) is now a multiplication! 
//// T::size_type is now left operand, and i(T::npos) might be a function call or a function-like cast
