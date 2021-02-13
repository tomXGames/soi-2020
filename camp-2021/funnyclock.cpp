#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define int long long
using namespace std;
const int INF = 1e18;
pair<int, int> current, desired;

int bfs(){
    if(desired == current) return 0;
    vector<pair<pair<int, int>, int > > queue;
    std::vector<std::vector<int> > passed(60, std::vector<int>(60, 0));    
    queue.push_back(make_pair(current, 0));
    while (!queue.empty()){
        pair<pair<int, int>, int> cur = queue.front();
        passed[cur.first.first][cur.first.second] = 1;
        if(cur.first == desired) return cur.second;
        else{
            pair<int, int> swapped = make_pair(cur.first.second, cur.first.first);
            if(passed[swapped.first][swapped.second] == 0) queue.push_back(make_pair(swapped, cur.second+1));
            pair<int, int> increment = make_pair(cur.first.first, cur.first.second+1);
            if(increment.second >= 60) increment = make_pair(increment.first +1 , increment.second%60);
            if(increment.first >= 60) increment = make_pair(0, increment.second%60);
            if(passed[increment.first][increment.second] == 0) queue.push_back(make_pair(increment, cur.second+1));
        }
        queue.erase(queue.begin());
    }
    return -1;
}

signed main() {
    cin >> current.first >> current.second >> desired.first >> desired.second;
    cout << bfs() << endl;
}
