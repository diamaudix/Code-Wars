typedef unsigned long long ulong;
#include <string>
ulong mystery(ulong n) {
	return n;
}

ulong mysteryInv(ulong n) {
	return n;
}

std::string nameOfMystery() {
	return "";
}


int main() {
    ulong result;

            result = mystery(6); // Equals(5));

            result = mysteryInv(5); // Equals(6));
  
            result = mystery(9); // Equals(13));
 
            result = mysteryInv(13); // Equals(9));

            result = mystery(19); // Equals(26));

            result = mysteryInv(26); // Equals(19));



	return 0;
}