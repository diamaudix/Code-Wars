#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

bool alreadyEntered(std::vector<string> &dict, std::string entry) {
    std::vector<std::string>::iterator it2 = dict.begin();
    bool encountered = false;
    while (it2 != dict.end()) {
        if (*it2==entry) encountered = true;
        else it2++;
    }

    return encountered;
}
int getIndex(std::vector<string>& dict, std::string entry) {
    std::vector<std::string>::iterator it3 = dict.begin();
    int index;
    while (it3 != dict.end()) {
        if (*it3 == entry) {
            index = (int)std::distance(dict.begin(), it3);
            it3 = dict.end();
        }
        else it3++;
    }

    return index;
}

std::string encoder(const std::string& data)
{
    
    bool finished = false;

    std::string copyOfData = data;

    std::string::iterator it = copyOfData.begin();

    std::vector<string> dictionary;
    std::string code;

    dictionary.push_back({ "" });

    int sizeOfSubString = 1;
    int startingPoint = 0;
    while (it != copyOfData.end()) {

        //string c = to_string(it);
        cout << *it << endl;
        std::string currentSubString = copyOfData.substr(std::distance(copyOfData.begin(), it), sizeOfSubString);
        if (!alreadyEntered(dictionary, currentSubString)) {
            dictionary.push_back(currentSubString);
            sizeOfSubString = 1;
            int index = getIndex(dictionary,currentSubString);
            code.push_back(index);
            code.push_back(*std::next(it,1));
            
        }
        else {
            sizeOfSubString++;
        }
        it++;
    }

    cout << "finished";
    return data;
}

std::string decoder(const std::string& data)
{
    return data;
}


int main(){
    encoder("ABAABABAABAB");//, Equals("0A0B1A2A4A4B"));
    encoder("ABAABABAABABAA");//, Equals("0A0B1A2A4A4B3"));
    encoder("ABBCBCABABCAABCAABBCAA");//, Equals("0A0B2C3A2A4A6B6"));
    encoder("AAAAAAAAAAAAAAA");//, Equals("0A1A2A3A4A"));
    encoder("ABCABCABCABCABCABC");//, Equals("0A0B0C1B3A2C4C7A6"));
    encoder("ABCDDEFGABCDEDBBDEAAEDAEDCDABC");//, Equals("0A0B0C0D4E0F0G1B3D0E4B2D10A1E4A10D9A2C"));

    decoder("0A0B1A2A4A4B");//, Equals("ABAABABAABAB"));
    decoder("0A0B1A2A4A4B3");//, Equals("ABAABABAABABAA"));
    decoder("0A0B2C3A2A4A6B6");//, Equals("ABBCBCABABCAABCAABBCAA"));
    decoder("0A1A2A3A4A");//, Equals("AAAAAAAAAAAAAAA"));
    decoder("0A0B0C1B3A2C4C7A6");//, Equals("ABCABCABCABCABCABC"));
    decoder("0A0B0C0D4E0F0G1B3D0E4B2D10A1E4A10D9A2C");//, Equals("ABCDDEFGABCDEDBBDEAAEDAEDCDABC"));

        return 0;

}