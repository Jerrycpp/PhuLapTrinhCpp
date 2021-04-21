#include <iostream>
using namespace std;

int n;
int arr[1000001];
int Maxl[1000001];
int Minl[1000001];
int Maxr[1000001];
int Minr[1000001];
void Input(){
    scanf("%d\n",&n);
    for (int i = 1;i<=n;i++){
        scanf("%d ",&arr[i]);
    }
}
void TaoMangMaxMin(){
    Maxl[1] = arr[1];
    Minl[1] = arr[1];
    for (int i = 2;i<=n;i++){
        if (Maxl[i-1]>arr[i]) Maxl[i] = Maxl[i-1];
        else{
            Maxl[i] = arr[i];
        }
        if (Minl[i-1]<arr[i]) Minl[i] = Minl[i-1];
        else {
            Minl[i] = arr[i];
        }
    }
    Maxr[n] = arr[n];
    Minr[n] = arr[n];
    //cout <<Minl[n] <<endl;
    for (int i = n-1;i>=1;i--){
        if (Maxr[i+1]>arr[i]) Maxr[i] = Maxr[i+1];
        else Maxr[i] = arr[i];
        if (Minr[i+1]<arr[i]) Minr[i] = Minr[i+1];
        else Minr[i] = arr[i];
    }
    

}

void XuLi(){
    Input();
    TaoMangMaxMin();
    long long Max = 0;
    /*for (int i = 1;i<=n;i++){
        cout <<Maxl[i] <<" ";
    }
    cout <<endl;
    for (int i = 1;i<=n;i++){
        cout <<Minl[i] <<" ";
    }
    cout <<endl;
    for (int i = 1;i<=n;i++){
        cout <<Maxr[i] <<" ";
    }
    cout <<endl;
    for (int i = 1;i<=n;i++){
        cout <<Minr[i] <<" ";
    }
    cout <<endl;*/
    for (int i = 2;i<=n-1;i++){
        //cout <<Maxl[i] <<" " <<arr[i] <<" " <<Minr[i] <<endl;
        long long tichduong = (Maxl[i]-arr[i])*(arr[i]-Minr[i]);
        //cout <<Minl[i] <<" " <<arr[i] <<" " <<Maxr[i] <<endl;
        long long ticham = (Minl[i]-arr[i])*(arr[i]-Maxr[i]);
        long long tich;
        //cout <<tichduong <<" " <<ticham <<endl;
        if (tichduong>ticham) tich = tichduong;
        else tich = ticham;
        if (tich>Max) Max = tich;
    }
    cout <<Max;
}

int main(){
    freopen("maxenergy.inp","r",stdin);
    freopen("maxenergy.out","w",stdout);
    XuLi();
    return 0;
}