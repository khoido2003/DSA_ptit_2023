#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz size()
#define pb push_back
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);



//////////////////////////////////////////////////////////////////

// DSA06035 - DÃY TAM GIÁC DÀI NHẤT

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


/////////////////////////////////////////////////////////////////////////

// DSA06034 - CẶP SỐ CÓ TỔNG BẰNG K

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    map < int, int > mp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mp[x]++;
    }
    //	for(auto it : mp){
    //		cout << it.first << ' ' << it.second << endl;
    //	}
    long long dem = 0;
    for (auto it: mp) {
      int a = it.first;
      int b = k - a;
      auto it2 = mp.find(b);
      if (it2 != mp.end() && a <= ( * it2).first) {
        if (b == a) {
          dem += 1 ll * mp[b] * (mp[b] - 1) / 2;
        } else {
          dem += 1 ll * mp[a] * mp[b];
        }
      }
    }
    cout << dem << endl;
    mp.clear();
  }
  return 0;
}


/////////////////////////////////////////////////////////////////////////

// DSA06033 - KHOẢNG CÁCH XA NHẤT

int main()
{
    int t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n];
        for(int &i : a) cin >> i;
        int MAX[n], ans = -1;
        MAX[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; --i) MAX[i] = max(MAX[i + 1], a[i]);
        int i, j;
        i = j = 0;
        while(i < n and j < n)
        {
            if(MAX[j] > a[i])
            {
                ans = max(ans, j - i);
                ++j;
            }
            else ++i;
        }
        if(!ans) ans = -1;
        cout << ans << endl;
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////

//DSA06032 - BỘ BA SỐ CÓ TỔNG NHỎ HƠN K

long long dem(long long A[], long long n, long long x) {
  long long count = 0;
  for (int i = 0; i < n - 2; i++) {
    int j = i + 1, k = n - 1;
    while (j < k) {
      long long tmp = A[i] + A[j] + A[k];
      if (tmp < x) {
        count += k - j;
        j++;
      } else {
        k--;
      }
    }
  }
  return count;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long a[n];
    for (long long & x: a) cin >> x;
    sort(a, a + n);
    cout << dem(a, n, k) << endl;
  }
  return 0;
}

//////////////////////////////////////////////////////////////

//DSA06031 - PHẦN TỬ LỚN NHẤT TRONG DÃY CON

int max(int l, int r, int a[]) {
  int m = -1e9;
  for (int i = l; i <= r; i++) {
    m = max(m, a[i]);
  }
  return m;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (auto & x: a) cin >> x;

    int l = 0, r = k - 1;
    while (r < n) {
      cout << max(l, r, a) << " ";
      l++;
      r++;
    }
    cout << endl;
  }
  return 0;
}

///////////////////////////////////////////////////////////

//DSA06030 - SẮP XẾP NỔI BỌT - LIỆT KÊ NGƯỢC

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    vector < vector < int > > v;

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
      int check = 1;
      vector < int > tmp;
      for (int j = 0; j < i; ++j) {
        if (a[j] > a[j + 1]) {
          int c = a[j];
          a[j] = a[j + 1];
          a[j + 1] = c;
          check = 0;
        }
      }
      if (check) break;
      for (int i = 0; i < n; ++i) {
        tmp.push_back(a[i]);
      }
      v.push_back(tmp);
    }

    for (int i = v.size() - 1; i >= 0; i--) {
      cout << "Buoc " << i + 1 << ": ";
      for (auto it: v[i]) {
        cout << it << ' ';
      }
      cout << endl;
    }
    v.clear();
  }
  return 0;
}

/////////////////////////////////////////////////////////////

//DSA06029 - SẮP XẾP CHÈN - LIỆT KÊ NGƯỢC

int main() {
  int n;
  cin >> n;
  int a[n];
  vector < multiset < int > > v;
  multiset < int > s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s.insert(a[i]);
    v.push_back(s);
  }

  for (int i = v.size() - 1; i >= 0; i--) {
    cout << "Buoc " << i << ": ";
    for (auto it: v[i]) {
      cout << it << ' ';
    }
    cout << endl;
  }
  v.clear();
  return 0;
}

////////////////////////////////////////////////////////////////

//DSA06028 - SẮP XẾP CHỌN - LIỆT KÊ NGƯỢC

