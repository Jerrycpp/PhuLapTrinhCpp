#include <iostream>
using namespace std;

int n,k;
void XuLi(){
    scanf("%d %d\n",&n,&k);
    bool a[n+1];
    for (int i = 1;i<=n;i++){
        a[i] = true;
    }
    int c = 0;
    for (int i = 1;i<=k;i++){
        for (int j = 1;j<=n;j++){
            if (j%(i+1)==0){
                a[j] ^= 1;
            }
            
        }
    }
    for (int i = 1;i<=n;i++){
        if (a[i]==false) c++;
    }
    cout <<c;
}

int main(){
    freopen("den.inp","r",stdin);
    freopen("den.out","w",stdout);
    XuLi(); return 0;
}