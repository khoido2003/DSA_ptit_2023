#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define sz size()




/////////////////////////////////////////////////////////////////

//DSA09029 - ĐƯỜNG ĐI HAMILTON

int n, m;
vector<int> adj[100001];
bool visited[100001];
int ok;

void dfs(int u, int cnt = 1)
{
	if(cnt == n) 
	{
		ok = 1;
		return;
	}
	if(ok) return;

	for (int x : adj[u])
	{
		if(!visited[x])
		{
			visited[x] = true;
			dfs(x, cnt + 1);
			visited[x] = false;
		}
	}
}

bool check()
{
	for (int i = 1; i <= n; ++i)
	{
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		dfs(i);
		if(ok) return true;
	}
	return false;
}

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(adj, 0, sizeof(adj));

		for (int i = 0; i < m; ++i)
		{
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		memset(visited, 0, sizeof(visited));
		ok = 0;

		cout << check() << endl;
	}
	return 0;
}


/////////////////////////////////////////////////////////////////////////

//DSA10011 - DI CHUYỂN TRÊN BẢNG SỐ

const int MAX = 505;
const int INF = INT_MAX;
int A[MAX][MAX];
int dist[MAX][MAX];

void dijkstra(int n, int m) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({A[0][0], {0, 0}});
    dist[0][0] = A[0][0];

    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (cost > dist[x][y]) {
            continue;
        }

        // Check adjacent cells
        if (x > 0 && dist[x - 1][y] > dist[x][y] + A[x - 1][y]) {
            dist[x - 1][y] = dist[x][y] + A[x - 1][y];
            pq.push({dist[x - 1][y], {x - 1, y}});
        }
        if (x < n - 1 && dist[x + 1][y] > dist[x][y] + A[x + 1][y]) {
            dist[x + 1][y] = dist[x][y] + A[x + 1][y];
            pq.push({dist[x + 1][y], {x + 1, y}});
        }
        if (y > 0 && dist[x][y - 1] > dist[x][y] + A[x][y - 1]) {
            dist[x][y - 1] = dist[x][y] + A[x][y - 1];
            pq.push({dist[x][y - 1], {x, y - 1}});
        }
        if (y < m - 1 && dist[x][y + 1] > dist[x][y] + A[x][y + 1]) {
            dist[x][y + 1] = dist[x][y] + A[x][y + 1];
            pq.push({dist[x][y + 1], {x, y + 1}});
        }
    }

    cout << dist[n - 1][m - 1] << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> A[i][j];
                dist[i][j] = INF;
            }
        }

        dijkstra(n, m);
    }

    return 0;
}


////////////////////////////////////////////////////////////////////

//DSA10015 - KRUSKAL

const int maxn = 1001;

struct edge
{
	int u, v;
	int w;
};

int n, m;
int parent[maxn], sz[maxn];
vector<edge> canh;

void make_set(){
	for (int i = 1; i <= n; ++i){
		parent[i] = i;
		sz[i] = 1;
	}
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	if(sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
	sz[a] += sz[b];
	return true;
}

void input(){
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int x, y, w; cin >> x >> y >> w;
		edge e = edge{x, y, w};
		canh.push_back(e);
	}
}

bool cmp(edge a, edge b){
	return a.w < b.w;
}

void kruskal(){
	vector<edge> mst;
	int d = 0;

	sort(canh.begin(), canh.end(), cmp);

	for (int i = 0; i < m; ++i){
		if(mst.size() == n - 1) break;
		edge e = canh[i];
		if(Union(e.u, e.v)){
			mst.pb(e);
			d += e.w;
		}
	}
	cout << d << endl;
}

