#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define ll long long int
int main(){
	string a;
	cin>>a;
	while(a[0]!='0'){
		vector<ll>dp(a.size()+1,1);
		for(ll i=2;i<=a.size();i++){
			if(a[i-1]=='0'){
				if(a[i-2]<='2' && a[i-2]>'0')
					dp[i]=dp[i-2];
				else{
					dp[a.size()]=0;
					break;
				}
			}	
			else{
				if(((a[i-2]-'0')*10 + a[i-1]-'0')<=26 && a[i-2]!='0')
					dp[i]=dp[i-1]+dp[i-2];
				else
					dp[i]=dp[i-1];
			}
		}
		cout<<dp[a.size()]<<endl;
		cin>>a;
	}
	return 0;
}