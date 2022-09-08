#include <vector>
#include <math.h>
#include <algorithm>

class Same {
public:
    static bool comp(std::vector<int>& a, std::vector<int>& b) {
        if (a.size() != b.size()) return false;
        for (size_t i = 0; i < b.size(); i++) if ((double(sqrt(b[i])) - floor(double(sqrt(b[i])))) != 0) return false;
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        for (size_t i = 0; i < a.size(); i++) { 
            if (a[i] != (int)sqrt(b[i])) return false; }
        return true;
    }
};



    int main(){

        std::vector<int> a = { 121, 144, 19, 161, 19, 144, 19, 11 };
        std::vector<int> b = { 14641, 20736, 361, 25921, 361, 20736, 361, 121 };
        bool ans = Same::comp(a, b); // equals true

        a = { 121, 144, 19, 161, 19, 144, 19, 11 };
        b = { 14641, 20736, 361, 25921, 361, 20736, 362, 121 };
        ans = Same::comp(a, b);  //equals false
       
        a = { 121, 144, 19, 161, 19, 144, 19, 11 };
        b = { 121, 14641, 20736, 36100, 25921, 361, 20736, 361 };
        ans = Same::comp(a, b);

        a = { 121, 144, 19, 161, 19, 144, 19, 11 };
        b = { 132, 14641, 20736, 361, 25921, 361, 20736, 361 };
        ans = Same::comp(a, b); //false
        
        a = { 121, 144, 19, 161, 19, 144, 19, 11 };
        b = {121, 14641, 20736, 36100, 25921, 361, 20736, 361};
        ans = Same::comp(a, b); //false
        return 0;
    }
