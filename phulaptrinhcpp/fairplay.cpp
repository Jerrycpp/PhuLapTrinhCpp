#include <iostream>
using namespace std;

int n;
int a[100001];
int b[100001];
void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("\n");
    for (int i = 1;i<=n;i++){
        scanf("%d",&b[i]);
    }
}
void QuickSort(int arr[],int l,int r){
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
    if (i<r) QuickSort(arr,i,r);
    if (l<j) QuickSort(arr,l,j);
}
void XuLi(){
    Input();
    QuickSort(a,1,n);
    QuickSort(b,1,n);
   /*for (int i = 1;i<=n;i++) cout <<a[i] <<endl;
    for (int i = 1;i<=n;i++) cout <<b[i] <<endl; */
    int c = 0; int i = 1; int j = 1;
    while (i <= n && j<=n){
        if (b[j]>a[i]){
            c++;
            i++;
            j++;
        }
        else j++;
    } 
    cout <<c;
}

int main(){
    freopen("fairplay.inp","r",stdin);
    freopen("fairplay.out","w",stdout);
    XuLi(); return 0;
}