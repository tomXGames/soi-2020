#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#include <map>
#include <set>
#define rep(x) for(int i = 0; i < x; i++)
using namespace std;

//NOT SOLVED YET

signed main() {
    ios_base::sync_with_stdio(false);	 
    cin.tie(0);							
    int k, n;
    cin >> k >> n;
    vector<string> prices;
    map<char, int> occurences;
    vector  <char> firsts;
    rep(n){
        string in;
        cin >> in;
        prices.push_back(in);
        for(int j = 0; j < in.size(); j++){
            occurences[in[j]] += 1;
        }
    }
    int sum = 0;
    for(int i = 0; i < n; i++){
        string price = prices[i];
        int amount = 0;
        for(int j = 0; j < price.size(); j++){
            char c = price[price.size()-1-j];
            amount += ((c -97) * pow((double)k, (double)j));
        }
        sum += amount;
    }
    cout << sum;
}
