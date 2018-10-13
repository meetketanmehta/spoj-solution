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
	vector<ll>dp(1000001,0);
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(ll i=3;i<1000001;i++){
		if(dp[i-1]==i-1)
			dp[i]=2;
		else
			dp[i]=dp[i-1]+2;
	}
	while(1){
		ll n;
		scanf("%llu",&n);
		if(n==0)
			return 0;
		printf("%llu\n",dp[n]);
	}
	return 0;
}