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
    string s;
    cin>>s;
    string t = "";
    for(int i=0;i<s.size();i++){
        if(s[i]=='o'){
            t+='o';
        }
        else if(i<s.size() && s[i+1]=='v'){
            t+='w';
        }
    }
    // int i=0;
    // while(i<t.size() && t[i]!='w'){
    //     i++;
    // }
    // int j = t.size()-1;
    // while(j>=0 && t[j]!='w'){
    //     j--;
    // }
    // char prev = t[i];
    // int cnt =0;
    // vector<int> temp;
    // while(i<=j){
    //     if(t[i]!=prev){
    //         temp.push_back(cnt);
    //         cnt = 0;
    //         prev = t[i];
    //     }
    //     cnt++;
    //     i++;
    // }
    // temp.push_back(cnt);
    int x = 0;
    vector<int> bw(t.size()) , aw(t.size());
    for(int i=0;i<t.size();i++){
        if(t[i]=='w'){
            bw[i] = ++x;
        }
        else{
            bw[i] = x;
        }
    }
    x = 0;
    for(int i=t.size()-1;i>=0;i--){
        if(t[i]=='w'){
            aw[i] = ++x;
        }
        else{
            aw[i] = x;
        }
    }


    // for(int i=0;i<t.size();i++){
    //     cout<<bw[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i=0;i<t.size();i++){
    //     cout<<aw[i]<<" ";
    // }
    cout<<endl;
    int ans = 0;
    for(int i=0;i<t.size();i++){
        if(t[i]=='o'){
            ans+=(aw[i]*bw[i]);
        }
    }
    cout<<ans<<endl;

    //cout<<t<<endl;

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

