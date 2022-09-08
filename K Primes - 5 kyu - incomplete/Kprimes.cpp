#include <vector>
#include <math.h>
class KPrimes
{
public:
    static std::vector<long long> countKprimes(int k, long long start, long long end);
    static std::vector<long long> getFactors(long long n);
    static bool isPrime(long long n);
    static int puzzle(int s);
};

std::vector<long long> KPrimes::getFactors(long long n) {
    std::vector<long long> factors = {};
    long long limit = sqrt(n);
    for (long long i = 2; i <= limit; i++)
    {
        if (KPrimes::isPrime(i)) {

            while (n % i == 0) {

                factors.push_back(i);
                n = n / i;
                if (KPrimes::isPrime(n))
                {
                    factors.push_back(n);

                }
            }
        }       
    } 
    
    return factors;
}
bool KPrimes::isPrime(long long m) {
    for (long long j = 2; j < (long long)floor(sqrt((double)m)); j++) {
        if (m % j == 0) {
            return false;
        }
    }
    return true;
}

std::vector<long long> KPrimes::countKprimes(int k, long long start, long long end) {


    

    std::vector<long long> solution = {};
    
    for (long long i = start; i <= end; i++) {
        
        std::vector<long long> test = KPrimes::getFactors(i);

        if (test.size() == k) {
            solution.push_back(i);
        }
        

    }
    
    
    return solution;
}




void dotest(int k, long long start, long long nd, std::vector<long long> expected)
{
    KPrimes::countKprimes(k, start, nd);
}

int main() {


    std::vector<long long> sol = { 4,6,9,10,14,15,21,22,25,26,33,34,35,38,39,46,49,51,55,57,58,62,65,69,74,77,82,85,86,87,91,93,94,95 };
    dotest(2, 0, 100, sol);
    sol = { 8, 12, 18, 20, 27, 28, 30, 42, 44, 45, 50, 52, 63, 66, 68, 70, 75, 76, 78, 92, 98, 99 };
    dotest(3, 0, 100, sol);

    return 0;
}
