#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

std::string encode_rail_fence_cipher(const std::string& str, int n) {
    
    size_t m = str.length();
    string code = "";
    vector<vector<string>> railroad (n, vector<string>(m, ""));

    int cycleLength = 2 * (n - 1);
    int midPoint = n - 1;
   
    for (unsigned int i = 0; i<str.size(); i ++){
        int offset = i % cycleLength;
        int fx = abs(offset - (n-1));
        railroad[midPoint - fx][i] = str[i];
    }
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < m; k++) {
            if (railroad[j][k] != "") code.append(railroad[j][k]);
        }
    }  
    return code;
}

std::string decode_rail_fence_cipher(const std::string& str, int n) {
    
    int m = str.length();
    
    vector<vector<string>> railroad(n, vector<string>(m, ""));
    string answer(str.length(), '*');
    
    int cycleLength = 2 * (n - 1);
    int currentRail = 0;
    int answerIndex = 0;
    int codeIndex = 0;
    
   while (currentRail < n) {

       int nextPos = 0;
       int instance = 0;

       while (nextPos < m) {

           if (currentRail == 0) {

               answerIndex = instance * cycleLength;
               answer[answerIndex] = str[codeIndex];
               nextPos = answerIndex + cycleLength;
           }
           else if (currentRail == n - 1) {
               
               answerIndex = instance * cycleLength + (n - 1);
               answer[answerIndex] = str[codeIndex];
               nextPos = answerIndex + cycleLength;
           }
           else {
               int gap;

               if (instance == 0) {
                   answerIndex = currentRail;
               }
               else {
                   if (instance % 2 == 1) {
                       gap = 2 * (n - currentRail - 1);
                       answerIndex += gap;
                   }
                   else {
                       gap = 2 * currentRail;
                       answerIndex += gap;
                   }
               }
               answer[answerIndex] = str[codeIndex];
               nextPos = answerIndex + (instance % 2 == 0 ? (2 * (n - currentRail - 1)) : (2 * currentRail));
           }
           instance++;
           codeIndex++;
       }
       currentRail++;
   }
    return answer;
}


int main(){
        
        string test = encode_rail_fence_cipher("I love my snuggly muffin", 8);// , Equals("WECRLTEERDSOEEFEAOCAIVDEN"));

        test = encode_rail_fence_cipher("WEAREDISCOVEREDFLEEATONCE", 3);// , Equals("WECRLTEERDSOEEFEAOCAIVDEN"));
        test = encode_rail_fence_cipher("Hello, World!", 3);// Equals("Hoo!el,Wrdl l"));
        test = encode_rail_fence_cipher("Hello, World!", 4);// Equals("H !e,Wdloollr"));
        test = encode_rail_fence_cipher("", 3);// , Equals(""));

        test = decode_rail_fence_cipher("H !e,Wdloollr", 4);// Equals("Hello, World!"));
        test = decode_rail_fence_cipher("WECRLTEERDSOEEFEAOCAIVDEN", 3);// Equals("WEAREDISCOVEREDFLEEATONCE"));
        test = decode_rail_fence_cipher("", 3);// , Equals(""));

        return 0;
}
