#include <iostream>
using namespace std;

int n;
int arr[10001];
void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%d\n",&arr[i]);
    }
}
void QuickSort(int l,int r){
    int x = arr[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (arr[i]<x) i++;
        while (arr[j]>x) j--;
        if (i<=j){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) QuickSort(i,r);
    if (l<j) QuickSort(l,j);
}
void XuLi(){
    Input();
    QuickSort(1,n);
    long long int T1 = arr[1]*arr[2]*arr[n];
    long long int T2 = arr[n]*arr[n-1]*arr[n-2];
    if (T1>T2) cout <<T1 <<endl;
    else cout <<T2 <<endl;
}

int main(){
    freopen("tichmax.inp","r",stdin);
    freopen("tichmax.out","w",stdout);
    XuLi(); return 0;
}