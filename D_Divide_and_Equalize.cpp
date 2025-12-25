#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    // write solution here
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        int val = arr[i];
        for(int j=2;j*j<=val;j++){
            if(val%j==0){
                while(val%j==0){
                    //cout<<j<<" ";
                    val/=j;
                    mpp[j]++;
                }
            }
        }
        if(val>1){
           // cout<<arr[i]<<" ";
             mpp[val]++;
            }
       //cout<<"\n";
    }
    for(auto it:mpp){
        if(it.second%n!=0){
           // cout<<it.first<<" ";
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}


/*
Notes:

*/

