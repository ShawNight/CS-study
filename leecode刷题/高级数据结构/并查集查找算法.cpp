#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class DisjointSet{
public:
    /*
    设置集合数组id[i],初始时每个元素构成一个单元素集合，编号为i的元素的集合i
    */
    DisjointSet(int n){
        for(int i = 0; i < n ; i++){
            _id.push_back(i);
            _size.push_back(1);
        }
        _count = n;
    } 

    int find(int p){
        while(p != _id[p]){
            _id[p] = _id[_id[p]];
            p = _id[p];
        }
        return p;
    }

    void union_(int p, int q){
        int i = find(p);
        int j = find(q);
        if( i == j)
            return;
        if(_size[i] < _size[j]){
            _id[i] = j;
            _size[j] += _size[i];
        }
        else{
            _id[j] = i;
            _size[i] += _size[j];
        }
        _count--;
    }

    void print_set(){
        printf("元素： ");
        for(int i = 0; i < _id.size(); i++){
            printf("%d ",i);
        }
        printf("\n");
        printf("集合： ");
        for(int i = 0; i < _id.size(); i++){
            printf("%d ",_id[i]);
        }
        printf("\n");
    }
    int count(){
        return _count;
    }
private:
    vector<int> _id;
    vector<int> _size;
    int _count;
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        DisjointSet disjoint_set(M.size());
        for(int i=0;i<M.size();i++){
            for(int j=i+1;j < M.size(); j++){
                if (M[i][j]){
                    disjoint_set.union_(i,j);
                }
            }
        }
        return disjoint_set.count();
    }
};
int main()
{
    vector<vector<int>> M={{1,1,0},{1,1,0},{0,0,1}};
    Solution s;
    cout<<s.findCircleNum(M)<<endl;
    return 0;
}