#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll sumofdig(ll n){
	ll sum = 0;
	while(n){
		sum+= n%10;
		n/=10;
	}
	return sum;
}
ll proofdig(ll n){
	ll pro = 1;
	while(n){
		pro*= n%10;
		n/=10;
	}
	return pro;
}
int main(){
	ll n;
	cin>>n;
	ll ans = 0;
	for(ll i=0;i<=1000000;i++){
		if(sumofdig(i)==proofdig(i) && sumofdig(i)==n){
			cout<<i<<" ";
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}