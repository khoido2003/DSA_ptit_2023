#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define sz size()

const int maxn = 1001;
int n,m;
vector<int> adj[maxn];
bool visited[maxn];
vector<int> topo;

void inp(){
	cin >> n >> m;
	for (int i = 0;i<m;++i){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}
	memset(visited,false , sizeof(visited));
}

void dfs(int u){
	visited[u] = true;
	for (int x : adj[u]){
		if(!visited[x]) dfs(x);
	}
	topo.push_back((u));
}

int main(){
	//topological sorting
	
	inp();
	for (int i =1;i<=n;++i){
		if(!visited[i]) dfs(i);
	}
	reverse(topo.begin(),topo.end());
	for (int x : topo){
		cout << x << " ";
	}
}


//7 7
//1 2
//2 3
//2 4
//3 5
//4 5
//1 6
//7 6

//OUTPUT
//7 1 6 2 4 3 5













