#include <cmath>
#include <math.h>
#include <iomanip>

class Magnets
{
public:
    static double doubles(int maxk, int maxn);
    static double vkn(int k, int n);
};

double Magnets::vkn(int k, int n) {
    return 1 / (k * pow(n + 1, 2 * k));
}

double Magnets::doubles(int maxk, int maxn) {
    double sum = 0;
    for (int k = 1; k <= maxk; k++) {
        for (int n = 1; n <= maxn; n++){
            sum += vkn(k, n);
        }
    }
    return sum;
}


int main(){

       double x =  Magnets::doubles(1, 10);// , 0.5580321939764581);
       double y = Magnets::doubles(10, 1000);// 0.6921486500921933);
       double z = Magnets::doubles(10, 10000);// 0.6930471674194457);
       double w = Magnets::doubles(20, 10000);// 0.6930471955575918);
        return 0;
}

