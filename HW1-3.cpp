#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
long long int n, m, sum=0, checking, first=0;

long long int q, a, b;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--){
        long long int roads[50010]={0};
        long long int sumarray[50010]={0};
        int no=0;
        sum=0;
        cin >> n >> m;
        for (long long int i=1 ; i<=n ; i++){
            cin >> roads[i];
        }
        for (long long int i=0 ; i<m ; i++){
            cin >> a >> b;
            roads[a]--;
            roads[b]--;
        }
        sort(roads+1, roads+n+1, greater<long long int>());
        for (long long int i=1 ; i<=n ; i++){
            if (roads[i]<0) {
                no=1;
                break;
            }
            if (i==1)   sumarray[i] = roads[i];
            else        sumarray[i] = sumarray[i-1] + roads[i];
        }
        if (sumarray[n]%2==1){
            no=1;
        }
        for (long long int i=n ; i>0 ; i--){
            first = upper_bound(roads+1, roads+n+1, i, greater<long long int>())-(roads);
            if (i>first){
                sum = sumarray[n]-sumarray[i];
            }
            else {
                sum = i*(first-i) + sumarray[n]-sumarray[first];
            }
            if (sumarray[i] <= i*(i-1) + sum)   continue;
            else{
                no=1;
                break;
            }
        }
        if (no) cout<<"No"<<endl;
        else    cout<<"Yes"<<endl;

    }
}
