#include <iostream>
#include <cmath>
using namespace std;


long long n;
long long int pt(long long x){
    long long k = x;
    long long c = 0;
    
    while (k%2==0) {
        c = 1;
        k/=2;
    }
    for (int i = 2;i<=sqrt(k);i+=2){
        if (k%i==0) c++;
        while (k%i==0){
            k/=i;
        }
    }
    if (k>2) c+=1;
    return c;
}
void XuLi(){
    scanf("%lld",&n);
    long long max = 0;
    long long maxdi = 0;
    for (long long int i = 2;i<=n;i++){
        if (pt(i) >= maxdi) {
            maxdi = pt(i);
            max = i;
        }
    }
    cout <<max;
}

int main(){
    freopen("mahoa656.inp","r",stdin);
    freopen("mahoa656.out","w",stdout);
    XuLi(); return 0;
}