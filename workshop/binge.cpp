#include <iostream>
#include <vector>
#include<algorithm>

#define int long long
using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<pair<int, int> > s(n);
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        s[i].second = a;
        s[i].first = b;
    }
    sort(s.rbegin(), s.rend());

    int lastend =s[0].first, lastbegin = s[0].second, count = 0;
    for (int i = 0; i < s.size(); i++){
        if (lastend > s[i].first) count++;
        if(lastend == s[i].first) if(lastbegin < s[i].second) lastbegin = s[i].second;
    }
    cout << count << endl;
}