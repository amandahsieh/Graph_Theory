#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

class infecting{
public:
    int tg; //target of infection
    int w;
};

class machineinfo{
public:
    vector <infecting> to;
    int infected = 0;
};

vector <machineinfo>    mc;
vector <long long int> inf;
vector <long long int> anti;
int infect_num = 0;
int n, m, p, q, tp, tq;
long long int t, T;

void dfsvirus(int s){
    for (int k=0 ; k<mc[s].to.size() ; k++){
        int next_ = mc[s].to[k].tg;
        if (inf[next_]>=0 && inf[next_] <= inf[s]+mc[s].to[k].w)    continue;
        else{
            inf[next_] = inf[s]+mc[s].to[k].w;
            mc[next_].infected = 1;
            dfsvirus(next_);
        }
    }
}

void dfsanti(int s){
    if (anti[s]>inf[s] && mc[s].infected>0) return;
    mc[s].infected = 0;
    for (int k=0 ; k<mc[s].to.size() ; k++){
        int next_ = mc[s].to[k].tg;
        if (anti[next_]>=0 && anti[next_] <= anti[s]+1)    continue;
        else{
            anti[next_] = anti[s]+1;
            dfsanti(next_);
        }
    }
}

int main (){
    cin >> n >> m >> p >> q >> t >> T;
    mc.resize(n+1);
    inf.resize(n+1, -1);
    anti.resize(n+1, -1);
    for (int i=0 ; i<m ; i++){
        int tmpa;
        infecting tmpto;
        cin >> tmpa >> tmpto.tg >> tmpto.w;
        mc[tmpa].to.push_back(tmpto);
    }
    for (int i=0 ; i<p ; i++){
        int tmpinf;
        cin >> tmpinf;
        inf[tmpinf] = 0;
        mc[tmpinf].infected = 1;
    }
    for (int i=0 ; i<q ; i++){
        int tmpanti;
        cin >> tmpanti;
        anti[tmpanti] = t;
    }
    for (int i=1 ; i<=n ; i++){
        if (inf[i]!=0)   continue;
        dfsvirus(i);
    }
    /*
    cout << "After dfs virus\n";
    for (int i=1 ; i<=n ; i++){
        cout << i << "infected or not: "<< mc[i].infected << "infected time: " << inf[i] << endl;
    }*/
    for (int i=1 ; i<=n ; i++){
        if (anti[i]!=t) continue;
        dfsanti(i);
    }
    /*
    cout << "After dfs antivirus\n";
    for (int i=1 ; i<=n ; i++){
        cout << i << "infected or not: "<< mc[i].infected << "infected time: " << inf[i] << endl;
    }
    */
    int sum = 0;
    for (int i=1 ; i<=n ; i++){
        if (mc[i].infected && inf[i]<=T)    sum++;
    }
    cout << sum;
}
