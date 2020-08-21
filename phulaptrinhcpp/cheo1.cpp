#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("cheo1.inp","r",stdin);
    freopen("cheo1.out","w",stdout);
    int n = 0;
    scanf("%d\n",&n);
    int arr[*(&n)][*(&n)];
    
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            scanf("%d ",&arr[i][j]);
        }
        scanf("\n");
    }

    int k = n-1; int sum = 0;
    for (int i = 0;i<n;i++){
        sum += arr[i][k];
        k--;
    }
    printf("%d",sum);
    return 0;


}