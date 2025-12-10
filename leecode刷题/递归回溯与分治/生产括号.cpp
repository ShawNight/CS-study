#include<iostream>
#include<vector>
#include<string>
using namespace std;
void generate(int i,int n,int state,string temp,vector<string>& result){
    if(state<0){
        return;
    }
    if(i==2*n){
        if(state==0)
            result.push_back(temp);
        return;
    }
    generate(i+1,n,state+1,temp+'(',result);
    generate(i+1,n,state-1,temp+')',result);

}
vector<string> generateParenthesis(int n) {
    vector<string> result;
    string temp="";
    int state=0;
    generate(0,n,state,temp,result);
    return result;
}
int main(){
    vector<string> result;
    result=generateParenthesis(3);
    for(auto s:result)
        cout<<s<<endl;
    return 0;
}