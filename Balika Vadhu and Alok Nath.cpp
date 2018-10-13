#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
ll max(ll a,ll b,ll c,ll d){
	if(a>=b && a>=c && a>=d)
		return a;
	if(b>=a && b>=c && b>=d)
		return b;
	if(c>=a && c>=b && c>=d)
		return c;
	return d;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	ll tc;
	cin>>tc;
	while(tc--){
		string a,b;
		ll k;
		cin>>a>>b>>k;
		string x="0";
		x+=a;
		string y="0";
		y+=b;
		vector< vector< vector<ll> > >dp(a.size()+1,vector< vector<ll> >(b.size()+1,vector<ll>(k+1,0)));
		for(ll i=0;i<=b.size();i++){
			for(ll j=1;j<=k;j++){
				dp[0][i][j]=LONG_MIN;
			}
		}
		for(ll i=0;i<=a.size();i++){
			for(ll j=1;j<=k;j++){
				dp[i][0][j]=LONG_MIN;
			}
		}
		for(ll i=1;i<=a.size();i++){
			for(ll j=1;j<=b.size();j++){
				for(ll z=1;z<=k;z++){
					if(x[i]==y[j])
						dp[i][j][z]=max(x[i]+dp[i-1][j-1][z-1],dp[i-1][j-1][z],dp[i-1][j][z],dp[i][j-1][z]);
					else{
						dp[i][j][z]=max(dp[i-1][j][z],dp[i][j-1][z]);
					}
				}
			}
		}
		if(dp[a.size()][b.size()][k]<0)
			cout<<"0\n";
		else
			cout<<dp[a.size()][b.size()][k]<<"\n";
	}
	return 0;
}