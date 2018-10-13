#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
vector<ll>prime;
vector<ll>mul_prime;
vector<bool>p(10000001,1);
vector<ll>ans(10000001,0);
void get_primes(){
	for(ll i=2;i<10000001;i++){
		if(p[i]){
			prime.push_back(i);
			mul_prime.push_back(2*i);
			for(ll j=2*i;j<10000001;j+=i){
				p[j]=0;
			}
		}
	}
}
void get_answer(){
	ll p=0,q=0;
	for(ll i=2;i<10000001;i++){
		if(prime[q+1]<=i)
			q++;
		if(mul_prime[p]<=i)
			p++;
		ans[i]=q-p+1;
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	get_primes();
	get_answer();
	prime.push_back(10000000000);
	mul_prime.push_back(20000000000);
	ll tc;
	cin>>tc;
	while(tc--){
		ll n;
		cin>>n;
		cout<<ans[n]<<"\n";
	}
	return 0;
}