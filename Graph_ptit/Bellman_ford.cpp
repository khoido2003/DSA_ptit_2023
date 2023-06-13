#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz size()
#define pb push_back

struct edge 
{
  int x, y, w;
};

const int INF = (int) 1e9;
int n, m, k;
vector < edge > E;
int d[1005];

void nhap() 
{
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) 
  {
    int x, y, w;
    cin >> x >> y >> w;
    E.push_back((edge){x, y, w});
  }
}

//Adjacency matrix to Adjacency list
void inputMatrix()
{
  cin >> n >> k;
  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      cin >> a[i][j];
    }
  }
  
  for(int i = 1; i<= n; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      if(a[i][j])
      {
        E.push_back((edge){i, j, a[i][j]});
      }
    }
  }
}

void BellmanFord(int s) 
{
  fill(d + 1, d + n + 1, INF);
  d[s] = 0;

  for (int i = 1; i <= n - 1; i++) 
  {
    for (edge e : E) 
    {
      int u = e.x, v = e.y, w = e.w;
      if (d[u] < INF) 
      {
        d[v] = min(d[v], d[u] + w);
      }
    }
  }
  for (int i = 1; i <= n; i++) 
  {
    cout << d[i] << ' ';
  }
  cout << endl;
}

int main ()
{
  nhap();
  BellmanFord(k);
  return 0;
}


//TEST CASE: Câu 5 đề 3 năm 2021-2022 toán rr2

// //INPUT
// 8 14 4
// 1 2 1
// 1 6 3
// 1 7 1
// 2 3 -1
// 3 4 2
// 3 8 1
// 4 5 3
// 5 1 -1
// 5 6 -2
// 6 4 2
// 6 3 1
// 6 2 2
// 7 5 1
// 8 2 1

// //OUTPUT
// 2 3 2 0 3 1 3 3












/////////////////////////////////////////////////

// const int maxn = 100001;
// const int INF = 1e9;
// int n, m, k;
// int a[10001][10001];
// vector<pair<int, int>> adj[maxn];

// void input()
// {
//   cin >> n >> k;
//   for (int i = 1; i <= n; ++i)
//   {
//     for (int j = 1; j <= n; ++j)
//     {
//       cin >> a[i][j];
//       if(a[i][j]) adj[i].pb({j, a[i][j]});
//     }
//   }
// }

// void dijstra(int s)
// {
//   vector<ll> d(n + 1, INF);
//   d[s] = 0;
//   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
//   Q.push({0, s});

//   while (!Q.empty())
//   {
//     pair<int, int> top = Q.top(); Q.pop();
//     int u = top.second, w = top.first;

//     if(w > d[u]) continue;
//     for (auto it : adj[u])
//     {
//       int v = it.first, kc = it.second;
//       if(d[v] > d[u] + kc)
//       {
//         d[v] = d[u] + kc;
//         Q.push({d[v], v});
//       }
//     }
//   }
//   for (int i = 1; i <= n; ++i) cout << d[i] << ' ';
//   cout << endl;
// }

// int main ()
// {
//   input();
//   dijstra(k);
//   return 0;
// }