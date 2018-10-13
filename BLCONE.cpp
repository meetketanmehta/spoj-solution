#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		double rad,hei;
		cin>>rad>>hei;
		double l =1,r=hei;
		double right = 2*sqrt(pow(rad,2)+pow(hei,2));
		double m = (l+r)/2;
		while(l<r){
			m = (l+r)/2.00000000;
			double left = ((rad*pow(m,3))/(pow(hei,2)*3))+(pow(m,2)*sqrt(pow(rad,2)+pow(hei,2))/pow(hei,2));
			if(left==right)
				break;
			if(left<right)
				l = m+0.0000000001;
			if(left>right)
				r = m-0.0000000001;
		}
		cout<<fixed;
		cout<<setprecision(6)<<m<<endl;
	}
}