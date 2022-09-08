#include <string>
#include <vector>
#include <algorithm>

class WhichAreIn
{

public:
	static std::vector<std::string> inArray(std::vector<std::string>& array1, std::vector<std::string>& array2);
};

std::vector<std::string> WhichAreIn::inArray(std::vector<std::string>& array1, std::vector<std::string>& array2) {


    std::vector<std::string> answer;

    for (auto str : array1) {

        unsigned int aLength = str.length();

        for (auto str2 : array2){

            if (str2.length() < aLength) continue;

            for (int i = 0; i < str2.length() - aLength + 1; i++) {

                std::string sub = str2.substr(i, aLength);

                if (sub == str) {
                    bool addThisOne = true;
                    for (auto test : answer) {
                        if (test == str) addThisOne = false;
                    }
                    
                    if(addThisOne) answer.push_back(str);

                }
            }
        }
    }
    std::sort(answer.begin(), answer.end());

    return answer;
}



int main(){
        std::vector<std::string> arr1 = { "arp", "live", "strong" };
        std::vector<std::string> arr2 = { "lively", "alive", "harp", "sharp", "armstrong" };
        std::vector<std::string> sol1 = { "arp", "live", "strong" };
        std::vector<std::string> ans1 = WhichAreIn::inArray(arr1, arr2);
        return 0;
}







