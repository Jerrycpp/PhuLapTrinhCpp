#include <iostream>
using namespace std;

int main(){
    long long int n;
    cin >>n;
    if (n<=1) {
        cout <<0;
        return 0;
    }
    long long socaibattay = ((n-1)*n)/2;
    cout <<socaibattay;
    return 0;

}