#include<iostream>
using namespace std;

int main(){
    int arr[6] = {1,3,5,6,7,8};

    for (int i=0;i<6;i++){
        cout<< arr[i]<<endl;
    }
    for (int i=0;i<6;i++){
        cout<< &arr[i]<<endl;
    }

    return 0;
}
