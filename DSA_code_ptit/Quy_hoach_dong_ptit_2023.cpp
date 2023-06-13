#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz size()
#define pb push_back
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);


//	DSA05030	DI CHUYỂN VỀ GỐC TỌA ĐỘ

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<ll>> dp(n + 5, vector<ll>(m + 5, 1));

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        cout << dp[0][0] << endl;
    }

    return 0;
}



////////////////////////////////////////////////////////////////////////////////

//	DSA05033	XÂU ĐỐI XỨNG 2

int main()
{
    faster();
    int t = 1;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int dp[41][41] = {};
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        for(int i = 0; i < s.sz; ++i)
        {
            for(int j = 0; j < tmp.sz; ++j)
            {
                if(s[i] == tmp[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        int M = dp[s.sz][tmp.sz];
        cout << s.sz - M << endl;
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////

//DSA05032 - XÂU ĐỐI XỨNG 1

int main()
{
    faster();
    int t = 1;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int dp[41][41] = {};
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        for(int i = 0; i < s.sz; ++i)
        {
            for(int j = 0; j < tmp.sz; ++j)
            {
                if(s[i] == tmp[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        int M = dp[s.sz][tmp.sz];
        cout << s.sz - M << endl;
    }
    return 0;
}



/////////////////////////////////////////////////////////////////////////////////


//DSA05011 - SỐ CÓ TỔNG CHỮ SỐ BẰNG K

int main()
{
    faster();
    int t, n, k;
    cin >> t;
    const int mod = 1e9 + 7;
    int dp[105][50005] = {};
    for(int i = 1; i <= 9; ++i)
        dp[1][i] = 1;
    for(int i = 1; i <= 100; ++i)
        for(int j = 0; j <= 9; ++j)
            for(int z = j; z <= 50000; ++z)
                dp[i][z] = (dp[i][z] + dp[i - 1][z - j]) % mod;
    while(t--)
    {
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
    return 0;
}




/////////////////////////////////////////////////////////////////////////////////////////

//DSA05010 - DÃY CON DÀI NHẤT CÓ TỔNG CHIA HẾT CHO K

int main()
{
    int t = 1, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            a[i] %= k;
        }
        int dp[n][k];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < k; ++j)
                dp[i][j] = INT_MIN;
        dp[0][a[0]] = 1;
        for(int i = 1; i < n; ++i)
            for(int j = 0; j < k; ++j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j + k - a[i]) % k] + 1);
        cout << dp[n - 1][0] << endl;
    }
    return 0;
}


///////////////////////////////////////////////////////////////////////////////

//	DSA05043	SỐ THUẬN NGHỊCH

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int n= s.sz;
		s = "x" + s;

		//f[i][j] == f[i + 1][j - 1]  and s[i] = s[j]
		bool f[n + 1][n + 1];
		memset(f, false, sizeof(f));
		for (int i = 0; i <= n; ++i) f[i][i] = true;
		int ans = 1;
		for (int length = 2; length <= n; ++length)
		{
			for (int i = 1; i <= n - length + 1; ++i)
			{
				int j = i + length - 1;
				if(length == 2 and s[i] == s[j]) f[i][j] = true;
				else
				{
					f[i][j] = f[i + 1][j - 1] and (s[i] == s[j]);
				}
				if(f[i][j]) ans = max(length, ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

//	DSA05042	DÃY CON LIÊN TIẾP TỔNG BẰNG K

string solve(ll* a, int &n, ll &k)
{
    unordered_map<ll, int> m;
    ll sum = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += a[i];
        if(sum == k or m[sum - k])
            return "YES";
        m[sum] = 1;
    }
    return "NO";
}

int main()
{
    faster();
    int t, n;
    ll k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ll a[n];
        for(ll &i : a)
            cin >> i;
        cout << solve(a, n, k) << endl;
    }
    return 0;
}

//////////////////////////////////////////////////////////////////

//DSA05041 - BIẾN ĐỔI VỀ XÂU ĐỐI XỨNG

int countRemovals(string s) {
    int n = s.length();
    
    // Khởi tạo bảng DP với giá trị ban đầu là 0
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Trường hợp cơ sở: chuỗi con có độ dài 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
    }
    
    // Tính toán độ dài các chuỗi con có độ dài từ 2 đến n
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[0][n - 1];
}

int main() {
    int T = 1;
    cin >> T;
    
    while (T--) {
        string s;
        cin >> s;
        
        int result = countRemovals(s);
        cout << result << endl;
    }
    
    return 0;
}




/////////////////////////////////////////////////////////////////////////

//DSA05040 - DÃY TAM GIÁC DÀI NHẤT

int main()
{
    int t = 1;
    cin >> t;
    int n, a[100005];
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> a[i];
        int inc[n], dec[n];
        inc[0] = dec[n - 1] = 1;
        for(int i = 1; i < n; ++i)
        {
            if(a[i] > a[i - 1]) inc[i] = inc[i - 1] + 1;
            else inc[i] = 1;
        }
        for(int i = n - 2; i >= 0; --i)
        {
            if(a[i] > a[i + 1]) dec[i] = dec[i + 1] + 1;
            else dec[i] = 1;
        }
        int ans = -1;
        for(int i = 0; i < n; ++i) ans = max(ans, inc[i] + dec[i] - 1);
        cout << ans << endl;
    }
    return 0;
}


///////////////////////////////////////////////////////////////////////////

//	DSA05036	TĂNG - GIẢM

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n; cin >> n;
		double a[n], b[n];
		for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
		
		vector<ll> dp(n, 1);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if(a[i] > a[j] and b[j] > b[i]) dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		cout << *max_element(dp.begin(), dp.end()) << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////////

//DSA05028 - BIẾN ĐỔI XÂU

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		string s1, s2; cin >> s1 >> s2;
		int dp[105][105];
		for (int i = 0; i <= s1.sz; ++i) dp[i][0] = i;
		for (int j = 0; j <= s2.sz; ++j) dp[0][j] = j;

		for (int i = 1; i <= s1.sz; ++i)
		{
			for (int j = 1; j <= s2.sz; ++j)
			{
				if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
				else
				{
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
				}
			}
		}
		cout << dp[s1.sz][s2.sz] << endl;
	}              
	return 0;                                                  
}

/////////////////////////////////////////////////////////////////////////////

//	DSA05024	TỔNG BẰNG K

const int mod = 1e9 + 7;

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		int a[n + 1];
		for (int i = 0; i < n; ++i) cin >> a[i];
		vector<int> dp(k + 5, 0);
		dp[0] = 1;
		for (int i = 1; i <= k; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(i >= a[j])
				{
					dp[i] = (dp[i] % mod + dp[i - a[j]] % mod) % mod;
				}
			}
		}
		cout << dp[k] << endl;
	}
	return 0;
}


