#include <utility>
#include <vector>
#include <math.h>
#include <numeric>
#include <functional>
using namespace std;
using LLPairs = vector<pair<long long, long long>>;

class SumSquaredDivisors
{
public:
    static LLPairs listSquared(long long m, long long n);
    static vector<long long> getDivisors(long long d);
    static bool isSquare(long long d);
};
bool SumSquaredDivisors::isSquare(long long d)
{
    long double g = static_cast<long double>(d);
    long long sr = (long long)sqrtl(g);
    return (sr*sr == d);
}

LLPairs SumSquaredDivisors::listSquared(long long m, long long n)
{
    LLPairs results = {};
    //auto square = [&](long long a) {return a * a;};

    for (long long i = m; i <= n; i++) {

        vector<long long> divisors = getDivisors(i);
        //long long sum = accumulate(divisors.begin(), divisors.end(), 0, [&](long long a) {return a * a; });
        long long sum = inner_product(divisors.begin(), divisors.end(), divisors.begin(), 0.0);
        
        if (isSquare(sum)) {
            results.push_back(std::make_pair(i, sum));
        }

    }

    
    
    return results;
}

vector<long long> SumSquaredDivisors::getDivisors(long long d)
{
    vector<long long> results = {};

    results.push_back(d);
    if (d!=1) results.push_back(1);

    for (long long i = 2; i * i < d; i++) {
        if (!(d % i)) {
            results.push_back(i);
            results.push_back(d / i);
        }
    }
    return results;
}
int main() {

    LLPairs result;

    result = SumSquaredDivisors::listSquared(1, 250); // { {1, 1}, { 42, 2500 }, { 246, 84100 } });
    result = SumSquaredDivisors::listSquared(42, 250); //  { {42, 2500}, {246, 84100} });
    result = SumSquaredDivisors::listSquared(250, 500); //  { {287, 84100} });
    result = SumSquaredDivisors::listSquared(300, 600); //  {});




    return 0;
}