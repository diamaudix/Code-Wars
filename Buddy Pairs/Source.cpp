using namespace std;
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
/* my attempt namespace Bud
{
    long long sumDivisors(long long x) {

        long long runningSum = 1; //1 is always a divisor
        
        for (long long k = 2; k < ceil(sqrt(x)); k=k+1) {
            if (x % k == 0) { //i is a divisor
                runningSum += k;
                runningSum += x / k;
            }
        }
        return runningSum;
    }

    string buddy(long long start, long long limit)
    {

        long long range = 2 * limit - start;
        vector<pair<long long, long long>> buddyVec(range, std::make_pair(0, 0));

        for (long long m = 0; m < range; m++) {
            pair<long long, long long> pair = { (start + m), sumDivisors(start + m) };
            buddyVec[m] = pair;
        }

        for (long long i = 0; i < limit; i++) {

            for (long long j = i + 1; j < range; j++) {

                //cout << "first: " << (buddyVec[i].second) << " second " << (buddyVec[j].second) <<" i+1: "<< buddyVec[i].first + 1 <<" j+1 "<< buddyVec[j].first + 1 <<endl;

                if ((buddyVec[i].second == buddyVec[j].first + 1) && (buddyVec[j].second == buddyVec[i].first + 1)) {

                    string buddies = std::to_string(buddyVec[i].first) + " " + std::to_string(buddyVec[j].first);
                    cout << buddyVec[i].first << " and " << buddyVec[j].first << " are buddies!" << endl;
                    cout << "returning buddies: " << buddies << endl;

                    return buddies;
                }
            }

        }
        cout << "No buddies found between " << start << " and " << limit << endl;
        return "Nothing"; //no buddies found
    }
}
*/

#include <cmath>
using namespace std;

namespace Bud {
    long long sum_divisors(long long num) {
        long long tmp = 1;
        for (long long i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                if (num / i == i) tmp += i;
                else tmp += (num / i + i);
            }
        }
        return tmp;
    }

    string buddy(long long start, long long limit) {
        for (long long i = start; i <= limit; i++) {
            long long tmp = sum_divisors(i) - 1;
            if (tmp <= i) continue;
            if (sum_divisors(tmp) == i + 1) {
                string res = "";
                res += '(' + to_string(i) + ' ' + to_string(tmp) + ')';
                return res;
            }
        }
        return "Nothing";
    }
}

void testing(long long start, long long limit, string expected)
{
    cout << "Start " << start << " Limit " << limit << endl;
    string actual = Bud::buddy(start, limit);
    cout << "Actual " << actual << endl;
    cout << "Expect " << expected << endl << endl;
   
}

int main(){

        testing(40, 80, "(48 75)");
        testing(2382, 3679, "Nothing");
        testing(8983, 13355, "(9504 20735)");
        testing(1071625, 1103735, "(1081184 1331967)");
       

        return 0;
 
};

