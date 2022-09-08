#include <vector>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <iostream>
#include <algorithm> 
#include <math.h>
using namespace std;

class Decomp
{
public:
    static std::vector<long long> decompose(long long input);

    
   

};

class Deconstructer
{

public:
    void deconstruct(long long remainder, long long nextSquare);
    bool duplicates();
    std::vector<long long> answer = {};
    bool solutionFound;
};


std::vector<long long> Decomp::decompose(long long input) {

    std::vector<long long> n;
    
    long long squared = input * input;   
    
    Deconstructer Deconstruction;

    Deconstruction.deconstruct(squared, input - 1);

    n = Deconstruction.answer;
    sort(n.begin(),n.end());

    //n.push_back(input);
    return n;
}

bool Deconstructer::duplicates() {

    const std::vector<long long> sortedVector = answer;
    const bool hasDuplicates = std::adjacent_find(sortedVector.begin(), sortedVector.end()) != sortedVector.end();
    return hasDuplicates;

}

void Deconstructer::deconstruct(long long remainder, long long a) {

    answer.push_back(a);


    long long newRemainder = remainder - (a * a);
    
    if (newRemainder == 0) {  //we are done!       
        
        if (Deconstructer::duplicates()) {
            answer.pop_back();
            return;
        }
        
        solutionFound = true;
        return;
    }
    if ((newRemainder < 0)) {

       // cout << "this branch won't work" << endl;
        answer.pop_back();
        return;
    }
    while ((newRemainder > 0)&&(solutionFound != true)) {

            long long nextA = (long long)floor(sqrt(newRemainder));
            
            if (nextA==a) {
                answer.pop_back();
                return;
            }

            Deconstructer::deconstruct(newRemainder, nextA);
            
            if (a==0) {
                answer.pop_back();
                return;
            } 
    }
}

void testing(long long n, std::vector<long long> sol)
{

    std::vector<long long > solution = Decomp::decompose(n);
    cout << "returned: ";
      
    for (unsigned int i = 0; i < solution.size();i++ ) {
        cout << solution[i]<<  " ,";
    }
    cout << " actual: ";
        
    for (unsigned int i = 0; i < sol.size(); i++) {
        cout << sol[i] << ", ";
    }
    cout << endl;
}

int main()
{
        testing(11, { 1,2,4,10 });
        testing(50, { 1,3,5,8,49 });
        testing(44, { 2,3,5,7,43 });
        testing(2, {});

        return 0;

}
