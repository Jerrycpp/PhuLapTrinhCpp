#include <iostream>
using namespace std;

int n;
int arr[100001];
int mangdem[100001];
void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    mangdem[1] = arr[1];
    for (int i = 1;i<=n;i++){
        mangdem[i] = mangdem[i-1]+arr[i];
    }
}


void XuLi(){
    Input();
    
    int maxl = 0, maxr = 0,maxd = -1;
    for (int i = 1;i<=n;i++){
        
        int total;
        for (int j = i;j<=n;j++){
            total = mangdem[j] - mangdem[i] + arr[i];
            if (total==0 && j - i > maxd){
                maxl = i;
                maxr = j;
                maxd = j-i;
            }
        }
        
    }
    if (maxr == 0) cout <<-1;
    else cout <<maxl <<" " <<maxr;
}
int main(){
    freopen("szero.inp","r",stdin);
    freopen("szero.out","w",stdout);
    XuLi(); return 0;
}