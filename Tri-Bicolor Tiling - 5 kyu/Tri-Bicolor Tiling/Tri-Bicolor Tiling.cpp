typedef long long LL;
#include <functional>
LL tri_bicolor_tiling(LL n, LL r, LL g, LL b) {
    
    std::function<LL(LL)> factorial = [&factorial](LL n) {
        return(n == 0 || n == 1) ? 1 : n*factorial(n - 1);
    };

    bool redGreen(r + g <= n), redBlue(r + b <= n), greenBlue = g + b <= n;

    LL rg, rb, gb, black;

    if (redGreen) {
        LL rPlace = n - r + 1;
        LL gPlace = n - g + 1;
        LL black = n - r - g;
        rg = factorial(black + 2) / (factorial(black));
    }
    if (redBlue) {
        LL rPlace = n - r + 1;
        LL bPlace = n - b + 1;
        LL black = n - r - b;
        rb = factorial(black + 2) / (factorial(black));
    }
    if (redGreen) {
        LL gPlace = n - g + 1;
        LL bPlace = n - b + 1;
        LL black = n - g - b;
        gb = factorial(black + 2) / (factorial(black));
    }
    return rg+rb+gb;

}

int main() {

    LL result;
            result = tri_bicolor_tiling(10, 2, 3, 4); //quals(248));

            result = tri_bicolor_tiling(5, 2, 3, 4); //quals(2));
            result = tri_bicolor_tiling(6, 2, 3, 4); //quals(8));
            result = tri_bicolor_tiling(5, 2, 2, 2); //quals(18));
            result = tri_bicolor_tiling(6, 2, 2, 2); //quals(54));
  
    return 0;
}