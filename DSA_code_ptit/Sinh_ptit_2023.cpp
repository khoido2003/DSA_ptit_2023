#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define sz size()
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);


///////////////////////////////////////////////////////////////////////

// DSA06046 - CHÊNH LỆCH NHỎ NHẤT

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        for (int i = 1; i < n; ++i)
            ans = min(ans, a[i] - a[i - 1]);
        cout << ans << endl;
    }
    return 0;
}


//////////////////////////////////////////////////////////////////////

// 	DSA06043	ĐIỂM CÂN BẰNG

int main()
{
    int t = 1, n, k, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n], f[n], sum = 0;
        cin >> a[0];
        f[0] = a[0];
        sum += a[0];
        for(int i = 1; i < n; ++i)
        {
            cin >> a[i];
            f[i] = f[i - 1] + a[i];
            sum += a[i];
        }
        bool check = 1;
        for(int i = 1; i < n; ++i)
        {
            if(f[i] - a[i] == sum - f[i])
            {
                cout << i + 1 << endl;
                check = 0;
                break;
            }
        }
        if(check) cout << -1 << endl;
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////

//  DSA06039 - SỐ ĐẦU TIÊN BỊ LẶP

string calc(int *a, int n, unordered_map<int, int> &m)
{
    for(int i = 0; i < n; ++i) if(m[a[i]] > 1) return to_string(a[i]);
    return "NO";
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    int n, a[100005];
    while(t--)
    {
        cin >> n;
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            ++m[a[i]];
        }
        cout << calc(a, n, m) << endl;
    }
    return 0;
}


///////////////////////////////////////////////////////////////////////////

// DSA06036 - BỘ BA SỐ BẰNG K

string calc(vector<int>& a, int& k)
{
    int n = a.size();
    int l, r;
    for (int i = 0; i < n; ++i)
    {
        l = i + 1;
        r = n - 1;
        while (l < r)
        {
            if (a[i] + a[l] + a[r] == k)
                return "YES";
            if (a[i] + a[l] + a[r] < k)
                ++l;
            else
                --r;
        }
    }
    return "NO";
}

int main()
{    
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int& i : a)
            cin >> i;
        sort(a.begin(), a.end());
        cout << calc(a, k) << endl;
    }
    return 0;
}

//////////////////////////////////////////////////////

// DSA06044 - SẮP XẾP CHẴN LẺ


int main() {

  int n;
  cin >> n;
  int a[n];
  vector < int > v1, v2;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i % 2 == 0) v1.push_back(a[i]);
    else v2.push_back(a[i]);
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end(), greater < int > ());

  int t1 = 0, t2 = 0;

  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      cout << v1[t1] << " ";
      t1++;
    } else {
      cout << v2[t2] << " ";
      t2++;
    }
  }
  return 0;
}
/////////////////////////////////////////////////////////////////

// DSA06040 - GIAO CỦA BA DÃY SỐ

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
		if(found == false) cout << "-1";
		cout << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////////

//DSA01018 - TẬP CON LIỀN KỀ PHÍA TRƯỚC

vector<int> a(1005);

