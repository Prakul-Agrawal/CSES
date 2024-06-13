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
    vector<string> a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    vvi mDist(n, vi(m, INT_MAX)), aDist(n, vi(m, INT_MAX));
    queue<pii> q;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (a[i][j] == 'M') {
                mDist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        int i = p.ff, j = p.ss;
        if(i > 0 && a[i-1][j] != '#' && mDist[i-1][j] == INT_MAX){
            mDist[i-1][j] = mDist[i][j] + 1;
            q.push({i-1, j});
        }
        if(i < n-1 && a[i+1][j] != '#' && mDist[i+1][j] == INT_MAX){
            mDist[i+1][j] = mDist[i][j] + 1;
            q.push({i+1, j});
        }
        if(j > 0 && a[i][j-1] != '#' && mDist[i][j-1] == INT_MAX){
            mDist[i][j-1] = mDist[i][j] + 1;
            q.push({i, j-1});
        }
        if(j < m-1 && a[i][j+1] != '#' && mDist[i][j+1] == INT_MAX){
            mDist[i][j+1] = mDist[i][j] + 1;
            q.push({i, j+1});
        }
    }
    vector<string> b(n, string(m, '.'));
    rep(row, 0, n){
        rep(col, 0, m){
            if(a[row][col] == 'A'){
                aDist[row][col] = 0;
                q.push({row, col});
                while(!q.empty()){
                    pii p = q.front();
                    q.pop();
                    int i = p.ff, j = p.ss;
                    if(i > 0 && a[i-1][j] != '#' && aDist[i-1][j] == INT_MAX && mDist[i-1][j] > aDist[i][j] + 1){
                        aDist[i - 1][j] = aDist[i][j] + 1;
                        q.push({i - 1, j});
                        b[i-1][j] = 'U';
                    }
                    if(i < n-1 && a[i+1][j] != '#' && aDist[i+1][j] == INT_MAX && mDist[i+1][j] > aDist[i][j] + 1){
                        aDist[i + 1][j] = aDist[i][j] + 1;
                        q.push({i + 1, j});
                        b[i+1][j] = 'D';
                    }
                    if(j > 0 && a[i][j-1] != '#' && aDist[i][j-1] == INT_MAX && mDist[i][j-1] > aDist[i][j] + 1){
                        aDist[i][j - 1] = aDist[i][j] + 1;
                        q.push({i, j - 1});
                        b[i][j-1] = 'L';
                    }
                    if(j < m-1 && a[i][j+1] != '#' && aDist[i][j+1] == INT_MAX && mDist[i][j+1] > aDist[i][j] + 1){
                        aDist[i][j + 1] = aDist[i][j] + 1;
                        q.push({i, j + 1});
                        b[i][j+1] = 'R';
                    }
                }
                rep(h,0,n){
                    if (aDist[h][0] != INT_MAX || aDist[h][m-1] != INT_MAX){
                        cout << "YES" << endl;
                        int dist = aDist[h][0] == INT_MAX ? aDist[h][m-1] : aDist[h][0];
                        cout << dist << endl;
                        string path;
                        int x = h;
                        int y = aDist[h][0] == INT_MAX ? m-1 : 0;
                        rep(j, 0, dist){
                            path += b[x][y];
                            if(b[x][y] == 'U'){
                                x++;
                            }
                            else if(b[x][y] == 'D'){
                                x--;
                            }
                            else if(b[x][y] == 'L'){
                                y++;
                            }
                            else{
                                y--;
                            }
                        }
                        reverse(all(path));
                        cout << path << endl;
                        return;
                    }
                }
                rep(g, 0, m) {
                    if (aDist[0][g] != INT_MAX || aDist[n - 1][g] != INT_MAX) {
                        cout << "YES" << endl;
                        int dist = aDist[0][g] == INT_MAX ? aDist[n - 1][g] : aDist[0][g];
                        cout << dist << endl;
                        string path;
                        int x = aDist[0][g] == INT_MAX ? n - 1 : 0;
                        int y = g;
                        rep(j, 0, dist) {
                            path += b[x][y];
                            if (b[x][y] == 'U') {
                                x++;
                            } else if (b[x][y] == 'D') {
                                x--;
                            } else if (b[x][y] == 'L') {
                                y++;
                            } else {
                                y--;
                            }
                        }
                        reverse(all(path));
                        cout << path << endl;
                        return;
                    }
                }
                cout << "NO" << endl;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}