#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <numeric>
#include <iostream>
#include <fstream>
using namespace std;


signed main() {
    int n, sum = 0;
    cin >> n;
    vector<int> mice, hamster;
    for(int i = 0; i <n; i++){
        string type;
        cin >> type;
        if (type == "M"){
            int in;
            cin >> in;
            mice.push_back(in);
            sum += in;
        }
        else{
            int in;
            cin >> in;
            hamster.push_back(in);
        }
    }
    cout << sum;
}
