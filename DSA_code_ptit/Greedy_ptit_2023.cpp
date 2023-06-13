#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz size()
#define pb push_back
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);


//DSA03014 - SỐ KHỐI LẬP PHƯƠNG

vector<long long> v;

string calc(string& s) {
    string tmp;
    for (long long& i : v) {
        tmp = to_string(i);
        int idx = 0;
        for (char& j : s) {
            if (j == tmp[idx])
                ++idx;
        }
        if (idx == tmp.size())
            return tmp;
    }
    return to_string(-1);
}

int main() {

    int t = 1;
    cin >> t;

    for (int i = 100; i; --i)
        v.push_back((long long)i * i * i);

    string s;
    while (t--) {
        cin >> s;
        cout << calc(s) << endl;
    }

    return 0;
}


//////////////////////////////////////////////////////////////////

//DSA03020 - BIỂU THỨC ĐÚNG

int main()
{
    faster();
    int t = 1;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        stack<char> st;
        int cnt = 0, res = 0;
        for(char &i : s)
        {
            if(st.empty())
            {
                st.push(i);
                cnt = 0;
            }
            else if(st.top() == '[' and i == ']')
            {
                cnt += 2;
                st.pop();
            }
            else if(st.top() == ']' and i == '[')
            {
                res += st.sz + cnt;
                st.pop();
            }
            else if(i == ']' and st.top() == ']') st.push(i);
            else if(i == '[') st.push(i);
        }
        cout << res << endl;
    }
    return 0;
}


////////////////////////////////////////////////////////////////

//DSA03019 - PHÂN SỐ ĐƠN VỊ

void solve(ll p, ll q)
{
    ll x = 0;
    while(1)
    {
        if(q % p == 0)
        {
            cout << "1/" << q / p << endl;
            return;
        }
        
        x = q / p + 1;
        cout << "1/" << x << " + ";
        p = x * p - q;
        q *= x;
    }
}

int main()
{
    int t = 1;
    cin >> t;
    ll p, q;
    while(t--)
    {
        cin >> p >> q;
        solve(p, q);
    }
    return 0;
}


//////////////////////////////////////////////////////////////////

// DSA03018 - SỐ MAY MẮN

int main()
{
	int t = 1; cin >> t; 
	while (t--)
	{
	    int n; cin >> n;
	    int ok = 0;

    	for (int d7 = n / 7; d7 >= 0; d7--)
    	{
    	    int k = n - d7 * 7;
        	if (k % 4 == 0) {
            	for (int j = 0; j < k / 4; j++)
            	{
                	cout << 4;
            	}
            	for (int j = 0; j < d7; j++)
            	{
                	cout << 7;
            	}
            	ok = 1;
            	cout << endl;
            	break;
        	}
    	}
    	if (!ok) cout << -1 << endl;
	}
}


//////////////////////////////////////////////////////////////////

//DSA03017 - GIÁ TRỊ NHỎ NHẤT CỦA XÂU

