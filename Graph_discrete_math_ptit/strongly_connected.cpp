#include<bits/stdc++.h>

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

void dfs(int u) {
  visited[u] = true;
  for (int v: adj[u]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
}

int main() {
  inp();
  bool isStronglyConnected = true;
  for (int i = 1; i <= n; ++i) {
    memset(visited, false, sizeof(visited));
    dfs(i);
    for (int j = 1; j <= n; ++j) {
      if (!visited[j]) {
        isStronglyConnected = false;
        break;
      }
    }
    if (!isStronglyConnected) {
      break;
    }
  }
  if (isStronglyConnected) {
    cout << "strongly connected";
  } else {
    cout << "not strongly connected";
  }
  return 0;
}

////////////////////////////////////////////////////////

// Code toán rr 2

#include<bits/stdc++.h>

using namespace std;

int n, m;
vector < int > adj[30];
bool visited[30];
int a[30][30];

void input() {
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
  visited[u] = true;
  for (int v: adj[u]) {
    if (!visited[v]) {
      dfs(v);
    }
  }
}

int main() {
  input();
  bool isStrongly = true;
  for (int i = 1; i <= n; ++i) {
    memset(visited, false, sizeof(visited));
    dfs(i);
    for (int j = 1; j <= n; ++j) {
      if (!visited[j]) {
        isStrongly = false;
        break;
      }
    }
    if (!isStrongly) {
      break;
    }
  }
  if (isStrongly) {
    cout << "strongly connected";
  } else {
    cout << "not strongly connected";
  }
  return 0;
}