#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	while(1){
		int n;
		scanf("%i",&n);
		if(n==-1)
			return 0;
		vector< pair<int,int> >a(n+1);
		a[0]=make_pair(-1,-1);
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%i%i",&x,&y);
			a[i] = make_pair(y,x);
		}
		sort(a.begin(),a.end());
		vector<int>dp(n+1,0);
		for(int i=1;i<=n;i++){
			int j = i/2;
			int prev = i;
			int x;
			int st = a[i].second;
			while(1){
				if(a[j].first<=st && a[j+1].first>st){
					x = dp[j];
					break;
				}
				if(a[j].first>st){
					prev = j;
					j = j/2;
				}
				if(a[j].first<=st && a[j+1].first<=st){
					j = j + (prev-j)/2;
				}
			}
			dp[i]=dp[i-1]+x+1;
			if(dp[i]>=100000000)
				dp[i]-=100000000;
		}
		string s;
		for(;dp[n]/10!=0;){
			s.push_back(dp[n]%10 + '0');
			dp[n]/=10;
		}
		s.push_back(dp[n]%10+'0');
		for(;s.size()<8;)
			s.push_back('0');
		reverse(s.begin(),s.end());
		cout<<s<<endl;
	}
	return 0;
}