#include <bits/stdc++.h> 
using namespace std;

int choose(int n, int r){
	double res = 1;
	for (int i=1; i<=r; i++) {
		res = res*(n-r+i)/i;
	}
	return (int)res;
}
