#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,q;
	cin>>n>>q;
	vector<ll>a(n);
	for(ll i=0;i<n;i++)
		cin>>a[i];
	//generation
	vector<ll>sa(n);
	sa=a;
	ll blk_size=sqrt(n);
	for(ll i=0;i<n;i+=blk_size){
		if(i+blk_size<n)
			sort(sa.begin()+i,sa.begin()+i+blk_size);
		else
			sort(sa.begin()+i,sa.end());
	}
	while(q--){
		char t;
		cin>>t;
		switch(t){
			case 'C':{
				ll p,q,x;
				ll ans = 0;
				cin>>p>>q>>x;
				p--;q--;
				for(;p<=q && p%blk_size!=0 && p<n;p++){
					if(a[p]<=x)
						ans++;
				}
				for(;p<=q && p+blk_size<n && p+blk_size<=q;p+=blk_size){
					ans += upper_bound(sa.begin()+p,sa.begin()+p+blk_size,x)-(sa.begin()+p);
				}
				for(;p<=q && p<n;p++){
					if(a[p]<=x)
						ans++;
				}
				cout<<ans<<"\n";
				break;
			}
			case 'M':{
				ll i,x;
				cin>>i>>x;
				i--;
				ll bc = i/blk_size;
				bc*= blk_size;
				ll index=0;
				if(bc+blk_size<n)
					index = lower_bound(sa.begin()+bc,sa.begin()+bc+blk_size,a[i]) - sa.begin();
				else
					index = lower_bound(sa.begin()+bc,sa.end(),a[i]) - sa.begin();
				sa[index]=x;
				if(bc+blk_size<n)
					sort(sa.begin()+bc,sa.begin()+bc+blk_size);
				else
					sort(sa.begin()+bc,sa.end());
				a[i]=x;
				break;
			}
		}
	}
	return 0;
}