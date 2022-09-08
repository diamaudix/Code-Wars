#include <random>
#include <stdio.h>
#include <iostream>
using namespace std;

struct Encoder {
    static std::string encode(const std::string& p_what) {
        return "";
    }
};

struct Decoder {
    static std::string decode(const std::string& p_what) {
        std::cout << (Encoder::encode("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")) << "\n";
        std::cout << (Encoder::encode("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")) << "\n";
        std::cout << (Encoder::encode("!@#$%^&*()_+-")) << "\n";
        std::string a, b, c;
        for (const auto& w : std::string("abcdefghijklmnopqrstuvwxyz")) {
            a += Encoder::encode(std::string("") + w)[0];
            b += Encoder::encode(std::string("_") + w)[1];
            c += Encoder::encode(std::string("__") + w)[2];
        }
        std::cout << a << "\n";
        std::cout << b << "\n";
        std::cout << c << "\n";
        return p_what;
    }
};

int main() {

    Decoder::decode("Hello World!");// , Equals("Hello World!"));
    Decoder::decode(Encoder::encode("Hello World!"));// , Equals("Hello World!"));

    return 0;
}