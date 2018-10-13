#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
ll dumb(vector<ll>a,ll r,ll l,ll i,vector< vector< vector<ll> > >&dp){
	if(l==r){
		if(i==2)
			return a[l];
		else
			return 0;
	}
	if(dp[l][r][i]==-1){
		if(i==2){
			dp[l][r][i] = max(a[l]+dumb(a,r,l+1,1,dp),a[r]+dumb(a,r-1,l,1,dp));
		}
		else{
			dp[l][r][i] = max(dumb(a,r,l+1,2,dp),dumb(a,r-1,l,2,dp));
		}
	}
	return dp[l][r][i];
}	
ll smart(vector<ll>a,ll r,ll l,ll i,vector< vector< vector<ll> > >&dp){
	if(l==r){
		if(i==2)
			return a[l];
		return 0;
	}
	if(dp[l][r][i]==-1){
		if(i==2){
			dp[l][r][i] = max(a[l]+smart(a,r,l+1,1,dp),a[r]+smart(a,r-1,l,1,dp));
		}
		else{
			dp[l][r][i] = min(smart(a,r,l+1,2,dp),smart(a,r-1,l,2,dp));
		}
	}
	return dp[l][r][i];
}
int main(){
	ll tc;
	cin>>tc;
	while(tc--){
		ll n;
		cin>>n;
		vector<ll>a(n);
		for(ll i=0;i<n;i++)
			cin>>a[i];
		vector< vector< vector<ll> > >dp1(n+1,vector< vector<ll> >(n+1,vector<ll>(3,-1)));
		vector< vector< vector<ll> > >dp2(n+1,vector< vector<ll> >(n+1,vector<ll>(3,-1)));
		cout<<dumb(a,n-1,0,2,dp1)<<" "<<smart(a,n-1,0,2,dp2)<<"\n";
	}
}