void selectionSort(int a[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    int min = i;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] < a[min]) min = j;
    }
    int x = a[i];
    a[i] = a[min];
    a[min] = x;

    cout << "Buoc " << i + 1 << ": ";
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " ";
    }
    cout << endl;

  }
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector < vector < int > > v;
  for (int i = 0; i < n - 1; ++i) {
    vector < int > tmp;
    int min = i;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] < a[min]) min = j;
    }
    int x = a[i];
    a[i] = a[min];
    a[min] = x;

    for (int i = 0; i < n; ++i) {
      tmp.push_back(a[i]);
    }
    v.push_back(tmp);
  }

  for (int i = v.size() - 1; i >= 0; i--) {
    cout << "Buoc " << i + 1 << ": ";
    for (auto it: v[i]) {
      cout << it << ' ';
    }
    cout << endl;
  }
  v.clear();
  return 0;
}

/////////////////////////////////////////////////////////////////////

//DSA06027 - SẮP XẾP ĐỔI CHỖ TRỰC TIẾP - LIỆT KÊ NGƯỢC

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector < vector < int > > v;
    for (int i = 0; i < n - 1; ++i) {
      vector < int > tmp;
      for (int j = i + 1; j < n; ++j) {
        if (a[i] > a[j]) {
          int x = a[i];
          a[i] = a[j];
          a[j] = x;
        }
      }
      for (int i = 0; i < n; i++) {
        tmp.push_back(a[i]);
      }
      v.push_back(tmp);
    }

    for (int i = v.size() - 1; i >= 0; i--) {
      cout << "Buoc " << i + 1 << ": ";
      for (auto it: v[i]) {
        cout << it << ' ';
      }
      cout << endl;
    }
    v.clear();
  }
  return 0;
}


////////////////////////////////////////////////////////////////

//DSA06026 - SẮP XẾP NỔI BỌT

int main() {
  int n;
  cin >> n;
  int a[n];
  multiset < int > s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int dem = 1;
  for (int i = n - 1; i >= 0; --i) {
    int check = 1;
    for (int j = 0; j < i; ++j) {
      if (a[j] > a[j + 1]) {
        int c = a[j];
        a[j] = a[j + 1];
        a[j + 1] = c;
        check = 0;
      }
    }
    if (check) break;
    cout << "Buoc " << dem << ": ";
    dem++;
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}


///////////////////////////////////////////////////////////

//DSA06025 - SẮP XẾP CHÈN

int main() {
  int n;
  cin >> n;
  int a[n];
  multiset < int > s;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s.insert(a[i]);
    cout << "Buoc " << i << ": ";
    for (auto it: s) {
      cout << it << " ";
    }
    cout << endl;
  }
  return 0;
}


///////////////////////////////////////////////////////////

// DSA06024 - SẮP XẾP CHỌN

void selectionSort(int a[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    int min = i;
    for (int j = i + 1; j < n; ++j) {
      if (a[j] < a[min]) min = j;
    }
    int x = a[i];
    a[i] = a[min];
    a[min] = x;

    cout << "Buoc " << i + 1 << ": ";
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " ";
    }
    cout << endl;

  }
}

int main() {
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n;
    vector < int > v;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    selectionSort(a, n);
    cout << endl;
  }
  return 0;
}


///////////////////////////////////////////////////////////////////

// DSA06023 - SẮP XẾP ĐỔI CHỖ TRỰC TIẾP

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[i] > a[j]) {
        int x = a[i];
        a[i] = a[j];
        a[j] = x;
      }
    }
    cout << "Buoc " << i + 1 << ": ";
    for (int i = 0; i < n; ++i) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
  return 0;
}


//////////////////////////////////////////////////////////////

//DSA06022 - SỐ NHỎ NHẤT VÀ NHỎ THỨ HAI

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int min1 = 1e9, min2 = 1e9;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x < min1) {
        if (x < min2) {
          min2 = min1;
        }
        min1 = x;
      } else {
        if (x < min2 && x != min1) min2 = x;
      }
    }
    if (min2 == 1e9) cout << "-1" << endl;
    else cout << min1 << ' ' << min2 << endl;
  }
}

/////////////////////////////////////////////////////////////////

// DSA06021 - TÌM KIẾM TRONG DÃY SẮP XẾP VÒNG

void binary_search(vector < pair < int, int >> a, int n, int x) {
  int l = 0, r = n - 1, res = -1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (a[m].first == x) {
      res = m;
      r = m - 1;
    } else if (a[m].first < x) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << a[res].second + 1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;

    vector < pair < int, int >> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());

    binary_search(a, n, k);
  }
  return 0;
}

//////////////////////////////////////////////////////////

// DSA06020 - TÌM KIẾM

int bs(int a[], int n, int x) {
  int l = 0, r = n - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (a[m] == x) {
      return 1;
    } else if (a[m] > x) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int & i: a) cin >> i;
    cout << bs(a, n, x) << endl;
  }
  return 0;
}

//////////////////////////////////////////////////////////////

