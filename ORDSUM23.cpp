#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define beg begin()
#define end end()
#define size size()
#define pb push_back
#define pop pop_back()
#define MOD 1000000007
#define PI 3.14
#define speed ios::sync_with_stdio(false)
int main(){
	speed;
	vector< ll >dp(1000001,0);
	dp[2]=1;
	dp[3]=1;
	dp[4]=1;
	dp[5]=2;
	dp[6]=2;
	for(ll i=7;i<=1000000;i++){
		dp[i] = dp[i-1] + dp[i-5];
		dp[i]=dp[i]%MOD;
	}
	ll tc;
	scanf("%llu",&tc);
	while(tc--){
		ll n;
		scanf("%llu",&n);
		cout<<dp[n]%MOD<<endl;
	}
	return 0;
}