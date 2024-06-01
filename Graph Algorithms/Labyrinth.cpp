//
// Created by Prakul Agrawal on 6/1/24.
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

//----------------------------- Explanation -----------------------------//
// This problem is a simple application of BFS to find the shortest path.
// I have used two maps for conversion between direction and movement.
// This reduces the number of if-else statements.
// We simply keep storing the direction of the path in the dir array and
// then backtrack from the end to the start to get the path.
// ----------------------------------------------------------------------//

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    rep(i, 0, n) cin >> grid[i];
    vector<string> dir(n, string(m, '.'));
    queue<pii> q;
    pii start, end;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }
    grid[end.ff][end.ss] = '.';
    q.push(start);
    map<pii, char> moveToDir;
    map<char, pii> dirToMove;
    moveToDir[{0, 1}] = 'R';
    moveToDir[{0, -1}] = 'L';
    moveToDir[{1, 0}] = 'D';
    moveToDir[{-1, 0}] = 'U';
    dirToMove['R'] = {0, 1};
    dirToMove['L'] = {0, -1};
    dirToMove['D'] = {1, 0};
    dirToMove['U'] = {-1, 0};
    while(!q.empty()){
        pii curr = q.front();
        q.pop();
        int x = curr.ff, y = curr.ss;
        for(auto mtd : moveToDir){
            int dx = mtd.ff.ff, dy = mtd.ff.ss;
            char d = mtd.ss;
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != '.' || dir[nx][ny] != '.')
                continue;
            dir[x + dx][y + dy] = d;
            q.push({x + dx, y + dy});
            if(x + dx == end.ff && y + dy == end.ss) {
                break;
            }
        }
    }
    if(dir[end.ff][end.ss] == '.'){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    string path;
    pii curr = end;
    while(curr != start){
        path += dir[curr.ff][curr.ss];
        pii dtr = dirToMove[dir[curr.ff][curr.ss]];
        curr = {curr.ff - dtr.ff, curr.ss - dtr.ss};
    }
    reverse(all(path));
    cout<<sz(path)<<endl;
    cout<<path<<endl;
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}