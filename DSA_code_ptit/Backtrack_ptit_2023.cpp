#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz size()
#define pb push_back
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

//DSA02028 - CHIA ĐỀU

int n, k;
int a[15], check, res = 0;
vector<int> sum(15);

void Try(int i, int cnt = 0) {
    if (cnt == k) {
       	res += (i == n) ? 1 : 0;
        return;
    }
    for (int j = i + 1; j <= n; ++j) {
        if (sum[j] - sum[i] == check) {
            Try(j, cnt + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) {
            cin >> check;
            sum[i] = sum[i - 1] + check;
        }
        if (sum[n] % k) {
            cout << 0;
            return 0;
        }
        check = sum[n] / k;
        Try(0);
        cout << res;
    }
    return 0;
}


///////////////////////////////////////////////////////////////////////

//DSA02027 - NGƯỜI DU LỊCH

int c[100][100];
int n, x[100];
int visited[100], res = INT_MAX, sum = 0,cmin = INT_MAX, cnt = 0;

void nhap(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if(c[i][j]) cmin = min(cmin, c[i][j]);
        }
    }

    x[1] = 1;
    visited[1] = 1;
}

void Try(int i){
    ++cnt;
    for (int j = 1; j <= n; ++j){
        if(!visited[j]){
            visited[j] = 1;
            x[i] = j;
            sum += c[x[i - 1]][x[i]];
            if(i == n){
                res = min(res, sum + c[x[i]][1]);
            }
            else if(sum + (n - i + 1) * cmin < res){
                Try(i + 1);
            }
            sum -= c[x[i - 1]][x[i]];
            visited[j] = 0;
        }
    }
}

int main (){
    nhap();
    Try(2);
    cout << res << endl;
}


//////////////////////////////////////////////////////////////////

//DSA02011 - MÁY ATM

const int maxn = 1001;

int n, s, k, x[maxn], a[maxn], res = 1e9;


void Try(int i, int start, int sum, int cnt){
    for (int j = start; j < n; ++j){
        sum += a[j];
        cnt++;
        if (sum == k){
            res = min(res, cnt);
            return ;
        } else if ( sum < k){
            Try(i + 1, j + 1, sum, cnt);
        }
        sum -= a[j];
        cnt--;
    }
}


int main (){
    int t; cin >> t;
    while (t--){
        res = 1e9;
        cin >> n >> k;
        for (int i = 0 ; i < n; ++i) cin >> a[i];

        Try(1, 0, 0, 0);

        if (res == 1e9) cout << -1 << endl;
        else cout << res << endl;
    }
    
}



//////////////////////////////////////////////////////////////////////

//DSA02010 - TỔ HỢP SỐ CÓ TỔNG BẰNG X

int n, s, a[100001], x[100001];
ll sum;

string tmp;
vector<string> final;

void Try(int i, int start)
{

	for (int j = start; j < n; ++j)
	{
		x[i] = a[j];
		sum += a[j];


		if(sum == s)
		{
			tmp = "";
			for (int k = 1; k <= i; ++k) tmp += to_string(x[k]) + " ";
			tmp.pop_back();
			tmp = "[" + tmp + "]";
			final.pb(tmp);
		}

		if(sum < s)
		{
			Try(i + 1, j);
		}
		sum -= a[j];
	}
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--)
	{
		cin >> n >> s;
		sum = 0;
		final.clear();

		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n);
		Try(1, 0);
		if(final.sz == 0) cout << -1;
		else for (auto it : final) cout << it;
		cout << endl;
	}
	return 0;
}




//////////////////////////////////////////////////////////////////

// /DSA02009 - CHIA MẢNG

const int maxn = 1001;
int n, k, a[maxn], x[maxn], s = 0, ok;

bool used[maxn];

void Try(int i, int start, int cnt, int sum)
{

    if(cnt == k) 
    {
        ok = 1;
        return;
    }
    if (ok) return;

    for (int j = start; j < n; ++j)
    {
        if(sum + a[j] <= s and !used[j])
        {
            used[j] = true;

            x[i] = a[j];

            if(sum + a[j] == s){
                Try(i + 1, 0, cnt + 1, 0);
            }
            else 
            {
                Try(i + 1, j + 1, cnt, sum + a[j]);
            }

            used[j] = false;
        }
    }
}


