#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
ll min(ll a,ll b,ll c){
	if(a<=b && a<=c)
		return a;
	if(b<=a && b<=c)
		return b;
	return c;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	ll tc;
	cin>>tc;
	while(tc--){
		ll n,k;
		cin>>n>>k;
		vector< pair<ll,ll> >a;
		a.push_back(make_pair(0,0));
		for(ll i=1;i<=k;i++){
			ll x;
			cin>>x;
			if(x>=0){
				a.push_back(make_pair(i,x));
			}
		}
		//vector< vector< vector<ll> > >dp(a.size()+2,vector< vector<ll> >(k+2,vector<ll>(n+2)));
		ll dp[a.size()+2][k+2][n+2];
		for(ll i=0;i<=k+1;i++){
			for(ll j=0;j<=n+2;j++){
				dp[0][i][j]=10000000000;
			}
		}
		for(ll i=0;i<=a.size()+1;i++){
			for(ll j=0;j<=k+1;j++){
				dp[i][j][0]=10000000000;
			}
		}
		for(ll i=0;i<=a.size()+1;i++){
			for(ll j=0;j<=n+1;j++){
				dp[i][0][j]=10000000000;
			}
		}
		for(ll i=0;i<=a.size()+1;i++){
			for(ll j=1;j<=n+1;j++){
				dp[i][1][j]=0;
			}
		}
		for(ll i=1;i<=a.size()-1;i++){
			for(ll j=1;j<=k+1;j++){
				for(ll z=1;z<=n+1;z++){
					if(j-a[i].first>=0)
						dp[i][j][z]=min(a[i].second+dp[i][j-a[i].first][z-1],a[i].second+dp[i-1][j-a[i].first][z-1],dp[i-1][j][z]);
					else
						dp[i][j][z]=dp[i-1][j][z];
				}
			}
		}
		ll y = dp[a.size()-1][k+1][n+1];
		if(y>=10000000000)
			cout<<"-1\n";
		else
			cout<<y<<"\n";
	}
}