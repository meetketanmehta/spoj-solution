#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long int
vector< vector<ll> >pp(14);
ll prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
void allsub(ll p[],ll n,vector< vector<ll> >& pp,ll mul,ll s){
	if(n<0){
		if(mul!=1)
			pp[s].push_back(mul);
		return;
	}
	allsub(p,n-1,pp,mul,s);
	allsub(p,n-1,pp,mul*p[n],s+1);
}
ll mangu(ll n){
	ll prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
	ll l=2;
	ll r=304250263527210;
	while(l<r){
		ll mid = (l+r)>>1;
		ll avail=0;
		for(ll i=1;i<=13;i++){
			for(ll j=0;j<pp[i].size();j++){
				if(mid/pp[i][j]==0)
					break;
				else{
					if(i%2==0)
						avail-=mid/pp[i][j];
					else
						avail+=mid/pp[i][j];
				}
			}
		}
		if(n>avail)
			l=mid+1;
		else
			r=mid;
	}
	return l;
}
int main(){
	ios::sync_with_stdio(false);
	allsub(prime,12,pp,1,0);
	for(ll i=1;i<=13;i++)
		sort(pp[i].begin(),pp[i].end());
	ll tc;
	cin>>tc;
	while(tc--){
		ll n;
		cin>>n;
		cout<<mangu(n)<<"\n";
	}
	return 0;
}