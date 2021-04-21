#include <iostream>
using namespace std;

struct khoang {
    
    long long int tr;
    long long int ph;
};
int n;
khoang a[100001];

void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%lld %lld\n",&a[i].tr,&a[i].ph);
    }
}
bool ss(khoang a, khoang b){
    if (a.tr<b.tr) return true;
    else return false;
}
void sort(int l,int r){
    khoang x = a[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (ss(a[i],x)==true) i++;
        while (ss(x,a[j])) j--;
        if (i<=j){
            khoang t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) sort(i,r);
    if (l<j) sort(l,j);
}
int tknp(int l,int r,khoang base){
    int res = 0;
    while (l<=r){
        int k = (l+r)/2;
        if (a[k].tr < base.ph) {
            res = k;
            l = k+1;
        }
        else r = k-1;
    }
    return res;
}
void XuLi(){
    Input();
    sort(1,n);
    /*for (int i = 1;i<=n;i++){
        cout <<a[i].tr <<" " <<a[i].ph <<endl;
    }*/
    int c = 0;
    for (int i = 1;i<=n;i++){
        int j = tknp(i+1,n,a[i]);
        if (j!=0) c+=(j-i);
    }
    cout <<c;
}
int main(){
    freopen("intervals.inp","r",stdin);
    freopen("intervals.out","w",stdout);
    XuLi(); return 0;
}