int main() {

    int t = 1, n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
        }
        
        int tmp = k;
        while (a[tmp - 1] + 1 == a[tmp] and tmp) {
            --tmp;
        }

        if (tmp) {
            --a[tmp];
            for (int i = tmp + 1; i <= k; i++) {
                a[i] = n - k + i;
            }
            for (int i = 1; i <= k; i++) {
                cout << a[i] << ' ';
            }
        } 
        else {
            for (int i = n - k + 1; i <= n; i++) {
                cout << i << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}




/////////////////////////////////////////////////////////////////////////////////

//	DSA01016	PHÂN TÍCH SỐ 1

int n, x[1001];
int cnt;
bool final = false;

void init () {
	cnt = 1;
	x[1] = n;
}

void sinh() {
   int i = cnt;
   while(i >= 1 and x[i] == 1) {
       --i;
   }
   if(i == 0) {
       final = true;
   }
   else {
       x[i]--;
       int d = cnt - i + 1;
       cnt = i;
       int q = d / x[i], r = d % x[i];
       for(int j = 1; j <= q; j++) {
           x[i + j] = x[i];
       }
       cnt += q;
       if(r > 0) {
           x[cnt + 1] = r;
           ++cnt; 
       }
   }
}

int main () {
	int t; 
	cin >> t;
	while (t--) {
		memset(x, 0, sizeof(x));
		final = false;
		cin >> n;
		init();
		while (!final) {
			cout << "(";
			for (int i = 1; i <= cnt; ++i){
				cout << x[i] ;
				if(i < cnt) cout << " ";
			}
			cout << ") ";
			sinh();
		}
		cout << endl;
	}
	return 0;
}

////////////////////////////////////////////////////////////////

//DSA01015	TÌM BỘI SỐ

int n, ok = 1;
string s;

void ktao() {
	s = string(n, '0');
}

void sinh() {
	int i = s.size() - 1;
	while( i >= 0 and s[i] == '9'){
		s[i] = '0';
		--i;
	}
	if(i == -1) ok = 0;
	else s[i] = '9';
}

int main () {
	n = 18;
	ktao();
	vector<ll> v;
	while (ok) {
		v.pb (stoll(s));
		sinh();
	}

	int t; cin >> t;
	while (t--){
		int m; cin >> m;
		for (auto it : v) {
			if (it % m == 0 and it != 0) {
				cout << it << endl;
				break;
			}
		}
	}
	return 0;
}

/////////////////////////////////////////////////////////////////

//	DSA01017	MÃ GRAY 3

string binaryToGray(string binary) {
    string gray = "";
    gray += binary[0];
    
    for (int i = 1; i < binary.length(); i++) {
        // XOR operation
        if (binary[i] != binary[i - 1]) {
            gray += "1";
        } else {
            gray += "0";
        }
    }
    
    return gray;
}

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        
        string binary;
        cin >> binary;
        
        string gray = binaryToGray(binary);
        cout << gray << endl;
    }
    
    return 0;
}


////////////////////////////////////////////////////////////////////

//	DSA01013	MÃ GRAY 2

string grayToBinary(string gray) {
    string binary = "";
    binary += gray[0];
    
    for (int i = 1; i < gray.length(); i++) {
        if (gray[i] == '0')
            binary += binary[i - 1];
        else
  
        	if(binary[i - 1] == '0') binary += '1';
        	else binary += '0';
    }
    
    return binary;
}

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        
        string gray;
        cin >> gray;
        
        string binary = grayToBinary(gray);
        cout << binary << endl;
    }
    
    return 0;
}



//////////////////////////////////////////////////////////////////////////////

// 	DSA01012 - MÃ GRAY 1

// Hàm sinh các mã Gray
vector<string> generateGrayCodes(int n) {
    // Nếu n = 1, trả về mã Gray cơ bản
    if (n == 1) {
        vector<string> grayCodes = { "0", "1" };
        return grayCodes;
    }

    // Sinh mã Gray của n-1 bits
    vector<string> prevGrayCodes = generateGrayCodes(n - 1);

    // Xâu mã Gray của n bits sẽ được tạo từ n-1 bits bằng cách:
    // - Thêm '0' vào đầu mỗi xâu trong n-1 bits
    // - Thêm '1' vào đầu mỗi xâu trong n-1 bits (theo thứ tự ngược)
    vector<string> grayCodes;
    for (int i = 0; i < prevGrayCodes.sz; i++) {
        grayCodes.pb("0" + prevGrayCodes[i]);
    }
    for (int i = prevGrayCodes.sz - 1; i >= 0; i--) {
        grayCodes.pb("1" + prevGrayCodes[i]);
    }

    return grayCodes;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;

        vector<string> grayCodes = generateGrayCodes(n);

        // In ra các mã Gray
        for (string code : grayCodes) {
            cout << code << " ";
        }
        cout << endl;
    }
    return 0;
}


