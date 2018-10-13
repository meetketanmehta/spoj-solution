#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define beg begin()
#define end end()
#define size size()
#define pb push_back
#define pop pop_back()
#define MOD 1000000007
#define PI 3.14
#define speed ios::sync_with_stdio(false)
inline bool dot(string s){
	for(ll i=0;i<s.size;i++){
		if(s[i]<'0' || s[i]>'9')
			return 1;
	}
	return 0;
}
inline int tonum(string s){
	int n=0;
	for(ll i=0;i<s.size;i++){
		n = n*10 + s[i] - '0';
	}
	return n;
}
int main(){
	speed;
	ll tc;
	cin>>tc;
	while(tc--){
		string a,b,c;
		char x,y;
		cin>>a>>x>>b>>y>>c;
		int n,m,t;
		if(dot(a)){
			m = tonum(b);
			t = tonum(c);
			n = t-m;
		}
		if(dot(b)){
			n = tonum(a);
			t = tonum(c);
			m = t-n;
		}
		if(dot(c)){
			n = tonum(a);
			m = tonum(b);
			t = n+m;
		}
		cout<<n<<" + "<<m<<" = "<<t<<endl;
	}
	return 0;
}