int main (){
	int t; cin >> t;
	while (t--){
		memset(parent, 0, sizeof(parent));
		canh.clear();
		memset(sz, 0, sizeof(sz));
		input();
		make_set();
		kruskal();
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////

//DSA10009 - FLOYD

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
	return 0;
}

////////////////////////////////////////////////////////////////

//DSA10008 - DIJKSTRA

const int maxn = 100001;
int n, m, s;
vector<pair<int, int>> adj[maxn];

void input(){
	cin >> n >> m >> s;
	for (int i = 0; i < m; ++i){
		int x, y, w; cin >> x >> y >> w;
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
} 

const int INF = 1e9;

void dijstra(int s){

	vector<ll> d(n + 1, INF);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push({0, s});
	while (!Q.empty()) {

		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;

		if(kc > d[u]) continue;
		for (auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	for (int i = 1; i <= n; ++i) cout << d[i] << " ";
}

int main (){
	int t; cin >> t;
	while (t--){
		memset(adj, 0, sizeof(adj));
		input();
		dijstra(s);
		cout << endl;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////

//	DSA09034	ĐẾM SỐ AO

int n,m;
char a[1001][1001]; //int a[1001][1001];
bool visited[1001][1001];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j){
	visited[i][j] = true;
	//duyet cac dinh ke
	for (int k = 0; k < 8; ++k){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 and i1 <= n and j1 >= 1 and j1 <= m and a[i1][j1] == 'W' and !visited[i1][j1]){
			dfs(i1, j1);	
		}
	}
}

void input(){
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			cin >> a[i][j];
		}
	}
	memset(visited,false, sizeof(visited));
	int cnt = 0;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			if(a[i][j] == 'W' && !visited[i][j]){
				
				dfs(i,j);
				++cnt;
			}
		}
	}
	cout << cnt << endl;
}

int main (){
	input();
	return 0;
}


///////////////////////////////////////////////////////////

//33	DSA09033	MẠNG XÃ HỘI

int n, m;
vector<int> adj[1000005];


int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		memset(adj, 0, sizeof(adj));

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		int flag = 0;

		for (int i = 1; i <= n; ++i){
			for(int j : adj[i]){
				if(adj[j].sz != adj[i].sz) {
					cout << "NO" << endl;
					flag = 1;
					break;
				}
			}
			if(flag == 1) break;
		}
		if(flag == 0) cout << "YES" << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////

//	DSA09032	KẾT BẠN

int n, m;
int parent[1000005], Rank[1000005];

void makeSet(){
	for (int i = 1; i <= n; ++i){
		parent[i] = i;
		Rank[i] = 1;
	}
}

int Find(int v){
	if(v == parent[v]) return v;
	return parent[v] = Find(parent[v]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a == b) return;
	if(Rank[a] < Rank[b]) swap(a, b);
	parent[b] = a;
	Rank[a] += Rank[b];
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		int Max = -1e9;
		makeSet();
		for (int i = 0; i < m; ++i) {
			int x, y; cin >> x >> y;
			Union(x, y);
		}
		for (int i = 1; i <= n; ++i){
			Max = max(Max, Rank[i]);
		}	
		cout << Max << endl;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////

// //DSA10007 - CÂY KHUNG CỦA ĐỒ THỊ THEO THUẬT TOÁN BFS

const int MAXN = 1e3 + 5;
const int MAXM = 1e5 + 5;

int T, N, M, u;
vector<int> adj[MAXN];
vector<pair<int, int>> tree;
bool visited[MAXN];

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
    	int v = q.front(); q.pop();
    	for (int x : adj[v]){
    		if(!visited[x]){
    			q.push(x);
    			tree.pb({v, x});
    			visited[x] = true;
    		}
    	}
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M >> u;

        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        tree.clear();

        for (int i = 1; i <= M; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        bfs(u);

        if (tree.sz != N-1) {
            cout << "-1\n";
        } else {
            for (auto edge : tree) {
                cout << edge.first << " " << edge.second << "\n";
            }
        }
    }
    return 0;
}


//////////////////////////////////////////////////////

//DSA10006 - CÂY KHUNG CỦA ĐỒ THỊ THEO THUẬT TOÁN DFS

const int MAXN = 1e3 + 5;
const int MAXM = 1e5 + 5;

int T, N, M, u;
vector<int> adj[MAXN];
vector<pair<int, int>> tree;
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            tree.pb({u, v});
            dfs(v);
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M >> u;

        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        tree.clear();

        for (int i = 1; i <= M; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        dfs(u);

        if (tree.sz != N-1) {
            cout << "-1\n";
        } else {
            for (auto edge : tree) {
                cout << edge.first << " " << edge.second << "\n";
            }
        }
    }
    return 0;
}


////////////////////////////////////////////////////////

//DSA10003 - KIỂM TRA CHU TRÌNH SỬ DỤNG DISJOIN SET

int n, m;
int parent[1001], Rank[1001];

