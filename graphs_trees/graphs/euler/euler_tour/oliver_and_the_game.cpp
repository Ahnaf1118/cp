#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

void dfs(int v, int p, int &time, vector<int> &in_time, vector<int> &out_time, vector<int> adj[]) {
	in_time[v] = time++;
	for (int ch: adj[v]) {
		if (ch == p) continue;
		dfs(ch, v, time, in_time, out_time, adj);
	}
	out_time[v] = time++;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> in_time(n+1, 0), out_time(n+1, 0), adj[n+1];
	for (int i=0; i<n-1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int time = 1;
	dfs(1, 1, time, in_time, out_time, adj);
	int q; cin >> q;
	for (int i=0; i<q; i++) {
		int d, u, v;
		cin >> d >> u >> v;
		if (not d) {
			if (in_time[v]>in_time[u] and out_time[v]<out_time[u]) {cout << "YES" << endl;}
			else {cout << "NO" << endl;}
		}
		else {
			if (in_time[u]>in_time[v] and out_time[u]<out_time[v]) {cout << "YES" << endl;}
			else {cout << "NO" << endl;}
		}
	}
}