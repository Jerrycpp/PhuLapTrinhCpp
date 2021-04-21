#include <iostream>
using namespace std;


long long n,L;
long long a[100002];
void sort(int l,int r){
    int x = a[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j){
            long long t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) sort(i,r);
    if (j>l) sort(l,j);
}
void XuLi(){
    scanf("%lld %lld\n",&n,&L);
    for (int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(1,n);
    float M = float(a[1]);
    a[0] = 0;

    for (int i = 2;i<=n;i++){
        long long dis = a[i] - a[i-1];
        float d = float(dis)/2;
        if (d>M) M = d;
    }
    long long dis = L - a[n];
    float d = float(dis)/2;
    if (d>M) M = d;
    printf("%.2f",M);
}

int main(){
    freopen("denduong.inp","r",stdin);
    freopen("denduong.out","w",stdout);
    XuLi(); return 0;
}