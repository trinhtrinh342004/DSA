#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

int main() {
    // Read input values
    int n, k;
    cin >> n >> k;

    set<long long> se;
    map<long long, long long> ma;
    vector<long long> ans;

    // Read input values and add them to set and map
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        se.insert(x);
        ma[x]++;
    }

    // Add k smallest distinct integers to vector
    for (long long v : se) {
        ma[v]--;
        if (ans.size() < k) ans.push_back(v);
    }

    // If there are not enough distinct integers, add the remaining ones
    if (se.size() < k)
    {
        k -= se.size();
        for (pair<long long, long long> it : ma) {
            if (k > 0) {
                while (it.second != 0) {
                    ans.push_back(it.first);
                    it.second--;
                    k--;
                    if (k == 0) break;
                }
            }
        }
    }

    // Sort and output the k smallest distinct integers
    sort(ans.begin(), ans.end());
    for (long long x : ans) cout << x << " ";
    cout << endl;

    return 0;
}