#include <iostream>
using namespace std;

long long int n,c;
long long int a[100001][3];
void Input(){
    scanf("%lld %lld\n",&n,&c);
    for (int i = 1;i<=n;i++){
        scanf("%lld %lld\n",&a[i][1],&a[i][2]);
    }
}
void swap(long long int &a,long long int &b){
    long long int t = a;
    a = b;
    b = t;
}
void SpecialSort(int l,int r){
    long long int x = a[(l+r)/2][1];
    int i = l;
    int j = r;
    while (i<=j){
        while (a[i][1]<x) i++;
        while (a[j][1]>x) j--;
        if (i<=j){
          swap(a[i][1],a[j][1]);
          swap(a[i][2],a[j][2]);
          i++;
          j--;  
        }
    }
    if (i<r) SpecialSort(i,r);
    if (l<j) SpecialSort(l,j);
}

void XuLi(){
    Input();
    SpecialSort(1,n);
    int count = 0;
    for (int i = 1;i<=n;i++){
        if (a[i][1]<=c){
            count++;
            c+=a[i][2];
        }
    }
    cout <<count;
}

int main(){
    freopen("olympic.inp","r",stdin);
    freopen("olympic.out","w",stdout);
    XuLi(); return 0;
}