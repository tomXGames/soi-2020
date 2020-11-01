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

signed main() {
    int t, n;
    cin >> t;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int> > right(t), left(t);
    vector<vector<int> > casesright(t), casesleft(t), indexright(t), indexleft(t);
    for (int i = 0; i< t; i++){
        int n;
        cin >> n;
        for (int j = 0; j < n; j++){
            int h;
            cin >> h;
            right[i].push_back(h);
        }
        for (int j = 0; j < n; j++){
            int h;
            cin >> h;
            left[i].push_back(h);
        }
        int maxright = *max_element(right[i].begin(), right[i].end());
        int maxrightindex = distance(right[i].begin(), max_element(right[i].begin(), right[i].end()));
        int maxleft = *max_element(left[i].begin(), left[i].end());
        int maxleftindex = distance(left[i].begin(), max_element(left[i].begin(), left[i].end()));
        for (int j = 0; j < n; j++){
            if(right[i][j] >= maxright - abs(maxrightindex - j)) {
                casesright[i].push_back(right[i][j]);
                indexright[i].push_back(j);
            }
            if(left[i][j] >= maxleft- abs(maxleftindex - j)) {
                casesleft[i].push_back(left[i][j]);
                indexleft[i].push_back(j);
            }        
        }
    }
    for (int t = 0; t < right.size(); t ++){
        int curmax = 0;
        for(int i = 0; i < casesright[t].size(); i++){
            for (int j = 0; j < casesleft[t].size(); j++){
                int next = casesright[t][i] + casesleft[t][j] + abs(indexright[t][i] - indexleft[t][j]);
                curmax = (next > curmax) ? next : curmax;
            }
        }
        cout << "Case #" << t << " : " << curmax << "\n";
    }
}