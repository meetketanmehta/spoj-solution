#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define ull long long int
#define beg begin()
#define end end()
#define size size()
#define pb push_back
#define pop pop_back()
#define MOD 1000000007
#define PI 3.14
#define speed ios::sync_with_stdio(false)
void update(vector<bool>&p){
	p[0]=0;
	p[1]=0;
	for(ull i=2;i<=1000000;i++){
		if(p[i]){
			for(ull j=2*i;j<=1000000;j+=i)
				p[j]=0;
		}
	}
}
void afraid(vector<bool>p,vector<bool>&a){
	for(ull i=2;i<=1000000;i++){
		if(p[i]){
			ull n = i;
			bool ans = 1;
			int d = 0;
			while(n/10!=0){
				d++;
				if(n%10==0){
					ans = 0;
				}
				n/=10;
			}
			d++;
			if(n%10==0){
				ans = 0;
			}
			if(ans){
				if(d==1){
					a[i]=1;
					continue;
				}
				ull p = pow(10,d);
				n = i % p;
				if(a[n])
					a[i]=1;
			}
		}	
	}
}
int main(){
	speed;
	ull tc;
	vector<bool>p(1000001,1);
	vector<bool>a(1000001,0);
	vector<ull>arr(1000001,0);
	update(p);
	afraid(p,a);
	scanf("%llu",&tc);
	ull i = 2;
	for(;i<=1000000;i++){
		if(a[i]){
			arr[i] = arr[i-1] + 1;
		}
		else{
			arr[i]=arr[i-1];
		}
	}
	while(tc--){
		ull n;
		scanf("%llu",&n);
		printf("%llu\n",arr[n]);
	}
	return 0;
}