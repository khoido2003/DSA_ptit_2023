#include <bits/stdc++.h>

using namespace std;

const int maxn = 1001;
int n, m;
vector < int > adj[maxn];
bool visited[maxn];

// Do thi vo huong

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

bool dfs(int u, int parent) {
  visited[u] = true;
  for (int x: adj[u]) {
    if (!visited[x]) {
      if (dfs(x, u)) return true;
    } else if (x != parent) return true;
  }
  return false;
}

int main() {

  inp();

  //	//Neu do thi lien thong
  //	if(dfs(1,0)) cout << "YES";
  //	else cout << "NO";

  //////////////////////////

  // // Neu do thi khong lien thong
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      if (dfs(i, 0)) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}

//Do thi vo huong

// 7 6
// 1 2
// 2 3
// 2 4
// 3 6
// 6 7
// 7 3

//YES

//////////////////////////////////////////////

//Kiem tra chu trinh tren do thi co huowng

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1001;
int n, m;
vector < int > adj[maxn];
bool visited[maxn];
int color[maxn];

void inp() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    //adj[y].push_back(x);
  }
  memset(color, 0, sizeof(color));
}

bool dfs(int u) {
  color[u] = 1;
  for (int v: adj[u]) {
    if (color[v] == 0) {
      if (dfs(v)) return true;
    } else if (color[v] == 1) return true;

  }
  color[u] = 2;
  return false;
}

int main() {

  inp();

  //	//Neu do thi lien thong
  //	if(dfs(1,0)) cout << "YES";
  //	else cout << "NO";

  //////////////////////////

  // // Neu do thi khong lien thong
  for (int i = 1; i <= n; ++i) {
    if (!color[i]) {
      if (dfs(i)) {
        cout << "YES";
        return 0;
      }
    }
  }
  cout << "NO";
}

//Do thi co huong

//7 7
//1 2
//1 5
//2 3
//4 2
//3 6
//6 7
//7 3

//YES