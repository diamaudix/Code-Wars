#include <vector>
#include <functional>
#include <numeric>
#include <math.h>
typedef std::vector<long long> KataVector;
using LL = long long;



KataVector John, Ann; //global Variables
LL currentLength = 0;

class Johnann
{
public:
    static KataVector john(LL n);
    static KataVector ann(LL n);
    static LL sumJohn(LL n);
    static LL sumAnn(LL n);
    static void createTable(LL start, LL n);

};


void Johnann::createTable(LL start, LL N)
{
    if (currentLength == 0) { John.push_back(0); Ann.push_back(1); start = 1; }
    else { John.resize(N); Ann.resize(N); }

    for (LL n = start; n <= N; n++) {
        
        LL ta = Ann[n - 1];
        LL tj = John[n - 1];        
        LL Atj = Ann[tj]; 
        John.push_back(n - Atj);
        LL Jta = John[ta];
        Ann.push_back(n - Jta);
    }
}

KataVector Johnann::john(LL n)
{
    if (currentLength == 0) createTable(0, n);
    else if (currentLength < n) createTable(currentLength, n);
    KataVector johnVec(John.begin(), John.begin() + n);
    return johnVec;
}
KataVector Johnann::ann(LL n)
{
    if (currentLength == 0) createTable(0, n);
    else if (currentLength < n) createTable(currentLength, n);
    KataVector AnnVec(Ann.begin(), Ann.begin() + n);
    return AnnVec;
}
LL Johnann::sumAnn(LL n)
{
    if (currentLength == 0) createTable(0, n);
    else if (currentLength < n) createTable(currentLength, n);
    return std::accumulate(Ann.begin(), Ann.begin() + n, 0);
}
LL Johnann::sumJohn(LL n)
{
    if (currentLength == 0) createTable(0, n);
    else if (currentLength < n) createTable(currentLength, n);
    return std::accumulate(John.begin(), John.begin() + n, 0);
}

int main() {

    Johnann::createTable(0, 5000);
    KataVector kv;
    LL sum;

    sum = Johnann::sumAnn(11);
    sum = Johnann::sumAnn(115); 
    sum = Johnann::sumAnn(150); //6930
    sum = Johnann::sumJohn(11);
    sum = Johnann::sumAnn(115); // equals , 4070);
    sum = Johnann::sumAnn(11188);
    sum = Johnann::sumJohn(75);// , 1720);
    sum = Johnann::sumJohn(1000);// , 308819);

    kv = Johnann::ann(6); //equals , { 1, 1, 2, 2, 3, 3 });

    kv = Johnann::john(11); //equals , { 0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6 });

	return 0;
}