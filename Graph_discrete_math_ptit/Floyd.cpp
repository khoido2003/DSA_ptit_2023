#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz size()
#define pb push_back

int F[1005][1005];
int n, m, x, y, z;

int main (){

	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			F[i][j] = 1e9;
		}
		F[i][i] = 0;
	}

	while (m--){
		cin >> x >> y >> z;
		F[x][y] = F[y][x] = z;
	}

	// Floyd

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			for (int t = 1; t <= n; ++t){
				F[j][t] = min(F[j][t], F[i][j] + F[i][t]);
			}
		}
	}

	int t; cin >> t;
	while (t--){
		int i, j; cin >> i >> j;
		cout << F[i][j] << endl;
	}

}