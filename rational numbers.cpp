#include <bits/stdc++.h>
using namespace std;

class RationalNumber {
    int num;
    int den;
    bool negative;
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
public:
    RationalNumber() {
        num = den = 1;
        negative = 0;
    }
    RationalNumber(int a, int b) {
        if ((a < 0) ^ (b < 0))
            negative = 1;
        else
            negative = 0;
        num = abs(a);
        den = abs(b);
        int h = gcd(a, b);
        num /= h;
        den /= h;
    }
    RationalNumber operator+(const RationalNumber &r) {
        RationalNumber added;
        added = RationalNumber(num * r.den + r.num * den, den * r.den);
        return added;
    }
    bool operator<(const RationalNumber &r) const {
        return num * r.den < r.num * den;
    }

    void toString() {
        cout << num << "/" << den << endl;
    }
};
int main(int argc, char **argv) {
    RationalNumber r1(3, 5);
    RationalNumber r2(1, 3);
    RationalNumber r3 = r1 + r2;
    RationalNumber r4(9, 13);
    vector<RationalNumber> v;
    map<RationalNumber, string> S;
    map<RationalNumber, string>::iterator it;
    S[r1] = "1";
    S.insert(S.begin(), pair<RationalNumber, string>(r2, "2"));
    S.insert(S.begin(), pair<RationalNumber, string>(r2, "2"));
    S.insert(S.begin(), pair<RationalNumber, string>(r3, "3"));
    S.insert(S.begin(), pair<RationalNumber, string>(r4, "4"));
    for (it = S.begin(); it != S.end(); ++it) {
        RationalNumber r = it->first;
        r.toString();
        cout << it->second << endl;
    }
    return 0;
}