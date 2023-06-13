#include <bits/stdc++.h>

using namespace std;

const int maxn = 1001;
#define ll long long
#define pb push_back


// //Cach 1: Khong su dung hang doi

// int n,m; //n: dinh, m: canh
// vector<pair<int,int>> adj[maxn];
// bool used[maxn]; // used = true : I thuoc tap V(mst) , used = false : I thuoc v

// struct canh
// {
// 	int x, y , w;

// 	//x : dinh 1
// 	//y : dinh 2
// 	//w : trong so giua 2 dinh
// };

// void inp() {
// 	cin >> n >> m;
// 	for (int i = 0; i < m; ++i){
// 		int x, y, w; cin >> x >> y >> w;
// 		adj[x].push_back({y,w});
// 		adj[y].push_back({x,w});
// 	}
// 	memset(used, false, sizeof(used));
// }

// void prim (int u){

// 	//B1 : Khoi Tao 

// 	vector<canh> MST; //cay khung
// 	int d = 0; //chieu dai cay khung
// 	used[u] = true; //dua dinh u vao MST

// 	//B2 : Lap
// 	while( MST.size() < n-1 ){
// 		//e = (x,y) 
// 		int X, Y; //Luu 2 dinh canh e
// 		for (int i = 1; i <= n; ++i){
// 			//neu dinh i thuoc MST
// 			if(used[i]) {
// 				//duyet danh sach ke
// 				for (pair<int,int> it : adj[i]){
// 					int j = it.first , trongso = it.second;
// 					if(!used[j] && trongso < min_w){
// 						min_w = trongso;
// 						X = j ; Y = i;
// 					}
// 				}
// 			}
// 		}
// 		MST.push_back({X,Y,min_w});
// 		d+= min_w;
// 		used[X] = true; //Cho dinh X vao MST, loai x khoi V
// 	}
// 	cout << d << endl;
// 	for (canh e : MST) {
// 		cout << e.x << " " << e.y << " " << e.w << endl;
// 	}

// } 

// int main (){

// 	//Prim algorithm

// 	inp();
// 	prim(1);

// }

// // Input

// 6 9
// 1 2 9
// 1 3 4
// 2 3 1
// 2 4 6
// 3 5 2
// 4 5 3
// 4 6 10
// 5 6 8

//Output
// 18
// 3 1 4
// 2 3 1
// 5 3 2
// 4 5 3
// 6 5 8

/////////////////////////////////

// //Cach 2 : su dung hang doi (recommend cach nay!!!)

int n,m; //n: dinh, m: canh
vector<pair<int,int>> adj[maxn];
bool used[maxn]; // used = true : I thuoc tap V(mst) , used = false : I thuoc v
int parent[maxn], d[maxn];

struct canh
{
	int x, y, w;

	//x : dinh 1
	//y : dinh 2
	//w : trong so giua 2 dinh
};

void inp() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i){
		int x, y, w; cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	memset(used, false, sizeof(used));
	for(int i = 1; i <= n ;++i) d[i] = INT_MAX;
}


void prim (int u){

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
	vector<canh> MST;
	int res = 0;
	Q.push({0, u});

	while (!Q.empty()) {
		pair<int,int> top = Q.top(); Q.pop();
		int dinh = top.second, trongso = top.first;

		if(used[dinh]) continue;
		res += trongso;
		used[dinh] = true;

		//in cac dinh canh do thi
		if(u != dinh){
			MST.push_back({dinh, parent[dinh], trongso});
		}

		//duyet tat ca dinh ke
		for (auto it : adj[dinh]){
			int y = it.first, w = it.second;
			if(!used[y] and w < d[y]) {
				Q.push({w,y});
				d[y] = w;
				parent[y] = dinh;
			} 
		}
	}

	cout << res << endl;
	for (auto it : MST) {
		cout << it.x << " " << it.y << " " << it.w << endl;
	}
}

int main (){

	//Prim algorithm

	inp();
	prim(1);

}

//Input

// 6 8
// 1 2 9
// 1 3 4
// 2 3 1
// 2 4 6
// 3 5 2
// 4 5 3
// 4 6 10
// 5 6 8

// OUTPUT

// 18
// 3 1 4
// 2 3 1
// 5 3 2
// 4 5 3
// 6 5 8
