#include<iostream>
#include<vector>
using namespace std;

//递归版
bool binary_search(vector<int> &sort_array,int begin,int end,int target){
    if(begin>end){
        return false;
    }
    int mid=(begin+end)/2;
    if(target==sort_array[mid])
        return true;
    else if(target<sort_array[mid]){
        return binary_search(sort_array,begin,mid-1,target);
    }else{
        return binary_search(sort_array,mid+1,end,target);
    }
}

//循环版
bool binary_search(vector<int> &sort_array,int target){
    int begin=0;
    int end=sort_array.size()-1;
    while(begin<=end){
        int mid=(begin+end)/2;
        if(sort_array[mid]==target){
            return true;
        }else if(sort_array[mid]>target)
        {
            end=mid-1;
        }else{
            begin=mid+1;
        }
    }
    return false;
}
int main(){
    vector<int> sort_array={1,4,7,20,45,77,80,100,200};
    cout<<binary_search(sort_array,20)<<endl;
    return 0;
}