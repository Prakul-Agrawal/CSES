//
// Created by Prakul Agrawal on 6/13/24.
//

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
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
    vector<pair<pii, int>> edges;
    vll dist(n + 1, LLONG_MIN);
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.pb({{a, b}, c});
    }
    vi reachable(n+1, 0);
    reachable[n] = 1;
    vvi adj(n+1);
    for(auto e: edges){
        adj[e.ff.ss].pb(e.ff.ff);
    }
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto next: adj[node]){
            if(reachable[next] == 0){
                reachable[next] = 1;
                q.push(next);
            }
        }
    }
    bool changed;
    dist[1] = 0;
    rep(i,0,n-1){
        changed = false;
        for(auto e: edges){
            int a = e.ff.ff;
            int b = e.ff.ss;
            int c = e.ss;
            if(dist[a] != LLONG_MIN){
                if (dist[b] < dist[a] + c) {
                    dist[b] = dist[a] + c;
                    changed = true;
                }
            }
        }
        if (!changed) break;
    }
    if(changed){
        for(auto e: edges){
            int a = e.ff.ff;
            int b = e.ff.ss;
            int c = e.ss;
            if(dist[a] != LLONG_MIN){
                if (dist[b] < dist[a] + c) {
                    dist[b] = dist[a] + c;
                    if (reachable[b] == 1) {
                        cout << -1 << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << dist[n] << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}