#include <iostream>
#include <cmath>
using namespace std;

int n;
int a[51][51];
int b[51][51];

void XuLi(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
        scanf("\n");
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            if (a[i][j] > 0) b[i][j] = a[i][j];
            else {
                int maxdis = n;
                int max = 0;
                for (int k = 1;k<=n;k++){
                    if (a[i][k] > 0){
                        int dis = abs(j-k);
                        if (dis < maxdis) {
                            maxdis = dis;
                            max = a[i][k];
                        }
                        else if (dis == maxdis && a[i][k] > max) max = a[i][k];
                    }
                    else if (a[k][j] > 0){
                        int dis = abs(i-k);
                        if (dis < maxdis) {
                            maxdis = dis;
                            max = a[k][j];
                        }
                        else if (dis == maxdis && a[k][j] > max) max = a[k][j];
                    }
                }
                b[i][j] = max;
            }
        }
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            cout <<b[i][j] <<" ";
        }
        cout <<endl;
    }
}

int main(){
    freopen("nztable.inp","r",stdin);
    freopen("nztable.out","w",stdout);
    XuLi(); return 0;
}