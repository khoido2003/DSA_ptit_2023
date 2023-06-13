#include<bits/stdc++.h>

using namespace std;

//DFS : Depth First Search
//Input: 9 9
//1 2
//1 3
//1 5
//2 4
//3 6
//3 7
//3 9
//5 8
//8 9

int n, m;
vector < int > adj[1001];
bool visited[1001];
int a[1001][1001];

void inp1() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  memset(visited, false, sizeof(visited));
}

void inp2() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i][j]) {
        adj[i].push_back(j);
      }
    }
  }
  memset(visited, false, sizeof(visited));
}

void dfs(int u) {
  cout << u << " ";
  visited[u] = true;
  for (int v: adj[u]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
}

int main() {
  inp1();
  dfs(1);
}