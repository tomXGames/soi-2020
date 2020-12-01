#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <numeric>
#include <iostream>
#include <fstream>

#define int long long
using namespace std;

vector < vector< int> > solutions;
vector<int > cases;
int t, n, s, f, cur;

vector<pair<int, int> > batteryfix (vector<int> vect){
    vector<pair<int, int> > curmaxcombs;
    vector<int> ideal = vect;
    int idealpot = 0;
    sort(ideal.begin(), ideal.end());
    for(int i = 0;  i< ideal.size(); i++) idealpot += abs(ideal[i]- ideal[-1-i]);
    int curmaxpot = 0;
    for(int i = 1; i < vect.size(); i+=2){
        vector<int> newvect1, newvect2;
        vector<pair<int, int> > newpairs1, newpairs2;
        int pot = abs(vect[0] - vect[i]);

        for(int j = 1; j < i; j++) newvect1.push_back(vect[j]);
        if(newvect1.size()>=2) {
            newpairs1 = batteryfix(newvect1); 
            pot += newpairs1[0].first;
            newpairs1.erase(newpairs1.begin());
        }

        for(int j = i+1; j < vect.size(); j++) newvect2.push_back(vect[j]);
        if(newvect2.size()>=2) {
            newpairs2= batteryfix(newvect2); 
            pot +=  newpairs2[0].first; 
            newpairs2.erase(newpairs2.begin());
        } 
        if(pot > curmaxpot) {
            curmaxpot = pot;
            curmaxcombs.clear();
            curmaxcombs.push_back(make_pair(pot, 0));
            curmaxcombs.push_back(make_pair(vect[0], vect[i]));
            for(int j = 0; j < newpairs1.size(); j++) curmaxcombs.push_back(newpairs1[j]);
            for(int j = 0; j < newpairs2.size(); j++) curmaxcombs.push_back(newpairs2[j]);
            if(curmaxpot == idealpot) return curmaxcombs;
        }
    }
    return curmaxcombs;    
}

signed main() {
    #pragma region input
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int i = 0; i< t; i++){
        cur = i;
        cin >> n;
        cases = vector<int> (2*n);
        for (int j = 0; j < 2*n; j++){
            int h;
            cin >> h;
            cases[j]= h;
        }
        cout<< "Case #" << i << ": " << endl;
        vector<pair<int, int> > maxcombs = batteryfix(cases);
        maxcombs.erase(maxcombs.begin());
        for (int j = 0; j <maxcombs.size(); j++) cout << distance(cases.begin(), find(cases.begin(), cases.end(),  maxcombs[j].first)) << " " << distance(cases.begin(), find(cases.begin(), cases.end(),  maxcombs[j].second)) << endl; 
    }
    #pragma endregion input
}