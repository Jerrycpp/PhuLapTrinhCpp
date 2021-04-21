#include <iostream>
using namespace std;

void sort(int a[],int l,int r){
    int x = a[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) sort(a,i,r);
    if (l<j) sort(a,l,j);
}

int main(){
    int arr[1000001];
    int n;
    cin >>n;
    for (int i = 1;i<=n;i++){
        cin >>arr[i];
    }
    sort(arr,1,n);
    int maxsize = arr[n];
    int c = 1;
    int maxa = maxsize*c;
    int cura = c*c;
    
    for (int i = n-1;i>=1;i--){
        if (arr[i]<maxsize) maxsize = arr[i];
        maxa = maxsize*c;
        cura = c*c;
        if (cura>=maxa) break;
        c++;
    }
    cout <<c;
    return 0;
}