int main (){
    int t; cin >> t;
    while (t--)
    {
        cin >> n >> k;
        s = 0;
        ok = 0;
        memset(used, false, sizeof(used));


        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            s += a[i];
        }
        if (s % k == 0)
        {
            s /= k;
            sort(a, a + n);
            Try(0, 0, 0, 0);
            cout << ok << endl; 
        }
        else cout << 0 << endl;
    }
}


////////////////////////////////////////////////////////////////////

//DSAKT012 - ĐỔI TIỀN

const int maxn = 1001;
int n, k, a[maxn], res = 1e9;

void Try(int i, int start, ll sum, int cnt)
{
    for (int j = start; j < n; ++j)
    {
        sum += a[j];
        cnt++;
        if (sum == k)
        {
            res = min(res, cnt);
            return ;
        } 
        else if ( sum < k)
        {
            Try(i + 1, j + 1, sum, cnt);
        }
        sum -= a[j];
        cnt--;
    }
}

int main ()
{
    cin >> n >> k;
    for (int i = 0; i < n ; ++i)
    {
        cin >> a[i];
    }
    Try(0, 0, 0, 0);

    if (res == 1e9) cout << -1 << endl;
    else cout << res << endl;
    return -;
}


//////////////////////////////////////////////////////////////////////

// 	DSA02045	TẬP CON CỦA XÂU KÝ TỰ

int n;
string s, tmp, x[100001];
vector<char> v;
vector<string> final;

void Try(int i, int start)
{
	for (int j = start; j < v.sz; ++j){
		x[i] = s[j];
		tmp += x[i];
		if(i >= 1) final.pb(tmp);
		Try(i + 1, j + 1);
		tmp.pop_back();
	}
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while(t--){
		cin >> n;
		cin >> s;
		v.clear();
		final.clear();
		tmp = "";

		for (int i = 0; i < s.sz; ++i) v.pb(s[i]);

		Try(1, 0);
		for (auto it : final){
			cout << it << ' ';
		}
		cout << endl;
	}
	return 0;
}



///////////////////////////////////////////////////////////////////////////

//DSA02041 - BIẾN ĐỔI VỀ 1

int minStepsToOne(int N) {
    queue<pair<int, int>> q;  // Lưu trạng thái (số, số bước)
    q.push({N, 0});

    while (!q.empty()) {
        int num = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (num == 1) {
            return steps;  // Trả về số bước khi đạt được 1
        }

        // Thực hiện ba thao tác và thêm các trạng thái mới vào hàng đợi
        if (num % 2 == 0) {
            q.push({num / 2, steps + 1});
        }
        if (num % 3 == 0) {
            q.push({num / 3, steps + 1});
        }
        q.push({num - 1, steps + 1});
    }

    return -1;  // Trường hợp không tìm thấy kết quả
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        cout << minStepsToOne(N) << endl;
    }

    return 0;
}




/////////////////////////////////////////////////////////

//	DSA02039	PHÂN TÍCH SỐ 2

int n, x[1001];
int cnt;
bool final = false;
vector<string> v;


void init (){
	cnt = 1;
	x[1] = n;
}

void sinh(){
   int i = cnt;
   while(i >= 1 and x[i] == 1){
       --i;
   }

   if(i == 0){
       final = 1;
   }
   else
   {
       x[i]--;
       int d = cnt - i + 1;
       cnt = i;
       int q = d / x[i], r = d % x[i];

       for(int j = 1; j <= q; j++){
           x[i + j] = x[i];
       }
       cnt += q;
       if(r > 0){
           x[cnt + 1] = r;
           ++cnt; 
       }
   }
}

int main (){
	int t; cin >> t;
	while (t--){
		memset(x,0, sizeof(x));
		final = false;
		cin >> n;
		v.clear();
		init();

		string s = "";

		while (!final) {
			s += "(";

			for (int i = 1; i <= cnt; ++i){
				s += to_string(x[i]);
				if(i < cnt) s += " ";
			}
			s += ")";
			v.pb(s);
			s = "";
			sinh();
		}
		cout << v.sz << endl;
		for (auto it : v) cout << it << " ";
		cout << endl;
	}
	return 0;
}

////////////////////////////////////////////////////////////////

//DSA02038 - DÃY CON CÓ K PHẦN TỬ TĂNG DẦN

const int maxn = 1001;
int n, k, x[maxn], a[maxn];

