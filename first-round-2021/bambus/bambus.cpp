#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#include <set>

#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    vector<int > solutions(t);
    for (int i = 0; i < t; i++){
        cin >> n ;
        vector<int > cases;
        for(int j = 0; j < n; j++){
            int h;
            cin >> h;
            cases.push_back(h);
        }
        std::set<int> opened;
        int count = 0;
        int previous = n+1;
        for (int j = 0; j < cases.size(); j++){
            opened.insert(cases[j]);
            vector<int > toberemoved;
            std::set<int>::iterator it;
            int i = 0;
            for (it = opened.begin(); it != opened.end(); ++it, i++) {
                int f = *it; 
                if (f < cases[j]) {
                    toberemoved.push_back(f);
                    count++;
                }
                else break;
            }
            for(int k = 0; k < toberemoved.size(); k++){
                opened.erase(toberemoved[k]);
            }
        }
        count += opened.size();
        solutions[i] = count;
        cout << "Case #" << i << ": "<< solutions[i] << endl;
    }
}