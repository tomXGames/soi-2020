#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <numeric>
#include <iostream>
#include <fstream>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<vector<int> > stairs (n);
    vector<vector<pair<int, string > > >  sol;
    for(int i = 0; i < n; i++){
        sol.push_back(vector<pair<int, string > >(i+3));
        stairs[i].push_back(0);
        for(int j = 0; j< i+1; j++){
            int in;
            cin >> in;
            stairs[i].push_back(in);
        }
        stairs[i].push_back(0);
    }
    sol[0][1] = make_pair(stairs[0][1],"");
    for(int j = 1; j < n; j++){
        for(int i = 1; i < (sol[j].size()-1); i++){
            if(sol[j-1][i-1].first > sol[j-1][i].first){
                sol[j][i] = make_pair(sol[j-1][i-1].first + stairs[j][i], sol[j-1][i-1].second + "R");
            }
            else{
                sol[j][i] = make_pair(sol[j-1][i].first + stairs[j][i], sol[j-1][i].second + "L");
            } // calculate the maximum way to this point by looking at the two above and choosing the bigger one
        }
        sol[j-1].clear();   //delete the rows we don't need (i don't think that's how I should do it, but ok)
        sol[j-1].shrink_to_fit();
    }
    pair<int, string > solution = *max_element(sol[n-1].begin(), sol[n-1].end());
    cout << solution.first << endl;
    cout << solution.second << endl;
}