#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int getMaxScore(std::vector<int> remaining, int currentScore) {
    if (remaining.size() == 1) {
        return std::max(0, remaining[0]);
    }
    else if (remaining.size() == 2) {
        return std::max({ 0,remaining[0],remaining[1] });
    }
    else {
        int current(0), best(0);
        for (int i = 0; i < (int)remaining.size() - 2; i++) {
            std::vector<int> partialValues(remaining.begin() + i, remaining.end());
            current = getMaxScore(partialValues, 0);
        }
    }

    return 0;
}

int targetGame(const std::vector<int>& values) {
  
    std::vector<int> mutableValues = values;
    int length = (int)values.size();
    int best = 0;
    int current = 0;
    for (int i = 0; i < length - 2; i++) {

        std::vector<int> partialValues(mutableValues.begin() + i, mutableValues.end());
        current = getMaxScore(partialValues, 0);
        if (current > best) best = current;
    }


    return current;
}

int main() {

    int result = 0;
    result = (targetGame({ 1, 2, 3, 4 })); //Equals(6));
    result = (targetGame({ 1, 3, 1 })); //Equals(3));
    result = (targetGame({ 5, 5, 5, 5, 5 })); //Equals(15));
    result = (targetGame({ 36, 42, 93, 29, 0, 33, 15, 84, 14, 24, 81, 11 })); //Equals(327));
    result = (targetGame({ 73, 80, 40, 86, 14, 96, 10, 56, 61, 84, 82, 36, 85 })); //Equals(490));
    result = (targetGame({ 11, 82, 47, 48, 80, 35, 73, 99, 86, 32, 32 })); //Equals(353));
    result = (targetGame({ 26, 54, 36, 35, 63, 58, 31, 80, 59, 61, 34, 54, 62, 73, 89, 7, 98, 91, 78 })); //Equals(615));
    result = (targetGame({ 0, 0, -1, -1 })); //Equals(0));
    result = (targetGame({ 1, 0, 0, 1 })); //Equals(2));
    result = (targetGame({ 5, -2, -9, -4 })); //Equals(5));

    return 0;
}