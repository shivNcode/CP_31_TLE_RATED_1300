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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    vector<ll> val , idx;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(i+1>arr[i]){
            val.push_back(arr[i]);
            idx.push_back(i+1);
        }
    }
    sort(val.begin() , val.end());
    sort(idx.begin() , idx.end());
    ll i = -1 , v = 0;
    ll ans = 0;
    while(v<val.size()){
        while(i+1<idx.size() && idx[i+1]<val[v]){
            i++;
        }
        //cout<<v<<" "<<idx[i+1]<<" "<<i+1<<endl;
        ans+=(i+1);
        v++;
    }
    cout<<ans<<endl;
    //cout<<"NEW"<<endl;
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