//////////////////////////////////////////////////////////////////////

//	DSA01011	HOÁN VỊ TIẾP THEO CỦA CHUỖI SỐ

int main (){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<char> v;
		string s ; cin >> s;
		for (int i = 0; i < s.sz; ++i) v.pb(s[i]);

		if(next_permutation(v.begin(), v.end())){
			cout << n << " ";
			for (auto it : v) cout << it ;
				cout << endl;
		} else {
			cout << n << " " << "BIGGEST" << endl;

		}
	}
}



/////////////////////////////////////////////////////////////////

// DSA01009	XÂU AB ĐẶC BIỆT

int  n, k, ok = 1 ;
int a[1001];
string s;

void ktao(){
	s = string(n, 'B');
}

void sinh(){
	int i = n - 1;
	while(i >= 0 and s[i] == 'A'){
		s[i] = 'B';
		i--;
	}
	if(i == -1) ok = 0;
	else s[i] = 'A';
}

bool check (){
	int dem = 0, res = 0;
	for (int i = 0; i < n; ++i){
		if(s[i] == 'A') ++dem;
		else dem = 0;
		if(dem > k) return false;
		if(dem == k) ++res;
	}
	return res == 1;
}

bool cmp(vector<string> a, vector<string> b){
	return a > b;
}

int main()
{
	cin >> n >> k;
	ktao();
	int dem = 0;
	vector<string> v;
	while(ok){
		if(check()){
			v.pb(s);	
			++dem;
		}
		sinh();
	}
	cout << dem << endl;
	sort(v.begin(), v.end());
	for (auto it : v) cout << it << endl;
   	return 0;
}


//////////////////////////////////////////////////////////

//CTDL_004 - DÃY CON TĂNG DẦN BẬC K

int n, k, a[1001];
long long ans = 0;
int cnt  = 0;

void Try(int i){
	for (int j = i + 1; j <= n; ++j){
		if(a[j] > a[i] ) {
			++cnt;
			if(cnt == k) ++ans;
			Try(j);
			--cnt;
		}
	}
}

