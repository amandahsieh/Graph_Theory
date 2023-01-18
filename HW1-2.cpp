#include <vector>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;


class relation{
public:
    vector <relation> nexts;
    int order;
};

/*
5 6 2 1
2 5
4 3
4 5
3 1
3 2
3 5
4 5
*/
queue <int> infected;
int n, m, k, t,ans=0;
vector <int> graph[1000005];
//relation graph[1000005];
int visited[1000005]={0};

int main(){
    cin >> n >> m >> k >> t;
    int a,b,tmp1;
    while (m--){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i=0 ; i<k ; i++){
        cin >> tmp1;
        visited[tmp1] = 1;
        infected.push(tmp1);
        ans++;
    }

    for (int i=1 ; i<t ; i++){
        int len = infected.size();
		if (len==0)	break;
        for (int j=0 ; j<len ; j++){
            int tmp3 = graph[infected.front()].size();
            for (int r=0 ; r<tmp3 ; r++){
                if (visited[graph[infected.front()][r]]==0){
                    visited[graph[infected.front()][r]]=1;
                    infected.push(graph[infected.front()][r]);
                    ans++;
                }
            }
            infected.pop();
        }
    }
    cout<<ans;
}


/*
int main(){
    int ans=0;
    cin>>n>>m>>k>>t;
    int a,b,tmp1;
    for (int i=0 ; i<n ; i++){
        graph[i+1].order=i+1;
        visited[i+1] = 0;
    }
    while (m--){
        cin>>a>>b;
        graph[a].nexts.push_back(graph[b]);
    }
    vector <int> tmp;
    for (int i=0 ; i<k ; i++){
        cin>>tmp1;
        visited[tmp1]=1;
        infected.push(graph[tmp1]);
        ans++;
    }

    for (int i=1 ; i<t ; i++){
        int len=infected.size();
		if (len==0)	break;
        for (int j=0 ; j<len ; j++){
            int tmp3=infected.front().nexts.size();
            for (int r=0 ; r<tmp3 ; r++){
                if (visited[infected.front().nexts[r].order]==0){
                    visited[infected.front().nexts[r].order]=1;
                    infected.push(infected.front().nexts[r]);
                    ans++;
                }
            }
            infected.pop();
        }
    }
    cout<<ans;
}
*/
