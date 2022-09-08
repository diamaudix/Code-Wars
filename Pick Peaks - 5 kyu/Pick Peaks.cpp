#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

struct PeakData {
    vector<int> pos, peaks;
};
PeakData pick_peaks(const std::vector<int>& v) {
    PeakData result;
    for (int i = 1; i < (int)(v.size() - 1); i++) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            if (result.pos.empty() || result.pos.back() != i) {
                result.peaks.push_back(v[i]);
                result.pos.push_back(i);
                continue;
            }
        }
        if (v[i] > v[i - 1] && v[i] == v[i + 1]) {
            for (int j = i + 1; j < (int)(v.size() - 1); j++) {
                if (v[j] == v[j + 1]) continue;
                if (v[j] < v[j + 1]) break;
                if (v[j] > v[j + 1]) {
                    if (result.pos.empty() || ((!result.pos.empty()) && result.pos.back() != i)) {
                        result.peaks.push_back(v[i]);
                        result.pos.push_back(i);
                    }
                }
            }
        }
    }
    return result;
}





int main(){

  
    pick_peaks(std::vector<int> {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 3});
       // expected = { .pos = {3, 7}, .peaks = {6, 3} };
       
        pick_peaks(std::vector<int> {1, 2, 2, 2, 1});
        //expected = { .pos = {1}, .peaks = {2} };
     
        pick_peaks(std::vector<int> {1, 2, 2, 2, 3});
       // expected = { .pos = {}, .peaks = {} };
        
        pick_peaks(std::vector<int> {1, 1, 1, 1, 1, 1, 1});

        
        
        return 0;
}