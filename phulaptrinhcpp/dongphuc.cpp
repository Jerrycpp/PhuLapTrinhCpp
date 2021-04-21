#include <iostream>
using namespace std;

long long int n,m,x,y,a[10001],b[10001];
void Input(){
    scanf("%lld %lld %lld %lld\n",&n,&m,&x,&y);
    for (int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    scanf("\n");
    for (int i = 1;i<=m;i++){
        scanf("%lld",&b[i]);
    }
}
void QuickSort(long long int arr[],int l,int r){
    long long int x = arr[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (arr[i]<x) i++;
        while (arr[j]>x) j--;
        if (i<=j){
            long long int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) QuickSort(arr,i,r);
    if (l<j) QuickSort(arr,l,j);
}
void XuLi(){
    Input();
    QuickSort(a,1,n);
    QuickSort(b,1,m);
    int c = 0;
    int i = 1; int j = 1;
    while (i<=n && j<=m){
        if (a[i]-x>b[j]) j++;
        else{
            if (a[i]+y<b[j]) i++;
            else{
                c++;
                i++;
                j++;
            }
        }
    }
    cout <<c;
}



int main(){
    freopen("dongphuc.inp","r",stdin);
    freopen("dongphuc.out","w",stdout);
    XuLi(); return 0;
}