#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <vector <int>> mt;
int n, m, k;
vector <int> t;
vector <int> chosen;

int bpm(int u, int seen[]){
    for (int v=1 ; v<m+1 ; v++){
        if (mt[u][v] && !seen[v]){
            seen[v] = 1;
            if (chosen[v]<0 || bpm(chosen[v], seen)){
                chosen[v]=u;
                return 1;
            }
        }
    }
    return 0;
}


int main (){
    cin >> n >> m >> k;
    mt.resize(n, vector <int> (m+1, 0));
    chosen.resize(m+1, -1);
    int tmplen, tmpver;
    for (int i=0 ; i<n ; i++){
        cin >> tmplen;
        for (int j=0 ; j<tmplen; j++){
            cin >> tmpver;
            mt[i][tmpver] = 1;
        }
    }
    int ans1 = 0, ansk = 0;
    for (int i=0 ; i<n ; i++){
        int checked[m+1];
        for (int j=0 ; j<m+1 ; j++) checked[j]=0;
        if (bpm(i, checked)==1)    ans1++;
    }
    //cout << ans1<<endl;
    for (int i=0 ; i<n ; i++){
        int checked[m+1];
        for (int j=0 ; j<m+1 ; j++) checked[j]=0;
        if (bpm(i, checked)==1)    ansk++;
    }
    //cout << ansk << endl;
    ans1 += min(ansk, k);
    cout << ans1;
}




/*
int n, m, k;
vector <int> t;
vector <vector<int>>  M;
vector <int>    hnum;
vector <int>    waiting;

bool comp (int a, int b){
    return hnum[a]<hnum[b];
}
bool compp(vector <int> a, vector <int> b){
    return a.size() < b.size();
}

int main (){
    cin >> n >> m >> k;
    t.resize(n);
    M.resize(n);
    waiting.resize(m+1, 1);
    hnum.resize(m+1);
    for (int i=0 ; i<n ; i++){
        cin >> t[i];
        M[i].resize(t[i]);
        for (int j=0 ; j<t[i] ; j++){
            cin >> M[i][j];
            hnum[M[i][j]]++;
        }
    }
    sort(M.begin(), M.end(), compp);
    sort(t.begin(), t.end());
    for (int i=0 ; i<n ; i++)   sort(M[i].begin(), M[i].end(), comp);
    for (int i=0 ; i<n ; i++){
        int done = 0;
        for (int j=0 ; j<t[i] ; j++){
            if (waiting[M[i][j]] && done==0){
                done = 1;
                waiting[M[i][j]] = 0;
                break;
            }
        }
    }
    for (int i=0 ; i<n ; i++){
        int minused=0;
        for (int j=M[i].size()-1 ; j>=0 ; j--){
            if (waiting[M[i][j]] == 0){
                t[i]--;
                M[i].erase(M[i].begin() + j-minused);
                minused++;
            }
        }
    }

    sort(M.begin(), M.end(), compp);
    sort(t.begin(), t.end());
    int use=0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<t[i] ; j++){
            if (waiting[M[i][j]]){
                waiting[M[i][j]] = 0;
                use ++ ;
                break;
            }
        }
        if (use == k)   break;
    }
    int ans=0;
    for (int i=1 ; i<=m ; i++){
        ans+=waiting[i];
        cout << i << waiting[i] << endl;
    }
    cout << ans << "\n";
}
*/
