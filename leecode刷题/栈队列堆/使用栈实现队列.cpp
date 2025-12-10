#include<iostream>
#include<stack>
using namespace std;
class MyQueue{
public:
    MyQueue(){}
    void push(int x){
        stack<int> temp_data;
        temp_data.push(x);
        while(!_data.empty()){
            temp_data.push(_data.top());
            _data.pop();
        }
        while(!temp_data.empty()){
            _data.push(temp_data.top());
            temp_data.pop();
        }
    }
    int pop(){
        int x= _data.top();
        _data.pop();
        return x;
    }
    int front(){ return _data.top();}
    bool empty(){ return _data.empty(); }
private:
    stack<int> _data;
};
int main()
{
    MyQueue q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }
    while(!q.empty()){
        cout<<q.pop()<<endl;
    }
    return 0;
}