void makeSet(){
	for (int i = 1; i <= n; ++i){
		parent[i] = i;
		Rank[i] = 1;
	}
}

int Find(int v){
	if(v == parent[v]) return v;
	return parent[v] = Find(parent[v]);
}


void Union(int a, int b, bool &hasCycle){
	a = Find(a);
	b = Find(b);
	if(a == b) {
		hasCycle = true;
		return;
	}
	if(Rank[a] < Rank[b]) swap(a, b);
	parent[b] = a;
	Rank[a] += Rank[b];
}

int main (){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;

		makeSet();
		bool hasCycle = false;

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			Union(x, y, hasCycle);
		}
		if(hasCycle == true) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

////////////////////////////////////////////////////////////

//	DSA09016	KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ CÓ HƯỚNG VỚI DFS
int n, m; 
vector<int> adj[1001];
bool visited[1001];
int color[1001];


bool dfs(int u){
	color[u] = 1;
	for (int x : adj[u]){
		if(color[x] == 0){
			if(dfs(x)) return true;
		}
		else if(color[x] == 1) return true;
	}
	color[u] = 2;
	return false;
}

int main (){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));
		memset(color, 0, sizeof(color));

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
		}

		int flag = 0;
		for (int i = 1; i <= n; ++i){
			if(!visited[i]) {
				if(dfs(i)) {
					cout << "YES" << endl;
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0) cout << "NO" << endl;
		
	}
	return 0;
}



///////////////////////////////////////////////

//DSA09014 - KIỂM TRA CHU TRÌNH TRÊN ĐỒ THỊ VÔ HƯỚNG

int n, m; 
vector<int> adj[1001];
bool visited[1001];

bool dfs(int u, int parent){
	visited[u] = true;
	for (int x : adj[u]){
		if(!visited[x]){
			if(dfs(x, u)) return true;
		}
		else if(x != parent) return true;
	}
	return false;
}

int main (){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		int flag = 0;
		for (int i = 1; i <= n; ++i){
			if(!visited[i]) {
				if(dfs(i, -1)) {
					cout << "YES" << endl;
					flag = 1;
					break;
				}
			}
		}
		if(flag == 0) cout << "NO" << endl;
		
	}
	return 0;
}


/////////////////////////////////////////////////////////

//	DSA09012	LIỆT KÊ ĐỈNH TRỤ

int n, m; 
vector<int> adj[1001];
bool visited[1001];

void dfs(int u){
	visited[u] = true;
	for (int v : adj[u]){
		if(!visited[v]) dfs(v);
	}
}

void dinhTru(){

	int ans = 0;
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= n; ++i){
		if(!visited[i]) {
			++ans;
			dfs(i);
		}
	}

	for (int i = 1; i <= n; ++i){
		memset(visited, 0, sizeof(visited));
		visited[i] = true;
		int cnt = 0;
		for (int j = 1; j <= n; ++j){
			if(!visited[j]) {
				++cnt;
				dfs(j);
			}
		}
		if(cnt > ans) cout << i << " ";
	}
	cout << endl;
}

int main (){
	int t;
	cin >> t;
	while (t--){
		cin >> n >> m;
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		dinhTru();
	}
	return 0;
}



///////////////////////////////////////////////////////////

//	DSA09011	SỐ LƯỢNG HÒN ĐẢO

int n, m;
bool visited[1001][1001];
int a[1001][1001];

//int dx[4] = {-1,0,0,1};
//int dy[4] = {0,-1,1,0};
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j){
	visited[i][j] = true;
	for (int k = 0; k < 8; ++k){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1 >= 1 and j1 >= 1 and i1 <= n and j1 <= m and !visited[i1][j1] and a[i1][j1] == 1) {
			dfs(i1, j1);
		}
	}
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;

		memset(visited, false, sizeof(visited));
		int cnt = 0;

		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j) {
				cin >> a[i][j];
			}
		}

		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j) {
				if(a[i][j] == 1 and !visited[i][j]) {
					dfs(i, j);
					++cnt;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}



////////////////////////////////////////////////////

//DSA09010 - KIỂM TRA TÍNH LIÊN THÔNG MẠNH

// Su dung thuat toan kosaraju de check

int n, m;
vector<int> adj[1001], radj[1001];
bool visited[1001];
stack<int> st;

void dfs(int u){
	visited[u] = true;
	for (int v : adj[u]){
		if(!visited[v]) dfs(v);
	}
	st.push(u);
}

void dfs2(int u){
	visited[u] = true;
	for (int v : radj[u]){
		if(!visited[v]) dfs2(v);
	}
}

void scc(){
	int dem = 0;
	for(int i = 1; i <= n; ++i){
		if(!visited[i]){
			dfs(i);
		}
	}
	memset(visited, 0, sizeof(visited));
	while (!st.empty()){
		int u = st.top(); st.pop();
		if(!visited[u])  {
			++dem;
			dfs2(u);
		}
	}

	if(dem == 1) cout << "YES" << endl;
	else cout << "NO" << endl;

}

int main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		stack<int> st2;

		//Reset 
		st.swap(st2);
		memset(adj, 0, sizeof(adj));
		memset(radj, 0, sizeof(radj));
		memset(visited, 0, sizeof(visited));


		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			radj[y].pb(x);
		}

		scc();
	} 	
}