////////////////////////////////////////////////////////

//DSA05023 - TỔNG CÁC XÂU CON

int main() {
    int T;
    cin >> T;

    while (T--) {
        string N;
        cin >> N;

        long long result = 0;

        for (int len = 1; len <= N.length(); len++) {
            for (int start = 0; start <= N.length() - len; start++) {
                string numStr = N.substr(start, len);
                result += stoll(numStr);
            }
        }

        cout << result << endl;
    }

    return 0;
}



////////////////////////////////////////////////////////////////////////////////////////

//	DSA05022	KÝ TỰ GIỐNG NHAU

int main()
{
    faster();
    int t = 1, n, insrt, cpy, del;
    cin >> t;
    while (t--)
    {
        cin >> n >> insrt >> del >> cpy;
        vector<int> dp(n + 1);
        int i = 1;
        dp[0] = 0;
        while (i <= n)
        {
            dp[i] = dp[i - 1] + insrt;
            if (i % 2 == 1)
                dp[i] = min(dp[i], dp[(i + 1) / 2] + del + cpy);
            else
                dp[i] = min(dp[i], dp[i / 2] + cpy);
            ++i;
        }
        cout << dp[n] << endl;
    }
    return 0;
}



//////////////////////////////////////////////////////////////////////////////////////////

//DSA05020 - ĐƯỜNG ĐI NHỎ NHẤT

