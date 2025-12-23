#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <iomanip>
using namespace std;

#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    // write solution here
    int n , k;
    cin>>n>>k;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int sum = 0;
    int v = min(n-k+1 , k);
    for(int i=1;i<=v;i++){
        //cout<<arr[i]<<" "<<i<<"\n";
        sum+=(arr[i]*i);
    }
    //cout<<"\n";
    for(int i = v+1;i<=n-v+1;i++){
        //cout<<arr[i]<<" "<<k<<"\n";
        sum+=(arr[i]*v);
    }
    //cout<<"\n";
    for(int i=n;i>=(n-v+2);i--){
        //cout<<arr[i]<<" "<<n-i+1<<"\n";
        sum+=(arr[i]*(n-i+1));
    }
    //cout<<'\n';
    //cout<<float(float (sum)/float(n-k+1))<<endl;
    cout << fixed << setprecision(10) << double (double (sum)/double (n-k+1))<<"\n";
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

