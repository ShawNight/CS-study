#include<iostream>
#include<string>
#include<vector>
using namespace std;
string removeKDigits(string num, int k) {
    int n=num.size();
    if(n<=k) return "0";
    vector<char> stk;
    for(auto &digit:num){
        while(stk.size()>0&&stk.back()>digit&&k>0){
            stk.pop_back();
            k--;
        }
        stk.push_back(digit);
    }
    for(;k>0;k--){
        stk.pop_back();
    }
    string ans="";
    for(int i=0;i<stk.size();i++){
        if(ans.size()==0&&stk[i]=='0'&&i<=stk.size()-1)
            continue;
        ans.push_back(stk[i]);
    }
    return ans;
}
int main(){
    string num="10";
    cout<<removeKDigits(num,2)<<endl;
    return 0;
}