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
    ll n , m;
    cin>>n>>m;
    vector<ll> arr(n) , brr(m);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    for(ll i =0;i<m;i++){
        cin>>brr[i];
    }
    sort(arr.begin() , arr.end() , greater<int>());

    ll ans = 0;
    ll ans2 = 0;
    for(ll i=0;i<n;i++){
        //cout<<i<<" "<<"for "<<arr[i]<<" "<<"\n";

        if(i<arr[i]){
            ans+=brr[i];
        }
        else{
            ans+=brr[arr[i]-1];
        }
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

/*
Notes:

*/