// DSA06019 - SẮP XẾP THEO SỐ LẦN XUẤT HIỆN


bool cmp(pair < int, int > a, pair < int, int > b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second > b.second;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map < int, int > mp;
    vector < pair < int, int > > v;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mp[x]++;
    }
    for (auto it: mp) {
      v.push_back({
        it.first,
        it.second
      });
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it: v) {
      for (int i = 0; i < it.second; i++) {
        cout << it.first << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}

/////////////////////////////////////////////////////////////

// DSA06018 - BỔ SUNG PHẦN TỬ

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (auto & x: a) cin >> x;
    sort(a, a + n);
    int thieu = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] != a[i + 1]) thieu += a[i + 1] - a[i] - 1;
    }
    cout << thieu << endl;
  }
  return 0;
}

//////////////////////////////////////////////////////////

//DSA06017 - TRỘN HAI DÃY

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int tong = n + m;
    int c[tong];
    for (int & x: c) cin >> x;
    sort(c, c + tong);
    for (int x: c) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}

////////////////////////////////////////////////////////////////

//DSA06016 - TÍCH LỚN NHẤT - NHỎ NHẤT

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, max = -1e9, min = 1e9;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > max) max = x;
    }
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      if (x < min) min = x;
    }
    cout << 1 ll * max * min << endl;
  }
  return 0;
}


///////////////////////////////////////////////////////////////////

//DSA06015 - MERGE SORT

//Merger sort

void merge(int a[], int l, int m, int r) {
  vector < int > x(a + l, a + m + 1);
  vector < int > y(a + m + 1, a + r + 1);

  int i = 0, j = 0;
  while (i < x.size() && j < y.size()) {
    if (x[i] < y[j]) {
      a[l] = x[i];
      ++l;
      ++i;
    } else {
      a[l] = y[j];
      ++l;
      ++j;
    }
  }
  while (i < x.size()) {
    a[l] = x[i];
    ++l;
    ++i;
  }
  while (j < y.size()) {
    a[l] = y[j];
    ++l;
    ++j;
  }
}

void mergeSort(int a[], int l, int r) {
  if (l >= r) return;
  int m = (l + r) / 2;
  mergeSort(a, l, m);
  mergeSort(a, m + 1, r);
  merge(a, l, m, r);
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    for (int x: a) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}

//////////////////////////////////////////////////////////////////

//DSA06014 - TỔNG CẶP SỐ NGUYÊN TỐ

int prime[10000000];

void sieve() {
  for (int i = 0; i <= 10000000; ++i) {
    prime[i] = 1;
  }
  prime[0] = prime[1] = 0;
  for (int i = 2; i <= sqrt(10000000); ++i) {
    if (prime[i]) {
      for (int j = i * i; j <= 10000000; j += i) {
        prime[j] = 0;
      }
    }
  }
}

int main() {
  int t;
  cin >> t;
  sieve();
  while (t--) {
    int n;
    cin >> n;
    bool check = false;
    for (int i = 2; i <= n / 2; i++) {
      if (prime[i] && prime[n - i]) {
        cout << i << ' ' << n - i;
        check = true;
        break;
      }
    }
    if (!check) cout << "-1" << endl;
    else cout << endl;
  }
  return 0;
}


////////////////////////////////////////////////////////////////////////


//DSA06013 - SỐ LẦN XUẤT HIỆN

int d[1000001] = {
  0
};
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    memset(d, 0, sizeof(d));
    for (int & x: a) {
      cin >> x;
      d[x]++;
    }
    if (d[k]) cout << d[k] << endl;
    else cout << "-1" << endl;
  }
  return 0;
}


/////////////////////////////////////////////////////////////////////////


//DSA06012 - PHẦN TỬ LỚN NHẤT

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (auto & x: a) cin >> x;
    sort(a, a + n, greater < int > ());
    for (int i = 0; i < k; i++) {
      cout << a[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}


/////////////////////////////////////////////////////////////////

// DSA06011 - TỔNG GẦN 0 NHẤT

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int res = 1e9;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (abs(res) > abs(a[i] + a[j])) {
          res = a[i] + a[j];
        }
      }
    }
    cout << res << endl;
  }
  return 0;
}

/////////////////////////////////////////////////////////////////

// DSA06010 - SẮP XẾP CHỮ SỐ

int main() {
  int t;
  cin >> t;
  while (t--) {

    int n;
    cin >> n;
    set < char > se;
    while (n--) {
      string s;
      cin >> s;
      for (int j = 0; j < s.sz; j++) {
        se.insert(s[j]);
      }
    }
    for (auto it : se) {
      cout << it << ' ';
    }
    cout << endl;
    se.clear();
  }
  return 0;
}


