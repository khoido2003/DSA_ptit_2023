#include<bits/stdc++.h>

using namespace std;

//Connected component

int n, m;
char a[1001][1001]; //int a[1001][1001];
bool visited[1001][1001];

int dx[4] = {
  -1,
  0,
  0,
  1
};
int dy[4] = {
  0,
  -1,
  1,
  0
};

void dfs(int i, int j) {
  cout << i << " " << j << endl;
  visited[i][j] = true;
  //duyet cac dinh ke
  for (int k = 0; k < 4; ++k) {
    int i1 = i + dx[k];
    int j1 = j + dy[k];
    if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1]) {
      dfs(i1, j1);
    }
  }
}

void bfs(int i, int j) {
  queue < pair < int, int >> q;
  q.push({
    i,
    j
  });
  a[i][j] = 'o';
  cout << i << " " << j << endl;
  while (!q.empty()) {
    pair < int, int > top = q.front();
    q.pop();
    //duyet cac dinh ke
    for (int k = 0; k < 4; ++k) {
      int i1 = top.first + dx[k];
      int j1 = top.second + dy[k];
      if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1]) {
        cout << i1 << " " << j1 << endl;
        q.push({
          i1,
          j1
        });
        a[i1][j1] = 'o';
      }
    }
  }
}

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  memset(visited, false, sizeof(visited));
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i][j] == 'x' && !visited[i][j]) {
        cout << "Thanh phan lien thong thu " << cnt + 1 << endl;

        //dfs(i,j);

        bfs(i, j);

        ++cnt;
      }
    }
  }
  cout << cnt << endl;
}

//BFS/DFS on grid

//6 6
//xxxooo
//ooxooo
//oxxxxo
//ooooox
//xxoxox
//xoxxox

1

////////////////////////////////////////////////////////////////////////////////////
//Find Path on grid

//6 6
//Aooxoo
//oxoooo
//oxoooo
//ooooxx
//Boooxo
//oooxxx

int n, m, s, t, u, v;
char a[1001][1001]; //int a[1001][1001];
bool visited[1001][1001];
int d[1001][1001];

int dx[4] = {
  -1,
  0,
  0,
  1
};
int dy[4] = {
  0,
  -1,
  1,
  0
};

// Normal Path

bool dfs(int i, int j) {
  cout << i << " " << j << endl;
  if (a[i][j] == 'B') {
    return true;
  }
  a[i][j] = 'x';
  for (int k = 0; k < 4; ++k) {
    int i1 = i + dx[k];
    int j1 = j + dy[k];
    if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'x') {
      if (dfs(i1, j1)) return true;
    }
  }
  return false;
}

bool bfs(int i, int j) {
  queue < pair < int, int >> q;
  q.push({
    i,
    j
  });
  a[i][j] = 'o';
  cout << i << " " << j << endl;
  while (!q.empty()) {
    pair < int, int > top = q.front();
    q.pop();
    //duyet cac dinh ke
    for (int k = 0; k < 4; ++k) {
      int i1 = top.first + dx[k];
      int j1 = top.second + dy[k];
      if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != 'x') {
        cout << i1 << " " << j1 << endl;
        if (a[i1][j1] == 'B') return true;
        q.push({
          i1,
          j1
        });
        a[i1][j1] = 'o';
      }
    }
  }
  return false;
}

void input() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 'A') {
        s = i;
        t = j;
      }
    }
  }
  memset(visited, false, sizeof(visited));
  //	if(dfs(s,t)) cout << "YES\n";
  //	else cout << "NO\n";

  if (bfs(s, t)) cout << "YES\n";
  else cout << "NO\n";

}

///////////////////////////////////////////

////Min Path
//
//void bfs_min(int i, int j){
//	queue<pair<int,int>> q;
//	q.push({i,j});
//	a[i][j] = 'x';
//	d[i][j] = 0;
//	cout << i << " " << j << endl;
//	while(!q.empty()){
//		pair<int,int> top = q.front(); q.pop();
//		//duyet cac dinh ke
//		for (int k =0;k<4;++k){
//			int i1 = top.first + dx[k];
//			int j1 = top.second + dy[k];
//			if(i1>=1 && i1<=n && j1>=1 && j1<=m && a[i1][j1] != 'x'){
//				cout << i1 << " " << j1 << endl;
//				d[i1][j1] = d[top.first][top.second] + 1;
//				if(a[i1][j1] == 'B') return ;
//				q.push({i1,j1});
//				a[i1][j1] = 'x';	
//			}
//		}
//	}
//}
//
//void input_min(){
//	cin >> n >> m;
//	for (int i =1;i<=n;++i){
//		for (int j =1;j<=m;++j){
//			cin >> a[i][j];
//			if(a[i][j] == 'A') {
//				s = i; t =j;
//			}
//			else if(a[i][j] == 'B'){
//				u = i; v = j;
//			}
//		}
//	}
//	memset(visited, false, sizeof(visited));
//	bfs_min(s,t);
//	if(!d[u][v]){
//		cout << "No Path\n";
//	}
//	else cout << d[u][v] << endl;
//}
//
//
//int main (){
//	//input();
//	
//	input_min();
//	
//}