#include <iostream>
using namespace std;


long long n;
long long k;
long long pow(long long base,long long expo){
    if (expo = 0) return 1;
    long long s = 1;
    for (int i = 1;i<=expo;i++){
        s*=base;
    }
    return s;
}
void XuLi(){
    scanf("%lld %lld\n",&n,&k);
    long long i = 1;
    while (true){
        long long power = pow(k,i);
        if (power>n){
            long long res = (n*(k-1)*power)/(power-1);
            cout <<res <<endl;
            return;
        }
        i++;
    }
}

int main(){
    freopen("cafe.inp","r",stdin);
    freopen("cafe.out","w",stdout);
    XuLi(); return 0;
}