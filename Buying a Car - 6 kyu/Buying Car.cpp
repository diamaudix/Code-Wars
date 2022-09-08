#include <vector>
#include <math.h>
using namespace std;

class BuyCar
{
public:
    static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth);
};
std::vector<int> BuyCar::nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth) {
    int month = 1;
    int savings = 0;
    double oldPrice = startPriceOld;
    double newPrice = startPriceNew;
    double currentBalance = startPriceOld + savings - startPriceNew;
    if (currentBalance >= 0) return { 0, (int)round(currentBalance) };
    while (currentBalance < 0) {
        if (month % 2 == 0) percentLossByMonth += 0.5;
        oldPrice -= oldPrice*(percentLossByMonth / 100);
        newPrice -= newPrice*(percentLossByMonth / 100);
        savings += savingperMonth;
        currentBalance = oldPrice + savings - newPrice;
        month++;
    }
    return { month-1, (int)round(currentBalance) };
}


int main(){

        vector<int> ans1 = BuyCar::nbMonths(2000, 8000, 1000, 1.5);
        //{ 6, 766 }

        ans1 = BuyCar::nbMonths(12000, 8000, 1000, 1.5);
       //{0,4000}
        return 0;
}
