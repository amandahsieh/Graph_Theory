#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

vector <long long int> m[300010];
class Tree{
public:
    long long int layer;
    long long int num;
    vector <long long int> parent;
};
Tree tree[300010];
long long int n, x, y, l=1;
long long int q, len=0, u, v;

void build (long long int vrt){
    if (m[vrt].size()==0) return;
    else{
        tree[vrt].layer = l;
        for (long long int k=0 ; k<m[vrt].size() ; k++){
            tree[m[vrt][k]].layer = ++l;
            tree[m[vrt][k]].parent.push_back(vrt);
            build(m[vrt][k]);
            l--;
        }
    }
}

long long int lca(long long int a){
    n1 = o1;
    n2 = o2;
    if (tree[n1].parent[0].num == tree[n2].parent[0].num)   return pow(2, a);
    for (long long int i=0 ; i<n ; i++){
            if (n1 == n2){
                if (i==0)   return pow(2, a) + pow(2, i);
                return lca(i-1) + pow(2, a);
            }
            else{
                o1 = n1;
                o2 = n2;
                n1 = tree[n1].parent[0].parent[0].num;
                n2 = tree[n2].parent[0].parent[0].num;
            }
        }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (long long int i=1 ; i<=n ; i++)    tree[i].num = i;
    for (long long int i=0 ; i<n-1 ; i++){
        cin >> x >> y;
        if (x>y)    swap(x, y);
        m[x].push_back(y);
    }
    build(1);
    cin >> q;
    while (q--){
        cin >> u >> v;
        if (tree[v].layer > tree[u].layer)  swap(u, v);
        len = tree[u].layer - tree[v].layer;
        long long int tmp1=u, tmp2=v;
        for (long long int i=0 ; i<len ; i++){
            tmp1 = tree[tree[tmp1].parent[0]].num;
        }
        for (long long int i=0 ; i<n ; i++){
            if (tmp1 == tmp2){
                len += 2*i;
                break;
            }
            else{
                tmp1 = tree[tree[tmp1].parent[0]].num;
                tmp2 = tree[tree[tmp2].parent[0]].num;
            }
        }
        cout<<len << "\n";
    }
}




/*
vector <long long int> m[300010];
class Tree{
public:
    long long int layer;
    long long int num;
    vector <Tree> parent;
    vector <Tree> children;
    Tree(){
        layer = -1;
    }
};

vector <Tree> tree
Tree tree[300010];
long long int n, x, y, l=1;
long long int q, len=0, u, v;
long long int n1, n2, o1, o2;

void build (long long int vrt){
    if (m[vrt].size()==0) return;
    else{
        tree[vrt].layer = l;
        for (long long int k=0 ; k<m[vrt].size() ; k++){
            tree[m[vrt][k]].layer = ++l;
            tree[vrt].children.push_back(tree[m[vrt][k]]);
            tree[m[vrt][k]].parent.push_back(tree[vrt]);
            build(m[vrt][k]);
            l--;
        }
    }
}

long long int lca(long long int a){
    n1 = o1;
    n2 = o2;
    if (tree[n1].parent[0].num == tree[n2].parent[0].num)   return pow(2, a);
    for (long long int i=0 ; i<n ; i++){
            if (n1 == n2){
                if (i==0)   return pow(2, a) + pow(2, i);
                return lca(i-1) + pow(2, a);
            }
            else{
                o1 = n1;
                o2 = n2;
                n1 = tree[n1].parent[0].parent[0].num;
                n2 = tree[n2].parent[0].parent[0].num;
            }
        }
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (long long int i=1 ; i<=n ; i++)    tree[i].num = i;
    for (long long int i=0 ; i<n-1 ; i++){
        cin >> x >> y;
        if (x>y)    swap(x, y);
        m[x].push_back(y);
    }
    build(1);
    cin >> q;
    while (q--){
        cout << q <<endl;
        cin >> u >> v;
        if (u==v){
            cout << 0 << "\n";
            continue;
        }
        if (tree[v].layer > tree[u].layer)  swap(u, v);
        len = tree[u].layer - tree[v].layer;
        cout<<tree[u].num;

        cout<<len;
        o1 = u;
        o2 = v;
        cout<<o1;
        cout<<lca(0);
        len += lca(0);
        cout<<len << "\n";

    }
}
*/
