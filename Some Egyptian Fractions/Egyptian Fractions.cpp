#include <string>
#include <functional>
#include <math.h>
using namespace std;
class Decomp
{
public:
	static string decompose(const string& nrStr, const string& drStr);
};
string Decomp::decompose(const string& nrStr, const string& drStr) {
	
	long long num = stoll(nrStr); long long den = stoll(drStr); long long integer = 0; long long fraction = 2; string answer;
	if (num == 0)return "[]";

 	function<long long(long long, long long)> gcd = [&gcd](long long a, long long b) {return (a == 0) ? b : gcd(b % a, a); };
	function<long long(long long, long long)> lcm = [&gcd](long long a, long long b) {return (a * b) / gcd(a, b); };
	function<void(long long&, long long&, long long&)> setinteger = [&](long long& n, long long& d, long long& i) {i = n / d; n %= d;  };
	function<void(long long&, long long&, long long)> simp = [&](long long& n, long long& d, long long div) { n /= div; d /= div; };
	
	simp(num, den, gcd(num, den));
	if (num>=den) setinteger(num, den, integer);
	if (integer != 0) answer.append(to_string(integer));
	
	while (num > 0) {
		if ((1 / (double)fraction) <= (double(num) / den)) {
			answer.append(", 1/" + to_string(fraction));
			long long l = lcm(fraction, den);
			num = num * (l / den) - l / fraction;
			den = lcm(den, fraction);
			simp(num, den, gcd(num, den));
		}

		(fraction<10) ? (fraction++) : (fraction = ceil(double(den) / num));


	}
	return((integer != 0) ? ('[' + answer + ']') : ('['+answer.substr(2)+']'));
}

int main(){
	string ans = Decomp::decompose("50", "4187");// , "[1/84, 1/27055, 1/1359351420]");

	ans = Decomp::decompose("66", "100");// , "[1/2, 1/7, 1/59, 1/5163, 1/53307975]");
	ans = Decomp::decompose("21", "23");// , "[1/2, 1/3, 1/13, 1/598, 1/897]");
	ans = Decomp::decompose("3", "4");// , "[1/2, 1/4]");
	ans = Decomp::decompose("12", "4");// , "[3]");
	ans = Decomp::decompose("4", "5");// , "[1/2, 1/4, 1/20]");
	ans = Decomp::decompose("8", "12");// , "[1/2, 1/6]");

	return 0;
}

/*double remainder = double(num) / den;
double fractValue = (double(1)) / fraction;
double toGo = fractValue - remainder;
double growthFactor = toGo/remainder;
long long growthStep = long long(growthFactor)+1;
(num != 1) ? fraction += growthStep : fraction = den;
//(fraction<50)? fraction+= 1 : fraction*=long long(growthStep/2)+1;
//(fraction<100)? fraction++ : fraction += 2*(long long)((1 / ((double)fraction) - (double(num) / den)) / (double(num) / den));
*/