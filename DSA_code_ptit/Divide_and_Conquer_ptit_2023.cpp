#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz size()
#define pb push_back
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

//DSA04012 - TÍCH ĐA THỨC

int main()
{
    faster();
    int t = 1, n, m;
    cin >> t;
    int p[105], q[105];
    while(t--)
    {
        cin >> n >> m;
        vector<int> res(n + m, 0);

        for(int i = 0; i < n; ++i) cin >> p[i];
        for(int i = 0; i < m; ++i) cin >> q[i];

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                res[i + j] += p[i] * q[j];
        m += n - 1;

        for(int i = 0; i < m; ++i) cout << res[i] << ' ';
        cout << endl;
    }
    return 0;
}


/////////////////////////////////////////////////////////////////

//DSA04013 - SẮP XẾP KANGURU

int main ()
{
	int t; cin >>  t;
	while (t--)
	{
		int n; cin >> n;
		int a[n];

		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}

		sort(a, a + n);

		int cnt = n;
		int mid = n / 2;
		int left = mid - 1;
		int right = n - 1;

		while (left >= 0 && right >= mid)
		{

			if( a[right] >= 2 * a[left] )
			{
				--cnt;
				--left;
				--right;
			} 
			else 
			{
				--left;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////

//DSA04011 - TÍCH HAI SỐ NHỊ PHÂN

ll binaryPower (int exp)
{
	ll res = 1;
	ll base = 2;

	while (exp > 0)
	{
		res *= base;
		--exp;
	}
	return res;
}

ll binaryToDecimal (string &s)
{
	ll res = 0;
	int n = s.sz;
	int j = n - 1;

	for (int i = 0; i < n; ++i)
	{
		if(s[i] == '1'){
			res += binaryPower(j);
		}
		--j;
	}
	return res;
}

int main ()
{
	int t = 1; 
	cin >> t;
	while (t--){
		string s1, s2;
		cin >> s1 >> s2;
		
		ll a = binaryToDecimal(s1);
		ll b = binaryToDecimal(s2);

		cout << 1ll * a * b << endl;

	}
	return 0;
}


///////////////////////////////////////////////////////

//	DSA04007	HỆ CƠ SỐ K

int cv(string& s, int& k) 
{
    int res = 0;
    for (char& i : s) 
    {
        res = res * k + (i - '0');
    }
    return res;
}

int main() 
{
	faster();
    int t = 1;
    cin >> t;
    string a, b;
    while (t--) 
    {
        int k;
        cin >> k >> a >> b;
        int res = cv(a, k) + cv(b, k);
        //cout << cv(a, k) << ' ' << cv(b, k) << endl;

        stack<int> st;
        while (res) 
        {
            st.push(res % k);
            res /= k;
        }
        while (!st.empty()) 
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}


///////////////////////////////////////////////////////////////////

//DSA04035 - TÍNH LŨY THỪA

const ll mod = 1e9 + 7; 

ll power(ll a, ll b)
{
	if(b == 0) return 1;
	else if(b % 2 == 0) 
	{
		ll half = power(a, b / 2);
		return (1ll * half * half) % mod;
	}
	else 
	{
		ll half = power(a, b / 2);
		return (1ll * half * half % mod * a) % mod;
	}
}

int main ()
{
	ll a, b;
	while (1)
	{
		cin >> a >> b;
		if(a == 0 and b == 0) return 0;
		cout << power(a, b) << endl;
	}
}


///////////////////////////////////////////////////////////////////

//	DSA04025	DÃY SỐ VÔ HẠN
//  DSA04008 - SỐ FIBONACCI THỨ N

unordered_map<ll, ll> F;
const int mod = 1000000007;

ll fibo(ll n)
{
    if(F[n] != 0) 
    {
        return F[n];
    }

    ll k = n / 2;
    if(n % 2 == 1) 
    {
        return F[n] = (fibo(k) * fibo(k + 1) + fibo(k - 1) * fibo(k)) % mod;
    } 
    else {
        return F[n] = (fibo(k) * fibo(k) + fibo(k - 1) * fibo(k - 1)) % mod;
    }
}

int main()
{
    int t, n;
    F[0] = F[1] = 1;

    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n == 0) 
        {
            cout << 0 << endl;
        } 
        else 
        {
            cout << fibo(n - 1) << endl;
        }
    }
    return 0;
}



//////////////////////////////////////////////////////////////////////////

//	DSA04009	LŨY THỪA MA TRẬN 1

const int mod = 1e9 + 7;

struct matrix
{
    int n;
    ll a[20][20];
    //Nap chong phep nhan matrix
    friend matrix operator * (matrix x, matrix y)
    {
        matrix res;
        res.n = x.n;
        //xay dung mang a cho matri res
        for(int i = 0; i < x.n; i++)
        {
            for(int j = 0; j < x.n; j++)
            {
                res.a[i][j] = 0;
                //xay dung a[i][j] cho res
                for(int k = 0; k < x.n; k++)
                {
                    res.a[i][j] += x.a[i][k] * y.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

matrix powMod(matrix A, ll n)
{
    if(n == 1)
    {
        return A;
    }
    matrix X = powMod(A, n / 2);
    if(n % 2 == 0)
    {
        return X * X;
    }
    else
    {
        return X * X * A;
    }
}



int main(){

	int t = 1; cin >> t;
	while (t--)
	{
		matrix A;
	    ll k;
	    cin >> A.n >> k;
	    for(int i = 0; i < A.n; i++)
	    {
	        for(int j = 0; j < A.n; j++)
	        {
	            cin >> A.a[i][j];
	        }
	    }
	    matrix kq = powMod(A, k);

	    // ll ans = 0;
	    // for(int i = 0; i < A.n; ++i) ans = (ans + res.a[i][A.n - 1]) % mod;
	    // cout << ans << endl;

	    for(int i = 0; i < A.n; i++){
	        for(int j = 0; j < A.n; j++){
	            cout << kq.a[i][j] << ' ';
	        }
	        cout << endl;
	    }
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////////

//	DSA04024	LŨY THỪA MA TRẬN 2

const int mod = 1e9 + 7;

struct matrix
{
    int n;
    ll a[20][20];
    //Nap chong phep nhan matrix
    friend matrix operator * (matrix x, matrix y)
    {
        matrix res;
        res.n = x.n;
        //xay dung mang a cho matri res
        for(int i = 0; i < x.n; i++)
        {
            for(int j = 0; j < x.n; j++)
            {
                res.a[i][j] = 0;
                //xay dung a[i][j] cho res
                for(int k = 0; k < x.n; k++)
                {
                    res.a[i][j] += x.a[i][k] * y.a[k][j];
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

matrix powMod(matrix A, ll n)
{
    if(n == 1)
    {
        return A;
    }
    matrix X = powMod(A, n / 2);
    if(n % 2 == 0)
    {
        return X * X;
    }
    else
    {
        return X * X * A;
    }
}



int main(){

	int t = 1; cin >> t;
	while (t--)
	{
		matrix A;
	    ll k;
	    cin >> A.n >> k;
	    for(int i = 0; i < A.n; i++)
	    {
	        for(int j = 0; j < A.n; j++)
	        {
	            cin >> A.a[i][j];
	        }
	    }
	    matrix res = powMod(A, k);

	    ll ans = 0;
	    for(int i = 0; i < A.n; ++i) ans = (ans + res.a[i][A.n - 1]) % mod;
	    cout << ans << endl;

	    // for(int i = 0; i < A.n; i++){
	    //     for(int j = 0; j < A.n; j++){
	    //         cout << kq.a[i][j] << ' ';
	    //     }
	    //     cout << endl;
	    // }
	}
	return 0;
}


///////////////////////////////////////////////////////////////

// /DSA04022 - KÝ TỰ THỨ K TRONG XÂU

ll power(ll n, ll k)
{
	if(k == 0) return 1;
	else if(k % 2 == 0)
	{
		ll half = power(n, k / 2);
		return half * half;
	}
	else if(k % 2)
	{
		ll half = power(n, k / 2);
		return half * half * n;
	}
}

ll solve(ll n, ll k)
{
	ll pivot = power(2, n - 1);
	if(k == pivot) return n;
	else if(k < pivot) return solve(n - 1, k);
	else return solve(n - 1, k - pivot);
}

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		cout << (char)(solve(n, k) + 'A' - 1) << endl;
	}
	return 0;
}


/////////////////////////////////////////////////////////////////////////

//	DSA04021	DÃY XÂU NHỊ PHÂN

int main ()
{
	ll f[93];
	f[1] = f[2] = 1;
	for (int i = 3; i <= 92; ++i) f[i] = f[i - 2] + f[i - 1];

	int t = 1;
	cin >> t;
	while (t--)
	{
		string s = "001";
		ll n, k; cin >> n >> k;

		while (n > 2)
		{
			if(k <= f[n - 2]) n -= 2;
			else 
			{
				k -= f[n - 2];
				--n;
			}
		}
		cout << s[n] << endl;
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////

//DSA04020 - TÌM KIẾM NHỊ PHÂN

// Cach 1

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		vector<int> a(n);

		for (int i = 0; i < n; ++i) cin >> a[i];
		auto it = lower_bound(a.begin(), a.end(), k);

		if(it != a.begin() and *it == k) cout << it - a.begin() + 1 << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

// Cach 2: Su dung Binary_search



//////////////////////////////////////////////////////////////////////

// /DSA04018 - ĐẾM SỐ 0

int main() 
{
    int t = 1;
    cin >> t;
    while(t--) 
    {
		int n; cin >> n;
		vector<int> v(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		auto it = upper_bound(v.begin(), v.end(), 0);
		cout << it - v.begin() << endl;
    }
    return 0;
}



/////////////////////////////////////////////////////////////

//	DSA04017	PHẦN TỬ KHÁC NHAU

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n] b[n-1];

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        for(int i = 0; i  < n - 1; i++)
        {
            if(a[i] != b[i])
            {
                cout << i + 1;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}


////////////////////////////////////////////////////////////

//	DSA04016	PHẦN TỬ THỨ K

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, m, k; cin >> n >> m >> k;
		vector<int> final;
		vector<int> a(n), b(m);

		for (int i = 0; i < n; ++i) 
		{
			cin >> a[i];
			final.pb(a[i]);
		}
		for (int i = 0; i < m; ++i) 
		{
			cin >> b[i];
			final.pb(b[i]);
		}
		sort(final.begin(), final.end());

		cout << final[k - 1] << endl;
	}
	return 0;
}


///////////////////////////////////////////////////////////////

//	DSA04015	TÍNH FLOOR(X)

int main ()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		auto it = lower_bound(a.begin(), a.end(), x);
		
		if(it != a.begin() and *it == x) cout << it - a.begin() + 1 << endl;
		else if(it != a.begin()) cout << it - a.begin() << endl;
		else cout << -1 << endl;
	}
	return 0;
}



//////////////////////////////////////////////////////////////////////

//	DSA04010	DÃY CON LIÊN TIẾP CÓ TỔNG LỚN NHẤT

int main ()
{
	int t = 1;
	cin >> t;
	while (t--) 
	{
    	int n;
    	cin >> n;
    	vector<int> a(n);
    	bool check = false;

    	for (int i = 0; i < n; i++) 
    	{
        	cin >> a[i];
        	if (a[i] > 0) check = true;
    	}
    	int M = -101;
    	if (!check) 
    	{
        	for (int i = 0; i < n; i++) 
        	{
            	M = max(M, a[i]);
        	}
    	} 
    	else 
    	{
        	int sum = 0;
        	for (int i = 0; i < n; i++) 
        	{
            	sum += a[i];
            	if (sum < 0) sum = 0;
            	M = max(M, sum);
        	}
    	}
    	cout << M << endl;
	}
	return 0;
}



////////////////////////////////////////////////////////////////

//	DSA04005	DÃY XÂU FIBONACI

const int maxn = 93;

int main ()
{
	ll f[maxn];
	f[1] = f[2] = 1;
	for (int i = 3; i <= 92; ++i) f[i] = f[i - 1] + f[i - 2];

	int t = 1;
	cin >> t;
	while (t--)
	{
		ll n, k; cin >> n >> k;
		string s = "AAB";
		while (n > 2)
		{
			if(k <= f[n - 2]) n -= 2;
			else 
			{
				k -= f[n - 2];
				--n; 
			}

		}
		cout << s[n] << endl;
	}
	return 0;
}


///////////////////////////////////////////////////////////////

//	DSA04004	GẤP ĐÔI DÃY SỐ

ll power(ll n, ll k)
{
	if(k == 0) return 1;
	if(k % 2 == 0)
	{
		ll half = power(n, k / 2);
		return  half * half;
	}
	if(k % 2)
	{
		ll half = power(n, k / 2);
		return  half * half * n;
	}
}

ll solve(ll n, ll k)
{
	ll pivot = power(2, n - 1);
	if(k == pivot) return n;
	if(k < pivot) return solve(n - 1, k);
	if(k > pivot) return solve(n - 1, k - pivot); 
}

int main()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		ll n, k; cin >> n >> k;
		cout << solve(n, k) << endl;
	}
	return 0;
}


///////////////////////////////////////////////////////////

//	DSA04003	ĐẾM DÃY

const int mod = 123456789;

ll power(ll n, ll k)
{
	if(k == 0) return 1;
	else if(k % 2 == 0) 
	{
		ll half = power(n, k / 2);
		return (half * half) % mod;
	}
	else if(k % 2)
	{
		ll half = power(n, k / 2);
		return (half * half % mod * n) % mod;
	}
}


int main()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		cout << power(2, n - 1) << endl;
	}
	return 0;
}




///////////////////////////////////////////////////////////////

// /	DSA04002	LŨY THỪA ĐẢO

const int mod = 1e9 + 7;

ll power(ll n, ll k)
{
	if(k == 0) return 1;
	else if(k % 2 == 0)
	{
		ll half = power(n, k / 2);
		return (1ll * half * half) % mod; 
	}
	else if(k % 2)
	{
		ll half = power(n, k / 2);
		return ((1ll * half * half % mod) * n) % mod;
	}
}

int main ()
{
	int t = 1; 
	cin >> t;
	while (t--)
	{
		string k;
		cin >> k;
		string n = k;
		reverse(k.begin(), k.end());

		ll N = stoll(n);
		ll K = stoll(k);
		cout << power(N, K) << endl;
	}
	return 0;
}


////////////////////////////////////////////////////////////

// 	DSA04001	LŨY THỪA

const int mod = 1e9 + 7;

ll power(int n, int k)
{
	if (k == 0) return 1;
	else if(k % 2 == 0) 
	{
		int half = power(n, k / 2);
		return (1ll * half * half) % mod;
	}
	else if(k % 2)
	{
		int half = power(n, k / 2);
		return (1ll * half * half % mod * n) % mod;  
	}
}

int main ()
{
	faster();
	int t = 1; 
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		cout << power(n, k) << endl;
	}
	return 0;
}