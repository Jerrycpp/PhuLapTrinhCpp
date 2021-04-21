#include <iostream>
using namespace std;

int n;
int arr[100001];

void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%d\n",&arr[i]);
    }
}
void QS(int l,int r){
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
    if (i<r) QS(i,r);
    if (l < j) QS(l,j);
}
int KhacNhau(){
    int c = 1;
    int current = arr[1];
    for (int i = 2;i<=n;i++){
        if (arr[i]!=current) {
            c++;
            current = arr[i];
        }
    }
    return c;
}
int MaxAppNNum(){
    int c = 1; int maxc = 1;
    int number = arr[1]; int maxNum = arr[1];
    for (int i = 2;i<=n;i++){
        if (arr[i]==number) {
            c++;
            
        }
        else {
            
            number = arr[i];
            c = 1;
            
        }
        if (c>maxc) maxc = c,maxNum = arr[i];
    }
    return maxc;
}
void XuLi(){
    Input();
    QS(1,n);
    cout <<KhacNhau() <<endl;
    cout <<MaxAppNNum() <<endl;

}
int main(){
    freopen("thongke.inp","r",stdin);
    freopen("thongke.out","w",stdout);
    XuLi(); return 0;
}