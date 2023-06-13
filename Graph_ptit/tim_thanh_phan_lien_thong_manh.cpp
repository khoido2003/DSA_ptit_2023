#include <bits/stdc++.h>

using namespace std;

//Thuat toan kosaraju tim thanh phan lien thong manh

// b1: goi thuat toan va luu thu tu duyet vao stack
// b2 : xay dung do thi lat nguoc
// b3: pop cac dinh trong stack o buoc 1 va goi dfs liet ke cac thanh phan

const int maxn = 1001;
int n,m;
vector<int> adj[maxn], radj[maxn];
bool used[maxn];
stack<int> st;

void inp(){
	cin >> n >> m;
	for (int i = 0;i<m;++i){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		radj[y].push_back(x);
	}
}

void dfs(int u){
	used[u] = true;
	for (int v : adj[u]){
		if(!used[v]){
			dfs(v);
		}
	}
	st.push(u);
}

void dfs2(int u){
	used[u] = true;
	cout << u << " ";
	for (int v : radj[u]){
		if(!used[v]) dfs2(v);
	}
}

void scc (){
	memset(used, false, sizeof(used));
	for (int i = 1;i <= n; ++i){
		if(!used[i]){
			dfs(i);
		}
	}
	cout << endl;
	memset(used, false, sizeof(used));
	while(!st.empty()){
		int u = st.top(); st.pop();
		if(!used[u]) {
			dfs2(u);
			cout << endl;
		}
	}
}

int main (){
	inp();
	scc();
}

//INPUT

// 8 9
// 1 2
// 2 3
// 3 4
// 4 1
// 3 5
// 5 6
// 6 7
// 7 8
// 8 6

//OUTPUT
// 1 4 3 2
// 5
// 6 8 7