////////////////////////////////////////////////////////

//	DSA09009	TÌM SỐ THÀNH PHẦN LIÊN THÔNG VỚI BFS

int n, m, k, h;
vector<int> adj[1001];
bool visited[1001];


void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (int x : adj[v]){
			if(!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

void connectedComponents (){
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		if(!visited[i]){
			++ans;
			bfs(i);
		}
	}
	cout << ans << endl;
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		memset(visited, 0, sizeof(visited));
		memset(adj, 0, sizeof(adj));

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		connectedComponents();
	}
	return 0;
}

//////////////////////////////////////////////

// DSA09008	ĐẾM SỐ THÀNH PHẦN LIÊN THÔNG

int n, m, k, h;
vector<int> adj[1001];
bool visited[1001];


void dfs(int u){
	visited[u] = true;
	for (int v : adj[u]){
		if(!visited[v]) dfs(v);
	}
}

void connectedComponents (){
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		if(!visited[i]){
			++ans;
			dfs(i);
		}
	}
	cout << ans << endl;
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		memset(visited, 0, sizeof(visited));
		memset(adj, 0, sizeof(adj));

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		connectedComponents();
	}
	return 0;
}

////////////////////////////////////////////////////////////////

	// DSA09006	ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ VÔ HƯỚNG
	// DSA09007	ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ VÔ HƯỚNG

int n, m, k, h;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void dfs(int u){
	visited[u] = true;
	for (int x : adj[u]){
		if(!visited[x]) {
			parent[x] = u;
			dfs(x);
		}
	}
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u]= true;
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
				parent[x] = v;
			}
		}
	}
}

void Path(int e, int f){
	dfs(e);
	//bfs(e);
	if(!visited[f]) cout << -1 << endl;
	else {
		vector<int> path;
		while (f != e){
			path.pb(f);
			f = parent[f];
		}
		path.pb(e);
		reverse(path.begin(), path.end());
		for (int x : path) cout << x << ' ';
		cout << endl;
	}

}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k >> h;

		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		memset(adj, 0, sizeof(adj));

		for (int i = 0; i < m; ++i) {
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		Path(k, h);
	}
	return 0;
}

///////////////////////////////////////////////////////////

//	DSA10005	CHU TRÌNH EULER TRONG ĐỒ THỊ CÓ HƯỚNG

int main (){
	int t; cin >> t;
	while (t--){
		int n, m, u, v;
		cin >> n >> m;

		int degPlus[n + 1] = {};
		int degMinus[n + 1] = {};

		for (int i = 0; i < m; ++i){
			cin >> u >> v;
			degPlus[u]++;
			degMinus[v]++;
		}

		bool EulerCycle = true;
		int cnt = 0;

		for (int i = 1; i <= n; ++i){
			cnt += abs(degPlus[i] - degMinus[i]);
			if(abs(degPlus[i] - degMinus[i]) > 1 or cnt > 2 or degPlus[i] == 0 or degMinus[i] == 0) EulerCycle = false;
		}

		if(EulerCycle == true) cout << 1 << endl;
		else cout << 0 << endl;
	}
 return 0;
}

/////////////////////////////////////////////////////////

//	DSA10004	ĐƯỜNG ĐI VÀ CHU TRÌNH EULER VỚI ĐỒ THỊ VÔ HƯỚNG

