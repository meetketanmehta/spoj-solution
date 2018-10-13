#include<iostream>
#include<vector>
using namespace std;
int main(){
	int tc;
	scanf("%i",&tc);
	while(tc--){
		int m,k;
		scanf("%i%i",&m,&k);
		vector< pair<int,int> >a;
		a.push_back(make_pair(0,0));
		for(int i=1;i<=k;i++){
			int t;
			scanf("%i",&t);
			if(t!=-1){
				a.push_back(make_pair(i,t));
			}
		}
		int n = a.size()-1;
		vector< vector<int> >dp(n+1,vector<int>(k+1,0));
		vector< vector<int> >s(n+1,vector<int>(k+1,0));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(j-a[i].first>0){
					if(dp[i-1][j-a[i].first] && dp[i-1][j]){
						int x = dp[i-1][j-a[i].first] + a[i].second;
						int y = dp[i-1][j];
						if(x<y && s[i-1][j-a[i].first]+1<=m){
							dp[i][j]=dp[i-1][j-a[i].first]+a[i].second;
							s[i][j]=s[i-1][j-a[i].first]+1;
						}
						else{
							dp[i][j]=dp[i-1][j];
							s[i][j]=s[i-1][j];
						}
					}
					if(dp[i-1][j]){
						dp[i][j]=dp[i-1][j];
						s[i][j]=s[i-1][j];
					}
					if(dp[i-1][j-a[i].first]){
						if(s[i-1][j-a[i].first]+1<=m){
							dp[i][j]=dp[i-1][j-a[i].first]+a[i].second;
							s[i][j]=s[i-1][j-a[i].first]+1;
						}
					}
				}
				else{
					if(j==a[i].first){
						if(dp[i-1][j]){
							int x = dp[i-1][j-a[i].first] + a[i].second;
							int y = dp[i-1][j];
							if(x<y && s[i-1][j-a[i].first]+1<=m){
								dp[i][j]=dp[i-1][j-a[i].first]+a[i].second;
								s[i][j]=s[i-1][j-a[i].first]+1;
							}
							else{
								dp[i][j]=dp[i-1][j];
								s[i][j]=s[i-1][j];
							}
						}
						else{
							if(s[i-1][j-a[i].first]+1<=m){
								dp[i][j]=dp[i-1][j-a[i].first]+a[i].second;
								s[i][j]=s[i-1][j-a[i].first]+1;
							}
						}
					}
					else{
						dp[i][j]=dp[i-1][j];
						s[i][j]=s[i-1][j];
					}
				}
			}
		}
		if(s[n][k]){
			cout<<dp[n][k]<<endl;
		}
		else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}