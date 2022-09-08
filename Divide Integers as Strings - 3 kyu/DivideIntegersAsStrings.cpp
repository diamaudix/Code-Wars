#include <iostream>
#include <vector>
#include <string>
using namespace std;



vector<string> divide_strings(string a, string b) {
    //return vector<string> {to_string(stoll(a, nullptr, 10) / stoll(b, nullptr, 10)), 
      //                  to_string(stoll(a, nullptr, 10) % stoll(b, nullptr, 10))}; 
   // This might work for the sample tests and maybe even half of the random tests but it won't work for arbitrarily large integers ;-)
    string dividend = "";
    string remainder = "";
    vector<string> answer = { "0","0" };
    long long divisor = stoll(b, nullptr, 10);
   
    string runningRemainder;
    string::iterator it = a.begin();

    while (it != a.end()) {


        runningRemainder.push_back(*it);
    
        long long divInt = stoll(runningRemainder, nullptr, 10);

        if (divInt / divisor) {

            dividend.append(to_string(divInt / divisor));
            runningRemainder = to_string(divInt % divisor);

        }
        else {
            if (!dividend.empty()) dividend.push_back('0');
        }
        it++;
    
    }

    runningRemainder.erase(0, min(runningRemainder.find_first_not_of('0'), runningRemainder.size() - 1));

    remainder = runningRemainder;

    if (dividend.empty()) dividend = "0";

    answer = { dividend, remainder };

    return answer;

}


int main() {

        vector<string> test = divide_strings("565165181616", "16"); // EqualsContainer(vector<string> {"0", "0"}));
        test = divide_strings("0", "5"); // EqualsContainer(vector<string> {"0", "0"}));
        test = divide_strings("4", "5"); // EqualsContainer(vector<string> {"0", "4"}));
        test = divide_strings("10", "2"); // EqualsContainer(vector<string> {"5", "0"}));
        test = divide_strings("20", "3"); // EqualsContainer(vector<string> {"6", "2"}));
        test = divide_strings("60", "5"); // EqualsContainer(vector<string> {"12", "0"}));
        test = divide_strings("219", "11"); // EqualsContainer(vector<string> {"19", "10"}));
        test = divide_strings("729", "9"); // EqualsContainer(vector<string> {"81", "0"}));
        test = divide_strings("1000", "10"); // EqualsContainer(vector<string> {"100", "0"}));
        test = divide_strings("600001", "100"); // EqualsContainer(vector<string> {"6000", "1"}));

        return 0;
}