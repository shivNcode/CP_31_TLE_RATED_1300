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
    string s;
    cin>>s;
    stack<pair<char , int>> st;
    char ch = s[0];
    int cnt = 1;
    int n = s.size();
    for(int i=1;i<n;i++){
        if(s[i]==ch){
            cnt++;
        }
        else{
            //cout<<ch<<" "<<cnt<<endl;
            st.push({ch , cnt});
            ch = s[i];
            cnt = 1;
        }
    }
    //cout<<ch<<" "<<cnt<<endl;
    st.push({ch , cnt});
    string ans = "";
    char prev = ch;
    for(int i=0;i<26;i++){
        char c = char(i+'a');
        if(prev!=c){
            prev = c;
            break;
        }
    }
   //cout<<prev<<endl;

    while(!st.empty()){
        auto it = st.top();
        //cout<<it.first<<" "<<it.second<<endl;

        for(int i=0;i<26;i++){
            char c = char(i+'a');
            if(c!=it.first && c!=st.top().first){
               prev = c;
               break;
            }
        }

        st.pop();
        if(it.second>1){
            if(it.second&1){
                for(int i=0;i<it.second;i++){
                    if(i%2==0) ans+=it.first;
                    else ans+=prev;
                }
            }
            else{
                if(ans.size()==0){
                    for(int i=0;i<it.second;i++){
                         if(i%2==0) ans+=prev;
                        else ans+=it.first;
                    }
                }
                else{
                    for(int i=0;i<it.second;i++){
                         if(i%2==0) ans+=it.first;
                        else ans+=prev;
                    }
                }
            }

        }
        else{
            ans+=it.first;
        }
        //cout<<ans<<" "<<prev<<endl;
        prev = it.first;
    }
    reverse(ans.begin() , ans.end());
    cout<<ans;

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

