#include <iostream>
using namespace std;

int n,m;
int a[501][501];
int b[501][501];
bool prime[100001];

void TaoSang(){
    for (int i = 1;i<=100000;i++){
        prime[i] = true;
    }
    for (int i = 1;i<=100000;i++){
        if (i==1) prime[i] = false;
        else if (prime[i] == true){
            for (int j = 2;j<=100000/i;j++){
                prime[i*j] = false;
            }
        }
    }
}
int sont(int base){
    if (prime[base]) return base;
    for (int i = base;i<=100000;i++){
        if (prime[i]==true) return i; 
    }
    return -1;
}
void Input(){
    scanf("%d %d\n",&n,&m);
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            scanf("%d ",&a[i][j]);
        }
        
    }
}
void TaoMangB(){
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            b[i][j] = sont(a[i][j])-a[i][j];
        }
    }
}
void XuLi(){
    Input();
    TaoSang();
    TaoMangB();
    /*for (int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){
            cout <<b[i][j] <<" ";
        }
        cout <<endl;
    }*/
    int s;
    int Min = 0;
    for (int j = 1;j<=m;j++){
        Min+=b[1][j];
    }
    for (int i = 2;i<=n;i++){
        s = 0;
        for (int j = 1;j<=m;j++){
            s+=b[i][j];
        }
        //cout <<s <<endl;
        if (s<Min) Min = s;
    }
    for (int j = 1;j<=m;j++){
        s = 0;
        for (int i = 1;i<=n;i++){
            s+=b[i][j];
        }
        //cout <<s <<endl;
        if (s<Min) Min = s;
    }
    cout <<Min;
}
int main(){
    freopen("pmatrix.inp","r",stdin);
    freopen("pmatrix.out","w",stdout);
    XuLi();
    return 0;
}