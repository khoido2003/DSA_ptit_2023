#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz size()
#define pb push_back
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);


//DSA08012 - TÌM SỐ K THỎA MÃN ĐIỀU KIỆN

bool isValid(int num) {
    vector<bool> seen(10, false);
    while (num > 0) {
        int digit = num % 10;
        if (digit > 5 or seen[digit]) {
            return false;
        }
        seen[digit] = true;
        num /= 10;
    }
    return true;
}

int countNumbers(int L, int R) {
    int count = 0;
    for (int num = L; num <= R; num++) {
        if (isValid(num)) {
            count++;
        }
    }
    return count;
}

int main() {
    faster();
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int L, R;
        cin >> L >> R;

        int result = countNumbers(L, R);
        cout << result << endl;
    }

    return 0;
}




////////////////////////////////////////////////////////

//DSA08010  BIẾN ĐỔI SỐ TỰ NHIÊN

int transformTo1(int N) {

    unordered_map<int, int> dist;
    if (N == 1) return 0;
   queue<int> q;
   
    q.push(N);
    dist[N] = 0;

    while (!q.empty()) {

        int current = q.front();
        q.pop();
        int sqrtN = sqrt(current);

        for (int i = 2; i <= sqrtN; i++) {
            if (current % i == 0 and dist[current / i] == 0) {
                
                if(current / i == 1) return dist[current] + 1;
                dist[current / i] = dist[current] + 1;
                q.push(current / i);
            }
        }

        if(current - 1 == 1) return dist[current] + 1;
        if (dist[current - 1] == 0 and current - 1 > 1){

            dist[current - 1] = dist[current] + 1;
            q.push(current - 1);
        }
       
    }

    return -1; 
}

int main() {

    faster();
    int T;
    cin >> T;

    while (T--){
        int N;
        cin >> N;

        int result = transformTo1(N);
        cout << result << endl;
    }

    return 0;
}


////////////////////////////////////////////////////////////

//  DSA08025    QUÂN MÃ

const int MAXN = 8;
int T, sx, sy, ex, ey;
int dist[MAXN][MAXN];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool check (int x, int y){
    if(x >= 0 and x < MAXN and y >= 0 and y < MAXN) return true;
    return false;
}

int bfs(int sx, int sy, int ex, int ey){
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof(dist));
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == ex and y == ey) return dist[x][y];
        for (int i = 0; i < 8; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(check(nx, ny) and dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main (){
    int t; cin >> t;
    while (t--){
        string s1, s2;
        cin >> s1 >> s2;

        sx = s1[0] - 'a';
        sy = s1[1] - '1';
        ex = s2[0] - 'a';
        ey = s2[1] - '1';

        int result = bfs(sx, sy, ex, ey);
        cout << result << endl;
    }
    return 0;
}



/////////////////////////////////////////////////////////

//DSA08009 - BIẾN ĐỔI S – T

const int MAXN = 10000;

int T, S, Targ;
int dist[MAXN+1];

void bfs(int start) {
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == Targ) break;
        if (u - 1 >= 1 && dist[u-1] == -1) {
            dist[u-1] = dist[u] + 1;
            q.push(u-1);
        }
        if (u * 2 <= MAXN && dist[u*2] == -1) {
            dist[u*2] = dist[u] + 1;
            q.push(u*2);
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> S >> Targ;
        bfs(S);
        cout << dist[Targ] << endl;
    }
    return 0;
}

////////////////////////////////

//DSA08004  GIÁ TRỊ NHỎ NHẤT CỦA XÂU

int main (){
    int t; cin >> t;
    while (t--){
        int k; cin >> k;
        string s;
        cin >> s;
        map <char, int> mp;
        priority_queue<int> Q;

        for (int i = 0; i < s.sz; ++i){
            mp[s[i]]++;
        } 
        for (auto it : mp){
            Q.push(it.second);
        }
        while (k--){
            int top1 = Q.top();
            if(top1 == 0) break;
            Q.pop();
            --top1;
            Q.push(top1);
        }
        ll sum = 0;
        while (!Q.empty()){
            sum += 1ll * Q.top() * Q.top();
            Q.pop();
        }
        cout << sum << endl;
        }
     return 0;

}

/////////////////////////////////////////////////////

//DSA08021 - DI CHUYỂN TRONG MA TRẬN


const int MAXN = 1005;
int A[MAXN][MAXN];
int dist[MAXN][MAXN];


int bfs(int M, int N){
    queue<pair<int, int>> q;
    memset(dist, -1, sizeof(dist));
    dist[1][1] = 0;
    q.push({1, 1});

    while (!q.empty()){
        int x = q.front().first; 
        int y= q.front().second; 
        q.pop();

        if(x == M and y == N) return dist[x][y];
        int dx = A[x][y], dy = A[x][y];

        if(x + dx <= M and dist[x + dx][y] == -1){
            dist[x + dx][y] = dist[x][y] + 1;
            q.push({x + dx, y});
        }

        if(y + dy <= N and dist[x][y + dy] == -1){
            dist[x][y + dy] = dist[x][y] + 1;
            q.push({x, y + dy});
        }
    }
    return -1;
}

int main (){
    int t; cin >> t;
    while (t--){
        int m, n; cin >> m >> n;

        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                cin >> A[i][j];
            }
        }

        int res = bfs(m, n);
        cout << res << endl;
    }
    return 0;
}



