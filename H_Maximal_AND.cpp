#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long


void solve() {
    ll n , k;
    cin>>n>>k;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<ll> bt(31 , 0);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<31;j++){
            if(arr[i]&1) bt[j]++;
            arr[i] = arr[i] >> 1;
        }
    }
    for(ll i = 30;i>=0;i--){
        //cout<<i<<" "<<bt[i]<<endl;
        if((bt[i] + k)>=n){
            k-=(n-bt[i]);
            bt[i] = n;
        }
    }
    ll val = 1;
    ll ans = 0;
    for(ll i = 0;i<31;i++){
        if(bt[i]==n){
            ans+=val;
        }
        val*=2;
    }
    cout<<ans<<endl;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}


