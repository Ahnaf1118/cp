#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long bin_exponentiation(long long a, long long b, long long M = 1337) {
        a %= M;
        long long res = 1;
        while(b) {
            if (b&1) {
                res = (res * a) % M;
            }
            a = (a*a) % M;
            b >>= 1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        long long num = 0;
        for (auto v: b) {
            num = (num*10 + v) % 1140;
        }
        return bin_exponentiation(a, num);
    }
};