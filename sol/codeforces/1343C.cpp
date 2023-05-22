#include <bits/stdc++.h>
using namespace std;

bool sign(int num)
{
    return num > 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        long long int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int mx = arr[i];
            int j = i;
            while (j < n && sign(arr[i]) == sign(arr[j]))
            {
                mx = max(mx, arr[j]);
                j++;
            }
            ans += mx;
            i = j - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}