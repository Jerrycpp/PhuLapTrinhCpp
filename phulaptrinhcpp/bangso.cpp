#include <iostream>
using namespace std;

int m,n;
int a[102][102];
int mangdem[101][101];
void XuLi(){
    for (int i = 0;i<102;i++){
        for (int j = 0;j<102;j++){
            a[i][j] = 0;
        }
    }
    scanf("%d %d\n",&m,&n);
    for (int i = 1;i<=m;i++){
        for (int j = 1;j<=n;j++){
            scanf("%d ",&a[i][j]);
        }
        scanf("\n");
    }
    for (int i = 1;i<=m-2;i++){
        for (int j = 1;j<=n-2;j++){
            mangdem[i][j] = a[i][j] + a[i+1][j] + a[i+2][j] + a[i][j+1] + a[i+1][j+1] + a[i+2][j+1] + a[i][j+2] + a[i+1][j+2] + a[i+2][j+2];
        }
    }
    int max = 0;
    int maxi,maxj;
    for (int i = 1;i<=m-2;i++){
        for (int j = 1;j<=n-2;j++){
            if (mangdem[i][j]>max) max = mangdem[i][j],maxi = i,maxj = j;
        }
    }
    cout <<max <<endl <<maxi <<" " <<maxj;
}

int main(){
    freopen("bangso.inp","r",stdin);
    freopen("bangso.out","w",stdout);
    XuLi(); return 0;
}