int main (){
	int t; cin >> t;
	while (t--){
		int n, m, u, v;
		cin >> n >> m;
		int degree[n + 1] = {};

		for (int i = 0; i < m; ++i){
			cin >> u >> v;
			degree[u]++;
			degree[v]++;
		}

		bool EulerCycle = true;
		int oddCnt = 0;

		for (int i = 1; i <= n; ++i){
			if(degree[i] % 2) ++oddCnt;
			if(degree[i] == 0) EulerCycle = false;
		}

		if(oddCnt == 0 and EulerCycle) cout << "2" << endl;
		else if(oddCnt == 2) cout << "1" << endl;
		else cout << "0" << endl;
	}

	return 0;
}

////////////////////////////////////////////////////////

// DSA09027 - KIỂM TRA ĐƯỜNG ĐI

int n, m, k, u;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];
int tplt[1001];
int cnt = 0;

void dfs(int u){
    tplt[u] = cnt;
    visited[u] = true;
    sort(adj[u].begin(), adj[u].end());
    for (int x : adj[u]){
        if(!visited[x]) {
            parent[x] = u;
            dfs(x);
        }
    }
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;

		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		memset(tplt, 0, sizeof(tplt));
		cnt = 0;

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		for (int i = 1; i <= n; ++i) {
			 if(!visited[i]) {
            	++cnt;
            	dfs(i);
        	}
		}

		int f; cin >> f;
	    while (f--){
	        cin >> k >> u;
	        if(tplt[k] == tplt[u]) cout << "YES" << endl;
	        else cout << "NO" << endl;
	    }

	}
	return 0;
}


/////////////////////////////////////////////////////////////

	// DSA09025	ĐƯỜNG ĐI THEO DFS VỚI ĐỒ THỊ CÓ HƯỚNG
	// DSA09026	ĐƯỜNG ĐI THEO BFS TRÊN ĐỒ THỊ CÓ HƯỚNG

int n, m, k, u;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()){
		int v = q.front(); q.pop();

		for (int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
				parent[x] = v;
			}
		}
	}
}

void dfs(int u){
	visited[u] = true;
	for (int v : adj[u]){
		if(!visited[v]) {
			parent[v] = u;
			dfs(v);
		}
	}
}

void Path(int s, int t){
	dfs(s);
	//bfs(s);

	if(!visited[t]) cout << "-1" << endl;
	else {
		vector<int> path;
		while (t != s){
			path.pb(t);
			t = parent[t];
		}
		path.pb(s);
		reverse(path.begin(), path.end());
		for (int x : path){
			cout << x << " ";
		}
		cout << endl;
	}
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k >> u;
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));
		memset(parent, 0, sizeof(parent));

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
		}

		Path(k, u);

	}
	return 0;
}

////////////////////////////////////////////

//	DSA09024	BFS TRÊN ĐỒ THỊ CÓ HƯỚNG

int n, m, k;
vector<int> adj[1001];
bool visited[1001];

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()){
		int v = q.front(); q.pop();
		cout << v << " ";

		for (int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k;
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
		}
		bfs(k);
		cout << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////

//	DSA09022	DFS TRÊN ĐỒ THỊ CÓ HƯỚNG

int n, m, k;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u){
	cout << u << " ";
	visited[u] = true;
	for (int v : adj[u]){
		if(!visited[v]) dfs(v);
	}
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k;
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
		}
		dfs(k);
		cout << endl;
	}
	return 0;
}


////////////////////////////////////////////////////

//	DSA09021  -	CHUYỂN MA TRẬN KỀ SANG DANH SÁCH KỀ

int n, m, k;
int a[1001][1001];

