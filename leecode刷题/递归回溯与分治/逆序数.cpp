#include<iostream>
#include<vector>
#include<utility>
using namespace std;
void merge_sort_two_vec(vector<pair<int,int>>& sub_vec1,vector<pair<int,int>> &sub_vec2,vector<pair<int,int>> &vec,vector<int>& count){
    int i=0;
    int j=0;
    while(i<sub_vec1.size()&&j<sub_vec2.size()){
        if(sub_vec1[i].first<=sub_vec2[j].first){
            vec.push_back(sub_vec1[i]);
            count[sub_vec1[i].second]+=j;
            i++;
        }else{
            vec.push_back(sub_vec2[j]);
            j++;
        }
    }
    for(i;i<sub_vec1.size();i++){
        vec.push_back(sub_vec1[i]);
        count[sub_vec1[i].second]+=j;
    }
    for(j;j<sub_vec2.size();j++)
        vec.push_back(sub_vec2[j]);
}

void merge_sort(vector<pair<int,int>> &vec,vector<int>& count){
    if(vec.size()<2){
        return;
    }
    int mid=vec.size()/2;
    vector<pair<int,int>> sub_vec1;
    vector<pair<int,int>> sub_vec2;
    for(int i=0;i<mid;i++)
        sub_vec1.push_back(vec[i]);
    for(int i=mid;i<vec.size();i++)
        sub_vec2.push_back(vec[i]);
    merge_sort(sub_vec1,count);
    merge_sort(sub_vec2,count);
    vec.clear();
    merge_sort_two_vec(sub_vec1,sub_vec2,vec,count);
}
vector<int> countSmaller(vector<int>& nums) {
    vector<pair<int,int>> vec;
    vector<int> count(nums.size(),0);
    for(int i=0;i<nums.size();i++){
        vec.push_back(make_pair(nums[i],i));
    }
    merge_sort(vec,count);
    return count;
}
int main(){
    vector<int> nums={5,2,6,1};
    vector<int> count;
    count=countSmaller(nums);
    for(auto n:count)
        cout<<n<<" ";
    return 0;
}