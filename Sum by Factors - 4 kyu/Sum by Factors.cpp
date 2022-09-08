#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

class SumOfDivided
{
public:
    static std::string sumOfDivided(std::vector<int>& lst);

    static std::vector<int> getFactors(int k);
};

std::vector<int> SumOfDivided::getFactors(int k) {

    std::vector<int> factors;
    if (abs(k) == 1) return {} ;
    if (abs(k) == 2) return { 2 };
    if (abs(k) == 3) return { 3 };

    for (int i = 2; i <= ceil(sqrt(abs(k))); i++) {
        while (k % i == 0) {
            if (factors.empty() || *(factors.end() - 1) != i) factors.push_back(i);
            k /= i;
        }
    }
    if (k != 1) factors.push_back(k);
    return factors;
}


std::string SumOfDivided::sumOfDivided(std::vector<int>& lst) {

    std::vector<int> factorsFound;
    std::vector<int> factorsOfThisNumber;
    std::string answer;
    std::vector<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        factorsOfThisNumber = SumOfDivided::getFactors(*it);
        for (unsigned int i = 0; i < factorsOfThisNumber.size(); i++) {
            factorsOfThisNumber[i] = abs(factorsOfThisNumber[i]);
        }

        
        if (factorsFound.empty()) {
            factorsFound.insert(factorsFound.end(), factorsOfThisNumber.begin(), factorsOfThisNumber.end());
        }
        else
        {
            for (auto i : factorsOfThisNumber) {
                std::vector<int>::iterator it2 = std::find(factorsFound.begin(), factorsFound.end(), i);
                if ((it2 == factorsFound.end()) && (i != 1)) factorsFound.push_back(i);
            }
            
        }
        it++;
    }

    

    std::sort(factorsFound.begin(), factorsFound.end());

    std::vector<int>::iterator it3 = factorsFound.begin();
    std::vector<int>::iterator it4 = lst.begin();
    
    while (it3 < factorsFound.end()) {
        int sum = 0;
        while (it4 != lst.end()) {

            if (*it4 % *it3 == 0) sum += *it4;
            it4++;
        }
        answer.push_back('(');
        answer.append(std::to_string(*it3));
        answer.push_back(' ');
        answer.append(std::to_string(sum));
        answer.push_back(')');

        it3++;
        it4 = lst.begin();
    }
    return answer;
}


int main(){
        std::vector<int> d1 = { 12, 15 };
        std::string ans1 = SumOfDivided::sumOfDivided(d1);
        std::string sol1 = "(2 12)(3 27)(5 15)";
        
    
        return 0;
}