/////////////////////////////////////////////////////

//DSA08019 - SỐ LỘC PHÁT 3

vector<ll> v;

void generateNumber(int n){
	queue<string> q;
	q.push("6");
	q.push("8");

	while (!q.empty()){
		string s = q.front(); q.pop();
		if(s.sz <= n) {
			ll num = stoll(s);
			v.pb(num);
		}
		else return;

		q.push(s + "6");
		q.push(s + "8");
	}
}

int main (){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		v.clear();

		generateNumber(n);
		sort(v.begin(), v.end(), greater<ll>());

		cout << v.sz << endl;
		for (ll it : v) cout << it << " ";
		cout << endl;
	}
	return 0;
}



////////////////////////////////////////////////////

//DSA08018 - SỐ LỘC PHÁT 2

vector<ll> v;

void generateNumber(int n){
	queue<string> q;
	q.push("6");
	q.push("8");

	while (!q.empty()){
		string s = q.front(); q.pop();
		if(s.sz <= n) {
			ll num = stoll(s);
			v.pb(num);
		}
		else return;

		q.push(s + "6");
		q.push(s + "8");
	}
}

int main (){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		v.clear();

		generateNumber(n);
		sort(v.begin(), v.end());

		cout << v.sz << endl;
		for (ll it : v) cout << it << " ";
		cout << endl;
	}
	return 0;
}


////////////////////////////////////////////////

//DSA08017	SỐ LỘC PHÁT 1

vector<ll> v;

void generateNumber(int n){
	queue<string> q;
	q.push("6");
	q.push("8");

	while (!q.empty()){
		string s = q.front(); q.pop();
		if(s.sz <= n) {
			ll num = stoll(s);
			v.pb(num);
		}
		else return;

		q.push(s + "6");
		q.push(s + "8");
	}
}

int main (){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		v.clear();

		generateNumber(n);
		sort(v.begin(), v.end(), greater<ll>());

		for (ll it : v) cout << it << " ";
		cout << endl;
	}
	return 0;
}


/////////////////////////////////////////////

//DSA08008 - SỐ BDN 2

ll findNumber (int n){
	queue<string> q;
	q.push("1");
	ll num;

	while (!q.empty()){
		string s = q.front(); q.pop();
		num = stoll(s);

		if(num % n == 0) return num;
		q.push(s + "0");
		q.push(s + "1");
	}
	return num;
}

