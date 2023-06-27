#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& arr)
{
	int lo=1, hi=arr.size()-2, n=arr.size();
	if (n==1) return arr[0];
	if (arr[0] != arr[1]) return arr[0];
	if (arr[n-1] != arr[n-1]) return arr[n-1];
	while(lo <= hi) {
		int md = (lo+hi)>>1;
		if (arr[md]!=arr[md-1] and arr[md]!=arr[md+1]) return arr[md];
		if ((md+(arr[md]==arr[md-1]))&1) hi = md -1;
		else lo = md + 1;
	}
	return arr[lo];
}