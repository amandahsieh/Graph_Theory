#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define inf 100000000000000001
using namespace std;
struct restaurants{
	long long int cost=inf;
	int idx=-1; // for "neighbor": child, for "road": parent
};
struct cmp{
	bool operator()(restaurants a, restaurants b){
		return a.cost > b.cost;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cases,sub;
	cin >> cases >> sub;
	while(cases--){
		int n, m, k, u, v;
		long long int w;
		restaurants tmp_res;
		cin >> n >> m >> k;
		vector< vector<restaurants> > neighbor(n+1);
		vector <long long int> route_1(n+1, inf);
		for(int i=0 ; i<m ; i++){
			cin >> u >> v >> w;
			tmp_res.cost = w;
			tmp_res.idx = u;
			neighbor[v].push_back(tmp_res);
		}
		route_1[1]=0;

		priority_queue<restaurants, vector<restaurants>, cmp> pq1; //run the path with min cost first
		tmp_res.cost = 0;
		tmp_res.idx = 1;
		pq1.push(tmp_res);
		while(!pq1.empty()){
			tmp_res = pq1.top();
			pq1.pop();
			for(int i=0 ; i<neighbor[tmp_res.idx].size() ; i++){
				if(route_1[neighbor[tmp_res.idx][i].idx] > route_1[tmp_res.idx] + neighbor[tmp_res.idx][i].cost){
					route_1[neighbor[tmp_res.idx][i].idx] = route_1[tmp_res.idx] + neighbor[tmp_res.idx][i].cost;
					pq1.push(neighbor[tmp_res.idx][i]);
				}
			}

		}

		if(k == 1){
			for(int i=1 ; i<=n ; i++){
				if (route_1[i]==inf) cout << -1 << " ";
				else cout<<route_1[i]<<" ";
			}
			cout<<'\n';
		}
		else if(k==2){
			vector<long long> road2(n+1, inf);
			//cout<<"*"<<road2[n].cost<<" / "<<road2[n].idx<<endl;
			road2[n]=0;
			tmp_res.cost = 0;
			tmp_res.idx = n;
			pq1.push(tmp_res);
			while(!pq1.empty()){
				tmp_res = pq1.top();
				pq1.pop();
				for(int i=0 ; i<neighbor[tmp_res.idx].size() ; i++){
					if(road2[neighbor[tmp_res.idx][i].idx] > road2[tmp_res.idx] + neighbor[tmp_res.idx][i].cost){
						road2[neighbor[tmp_res.idx][i].idx] = road2[tmp_res.idx] + neighbor[tmp_res.idx][i].cost;
						pq1.push(neighbor[tmp_res.idx][i]);
					}
				}

			}

			for(int i=1 ; i<=n ; i++){
				if(route_1[i]!=inf && road2[i]!=inf){
					tmp_res.cost = route_1[i]+road2[i];
					tmp_res.idx = i;
					neighbor[0].push_back(tmp_res);
				}
			}
			vector<long long int> road(n+1, inf);
			//cout<<"*"<<road2[n].cost<<" / "<<road2[n].idx<<endl;
			road[0] = 0;
			tmp_res.cost = 0;
			tmp_res.idx = 0;
			pq1.push(tmp_res);
			while(!pq1.empty()){
				tmp_res = pq1.top();
				pq1.pop();
				for(int i=0 ; i<neighbor[tmp_res.idx].size() ; i++){
					if(road[neighbor[tmp_res.idx][i].idx] > road[tmp_res.idx] + neighbor[tmp_res.idx][i].cost){
						road[neighbor[tmp_res.idx][i].idx] = road[tmp_res.idx] + neighbor[tmp_res.idx][i].cost;
						pq1.push(neighbor[tmp_res.idx][i]);
					}
				}

			}

			for(int i=1 ; i<=n ; i++){
				if(road[i] == inf) cout << -1 << " ";
				else cout << road[i] << " ";
			}
			cout << '\n';
		}
	}
}


/*
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class route{
public:
    vector <long long int> from;
    vector <long long int> w;
    long long int f=0;
};

vector <route> r;
long long int T, sub, n, m, j;
vector <long long int> u;
vector <long long int> v;
vector <long long int> num;
vector <long long int> ww;
vector <long long int> one;
vector <long long int> nth;
vector <int> visited;

class route{
    int s, d;
    long long int w;
};

void

vector <route> r;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T >> sub;
    while (T--){
        cin >> n >> m >> k;
        r.resize(m+5);
        for (long long int i=0 ; i<m ; i++)    cin >> r[i].s >> r[i].d >> r[i].w;
        one.resize(n+5, -1);
        nth.resize(n+5, -1);
        nth[n]=0;
        one[1]=0;
        build(1, visited, one, 0);
        if (j==1){
            for (long long int i=1 ; i<=n ; i++)    cout << one[i]<<" ";
            cout << "\n";
            continue;
        }
        build(n, visited, nth, 1);
        for (long long int i=1 ; i<=n ; i++)  nth[i] =(nth[i]<0||one[i]<0)? -1:nth[i]+one[i];
        build(1, visited, nth, 0);
        for (long long int i=1 ; i<=n ; i++)    cout << nth[i]<<" ";
        cout << "\n";
    }
}
*/
