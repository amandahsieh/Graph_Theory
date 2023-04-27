#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int main (){
    int n,m;
    cin>>n>>m;
    vector <vector<int>> matrix;
    vector <int> indegree;
    vector <int> outdegree;

    for (int i=0 ; i<n ; i++){
        vector <int> tmp;
        for (int j=0 ; j<n ; j++){
            tmp.push_back(0);
        }
        indegree.push_back(0);
        outdegree.push_back(0);
        matrix.push_back(tmp);
    }
    int v1, v2, w;
    for (int i=0 ; i<m ; i++){
        cin>>v1>>v2>>w;
        matrix[v1-1][v2-1]+=w;
        outdegree[v1-1]+=1;
        indegree[v2-1]+=1;
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i=0 ; i<n ; i++){
        cout<< indegree[i]<<" "<<outdegree[i]<<endl;
    }
}