int main ()
{
    int t; cin >> t;
    while (t--)
    {    
        int k; cin >> k;
        string s; cin >> s;
        priority_queue<int> Q;
        map<char, int> mp;

        for (int i = 0; i < s.sz; ++i)
        {
            mp[s[i]]++;
        }

        for (auto it : mp)
        {
            Q.push(it.second);
        }

        while (k--)
        {
            int top1 = Q.top();

            if(top1 == 0) break;
            Q.pop();
            --top1;
            Q.push(top1);
        }

        ll sum = 0;
        while(Q.size() > 0)
        {
            sum +=  1ll * Q.top() * Q.top();
            Q.pop();
        }
        cout << sum << endl;
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////

//DSA03016 - SỐ NHỎ NHẤT

int main()
{
    int t = 1, s, d;
    cin >> t;
    while(t--)
    {
        cin >> s >> d;
        stack<int> st;
        if(d == 1 and s == 0) cout << 0;
        if(s == 0 or d * 9 < s) cout << -1;
        else
        {
            --s;
            while(d--)
            {
                if(s >= 9)
                {
                    st.push(9);
                    s -= 9;
                }
                else if (s > 0)
                {
                    st.push(s);
                    s = 0;
                }
                else st.push(0);
            }

            cout << st.top() + 1;
            st.pop();
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
        }
        cout << endl;
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////


//	DSA03011	NỐI DÂY 2

const int mod = 1e9 + 7;

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n; cin >> n;
		priority_queue<ll, vector<ll>, greater<ll>> q;

		for (int i = 0; i < n; ++i) 
		{
			ll x; cin >> x;
			q.push(x);
		}

		ll sum = 0;
		while (q.sz > 1) 
		{
			ll u1 = q.top(); q.pop();
			ll u2 = q.top(); q.pop();
			sum += u1 + u2;
			sum % mod;
			q.push((u1 + u2) % mod);
		}

		cout << sum % mod << endl;
	}
	return 0;               
}




//////////////////////////////////////////////////////////////////////////////

// /	DSA03009	SẮP XẾP CÔNG VIỆC 2

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main ()
{
	int t = 1;
	cin >> t;
	while(t--)
	{
		int n; cin >> n;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x >> v[i].first >> v[i].second;
		}
		sort(v.begin(), v.end(), cmp);

		bool used[1005] = { false };
		int cnt = 0, total = 0;

		for (auto p : v)
		{
			while( p.first > 0 and used[p.first] ) --p.first;

			if(!used[p.first] and p.first > 0)
			{
				++cnt;
				total += p.second;
				used[p.first] = true;
			}
		}
		cout << cnt << ' ' << total << endl;
	}
	return 0;
}



////////////////////////////////////////////////////////////////////

//DSA03007 - GIÁ TRỊ NHỎ NHẤT CỦA BIỂU THỨC

int main(){

    int t, n;
    ll res;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll a[n], b[n];
        for(ll &i : a) cin >> i;
        for(ll &i : b) cin >> i;
        sort(a, a + n);
        sort(b, b + n, greater<int>());
        res = 0;
        for(int i = 0; i < n; ++i) res += a[i] * b[i];
        cout << res << endl;
    }
    return 0;
}


//////////////////////////////////////////////////////////////////

//DSA03035 - SẮP XẾP ĐƠN GIẢN

int main ()
{
	int n; cin >> n;
	vector<int> a(n + 1), f(n + 1, 0) ;

	for (int i = 1; i <= n; ++i) cin >> a[i];
	int res = 0;

	for (int i = 1; i <= n; ++i) 
	{
		f[a[i]] = f[a[i] - 1] + 1;
		res = max(res, f[a[i]]);
	}
	cout << n - res << endl;
	return 0;
}



//////////////////////////////////////////////////////////////////

//DSA03034 - DÃY CON CHUNG

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		map<int, int> mp1, mp2, mp3;

		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x; 
			mp1[x]++;
		}

		for (int i = 0; i < m; ++i)
		{
			int x; cin >> x; 
			mp2[x]++;
		}

		for (int i = 0; i < k; ++i)
		{
			int x; cin >> x; 
			mp3[x]++;
		}

		bool found = false;
		for (auto it = mp1.begin(); it != mp1.end(); ++it)
		{
			int num = it -> first;
			if(mp2.find(num) != mp2.end() and mp3.find(num) != mp3.end())
			{
				found = true;
				int cnt = min(it -> second, min(mp2[num], mp3[num]));
				while (cnt--)
				{
					cout << num << ' ';
				}
			}
		}
		if(found == false) cout << "NO";
		cout << endl;
	}
	return 0;
}


/////////////////////////////////////////////////////////////////

