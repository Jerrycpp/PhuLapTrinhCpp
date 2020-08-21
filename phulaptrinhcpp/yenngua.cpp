#include <iostream>
#include <climits>
using namespace std;
int m,n;
int A[1000][1000];

void Nhap(){
    scanf("%d %d\n",&m,&n);
    for (int i = 0;i<m;i++){
        for (int j = 0;j<n;j++) scanf("%d ",&A[i][j]);
        scanf("\n");
    }
}
bool MinHang(int a,int b){
    
    for (int i = 0;i<n;i++){
        if (A[a][i]<A[a][b]) return false;
    }
    return true;
    
}
bool MaxCot(int a, int b){
    for (int i = 0;i<m;i++){
        if (A[i][b]>A[a][b]) return false;
    }
    return true;
}

void XuLi(){
    for (int i = 0;i<m;i++){
        for (int j = 0;j<n;j++){
            if (MinHang(i,j)&&MaxCot(i,j)) {
                printf("%d %d\n",i+1,j+1); 
            }
        }
    }

}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("yenngua.inp","r",stdin);
    freopen("yenngua.out","w",stdout);
    Nhap();
    XuLi();
    return 0;
}