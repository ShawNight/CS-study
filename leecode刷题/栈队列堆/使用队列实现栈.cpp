#include<iostream>
#include<queue>
using namespace std;

class MyStack{
public:
    MyStack(){}
    void push(int x){
        queue<int> temp_data;
        temp_data.push(x);
        while(!_data.empty())
        {
            temp_data.push(_data.front());
            _data.pop();
        }
        while(!temp_data.empty()){
            _data.push(temp_data.front());
            temp_data.pop();
        }
    }
    int pop(){
        int x=_data.front();
        _data.pop();
        return x;
    }
    int top(){
        return _data.front();
    }
    bool empty(){
        return _data.empty();
    }
private:
    queue<int> _data;
};
int main()
{
    MyStack s;
    for(int i=1;i<=5;i++){
        s.push(i);
    }
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}