void inkq(){
    for (int i  = 1; i <= k; ++i){
        cout << a[x[i]] << " ";
    }
    cout << endl;
}

void Try(int i){
    for (int j = x[i - 1] + 1; j <= n - k + i; ++j ){
        x[i] = j;
        if(i == k) inkq();
        else Try(i + 1);
    }
}

int main (){
    int t; cin >> t;
    while (t--){
        memset(x, 0, sizeof(x));
        memset(a, 0, sizeof(a));

        cin >> n >> k;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        x[0] = 0;
        Try(1);
    }
}

//////////////////////////////////////////////////////////////////////

// DSA02037 - DÃY CON CÓ TỔNG NGUYÊN TỐ

int n, a[10001], x[10001], sum = 0;
//int check[1000001] = {};
vector<int> prime;
vector<vector<int>> final;

// void sieve()
// {
// 	for (int i = 2; i <= sqrt(1000000); ++i){
// 		if(!check[i]) {
// 			for (int j = i * i; j <= 1000000; j += i){
// 				check[j] = 1;
// 			}
// 		}
// 	}
// }

bool check(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i){
        if(n % i == 0) return false;
    }
    return true;
}

void Try(int i, int start)
{
	for (int j = start; j < n; ++j){
		x[i] = a[j];
		sum += a[j];

		if(check(sum)) {
			vector<int> tmp(x, x + i + 1);
			final.pb(tmp);
		}

		if(j + 1 < n) Try(i + 1, j + 1);
		sum -= a[j];
	}
}

int main ()
{
	//memset(check, 0, sizeof(check));
	//sieve();
	int t; t = 1;
	cin >> t;
	while (t--){
		cin >> n;
		final.clear();
		memset(a, 0, sizeof(a));
		memset(x, 0, sizeof(x));
		sum = 0;

		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n, greater<int>());
		Try(0, 0);

		sort(final.begin(), final.end());
		for (auto it : final){
			for (auto i : it) cout << i << ' ';
			cout << endl;
		}
	}
	return 0;
}




////////////////////////////////////////////////////////////

//DSA02036 - DÃY CON CÓ TỔNG LẺ

int n, a[100001], x[100001], sum;
vector<vector<int>> final;

void Try(int i, int start)
{
	for (int j = start; j < n; ++j){
		x[i] = a[j];
		sum += a[j];
		if(sum % 2) {
			vector<int> tmp(x, x + i + 1);
			final.pb(tmp);
		}
		if(j + 1 < n) Try(i + 1, j + 1);
		sum -= a[j];
	}
}	

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--) {
		cin >> n;
		final.clear();
        memset(a, 0, sizeof(a));

		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n, greater<int>());

		Try(0, 0);

		sort(final.begin(), final.end());
		for (auto it : final){
			for (auto i : it) cout << i << ' ';
			cout << endl;
		}
	}
	return 0;
}


/////////////////////////////////////////////////////////

//	DSA02035	HOÁN VỊ CÁC CHỮ SỐ

int n, k, res;
vector<string> v;
vector<int> a;

int calc()
{
	int m = INT_MAX, M = INT_MIN, tmp;

	string ss;
	for (string i : v){
		ss = "";
		for (int j : a){
			ss += i[j];
		}
		tmp = stoi(ss);
		m = min(m, tmp);
		M = max(M, tmp);
	}
	return M - m;
}

int main ()
{
	//faster();
	int t; t = 1;
	//cin >> t;
	while (t--){
		cin >> n >> k;
		string s; 
		res = INT_MAX;

		for (int i = 0; i < n; ++i){
			cin >> s;
			v.pb(s);
		}

		for (int i = 0; i < k; ++i) a.pb(i);

		do {
			res = min(res, calc());
		}
		while (next_permutation(a.begin(), a.end()));
		cout << res << endl;
	}
	return 0;
}



//////////////////////////////////////////////////////////////////

// DSA02032 - TỔ HỢP SỐ CÓ TỔNG BẰNG X

int n, k, a[10001], x[10001], sum;
vector<vector<int>> final;

