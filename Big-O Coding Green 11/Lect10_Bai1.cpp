#include <iostream>
#include <cmath>
using namespace std;

struct Fraction{
    int nu;
    int de;
};

Fraction sumFraction(Fraction p1, Fraction p2);
void reduceFraction(Fraction &p);
int gcd(int a, int b);

Fraction sumFraction(Fraction p1, Fraction p2){
    Fraction p3;
    p3.nu = p1.nu * p2.de + p1.de * p2.nu;
    p3.de = p1.de * p2.de;
    reduceFraction(p3);
    return p3;
}

void reduceFraction(Fraction &p){
    if(p.nu == 0){
        p.de = 1;
        return;
    }
    int x = gcd(abs(p.nu), abs(p.de));
    p.nu = p.nu / x;
    p.de = p.de / x;
}

int gcd(int a, int b){
    int r = 0;
    while(b!=0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    Fraction p1;
    Fraction p2;
    Fraction p3;
    cin >> p1.nu >> p1.de;
    cin >> p2.nu >> p2.de;

    p3 = sumFraction(p1, p2);
    cout << p3.nu << " " << p3.de;

    return 0;
}