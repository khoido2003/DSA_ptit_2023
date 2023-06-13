#include <bits/stdc++.h>

using namespace std;


int n,m;
set<int> adj[1001];
int degree[1001];

int a[1000][1000];

void nhap(){
	cin >> n>> m;
	for (int i =0;i<m;++i){
		int x,y; cin >> x >> y;
		adj[x].insert(y); 
		adj[y].insert(x); 
		degree[x]++;
		degree[y]++;
	}
}

void euler(int v){
	stack<int> st;
	vector<int> EC;
	st.push(v);
	while(!st.empty()){
		int x = st.top();
		if(adj[x].size() != 0){
			int y = (*adj[x].begin());
			st.push(y);
			//Xoa x,y;
			adj[x].erase(y);
			adj[y].erase(x);
		}
		else {
			st.pop();
			EC.push_back(x);
		}
	}
	reverse(begin(EC), end(EC));
	for (int x : EC) cout << x << ' ';
}


int main (){
	
	//Euler cycle
//	nhap();
	
	cin >> n >> m;
	for (int i =1;i<=n;++i){
		for (int j = 1;j<= n;++j){
			cin >> a[i][j];
		}
	}
	
	for(int i =1; i<=n;++i){
		for (int j = 1;j<=n;++j){
			if(a[i][j]){
				adj[i].insert(j);
			}
		}
	}
	
	euler(1);

//	5 6
//	1 2
//	2 3
//	3 1
//	2 4
//	4 5
//	2 5
	
}
