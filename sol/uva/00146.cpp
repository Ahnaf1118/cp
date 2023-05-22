#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    while (cin >> input)
    {
        if (input == "#")
            break;
        int i = input.length() - 2;
        while (i >= 0 && input[i] >= input[i + 1])
            i--;
        if (i < 0)
            cout << "No Successor\n";
        else
        {
            int j = input.length() - 1;
            while (j > i && input[j] <= input[i])
                j--;
            swap(input[i], input[j]);
            if (i+1 < input.length()-1)
                reverse(input.begin() + i, input.end());
            cout << input << '\n';
        }
    }
    return 0;
}