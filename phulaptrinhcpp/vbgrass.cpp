#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("vbgrass.inp","r",stdin);
    freopen("vbgrass.out","w",stdout);
    int m,n;
    scanf("%d %d\n",&m,&n);
    char arr[1000][1000];
    for (int i = 0;i<m;i++){
        for (int j = 0;j<n;j++) scanf("%c",&arr[i][j]);
        scanf("\n");
    }
    int counter = 0;
    for (int i = 0;i<m;i++){
        for (int j = 0;j<n;j++){
            if (arr[i][j]=='#'&&arr[i-1][j]!='#'&&arr[i][j-1]!='#') ++counter;
            
            
            
        }
    }
    printf("%d",counter);
    return 0;
}