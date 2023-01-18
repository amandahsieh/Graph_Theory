#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
long long int Q, n, m;
class special{
public:
    long long int u, v;
    long long int w;
};

vector <special>  s;

bool bigger(special a, special b){
    return a.w < b.w;
}

vector <long long int> cost;
vector <long long int> component;

long long int looking(long long int a){
    if (a!= component[a])   return looking(component[a]);
    else    return a;
}
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> Q;
    for (long long int casenum=0 ; casenum<Q ; casenum++){
        cin >> n >> m;
        s.resize(m);
        cost.resize(n+1);
        component.resize(n+1);
        for (long long int i=1 ; i<=n ; i++)   component[i] = i;
        for (long long int i=1 ; i<=n ; i++)   cin >> cost[i];
        long long int mini = *min_element(cost.begin()+1, cost.end());
        long long int ans = 0;
        for (long long int i=1 ; i<=n ; i++) ans += mini+cost[i];
        ans-=(mini*2);
        for (long long int i=0 ; i<m ; i++)   cin >> s[i].u >> s[i].v >> s[i].w;
        sort(s.begin(), s.end(), bigger);
        for (long long int i=0 ; i<m ; i++){
            long long int lena, lenb;
            long long int first = looking(s[i].u);
            long long int second = looking(s[i].v);
            if (first == second)    continue;
            lena = mini + cost[first];
            lenb = mini + cost[second];
            if (s[i].w<lena || s[i].w<lenb){
                ans-= max(lena, lenb);
                ans+= s[i].w;
                if (lena < lenb)    component[second] = first;
                else if (lena >= lenb)    component[first] = second;
            }
        }
        cout << ans << "\n";
    }
}
