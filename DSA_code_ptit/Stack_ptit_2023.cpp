#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define sz size()

//DSA07017 - PHẦN TỬ BÊN PHẢI NHỎ HƠN

int main (){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n];
        int res[n];
        for(int &i : a) cin >> i;
        res[n - 1] = -1;
        stack<int> st;
        st.push(n - 1);
        for(int i = n - 2; i >= 0; --i)
        {
            if(st.sz and a[i] < a[st.top()])
            {
                res[i] = st.top();
                st.push(i);
            }
            else
            {
                while(st.sz and a[i] >= a[st.top()]) st.pop();
                if(st.sz) res[i] = st.top();
                else res[i] = -1;
                st.push(i);
            }
        }

        stack<int> st2;
        int ans[n];
        ans[n - 1] = -1;
        st2.push(n - 1);
        for(int i = n - 2; i >= 0; --i)
        {
            if(st2.sz and a[i] > a[st2.top()])
            {
                ans[i] = st2.top();
                st2.push(i);
            }
            else
            {
                while(st2.sz and a[i] <= a[st2.top()]) st2.pop();
                if(st2.sz) ans[i] = st2.top();
                else ans[i] = -1;
                st2.push(i);
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(res[i] != -1 and ans[res[i]] != -1) cout << a[ans[res[i]]] << ' ';
            else cout << -1 << ' ';
        }
        cout << endl;
    }
        
    return 0;
}



///////////////////////////////////////////////////

//DSA07016 - BIỂU THỨC TĂNG GIẢM

int main()
{
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        string ans = "";
        stack<int> st;
        for(int i = 0; i <= s.sz; ++i)
        {
            st.push(i + 1);
            if (i == s.sz or s[i] == 'I')
            {
                while(!st.empty())
                {
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

////////////////////////////////////////////////////

//DSA07012 - BIẾN ĐỔI HẬU TỐ - TRUNG TỐ

int main (){

    int t; cin >> t;
    while (t--){
        string s, tmp; cin >> s;
        stack<string> st;

        for (char &i : s){
            if(isalpha(i)) st.push(string(1, i));
            else{
                tmp = st.top();
                st.pop();
                tmp = st.top() + i + tmp;
                st.pop();
                tmp = '(' + tmp + ')';
                st.push(tmp);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}


//////////////////////////////////////////////////


//DSA07011 - BIẾN ĐỔI HẬU TỐ - TIỀN TỐ

int main (){

    int t; cin >> t;
    while (t--){
        string s, tmp; cin >> s;
        stack<string> st;

        for (char &i : s){
            if(isalpha(i)) st.push(string(1, i));
            else{
                tmp = st.top();
                st.pop();
                tmp = st.top() + tmp;
                st.pop();
                tmp = i + tmp;
                st.push(tmp);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}

////////////////////////////////////////////////////

//DSA07008 - BIẾN ĐỔI TRUNG TỐ - HẬU TỐ

int degree(char c)
{
    if(c == '^') return 5;
    if(c == '*' || c == '/') return 4;
    if(c == '+' || c == '-') return 3;
    return 2;
}

int main (){
    int t; cin >> t;
    while (t--){
        string s, res = "" ; 
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.sz; ++i){

            if(isalpha(s[i])) res += s[i];
            else if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')'){
                while(st.sz and st.top() != '('){
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }

            else if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/' or s[i] == '^'){
                while (st.sz and degree(st.top()) >= degree(s[i])){
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            } 
        }
        while (st.sz){
            if(st.top() != '(') res += st.top();
            st.pop();
        }
        cout << res << endl;
    }
    return 0;
}


/////////////////////////////////////////////////////


//DSA07110 - KIỂM TRA DÃY NGOẶC ĐÚNG

string calc(string &s){
    
    stack<char> st;
    for (char &i : s){
        if(i == '(' or i == '[' or i == '{') st.push(i);
        else {
            if(i == ')') {
                if(st.sz and st.top() == '(') st.pop();
                else return "NO";
            }
            else if( i == ']'){
                if(st.sz and st.top() == '[') st.pop();
                else return "NO";
            }
             else if( i == '}'){
                if(st.sz and st.top() == '{') st.pop();
                else return "NO";
            }
        }
    }
    if(st.sz) return "NO";
    return "YES";
}

int main (){
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        cout << calc(s) << endl;
    }
}


////////////////////////////////////////////////////////

//DSA07027 - PHẦN TỬ BÊN PHẢI ĐẦU TIÊN LỚN HƠN

int main (){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n], res[n];
        for (int i = 0; i < n; ++i) cin >> a[i];

        res[n - 1] = -1;
        stack<int> st;

        st.push(a[n - 1]);
        for (int i = n - 2; i >= 0; --i){

            if(st.sz and a[i] < st.top()){
                res[i] = st.top();
                st.push(a[i]);
            }

            else {
                while(st.sz and a[i] >= st.top()) st.pop();
                if(st.sz) res[i] = st.top();
                else res[i] = -1;
                st.push(a[i]);
            }
        } 

        for (int i = 0; i < n; ++i) cout << res[i] << " ";
        cout << endl;

    }
    return 0;
}

//////////////////////////////////////////////////////

//DSA07023 - ĐẢO TỪ.cpp

int main()
{
    int t = 1;
    string s;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        getline(cin, s);
        stringstream ss(s);
        stack<string> st;
        while(ss >> s) st.push(s);
        while(st.sz)
        {
            cout << st.top() << ' ';
            st.pop();
        }
        cout << endl;
    }
    return 0;
}


///////////////////////////////////////////////////////

//DSA07021 - DÃY NGOẶC ĐÚNG DÀI NHẤT

int main()
{
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        stack<int> st;
        st.push(-1);
        int res = -1;
        for(int i = 0; i < s.sz; ++i)
        {
            if(s[i] == '(') st.push(i);
            else
            {
                st.pop();
                if(st.empty()) st.push(i);
                else res = max(res, i - st.top());
            }
        }
        cout << res << endl;
    }
    return 0;
}

////////////////////////////////////////////////////////////


DSA07014 - TÍNH GIÁ TRỊ BIỂU THỨC TIỀN TỐ

void solve(string s){

	reverse(s.begin(), s.end());
	stack<int> st;
	for (int i = 0; i < s.sz; ++i){
		if(isdigit(s[i])) st.push(s[i] - '0');
		else {
			int oop1 = st.top(); st.pop();
			int oop2 = st.top(); st.pop();

			if(s[i] == '+') st.push(oop1 + oop2);
			if(s[i] == '-') st.push(oop1 - oop2);
			if(s[i] == '*') st.push(oop1 * oop2);
			if(s[i] == '/') st.push(oop1 / oop2);

		}
	}
	cout << st.top() << endl;
}

int main()
{
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		solve(s);
	}
	return 0;
}


/////////////////////////////////////////////////////

//DSA07013 - TÍNH GIÁ TRỊ BIỂU THỨC HẬU TỐ

void solve(string s){
	stack<int> st;
	for (int i = 0; i < s.sz; ++i){
		if(isdigit(s[i])) st.push(s[i] - '0');
		else {
			int oop1 = st.top(); st.pop();
			int oop2 = st.top(); st.pop();

			if(s[i] == '+') st.push(oop2 + oop1);
			if(s[i] == '-') st.push(oop2 - oop1);
			if(s[i] == '*') st.push(oop2 * oop1);
			if(s[i] == '/') st.push(oop2 / oop1);

		}
	}
	cout << st.top() << endl;
}

int main()
{
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		solve(s);
	}
	return 0;
}


////////////////////////////////////////////////////

//DSA07010 - BIẾN ĐỐI TIỀN TỐ - HẬU TỐ

int main (){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;

		stack<string> st;
		for (int i = s.sz - 1; i >= 0; --i){

			if(isalpha(s[i])) st.push(string(1, s[i]));

			else {
				string oper1 = st.top(); st.pop();
				string oper2 = st.top(); st.pop();

				string tmp = oper1 + oper2 + s[i];
				st.push(tmp);
			}
		}
		cout << st.top() << endl;
	}
}


///////////////////////////////////////////////

//DSA07009 - BIẾN ĐỔI TIỀN TỐ - TRUNG TỐ.cpp

void solve (string s){
	stack <string> st;
	for (int i = s.sz - 1; i >= 0; --i){
		if(isalpha(s[i])) st.push(string(1, s[i]));
		else {
			string opp1 = st.top(); st.pop();
			string opp2 = st.top(); st.pop();

			string tmp = "(" + opp1 + s[i] + opp2 + ")";
			st.push(tmp);
		}
	}
	cout << st.top() << endl;
}

int main ()
{
	int t; cin >> t;
	while (t--){
		string s; cin  >> s;
		solve(s);
	}
	return 0;
}

/////////////////////////////////////////////////////

//DSA07004 - ĐẾM SỐ DẤU NGOẶC ĐỔI CHIỀU

int calc(string &s){
	stack <char> st;
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < s.sz; ++i){

		char cur = s[i];
		if( !st.empty() and cur == ')' and st.top() == '(') {
			st.pop();
		}
		else {
			st.push(cur);
		}
	}

	while (!st.empty()){

		char c = st.top(); 
		if (c == '(') ++cnt1;
		else ++cnt2;
		st.pop();

	}
	return (cnt1 / 2) + (cnt1 % 2) + (cnt2 / 2) + (cnt2 % 2);
}

