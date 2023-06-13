#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define pb push_back
#define sz size()
 
const int maxn = 100001;
int n, m, s, t;
vector<pair<int, int>> adj[maxn];
int a[1001][1001];


// danh sach canh sang danh sach ke
void nhap(){
	cin >> n >> m >> s;

	//Path
	cin >> t;

	for(int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		//adj[y].push_back({x, w});
	}
}
 

 // Ma tran ke sang danh sach ke
void input(){
	cin >> n >> s ;
	for (int i = 1; i <= n; ++i){
		for (int j = 1;j <= n; ++j){
			cin >> a[i][j];
		}
	}
	
	for(int i = 1; i <= n; ++i){
		for (int j = 1;j <= n; ++j){
			if(a[i][j]){
				adj[i].push_back({j, a[i][j]});
			}
		}
	}	

}

const int INF = 1e9;

// in ra trong so duong di ngan nhat

void dijkstra(int s){
	//Mang luu khoang cach duong di
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
	//{khoang cach, dinh}
	Q.push({0, s});
	while(!Q.empty()){
		//Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if(kc > d[u]) continue;
		//Relaxtion : Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S, cập
		//nhật khoảng cách với các đỉnh kề với u
		for(auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << d[i] << ' ';
	}
}
 
////////////////////

int pre[maxn];

//danh sach canh

// Xay dung duong di ngan nhat

void dijkstra_path(int s, int t){
	//Mang luu khoang cach duong di
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	pre[s] = s;

	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
	//{khoang cach, dinh}
	Q.push({0, s});
	while(!Q.empty()){
		//Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if(kc > d[u]) continue;
		//Relaxtion : Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S, cập
		//nhật khoảng cách với các đỉnh kề với u
		for(auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
				pre[v] = u;
			}
		}
	}
	cout << d[t] << endl;
	vector<int> path;
	while (1){
		path.push_back(t);
		if(t == s) break;
		t = pre[t];
	}
	reverse(path.begin(), path.end());

	for (int x : path ) {
		cout << x << " " ;
	}
	cout << endl;

}

/////////////////////
 
// ma tran ke // toan rr 2

// Xay dung duong di ngan nhat

void dijkstra_path_matrix(int s, int t){
	//Mang luu khoang cach duong di
	vector<ll> d(n + 1, INF);
	d[s] = 0;
	pre[s] = s;

	priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
	//{khoang cach, dinh}
	Q.push({0, s});
	while(!Q.empty()){
		//Chọn ra đỉnh có khoảng cách từ s nhỏ nhất 
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if(kc > d[u]) continue;
		//Relaxtion : Thông qua đỉnh u đã biết khoảng cách ngắn nhất tính từ S, cập
		//nhật khoảng cách với các đỉnh kề với u
		for(auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
				pre[v] = u;
			}
		}
	}
	cout << "K/c " << s << " -> " << t << " = " ;
	cout << d[t] << "       ";
	vector<int> path;
	if(d[t] == 0) cout << s << " <- " << s << endl;
	else while (1){
		path.push_back(t);
		if(t == s) break;
		t = pre[t];
	}
	//reverse(path.begin(), path.end());

	for (int i = 0; i < path.sz; ++i) {
		if(i != path.sz - 1) cout << path[i] << " <- " ;
		else cout << path[i] << endl;
	}
	

} 

 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Danh sach canh // Test 1

	// nhap();
	//dijkstra(s);
	//dijkstra_path(s, t);



	//Ma tran trong so // Test 2
	input();
	for (int i = 1; i <= n; ++i){
		dijkstra_path_matrix(s, i);
	}
}


////////////////////////////////////////

// // // Test case dijkstra_path cho danh sach canh

// 6 8 1 5
// 1 2 7
// 1 3 12
// 2 3 2
// 2 4 9
// 3 5 10
// 4 6 1
// 5 4 4
// 5 6 5

// // // Output
// // // 19
// // // 1 2 3 5


//////////////////////////////////////////

//Test case cho ma tran trong so

// case=1

// input=

// 13

// 1

// 0   2   8   0   0   0   0   0   0   0   0   0   0

// 0   0   2   0   0   0   9   0   0   0   0   0   0

// 0   0   0   6   0   8   1   0   0   0   0   0   0

// 7   0   0   0   0   0   0   0   0   0   0   0   0

// 0   0   1   7   0   0   0   0   0   0   0   0   0

// 0   0   0   0   1   0   0   9   8   0   0   0   0

// 0   0   0   0   0   2   0   2   0   0   0   0   0

// 0   0   0   0   0   0   0   0   9   0   0   2   0

// 0   0   0   0   0   0   0   0   0   6   0   9   8

// 0   0   0   0   7   6   0   0   0   0   0   0   0

// 0   0   0   0   0   0   0   0   6   7   0   0   0

// 0   0   0   0   0   0   0   0   0   0   0   0   2

// 0   0   0   0   0   0   0   0   0   0   7   0   0

// output=

// K/c 1 -> 1 = 0;        1 <- 1

// K/c 1 -> 2 = 2;        2 <- 1

// K/c 1 -> 3 = 4;        3 <- 2 <- 1

// K/c 1 -> 4 = 10;       4 <- 3 <- 2 <- 1

// K/c 1 -> 5 = 8;        5 <- 6 <- 7 <- 3 <- 2 <- 1

// K/c 1 -> 6 = 7;        6 <- 7 <- 3 <- 2 <- 1

// K/c 1 -> 7 = 5;        7 <- 3 <- 2 <- 1

// K/c 1 -> 8 = 7;        8 <- 7 <- 3 <- 2 <- 1

// K/c 1 -> 9 = 15;       9 <- 6 <- 7 <- 3 <- 2 <- 1

// K/c 1 -> 10 = 21;      10 <- 9 <- 6 <- 7 <- 3 <- 2 <- 1

// K/c 1 -> 11 = 18;      11 <- 13 <- 12 <- 8 <- 7 <- 3 <- 2 <- 1

// K/c 1 -> 12 = 9;       12 <- 8 <- 7 <- 3 <- 2 <- 1

// K/c 1 -> 13 = 11;      13 <- 12 <- 8 <- 7 <- 3 <- 2 <- 1