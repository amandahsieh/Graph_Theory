#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int main (){
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    vector <int> points;
    points.resize(n);
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            int tmp;
            cin>>tmp;
            if (i!=j){
                switch (tmp){
                case 0:
                    points[i]+=b;
                    break;
                case 1:
                    points[i]+=a;
                    break;
                case 2:
                    points[i]+=c;
                    break;
                default:
                    break;
                }
            }
        }
    }
    for (int i=0 ; i<n ; i++){
        cout<<points[i]<<" ";
    }

}
