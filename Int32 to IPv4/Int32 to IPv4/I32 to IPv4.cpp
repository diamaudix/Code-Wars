#include <string>
#include <math.h>

std::string uint32_to_ip(uint32_t ip){
    std::string bin, answer;
    for (int i = 31; i >= 0; i--) {
        bin.append(std::to_string(ip / (uint32_t)pow(2, i)));
        ip %= (uint32_t)pow(2,i);
    }
    for (int i = 0; i < 4; i++) {
        int octet(0);
        for (int j = 0; j < 8; j++) if (bin[8*i+j]-48) octet += pow(2, 7 - j);
        answer.append(std::to_string(octet) + ".");
    }
    return answer;
}


int main() {

    std::string result;
    result = uint32_to_ip(2154959208);// , Equals("128.114.17.104"));
           result = uint32_to_ip(0);// , Equals("0.0.0.0"));
           result = uint32_to_ip(2149583361);// , Equals("128.32.10.1"));
 
	return 0;
}