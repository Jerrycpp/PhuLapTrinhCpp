#include <iostream>
using namespace std;

bool Prime[1000000];
void FillPrime(){
    for (int i = 0;i<1000000;i++) Prime[i] = true;
    for (int i = 0;i<1000000;i++){
        if (i==0||i==1) Prime[i] = false;
        else if (Prime[i]==true){
            for (int j = 2;j<=999999/i;j++){
                Prime[i*j] = false;
            }
        }
    }
}
int DaoNguoc(int N){
    int neW = 0;
    int Ne = N;
    while (Ne>0){
        int c = Ne%10;
        neW = neW*10+c;
        Ne/=10;
    }
    return neW;
}
int main(){
    FillPrime();
    int p,q;
    cin >>p;
    cin >>q;
    for (int i = p;i<=q;i++){
        if (Prime[DaoNguoc(i)]==true) cout <<i <<endl;
    }
    return 0;
}