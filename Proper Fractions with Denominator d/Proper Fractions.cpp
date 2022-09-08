//#include <functional>
//#include <iostream>
//using namespace std;
//#define deb(a, x) std::cout << a << " " << x << std::endl;
//long properFractions(long n)
//{
//    if (n == 1) return 0;
//    if (n == 2) return 1;
//    int count = 1; //n==1
//
//    function<long(long, long)> gcd = [&gcd](long a, long b) {return (a == 0) ? b : gcd(b % a, a); };
//    function<long(long, long)> lcm = [&gcd](long a, long b) {return (a * b) / gcd(a, b); };
//    
//    function<void(long, long)> reduce = [&](long a, long b) {a /= gcd(a, b); b /= gcd(a, b); };
//
//    function<bool(long)> isOddPrime = [=](long a) {
//        for (int i = 3; i * i <= a; i += 2) { if (a % i == 0) return false; } return true; };
//
//    switch (n % 2) {
//    case(0):
//        count++; //n==n-1;
//        for (long i = 3; i < n-1 ; i += 2) {
//            long div = gcd(i, n);
//            if (div == 1) count++;
//        }
//
//        break;
//    case(1):
//
//        if (isOddPrime(n)) return (n - 1);
//        
//        
//        count+=2; //n==2 && n==n-1
//        for (long i = 3; i < n-1; i++) {
//            if (gcd(i, n) == 1) count++;
//        }
//        break;
//    }
//    return count;
//
//}
//
///*int main() {
//    long ans;
//
//        for (long a = 1; a <= 200; a++) {
//            ans = properFractions(a);
//            deb(a, ans);
//        }
//        
//    ans    = properFractions(1); // Equals(0));
//    ans = properFractions(2); // Equals(1));
//    ans = properFractions(5); // Equals(4));
//    ans = properFractions(31); // Equals(30));
//    ans = properFractions(15); // Equals(8));
//    ans = properFractions(16); // Equals(8));
//    ans = properFractions(25); // Equals(20));
//
//    return 0;
//}
//*/