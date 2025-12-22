#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
using namespace std;

#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    // write solution here
    int n , h;
    cin>>n>>h;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        sort(arr.begin() , arr.begin()+i +1, greater<int>());
        int sum = 0;
        //cout<<i<<" : ";
        for(int j = 0 ; j<=i; j+=2){
           // cout<<arr[j]<<" ";
            sum+=arr[j];
        }
        cout<<"\n";
        //cout<<sum<<" \n";
        if(sum>h){
            cout<<i<<endl;
            return;
        }
    }
    cout<<n<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}


/*
Notes:

*/