int main (){
	int t; t = 1;
	while (t--){
		cin >> n;
		cin.ignore();
		for (int i = 1; i <= n; ++i){
			string s, num;
			getline(cin, s);
			stringstream ss(s);
			while (ss >> num){
				a[i][stoi(num)] = 1;
			}		
		}
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}




/////////////////////////////////////////////////////

// DSA09013 - LIỆT KÊ CẠNH CẦU

int n, m, k;
vector<int> adj[1001];
vector<pair<int, int >> dscanh;
bool visited[1001];
int dem = 0;

void dfs(int u){
	visited[u] = true;
	for (int x : adj[u]){
		if(!visited[x]){
			dfs(x);
		}
	}
}

void dfs2(int u, int s, int t){
	visited[u] = true;
	for (int v : adj[u]){
		if((u == s and v == t) or (u == t and v == s)) continue;
		if(!visited[v]) dfs2(v, s, t);
	}
}

void canhCau(){
	int ans = 0;
	int connectedComponent = 0;
	for (int i = 1; i <= n; ++i){
		if(!visited[i]) {
			++connectedComponent;
			dfs(i);
		}
	}

	for (auto it : dscanh){
		int x = it.first, y = it.second;
		memset(visited,false,sizeof(visited));
		dem = 0;
		for (int j = 1; j <= n; ++j){
			if(!visited[j]) {
				++dem;
				dfs2(j, x, y);
			}
		}
		if(dem > connectedComponent) {
			++ans;
			cout << x << " " << y << " ";		
		}
	}
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		memset(adj, 0, sizeof(adj));
 		memset(visited, 0, sizeof(visited));
 		dscanh.clear();

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
			dscanh.pb({x, y});
		}
		 canhCau();
		 cout << endl;
	}
	return 0;
}

////////////////////////////////////////////////

// 	DSA09005	BFS TRÊN ĐỒ THỊ VÔ HƯỚNG

int n, m, k;
vector<int> adj[1001];
bool visited[1001];

void bfs(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()){
		int v = q.front(); q.pop();
		cout << v << ' ';
		for (int x : adj[v]){
			if(!visited[x]) {
				q.push(x);
				visited[x] = true;
			}
		}
	}
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k;
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		bfs(k);
		cout << endl;
	}
	return 0;
}


////////////////////////////////////////////////

	// DSA09004	DFS TRÊN ĐỒ THỊ VÔ HƯỚNG

int n, m, k;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u){
	cout << u << " ";
	visited[u] = true;
	for (int v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k;
		memset(adj, 0, sizeof(adj));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		dfs(k);
		cout << endl;
	}
	return 0;
}


///////////////////////////////////////////////////

	// DSA09003	BIỂU DIỄN ĐỒ THỊ CÓ HƯỚNG.

int n, m;
vector<int> adj[1001];

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		memset(adj, 0, sizeof(adj));
		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
		}

		for (int i = 1; i <= n; ++i){
			cout << i << ": ";
			for (int x : adj[i]) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}


/////////////////////////////////////////////////////////////

//	DSA09002	CHUYỂN TỪ DANH SÁCH KỀ SANG DANH SÁCH CẠNH

int n, m;
vector<pair<int, int>> edge;

int main (){
	int t; t = 1;
	while (t--){
		cin >> n;
		edge.clear();
		cin.ignore();
		for (int i = 1; i <= n; ++i){
			string s, num;
			getline(cin, s);
			stringstream ss(s);
			while (ss >> num){
				if(stoi(num) > i){
					edge.pb({i, stoi(num)});
				}
			}
		}
		for (auto it : edge){
			cout << it.first << " " << it.second << endl;
		}
	}
	return 0;
}


///////////////////////////////////////////////////////////////

//DSA09001 - CHUYỂN DANH SÁCH CẠNH SANG DANH SÁCH KỀ

int n, m;
vector<int> adj[1001];

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		memset(adj, 0, sizeof(adj));
		for (int i = 0; i < m; ++i){
			int x, y; cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		for (int i = 1; i <= n; ++i){
			cout << i << ": ";
			for (int x : adj[i]) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}


/////////////////////////////////////////////////////////////////////

//KRUSKAl - CODE EXAMPLE

const int maxn = 1001;

struct edge{

	int u, v, w;
};

int n, m;
vector<edge> canh;
int parent[maxn], SZ[maxn];

void makeSet()
{
	for (int i = 1; i <= n ; ++i)
	{
		parent[i] = i;
		SZ[i] = 1;
	}
}

int Find(int v)
{
	if(v == parent[v]) return v;
	return parent[v] = Find(parent[v]);
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if(a == b) return false;
	if(SZ[a] < SZ[b]) swap(a, b);
	SZ[a] += SZ[b];
	parent[b] = a;
	return true;
}

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y, w; cin >> x >> y >> w;
		edge e = edge{x, y, w};
		canh.pb(e);
	}
}

bool cmp(edge a, edge b)
{
	return a.w < b.w;
}

