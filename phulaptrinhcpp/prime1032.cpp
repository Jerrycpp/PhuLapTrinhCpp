#include <iostream>
#include <cmath>
using namespace std;
long long T;
bool PTNT(long long num){
    int c = 0;
    long long n = num;
    int count = 0;
    while (n%2==0){
        n/=2;
        c++;
        count++;
        if (count>=2) return false;
    }
    
    for (int i = 3;i<=sqrt(n);i+=2){
        count = 0;
        while (n%i==0){
            c++;
            count++;
            n/=i;
            if (count>=2) return false;
        }
    }
    if (n>1) c++;
    if (c!=2) return false;
    return true;
}

void XuLi(){
    scanf("%lld",&T);
    long long max = 6;
    for (long long int i = 6;i<=T;i++){
        if (PTNT(i)&&i>max) max = i;
    }
    cout <<max;
}

int main(){
    freopen("prime1032.inp","r",stdin);
    freopen("prime1032.out","w",stdout);
    XuLi(); return 0;
}