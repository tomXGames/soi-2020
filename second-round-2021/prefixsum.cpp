#include <soi>

signed main() {
    int n = read_int();
    int m = read_int();
    int q = read_int();
    vector<vector<int> > sum (m+1, vector<int>(n+1, 0));
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int cursum = read_int();
            cursum += sum[i][j-1]+ sum[i-1][j] - sum[i-1][j-1];
            sum[i][j] = cursum;
        }
    }
    for(int i = 0; i < q; i++){
        int x_1 = read_int(), y_1 = read_int(), x_2 = read_int()+1, y_2 = read_int()+1;
        int out = sum[y_2][x_2] - sum[y_1][x_2] - sum[y_2][x_1] + sum[y_1][x_1];
        print(out);
    }
}
