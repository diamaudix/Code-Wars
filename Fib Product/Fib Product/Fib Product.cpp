#include <vector>
typedef unsigned long long ull;
using namespace std;

class ProdFib
{
public:
    static ull getFibProds(vector<ull>&, vector<ull>&, ull max);
	static vector<ull> productFib(ull prod);
};

vector<ull> ProdFib::productFib(ull prod)
{
    vector<ull> answer = {};   
    vector<ull> fib = {1,1};
    vector<ull> products;
    ull index = getFibProds(fib, products, prod);
    answer.push_back(fib[index - 2]);
    answer.push_back(fib[index - 1]);
    answer.push_back((products[index-2]==prod) ? 1 : 0);
    return answer;
}
ull ProdFib::getFibProds(vector<ull>& fib, vector<ull>& products, ull max)
{
    ull currentProd = 0;
    ull index = 1;
    while (currentProd < max) {
        currentProd = fib[index] * fib[index - 1];
        products.push_back(currentProd);
        fib.push_back(fib[index] + fib[index - 1]);
        ++index;
    }
    return index;
}

int main() {

        vector<ull> result;

            result = ProdFib::productFib(4895);// , { 55, 89, true });
            result = ProdFib::productFib(5895);//, { 89, 144, false });
            result = ProdFib::productFib(74049690);//, { 6765, 10946, 1ULL });
            result = ProdFib::productFib(84049690);//, { 10946, 17711, 0ULL });

	return 0;
}