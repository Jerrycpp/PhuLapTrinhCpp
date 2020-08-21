#include <iostream>

using namespace std;

long long int MaxProd(long long int arr[],int n){
long long int max1 = arr[0];long long int max2 = INT8_MIN;
long long int min1 = arr[0];long long int min2 = INT8_MAX;
for (int i = 1;i<n;i++){
if (arr[i]>max1) {max2=max1;max1=arr[i];}
else if (arr[i]>max2){max2=arr[i];}
if (arr[i]<min1) {min2 = min1;min1=arr[i];}
else if (arr[i]<min2){min2=arr[i];}

}
if (max1*max2<min1*min2) return min1*min2;
else return max1*max2;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("maxprod.inp","r",stdin);
    freopen("maxprod.out","w",stdout);
    int sl;
    scanf("%d\n",&sl);
    long long int m[sl];
    for (int i = 0;i<sl;i++) scanf("%lld ",&m[i]);
    printf("%lld",MaxProd(m,sl));
    return 0;
}
