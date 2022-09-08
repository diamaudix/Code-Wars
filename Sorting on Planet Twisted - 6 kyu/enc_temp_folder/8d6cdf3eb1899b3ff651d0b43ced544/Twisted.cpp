
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector <int> sortTwisted37(vector <int> numbers) {
    vector<int> mod, result;
    const char t = '&', x = '3', y = '7';

    for (size_t i = 0; i < numbers.size(); i++) {
        string s = std::to_string(numbers[i]);
        std::replace(s.begin(), s.end(), x, t);
        std::replace(s.begin(), s.end(), y, x);
        std::replace(s.begin(), s.end(), t, y);
        mod.push_back(std::stoi(s));
    }

    std::sort(mod.begin(), mod.end());

    for (size_t i = 0; i < mod.size(); i++) {
        string s = std::to_string(mod[i]);
        std::replace(s.begin(), s.end(), x, t);
        std::replace(s.begin(), s.end(), y, x);
        std::replace(s.begin(), s.end(), t, y);
        result.push_back(std::stoi(s));
    }

    return result;
}

int main() {
    vector<int> answer;
    vector <int> input1{ 1,2,3,4,5,6,7,8,9 };
    answer = sortTwisted37(input1);// expected1{ 1,2,7,4,5,6,3,8,9 };

    vector <int> input2{ 12,13,14 }; 
    answer = sortTwisted37(input2); //expected2{ 12,14,13 };

    vector <int> input3{ 9,2,4,7,3 }; 
    answer = sortTwisted37(input3); //expected3{ 2,7,4,3,9 };
    
    vector <int> input4{ 39,72,4,37,33, 77, 42 }; 
    answer = sortTwisted37(input4); //expected3{ 2,7,4,3,9 };
}