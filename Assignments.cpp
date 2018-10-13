#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
/*ll assign(ll n,vector< vector<ll> >a,vector<bool>avail){
	if(n<0)
		return 1;
	ll ans=0;
	for(ll i=0;i<a.size();i++){
		if(a[i][n] && avail[i]){
			avail[i]=0;
			ans+=assign(n-1,a,avail);
			avail[i]=1;
		}
	}
	return ans;
}*/
int main(){
	ll tc;
	cin>>tc;
	while(tc--){
		ll n;
		cin>>n;
		vector< vector<ll> >a(n,vector<ll>(n));
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		vector< vector<ll> >dp(n,vector<ll>(n,0));
		for(ll i=0;i<n;i++){
			dp[i][0]=a[i][0];
		}
		for(ll i=0;i<n;i++){
			if(a[i][0]){
				for(ll j=0;j<n;j++){
					if(a[j][1] && j!=i){
						dp[j][1]+=dp[i][0];
					}
				}
			}
		}
		for(ll i=1;i<n-1;i++){
			for(ll j=0;j<n;j++){
				if(a[j][i]){
					for(ll k=0;k<n;k++){
						if(a[k][i+1] && k!=j){
							dp[k][i+1]+=dp[j][i];
							for(ll z=i-1;z>=0;z--){
								dp[k][i+1]-=dp[k][z];
							}
							if(dp[k][i+1]<0)
								dp[k][i+1]=0;
						}
					}
				}
			}
		}
		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++)
				cout<<dp[i][j]<<" ";
			cout<<"\n";
		}
		cout<<"\n";
		ll ans = 0;
		for(ll i=0;i<n;i++){
			ans+=dp[i][n-1];
		}
		cout<<ans<<"\n";
	}
}