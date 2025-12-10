#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool generate(int i,vector<int>& matchsticks,int target,int bucket[]){
    if(i==matchsticks.size()){
        return bucket[0]==target&&bucket[1]==target&&bucket[2]==target&&bucket[3]==target;
    }
    for(int j=0;j<4;j++){
        if(bucket[j]+matchsticks[i]>target){
            continue;
        }
        bucket[j]=bucket[j]+matchsticks[i];
        if(generate(i+1,matchsticks,target,bucket)){
            return true;
        }
        bucket[j]=bucket[j]-matchsticks[i];
    }
    return false;

}

// bool makesquare(vector<int>& matchsticks) {
//     int sum=0;
//     for(int i=0;i<matchsticks.size();i++){
//         sum+=matchsticks[i];
//     }
//     if(sum%4!=0)
//         return false;
//     int len=sum/4;
//     sort(matchsticks.begin(),matchsticks.end(),[](const int &lhs,const int &rhs){
//         return lhs>rhs;
//     });
//     int bucket[4]={0};
//     return generate(0,matchsticks,len,bucket);
// }

bool makesquare(vector<int>& matchsticks) {
    if(matchsticks.size()<4){
        return false;
    }
    int sum=0;
    for(int i=0;i<matchsticks.size();i++){
        sum+=matchsticks[i];
    }
    if(sum%4!=0)
        return false;
    int target=sum/4;
    vector<int> ok_subset; //所有满足条件的一个边的集合
    vector<int> ok_half; //所有满足条件的两个边代表的集合
    int all=1<<matchsticks.size();
    for(int i=0;i<all;i++){
        int sum=0;
        for(int j=0;j<matchsticks.size();j++){
            if(i&(1<<j)){
                sum+=matchsticks[j];
            }
        }
        if(sum==target)
            ok_subset.push_back(i);
    }
    for(int i=0;i<ok_subset.size();i++){
        for(int j=i+1;j<ok_subset.size();j++){
            if((ok_subset[i]&ok_subset[j]) == 0){
                ok_half.push_back(ok_subset[i]|ok_subset[j]);
            }
        }
    }
    for(int i=0;i<ok_half.size();i++){
        for(int j=i+1;j<ok_half.size();j++){
            if((ok_half[i]&ok_half[j])==0)
                return true;
        }
    }
    return false;
}
int main(){
    vector<int> matchsticks={1,1,2,2,2};
    cout<<makesquare(matchsticks)<<endl;
    return 0;
}