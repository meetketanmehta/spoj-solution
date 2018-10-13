#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define speed ios::sync_with_stdio(false)
int main(){
	speed;
	vector< vector<int> >dp(7001,vector<int>(7001,0));
	dp[0][0]=1;
	for(int i=0;i<=7000-1;i++){
		for(int j=0;j<=i;j++){
			dp[i+1][j]+=dp[i][j]%MOD;
			dp[i+1][j+1]+=dp[i][j]%MOD;	
			if(j){
				dp[i+1][j-1]+=dp[i][j]%MOD;
			}
		}
	}
	int tc;
	scanf("%i",&tc);
	while(tc--){
		int x,y;
		scanf("%i%i",&x,&y);
		printf("%i\n",dp[x][y]%MOD);
	}
	return 0;
}