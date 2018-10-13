#include<iostream>
using namespace std;
int min(int a,int b,int c,int d){
	if(a<=b && a<=c && a<=d)
		return a;
	if(b<=a && b<=c && b<=d)
		return b;
	if(c<=a && c<=b && c<=d)
		return c;
	return d;
}
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		int n,m,k;
		cin>>n>>m>>k;
		int mn=INT_MAX;
		for(int i=0;i<k;i++){
			int x,y;
			cin>>x>>y;
			int m = min(x-1,y-1,n-x,m-y);
			if(m<mn)
				mn=m;
		}
		if(mn<5)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}