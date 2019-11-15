# Daily Coding Problem: Problem #150 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by LinkedIn.

Given a list of points, a central point, and an integer k, find the nearest k points from the central point.

For example, given the list of points [(0, 0), (5, 4), (3, 1)], the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

void kNearestPoints(vector<P>v, int x, int y, int k){
    vector<pair<double, int>>dist;
    for(int i = 0; i < v.size(); i++){
        double tmp = sqrt(pow(abs(x - v[i].first), 2) + pow(abs(y - v[i].second), 2));
        dist.push_back({tmp, i});
    }
    sort(dist.begin(), dist.end());
    for(int i = 0; i < k; i++){
        int ind = dist[i].second;
        cout<<v[ind].first<<" "<<v[ind].second<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k, x, y;
        cin>>n>>k;
        vector<P>points;
        for(int i = 0; i < n; i++){
            cin>>x>>y;
            points.push_back({x,y});
        }
        cin>>x>>y;
        kNearestPoints(points, x, y, k);
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/4FIsVF03LD)**