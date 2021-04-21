#include <iostream>
using namespace std;

struct keo {
    int chiso;
    long long noidung;
};

int n;
long long m;
keo a[100001];
bool SoSanh(keo a,keo b){
    if (a.noidung > b.noidung) return true;
    else if (a.noidung == b.noidung && a.chiso < b.chiso) return true;
    else return false;
}
void SapXep(int l,int r){
    keo x = a[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (SoSanh(a[i],x)==false) i++;
        while (SoSanh(a[j],x)) j--;
        if (i<=j){
            keo t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) SapXep(i,r);
    if (l<j) SapXep(l,j);
}
void sort(int l,int r){
    int x = a[(l+r)/2].chiso;
    int i = l;
    int j = r;
    while (i<=j){
        while (a[i].chiso<x) i++;
        while (a[j].chiso>x) j--;
        if (i<=j){
            keo t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) sort(i,r);
    if (l<j) sort(l,j);
}
void XuLi(){
    scanf("%d %lld\n",&n,&m);
    for (int i = 1;i<=n;i++){
        scanf("%lld",&a[i].noidung);
        a[i].chiso = i;
    }
    for (long long i = 1;i<=m;i++){
        SapXep(1,n);
        a[1].noidung++;
    }
    sort(1,n);
    for (int i = 1;i<=n;i++){
        cout <<a[i].noidung <<" ";
    }
}


int main(){
    freopen("candy1051.inp","r",stdin);
    freopen("candy1051.out","w",stdout);
    XuLi(); return 0;
}