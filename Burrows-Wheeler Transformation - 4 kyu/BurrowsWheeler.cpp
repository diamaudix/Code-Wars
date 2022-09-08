#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;
using std::string;
using std::pair;

pair<string, int> encode(const string& s) {
    if (s.empty()) return { "",0 };
    vector<string> matrix;
    string rotation = s;
    pair<string, int> coded;
    matrix.push_back(rotation);

    for (int i = 0; i < (int)s.size(); i++) {
        std::rotate(rotation.begin(), rotation.end()-1, rotation.end());
        matrix.push_back(rotation);
    }    
    matrix.pop_back();
    std::sort(matrix.begin(), matrix.end());
    string answerString;   
    for (int i = 0; i < (int)matrix.size(); i++) {
        answerString.push_back(matrix[i][matrix.size() - 1]);
        if (matrix[i] == s) coded.second = i;

    }   
    coded.first = answerString;
    return coded;
}

vector<string> getSuffixArray(string str) {
    
    int lastIndex = (int)str.length()-1;
    vector<string> suffixArray;
    for (int i = lastIndex; i >= 0; --i) {
        string suffix = str.substr(lastIndex - i, lastIndex);
        suffixArray.push_back(suffix);
    }
    return suffixArray;

}

string decode(const string& s, int n) {
    if (s.empty()) return { "" };
    string sorted = s;
    sort(sorted.begin(), sorted.end());

    vector<string> codedSuffixArray = getSuffixArray(s);
    vector<string> sortedSuffixArray = getSuffixArray(sorted);
    vector<string> mergedArray(s.size(), "");

    for (int i = 0; i < (int)s.size(); i++) {
        std::copy(codedSuffixArray[i].begin(), codedSuffixArray[i].begin() + 1, back_inserter(mergedArray[i]));
        std::copy(sortedSuffixArray[i].begin(), sortedSuffixArray[i].begin() + 1, back_inserter(mergedArray[i]));
    }
    std::sort(mergedArray.begin(), mergedArray.end());
    
    while (mergedArray[0].size() < s.size()) {
        for (int i = 0; i < (int)s.size(); i++) mergedArray[i].insert(0, 1, codedSuffixArray[i][0]);
        std::sort(mergedArray.begin(), mergedArray.end());
    }
    return mergedArray[n];
}



int main() {

   
typedef pair<string, int> psi;
   
  
    psi ans;
    string ans2;
    string decoded;
  


    ans = encode("UndefinedBehaviorSanitizer:DEADLYSIGNAL== 1 == ERROR : UndefinedBehaviorSanitizer : SEGV on unknown address 0x000000000008 (pc 0x0000004263bd bp 0x7ffe43ca94e0 sp 0x7ffe43ca94b0 T1) == 1 == The signal is caused by a READ memory access.");
    decoded = decode(ans.first, ans.second);

    
    ans = encode("Humble Bundle"); // Equals(psi{ "e emnllbduuHB", 2 }));
    
    ans = encode("Mellow Yellow"); // Equals(psi{ "ww MYeelllloo", 1 }));


    ans2 = decode("nnbbraaaa", 4); // Equals("bananabar"));
    ans2 = decode("e emnllbduuHB", 2); // Equals("Humble Bundle"));
    ans2 = decode("ww MYeelllloo", 1); // Equals("Mellow Yellow"));

    
    string code = "I love you, my sweet snuffleberry, Goksenin!";
    std::cout << "The Original Mesage: " << code << std::endl;
    psi coded = encode(code);
    std::cout << "The coded message is: " << coded.first << std::endl;
    decoded = decode(coded.first, coded.second);
    std::cout << "The decoded message is: " << decoded << std::endl;


    return 0;
}