int main ()
{
	int t = 1; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;
		int a[n + 1][m + 1], dp[n + 1][m + 1];
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> a[i][j];
			}
		}
		//Initial dp 
		dp[1][1] = a[1][1];
		for (int i = 2; i <= n; ++i) dp[i][1] = a[i][1] + dp[i - 1][1];
		for (int j = 2; j <= m; ++j) dp[1][j] = a[1][j] + dp[1][j - 1];

		for (int i = 2; i <= n; ++i)
		{
			for (int j = 2; j <= m; ++j)
			{
				dp[i][j] = a[i][j] + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////

//DSA05019 - HÌNH VUÔNG LỚN NHẤT

int main ()
{
	int t = 1; 
	cin >> t;
	while (t--)
	{
		int n, m, ans = 0; cin >> n >> m;
		int dp[n + 1][m + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				int x; cin >> x;
				if(x == 0) dp[i][j] = 0;
				else
				{
					dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
					ans = max(ans, dp[i][j]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////

//DSA05018 - XÂU CON ĐỐI XỨNG DÀI NHẤT

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int n= s.sz;
		s = "x" + s;

		//f[i][j] == f[i + 1][j - 1]  and s[i] = s[j]
		bool f[n + 1][n + 1];
		memset(f, false, sizeof(f));
		for (int i = 0; i <= n; ++i) f[i][i] = true;
		int ans = 1;
		for (int length = 2; length <= n; ++length)
		{
			for (int i = 1; i <= n - length + 1; ++i)
			{
				int j = i + length - 1;
				if(length == 2 and s[i] == s[j]) f[i][j] = true;
				else
				{
					f[i][j] = f[i + 1][j - 1] and (s[i] == s[j]);
				}
				if(f[i][j]) ans = max(length, ans);
			}
		}
		cout << ans << endl;
	}
	return 0;
}



//////////////////////////////////////////////////////////////

//DSA05017 - DÃY SỐ BI-TONIC

int n, a[105], dp1[105], dp2[105];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            dp1[i] = dp2[i] = a[i];
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (a[i] > a[j]) {
                    dp1[i] = max(dp1[i], dp1[j] + a[i]);
                }
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            for (int j = n; j > i; j--) {
                if (a[i] > a[j]) {
                    dp2[i] = max(dp2[i], dp2[j] + a[i]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp1[i] + dp2[i] - a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}


////////////////////////////////////////////////////////

//DSA05016 - SỐ UGLY

int main() {
    int t;
    cin >> t;
    while (t--) {
    	
        int n;
        cin >> n;
        int ugly[n];
        ugly[0] = 1;

        int idx2 = 0, idx3 = 0, idx5 = 0;
        int next2 = 2, next3 = 3, next5 = 5; 

        for (int i = 1; i < n; i++) {

            int min_next = min(next2, min(next3, next5)); 
            ugly[i] = min_next; 

            if (min_next == next2) {
                idx2++; 
                next2 = ugly[idx2] * 2; 
            }
            if (min_next == next3) { 
                idx3++; 
                next3 = ugly[idx3] * 3; 
            }
            if (min_next == next5) { 
                idx5++; 
                next5 = ugly[idx5] * 5; 
            }
        }

        cout << ugly[n - 1] << endl; 
    }
    return 0;
}


//////////////////////////////////////////////////////////////

//DSA05015 - TÍNH P(N,K)

const ll mod = 1e9 + 7;

int main ()
{
	int t; cin >> t;
	while (t--)
	{
		int n, k; 
		cin >> n >> k;

		if(k > n) cout << 0 << endl;
		else if(!k) cout << 1 << endl;
		else 
		{
			ll  res = 1;
			for (int i = n - k + 1; i <= n; ++i)
			{
				res = (res * i) % mod;
			}
			cout << res << endl;
		}
	}
	return 0;
}



///////////////////////////////////////////////////////////////////

	// DSA05007 - TỔNG LỚN NHẤT CỦA DÃY CON KHÔNG KỀ NHAU

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int a[n + 1];
		for (int i = 1; i <= n; ++i) cin >> a[i];

		int f1 = a[1];
		int f2 = max(a[1], a[2]);
		int f3 = max(a[2], a[1] + a[3]);
		for (int i = 4; i <= n; ++i)
		{
			int fi = max(f2, f1) + a[i];
			f1 = f2;
			f2 = f3;
			f3 = fi;
		}
		int result = max(f2, f3);
		cout << result << endl;
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////

//DSA05006 - TỔNG LỚN NHẤT CỦA DÃY CON TĂNG DẦN

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, res = -1e9; cin >> n;
		int a[n + 1];
		int dp[n + 1];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			dp[i] = a[i];
		} 
		for(int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if(a[i] > a[j]) 
				{
					dp[i] = max(dp[i], dp[j] + a[i]);
				}
			}
			res = max(res, dp[i]);
		}
		cout << res << endl;
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

//DSA05003 - DÃY CON CHUNG DÀI NHẤT CỦA BA XÂU

int main ()
{
	int t; cin >> t;
	while (t--)
	{
		int n, m, k; cin >> n >> m >> k;
		string x, y, w; cin >> x >> y >> w;
		int dp[n + 5][m + 5][k + 5];
		memset(dp, 0, sizeof(dp));

		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				for (int z = 0; z <= k; ++z)
				{
					if(i == 0 or z == 0 or j == 0) dp[i][j][z] = 0;
					else 
					{
						if(x[i - 1] == w[z - 1] and x[i - 1] == y[j - 1])
						{
							dp[i][j][z] = dp[i - 1][j - 1][z - 1] + 1;
						}
						else dp[i][j][z] = max(dp[i - 1][j][z], max(dp[i][j - 1][z], dp[i][j][z - 1]));
					}
				}
			}
		}
		cout << dp[n][m][k] << endl;
	}
	return 0;
}


////////////////////////////////////////////////////////////////

// DSAKT110	NHÀ KHÔNG KỀ NHAU

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int a[n + 1];
		for (int i = 1; i <= n; ++i) cin >> a[i];

		int f1 = a[1];
		int f2 = max(a[1], a[2]);
		int f3 = max(a[2], a[1] + a[3]);
		for (int i = 4; i <= n; ++i)
		{
			int fi = max(f2, f1) + a[i];
			f1 = f2;
			f2 = f3;
			f3 = fi;
		}
		int result = max(f2, f3);
		cout << result << endl;
	}
	return 0;
}

//////////////////////////////////////////////////////////////

// DSAKT055 - BÀI TOÁN CÁI TÚI 0-1

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, s; cin >> n >> s;
		ll w[n + 1], v[n + 1];
		for (int i = 1; i <= n; ++i) cin >> w[i];
		for (int i = 1; i <= n; ++i) cin >> v[i];

		ll dp[n + 1][s + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= s; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				if(j >= w[i]) 
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
				}
			}
		}
		cout << dp[n][s] << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////////////