int main (){
	int t; cin >> t;
	while (t--){
		string s; cin >> s;
		cout << calc(s) << endl;
	}
	return 0;
}

/////////////////////////////////////////////////////////

//DSA07003 - KIỂM TRA BIỂU THỨC SỐ

string calc (string &s){
	stack<char> st;
	bool check;
	char cur;

	for (char &i : s){
		if(i == ')'){
			cur = st.top(); st.pop();
			check = 0;

			while (cur != '(') {
				if(cur == '*' or cur == '-' or cur == '+' or cur == '/') check = 1;
				cur = st.top(); st.pop();
			}

			if(check == 0) return "Yes";
		}
		else st.push(i);
	}
	return "No";
}


int main (){
	int t; cin >> t;
	cin.ignore();
	while (t--){
		string s; getline(cin, s);
		cout << calc(s) << endl;
	}
	return 0;
}

///////////////////////////////////////////////////////

// DSA07002 -   NGĂN XẾP 2

int main()
{
 
    stack<int> st;
    int n;
    string s;
    cin >> n;
    while(cin >> s)
    {
        if(s == "PUSH")
        {
            cin >> n;
            st.push(n);
        }
        else if(s == "POP" and st.sz) st.pop();
        else if(s == "PRINT")
        {
            if(st.sz) cout << st.top() << endl;
            else cout << "NONE\n";
        }
    }
    return 0;
}



///////////////////////////////////////////////////////

// DSA07001 NGĂN XẾP 1


int main (){

    stack<int> st;
    int n; 
    string s;
    while (cin >> s){
        if(s == "pop" && st.sz) st.pop();
        else if(s == "push") {
            cin >> n;
            st.push(n);
        }
        else {

            if(st.empty()) cout << "empty" << endl;
            else {
                stack<int> tmp;
                while (st.sz){
                    
                    tmp.push(st.top());
                    st.pop();
                }

                while (tmp.sz){
                    cout << tmp.top() << " ";
                    st.push(tmp.top());
                    tmp.pop();
                }
                cout << endl;
            }
        }
    }

}
