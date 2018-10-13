#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define beg begin()
#define end end()
#define size size()
#define pb push_back
#define pop pop_back()
#define MOD 1000000007
#define PI 3.14
#define speed ios::sync_with_stdio(false)
int main(){
	speed;
	while(1){
		ll a,b,c;
		cin>>a>>b>>c;
		if(a==0 && b==0 && c==0)
			return 0;
		if(a==0 || b==0 || c==0){
			cout<<"AP "<<c+c-b<<endl;
			continue;
		}
		if(b-a == c-b){
			cout<<"AP "<<c+c-b<<endl;
			continue;
		}
		if(b/a == c/b){
			cout<<"GP "<<c*c/b<<endl;
		}
	}
	return 0;
}