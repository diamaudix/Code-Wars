#include <cinttypes>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
uint64_t descendingOrder(uint64_t a)
{

    uint64_t x = a;
    std::vector<uint64_t> numbers;
    while (x > 0)
    {
        numbers.push_back(x % 10);
        x /= 10;
    }
    sort(numbers.begin(), numbers.end(), std::greater<uint64_t>());


    uint64_t n = 0;
    uint64_t N = numbers.size();
    for (unsigned int i = 0; i < N; i++) {
        n += numbers[i] * powl(10, N - i - 1);
    }
    return n;
}

int main() {



   // descendingOrder(0);// , Equals(0));
   // descendingOrder(1);// , Equals(1));
    descendingOrder(910123323455766660);// (976666554333221100);// , Equals(51));
    descendingOrder(1021);// , Equals(2110));
    descendingOrder(123456789);// , Equals(987654321));

 }