/////////////////////////////////////////////////////////////

//DSA06009 - CẶP SỐ TỔNG BẰNG K

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    int d[1005] = {
      0
    };
    for (int & x: a) {
      cin >> x;
      d[x]++;
    }
    int dem = 0;
    for (int i = 0; i <= k / 2; i++) {
      int j = k - i;
      if (i != j) dem += d[i] * d[j];
      else dem += d[i] * (d[i] - 1) / 2;
    }
    cout << dem << endl;
  }
  return 0;
}


/////////////////////////////////////////////////////////////////

//DSA06008 - ĐẾM CẶP

int count(int x, int y[], int m, int DEM[]) {
  if (x == 0) return 0;
  if (x == 1) return DEM[0];

  int * idx = upper_bound(y, y + m, x);
  int ans = (y + m) - idx;
  ans += (DEM[0] + DEM[1]);

  if (x == 2) {
    ans -= (DEM[3] + DEM[4]);
  }
  if (x == 3) {
    ans += DEM[2];
  }
  return ans;
}

int tong(int x[], int y[], int n, int m) {

  int DEM[5] = {0};
  for (int i = 0; i < m; i++) {
    if (y[i] < 5) DEM[y[i]]++;
  }
  sort(y, y + n);
  int cap = 0;
  for (int i = 0; i < n; i++) {
    cap += count(x[i], y, m, DEM);
  }
  return cap;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (auto & x: a) cin >> x;
    for (auto & x: b) cin >> x;
    cout << tong(a, b, n, m) << endl;
  }
  return 0;
}


//////////////////////////////////////////////////////////////////


//DSA06007 - SẮP XẾP DÃY CON LIÊN TỤC

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
      if (b[i] != a[i]) {
        cout << i + 1 << ' ';
        break;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (b[i] != a[i]) {
        cout << i + 1 << endl;
        break;
      }
    }
  }
  return 0;
}

/////////////////////////////////////////////////////////////////

// /DSA06006 - SẮP XẾP [0 1 2]

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (auto & x: a) cin >> x;
    sort(a, a + n);
    for (auto x: a) cout << x << ' ';
    cout << endl;
  }
  return 0;
}

///////////////////////////////////////////////////////////////

//	DSA06005	HỢP VÀ GIAO CỦA HAI DÃY SỐ 2

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int & x: a) cin >> x;
    for (int & x: b) cin >> x;

    int i = 0, j = 0;
    // Hop
    while (i < n && j < m) {
      if (a[i] == b[j]) {
        cout << a[i] << ' ';
        i++;
        j++;
      } else if (a[i] < b[j]) {
        cout << a[i] << ' ';
        i++;
      } else {
        cout << b[j] << ' ';
        j++;
      }
    }
    while (i < n) {
      cout << a[i] << ' ';
      i++;
    }
    while (j < m) {
      cout << b[j] << ' ';
      j++;
    }
    cout << endl;

    //	Giao
    i = 0, j = 0;
    while (i < n && j < m) {
      if (a[i] == b[j]) {
        cout << a[i] << ' ';
        i++;
        j++;
      } else if (a[i] < b[j]) i++;
      else j++;
    }
    cout << endl;
  }
  return 0;
}


//////////////////////////////////////////////////////////////

//DSA06003 - ĐỔI CHỖ ÍT NHẤT

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int & x: a) cin >> x;

    int doi = 0;
    for (int i = 0; i < n - 1; i++) {
      int pos = i;
      for (int j = i + 1; j < n; j++) {
        if (a[j] < a[pos]) {
          pos = j;
        }
      }
      if (pos != i) ++doi;
      swap(a[i], a[pos]);
    }
    cout << doi << endl;
  }
  return 0;
}


//////////////////////////////////////////////////////////

//DSA06002 - SẮP XẾP THEO GIÁ TRỊ TUYỆT ĐỐI

int n, x;

bool cmp(int a, int b) {
  //	if(abs(a-x) == abs(b-x)) return a < b;
  return abs(a - x) < abs(b - x);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    int a[n];
    for (auto & x: a) cin >> x;
    stable_sort(a, a + n, cmp);
    for (int x: a) cout << x << ' ';
    cout << endl;
  }
  return 0;
}


/////////////////////////////////////////////////////

//DSA06001 - SẮP XẾP XEN KẼ

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (auto & x: a) cin >> x;
    sort(a, a + n);
    int l = 0, r = n - 1, index = 0;
    while (l <= r) {
      if (index % 2 == 0) {
        cout << a[r] << ' ';
        r--;
      } else {
        cout << a[l] << ' ';
        l++;
      }
      ++index;
    }
    cout << endl;
  }
  return 0;
}