#include <iostream>
using namespace std;

int n,m;
int a[1001];

void Input(){
    scanf("%d %d\n",&n,&m);
    for (int i = 1;i<=n;i++){
        scanf("%d\n",&a[i]);
    }
}
void sort(int l,int r){
    int x = a[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j) {
            int t = a[i];
            a[i] =a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) sort(i,r);
    if (l<j) sort(l,j);
}
int Max(int l,int r,int base){
    
    while (l<=r){
        int k = (l+r)/2;
        if (a[k]>base) {
            r = k-1;
        }
        else if (a[k]==base || a[k+1]>base){
            return a[k];
        }
        else {
            l = k+1;
        }
    }
    return -1;
}
void XuLi(){
    Input();
    sort(1,n);

    int max = 0;
    int score = 0;
    int least = a[1];
    for (int i = 1;i<=n;i++){
        for (int j = i+1;j<=n;j++){
            int most = m - a[i] - a[j];
            //cout <<most <<endl;
            if (most < least) break;
            
            int last = Max(j+1,n,most);
            if (Max(j+1,n,most)==-1) break;
            
            score = a[i] + a[j] + last;
            if (score > max) {max = score; cout <<a[i] <<" " <<a[j] <<" " <<last <<endl;}
        }
    }
    cout <<max;
}

int main(){
    freopen("ndccard.inp","r",stdin);
    freopen("ndccard.out","w",stdout);
    XuLi(); return 0;
}