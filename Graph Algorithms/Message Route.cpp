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
    vvi adj(n+1);
    rep(i,0,m){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vi dist(n+1, INT_MAX);
    vi parent(n+1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(dist[v] == INT_MAX){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    if(dist[n] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vi path;
    int u = n;
    while(u != -1){
        path.pb(u);
        u = parent[u];
    }
    reverse(all(path));
    cout << sz(path) << endl;
    for(auto x: path){
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}