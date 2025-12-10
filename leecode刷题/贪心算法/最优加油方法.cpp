#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    return a.first>b.first;
}
int get_minimun(int L,int P,vector<pair<int,int>> &stop){ //L为起点到终点的距离，P为起始点的油量,pair<加油站至终点的距离，加油站的油量
    priority_queue<int> Q;  //存储油量的最大堆
    int result=0;           //记录加油的次数
    stop.push_back(make_pair(0,0)); //  将终点作为一个停靠点，添加至stop数组
    sort(stop.begin(),stop.end(),cmp);  //  已停靠点至终点的距离从大到小排序
    for(int i=0;i<stop.size();i++){     //遍历各个停靠点
        int dis=L-stop[i].first;        
        while(!Q.empty()&&P<dis){
            P+=Q.top();
            result++;
            Q.pop();
        }
        if(Q.empty()&&P<dis)
            return -1;
        P=P-dis;
        Q.push(stop[i].second);
    }
    return result;
}
int main(){
    
    return 0;
}