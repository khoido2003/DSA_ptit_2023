#include <bits/stdc++.h>

using namespace std;

const int maxn = 1001;

struct edge{
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
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
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

    //tao cay khung cuc tieu rong
    vector<edge> mst;
    int d = 0;

    //sort theo chieu dai tang dan
    sort(canh.begin(), canh.end(), cmp);

    //Lap
    for (int i = 0; i < m; ++i){
        if (mst.size() == n - 1) break;
        edge e = canh[i]; // chon canh e la canh nho nhat
        if (Union(e.u, e.v)) {
            mst.push_back(e);
            d += e.w;
        }
    }
    //Tra ve ket qua
    if (mst.size() != n - 1) {
        cout << "Do thi khong lien thong" << endl;
    }
    else {
        cout << "MST: " << d << endl;
        for (auto it : mst){
            cout << it.u << " " << it.v << " " << it.w << endl;
        }
    }
}

int main (){
    input();
    make_set();
    kruskal();
    return 0;
}

//Input

// 6 9 
// 1 2 12
// 1 3 4
// 2 3 1
// 2 4 5
// 2 5 3
// 3 5 2
// 4 5 3
// 4 6 10
// 5 6 8

//Output

// MST: 18
// 2 3 1
// 3 5 2
// 4 5 3
// 1 3 4
// 5 6 8



/////////////////////////////////////////////////

//Code toan rr2

// #include <bits/stdc++.h>

// using namespace std;

// const int maxn = 1001;

// struct edge{
//     int u,v;
//     int w;
// };

// int n,m;
// int parent[maxn], sz[maxn];
// vector<edge> canh;

// void make_set(){
//     for (int i = 1; i <=n ;++i){
//         parent[i] = i;
//         sz[i] = 1;
//     }
// }

// int find(int v)
// {
//     if (v == parent[v]) return v;
//     return parent[v] = find(parent[v]);
// }

// bool Union(int a,int b){
//     a = find(a);
//     b = find(b);
//     if (a==b) return false;
//     if(sz[a] < sz[b]) swap(a,b);
//     parent[b] = a;
//     sz[a]+= sz[b];
//     return true;
// }

// void inp(){
//     cin >> n;
//     canh.clear();
//     for (int i = 1; i <= n;++i){
//         for (int j = 1; j <= n;++j){
//             int w;
//             cin >> w;
//             if(w !=0 ){
//                 edge e = edge{i,j,w};
//                 canh.push_back(e);
//             }
//         }
//     }
//     m = canh.size();
// }

// bool cmp(edge a, edge b){
//     if(a.w != b.w) {
//         return a.w < b.w;
//     }
//     if (a.u != b.u) {
//         return a.u < b.u;
//     }
//     return a.v < b.v;
// }

// void kruskal(){
//     vector<edge> mst;
//     int d = 0;
//     sort(canh.begin(), canh.end(), cmp);
//     make_set();
//     for (int i = 0; i < m;++i){
//         if(mst.size()==n-1) break;
//         edge e = canh[i];
        
//         if(Union(e.u, e.v)){
//             mst.push_back(e);
//             d += e.w;
//         }
//     }
//     if(mst.size() != n-1){
//         cout << "Do thi khong lien thong" << endl;
//     }
//     else {
//         cout << "dH = " << d << endl;
//         for (auto it : mst){
//             cout << it.u << " " << it.v << endl;
//         }
//     }
// }

// int main (){
//     inp();
//     kruskal();
//     return 0;
// }

////////////////////////////

// //3.7 toan rr2

// // 10
// // 0 4 1 1 2 9 0 5 4 7
// // 4 0 2 0 9 1 5 0 6 0
// // 1 2 0 7 0 6 6 1 1 9
// // 1 0 7 0 1 7 0 6 0 0
// // 2 9 0 1 0 3 4 3 1 2
// // 9 1 6 7 3 0 3 1 1 5
// // 0 5 6 0 4 3 0 4 5 0
// // 5 0 1 6 3 1 4 0 4 2
// // 4 6 1 0 1 1 5 4 0 4
// // 7 0 9 0 2 5 0 2 4 0

// // dH = 12
// // 1 3
// // 1 4
// // 2 6
// // 3 8
// // 3 9
// // 4 5
// // 6 8
// // 5 10
// // 6 

////////////////////////////

// //3.9 toan rr2

// // 10
// // 0 4 8 8 2 9 0 5 4 7
// // 4 0 2 0 9 7 5 0 6 0
// // 8 2 0 7 0 6 6 9 9 9
// // 8 0 7 0 7 7 0 6 0 0
// // 2 9 0 7 0 3 4 3 1 2
// // 9 7 6 7 3 0 3 1 1 5
// // 0 5 6 0 4 3 0 4 5 0
// // 5 0 9 6 3 1 4 0 4 2
// // 4 6 9 0 1 1 5 4 0 4
// // 7 0 9 0 2 5 0 2 4 0

// // dH = 22
// // 5 9
// // 6 8
// // 6 9
// // 1 5
// // 2 3
// // 5 10
// // 6 7
// // 1 2
// // 4 8