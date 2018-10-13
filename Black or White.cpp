#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long int
ll min(ll x,ll y,ll z){
	if(x<=y && x<=z)
		return x;
	if(y<=x && y<=z)
		return y;
	return z;
}
/*ll painted(vector<ll>a,ll n,ll b,ll w,vector< vector< vector<ll> > > & dp){
	if(n<1)
		return 0;
		ll x,y,z;
		x=LONG_MAX;y=LONG_MAX;z=LONG_MAX;
		if(a[n]>a[b])
			x=painted(a,n-1,n,w,dp);
		if(a[n]<a[w])
			y=painted(a,n-1,b,n,dp);
		z=painted(a,n-1,b,w,dp)+1;
		return min(x,y,z);
}*/
int main(){
	while(1){
		ll n;
		cin>>n;
		if(n==-1)
			return 0;
		vector<ll>a(n+1);
		a[0]=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		a.push_back(LONG_MAX);
		a.push_back(LONG_MIN);
		vector< vector< vector<ll> > > dp(n+3,vector< vector<ll> >(n+3,vector<ll>(n+3,0)));
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n+2;j++){
				for(ll k=1;k<=n+1;k++){
					ll x,y,z;
					x=LONG_MAX;y=LONG_MAX;z=LONG_MAX;
					if(a[i]>a[j])
						x=dp[i-1][i][k];
					if(a[i]<a[k])
						y=dp[i-1][j][i];
					z=dp[i-1][j][k]+1;
					dp[i][j][k] = min(x,y,z);
				}
			}
		}
		cout<<dp[n][n+2][n+1]<<"\n";
		//cout<<painted(a,n,n+2,n+1,dp)<<"\n";
	}
}