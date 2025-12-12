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
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(arr[0]==1){
        cout<<1<<" ";
        int l = 1 , r = 1;
        while(r<n){
            //cout<<arr[r]<<endl;
            if((r-l+1)<=arr[r]){
                cout<<r-l+1<<" ";
                r++;
            }
            else{
                cout<<r-l<<" ";
                r++;
                l++;
            }
        }
    }
    else{
        int l = 0 , r = 0;
        while(r<n){
            //cout<<arr[r]<<endl;
            if((r-l+1)<=arr[r]){
                cout<<r-l+1<<" ";
                r++;
            }
            else{
                cout<<r-l<<" ";
                r++;
                l++;
            }
        }
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


