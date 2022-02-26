#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<queue>
#include<iomanip>
#include<map>
#include<stack>
#include<bitset>
#include <cstring>
#include<cassert>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
void fast() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int n, k;
vector<pair<int, int>>x;
vector<int>cost;
//max operation is 15000
//because lager number (1000) it spend 12 operation.
int dp[1003][15005];
int ans(int i, int v) {
    if (i == n)return 0;
    int& ret = dp[i][v];
    if (ret != -1)return ret;
    ret = 0;
    if (x[i].second <= v) {
        ret = max(ans(i + 1, v - x[i].second) + cost[i], ret);
    }
    ret = max(ans(i + 1, v), ret);
    return ret;
}
int main() {
    fast();
    vector<int>num(1005, 1e9);
    vector<pair<int, int>>temp;
    //to know every number of operation for(1->1000).
    temp.pb({ 1,0 });
    num[1] = 0;
    for (int i = 0; i < temp.size(); i++) {
        for (int j = 1; j <= temp[i].first; j++) {
            int l = (temp[i].first / j) + temp[i].first;
            if (l > 1000)continue;
            if (num[l] == 1e9) {
                temp.pb({ l, temp[i].second + 1 });
                num[l] = temp[i].second + 1;
            }
        }
    }
    int t; cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        x = vector<pair<int, int>>(n);
        cost = vector<int>(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i].first;
            x[i].second = num[x[i].first];
        }
        for (int i = 0; i < n; i++)cin >> cost[i];
        cout << ans(0, min(k, 15004)) << '\n';
    }
}