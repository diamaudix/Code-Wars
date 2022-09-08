#include <string>
#include <regex>
#include <vector>
//
//std::string AB(char a, char b) {
//    
//    //std::string answ = '\"' + std::toupper(a[0]);// +'.' + std::toupper(b[0]) + '\"';
//    return (std::to_string( (a-48)  + '.'  + (b-48)));
//}

std::string abbrevName(std::string name)
{

	//std::string(*ptr) (char, char);
 //   ptr = AB;
    std::regex regex("\\ ");
    std::vector<std::string> names(std::sregex_token_iterator(name.begin(), name.end(), regex, -1), std::sregex_token_iterator());
    std::string outname(1, '\"');
    outname.append(std::to_string((char)names[0][0]));

	return "";
}


int main() {
    std::string result;
            result = (abbrevName("Sam Harris")); //Equals("S.H"));
            result = (abbrevName("Patrick Feenan")); //Equals("P.F"));
            result = (abbrevName("Evan Cole")); //Equals("E.C"));
            result = (abbrevName("P Favuzzi")); //Equals("P.F"));
            result = (abbrevName("David Mendieta")); //Equals("D.M"));
            return 0;
}