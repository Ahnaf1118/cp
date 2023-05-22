// hackerearth city and campers
#include <iostream>
#include <set>
using namespace std;
const int N = 1e5 + 10;
int par[N];
int s[N];
multiset<int> sizes;

void make(int v)
{
    par[v] = v;
    s[v] = 1;
    sizes.insert(1);
}

int find(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

void merge(int p1, int p2)
{
    sizes.erase(sizes.find(s[p1]));
    sizes.erase(sizes.find(s[p2]));
    sizes.insert(s[p1] + s[p2]);
}

void Union(int v1, int v2)
{
    int p1 = find(v1);
    int p2 = find(v2);
    if (p1 == p2)
        return;
    if (s[p1] < s[p2])
        swap(p1, p2);
    par[p2] = p1;
    merge(p1, p2);
    s[p1] += s[p2];
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 1; i <= v; i++)
    {
        make(i);
    }
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        Union(x, y);
        if (sizes.size() > 1)
        {
            int mn = *(sizes.begin());
            int mx = *(--sizes.end());
            cout << mx - mn << endl;
        }
        else
            cout << 0 << endl;
    }
}