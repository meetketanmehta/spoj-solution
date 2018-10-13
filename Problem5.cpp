#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		int n,k;
		cin>>n>>k;
		int a[n+1];
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int dp[n+1][k+1];
		for(int i=0;i<=k;i++)
			dp[0][i]=0;
		for(int i=0;i<=n;i++)
			dp[i][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(j<=a[i]){
					if(dp[i-1][j]==0 && dp[i-1][j-a[i]]==0){
						dp[i][j]=dp[i-1][j];
						continue;
					}
					if(dp[i-1][j]==0){
						dp[i][j]=dp[i-1][j-a[i]]+1;
						continue;
					}
					dp[i][j]=min(dp[i-1][j-a[i]]+1,dp[i-1][j]);
				}
				else
					dp[i][j]=dp[i-1][j];
			}
		}
		if(dp[n][k]==0)
			cout<<"impossible\n";
		else
			cout<<dp[n][k]<<"\n";
	}
}