void Try(int i, int start)
{
	for (int j = start; j <= n; ++j){
		x[i] = a[j];
		sum += a[j];

		if(sum == k) {
			vector<int> tmp(x, x + i + 1);
			final.pb(tmp);
		}
		if(sum < k) Try(i + 1, j);
		sum -= a[j];
	}
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--){
		cin >> n >> k;
		final.clear();
		memset(a, 0, sizeof(a));
		memset(x, 0, sizeof(x));
		sum = 0;

		for (int i = 1; i <= n; ++i) cin >> a[i];
		Try(1, 1);
		if(final.sz == 0) cout << -1 << endl;
		else {
			cout << final.sz << " ";
			for (auto it : final){
				cout << "{";
				for (int i = 1; i < it.sz - 1; ++i) cout << it[i] << " ";
				cout << it[it.sz - 1] << "} ";
			}
			cout << endl;
		}
	}
	return 0;
}






////////////////////////////////////////////////////////////////////////////

//	DSA02017	SẮP XẾP QUÂN HẬU 2

int n, a[1001][1001], res = 0, tong = 0;
int x[1001], cot[1001], d1[1001], d2[1001];

void Try(int i)
{
	for (int j = 1; j <= 8; ++j){
		if(cot[j] == 0 and d1[8 - j + i] == 0 and d2[i + j - 1] == 0){
			tong += a[i][j];
			cot[j] = 1;
			d1[8 - j + i] = 1;
			d2[i + j - 1] = 1;

			if(i == 8) res = max(res, tong);
			else Try(i + 1);

			tong -= a[i][j];
			cot[j] = 0;
			d1[8 - j + i] = 0;
			d2[i + j - 1] = 0;
		}
	}
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--){
		res = 0;
		tong = 0;
		memset(cot, 0, sizeof(cot));
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		n = 8;
		for (int i = 1; i <= 8; ++i) {
			for (int j = 1; j <= 8; ++j) cin >> a[i][j];
		}

		Try(1);
		cout << res << endl;

	}
	return 0;
}





//////////////////////////////////////////////////////////////

//DSA02013 - SỐ NGUYÊN TỐ

int n, p, s, P = 200, st;
bool notPrime[205] = {};
vector<int> prime, tmp;
vector<vector<int>> final;


// sàng nguyên tố
void sieve()
{
	int sqr = sqrt(P);
	for (int i = 2; i <= sqr; ++i)
	{
		if(!notPrime[i]) 
		{
			for (int j = i * i; j <= P; j += i)
			{
				notPrime[j] = 1;
			}
		}
	}
	for (int i = 2; i <= P; ++i)
	{
		if(!notPrime[i]) prime.pb(i);
	}
}

void Try(int i, int sum)
{
	if(sum > s) return;
	if(sum == s) 
	{
		if(tmp.sz == n) final.pb(tmp);
		return;
	}
	for (int j = i; j < prime.sz; ++j)
	{
		tmp.pb(prime[j]);
		Try(j + 1, sum + prime[j]);
		tmp.pop_back();
	}
}

