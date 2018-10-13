#include<iostream>
using namespace std;
#define ll long long int
int main(){
	ll tc;
	cin>>tc;
	while(tc--){
		ll n,k,s;
		cin>>n>>k>>s;
		ll req = k*s;
		ll d_req = req/n;
		if(req%n)
			d_req++;
		ll d_avail=s - (s/7);
		if(d_avail>=d_req){
			cout<<d_req<<"\n";
		}
		else
			cout<<"-1\n";
	}
	return 0;
}