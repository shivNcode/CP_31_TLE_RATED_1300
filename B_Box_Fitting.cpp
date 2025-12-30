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
    int n , w;
    cin>>n>>w;
    vector<int> arr(n) , temp(21 , 0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        int val = log2(arr[i]);
        temp[val]++;
    }
    int i = 0;
    int h = 0;
    while(i<n){
        int v = w;
        for(int j=20;j>=0;j--){
            while(temp[j]>0 && (1 << j)<=v){
                v-=(1<<j);
                temp[j]--;
                i++;
            }
        }
        h++;
        //i++;
    }
    cout<<h<<endl;
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
good question and important thing is to handle the all n element for this we use the hash and store thr all the the element if the array with there log value that make our work easy becase then we complete iterate all the value and sice all the value are the power of 2 so please go in our desired order
*/

