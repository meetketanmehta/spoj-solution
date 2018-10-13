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
int main(){
	speed;
	ll n;
	cin>>n;
	vector<ll>a(n);
	vector<ll>b(n);
	vector<ll>c(n);
	vector<ll>d(n);
	for(ll i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	vector<ll>right;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			right.pb((-1)*(c[i]+d[j]));
		}
	}
	sort(right.beg,right.end);
	ll total=0;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			ll x = a[i]+b[j];
			if(binary_search(right.beg,right.end,x))
				total+= upper_bound(right.beg,right.end,x) - lower_bound(right.beg,right.end,x);
		}
	}
	cout<<total<<endl;
	return 0;
}