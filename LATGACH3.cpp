#include<iostream>
#include<vector>
using namespace std;
#define ll long long int
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	vector<ll>ans(31,0);
	ans[0]=1;
	ans[2]=3;
	for(int i=4;i<=30;i+=2){
		ans[i]+=3*ans[i-2];
		int j=i-4;
		while(j!=0){
			ans[i]+=2*ans[j];
			j-=2;
		}
		ans[i]+=2;
	}
	while(1){
		int n;
		cin>>n;
		if(n==-1)
			return 0;
		cout<<ans[n]<<"\n";
	}
	return 0;
}