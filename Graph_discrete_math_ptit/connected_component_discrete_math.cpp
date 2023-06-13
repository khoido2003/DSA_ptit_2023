#include<bits/stdc++.h>

using namespace std;

//10 8
//1 2
//2 3
//2 4
//3 6
//3 7
//6 7
//5 8
//8 9

int n, m;
vector < int > adj[1001];
bool visited[1001];
int a[1001][1001];

void dfs(int u) {
  visited[u] = true;
  //cout << u << " ";
  for (int x: adj[u]) {
    if (!visited[x]) dfs(x);
  }
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

void connectedComponent() {
  int ans = 0;
  memset(visited, false, sizeof(visited));
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      ++ans;
      //cout << "Cac dinh thuoc thanh phan lien thong thu " << ans << " :\n";
      dfs(i);
      //bfs(i);
    }
  }
  //cout << endl;
  cout << ans << endl;
}

int main() {
  //	cin >> n >> m;
  //	for (int i =0;i<m;++i){
  //		int x, y; cin >> x >> y;
  //		adj[x].push_back(y);
  //		adj[y].push_back(x);
  //	}

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

  connectedComponent();
}

//////////////////////////////////////////////

//Duyet dinh tru 

#include <bits/stdc++.h>

using namespace std;
#define pb push_back
int n, m;
vector < int > adj[1001];
bool visited[1001];
int a[1001][1001];

void dfs(int u) {
  visited[u] = true;
  for (int x: adj[u]) {
    if (!visited[x]) dfs(x);
  }
}

void connectedComponent() {
  int ans = 0;
  memset(visited, false, sizeof(visited));
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      ++ans;
      dfs(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    memset(visited, false, sizeof(visited));
    visited[i] = true;
    int cnt = 0;
    for (int j = 1; j <= n; ++j) {
      if (!visited[j]) {
        ++cnt;
        dfs(j);
      }
    }
    if (cnt > ans) cout << i << " ";

  }
  cout << endl;
}

int main() {
  // cin >> n;
  // for (int i =1;i<=n;++i){
  //     for (int j =1;j<=n;++j){
  //         cin >> a[i][j];
  //     }
  // }

  // for (int i =1;i<=n;++i){
  //     for (int j =1;j<=n;++j){
  //         if(a[i][j]){
  //             adj[i].push_back(j);
  //         }
  //     }
  // }

  cin >> n >> m;
  memset(visited, false, sizeof(visited));
  memset(adj, 0, sizeof(adj));
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  connectedComponent();
}

//////////////////////////////

//Duyet canh cau

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector < int > adj[17];
bool visited[17];
int a[17][17];
vector < pair < int, int >> dscanh;
int dem = 0;

void dfs(int u) {
  visited[u] = true;
  for (int x: adj[u]) {
    if (!visited[x]) dfs(x);
  }
}

void dfs2(int u, int s, int t) {
  visited[u] = true;
  for (int v: adj[u]) {
    if ((u == s && v == t) || (u == t && v == s)) continue;
    if (!visited[v]) dfs2(v, s, t);
  }
}

void canh_cau() {
  int ans = 0;
  int connectedComponent = 0;
  memset(visited, false, sizeof(visited));
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      ++connectedComponent;
      dfs(i);
    }
  }
  for (auto it: dscanh) {
    int x = it.first, y = it.second;
    memset(visited, false, sizeof(visited));
    int dem = 0;
    for (int j = 1; j <= n; ++j) {
      if (!visited[j]) {
        ++dem;
        dfs2(j, x, y);
      }
    }
    if (dem > connectedComponent) {
      ++ans;
      cout << x << " " << y << endl;
    }
  }
  //cout << ans << endl;
}

int main() {
  // cin >> n;
  // for (int i =1;i<=n;++i){
  //     for (int j =1;j<=n;++j){
  //         cin >> a[i][j];
  //     }
  // }

  // for (int i =1;i<=n;++i){
  //     for (int j =1;j<=n;++j){
  //         if(a[i][j]){
  //             adj[i].push_back(j);
  //             if (i < j) dscanh.push_back({i,j});
  //         }
  //     }
  // }

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    dscanh.push_back({
      x,
      y
    });
  }

  canh_cau();
}

//10 8
//10 9
//10 8
//10 3
//10 4
//5 3
//10 1
//5 1
//5 4

//output 2