#include <bits/stdc++.h>

using namespace std;

int parent[1005], size[1005];

int n;

void make_set(){
	for (int i = 1;i<=n;++i){
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int v){
	if(v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void union(int a, int b){
	a = find(a);
	b = find(b);
	if(a!= b) {
		if(size[a] < size[b]) swap(a, b);
		parent[b] = a;
		size[a] += size[b];
	}
	
}
