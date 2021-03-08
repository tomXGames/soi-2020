#include <iostream>
#include <vector>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;

signed main() {
    int n,  m;
    cin >> n >> m;
    vector<pair<int, int> > lights;
    for(int i = 0; i < m; i++){
        int in1, in2;
        cin >> in1 >> in2;
        lights.push_back(make_pair(in1, in2));
    }
    vector<int> dp (n+1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; i ++){
        cerr << i << ": ";
        for(auto[length, power]: lights){
            int minpowerinrange = dp[i-1];
            for(int k = 0; (i-k>= 0 && k <= length); k++){
                minpowerinrange = min(minpowerinrange, dp[i-k]);
            }
            dp[i] = min(minpowerinrange+ power, dp[i]);
            cerr << dp[i] << " " ;
        }
        cerr << "\n";
    }
    for(int i: dp) cerr << i << " ";
    cerr << "\n";
    cout << dp[n];
}