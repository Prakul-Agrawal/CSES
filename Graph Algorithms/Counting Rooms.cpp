#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<vii> vvii;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(s) s.begin(), s.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define max_heap(x) priority_queue<x>
#define min_heap(x) priority_queue<x, vector<x>, greater<x>>

//----------------------------- Explanation -----------------------------//
// This problem is a simple application of DFS
// Each time you find a unvisited node, you start a new component and 
// after reaching all accessible nodes from that node, you increment the
// count of components by 1
// ----------------------------------------------------------------------//

void dfs(int n, int m, vvi &vis, int x, int y, vector<string> &adj){
    vis[x][y] = 1;
    if (x - 1 >= 0 && adj[x-1][y] == '.' && !vis[x-1][y]) dfs(n, m, vis, x-1, y, adj);
    if (x + 1 < n && adj[x+1][y] == '.' && !vis[x+1][y]) dfs(n, m, vis, x+1, y, adj);
    if (y - 1 >= 0 && adj[x][y-1] == '.' && !vis[x][y-1]) dfs(n, m, vis, x, y-1, adj);
    if (y + 1 < m && adj[x][y+1] == '.' && !vis[x][y+1]) dfs(n, m, vis, x, y+1, adj);
}
 
void solve(){
    int n, m, count = 0;;
    cin>>n>>m;
    vector<string> adj(n);
    rep(i,0,n) cin>>adj[i];
    vvi vis(n, vi(m, 0));
    rep(i,0,n){
        rep(j,0,m){
            if (adj[i][j] == '.' && !vis[i][j]){
                dfs(n, m, vis, i, j, adj);
                count++;
            }
        }
    }
    cout<<count<<endl;
}
 
int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}