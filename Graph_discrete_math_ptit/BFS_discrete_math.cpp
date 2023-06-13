#include <bits/stdc++.h>

using namespace std;

//BFS 

//10 11 
//1 2
//1 3
//1 5
//1 10
//2 4
//3 6
//3 7
//3 9
//6 7
//5 8 
//8 9

int n, m;
vector < int > adj[1001];
bool visited[1001];

void inp() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  memset(visited, false, sizeof(visited));
}

void bfs(int u) {
  queue < int > q;
  q.push(u);
  visited[u] = true;

  while (!q.empty()) {
    int v = q.front(); //Lay dinh o dau hang doi
    q.pop();
    cout << v << " ";
    for (int x: adj[v]) {
      if (!visited[x]) {
        q.push(x);
        visited[x] = true;
      }
    }
  }
}

int main() {
  inp();
  bfs(1);
}

////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector < int > adj[1001];
bool visited[1001];
int a[1001][1001];

void inp() {
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

void bfs(int u) {
  queue < int > q;
  q.push(u);
  visited[u] = true;

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    cout << v << " ";
    for (int x: adj[v]) {
      if (!visited[x]) {
        q.push(x);
        visited[x] = true;
      }
    }
  }
}

int main() {
  inp();
  bfs(6);
}

////////////////////////