//DSAKT053 - SỐ NGUYÊN LỚN

int main ()
{
	int t = 1; 
	cin >> t;
	while (t--){
		string x, y; cin >> x >> y;

		int n = x.sz, m = y.sz;
		int f[n + 1][m + 1];

		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				if(i == 0 or j == 0)
				{
					f[i][j] = 0;
				}
				else 
				{
					if(x[i - 1] == y[j - 1])
					{
						f[i][j] = f[i - 1][j - 1]  + 1;
					}
					else 
					{
						f[i][j] = max(f[i - 1][j], f[i][j - 1]);
					}
				}
			}
		}
		cout << f[n][m] << endl;
	}
	return 0;
}


///////////////////////////////////////////////////////////////

//DSA05034 - TỔNG SỐ CÁCH DI CHUYỂN

const int mod = 1e9 + 7;

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		int dp[n + 1];
		dp[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			dp[i] = 0;
			for (int j = 1; j <= min(i, k); ++j)
			{
				dp[i] = (dp[i] + dp[i - j]) % mod;
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}


//////////////////////////////////////////////////////////////////

// /DSA05029 - GIẢI MÃ

int numDecodings(string s)
{
	int n = s.sz;
	int dp[n + 1];
	dp[0] = 1;
	dp[1]= s[0] == '0' ? 0 : 1;
	for (int i = 2; i <= n; ++i)
	{
		int oneDigit = stoi(s.substr(i - 1, 1));
		int twoDigit = stoi(s.substr(i - 2, 2));
		dp[i] = 0;
		if(oneDigit >= 1) dp[i] += dp[i - 1];
		if(twoDigit >= 10 and twoDigit <= 26) dp[i] += dp[i - 2];
	}
	return dp[n];
}

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		string s; cin >> s;
		cout << numDecodings(s) << endl;
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////

//DSA05027 - CÁI TÚI

int main ()
{
	int t = 1; 
	cin >> t;
	while (t--)
	{
		ll n, m; cin >> n >> m;
		ll w[n + 1], v[n + 1];

		for (int i = 1; i <= n; ++i) cin >> w[i];
		for (int i = 1; i <= n; ++i) cin >> v[i];

		ll dp[n + 1][m + 1];
		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				// ko lay do vat thu i
				dp[i][j] = dp[i - 1][j];

				// lay do vat thu i vao tui
				if(j >= w[i])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
				}
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////////////

//DSA05026 - XEM PHIM

int main ()
{
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int s, n; cin >> s >> n;
		ll w[n + 1];
		for (int i = 1; i <= n; ++i) cin >> w[i];
		ll dp[n + 1][s + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= s; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				if(j >= w[i])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i]);
				}
			}
		}
		cout << dp[n][s] << endl;
	}
	return 0;
}


