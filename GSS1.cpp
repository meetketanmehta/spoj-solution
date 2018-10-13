#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 900005
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);
struct con{
    ll sum, allsum, prefixsum, suffixsum;
};
struct con st[N];
ll arr[N];
ll pref_sum[N];
ll left(ll n){
    return 2*n;
}
ll right(ll n){
    return 2*n + 1;
}
ll middle(ll l,ll r){
    return (l+r)/2;
}
bool in_range(int s,int e,int c){
    return c>=s && c<=e;
}
struct con max(struct con a, struct con b, struct con c){
    if(c.sum>=a.sum && c.sum>=b.sum)
        return c;
    if(a.sum>=b.sum && a.sum>=c.sum)
        return a;
    return c;
}
struct con max(struct con a, struct con b){
    if(a.sum>=b.sum)
        return a;
    return b;
}
ll max(ll a, ll b, ll c){
    ll x = max(a,b);
    return max(x,c);
}
bool operator == (struct con a, struct con b){
    return a.sum==b.sum && a.prefixsum==b.prefixsum && a.suffixsum==b.suffixsum && a.allsum==b.allsum;
}
struct con create_st(ll s, ll e, ll c){
    if(s==e){
        st[c].sum = arr[s];
        st[c].allsum = arr[s];
        st[c].prefixsum = arr[s];
        st[c].suffixsum = arr[s];
        return st[c];
    }
    ll mid = middle(s,e);
    struct con leftc = create_st(s,mid,left(c));
    struct con rightc = create_st(mid+1, e, right(c));
    st[c].prefixsum = max(leftc.allsum + rightc.prefixsum, leftc.prefixsum);
    st[c].suffixsum = max(leftc.suffixsum + rightc.allsum, rightc.suffixsum);
    st[c].allsum = leftc.allsum + rightc.allsum;
    st[c].sum = max(leftc.sum, rightc.sum, leftc.suffixsum + rightc.prefixsum);
    return st[c];
}
struct con query(ll x, ll y, ll s, ll e,ll c){
    struct con dummy;
    dummy.sum = -15008;
    dummy.prefixsum = -15008;
    dummy.suffixsum = -15008;
    dummy.allsum = -15008;
    if (x <= s && y >= e)
        return st[c];
    if (e < x || s > y)
        return dummy;
    ll mid = middle(s,e);
    struct con leftc = query(x,y,s,mid,left(c));
    struct con rightc = query(x,y,mid+1,e,right(c));
    if(leftc == dummy){
        return rightc;
    }
    if(rightc == dummy){
        return leftc;
    }
    struct con allc;
    allc.prefixsum = max(leftc.allsum + rightc.prefixsum, leftc.prefixsum);
    allc.suffixsum = max(leftc.suffixsum + rightc.allsum, rightc.suffixsum);
    allc.allsum = leftc.allsum + rightc.allsum;
    allc.sum = max(leftc.sum, rightc.sum, leftc.suffixsum + rightc.prefixsum);
    return allc;
}
void cal_prefix_sum(ll n){
    pref_sum[0] = arr[0];
    for(ll i=1;i<n;i++){
        pref_sum[i] = pref_sum[i-1] + arr[i];
    }
}
int main(){
    SPEED
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    cal_prefix_sum(n);
    create_st(0,n-1,1);
    /*for(ll i=1;i<=5;i++){
        cout<<st[i].sum<<" "<<st[i].l<<" "<<st[i].r<<"\n";
    }*/
    ll m;
    cin>>m;
    while (m--) {
        ll x,y;
        cin>>x>>y;
        struct con ans = query(x-1,y-1,0,n-1,1);
        cout<<ans.sum<<"\n";
        //cout<<ans.sum<<" "<<ans.l<<" "<<ans.r<<"\n";
    }
    return 0;
}
