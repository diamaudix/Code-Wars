using namespace std;
#include <stdio.h>
#include <utility>
#include <iostream>
#include <math.h>
int comparePowers(std::pair<long, long> n1, std::pair<long, long> n2) {

    long n1Base, n2Base;
    long n1Exp, n2Exp;
    long long n1Answer = 1, n2Answer = 1;

    n1Base = n1.first; n2Base = n2.first;
    n1Exp = n1.second; n2Exp = n2.second;

    if (n1Exp * log(n1Base) > n2Exp * log(n2Base))return -1;
    if (n1Exp * log(n1Base) == n2Exp * log(n2Base))return 0;
    return 1;


    // return l == r ? 0 : l < r ? 1 : -1;


/*
    for (unsigned int i = 1; i <= n1Exp; i++) {
        n1Answer *= n1Base;
    }

    for (unsigned int j = 1; j <= n2Exp; j++) {
        n2Answer *= n2Base;
    }

    if (n1Answer > n2Answer) return -1;
    if (n1Answer == n2Answer) return 0;
    return 1;
    */
}

int main() {

    cout<<"2,10 and 2,15 "<< comparePowers({2,10}, {2,15})<<endl;
    cout << "1,10 and 3,10 " << comparePowers({ 1,10 }, { 3,10 }) << endl;
    cout << "2,4 and 4,2 " << comparePowers({ 2,4 }, { 4,2 }) << endl;
    cout << "3,9 and 1,6 " << comparePowers({ 3,9 }, { 1,6 }) << endl;
    cout << "1,10 and 1,15 " << comparePowers({ 1,10 }, { 1,15 }) << endl;

    cout << "2,100 and 2,150 " << comparePowers({ 2,100 }, { 2,150 }) << endl;
    cout << "1,100 and 3,100 " << comparePowers({ 1,100 }, { 3,100 }) << endl;
    cout << "2,100 and 2,100 " << comparePowers({ 2,100 }, { 2,100 }) << endl;
    cout << "34,98 and 51,67 " << comparePowers({ 34,98 }, { 51,67 }) << endl;
    cout << "1024,97 and 1024,81 " << comparePowers({ 1024,97 }, { 1024,81 }) << endl;

    return 0;
}