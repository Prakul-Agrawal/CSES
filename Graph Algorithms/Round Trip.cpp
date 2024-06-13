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

int dfs(int node, int parent, vvi &adj, vi &visited, vi &path, int mark){
    visited[node] = mark;
    path.pb(node);
    for(auto v: adj[node]) {
        if (v == parent) {
            continue;
        }
        if (visited[v] == mark) {
            path.pb(v);
            return 1;
        }
        if (visited[v]) {
            continue;
        }
        if (dfs(v, node, adj, visited, path, mark)) {
            return 1;
        }
    }
    path.pop_back();
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vvi adj(n+1);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi visited(n+1, 0);
    rep(i,1,n+1){
        if (visited[i]){
            continue;
        }
        vi path;
        if (dfs(i, -1, adj, visited, path, i)){
            int start = path.back();
            vi cycle;
            cycle.pb(start);
            for(int i = sz(path) - 2; i >= 0; i--){
                cycle.pb(path[i]);
                if (path[i] == start){
                    break;
                }
            }
            cout << sz(cycle) << endl;
            for(auto v: cycle){
                cout << v << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}