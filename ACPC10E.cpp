#include<iostream>
#include<vector>
using namespace std;
#define ll unsigned long long int
int main(){
	vector<ll>sq(19);
	sq[0]=1;
	for(int i=1;i<34;i++){
		sq[i]=sq[i-1]*2;
	}
	while(1){
	long long int g,a,t,d,x,y;
	cin>>g>>t>>a>>d;
	if(g==-1 && a==-1 && t==-1 && d==-1)
		return 0;
	x=0;y=0;
	x+=g*t*(t-1)/2;
	
	ll total=0;
	ll m = g*a+d;
	ll i = 0;
	for(i=0;i<34;i++){
		if(sq[i]<m)
			x+=sq[i];
		if(sq[i]>=m)
			break;
	}
	y = sq[i]-m;
	cout<<g<<"*"<<a<<"/"<<t<<"+"<<d<<"="<<x<<"+"<<y<<endl;
	}
	return 0;
}