//DSA03024 - LỰA CHỌN TỐI ƯU
//DSA03025 - TRỤC TỌA ĐỘ

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		vector<pair<int, int>> v;
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int a, b; cin >> a >> b;
			v.pb({a, b});
		}

		sort(v.begin(), v.end(), cmp);

		int cnt = 1, check = v[0].second;
		for (int i = 1; i < v.sz; ++i)
		{
			if(v[i].first >= check)
			{
				++cnt;
				check = v[i].second;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}


///////////////////////////////////////////////////////////////////////////

// 	DSA03022	TÍCH LỚN NHẤT

int main (){
	int n; cin >> n;

	int M1, M2, M3, m1, m2, m3;

	M1 = M2 = M3 = INT_MIN;
	m1 = m2 = m3 = INT_MAX;

	while (n--){
		int x; cin >> x;

		//Find 3 biggest positive numbers in the array

		if(x > M1){
			M3 = M2;
			M2 = M1;
			M1 = x;
		}
		else if (x > M2){
			M3 = M2;
			M2 = x;
		}
		else if(x > M3) M3 = x;


		//Find 3 smallest negative numbers in the array

		if(x < m1) {
			m3 = m2;
			m2 = m1;
			m1 = x;
		}
		else if ( x < m2){
			m3 = m2;
			m2 = x;
		}
		else if(x < m3) m3 = x;
	}

	cout << max(1ll * M1 * M2 * M3, max(1ll * m1 * m2 * M1, max(1ll * m1 * m2 , 1ll * M1 * M2))) << endl;

	return 0;
}


///////////////////////////////////////////////////////////////////////


// DSA03015 - MUA LƯƠNG THỰC

//*Notes: Compare the day needed to survive instead of calculating the amount of food needed

int main ()
{
	int t; cin >> t;
	while (t--)
	{
		int n, s, m; cin >> n >> s >> m;

		ll maxFoodRequired = s * m;

		ll dayBuyFood;

		if(maxFoodRequired % n == 0) dayBuyFood = maxFoodRequired / n;
		else dayBuyFood = maxFoodRequired / n + 1;

		ll maxDaySurvive = s / 7 * 6 + s % 7; // 6 days buy food per week

		if(dayBuyFood <= maxDaySurvive) cout << dayBuyFood << endl;
		else cout << - 1 << endl;

	}
	return 0;
}


//////////////////////////////////////////////////////////////////

//DSA03013 - SẮP ĐẶT XÂU KÝ TỰ 2

//*Notes : s.size() - (n - 1) * (max - 1)

int main (){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		string s; cin >> s;
		map<char, int> mp;

		for (int i = 0; i < s.sz; ++i){
			mp[s[i]]++;
		}

		auto it = mp.begin();
		int max = it -> second;

		int check = s.sz - (n - 1) * (max - 1);

		if(check >= max) cout << 1 << endl;
		else cout << -1 << endl;
	}
	return 0;
}

////////////////////////////////////////////////////////////////////

//DSA03012 - SẮP ĐẶT XÂU KÝ TỰ 1

//*Notes : aaaabc : false  , aabcd : true   

int main ()
{
	int t; cin >> t; 
	while (t--)
	{
		string s; cin >> s;
		map<char, int> mp;

		for (int i = 0; i < s.sz; ++i )
		{
			mp[s[i]]++;
		}

		auto it = mp.begin();
		int max = it -> second;

		if(max <= s.sz - max + 1) cout << 1 << endl;
		else cout << -1 << endl;
	}
	return 0;
}

////////////////////////////////////////////////////////////////

//DSA03010	NỐI DÂY 1

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--)
	{
		priority_queue<int, vector<int>, greater<int>> q;
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			q.push(x);
		}
		ll sum = 0;
		while (q.sz > 1)
		{
			int x1 = q.top(); q.pop();
			int x2 = q.top(); q.pop();

			sum += x1 + x2;
			q.push(x1 + x2); 
		}
		cout << sum << endl;
	}
	return 0;
}



/////////////////////////////////////////////////////////////////

