#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<stack>
using namespace std;
inline void update(vector<int>& st,int s,int e,int c,int i,int n){
	if(i>=s && i<=e){
		st[c]+=n;
		if(s==e)
			return;
		int mid = s+ (e-s)/2;
		if(i>=mid+1 && i<=e)
			update(st,mid+1,e,2*c+1,i,n);
		if(i>=s && i<=e)
			update(st,s,mid,2*c,i,n);
	}
}
long long int get_sum(vector<int>st,int s,int e,int c,int ss,int se){
	if(s>=ss && e<=se)
		return st[c];
	if(ss>e || se<s)
		return 0;
	int mid = s+(e-s)/2;
	return get_sum(st,s,mid,2*c,ss,se) + get_sum(st,mid+1,e,2*c+1,ss,se);
}
int main(){
	ios::sync_with_stdio(true);
	int m;
	scanf("%i",&m);
	vector<int>st(4*m+1,0);
	int q;
	scanf("%i",&q);
	while(q--){
		string t;
		int x,y;
		cin>>t;
		scanf("%i%i",&x,&y);
		if(t=="add"){
			int i = x-1;
			int n = y;
			stack<int>c;
			stack<int>s;
			stack<int>e;
			c.push(1);
			s.push(0);
			e.push(m-1);
			while(c.size()!=0){
				int cu = c.top();
				c.pop();
				int sta = s.top();
				s.pop();
				int en = e.top();
				e.pop();
				if(i>=sta && i<=en){
					st[cu]+=n;
					if(sta!=en){
						int mid = sta+ (en-sta)/2;
						if(i>=mid+1 && i<=en){
							c.push(2*cu+1);
							s.push(mid+1);
							e.push(en);
						}
						if(i>=sta && i<=mid){
							c.push(2*cu);
							s.push(sta);
							e.push(mid);
						}
					}
				}
			}
			//update(st,0,n-1,1,x-1,y);
		}
		else{
			long long int total = 0;
			int ss = x-1;
			int se = y-1;
			stack<int>c;
			stack<int>s;
			stack<int>e;
			c.push(1);
			s.push(0);
			e.push(m-1);
			while(s.size()!=0){
				int sta = s.top();
				s.pop();
				int cu = c.top();
				c.pop();
				int en = e.top();
				e.pop();
				if(sta>=ss && en<=se)
					total += st[cu];
				else {
					if(ss>en || se<sta){
						total += 0;
					}
					else{
						int mid = sta+(en-sta)/2;
						c.push(2*cu);
						s.push(sta);
						e.push(mid);
						c.push(2*cu+1);
						s.push(mid+1);
						e.push(en);
					}
				}
			}
			printf("%llu\n",total);
			//printf("%llu\n",get_sum(st,0,n-1,1,x-1,y-1));
		}
	}
}