int main (){
	cin >> n >> k;
	for (int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	Try(0);
	cout << ans;
	return 0;
}



////////////////////////////////////////////////////

//DSA01028 - LIỆT KÊ TỔ HỢP

int n, k;
vector<int> v;
int a[1001];

void inkq() {
    for (int i = 1; i <= k; ++i) {
        cout << v[a[i] - 1] << " ";
    }
    cout << endl;
}

void Try(int i) {
    for (int j = a[i - 1] + 1; j <= n - k + i; ++j) {
        a[i] = j;
        if (i == k) {
            inkq();
        } else {
            Try(i + 1);
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end()); // remove duplicates
    n = v.size();
    Try(1);
    return 0;
}


///////////////////////////////////////////////////////////////////////////

//	DSA01027	HOÁN VỊ DÃY SỐ

int main (){
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());

	do{
		for (int it : a) cout << it << ' ';
		cout << endl;
	} while (next_permutation(a.begin(), a.end()));

	return 0;
}

//////////////////////////////////////////////////////////////////////////////

//	DSA01026	PHÁT LỘC

int n, a[1000001], ok;

void ktao(){
	for (int i = 1; i <= n; ++i) a[i] = 6;
}

void sinh(){
	int i = n;
	while (i >= 1 and a[i] == 8){
		a[i] = 6;
		--i;
	}
	if(i == 0) ok = 0;
	else a[i] = 8;
}

void display(){
	for (int i = 1; i <= n; ++i) cout << a[i];
	cout << endl;
}

bool check(){

	if (n < 6) return false;
	if(a[1] == 6 or a[n] == 8) return false;
	for (int i = 1; i < n; ++i) {
		if(a[i] == 8 and a[i + 1] == 8) return false;
	}
	for (int i = 1; i <= n - 3; ++i) {
		if(a[i] == 6 and a[i + 1] == 6 and a[i + 2] == 6 and a[i + 3] == 6) return false;
	}
	return true;
}

int main (){
	int t; t = 1;
	//cin >> t;
	while (t--){
		cin >> n;

		ktao(); ok = 1;
		while (ok){
			if(check()){
				display();
			}
			sinh();
		}
	}
	return 0;
}


/////////////////////////////////////////////////////////////////////////

//	DSA01025	ĐẶT TÊN - 2

int n, k, a[10000001], ok;

void ktao(){
	for (int i = 1; i <= k; ++i) a[i] = i;
}

void sinh(){
	int i = k;
	while (i >= 1 and a[i] == n - k + i){
		--i;
	}
	if(i == 0) ok = 0;
	else {
		a[i]++;
		for (int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
	}
}

void display(){
	for (int i = 1; i <= k; ++i){
		cout << (char)(a[i] + 'A' - 1);
	}
	cout << endl;
}


int main (){
	int t; t = 1;
	cin >> t;
	while (t--){
		cin >> n >> k;
		ktao();
		ok = 1;
		while (ok) {
			display();
			sinh();
		}
	}
	return 0;
}



////////////////////////////////////////////////////////////////////

//	DSA01023	SỐ THỨ TỰ TỔ HỢP

int n, k, ok;
vector<int> a, b;

void ktao(){
	for (int i = 0; i < k; ++i) a[i] = i + 1;
}

void sinh(){
	int i = k - 1;
	while (i >= 0 and a[i] == n - k + i + 1){
		--i;
	}
	if(i == -1) ok = 0;
	else {
		a[i]++;
		for (int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
	}
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--){
		cin >> n >> k;
		a.resize(k);
		b.resize(k);
		ok = 1;
		ktao();
		for (int i = 0; i < k; ++i) cin >> b[i]; 
		int cnt = 0;
		while (ok){
			++cnt;
			if(a == b) {
				cout << cnt << endl;
				break;
			} 
			sinh();
		}
	}
	return 0;
}





/////////////////////////////////////////////////////////////////////

//	DSA01022	SỐ THỨ TỰ HOÁN VỊ

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i){
			a[i] = i + 1;
			cin >> b[i];
		}
		int dem = 1;
		if(a == b) cout << 1 << endl;
		else {
			while ( a != b ){
				++dem;
				next_permutation(a.begin(), a.end());
			}
			cout << dem << endl;
		}
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////

//	DSA01021	TỔ HỢP TIẾP THEO

int n, k, ok, a[10000001];

void sinh(){
	int i = k;
	while (i >= 1 and a[i] == n - k + i){
		a[i] = 0;
		--i;
	}
	if(i == 0) ok = 0;
	else {
		a[i]++;
		for (int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
	}
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--){

		set<int> se;
		cin >> n >> k;
		for (int i = 1; i <= k ; ++i) {
			cin >> a[i];
			se.insert(a[i]);
		}
		int cnt = 0;
		sinh();
		for (int i = 1; i <= k; ++i){
			if(se.find(a[i]) == se.end()) ++cnt;
		}
		cout << cnt << endl;
	}
	return 0;
}


/////////////////////////////////////////////////////////////////

//	DSA01020	XÂU NHỊ PHÂN TRƯỚC

int ok;
string s;

void sinh(){
	int i = s.sz - 1;
	while (i >= 0 and s[i] == '0'){
		s[i] = '1';
		--i;
	}
	if(i == -1) ok = 0;
	else s[i] = '0';
}

int main (){

	int t; t = 1;
	cin >> t;
	while (t--){
		cin >> s;
		sinh();
		for (int i = 0; i < s.sz; ++i) cout << s[i];
		cout << endl;
	}
	return 0;
}


//////////////////////////////////////////////////////////////

//	DSA01019	HAHAHA

int n, ok, a[10000001];
string s;

void ktao(){
	for (int i = 0; i < n; ++i) s[i] = 'A'; 
}

void sinh(){
	int i = n - 1;
	while (i >= 0 and s[i] == 'H'){
		s[i] = 'A';
		--i;
	}
	if (i == -1) ok = 0;
	else s[i] = 'H';
}

bool check(){
	if(s[0] != 'H' or s[n - 1] != 'A') return false;
	for (int i = 0; i <= n - 2; ++i) {
		if(s[i] == 'H' and s[i + 1] == 'H') return false;
	}
	return true;
}

void display(){
	 if(check()){
		for (int i = 0; i < n; ++i) cout << s[i];
		cout << endl;
	}
}

int main (){
	int t; t = 1;
	cin >> t;
	while (t--){
		
		cin >> n;
		ktao();
		ok = 1;
		while (ok){
			display();
			sinh();
		}
	}
	return 0;
}

///////////////////////////////////////////////////////////

//	DSA01008	XÂU NHỊ PHÂN CÓ K BIT 1

int n, k, ok, a[10000001];

void ktao(){
	for (int i = 1; i <= n; ++i) a[i] = 0;
}

void sinh(){
	int i = n;
	while (i >= 1 and a[i] == 1){
		a[i] = 0;
		i--;
	}
	if(i == 0) ok = 0;
	else a[i] = 1; 
}

void display(){
	int cnt = 0;
	for (int  i = 1; i <= n; ++i){
		if(a[i] == 1) ++cnt;
	}

	if(cnt == k) {
		for (int i = 1; i <= n; ++i) cout << a[i];
		cout << endl;
	}
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n >> k;
		ktao();
		ok = 1;
		while (ok){
			display();
			sinh();
		}
	}
	return 0;
}