//DSA03008 - SẮP XẾP CÔNG VIỆC 1

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<pair<int, int>> v;
		int a[n], b[n];

		for (int  i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0 ; i < n; ++i) cin >> b[i];
		for (int i = 0; i < n; ++i) v.pb({a[i], b[i]});
		sort(v.begin(), v.end(), cmp);

		int check = v[0].second;
		int cnt = 1;
		for (int i = 1; i < n; ++i)
		{
			if(v[i].first >= check)
			{
				++cnt;
				check = v[i].second;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}


/////////////////////////////////////////////////////////

//	DSA03006	SẮP XẾP THAM LAM

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--)
	{
		int n; cin >> n;
		ll a[n];
		vector<ll> v;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			v.pb(a[i]);
		}
		sort(v.begin(), v.end());
		bool ok = true;

		for (int i = 0; i < n; ++i)
		{
			if(a[i] != v[i] and a[i] != v[n - i - 1])
			{
				ok = false;
				break;
			}
		}
		if(ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
 return 0;
}

//////////////////////////////////////////////////////////////////

//	DSA03005	CHIA MẢNG THÀNH HAI MẢNG CON CÓ TỔNG LỚN NHẤT

int n, k; 

int main()
{
	int t; t = 1;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		priority_queue<int, vector<int>, greater<int>> q;

		for (int i = 0; i < n; ++i)
		{
			int x; cin >> x;
			q.push(x);
		}

		int a = min(k, n - k);
		ll sum1 = 0; ll sum2 = 0;

		while (!q.empty() and a > 0)
		{
			int u = q.top(); q.pop();
			sum1 += u;
			--a;
		}
		while (!q.empty())
		{
			int u = q.top(); q.pop();
			sum2 += u;
		}
		cout << sum2 - sum1 << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

// //DSA03004 - TỔNG NHỎ NHẤT

//*Notes: vi tri chan tao thanh 1 so, vi tri le tao thanh 1 so

int main ()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		priority_queue<int, vector<int>, greater<int>> q;

		for (int i = 0; i < n; ++i){
			int x; cin >> x; q.push(x);
		}
		int i = 0; ll a = 0, b = 0;
		while (!q.empty() && i < n)
		{
			if(i % 2 == 0) a = q.top() + a * 10;
			else b = q.top() + b * 10;

			q.pop();
			i++;
		}

		cout << a + b << endl;
	}
	return 0;
}

////////////////////////////////////////////////////////////

//	DSA03003	TÌM MAX

int n, a[1000001];
const int modulo = 1e9 + 7;

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--)
	{
		cin >> n;
		priority_queue<int> q;

		for (int i = 0; i < n; ++i) 
		{
			cin >> a[i];
			q.push(a[i]);
		}
		int k = n - 1;
		ll sum = 0;

		while (!q.empty())
		{
			int u = q.top(); q.pop();
			sum += u * k;
			sum %= modulo;
			k--;
		}	
		cout << sum % modulo << endl;
	}
	return 0;
}


/////////////////////////////////////////////////////////////////

//DSA03002	NHẦM CHỮ SỐ

string s1, s2;

void solveMax(string &s)
{
	for (int i = 0; i < s.sz; ++i)
	{
		if(s[i] == '5') s[i] = '6';
	}
}

void solveMin(string &s)
{
	for (int i = 0; i < s.sz; ++i)
	{
		if(s[i] == '6') s[i] = '5';
	}
}


int main ()
{
	int t; t = 1;
	//cin >> t;
	while (t--)
	{
		cin >> s1 >> s2;
		solveMax(s1); solveMax(s2);
		ll Max1 = stoll(s1);
		ll Max2 = stoll(s2);

		solveMin(s1); solveMin(s2);
		ll Min1 = stoll(s1);
		ll Min2 = stoll(s2);

		cout << Min1 + Min2 << ' ' << Max1 + Max2 << endl;
	}
	return 0;
}



//////////////////////////////////////////////////////////////////

//	DSA03001	ĐỔI TIỀN

int n;
int a[10] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };

int main()
{
	int t; t = 1;
	cin >> t;
	while (t--)
	{
		cin >> n;
		int cnt = 0;
		priority_queue<int> q;

		for (int i = 0; i < 10; ++i) q.push(a[i]);

		while(!q.empty() and n > 0)
		{
			int u = q.top(); q.pop();

			int notes = n / u;
			cnt += notes;
			n -= notes * u;
		}

		cout << cnt << endl;
	}
	return 0;
}
