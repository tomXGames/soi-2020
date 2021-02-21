#include <soi>
#define rep(x) for(int i = 0; i <x; i++)

signed main() {
    int n = read_int();
    int x = read_int();
    vector<int> available;
    available.push_back(0);
    vector<vector<bool> > dp (n+1, vector<bool>(x+1, false));
    rep(n){
        int in = read_int();
        available.push_back(in);
        dp[i+1][0] = true;
    }
    sort(available.begin(), available.end());
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            if(j-available[i] >= 0){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-available[i]];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    if(dp[n][x]) print("YES");
    else print("NO");
}
