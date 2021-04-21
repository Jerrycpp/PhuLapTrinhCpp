#include <iostream>
using namespace std;


int n;
int a[101];
int b[101];
int sorta[101];
int sortb[101];

int vitri[101];
void sort(int l,int r,int arr[]){
    int x = arr[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i<=j){
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    if (i < r) sort(i,r,arr);
    if (l<j) sort(l,j,arr);
}
void t(int k){
    int t = a[k];
    a[k] = a[k+1];
    a[k+1] = t;

}
void XuLi(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%d ",&a[i]);
    }
    for (int i = 1;i<=n;i++){
        scanf("%d ",&b[i]);
    }
    
    int kq = 0;
    
    for (int i = 1;i<=n;i++){
        vitri[i] = 0;
        for (int j = 1;j<=n;j++){
            if (a[j] == b[i]){
                vitri[i] = j;
                break;
            }
        }
        if (vitri[i] > 0){
            kq = kq + vitri[i] - i;
            for (int j = vitri[i]-1;j>=i;j--){
                t(j);
            }
        }
        else {
            cout <<-1;
            return;
        }
    }
    cout <<kq <<endl;
    for (int i = 1;i<=n;i++){
        for (int j = vitri[i]-1;j>=i;j--){
            cout <<j <<" ";
        }
    }
    
}

int main(){
    freopen("exarray.inp","r",stdin);
    freopen("exarray.out","w",stdout);
    XuLi(); return 0;
}