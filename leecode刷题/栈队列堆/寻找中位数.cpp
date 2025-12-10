#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class MediaFinder{
public:
    MediaFinder(){
    }
    void addNum(int num){
        if(big_queue.empty()){
            big_queue.push(num);
            return;
        }
        if(big_queue.size()==small_queue.size()){
            if(big_queue.top()>=num){
                big_queue.push(num);
            }else{
                small_queue.push(num);
            }
        }
        else if(big_queue.size()>small_queue.size()){
            if(num>big_queue.top())
                small_queue.push(num);
            else{
                small_queue.push(big_queue.top());
                big_queue.pop();
                big_queue.push(num);
            }
        }else{
            if(num<small_queue.top())
                big_queue.push(num);
            else{
                big_queue.push(small_queue.top());
                small_queue.pop();
                small_queue.push(num);
            }
        }
    }
    int getMid(){
        if(big_queue.size()>=small_queue.size())
            return big_queue.top();
        else{
            return small_queue.top();
        }
    }
private:
    priority_queue<int,vector<int>,greater<int>>  small_queue;
    priority_queue<int,vector<int>,less<int>>  big_queue;
};

int main(){
    vector<int> q={1,3,4,5,2,3,7,9,8,6,6,10};
    MediaFinder m;
    for(int i=0;i<q.size();i++){
        m.addNum(q[i]);
    }
    cout<<m.getMid()<<endl;
    return 0;
}