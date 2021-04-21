#include <iostream>
using namespace std;

struct Doan {
    int d,c;
};

int n;
Doan a[10001];
void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%d %d\n",&a[i].d,&a[i].c);
    }
}
void sort(int l,int r){
    Doan x = a[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (a[i].d<x.d) i++;
        while (a[j].d>x.d) j--;
        if (i<=j){
            Doan t = a[i];
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
    Input();
    sort(1,n);
    int max = 0;
    int s;
    int x = a[1].d;
    int y = a[1].c;
    for (int i = 2;i<=n;i++){
        if (a[i].d<y){
            if (a[i].c>y){
                y = a[i].c;
            }
        }
        else{
            s = y-x;
            if (s>max) max = s;
            x = a[i].d;
            y = a[i].c;
        }
    }
    s = y-x;
    if (s>max) max = s;
    cout <<max;
}
int main(){
    freopen("doanphu943.inp","r",stdin);
    freopen("doanphu943.out","w",stdout);
    XuLi(); return 0;
}