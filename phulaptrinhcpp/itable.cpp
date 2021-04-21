#include <iostream>
using namespace std;


int n,m;
char a[1001][1001];
void Input(){
    scanf("%d %d\n",&n,&m);
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            scanf("%c",&a[i][j]);
        }
        scanf("\n");
    }
}
bool CheckRaNgoai(int hang,int cot){
    int i = hang;
    int j = cot;
    if (i==1 && a[i][j]=='N') return false;
    else if (i==1 && a[i][j]=='S') return true;
    if (i==n && a[i][j]=='S') return false;
    else if (i==n && a[i][j]=='N') return true;
    if (j==1 && a[i][j]=='W') return false;
    else if (j==1 && a[i][j]=='E') return true;
    if (j==m&&a[i][j]=='E') return false;
    else if (j==m&&a[i][j]=='W') return true;
    if (a[i][j] = 'E') return CheckRaNgoai(i,j+1);
    else if (a[i][j] = 'W') return CheckRaNgoai(i,j-1);
    else if (a[i][j] = 'N') return CheckRaNgoai(i-1,j);
    else return CheckRaNgoai(i+1,j);

}
void XuLi(){
    Input();
    int c = 0;
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            if (CheckRaNgoai(i,j)==true) c++;
        }
    }
    cout <<c;
}

int main(){
    freopen("itable.inp","r",stdin);
    freopen("itable.out","w",stdout);
    XuLi(); return 0;
}