#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define SPEED ios_base::sync_with_stdio(0);cin.tie(0);
int main(){
    SPEED
    ll tc;
    cin>>tc;
    while(tc--){
        ll n,c;
        cin>>n>>c;
        vector <ll> arr(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        ll lo=0, hi=arr[n-1]-arr[0]+1;
        while(hi-lo>1){
            ll mid = (lo+hi)/2;
            ll cows_placed = 0;
            cows_placed++;
            ll last_placed = arr[0];
            bool possible = false;
            for(ll i=1;i<n;i++){
                if(arr[i]-last_placed>=mid){
                    cows_placed++;
                    last_placed = arr[i];
                    if(cows_placed==c){
                        possible = true;
                    }
                }
            }
            if(possible){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
        cout<<lo<<"\n";
    }
    return 0;
}

