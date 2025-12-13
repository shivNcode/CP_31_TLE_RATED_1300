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
    int n;
    cin>>n;
    vector<int> arr(n+1);
    vector<int> x(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int prev = -1;
    for(int i=1;i<=n;i++){
        if(i==1) x[i] = -1;
        else{
            if(arr[i]!=arr[i-1]) x[i] = i-1;
            else x[i] = x[i-1];
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<x[i]<<" ";
    // }
    //cout<<endl;
    int q;
    cin>>q;
    vector<int> qrr(q);
    int l , r;
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        if(l<=x[r]) cout<<x[r]<<" "<<r<<endl;
        else cout<<-1<<" "<<-1<<endl;
    }
    cout<<endl;
    return;
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


