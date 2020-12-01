#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#include <fstream>

#define int long long
using namespace std;

vector < vector< int> > solutions;
vector<int > mins, maxs;
int t, n, s, f;

signed main() {
    #pragma region input
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int i = 0; i< t; i++){
        cin >> n >> s >> f;
        vector<int > mins, maxs;
        for (int j = 0; j < n; j++){
            int m;
            cin >> m;
            mins.push_back(m);
        }
        for (int j = 0; j < n; j++){
            int m;
            cin >> m;
            maxs.push_back(m);
        }
        solutions.push_back(vector<int>(n, __LONG_LONG_MAX__));
        solutions[i][s]= 0;
        int minaccessed = s;
        int maxaccessed = s;
        vector<int> queue;
        vector<vector<int> > con (maxs.size());
        queue.push_back(s);
        int maxacc, minacc;
        while(!queue.empty()){
            int c = queue.front();
            int minimum = mins.at(c);
            int maximum = maxs.at(c);
            int cur = solutions[i][c];
            for (int j = minimum; j <= maximum && (c-j >= 0 || c + j < n); j++){
                if(c+j < n){
                    if(solutions[i][c+j] > cur+1){
                        solutions[i][c+j] = cur + 1;
                        queue.push_back(c+j);
                        if(c+j == f) { queue.clear(); goto OUTPUT;} 
                    }
                }
                if(c-j >= 0){
                    if(solutions[i][c-j] > cur+1){
                        solutions[i][c-j] = cur + 1;
                        queue.push_back(c-j);                   
                        if(c-j == f) { queue.clear(); goto OUTPUT;}  
                    }
                }
            }
            queue.erase(queue.begin());
        }
        OUTPUT:cout << "Case #" << i << ": "<< (solutions[i][f]==__LONG_LONG_MAX__? -1: solutions[i][f]) << "\n";
    }
    #pragma endregion input
}
