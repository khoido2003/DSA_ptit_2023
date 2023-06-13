#include<iostream>
#include <stack>
#include <vector>
#include<set>
#include <algorithm>

using namespace std;

int n,m;
set<int> adj[30];
int degree[30];

int a[20][20];

void euler(int v)
{
    stack<int> st;
    vector<int> EC;
    st.push(v);
    while(!st.empty())
    {
        int x = st.top();
        if(adj[x].size() != 0)
        {
            int y = (*adj[x].begin());
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else {
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(begin(EC), end(EC));
    for (int x : EC) cout << x << " ";
    
}

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1;j <= n; ++j){
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if(a[i][j])
            {
                adj[i].insert(j);
            }
        }
    }
    euler(m);
    return 0;
}


//TEST  CASE

// case=1

// input=

// 6

// 1

// 0  0  0  1  1  0  

// 0  0  1  1  1  1  

// 0  1  0  1  1  1  

// 1  1  1  0  1  0  

// 1  1  1  1  0  0  


// 0  1  1  0  0  0  

// output=

// 1  4  2  3  4  5  2  6  3  5  1

// case=2

// input=

// 13

// 5

// 0 1 0 0 0 1 0 0 0 0 0 0 0

// 1 0 1 0 1 1 0 0 0 0 0 0 0

// 0 1 0 1 1 0 0 0 0 0 1 0 0

// 0 0 1 0 0 0 1 1 0 0 1 0 0

// 0 1 1 0 0 1 1 0 0 0 0 0 0

// 1 1 0 0 1 0 1 0 0 0 0 0 0

// 0 0 0 1 1 1 0 1 0 0 0 0 0

// 0 0 0 1 0 0 1 0 1 1 0 0 0

// 0 0 0 0 0 0 0 1 0 1 0 1 1

// 0 0 0 0 0 0 0 1 1 0 1 1 0

// 0 0 1 1 0 0 0 0 0 1 0 1 0

// 0 0 0 0 0 0 0 0 1 1 1 0 1

// 0 0 0 0 0 0 0 0 1 0 0 1 0


// output=

// 5  2  1  6  2  3  4  7  5  3  11  4  8  9  10  11  12  9  13  12  10  8  7  6  5

// case=3

// input=

// 13

// 7

// 0 0 0 1 0 1 0 0 0 0 0 0 0

// 0 0 1 0 0 0 0 1 0 1 1 0 0

// 0 1 0 0 0 0 0 0 1 1 0 0 1

// 1 0 0 0 0 1 0 1 0 0 0 1 0

// 0 0 0 0 0 0 1 0 1 0 0 0 0

// 1 0 0 1 0 0 0 0 0 1 0 1 0

// 0 0 0 0 1 0 0 0 0 0 1 0 1

// 0 1 0 1 0 0 0 0 0 0 1 1 0

// 0 0 1 0 1 0 0 0 0 0 0 0 1

// 0 1 1 0 0 1 0 0 0 0 0 1 0

// 0 1 0 0 0 0 1 1 0 0 0 0 1

// 0 0 0 1 0 1 0 1 0 1 0 0 0

// 0 0 1 0 0 0 1 0 1 0 1 0 0

// output=

// 7  5  9  3  2  8  4  1  6  4  12  6  10  2  11  7  13  3  10  12  8  11  13  9

