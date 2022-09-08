#include <string>
#include <functional>
std::string rot13(std::string msg){
	std::function<char(char)> rotate = [=](char n) { return (n + 13) % 26; };
	for (auto& c : msg) {
		if (c >= 65 && c <= 90) c = rotate((int)c - 65) + 65;
		else if (c >= 97 && c <= 122) c = rotate((int)c - 97) + 97;
	}
	return msg;
}


int main() {
	std::string result;

	result = (rot13("abcdefghijklmnopqrstuvwxyz")); //Equals("grfg"));
	result = (rot13("test")); //Equals("grfg"));
	result = (rot13("Test")); //Equals("Grfg"));
	result = (rot13("AbCd")); //Equals("NoPq"));
	return 0;
}