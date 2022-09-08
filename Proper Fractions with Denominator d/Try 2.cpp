#include <functional>
#include <vector>
using namespace std;
long properFractions(long n){

    if (n == 1) return 0;
    if (n == 2) return 1;
    vector<long> p = {};
    function<void(long)> getPrimes = [&p](long a) {
        for (int i = 2; i * i <= a; i += 2) { 
            while (!(a % i)) {
                if((p.empty()) || p.back() != i) p.push_back(i);
                a /= i;
            }
            if (i == 2) i--;
        } 
        if (std::find(p.begin(), p.end(), a) ==p.end() && a != 1) p.push_back(a);
    };
   
    getPrimes(n);
    double phi = 1;
    for (auto i : p) phi *= (1 - (1 / (double)i));
    return (long)(phi * n);
}

int main() {
    long ans;

    ans = properFractions(5); // Equals(4));
    ans = properFractions(6);
    ans = properFractions(7);
    ans = properFractions(8);
    ans = properFractions(9); //equals 
    ans = properFractions(10);
    ans = properFractions(31); // Equals(30));
    ans = properFractions(15); // Equals(8));
    ans = properFractions(16); // Equals(8));
    ans = properFractions(25); // Equals(20));

    return 0;
}
