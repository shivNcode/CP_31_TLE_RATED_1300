#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
using namespace std;

#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    // write solution here
    int n;
    cin>>n;
    vector<int> a(n) , b(n);
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mpp[a[i]] = i+1;
    }
    int sum = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        if((mpp[b[i]]-(i+1))>0){
            cnt++;
        }
        else if((mpp[b[i]]-(i+1))==0 && sum>0){
            cnt++;
        }
        sum+=((mpp[b[i]]-(i+1)));
    }
    cout<<cnt<<endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


        Solve();
    return 0;
}


/*
Notes:

*/

