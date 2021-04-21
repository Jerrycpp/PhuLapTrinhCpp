#include <iostream>
using namespace std;

long long int n;
bool a[81];
long long prime[81];
int limit;
void TaoPrime(){
    for (int i = 1;i<=80;i++){
        a[i] = true;
    }
    for (int i = 1;i<=80;i++){
        if (i==1) a[i] = false;
        else if (a[i]==true){
            for (int j = i*i;j<=80;j+=i){
                a[j] = false;
            }
        }
    }
    limit = 0;
    for (long long i = 2;i<=80;i++){
        if (a[i]==true) {
            limit++;
            prime[limit] = i;
        }
    }
}


void XuLi(){
    scanf("%lld\n",&n);
    long long c = 1;
    TaoPrime();
    for (int i = 1;i<=limit;i++){
        long long p = prime[i];
        long long exp = 0;
        while (p<=n){
            exp+=n/p;
            p*=prime[i];
        }
        c *= (exp+1);
    }
    cout <<c-1;
}

int main(){
    freopen("divisors.inp","r",stdin);
    freopen("divisors.out","w",stdout);
    XuLi();
    return 0;
}