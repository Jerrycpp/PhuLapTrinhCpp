#include <iostream>
using namespace std;

long long n;
void Input(){
    scanf("%lld\n",&n);
}
long long gcd(long long a, long long b){
    if (a==0) return b;
    if (b==0) return a;
    if (a>b) return gcd(b,a-b);
    return gcd(a,b-a);
}
long long lcm(long long a,long long b){
    return a*b/gcd(a,b);
}
void XuLi(){
    Input();
    long long max = 0;
    for (int i = 1;i<=n/2;i++){
        if (lcm(i,n-i)>max) max = lcm(i,n-i);
    }
    cout <<max;
}

int main(){
    freopen("pairlcm.inp","r",stdin);
    freopen("pairlcm.out","w",stdout);
    XuLi(); return 0;
}