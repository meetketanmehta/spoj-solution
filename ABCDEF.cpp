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
	scanf("%llu",&n);
	vector<ll>s(n);
	for(ll i=0;i<n;i++)
		scanf("%llu",&s[i]);
	vector<ll>right;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			for(ll k=0;k<n;k++){
				if(s[k]){
					right.pb((s[i]+s[j])*s[k]);
				}
			}
		}
	}
	sort(right.beg,right.end);
	ll total = 0;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			for(ll k=0;k<n;k++){
				ll x = s[i]*s[j]+s[k];
				if(binary_search(right.beg,right.end,x))
					total+= upper_bound(right.beg,right.end,x) -  lower_bound(right.beg,right.end,x);
			}
		}
	}
	printf("%llu\n",total);
	return 0;
}