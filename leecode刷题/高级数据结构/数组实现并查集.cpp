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
        }
    } 

    int find(int p){
        return _id[p];  //查询元素p属于哪个集合直接返回id[p]
    }

    void union_(int p, int q){
        int pid = find(p);
        int qid = find(q);
        if ( pid == qid ){
            return;
        }
        for (int i = 0; i < _id.size(); i++){   //将所有属于pid的集合全部改为qid的集合
            if (_id[i] == pid){
                _id[i] = qid;
            }
        } 
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

private:
    vector<int> _id;
};
int main()
{
    DisjointSet disjoint_set(8);
    disjoint_set.print_set();
    printf("Union(0,5)\n");
    disjoint_set.union_(0,5);
    disjoint_set.print_set();
    printf("Find(0) = %d ,Find(5) = %d\n",disjoint_set.find(0),disjoint_set.find(5));
    printf("Find(2) = %d ,Find(5) = %d\n",disjoint_set.find(2),disjoint_set.find(5));
    disjoint_set.union_(2,4);
    disjoint_set.print_set();
    disjoint_set.union_(0,4);
    disjoint_set.print_set();
    printf("Find(2) = %d ,Find(5) = %d\n",disjoint_set.find(2),disjoint_set.find(5));
    return 0;
}