void Kruskal()
{
	vector<edge> mst;
	int d = 0;
	sort(canh.begin(), canh.end(), cmp);

	for (int i = 0; i < m; ++i)
	{
		if(mst.sz == n - 1) break;
		edge e = canh[i];
		if(Union(e.u, e.v)) 
		{
			mst.pb(e);
			d += e.w;
		}
	}
	if(mst.sz != n - 1) cout << "NO" << endl;
	else {
		cout << d << endl;
		for (auto it : mst)
		{
			cout << it.u << ' ' << it.v << ' ' << it.w << endl;
		}
	}
}

int main ()
{
	input();
	makeSet();
	Kruskal();
	return 0;
}

//////////////////////////////////////////////////////

// PRIM - CODE EXAMPLE

int n, m; 
vector<pair<int, int>> adj[100001];
int parent[10001], d[10001];
bool used[10001];

struct canh
{
	int x, y, w;
};

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
	memset(used, 0, sizeof(used));
	for (int i = 1; i <= n; ++i) d[i] = INT_MAX;
}

void prim(int u)
{
	vector<canh> mst;
	int res = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push({0, u});

	while (!Q.empty())
	{
		pair<int, int> top = Q.top(); Q.pop();

		int trongso = top.first; int dinh = top.second;

		if(used[dinh]) continue;
		used[dinh] = true;
		res += trongso;

		if(u != dinh) {
			mst.pb({dinh, parent[dinh], trongso});
		}

		for (auto it : adj[dinh])
		{
			int y = it.first, w = it.second;
			if(!used[y] and w < d[y])
			{
				Q.push({w, y});
				d[y] = w;
				parent[y] = dinh;
			}
		}
	}
	cout << res << endl;
	for (auto it : mst)
	{
		cout << it.x << ' ' << it.y << ' ' << it.w << endl; 
	}
}

int main ()
{
	input();
	prim(1);
	return 0;
}

////////////////////////////////////////////////////////////

//DIJTSRA CODE EXAMPLE

const int maxn = 100001;
int n, m, s;
vector<pair<int, int>> adj[maxn];

void input(){
	cin >> n >> m >> s;
	for (int i = 0; i < m; ++i){
		int x, y, w; cin >> x >> y >> w;
		adj[x].pb({y, w});
		//adj[y].pb({x, w});
	}
} 

void inputMatrix()
{
	cin >> n >> s;
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
				adj[i].push_back({j, a[i][j]});
			}
		}
	}
}

const int INF = 1e9;

void dijstra(int s){

	vector<ll> d(n + 1, INF);
	d[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
	Q.push({0, s});
	while (!Q.empty()) {

		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;

		if(kc > d[u]) continue;
		for (auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	}
	for (int i = 1; i <= n; ++i) cout << d[i] << " ";
}

int main (){
	int t; cin >> t;
	while (t--){
		memset(adj, 0, sizeof(adj));
		input();
		dijstra(s);
		cout << endl;
	}
	return 0;
}

//TEST CASE Dijstra code đề 1 toán rr2 năm 2021-2022

//INPUT
// 1
// 8 15 8
// 1 2 9
// 2 4 2
// 2 7 2
// 3 1 2
// 3 8 4
// 4 3 3
// 4 6 4
// 4 7 5
// 5 3 3
// 5 8 1
// 6 5 1
// 7 1 6
// 7 3 3
// 8 4 7
// 8 6 1

//OUTPUT
//7 16 5 7 2 1 12 0


///////////////////////////////////////////////


//Bellman-Ford Code example

struct edge
{
	int x, y, w;
};

vector<edge> E;
int d[1005], a[1005][1005];
int n, m, k;

const int INF = 1e9;

void input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j) 
		{
			cin >> a[i][j];
			if(a[i][j]) E.pb((edge){i, j, a[i][j]});
		}
	}
}


void BellmanFord(int s)
{
	fill(d + 1, d + n + 1, INF);
	d[s] = 0;
	for (int i = 1; i <= n - 1; ++i)
	{
		for (edge e : E)
		{
			int u = e.x, v = e.y, w = e.w;
			if(d[u] < INF)
			{
				d[v] = min(d[v], d[u] + w);
			}
		}
	}
	for (int i = 1; i <= n; ++i) cout << d[i] << ' ';
	cout << endl;
}

int main()
{
	input();
	BellmanFord(k);
	return 0;
}