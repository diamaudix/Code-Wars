#include <math.h>
#include <functional>
#include <iostream>
class Suite{ public: static double going(int n);};

double Suite::going(int n) {

    double sum = 1;
    double factorial = 1;

    while (n > 1) {
        factorial *= n;
        sum += 1 / factorial;
        n--;
    }

    return floor(sum * 1000000) / 1000000;

}
   
   // long long f = fact(n); double sum=0;
    //for (int i = 0; i <= n-1 ; ++i) sum += (fact(n-i)/f);
    //return (double)(floor((sum) * 1000000.0)) / 1000000.0;

  /*  std::function<double(int, int)> fs = [&fs](int n, int i) { return (i == n - 1) ? 1 : (n - i) * fs(n, i + 1); };

    double test = std::log(fs(n, 0));

    double denom = 0; double answer;

    for (int i = 0; i < n; i++) {
        denom += 1/fs(n, i);
    }
    */ 
    
    /*
    std::function<double(int)> fl = [&fl](int k) { return (k == 1 || k==0) ? 0 : log10(k) + (fl(k - 1));};
    
    double test = fl(n);

    test = log10(6) + log10(5) + log10(4) + log10(3) + log10(2) + log10(1);
    double sum = 1;
    for (int i = 1; i <= n; i++) {

        sum += fl(n)-fl(i);

    }

    double answer = pow(sum - fl(n), 10);
    answer = (double)(floor((sum) * 1000000.0)) / 1000000.0;
    return answer; 
    
}

*/


int main(){


    double ans = Suite::going(200);// , 1.275);
        ans =  Suite::going(175);//, 1.2125);
        ans = Suite::going(7);//, 1.173214);
        ans = Suite::going(8);//, 1.146651);
      //  ans = Suite::going(100);
      
        for (int i = 0; i < 200; i++) {
            std::cout << i<< " : "<< Suite::going(i) << std::endl;
        }
        
        return 0;
}
