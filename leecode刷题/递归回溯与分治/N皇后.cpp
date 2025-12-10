#include<iostream>
#include<vector>
#include<string>
using namespace std;

void generate(int k,int n,vector<int> &temp,vector<string> &mark,vector<vector<string>> &result){
    if(k==n){
        result.push_back(mark);
        return;
    }
    for(int i=0;i<n;i++){
        int state=0;
        for(int j=0;j<temp.size();j++){
            if(j-k==i-temp[j]||i==temp[j]||j-k==temp[j]-i){
                state=1;
                break;
            }
        }
        if(state==0){
            temp.push_back(i);
            mark[k][i]='Q';
            generate(k+1,n,temp,mark,result);
            mark[k][i]='.';
            temp.pop_back();
        }
    }
}
vector<vector<string>> searchResult(int n){
    vector<string> mark;
    for(int i=0;i<n;i++){
        string s="";
        for(int j=0;j<n;j++){
            s+='.';
        }
        mark.push_back(s);
    }
    vector<int> temp;
    vector<vector<string>> result;
    generate(0,n,temp,mark,result);
    return result;
}
int main(){
    vector<vector<string>> result;
    result=searchResult(4);
    cout<<result.size()<<endl;
    for(auto r:result){
        cout<<"___________________"<<endl;
        for(auto s:r)
            cout<<s<<endl;
        cout<<"___________________"<<endl;
    }
    return 0;
}