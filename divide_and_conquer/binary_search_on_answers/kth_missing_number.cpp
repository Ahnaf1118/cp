#include <bits/stdc++.h>
using namespace std;

int missingK(vector < int > vec, int n, int k) {
    int lo=0, hi=n-1;
    while(lo<=hi) {
        int md = (lo+hi)>>1;
        if ((vec[md]-md)<=k) lo=md+1;
        else hi=md-1;
    }
    return lo+k;
}
