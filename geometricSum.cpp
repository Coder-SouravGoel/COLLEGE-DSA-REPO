#include<iostream>
#include<math.h>
using namespace std;

double geo_sum(int k){
    if(k == 1){
        return 1.5;
    }

    else{
        return (1/pow(2,k)) + geo_sum(k-1);
    }
}
int main()
{
    int k;
    cin>>k;

    cout<<geo_sum(k);
    return 0;
}