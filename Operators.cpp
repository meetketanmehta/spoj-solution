#include<iostream>
#include<vector>
using namespace std;
int main(){
	int d,n;
	cin>>n>>d;
	vector<int>a;
	bool ans=1;
	if(d<0){
		for(int i=n;i>=1;i--){
			if(d>0){
				d-=i;
				a.push_back(i);
			}
			else{
				d+=i;
				int j = i - 2*i;
				a.push_back(j);
			}
		}
		ans=0;
	}
	if(ans){
		for(int i=n;i>=1;i--){
			if(d>=0){
				d-=i;
				a.push_back(i);
			}
			else{
				d+=i;
				int j = i - 2*i;
				a.push_back(j);
			}
		}
	}
	if(d!=0){
		cout<<"Impossible";
		return 0;
	}
	if(a[n-1]<0){
		cout<<"Impossible";
		return 0;
	}
	cout<<a[n-1];
	for(int i=n-2;i>=0;i--){
		if(a[i]>0){
			cout<<"+"<<a[i];
		}
		else{
			cout<<a[i];
		}
	}
	return 0;
}