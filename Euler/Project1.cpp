#include <bits/stdc++.h>
using namespace std;

int main(){
    const int N = 1000;
    int s = 0;
    for (int i = 3;i<N;i++){
        if (i%3==0 || i%5==0) s+=i;
    }
    cout <<s <<endl;
    return 0;
}