int main ()
{
	memset(notPrime, 0, sizeof(notPrime));
	sieve();
	int t; t = 1;
	cin >> t;
	while (t--)
	{
		cin >> n >> p >> s;
		tmp.clear();
		final.clear();

		// tìm vị trí phần tử đầu tiên lớn hơn p là số nguyên tố
		st = upper_bound(prime.begin(), prime.end(), p) - prime.begin();
		Try(st, 0);

		cout << final.sz << endl;
		for (auto it : final){
			for (auto i : it) {
				cout << i << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}


////////////////////////////////////////////////////////////////////


//DSA02007 - ĐỔI CHỖ CÁC CHỮ SỐ

string s;
int k;

void findMax(string &res, int cnt) {
    if (!k)
        return;
    char tmp = s[cnt];
    for (int i = cnt; i < s.length(); i++)
        if (tmp < s[i])
            tmp = s[i];
    if (tmp != s[cnt])
        --k;
    for (int i = s.length() - 1; i >= cnt; i--) {
        if (s[i] == tmp) {
            swap(s[cnt], s[i]);
            if (s.compare(res) > 0)
                res = s;
            findMax(res, cnt + 1);
            swap(s[cnt], s[i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        cin >> k >> s;
        string res = s;
        findMax(res, 0);
        cout << res << endl;
    }
    return 0;
}




/////////////////////////////////////////////////////////////////

// 	DSA02004	DI CHUYỂN TRONG MÊ CUNG 2

const  int maxn = 1001;

int n, k, a[maxn][maxn], check[maxn][maxn];
vector<string> v;
string s;

// Đề bài yêu cầu sắp xếp theo từ điển
// D-L-R-U : Ascending order  (tăng dần)
// U-R-L-D : Descending order (giảm dần)

void Try(int i, int j)
{
    if(i == n && j == n) 
    {
        v.pb(s);
        return ;
    }
    // Going down
    if(a[i + 1][j] == 1 && check[i + 1][j] == 0 && i <= n)
    {
        s += 'D';
        check[i][j] = 1;
        Try(i + 1, j);
        s.pop_back();
        check[i][j] = 0;
    }
    //Going left
    if(a[i][j - 1] == 1 && check[i][j - 1] == 0 && j >= 1)
    {
        s += 'L';
        check[i][j] = 1;
        Try(i, j - 1);
        s.pop_back();
        check[i][j] = 0;
    }

    //Going right
    if(a[i][j + 1] == 1 && check[i][j + 1] == 0 && j <= n)
    {
        s += 'R';
        check[i][j] = 1;
        Try(i, j + 1);
        s.pop_back();
        check[i][j] = 0;
    }

    //Going up
    if(a[i - 1][j] == 1 && check[i - 1][j] == 0 && i >= 1)
    {
        s += 'U';
        check[i][j] = 1;
        Try(i - 1, j);
        s.pop_back();
        check[i][j] = 0;
    }

}

int main ()
{
    int t = 1; 
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(check, 0, sizeof(check));
        v.clear();
        s = "";

        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> a[i][j];
                check[i][j] = 0;
            }
        }

        Try(1, 1);
        if (v.sz == 0) cout << -1 << endl;
        else 
        {
            for (auto it : v) cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}



///////////////////////////////////////////////////////////////////

//DSA05009 - TẬP CON BẰNG NHAU

int n, a[1001], s, x[1001], ok;

void Try(int i, int start, int sum)
{
	if(ok) return;
	for (int j = start; j <= n; ++j)
	{
		x[i] = a[j];
		if(sum + a[j] == s)
		{
			ok = 1; 
			return;
		}
		else if(sum > s) return;
		else Try(i + 1, j + 1, sum + a[j]);
	}
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--){
		cin >> n;
		s = 0;
		ok = 0;

		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			s += a[i];
		}
		if(s % 2 == 0) 
		{
			s /= 2;
			sort(a, a + n + 1);
			Try(1, 1, 0);
			if(ok) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}




//////////////////////////////////////////////////////////////////

// DSA02033 - SỐ XA CÁCH

// DSA02034 - TRÒ CHƠI VỚI CÁC CON SỐ

bool check(vector<int> a)
{
	for (int i = 0; i < a.sz - 1; ++i){
		if(abs(a[i] - a[i + 1]) < 2) return false; 
	}
	return true;
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a;
		for (int i = 1; i <= n; ++i) a.pb(i);

		do{
			if(check(a)) {
				for (auto it : a) cout << it;
				cout << endl;
			}
		}
		while (next_permutation(a.begin(), a.end()));

	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////

// DSA02031 - GHÉP CHỮ CÁI

bool check(char c)
{
	return c == 'A' or c == 'E';
}


bool checkMiddle(string s)
{
	for (int i = 0; i < s.sz; ++i){
		if(check(s[i]) and (i == 0 or i == s.sz - 1)) continue;
		if(check(s[i]) and !check(s[i - 1]) and !check(s[i + 1])) return false;
	}
	return true;
}

int main()
{
	int t; t = 1;
	//cin >> t;
	while (t--){

		string s = "ABC";
		char c; cin >> c;
		for (char i = 'D'; i <= c; ++i) s += i;

		do{
			if(checkMiddle(s)) cout << s << endl;

		}
		while (next_permutation(s.begin(), s.end()));

	}
	return 0;
}


/////////////////////////////////////////////////////////////

//DSA02030 - LIỆT KÊ XÂU KÝ TỰ

int n;
char c;

void Try(int i, string s = "", char k = 'A')
{
	if(i == n)
	{
		cout << s << endl;
		return;
	}
	for (char j = k; j <= c; ++j) Try(i + 1, s + j, j);
}

int main ()
{
	faster();
	int t; t = 1;
	while (t--)
	{
		cin >> c >> n;
		Try(0);
	}
	return 0;
}


/////////////////////////////////////////////////////////////////


//	DSA02029	THÁP HÀ NỘI

void move(int n, char A, char B, char C){
	if(n == 1){
		cout << A << " -> " << C << endl; 
		return;
	} 
	move(n - 1, A, C, B);
	cout << A << " -> " << C << endl;
	move(n - 1, B, A, C);

}

int main() {
    int n;
    cin >> n;
    move(n, 'A', 'B', 'C');
    return 0;
}

/////////////////////////////////////////////////////////////////

//	DSA02024	DÃY CON TĂNG DẦN

int n, a[1001], x[1001];
vector<string> v;

void display(int i)
{
	string tmp;
	for (int j = 1; j <= i; ++j)
	{
		tmp += to_string(x[j]) + " ";
	}
	v.pb(tmp);
}

void Try(int i, int start)
{
	for (int j = start; j <= n; ++j)
	{
		if(a[j] > x[i - 1])
		{
			x[i] = a[j];

			if(i >= 2) display(i);
			Try(i + 1, j + 1);
		}
	}
}

int main ()
{
	int t; t = 1;
	//cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];

		Try(1, 1);
		sort(v.begin(), v.end());
		for (auto it : v) cout << it << endl;
	}
	return 0;
}





///////////////////////////////////////////////////////////////////////

//	DSA02023	ĐẶT TÊN

int n, k, x[1001];
vector<string> v;

void display()
{
	for (int i = 1; i <= k; ++i)
	{
		cout << v[x[i] - 1] << ' ';
	}
	cout << endl;
}

void Try(int i)
{
	for (int j = x[i - 1] + 1; j <= v.sz - k + i; ++j)
	{
		x[i] = j;
		if(i == k) display();
		else Try(i + 1);
	}
}

int main ()
{
	int t; t = 1;
	//cin >> t;
	while (t--){
		cin >> n >> k;
		set<string> se;
		v.clear();
		memset(x, 0, sizeof(x));


		for (int i = 0; i < n; ++i) 
		{
			string x; cin >> x;
			se.insert(x);
		}

		for (auto it : se) v.pb(it);
		x[0] = 0;
		Try(1);
	}
	return 0;
}



//////////////////////////////////////////////////////////////////////////////

//DSA02022 - NGÀY ĐẶC BIỆT

string s = "2000";
vector<string> year, day;
char a[2] = {'0', '2'};

void Try(int i){
	for (int j = 0; j < 2; ++j){
		s[i] = a[j];
		if(i == 3) year.pb(s);
		else Try(i + 1);
	}
}

int main ()
{
	int t; t = 1;
	//cin >> t;
	while (t--){
		day.pb("02");
		day.pb("20");
		day.pb("22");
		Try(1);

		for (auto d : day){
			for (auto y : year){
				cout << d << "/02/" << y << endl;
			}
		}
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////

//DSA02016 - SẮP XẾP QUÂN HẬU 1

int n, x[100001], cot[100001], d1[100001], d2[100001]; 
int cnt;

void Try(int i){
	for (int j = 1; j <= n; ++j){
		if(cot[j] == 0 and d1[i - j + n] == 0 and d2[i + j - 1] == 0){
			x[i] = j;
			cot[j] = d1[i - j + n] = d2[i + j - 1] = 1;
			if (i == n) ++cnt;
			else Try(i + 1);
			cot[j] = d1[i - j + n] = d2[i + j - 1] = 0;
 		}
	}
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--){
		cin >> n;
		memset(cot, 0, sizeof(cot));
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		memset(x, 0, sizeof(x));
		cnt = 0;

		Try(1);
		cout << cnt << endl;
	}
	return 0;
}



////////////////////////////////////////////////////////////////////////

//	DSA02012	DI CHUYỂN TRONG MA TRẬN


int m, n, cnt, a[1001][1001];

void Try(int i, int j){
	if(i == m - 1 and j == n - 1) ++cnt;
	if(i < m - 1) Try(i + 1, j);
	if(j < n - 1) Try(i, j + 1);
}

int main (){
	int t; t = 1;
	cin >> t;
	while (t--){
		cnt = 0;
		memset(a, 0, sizeof(a));

		cin >> m >> n;
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				cin >> a[i][j];
			}
		}
		Try(0, 0);
		cout << cnt << endl;

	}
	return 0;
}

/////////////////////////////////////////////////////////////

//DSA02006 - DÃY CON TỔNG BẰNG K

int n, sum, s, a[1001], x[1001];
vector<vector<int>> final;

void Try(int i, int start){
	for (int j = start; j < n; ++j){
		x[i] = a[j];
		sum += a[j];

		if (sum == s) {
			vector<int> tmp(x, x + i + 1);
			final.pb(tmp);
		}
		else if(sum < s) Try(i + 1, j + 1);
		sum -= a[j];
	}
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		memset(x, 0, sizeof(x));
		sum = 0;
		final.clear();

		cin >> n >> s;
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a, a + n);
		Try(0, 0);

		if (final.sz == 0) cout << -1 << endl; 

		else for (auto it : final){
			cout << "[";
			for (int i = 0; i < it.sz - 1; ++i) cout << it[i] << ' ';
			cout << it[it.sz - 1] << "] ";
		}
		cout << endl;
	}
	return 0;
}



//////////////////////////////////////////////////////////////////

//DSA02005	HOÁN VỊ XÂU KÝ TỰ

int main ()
{
	int t; t = 1; 
	cin >> t;
	while (t--){
		string s; cin >> s;
		vector<char> v;
		for (int i = 0; i < s.sz; ++i) v.pb(s[i]);

		vector<int> a;
		for (int i = 0; i < s.sz; ++i) a.pb(i);

		do{
			for (int i = 0; i < a.sz; ++i) {
				cout << v[a[i]] << "";
			}
			cout << " ";
		}
		while (next_permutation(a.begin(), a.end()));
		cout << endl;
	}
}


////////////////////////////////////////////////////////////

// DSA02003 - DI CHUYỂN TRONG MÊ CUNG 1

int n, a[1001][1001], check;
string s;

void Try(int i, int j)
{
	if(i == n and j == n) {
		cout << s << " ";
		check = 1;
		return;
	}

	if(a[i + 1][j] == 1) {
		s += "D";
		Try(i + 1, j);
		s.erase(s.sz - 1, 1);
	}

	if (a[i][j + 1] == 1) {
		s += "R";
		Try(i, j + 1);
		s.erase(s.sz - 1, 1);
	}
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--){

		s = "";
		check = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i){
			for (int j =1; j <= n; ++j){
				cin >> a[i][j];

			}
		}
		if (a[1][1] == 0) cout << -1;
		else {
			Try(1, 1);
			if(check == 0) cout << -1;
		}

		cout << endl;
	}
	return 0;
}

