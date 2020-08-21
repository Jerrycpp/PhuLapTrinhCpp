#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("bangdx.inp","r",stdin);
    freopen("bangdx.out","w",stdout);
    int n = 5;
    int arr[n][n];
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++) scanf("%d ",&arr[i][j]);
        scanf("\n");
    }
    int x = INT_MAX;int y = INT_MAX;
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            if (arr[i][j]==1){
                x = i;
                y = j;
                break;
            }
        }
        if (x<6&&y<6) break;
    }
    x++;y++;
    int move = abs(x-3)+abs(y-3);
    
    printf("%d",move);
    return 0;

}