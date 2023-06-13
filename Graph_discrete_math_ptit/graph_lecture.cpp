#include<bits/stdc++.h>

using namespace std;

////Chuyen danh sach canh sang ma tran ke

int n, m;
int a[1001][1001];

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    a[x][y] = a[y][x] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
}

///////////////////////////////////////////

////Chuyen danh sach canh sang danh sach ke

int n, m;
int a[1001][1001];

vector < int > adj[1001];

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for (int i = 1; i <= n; ++i) {
    cout << i << ":";
    for (int x: adj[i]) {
      cout << x << " ";
    }
    cout << endl;
  }
}

////////////////////////////////////////////

////Ma tran ke sang danh sach canh
//
int n, m;
int a[1001][1001];

vector < int > adj[1001];
vector < pair < int, int >> edge;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i][j] && i < j) {
        edge.push_back({
          i,
          j
        });
      }
    }
  }
  for (auto it: edge) {
    cout << it.first << " " << it.second << endl;
  }
}

////////////////////////////////////////////////////////

//ma tran ke sang danh sach ke

int n, m;
int a[1001][1001];

vector < int > adj[1001];
vector < pair < int, int >> edge;

int main() {
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
  for (int i = 1; i <= n; ++i) {
    cout << i << ":";
    for (int x: adj[i]) {
      cout << x << " ";
    }
    cout << endl;
  }
}

///////////////////////////////////////////////////

//Danh sach ke sang ma tran ke

int n, m;
int a[1001][1001];

vector < int > adj[1001];
vector < pair < int, int >> edge;

int main() {
  cin >> n;
  cin.ignore();
  for (int i = 1; i <= n; ++i) {
    string s, num;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> num) {
      a[i][stoi(num)] = 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

//////////////////////////////////////////////////////

//Danh sach ke sang danh sach canh

int n, m;
int a[1001][1001];

vector < int > adj[1001];
vector < pair < int, int >> edge;

int main() {
  cin >> n;
  cin.ignore();
  for (int i = 1; i <= n; ++i) {
    string s, num;
    getline(cin, s);
    stringstream ss(s);
    while (ss >> num) {
      if (stoi(num) > i) {
        edge.push_back({
          i,
          stoi(num)
        });
      }
    }
  }
  for (auto it: edge) {
    cout << it.first << " " << it.second << endl;
  }
}