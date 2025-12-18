/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <unordered_map>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long


void solve() {
    ll n , w;
    cin>>n>>w;
    vector<ll> arr(n);
    unordered_map<ll,ll> mpp;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        mpp[arr[i]]++;
    }
    // for(auto it:mpp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    ll h =0 ;
    int a = 0;
    while(true){
        //cout<<"1";
        cout<<h<<" :";
        bool comp = true;
        ll val = w;
        for(auto it: mpp){
            while(val>=it.first && mpp[it.first]!=0){
                val-=it.first;
                mpp[it.first]--;
                cout<<it.first<<" ";
                comp = false;
            }
            if(val==0) break;
        }
        cout<<endl;a++;
        if(comp) break;
        h++;
    }
    cout<<h<<endl;
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



*/

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


