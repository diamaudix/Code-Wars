#include <vector>
//typedef std::vector<long long> std::vector<long long>;
//using long long = long long;


class Johnann
{
public:
    static std::vector<long long> john(long long n);
    static std::vector<long long> ann(long long n);
    static long long sumJohn(long long n);
    static long long sumAnn(long long n);
};

long long Johnann::sumAnn(long long n)
{
    return 0;
}

int main() {

    std::vector<long long> kv = {};
    long long sum = 0;

    sum = Johnann::sumAnn(115); // equals , 4070);

    //sum = Johnann::sumJohn(75);// , 1720);

    kv = Johnann::ann(6); //equals , { 1, 1, 2, 2, 3, 3 });

    //kv = Johnann::john(11); //equals , { 0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6 });

    return 0;
}