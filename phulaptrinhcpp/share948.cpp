#include <iostream>
#include <cmath>
using namespace std;
struct hs {
    long long int money;
    int tt;
};

int n;
long long int m;
hs arr[100001];
long long int kq[100001];

void Sort(int l,int r){
    long long int x = (arr[l].money+arr[r].money)/2;
    int i = l;
    int j = r;
    while (i<=j){
        while (arr[i].money<x) i++;
        while (arr[j].money>x) j--;
        if (i<=j){
            hs t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) Sort(i,r);
    if (l<j) Sort(l,j);
}
void XuLi(){
    long long int total = 0;
    scanf("%d %lld\n",&n,&m);
    for (int i = 1;i<=n;i++){
        scanf("%lld ",&arr[i].money);
        arr[i].tt = i;
        total+=arr[i].money;
    }
    Sort(1,n);
    if (total<m) {
        cout <<-1;
        return;
    }
    for (int i = 1;i<=n;i++){
        long long int tb = m/(n+1-i);

        if (arr[i].money<tb){
            kq[arr[i].tt] = arr[i].money;
            m-=arr[i].money;
        }
        else{
            kq[arr[i].tt] = tb;
            m-=tb;
        }
    }
    for (int i = 1;i<=n;i++){
        cout <<kq[i] <<" ";
    }
}


int main(){
    freopen("share948.inp","r",stdin);
    freopen("share948.out","w",stdout);
    XuLi(); return 0;
}