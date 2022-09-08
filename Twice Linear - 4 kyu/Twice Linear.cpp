#include <vector>
#include <set>

class DoubleLinear
{
public:
    static int dblLinear(int n);
};

int DoubleLinear::dblLinear(int n) {

    std::set<int> setOfNumbers;

    setOfNumbers.insert(1);
    int previous = 1;
    int current = *setOfNumbers.rbegin();

    while ((int)setOfNumbers.size() < 2 * n) {

        std::set< int >::iterator it = setOfNumbers.find(previous);
        
        if(*it!=*setOfNumbers.rbegin()) std::advance(it, 1);

        current = *it;

        setOfNumbers.insert(2 * current + 1);
        setOfNumbers.insert(3 * current + 1);
        previous = current;
    }
    
    std::set< int >::iterator it2 = setOfNumbers.begin();

    std::advance(it2, n);
    
    return *it2;
}

int main(){
    int ans = DoubleLinear::dblLinear(10);//22
    
    ans = DoubleLinear::dblLinear(20);//57
    ans = DoubleLinear::dblLinear(30);// 91
    ans = DoubleLinear::dblLinear(50);// 175
    return 0;
}

