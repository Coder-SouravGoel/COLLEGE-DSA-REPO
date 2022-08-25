#include<iostream>
using namespace std;

int multiply(int n, int m){
    if (m == 1){
        return n;
    }
    else{
        return n + multiply(n, m-1);
    }
}
int main()
{
    int n, m;
    cin>>n>>m;

    cout<<multiply(n, m)<<endl;
    return 0;
}