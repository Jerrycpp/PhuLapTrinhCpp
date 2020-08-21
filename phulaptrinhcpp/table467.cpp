#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("table467.inp","r",stdin);
    freopen("table467.out","w",stdout);
    int n;
    scanf("%d\n",&n);
    int size1 = n+2;
    
    int arr1[size1][size1];
    int arr2[n][n];
    for (int i = 0;i<size1;i++){
        for (int j = 0;j<size1;j++) arr1[i][j]=0;
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++) scanf("%d ",&arr1[i][j]);
        scanf("\n");
    }
    for (int i = 1;i<=n;i++){
        for (int j = 1;j<=n;j++){
            arr2[i-1][j-1]=arr1[i][j]+arr1[i-1][j]+arr1[i+1][j]+arr1[i][j-1]+arr1[i][j+1];
           // printf("%d %d %d %d %d\n",arr1[i][j],arr1[i-1][j],arr1[i+1][j],arr1[i][j-1],arr1[i][j+1]);
        }
       // printf("\n");
    }
    printf("%d\n",n);
   // for (int i  =0;i<size1;i++){
     //   for (int j =0;j<size1;j++) printf("%d ",arr1[i][j]);
       // printf("\n");
    //}
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++) printf("%d ",arr2[i][j]);
        printf("\n");
    }
    return 0;
}