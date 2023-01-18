#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
10 10
1 2
1 5
2 3
2 4
3 6
4 9
9 10
5 10
5 7
5 8
*/
int n, m, ta, tb;
class edgeinfo{
public:
    vector <int> neighbor;
    int con = 0;
};
vector <vector <int>> e;
vector <int>    iscut;
vector <int>    visited;
vector <int>    discovery;
vector <int>    low;

void findinsub(int u, int& t, int parent){
    int ch_num = 0;
    visited[u] = 1;
    discovery[u] = low[u] = ++t;
    for (int s=0 ; s<e[u].size() ; s++){
        int v = e[u][s];
        if (visited[v]==0){
            ch_num ++;
            findinsub(v, t, u);
            low[u] = min(low[u], low[v]);
            if (parent != -1 && low[v]>=discovery[u])   iscut[u] = 1;
        }
        else if (v!= parent)
            low[u] = min(low[u], discovery[v]);
    }
    if (parent == -1 && ch_num > 1)   iscut[u] = 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    e.resize(n+1);
    visited.resize(n+1);
    iscut.resize(n+1);
    discovery.resize(n+1);
    low.resize(n+1);
    for (int i=0 ; i<m ; i++){
        cin >> ta >> tb;
        e[ta].push_back(tb);
        e[tb].push_back(ta);
    }
    int time = 0;
    for (int i=1 ; i<=n ; i++){
        if (!visited[i])
            findinsub(i, time, -1);
    }
    int cutnum = 0;
    for (int i=1 ; i<=n ; i++){
        if (iscut[i])   cutnum++;
    }
    cout << cutnum << "\n";
    for (int i=1 ; i<=n ; i++)  if (iscut[i])   cout << i << " ";
}
