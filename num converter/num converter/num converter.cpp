#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int to_sys(int num, int sys) {
    int num2 = 0, res = 0, tm = 1;
    while (num) {
        if (num % sys == 0) {
            tm = 10;
        }
        num2 = num2 * 10 + num % sys;
        num /= sys;
    }
    while (num2) {
        res = res * 10 + num2 % 10;
        num2 /= 10;
    }
    return res;
}

int to_dec(int num, int sys) {
    int num2=0, deg = 0;
    while (num > 0) {
        num2 += (num%10) * pow(sys, deg);
        ++deg;
        num /= 10;
    }
    return num2;
}

void cust() { cout << "\tNUM CONVERTER" << endl; }

int main() {
    setlocale(LC_ALL, "");
    int sys, num, sys2, tmp;
    cust();
    cout << "\tВведите число:\n\t";
    cin >> num;

    cout << "\tЧисло записано в системе счисления (цифрой):\n\t";
    cin >> sys;
    cout << "\tПеревод в систему счисления (цифрой):\n\t";
    cin >> sys2;
    if (sys2 == 10) { cout << "Ваш ответ в десятичной системе счисления:\n\t" << num << ""<< " = " <<to_dec(num, sys);}
    else {
        cout << "\tВаш ответ:\n\t" << num << " = ";
        if (sys == 10) { cout << to_sys(num, sys2); }
        else {
            tmp = to_dec(num, sys);
            cout << to_sys(tmp, sys2);
        }
    }
    return 0;}