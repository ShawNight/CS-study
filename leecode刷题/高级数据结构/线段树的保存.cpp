#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
void build_segment_tree(vector<int> &value,vector<int> &nums,int pos,int left,int right){
    if(left == right){
        value[pos] = nums[left];
        return;
    }
    int mid = (left + right)/2;
    build_segment_tree(value, nums, pos * 2 + 1, left, mid);
    build_segment_tree(value, nums, pos * 2 + 2, mid+1, right);
    value[pos] = value[pos*2+1] + value[pos*2 +2];

}

//线段树的遍历
void print_segment_tree(vector<int> &value,int pos, int left, int right, int layer){
    for(int i = 0; i < layer; i++){
        printf("---");
    }
    printf("{%d %d}{%d}: %d\n",left,right,pos,value[pos]);
    int mid = (left + right)/2;
    print_segment_tree(value,pos*2+1,left,mid,layer+1);
    print_segment_tree(value,pos*2+2,mid+1,right,layer+1);
}

//线段树求和
int sum_range_segment_tree(vector<int> &value,int pos,int left, int right,int qleft,int qright){
    if( qleft > right || qright < left){
        return  0;
    }
    if( qleft <= left &&qright >=right){
        return value[pos];
    }
    int mid = (left +right)/2;
    return sum_range_segment_tree(value,pos*2+1,left,mid,qleft,qright)+sum_range_segment_tree(value,pos*2+2,mid+1,right,qleft,qright);

}

//线段树更新
void update_segment_tree(vector<int> &value,int pos,int left,int right,int index,int new_value){
    if( left == right &&left == index){
        value[pos] = new_value;
        return;
    }
    int mid = (left+right)/2;
    if( index <= mid){
        update_segment_tree(value,pos*2+1,left,mid,index,new_value);
    }
    else{
        update_segment_tree(value,pos*2+2,mid=1,right,index,new_value);
    }
    value[pos] = value[pos*2+1] + value[pos*2 + 2];
}
int main(){
    return 0;
}