////////////////////////////////////////////////////////////

//DSA01007	XÂU AB CÓ ĐỘ DÀI N

int n, a[10000001], ok;

void ktao() {
	for (int i = 1; i <= n; ++i) a[i] = 0;
}

void sinh(){
	int i = n;
	while (i >= 1 and a[i] == 1) {
		a[i] = 0;
		i--;
	}
	if(i == 0) ok = 0;
	else a[i] = 1;
}

void display(){
	for (int i = 1; i <= n; ++i){
		if( a[i] == 0) cout << "A";
		else cout << "B";
	}
	cout << " ";
}

int main (){
	int t; cin >> t;
	while (t--){
		cin >> n;
		ktao();
		ok = 1;

		while (ok){
			display();
			sinh();
		}
		cout << endl;

	}
	return 0;
}

///////////////////////////////////////////////////////////

//		DSA01006	HOÁN VỊ NGƯỢC

int main (){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> v(n);
		int j = 0;
		for (int i = n - 1; i >= 0; i--) {
			v[j] = i + 1;
			j++;
		}
		do{
			for(int it : v) cout << it;
			cout << " ";
		} 
		while (prev_permutation(v.begin(), v.end()));
		cout << endl;
	}
	return 0;
}



///////////////////////////////////////////////////////////

//	DSA01005	SINH HOÁN VỊ

int main (){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) v[i] = i + 1;
		do{
			for(int it : v) cout << it;
			cout << " ";
		} 
		while (next_permutation(v.begin(), v.end()));
		cout << endl;
	}
	return 0;
}


//////////////////////////////////////////////////////////////

//	DSA01004	SINH TỔ HỢP

int n, k, a[10000001], ok;

void ktao()
{
	for (int i = 1; i <= k; ++i) a[i] = i;
}

