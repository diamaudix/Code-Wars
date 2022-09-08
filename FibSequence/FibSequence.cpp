#include <vector>
#include <math.h>
using namespace std;
class Fibkind
{
public:
    static int lengthSupUK(int n, int k);
    static int comp(int n);
};


int Fibkind::lengthSupUK(int n, int k) {

   std::vector<int> fibSequence = { 0,1,1,2,3,3,4,5,5,6,6,6,8,8,8,10,9,10,11,11,12,12,12,12 };

    for (unsigned int i = 24; i <= max(n, k); i++) {

        int a = fibSequence[i - 1];
        int b = fibSequence[i - 2];
        int c = fibSequence[i - a];
        int d = fibSequence[i - b];

        fibSequence.push_back(c + d);

    }

    int length = 0;
    for(unsigned int j=1;j<=n; j++){
    
        if (fibSequence[j] >= k) length++;
    }

    return length;

}

int Fibkind::comp(int n) {

    std::vector<int> fibSequence = { 0,1,1,2,3,3,4,5,5,6,6,6,8,8,8,10,9,10,11,11,12,12,12,12 };

    for (unsigned int i = 24; i <= n; i++) {

        int a = fibSequence[i - 1];
        int b = fibSequence[i - 2];
        int c = fibSequence[i - a];
        int d = fibSequence[i - b];

        fibSequence.push_back(c + d);

    }

    int comp=0;

    for (unsigned int j = 1; j < n; j++) {

        if (fibSequence[j + 1] < fibSequence[j]) comp++;

    }
    return comp;
}

int main() {

    int z = Fibkind::lengthSupUK(50, 25);//, 2);
    int y = Fibkind::lengthSupUK(3332, 973);// 1391);
    int x = Fibkind::lengthSupUK(2941, 862);// 1246);
    int w = Fibkind::lengthSupUK(3177, 573);// 2047);
    int v = Fibkind::lengthSupUK(1745, 645);// 474);

    z=Fibkind::comp(74626);// 37128);
    y=Fibkind::comp(71749);// 35692);
    x=Fibkind::comp(56890);// 28281);
    w=Fibkind::comp(60441);// 30054);
    v=Fibkind::comp(21361);// 10581);

    return 0;

}
