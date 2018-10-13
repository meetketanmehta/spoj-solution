#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
#define MOD 1000000007
#define ll long long int
vector<bool>p(50001,1);
vector<int>prime;
void get_primes(){
	for(int i=2;i<=50000;i++){
		if(p[i]){
			prime.push_back(i);
			for(int j=2*i;j<=50000;j+=i){
				p[j]=0;
			}
		}
	}
}
void get_answer(vector< vector<ll> >& d){
	for(int i=0;i<prime.size();i++){
		for(int j=1;pow(prime[i],j)<=50000;j++){
			ll x = pow(prime[i],j);
			for(int z = x;z<=50000;z+=x){
				d[i][z]=j;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	p[0]=0;
	p[1]=0;
	get_primes();
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		ll ans = 1;
		for(ll i=0;i<prime.size();i++){
			ll a=1;
			ll j=1;
			while(n/pow(prime[i],j)!=0){
				a++;
				j++;
			}
			ans*=a;
			if(ans>=MOD)
				ans=ans%MOD;
		}
		cout<<ans<<"\n";
	}
	return 0;
}