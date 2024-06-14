//
// Created by Prakul Agrawal on 6/14/24.
//

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define INF 1e15
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
    vvii adj(n + 1);
    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    vll dist1(n + 1, INF), distN(n + 1, INF);
    dist1[1] = 0;
    distN[n] = 0;
    min_heap(pli) pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        pli p = pq.top();
        pq.pop();
        ll d = p.ff;
        int u = p.ss;
        if (d > dist1[u]) continue;
        for (pii e : adj[u]) {
            int v = e.ff;
            ll w = e.ss;
            if (dist1[u] + w < dist1[v]) {
                dist1[v] = dist1[u] + w;
                pq.push({dist1[v], v});
            }
        }
    }
    vvii adjRev(n + 1);
    rep(i, 1, n + 1) {
        for (pii e : adj[i]) {
            adjRev[e.ff].pb({i, e.ss});
        }
    }
    pq.push({0, n});
    while (!pq.empty()) {
        pli p = pq.top();
        pq.pop();
        ll d = p.ff;
        int u = p.ss;
        if (d > distN[u]) continue;
        for (pii e : adjRev[u]) {
            int v = e.ff;
            ll w = e.ss;
            if (distN[u] + w < distN[v]) {
                distN[v] = distN[u] + w;
                pq.push({distN[v], v});
            }
        }
    }
    ll ans = LLONG_MAX;
    rep(u, 1, n + 1) {
        for (pii e : adj[u]) {
            int v = e.ff;
            ll w = e.ss;
            ans = min(ans, dist1[u] + distN[v] + w / 2);
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}