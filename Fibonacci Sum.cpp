#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int
#define MOD 1000000007
vector<ll>p(63);
struct matrix{
	ll a,b,c,d;
};
matrix products[63];
matrix mult(matrix m1,matrix m2){
	matrix ans;
	ans.a = m1.a*m2.a+m1.b*m2.c;
	ans.a = ans.a%MOD;
	ans.b = m1.a*m2.b+m1.b*m2.d;
	ans.b = ans.b%MOD;
	ans.c = m1.c*m2.a+m1.d*m2.c;
	ans.c = ans.c%MOD;
	ans.d = m1.c*m2.b+m1.d*m2.d;
	ans.d = ans.d%MOD;
	return ans;
}
ll fibo(ll n){
	if(n==0 || n==1)
		return n;
	if(n<0)
		return 0;
	matrix ans;
	n--;
	ans.a=1;ans.b=0;ans.c=0;ans.d=1;
	while(n!=0){
		ll i = lower_bound(p.begin(),p.end(),n) - p.begin();
		if(p[i]>n)
			i--;
		n-=p[i];
		ans = mult(ans,products[i]);
	}
	return ans.a;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	p[0]=1;
	for(ll i=1;i<p.size();i++)
		p[i]=p[i-1]*2;
	products[0].a=1;
	products[0].b=1;
	products[0].c=1;
	products[0].d=0;
	for(ll i=1;i<p.size();i++){
		products[i]=mult(products[i-1],products[i-1]);
	}
	ll tc;
	//cin>>tc;
	tc=1;
	while(tc--){
		ll n;
		cin>>n;
		//n = 1e18;
		n--;
		cout<<fibo(n)<<"\n";
	}
	return 0;
}