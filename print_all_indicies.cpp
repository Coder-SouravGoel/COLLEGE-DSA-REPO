#include <iostream>
using namespace std;
int allindex(int* arr, int n, int x, int* output){
    if(n==0){
        return 0;
    }

    int smallo=allindex(arr, n-1, x, output);
    if(arr[n]==x){
        output[smallo]=0;
        smallo++;
        return smallo;
    }
    return smallo;
}
int main(){
    int n=0;
    cout << "Enter the size of array: ";
    cin >> n;

    int*arr=new int[n];
    cout << "Enter the elements of array: " << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int x=0;
    cout << "Enter the number to find: ";
    cin >> x;

    int* output=new int[n];
    int size=allindex(arr, n, x, output);

    for(int i=0;i<size;i++){
        cout << output[i] << " " << endl;
    }
    return 0;
}