#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int FindContentChildren(vector<int>& g,vector<int>& s){
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int child=0;
    int cookie=0;
    while(cookie<s.size()&&child<g.size()){
        if(s[cookie]>=g[child])
            child++;
        cookie++;
    }
    return child;
}
int main(){
    
    return 0;
}