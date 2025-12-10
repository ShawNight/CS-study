#include<iostream>
#include<vector>
#include<ctime>
using namespace std;
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    result.push_back(vector<int>(1,1));
    for(int i=1;i<numRows;i++){
        vector<int> temp;
        for(int j=0;j<=i;j++){
            int num=0;
            if(j-1>=0)  num+=result[i-1][j-1];
            if(j<i) num+=result[i-1][j];
            temp.push_back(num);
        }
        result.push_back(temp);
    }
    return result;
}
int main(){
    vector<vector<int>> result;
    result=generate(5);
    for(auto c:result){
        for(auto r:c)
        {
            cout<<r<<" ";
        }
        cout<<endl;
    }
}