void sinh()
{
	int i = k;
	while (i >= 1 and a[i] == n - k + i){
		--i;
	}
	if(i == 0) ok = 0;
	else {
		a[i]++;
		for (int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
	}
}

void display()
{
	for (int i = 1; i <= k; ++i){
		cout << a[i] ;
	}
	cout << ' ';
}

int main ()
{
	int t; t = 1;
	cin >> t;
	while (t--){
		ok = 1;
		cin >> n >> k;
		memset(a, 0, sizeof(a));
		ktao();
		while (ok) {
			display();
			sinh();
		}
		cout << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////////////

//	DSA01003	HOÁN VỊ KẾ TIẾP

int main ()
{
	faster();
	int t; t = 1;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		bool found = next_permutation(v.begin(), v.end());

		int flag = 1;
		if(found) {
			for (int i = 0; i < n; ++i) cout << v[i] << ' ';
			cout << endl;
			flag = 0;
		}
		if(flag == 1) {
			for (int i = 1; i <= n; ++i) cout << i << ' ';
			cout << endl;
		}
	}
	return 0;
}



/////////////////////////////////////////////////////////////

//	DSA01002	TẬP CON KẾ TIẾP

int n, k, a[1000001], ok;

bool check()
{ 
	for (int i = 1; i <= k;++i){
		if(a[i] != n - k + i) return false;
	}
	return true;
}

void sinh()
{
	int i = k;
	while (i >= 1 and a[i] == n - k + i){
		--i;
	}
	if (i == 0) ok = 0;
	else {
		a[i]++;
		for (int j = i + 1; j <= k; ++j) a[j] = a[j - 1] + 1;
	}
}

int main ()
{
	faster();
	int t; t = 1;
	cin >> t;
	while (t--){

		cin >> n >> k;
		for (int i = 1; i <= k; ++i) cin >> a[i];

		if(check()) {
			for (int i = 1; i <= k; ++i) cout << i << ' ';
			cout << endl;
		}
		else {
			sinh();
			for (int i = 1; i <= k; ++i) cout << a[i] << ' ';
			cout << endl;
		}
	}
	return 0;
}



////////////////////////////////////////////////////////////////////

//	DSA01001	XÂU NHỊ PHÂN KẾ TIẾP

string s;

bool check(){
	for (int i = 0; i < s.sz; ++i){
		if (s[i] == '0') return false; 
	}
	return true;
}

void sinh(){

	int i = s.sz - 1;
	while (i >= 0 and s[i] == '1'){
		s[i] = '0';
		--i;
	}
	s[i] = '1';
}

int main (){

	faster();
	int t; cin >> t;
	while (t--){
		cin >> s;
		if (check()) {
			for (int i = 0; i < s.sz; ++i) cout << 0;
			cout << endl;
		}
		else {
			sinh();
			for (int i = 0; i < s.sz; ++i) cout << s[i];
			cout << endl;
		}
	}
	return 0;
}


//////////////////////////////////////////////////////////////////

//	CTDL_002 - Tổng dãy con = K

int n, k, a[1000001], x[1000001], ok, cnt;

void sinh(){

	int i = n;
	while (i >= 1 and x[i] == 1){
		x[i] = 0;
		i--;
	}
	if(i == 0) ok = 0;
	else x[i] = 1;
}

void display(){

	int sum = 0;
	for (int i = 1; i <= n; ++i){
		sum += a[i] * x[i];
	}
	if(sum == k) {

		++cnt;
		for (int i = 1; i <= n; ++i) {
			if(x[i] != 0) cout << a[i] << ' ';
		}
		cout << endl;
	}
}

int main (){

	faster();
	cin >> n >> k;
	ok = 1;
	cnt = 0;
	memset(x, 0, sizeof(x));

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}


	while (ok) {
		display();
		sinh();
	}
	cout << cnt << endl;
	return 0;
}



////////////////////////////////////////////////////////////

  // CTDL_001	THUẬT TOÁN SINH

int n, a[10000001], ok;


void ktao(){
	for (int i = 0; i < n; ++i) a[i] = 0;
}

void sinh(){
	int i = n - 1;
	while (i >= 0 and a[i] == 1) {
		a[i] = 0;
		--i;
	}
	if(i == -1) ok = 0;
	else a[i] = 1;

}

bool check(){
	int l = 0, r = n - 1;
	while (l <= r){
		if(a[l] != a[r]) return false;
		++l; --r;
	}
	return true;
}

int main (){

	faster();
	int t; t = 1;
	while (t--){
		ok = 1;
		cin >> n;
		ktao();
		while (ok){
			if(check()) {
				for (int i = 0; i < n; ++i) cout << a[i] << " ";
				cout << endl;
			}
			sinh();
		}

	}
	return 0;
}