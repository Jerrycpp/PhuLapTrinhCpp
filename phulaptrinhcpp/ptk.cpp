#include <iostream>
#include <cstdlib>
using namespace std;

int arr[10000001];
int d[1000001];
int n,m,k;
void Input()
{
    scanf("%d %d %d\n",&n,&m,&k);
    for (int i = 1; i<=n; i++)
    {
        if (i==1||i==2) arr[i] = 1;
        else
        {
            arr[i] = (arr[i-1]+arr[i-2])%m;
        }
    }
}


void QuickSort(int l,int r)
{
    int x = arr[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j)
    {
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
void Dem(){
    int x = 1, y = 1,z;
    for (int i = 3;i<=n;i++){
        z = (x+y)%m;
        d[z]++;
        y = x;
        x = z;
    }
    int r = 0, i = -1;
    while (r<k){
        i++;
        r+=d[i];
        if (r>k) {cout <<i; return;}
    }
    cout <<i-1;
}
void XuLi()
{
    Input();
    if (n<=1000000){
        QuickSort(1,n);
        cout <<arr[k];
    }
    else{
        Dem();
    }
}
int main()
{
    freopen("ptk.inp","r",stdin);
    freopen("ptk.out","w",stdout);
    XuLi();
    return 0;
}
