#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    int n;
    cin >> n;
    vi array(n, 0);
    for (int i=0; i<n; i++)
        cin >> array[i];
    vector<vi> subsets;
    int sz = (1 << n) - 1;
    for (int mask = 0; mask <= sz; mask++) {
        vi subset;
        for (int i=0; i<n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(array[i]);
            }
        }
        subsets.push_back(subset);
    }
    for (auto subset: subsets) {
        cout << "[ ";
        for (auto element: subset) {
            if (element == *(--subset.end()))
                cout << element << ' ';
            else
                cout << element << ", ";
        }
        cout << "]\n";
    }
}