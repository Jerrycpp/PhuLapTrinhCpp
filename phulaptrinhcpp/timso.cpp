#include <iostream>
using namespace std;

int n;
long long int arr[100001];

void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%lld\n",&arr[i]);
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
    if (j>l) QuickSort(l,j);
}

void XuLi(){
    Input();
    QuickSort(1,n);
    cout <<arr[1] <<" " <<arr[n] <<endl;
    for (int i = 1;i<=n-1;i++){
    	for (int j = arr[i]+1;j<=arr[i+1]-1;j++) cout <<j <<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("timso.inp","r",stdin);
    freopen("timso.out","w",stdout);
    XuLi(); return 0;
}