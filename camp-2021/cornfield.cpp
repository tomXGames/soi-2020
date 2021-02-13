#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#include <fstream>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > field (n);
    rep(n){
        for(int j = 0; j< m; j++){
            int in;
            cin >> in;
            field[i].push_back(in);
        }
    }
    vector<vector<int> > DP (n, vector<int>(m, 0));
    DP[0][0] = field[0][0];
    for(int i = 0; i< n; i++){
        for(int j = 0; j <m; j++){
            if(i == 0 && j == 0) continue;
            int up = (i-1>=0)? DP[i-1][j]:-1;
            int left = (j-1>= 0)? DP[i][j-1]: -1;
            if(left > up){
                DP[i][j] = left + field[i][j];
                field[i][j-1] = 0;
            }
            else{
                DP[i][j] = up + field[i][j];
                field[i-1][j] = 0;
            }
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= m; j--){
            if(i == n-1 && j == m-1) continue;
            int down = (i+1>n-1)? DP[i+1][j]:0;
            int right = (j+1>m-1)? DP[i][j+1]: 0;
            if(right > down){
                DP[i][j] = right + field[i][j];
                field[i][j+1] = 0;
            }
            else{
                DP[i][j] = down + field[i][j];
                field[i+1][j] = 0;
            }
        }
    }

    cout << DP[0][0] << endl;
}
 