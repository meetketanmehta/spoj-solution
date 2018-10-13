#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector< pair<ll,ll> >a(n);
		for(ll i=0;i<n;i++){
			ll x,y;
			cin>>x>>y;
			a[i] = make_pair(x,y);
		}
		sort(a.begin(),a.end());
		vector<ll>sa(n);
		sa[0]=a[0].second;
		for(int i=1;i<n;i++)
			sa[i]=sa[i-1]+a[i].second;
		ll l = 0;
		ll u = upper_bound(a.begin(),a.end(),a[0]) - a.begin();
		ll ans = 0;
		while(u<n){
			ll r = a[u].first - a[u-1].first;
			ll req = sa[u-1];
			if(m>=r*req){
				m-=r*req;
				u = upper_bound(a.begin(),a.end(),a[u]) - a.begin();
			}
			else{
				ans = a[u-1].first+m/req;
				break;
			}
		}
		ll req;
		req = sa[n-1];
		if(ans==0)
			ans = a[n-1].first + m/req;
		cout<<ans<<endl;
	}
	return 0;
}