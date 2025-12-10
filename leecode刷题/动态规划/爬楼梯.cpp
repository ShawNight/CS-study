#include<iostream>
#include<vector>
using namespace std;

int climbStairs(int n) {
    if(n==1)  return 1;
    if(n==2)  return 2;
    vector<int> f(n,0);
    f[0]=1;
    f[1]=2;
    for(int i=2;i<n;i++)
        f[i]=f[i-1]+f[i-2];
    return f[n-1];

}
int main(){
    cout<<climbStairs(3)<<endl;
    return 0;
}