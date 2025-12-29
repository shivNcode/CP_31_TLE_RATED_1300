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
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void fact(int n){
    vector<int> small, large;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            small.push_back(i);
            if(i != n / i)
                large.push_back(n / i);
        }
    }
    for(int x : small) cout << x << " ";
    reverse(large.begin(), large.end());
    for(int x : large) cout << x << " ";
    cout << '\n';
}

void Solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> bts(33 , 0);
    for(int i=0;i<n;i++){
        int val = arr[i];
        int j = 0;
        while(val){
            if(val&1) bts[j]++;
            j++;
            val/=2;
        }
    }
    int temp = 0;
    for(int i = 0;i<33;i++){
        //cout<<bts[i]<<" ";
        temp = gcd(temp , bts[i]);
    }

    //cout<<temp<<endl;
    if(temp==0){
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<'\n';
        return;
    }
    if(temp==1){
        cout<<1<<endl;
        return;
    }
    fact(temp);
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

