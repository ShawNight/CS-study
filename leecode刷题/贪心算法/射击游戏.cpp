#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>
using namespace std;
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(),points.end(),[](const vector<int> &lhs,const vector<int> &rhs){
        return lhs[0]<rhs[0];
    });
    int min=points[0][0];
    int max=points[0][1];
    int counts=1;
    for(int i=1;i<points.size();i++){
        if(points[i][0]>min){
            min=points[i][0];
        }
        if(points[i][1]<max){
            max=points[i][1];
        }
        if(min>max){
            counts++;
            max=points[i][1];
        }
    }
    return counts;
}
int main(){
    vector<vector<int>> points={{10,16},{2,8},{1,6},{7,12}};
    cout<<findMinArrowShots(points)<<endl;
    return 0;
}