#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int INF = 1e9 + 10;
int dist[N][N];

void reset()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = 0;
}

void print(int v) {
    for (int i=1; i<=v; i++) {
        for (int j=1; j<=v; j++) {
            if (dist[i][j] == INF)
                cout << 'I' << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

void floyd_warshall(int v) {
    for (int k=1; k<=v; k++) {
        for (int i=1; i<=v; i++) {
            for (int j=1; j<=v; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    int v;
    cin >> v;
    reset();
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++) 
            cin >> dist[i][j];
    vector<int> del(v, 0);
    for (int i=0; i<v; i++)
        cin >> del[i];
    reverse(del.begin(), del.end());
    vector<long long> res(v, 0);
    for (int k=0; k<v; k++) {
        for (int i=1; i<=v; i++) {
            for (int j=1; j<=v; j++) {
                int temp = dist[i][del[k]] + dist[del[k]][j];
                dist[i][j] = min(dist[i][j], temp);
            }
        }
        for(int i=0; i<=k; i++) {
            for (int j=0; j<=k; j++) {
                res[k] += dist[del[i]][del[j]];
            }
        }        
    }
    reverse(res.begin(), res.end());
    for (auto r: res)
        cout << r << ' ';
    cout << endl;
    return 0;
}