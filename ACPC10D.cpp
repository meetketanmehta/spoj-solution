#include<iostream>
#include<vector>
using namespace std;
long long int min(long long int a,long long int b,long long int c,long long int d){
	if(a<=b && a<=c && a<=d)
		return a;
	if(b<=a && b<=c && b<=d)
		return b;
	if(c<=a && c<=b && c<=d)
		return c;
	return d;
}
long long int min(long long int a,long long int b,long long int c){
	if(a<=b && a<=c)
		return a;
	if(b<=a && b<=c)
		return b;
	return c;
}
int main(){
	int i = 1;
	while(1){
		int n;
		cin>>n;
		if(n==0)
			return 0;
		vector< vector<int> > a(n,vector<int>(3));
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		vector< vector<long long int> >dp(n,vector<long long int>(3,0));
		dp[0][0]=10000000;
		dp[0][1]=a[0][1];
		dp[0][2]=dp[0][1]+a[0][2];
		for(int i=1;i<n;i++){
			for(int j=0;j<3;j++){
				if(j==0){
					dp[i][j]=min(dp[i-1][j]+a[i][j],dp[i-1][j+1]+a[i][j]);
				}
				if(j==1)
					dp[i][j]=min(dp[i][j-1]+a[i][j],dp[i-1][j-1]+a[i][j],dp[i-1][j]+a[i][j],dp[i-1][j+1]+a[i][j]);
				if(j==2)
					dp[i][j]=min(dp[i][j-1]+a[i][j],dp[i-1][j-1]+a[i][j],dp[i-1][j]+a[i][j]);
			}
		}
		cout<<i++<<". "<<dp[n-1][1]<<endl;
	}
	return 0;
}