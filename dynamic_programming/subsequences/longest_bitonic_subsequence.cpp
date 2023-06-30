#include <bits/stdc++.h> 
using namespace std;

int longestBitonicSequence(vector<int>& arr, int n) {
	vector<int> front(n, 1), rear(n, 1);
	for (int i=0; i<n; i++) {
		for (int j=0; j<i; j++) {
			if (arr[i] > arr[j]) front[i] = max(front[i], 1 + front[j]);
		}
	}
	for (int i=n-1; i>=0; i--) {
		for (int j=n-1; j>i; j--) {
			if (arr[i] > arr[j]) rear[i] = max(rear[i], 1 + rear[j]);
		}
	}
	int mx = 0;
	for (int i=0; i<n; i++) mx = max(mx, front[i]+rear[i]-1);
	return mx;
} 
