#include<iostream>
#include<stack>
using namespace std;

class MyStack{
public:
    MyStack(){}
    void push(int x){
        _data.push(x);
        if(_min.empty()||_min.top()>x){
            _min.push(x);
        }else{
            _min.push(_min.top());
        }
    }
    void pop(){
        _min.pop();
        _data.pop();
    }
    int getMin(){ return _min.top();}
    int top(){ return _data.top();}
    bool empty(){return _data.empty();}
private:
    stack<int> _data;
    stack<int> _min;
};
int main()
{
    MyStack s;
    for(int i=1;i<=5;i++){
        s.push(i);
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        cout<<s.getMin()<<endl;
        s.pop();
    }
    return 0;
}