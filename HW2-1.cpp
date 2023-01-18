#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string Shortest_Super_String(vector<string>& S) {
    vector<vector<string>> dp(1<<n,vector<string>(n));
    vector<vector<int>> thesame(n,vector<int>(n,0));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j) if(i!=j){
            for(int k = min(S[i].size(), S[j].size()); k>0; --k){
                if(S[i].substr(S[i].size()-k)==S[j].substr(0,k)){
                    thesame[i][j] = k;
                    break;
                }
            }
        }
    }
    for(int i=0; i<n; ++i) dp[1<<i][i] += S[i];
    for(int mask=1; mask<(1<<n); ++mask){
        for(int j=0; j<n; ++j) if((mask&(1<<j))>0){
            for(int i=0; i<n; ++i) if(i!=j && (mask&(1<<i))>0){
                string shorter_or_not;
                shorter_or_not = dp[mask^(1<<j)][i]+S[j].substr(thesame[i][j]);
                //cout << mask << "  "<<j <<"  "<<shorter_or_not << endl;
                if(dp[mask][j].empty() || shorter_or_not.size()<dp[mask][j].size() || (shorter_or_not.size()==dp[mask][j].size() && shorter_or_not.compare(dp[mask][j])<0))
                    dp[mask][j] = shorter_or_not;
            }
        }
    }
    int tmp = (1<<n)-1;
    string shortest = dp[tmp][0];
    for(int i=1; i<n; ++i) {
        if(dp[tmp][i].size() < shortest.size() ||(dp[tmp][i].size() == shortest.size() && dp[tmp][i].compare(shortest)<0)){
        shortest = dp[tmp][i];
        }
    }
    return shortest;
}


int main (){
    int relation[20][20]={0};
    cin >> n;
    vector <string> s;
    for (int i=0 ; i<n ; i++){
        string tmpstring;
        cin >> tmpstring;
        bool included = 0;
        for (int j=0 ; j<s.size() ; j++){
            if (s[j].find(tmpstring)!=string::npos) included = 1;
            else if (tmpstring.find(s[j])!=string::npos){
                s.erase(s.begin()+j);
                j--;
            }
        }
        if (included == 0)  s.push_back(tmpstring);
    }
    n = s.size();
    cout << Shortest_Super_String(s);
}
























/*
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int tmp[20][20];
string s[20];

int findlen(string a, string b){
    if (a.length() ==0 || b.length()==0)    return 0;
    int start = a.length()>b.length()? (a.length()-b.length()) : 0;
    int last  = a.length();
    int same = 1;
    int k = start;
    for (k=start ; k<last; k++){
        if (a.compare(k, last, b, 0, (last-k))==0){
            return a.length()-k;
            break;
        }
    }
    if (k == last)  return 0;

}

int compute (int which, int relation[20][20], int cnt){
    int m=-10;
    long long int last = -1;
    for (int r=0 ; r<n ; r++){
        if (r == tmp[which][cnt])   continue;
        char a[s[r].length() + 1];
        char b[s[last].length() + 1];
        for (int i=0 ; i<s[r].length() ; i++)    a[i] = s[r][i];
        for (int i=0 ; i<s[last].length() ; i++)    b[i] = s[last][i];
        if (relation[tmp[which][cnt]][r]>m || (relation[tmp[which][cnt]][r]==m && s[r].size()>0 && s[last].size()>0 && lexicographical_compare(a, a+s[r].length(), b, b+s[last].length()))){

            m = relation[tmp[which][cnt]][r];
            last = r;
            tmp[which][cnt+1] = r;
        }
        relation[r][tmp[which][cnt]] = -10;
    }
    if (cnt == n-2)   return m;
    return compute(which, relation, cnt+1) + m;
}

int main (){
    int relation[20][20]={0};
    cin >> n;
    for (int i=0 ; i<n ; i++)   cin >> s[i];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (i==j)   continue;
            else    relation[i][j] = findlen(s[i], s[j]);
            if (relation[i][j] == s[i].size()) s[i] = "\0";
            else if (relation[i][j] == s[j].size()) s[j] = "\0";
        }
    }

    int start, len = -10;
    string answer;
    for (int i=0 ; i<n ; i++){
        string tmpans;
        int res[20][20];
        for (int j=0 ; j<n ; j++){
            for (int k=0 ; k<n ; k++)   res[j][k] = relation[j][k];
        }
        int howmany = 0;
        tmp[i][0] = i;
        int computing = compute(i, res, howmany);
        for (int j=0 ; j<n ; j++){
            if (s[tmp[i][j]].length() == relation[tmp[i][j]][tmp[i][j+1]])   continue;
            if (s[tmp[i][j+1]].size()==0) tmpans += s[tmp[i][j]];
            else    tmpans += s[tmp[i][j]].substr(0, s[tmp[i][j]].size() - relation[tmp[i][j]][tmp[i][j+1]]);
        }
        if (i==0)   answer = tmpans;
        if (computing>len || (computing == len && answer>tmpans && tmpans.size()>0)){
            len = computing;
            answer = tmpans;
        }
    }
    cout << answer;
}
*/







/*#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int total = 1;


int findlen(string a, string b){
    if (a.length() ==0 || b.length()==0)    return 0;
    int start = a.length()>b.length()? (a.length()-b.length()) : 0;
    int last  = a.length();
    int same = 1;
    int k = start;
    for (k=start ; k<last; k++){
        if (a.compare(k, last, b, 0, (last-k))==0){
            return a.length()-k;
            break;
        }
    }
    if (k == last)  return 0;
}


int compute (int which, int relation[20][20], int cnt){
    int m=-10;
    for (int r=0 ; r<n ; r++){
        if (find(tmp[which], tmp[which]+cnt, r))    continue;
        tmp[which][cnt+1] = r;
        if (cnt == n-2)  return relation[tmp[which][cnt]][r];
        m=max(m, compute(which, relation, cnt+1) + relation[tmp[which][cnt]][r]) ;
    }
    return m;
}


int main (){
    int relation[20][20]={0};
    string s[20];
    cin >> n;
    for (int i=1 ; i<=n ; i++)  total *= i;
    for (int i=0 ; i<n ; i++)   cin >> s[i];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (i==j)   continue;
            else    relation[i][j] = findlen(s[i], s[j]);
            if (relation[i][j] == s[i].size()) s[i] = "\0";
            else if (relation[i][j] == s[j].size()) s[j] = "\0";
        }
    }

    int start, len = -10;
    int tmp[20][20];

    for (int i=0 ; i<n ; i++){
        int howmany = 0;
        tmp[i][0] = i;
        int computing = compute(i, relation, howmany, tmp[i]);
        if (computing>len){
            len = computing;
            start = i;
        }
    }

    for (int i=0 ; i<n ; i++){
        if (s[tmp[start][i]].length() == relation[tmp[start][i]][tmp[start][i+1]])   continue;
        else{
            if (s[tmp[start][i+1]].size()==0) cout << s[tmp[start][i]];
            else    cout << s[tmp[start][i]].substr(0, s[tmp[start][i]].size() - relation[tmp[start][i]][tmp[start][i+1]]);
        }
    }
}
*/
