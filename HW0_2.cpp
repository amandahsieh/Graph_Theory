#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int main (){
    int n,which=0,m=-1;
    vector <int> fre;
    cin>>n;
    fre.resize(n+1);
    for (int i=0 ; i<n ; i++){
        int tmp;
        cin>>tmp;
        fre[tmp]++;
        if (fre[tmp]>m || (fre[tmp]==m && tmp>which)){
            m=fre[tmp];
            which=tmp;
        }
    }
    cout<<which<<" "<<m;
}