////////////////////////////////////////////////////////////

//	DSA05025	CON ẾCH

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		ll dp[n + 1];
		dp[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			dp[i] = 0;
			for (int j = 1; j <= min(i, 3); ++j)
			{
				dp[i] = dp[i] + dp[i - j];
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////////

//DSA05013 - BẬC THANG

const int mod = 1e9 + 7;

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		int dp[n + 1];
		dp[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			dp[i] = 0;
			for (int j = 1; j <= min(i, k); ++j)
			{
				dp[i] = (dp[i] + dp[i - j]) % mod;
			}
		}
		cout << dp[n] << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////////

// /DSA05012 - TỔ HỢP C(n, k)

const int mod = 1e9 + 7;

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		ll C[k + 1];
		memset(C, 0, sizeof(C));

		C[0] = 1;
		 // Compute next row of pascal triangle using
	     // the previous row
		for (int i = 1; i <= n; ++i)
		{
			for (int j = min(i, k); j > 0; --j)
			{
				C[j] = C[j] % mod + C[j - 1] % mod;
			}
		}
		cout << C[k] % mod << endl;
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////

//DSA05008 - DÃY CON CÓ TỔNG BẰNG S

int main ()
{
	int t = 1; 
	cin >> t;
	while (t--)
	{
		int n, s; cin >> n >> s;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		vector<bool> f(s + 1, false);
		f[0] = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = s; j >= a[i]; --j)
			{
				if(f[j - a[i]] == true) f[j] = true;
			}
		}
		if(f[s]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////

//DSA05005 - SỐ BƯỚC ÍT NHẤT

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		vector<int> f(n, 1);
		for (int i = 0; i < n; ++i) 
		{
			for (int j = 0; j < i; ++j)
			{
				if(a[i] >= a[j])
				{
					f[i] = max(f[i], f[j] + 1);
				}
			}
		}
		cout << n - *max_element(f.begin(), f.end()) << endl;
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////

//	DSA05004	DÃY CON TĂNG DÀI NHẤT

int main ()
{
	int t = 1;
	//cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		vector<int> F(n, 1);

		for (int i = 0; i < n; ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				if(a[i] > a[j]) 
				{
					F[i] = max(F[i], F[j] + 1);
				}
			}
		}
		cout << *max_element(F.begin(), F.end()) << endl;
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////

//DSA05001 - XÂU CON CHUNG DÀI NHẤT

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		string x, y; cin >> x >> y;
		int n = x.sz, m = y.sz;
		int f[n + 1][m + 1];

		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				if(i == 0 or j == 0) f[i][j] = 0;
				else
				{
					if(x[i - 1] == y[j - 1]) 
					{
						f[i][j] = f[i - 1][j - 1] + 1;
					}
					else 
					{
						f[i][j] = max(f[i - 1][j], f[i][j - 1]);
					}
				}
			}
		}
		cout << f[n][m] << endl;
	}
	return 0;
}
