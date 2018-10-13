#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,q;
	cin>>n;
	vector<ll>a(n);
	for(ll i=0;i<n;i++)
		cin>>a[i];
	ll blk_size = sqrt(n);
	vector<ll>sa(n/blk_size+1);
	sa[0]=a[0];
	ll min = a[0];
	ll j =0;
	for(ll i=1;i<n;i++){
		if(i%blk_size==0){
			sa[j]=min;
			j++;
			min=a[i];
		}
		else{
			if(min>a[i])
				min=a[i];
		}
	}
	sa[j]=min;
	cin>>q;
	while(q--){
		ll l,r;
		cin>>l>>r;
		ll min=a[l];
		for(;l<=r && l%blk_size!=0;l++){
			if(min>a[l])
				min=a[l];
		}
		ll i = l/blk_size;
		for(;l+blk_size<=r+1 && l<n;l+=blk_size){
			if(min>sa[i])
				min=sa[i];
			i++;
		}
		for(;l<=r && l<n;l++){
			if(min>a[l])
				min=a[l];
		}
		cout<<min<<"\n";
	}
	return 0;
}