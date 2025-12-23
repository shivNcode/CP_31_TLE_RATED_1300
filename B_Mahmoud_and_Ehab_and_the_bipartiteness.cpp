// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <deque>
// #include <random>
// #include <chrono>
// #include <unordered_map>
// #include <map>
// using namespace std;

// #define int long long
// #define INF (int)1e18

// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// void Solve() {
//     // write solution here
//     int n;
//     cin>>n;
//     vector<bool> mark(n+1 , false);
//     unordered_map<int,vector<int>> mpp;
//     for(int i=0;i<n-1;i++){
//         int u , v;
//         cin>>u>>v;
//         mpp[u].push_back(v);
//     }
//     stack<int> st;
//     st.push(1);
//     while(!st.empty()){
//         auto it = st.top();
//         cout<<it<<endl;
//         st.pop();
//         for(auto itr:mpp[it]){
//             cout<<itr<<" ";
//             mark[itr] = !mark[it];
//             st.push(itr);
//         }
//         cout<<endl;
//     }
//     int cnt = 0;
//     for(int i=1;i<=n;i++){
//         if(mark[i]==0) cnt++;
//        //cout<<mark[i]<<" ";
//     }
//     int total = cnt*(n-cnt);
//     cout<<total - (n-1)<<endl;
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t = 1;
//     //cin >> t;
//     while (t--) {
//         Solve();
//     }

//     return 0;
// }


// /*
// Notes:
//     make an array of nodes and to mark two section
//     then
// */


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define int long long

void Solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);   // IMPORTANT
    }

    vector<int> color(n + 1, -1); // -1 = unvisited
    stack<int> st;

    color[1] = 0;   // start coloring from node 1
    st.push(1);

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        for (int v : adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1;
                st.push(v);
            }
        }
    }

    int cnt0 = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) cnt0++;
    }

    int cnt1 = n - cnt0;
    int total_possible = cnt0 * cnt1;
    int missing_edges = total_possible - (n - 1);

    cout << missing_edges << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();
    return 0;
}
