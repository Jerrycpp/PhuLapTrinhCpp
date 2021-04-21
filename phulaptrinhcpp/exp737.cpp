#include <iostream>
using namespace std;

int n;
long long a[100001];
void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%lld ",&a[i]);
    }
}
void XuLi(){
    Input();
    long long maxchan = 2;
    long long minle = 1;
    for (int i = 4;i<=n;i+=2){
        if (a[i]>a[maxchan]) maxchan = i;
    }
    for (int i =3;i<=n;i+=2){
        if (a[i]<a[minle]) minle = i;
    }
    if (a[maxchan]>a[minle]) {
        long long t = a[maxchan];
    a[maxchan] = a[minle];
    a[minle] = t;
    }
    long long s = 0;
    for (int i = 1;i<=n;i++){
        if (i%2!=0) s+=a[i];
        else {
            s-=a[i];
        }
    }
    cout <<s;
}

int main(){
    freopen("exp737.inp","r",stdin);
    freopen("exp737.out","w",stdout);
    XuLi();
    return 0;
}