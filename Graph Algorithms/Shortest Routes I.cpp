//
// Created by Prakul Agrawal on 4/22/24.
//

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <vii> vvii;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(s) s.begin(), s.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define printcase int t; cin>>t; for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";solve();}
#define max_heap(x) priority_queue<x>
#define min_heap(x) priority_queue<x, vector<x>, greater<x>>

void solve() {
    int n, m;
    cin >> n >> m;
    vvii adj(n+1);
    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    vll dist(n+1, LLONG_MAX);
    vi visited(n+1, 0);
    dist[1] = 0;
    min_heap(pli) pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int u = pq.top().ss;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto &x: adj[u]) {
            int v = x.ff, w = x.ss;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    rep(i, 1, n+1) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}