//////////////////////////////////////////////////////

//	DSA02002	DÃY SỐ 2

void printTriangle(int a[], int n) 
{
    if (n == 1) {
        cout << "[" << a[0] << "] "; 
        return;
    }
    int b[n - 1];
    for (int i = 0; i < n - 1; i++) {
        b[i] = a[i] + a[i + 1];
    }
    printTriangle(b, n - 1);
    cout << "[";
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << "] " ;
}


int main ()
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        printTriangle(a, n);
        cout << endl;
    }
    return 0;
}



/////////////////////////////////////////////////////////////////////

//	DSA02001	DÃY SỐ 1

int n, a[1000001];

void Try(int i)
{
	if(i > 0) {
		cout << "[";
		for (int j = 0; j < i - 1; ++j) cout << a[j] << ' ';
		cout << a[i - 1] << "]" << endl;

		for (int j = 0; j < i - 1; ++j){
			a[j] = a[j] + a[j + 1];
		}
		Try(i - 1);
	}
}

int main () 
{
	int t; t = 1;
	cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		Try(n);
	}
	return 0;
}


///////////////////////////////////////////////////////////

//	DSA01024	ĐẶT TÊN - 1

int n, k, a[1000001]; 
vector<string> v;

void display()
{
	for (int i = 1; i <= k; ++i){
		cout << v[a[i] - 1] << " ";
	}
	cout << endl;
}

void backtrack(int i) 
{
	for (int j = a[i - 1] + 1; j <= v.sz - k + i; ++j){
		a[i] = j;
		if(i == k) display();
		else backtrack(i + 1);
	}
}

int main ()
{
	int t; t = 1;
	// cin >> t;
	while (t--){
		cin >> n >> k;
		set<string> se;
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			se.insert(s);
		}

		for (auto it : se) {
			v.pb(it);
		}
		a[0] = 0;
		backtrack(1);
	}
	return 0;
}
