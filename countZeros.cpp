#include<iostream>
using namespace std;

int zeros(int n){
    if (n == 0) {
        return 0;
    }
    else if (n%10 == 0){
        return 1 + zeros(n/10);
    }
    else{
        return zeros(n/10);
    }
}
int main()
{
    int n;
    cin>>n;

    cout<<zeros(n);
    return 0;
}