#include<bits/stdc++.h>

using namespace std;

int n,m,s,t;
int a[1001][1001];
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void dfs(int u){
	visited[u] = true;
	for (int v : adj[u]){
		if(!visited[v]){
			
			//ghi nhan cha cua v la u
			parent[v] = u;
			dfs(v);
		}
	}
}

void bfs (int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int v = q.front(); q.pop();
		for (int x : adj[v]){
			if(!visited[x]){
				q.push(x);
				visited[x] = true;
				//ghi nhan chu cua x la v
				parent[x] = v;
			}
		}
	}
}

void Path(int s, int t){
	memset(visited,false, sizeof(visited));
	memset(parent,0, sizeof(parent));
	dfs(s);
	//bfs(s);
	if(!visited[t]) {
		cout << "KHong co  duong di";
	}
	else{
		//Truy cap duong di
		vector<int> path;
		//Bat dau tu dinh t
		while (t != s){
			path.push_back(t);
			//Lat nguoc
			
			t = parent[t];
		}
		path.push_back(s);
		reverse(path.begin(), path.end());
		for (int x : path){
			cout << x << " ";
		}
	}
}

//10 8
//1 2
//2 3
//2 4
//3 6
//3 7
//6 7
//5 8
//8 9


int main (){
//	cin >> n >> m ;
//	for (int i =0;i<m;++i){
//		int x, y; cin >> x >> y;
//		adj[x].push_back(y);
//		adj[y].push_back(x);
//	}

	cin >> n ;
	cin >> s>> t;
	for (int i =1;i<=n;++i){
		for (int j = 1;j<= n;++j){
			cin >> a[i][j];
		}
	}
	
	for(int i =1; i<=n;++i){
		for (int j = 1;j<=n;++j){
			if(a[i][j]){
				adj[i].push_back(j);
			}
		}
	}
	
	//cin >> s >> t;
	Path(s,t);
}

//#include <bits/stdc++.h>
//
//using namespace std;
//
//int n,m,s ,t;
//int a[1001][1001];
//vector<int> adj[1001];
//bool visited[1001];
//int parent[1001];
//
//int check = 0;
//
//void dfs(int u){
//    visited[u] = true;
//    for (int v: adj[u]){
//        if(!visited[v]){
//            parent[v] = u;
//            dfs(v);
//        }
//    }
//}
//
//void bfs(int u){
//    queue<int> q;
//    q.push(u);
//    visited[u] = true;
//    while(!q.empty()){
//        int v = q.front(); q.pop();
//        for (int x: adj[v]){
//            if(!visited[x]){
//                q.push(x);
//                visited[x] = true;
//                
//                parent[x] = v;
//            }
//        }
//    }
//}
//
//void Path(int s,int t){
//    memset(visited,false, sizeof(visited));
//    memset(parent,0, sizeof(parent));
//    dfs(s);
//    if(!visited[t]){
//        cout << "no path" << endl;
//        check = 1;
//    }
//    else {
//        vector<int> path;
//        while(t!= s){
//            path.push_back(t);
//            t = parent[t];
//        }
//        path.push_back(s);
//        //reverse(path.begin(),path.end());
//        cout << "DFS path: " ;
//        for (int x : path){
//            cout << x << " ";
//            
//        }
//        cout << endl;
//    }
//}
//
//void Path1(int s,int t){
//    memset(visited,false, sizeof(visited));
//    memset(parent,false, sizeof(parent));
//    bfs(s);
//    if(!visited[t]){
//        cout << "no path" << endl;
//    }
//    else {
//        vector<int> path;
//        while(t!= s){
//            path.push_back(t);
//            t = parent[t];
//        }
//        path.push_back(s);
//        //reverse(path.begin(),path.end());
//        cout << "BFS path: " ;
//        for (int x : path){
//            cout << x << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main (){
//    cin >> n;
//    cin >> s >> t;
//    for (int i = 1;i<=n;++i){
//        for (int j =1;j<=n;++j){
//            cin >> a[i][j];
//        }
//    }
//    for (int i =1;i<=n;++i){
//        for (int j =1;j<=n;++j){
//            if(a[i][j]){
//                adj[i].push_back(j);
//            }
//        }
//    }
//    
//   
//    Path(s,t);
//    if(check == 0) Path1(s,t);
//}




// 10
// 3 9
// 0 1 0 0 1 0 0 1 0 1
// 1 0 1 1 0 1 0 0 0 0
// 0 1 0 0 0 0 0 0 0 0
// 0 1 0 0 0 1 0 1 0 0
// 1 0 0 0 0 1 1 0 1 1
// 0 1 0 1 1 0 1 0 0 1
// 0 0 0 0 1 1 0 1 1 1
// 0 0 0 1 0 0 1 0 1 0
// 0 0 0 0 1 0 1 1 0 1
// 1 1 0 0 1 1 1 0 1 0