#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}
inline ll n_peculiar(ll a,ll b,ll c,ll n){
	ll l=1,r=1000000000000000000;
	while(l<r){
		ll mid = (l+r)>>1;
		ll avail = mid/a - mid/b + mid/c;
		if(avail<n){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	ll a,b,c,q;
	cin>>a>>b>>c>>q;
	ll x = a*b/gcd(a,b);
	ll y = x*c/gcd(x,c);
	while(q--){
		ll n;
		cin>>n;
		cout<<n_peculiar(a,x,y,n)<<"\n";
	}
}