int main (){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		ll result = findNumber(n);
		cout << result << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////

//	DSA08007	SỐ BDN 1

int countNumber (ll n){
	queue<string> q;
	q.push("1");
	int cnt = 0;

	while (!q.empty()){

		string s = q.front(); q.pop();
		ll num = stoll(s);
		if(num <= n) ++cnt;
		else return cnt;

		q.push(s + "0");
		q.push(s + "1");
	}
	return cnt;
}

int main (){
	int t; cin >> t; 
	while (t--){
		ll n; cin >> n;
		int result = countNumber(n);
		cout << result << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////

//	DSA08006	SỐ 0 VÀ SỐ 9

int findNumber(int n){

	queue<string> q;
	q.push("9");
	while (!q.empty()){

		string s = q.front(); q.pop();
		int num = stoi(s);
		if(num % n == 0) return num;

		q.push(s + "0");
		q.push(s + "9");
	}
	return -1;

}

int main (){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int result = findNumber(n);
		cout << result << endl;
	}
	return 0;
}

///////////////////////////////////////////

//DSA08005 - SỐ NHỊ PHÂN TỪ 1 ĐẾN N

void printBinaryNumbers(int n) {
    // Khởi tạo queue
    queue<string> q;

    // Thêm số "1" vào queue
    q.push("1");

    // In ra tất cả các số nhị phân từ 1 đến n
    for (int i = 1; i <= n; i++) {
        // Lấy số đầu tiên trong queue
        string s = q.front();
        q.pop();

        // In số đó
        cout << s << " ";

        // Thêm số "0" và "1" vào queue
        q.push(s + "0");
        q.push(s + "1");
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        printBinaryNumbers(n);

        cout << endl;
    }

    return 0;
}


////////////////////////////////////////////////////////////

//DSA08003 - HÀNG ĐỢI HAI ĐẦU (DEQUEUE)

int main (){
	int t = 1;
    cin >> t;
    deque<int> dq;
    string s;
    while(cin >> s)
    {
        if(s == "PUSHBACK")
        {
            cin >> t;
            dq.push_back(t);
        }
        else if(s == "PUSHFRONT")
        {
            cin >> t;
            dq.push_front(t);
        }
        else if(s == "PRINTFRONT")
        {
            if(dq.empty()) cout << "NONE\n";
            else cout << dq.front() << endl;
        }
        else if(s == "POPFRONT" and dq.sz) dq.pop_front();
        else if(s == "PRINTBACK")
        {
            if(dq.empty()) cout << "NONE\n";
            else cout << dq.back() << endl;
        }
        else if(s == "POPBACK" and dq.sz) dq.pop_back();
    }
    return 0;
}


////////////////////////////////////////////////////

//DSA08002 - CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 2

int main (){
	int t; cin >> t;
	while (t--){
		string s;
		int x;
		queue<int> q;
		while (cin >> s){
			if(s == "PUSH") {
				cin >> x;
				q.push(x);
			}
			if(s == "PRINTFRONT"){
				if(q.empty()) cout << "NONE\n";
				else {
					int v = q.front(); 
					cout << v << endl;
				}
			}
			if(s == "POP") {
				if(!q.empty()) q.pop();
			}
		}
	}
	return 0;
}

/////////////////////////////////////////////////////

//DSA08001 - CẤU TRÚC DỮ LIỆU HÀNG ĐỢI 1


int main (){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		queue<int> q;
		while (n--){
			int x; cin >> x;
			if(x == 1) cout << q.sz << endl;
			else if(x == 2) {
				if(!q.empty()) cout << "NO\n";
				else cout << "YES\n";
			}
			else if(x == 3){
				int m; cin >> m;
				q.push(m);
			}
			else if(x == 4) {
				if(!q.empty()) q.pop();
			}
			else if(x == 5){
				if(q.empty()) cout << -1 << endl;
				else {
					int v = q.front();
					cout << v << endl;
				}
			}
			else if(x == 6){
				if(q.empty()) cout << -1 << endl;
				else {
					int v = q.back();
					cout << v << endl;
				}
			}
			else continue;
		}
	}
	return 0;
}





