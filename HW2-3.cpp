#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
long long int m, n, u, v;
/*
14
1 2
2 3
3 4
4 5
5 6
6 7
2 8
8 9
9 10
3 0
4 13
5 11
11 12
4
3 1 1 2
*/

/*
15
5 14
4 13
2 5
5 8
1 11
11 7
9 2
1 13
12 0
8 1
10 6
9 6
3 9
7 12
3
2  2  1
*/

/*
14
4 13
2 5
5 8
1 11
11 7
9 2
1 13
12 0
8 1
10 6
9 6
3 9
7 12
2
2 2
*/

struct connection{
    long long int num;
    long long int neighbor[3];
    bool yes[3] = {1,1,1};
    int cnt=0;
};

long long int len(long long int pre, long long int t, bool& y, connection graph[]){
    if (y==0)   return -1;
    if (graph[t].cnt==3){
        y = 0;
        return 0;
    }
    if (graph[t].cnt==1)    return 1;
    for (int i=0 ; i<2 ; i++){
        if (graph[t].neighbor[i] != pre){
            return len(t, graph[t].neighbor[i], y, graph) + 1;
        }

    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int rev = 0;
    long long int head = -5;
    long long int tail = -10;
    connection graph[n+5];
    vector<int> leafnum[n+5];
    vector<long long int> endings;
    vector <long long int> joints;
    for (long long int i=0 ; i<n ; i++) graph[i].num = i;
    for (long long int i=0 ; i<n-1 ; i++){
        cin >> u >> v;
        graph[u].neighbor[graph[u].cnt++] = v;
        graph[v].neighbor[graph[v].cnt++] = u;
    }
    cin >> m;
    long long int request[m+5];
    for (long long int i=0 ; i<m ; i++){
        cin >> request[i];
    }
    for (long long int i=0 ; i<n ; i++){
        //cout << i << "  " << graph[i].cnt << endl;
        if (graph[i].cnt > 3){
            cout << "NO";
            //cout << endl << "cnt > 3";
            return 0;
        }
        if (graph[i].cnt ==3){
            joints.push_back(i);
            //cout << i<< endl;
        }
    }
    if (joints.size()!=m){
        cout << "NO";
        //cout << joints.size() << endl << "joints size";
        return 0;
    }
    for (long long int i=0 ; i<joints.size() ; i++){
        long long int nn[3] = {0};
        bool y[3] = {1, 1, 1};
        for (int j=0 ; j<3 ; j++){
            nn[j] = len(joints[i], graph[joints[i]].neighbor[j], y[j], graph);
            graph[joints[i]].yes[j] = y[j];
            if (y[j]){
                //cout << y[j] <<"  ";
                leafnum[joints[i]].push_back(nn[j]);
                if (leafnum[joints[i]].size()==2){
                    endings.push_back(joints[i]);
                    //cout << joints[i]<<endl;
                }
            }
        }
    }
    if ((leafnum[endings[0]][0] == request[0] || leafnum[endings[0]][1] == request[0]) && (leafnum[endings[1]][0] == request[m-1] || leafnum[endings[1]][1] == request[m-1])){
        head = endings[0];
        tail = endings[1];
    }
    if (head > 0)   rev = 1;
    if ((leafnum[endings[1]][0] == request[0] || leafnum[endings[1]][1] == request[0]) && (leafnum[endings[0]][0] == request[m-1] || leafnum[endings[0]][1] == request[m-1])){
        head = endings[1];
        tail = endings[0];
    }
    //cout << head << "\t" << tail << endl;
    if (head<0){
        cout << "NO";
        //cout << endl << head << "   head is wrong" << endl;
        return 0;
    }
    long long int cur = head;
    long long int las = -5;
    long long int which = 1;

    //cout << cur << "  " << head << "  " << tail << endl;
    if (rev){
        int no = 0;
        cur = tail;
        for (int i=0 ; i<3 ; i++){
            if (graph[cur].yes[i] == 0){
                las = cur;
                cur = graph[cur].neighbor[i];
                break;
            }
        }
        while (cur != head){
            if (no) break;
            if (graph[cur].cnt == 1){
                las = cur;
                cur = graph[cur].neighbor[0];
            }
            else if (graph[cur].cnt == 2){
                //cout << graph[cur].neighbor[0] <<"  "<<graph[cur].neighbor[1] << "  "<< las << endl;
                if (graph[cur].neighbor[0] != las){
                    las = cur;
                    cur = graph[cur].neighbor[0];
                }
                else{
                    las = cur;
                    cur = graph[cur].neighbor[1];
                }
            }
            else{
                if (leafnum[cur][0]!=request[which]){
                    no = 1;
                    break;
                }
                which++;
                for (int j=0 ; j<3 ; j++){
                    if (las == graph[cur].neighbor[j])  continue;
                    if (graph[cur].yes[j] == 1) continue;
                    else{
                        las = cur;
                        cur = graph[cur].neighbor[j];
                        break;
                    }
                }
            }
        }
        if (no==0){
            cout << "YES";
            return 0;
        }
    }
    cur = head;
    for (int i=0 ; i<3 ; i++){
        if (graph[cur].yes[i] == 0){
            las = cur;
            cur = graph[cur].neighbor[i];
            break;
        }
    }
    while (cur != tail){
        if (graph[cur].cnt == 1){
            las = cur;
            cur = graph[cur].neighbor[0];
        }
        else if (graph[cur].cnt == 2){
            //cout << graph[cur].neighbor[0] <<"  "<<graph[cur].neighbor[1] << "  "<< las << endl;
            if (graph[cur].neighbor[0] != las){
                las = cur;
                cur = graph[cur].neighbor[0];
            }
            else{
                las = cur;
                cur = graph[cur].neighbor[1];
            }
        }
        else{
            if (leafnum[cur][0]!=request[which]){
                cout << "NO";
                //cout << cur << "  "<<leafnum[cur][0] << "  " << which << "  "<< request[which] << endl;
                return 0;
            }
            which++;
            for (int j=0 ; j<3 ; j++){
                if (las == graph[cur].neighbor[j])  continue;
                if (graph[cur].yes[j] == 1) continue;
                else{
                    las = cur;
                    cur = graph[cur].neighbor[j];
                    break;
                }
            }
        }
    }
    cout << "YES";
}
