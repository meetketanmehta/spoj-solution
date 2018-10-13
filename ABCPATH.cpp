#include<iostream>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int i = 1;
	while(i){
		int h,w;
		cin>>h>>w;
		if(h==0 && w==0)
			return 0;
		vector< vector<char> >a(h+2,vector<char>(w+2,'Z'+5));
		vector< vector<long long int> >dp(h+2,vector<long long int>(w+2,-1));
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				cin>>a[i][j];
				if(a[i][j]=='A')
					dp[i][j]=1;
			}
		}
		long long int max = 0;
		for(char c = 'A';c<'Z';c=c+1){
			for(int i=1;i<=h;i++){
				for(int j=1;j<=w;j++){
					if(a[i][j]==c && dp[i][j]!=-1){
						if(a[i+1][j]==c+1)
							dp[i+1][j]=dp[i][j]+1;
						if(a[i-1][j]==c+1)
							dp[i-1][j]=dp[i][j]+1;
						if(a[i][j+1]==c+1)
							dp[i][j+1]=dp[i][j]+1;
						if(a[i][j-1]==c+1)
							dp[i][j-1]=dp[i][j]+1;
						if(a[i+1][j+1]==c+1)
							dp[i+1][j+1]=dp[i][j]+1;
						if(a[i-1][j+1]==c+1)
							dp[i-1][j+1]=dp[i][j]+1;
						if(a[i+1][j-1]==c+1)
							dp[i+1][j-1]=dp[i][j]+1;
						if(a[i-1][j-1]==c+1)
							dp[i-1][j-1]=dp[i][j]+1;
					}
				}
			}
		}
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(dp[i][j]>max)
					max = dp[i][j];
			}
		}
		cout<<"Case "<<i++<<":"<<max<<endl;
	}
	return 0;
}