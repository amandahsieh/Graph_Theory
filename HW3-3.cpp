#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

class Node{
public:
    int parent = -1;
    vector <int> child;
    int height = 0;
    vector <int> neighbor;
};

int n;
vector <Node> tree;

void build_tree(int t){
    for (int k=0 ; k<tree[t].neighbor.size() ; k++){
        if (tree[t].neighbor[k] == tree[t].parent)    continue;
        tree[tree[t].neighbor[k]].parent = t;
        tree[t].child.push_back(tree[t].neighbor[k]);
        build_tree(tree[t].neighbor[k]);
    }
}

void trace(int t){
    if (tree[t].parent !=-1){
        tree[tree[t].parent].height = max(tree[tree[t].parent].height, tree[t].height+1);
        trace(tree[t].parent);
    }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    tree.resize(n+5);
    int x, y;
    for (int i=0 ; i<n-1 ; i++) {
        cin >> x >> y;
        tree[x].neighbor.push_back(y);
        tree[y].neighbor.push_back(x);
    }
    build_tree(1);
    //cout << "built\n";
    for (int i=1 ; i<=n ; i++){
        if (tree[i].child.size() == 0)  trace(i);
    }
    for (int i=1 ; i<n+1 ; i++){
        cout << tree[i].height << " " << tree[i].parent << "\n";
    }
}
