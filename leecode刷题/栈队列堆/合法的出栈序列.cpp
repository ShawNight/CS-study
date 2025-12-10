#include<iostream>
#include<queue>
#include<stack>
using namespace std;

bool check_is_valid_order(queue<int> &order){
    stack<int> S;
    int n=order.size();
    for(int i=1;i<=n;i++){
        S.push(i);
        while(!S.empty()&&order.front()==S.top()){
            order.pop();
            S.pop();
        }
    }
    if(S.empty())
        return true;
    else
        return false;
}
int main(){
    queue<int> order=queue<int>({1,2,3,4,5});
    cout<<check_is_valid_order(order)<<endl;
    return 0;
}