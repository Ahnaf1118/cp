/*
n participants of the competition were split into m teams in some manner so that each team has at least one participant. After the competition each pair of participants from the same team became friends.
Your task is to write a program that will find the minimum and the maximum number of pairs of friends that could have formed by the end of the competition.
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
#define rep(i, a, b) for (int i=a; i<b; i++)
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
const int INF = 1e9;
const ll LINF = 1e17;
 
int main() {
    ll n, m;
    cin >> n >> m;
    ll t = n-m;
    ll mx = t*(t+1)/2;
    if (m == 1) return cout << mx << ' ' << mx << endl, 0;
    ll op1 = n/m;
    ll op2 = n%m;
    ll mn = (op1*(op1-1)/2)*(m-op2) + ((op1+1)*((op1+1)-1)/2)*op2;
    cout << mn << ' ' << mx << endl;
}