#include <iostream>
using namespace std;

int n;
int mangdem[100001];
int a[50001],b[50001];
void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=2*n;i++) mangdem[i] = 0;
    for (int i = 1;i<=n;i++){
        int x;
        scanf("%d\n",&x);
        mangdem[x] = 1;
    }
    int j = 1; int m = 1;
    for (int i = 1;i<=2*n;i++){
        if (mangdem[i]==0) {b[j] = i; j++;}
        else{
            a[m] = i; m++;
        }
    }
}
void XuLi(){
    Input();
    int c = 0; int i = 1,j = 1;
    /*for (int i = 1;i<=n;i++){
        cout <<a[i] <<" " <<b[i] <<endl;
    }*/
    while (j<=n && i <= n){
        if (b[j]>a[i]){
            i++;
            c++;
        }
        j++;
    }
    cout <<c;
}

int main(){
    freopen("danhbai.inp","r",stdin);
    freopen("danhbai.out","w",stdout);
    XuLi(); return 0;
}