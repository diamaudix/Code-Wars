#include <utility>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
class SumFractions
{
public:
    static std::pair <int, int> sumFracts(std::vector<std::vector<int>>& l);
    static int getLCM(int a, int b);
    static int getGCD(int a, int b);
};


std::pair <int, int> SumFractions::sumFracts(std::vector<std::vector<int>>& l) {
    
    std::pair <int, int> answer = {0,1};
    if (l.empty()) return answer;

    int numerator = 0; int denominator;
    unsigned int i = 0;
    int lcm = l[i][1];

    for (i = 1; i < l.size(); i++) {

        lcm = getLCM(lcm, l[i][1]);

    }
    
    denominator = lcm;

    for (i = 0; i < l.size(); i++) {

        numerator += l[i][0] * lcm / l[i][1];
    }
    
    for (unsigned int j = 2; j <= ceil(sqrt(max(numerator, denominator))); j++) {
        while (numerator % j == 0 && denominator % j == 0) {
            numerator /= j; denominator /= j;
        }
    }

    answer = std::make_pair(numerator, denominator);

    return answer;
}

int SumFractions::getLCM(int a, int b) {

    return ((a / getGCD(a, b)) * b);

}

int SumFractions::getGCD(int a, int b) {

    
    if (b == 0) return a;
    else {
        return (getGCD(b, a % b));
    }

}

int main() {

    std::vector<std::vector<int>> a1 = { {1,2}, {2,9}, {3,18}, {4,24}, {6,48} };
    SumFractions::sumFracts(a1);    // {85, 72 };
    std::vector<std::vector<int>> a2 = { {1, 2}, {1, 3}, {1, 4} };
    SumFractions::sumFracts(a2);    // {13, 12 };
    std::vector<std::vector<int>> a3 = { {1, 3}, {5, 3} };
    SumFractions::sumFracts(a3);    // {2, 1 };
    std::vector<std::vector<int>> a4 = { };
    SumFractions::sumFracts(a4);    // {0, 1 };

    return 0;
}

