#include <string>
#include <functional>
using namespace std;
class RGBToHex
{
public:
    static string rgb(int r, int g, int b);
};
string RGBToHex::rgb(int r, int g, int b)
{
    function<string(int)> convertHex = [=](int x) {
        return(x <= 9 ? to_string(x) : (x == 10) ? "A" : (x == 11) ? "B" : (x == 12) ? "C" : (x == 13) ? "D" : (x == 14) ? "E" : "F");
    };
    function<string(int)> getHex = [&](int x) {
        int hex1(x / 16), hex2(x % 16);
        return convertHex(hex1)+convertHex(hex2);
    };
    string answer;
    (r <= 0) ? answer.append("00") : (r >= 255) ? answer.append("FF") : answer.append(getHex(r));
    (g <= 0) ? answer.append("00") : (g >= 255) ? answer.append("FF") : answer.append(getHex(g));
    (b <= 0) ? answer.append("00") : (b >= 255) ? answer.append("FF") : answer.append(getHex(b));

    return answer;
}

int main() {
    string result;
            result = RGBToHex::rgb(0, 0, 0); //Equals("000000"));
            result = RGBToHex::rgb(1, 2, 3); //Equals("010203"));
            result = RGBToHex::rgb(255, 255, 255); //Equals("FFFFFF"));
            result = RGBToHex::rgb(254, 253, 252); //Equals("FEFDFC"));
            result = RGBToHex::rgb(-20, 275, 125); //Equals("00FF7D"));
      
    return 0;
}