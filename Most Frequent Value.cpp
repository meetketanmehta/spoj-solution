#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long int
#define OF 100000
ll blk_size;
struct query
{
	ll i,l,r,ans;
};
bool comp1(query q1,query q2){
	if(q1.l/blk_size == q2.l/blk_size)
		return q1.r<q2.r;
	return q1.l<q2.l;
}
bool comp2(query q1,query q2){
	return q1.i<q2.i;
}
int main(){
		ll n,q;
		cin>>n;
		blk_size = sqrt(n);
		cin>>q;
		vector<ll>a(n);
		for(ll i=0;i<n;i++)
			cin>>a[i];
		vector<query>b(q);
		for(ll i=0;i<q;i++){
			ll l,r;
			cin>>l>>r;
			b[i].i=i;
			b[i].l=l;
			b[i].r=r;
		}
		sort(b.begin(),b.end(),comp1);
		vector<ll>f(200005,0);
		ll cl=b[0].l;
		ll cr=b[0].r+1;
		priority_queue< pair<ll,ll> >ans;
		for(ll i=cl;i<cr;i++){
			f[a[i]]++;
			ans.push(make_pair(f[a[i]],a[i]));
		}
		b[0].ans=(ans.top()).first;
		for(ll i=1;i<q;i++){
			while(cl<b[i].l){
				f[a[cl]]--;
				ans.push(make_pair(f[a[cl]],a[cl]));
				cl++;
			}
			while(cl>b[i].l){
				f[a[cl-1]]++;
				ans.push(make_pair(f[a[cl-1]],a[cl]));
				cl--;
			}
			while(cr<=b[i].r){
				f[a[cr]]++;
				ans.push(make_pair(f[a[cr]],a[cr]));
				cr++;
			}
			while(cr>b[i].r+1){
				f[a[cr-1]]--;
				ans.push(make_pair(f[a[cr-1]],a[cr-1]));
				cr--;
			}
			while(1){
				ll x = (ans.top()).first;
				ll y = (ans.top()).second;
				if(f[y+OF]==x){
					b[i].ans=x;
					break;
				}
				else{
					ans.pop();
				}
			}
		}
		sort(b.begin(),b.end(),comp2);
		for(ll i=0;i<q;i++){
			cout<<b[i].ans<<"\n";
		}
}