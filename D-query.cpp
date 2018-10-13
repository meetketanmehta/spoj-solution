#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long int

struct query{
	ll i,l,r,ans;
};

ll blk_size;

bool comp1(query q1,query q2){
	if(q1.l/blk_size == q2.l/blk_size){
		return q1.r<q2.r;
	}
	return q1.l/blk_size<q2.l/blk_size;
}

bool comp2(query q1,query q2){
	return q1.i<q2.i;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll n,q;
	cin>>n;
	blk_size = sqrt(n);
	vector<ll>a(n);
	for(ll i=0;i<n;i++)
		cin>>a[i];
	cin>>q;
	vector<query>b(q);
	for(ll i=0;i<q;i++){
		ll l,r;
		cin>>l>>r;
		l--;r--;
		b[i].i=i;
		b[i].l=l;
		b[i].r=r;
	}
	vector<ll>f(1000001,0);
	sort(b.begin(),b.end(),comp1);
	ll cl=b[0].l;
	ll cr=b[0].r+1;
	ll ans=0;
	for(ll i=cl;i<cr;i++){
		if(f[a[i]]==0)
			ans++;
		f[a[i]]++;
	}
	b[0].ans=ans;
	for(ll i=1;i<q;i++){
		while(cl<b[i].l){
			f[a[cl]]--;
			if(f[a[cl]]==0)
				ans--;
			cl++;
		}
		while(cl>b[i].l){
			if(f[a[cl-1]]==0)
				ans++;
			f[a[cl-1]]++;
			cl--;
		}
		while(cr<=b[i].r){
			if(f[a[cr]]==0)
				ans++;
			f[a[cr]]++;
			cr++;
		}
		while(cr>b[i].r+1){
			f[a[cr-1]]--;
			if(f[a[cr-1]]==0)
				ans--;
			cr--;
		}
		b[i].ans=ans;
	}
	sort(b.begin(),b.end(),comp2);
	for(ll i=0;i<q;i++){
		cout<<b[i].ans<<"\n";
	}
	return 0;
}