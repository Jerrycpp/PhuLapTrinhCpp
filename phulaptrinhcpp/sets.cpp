#include <iostream>
using namespace std;

struct Doan {
    long long int a;
    long long b;

};
int n;
Doan d[100001];
int arr[100001];
void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%lld %lld\n",&d[i].a,&d[i].b);
    }
}
bool comp(Doan x, Doan y){
    if (x.b>y.b) return true;
    else if (x.b<y.b) return false;
    else if (x.b==y.b&&x.a>y.a) return true;
    else return false;
}
void sort(int l,int r){
    Doan x = d[(l+r)/2];
    int i = l; int j = r;
    while (i<=j){
        while (comp(x,d[i])) i++;
        while (comp(d[j],x)) j--;
        if (i<=j){
            Doan t = d[i];
            d[i] = d[j];
            d[j] = t;
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
    int c = 0;
    c++; 
}

int main(){
    freopen("sets.inp","r",stdin);
    freopen("sets.out","w",stdout);
    XuLi(); return 0;
}