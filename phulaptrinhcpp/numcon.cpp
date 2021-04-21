#include <iostream>
using namespace std;

string arr[101];
int N = 0;
void Input(){
    string a;
    
    while (cin>>a){
        N++;
        arr[N] = a;
    }
}
bool Comp(string x,string y){
    //cout <<x+y <<' ' <<y+x <<endl;
    string a = x+y;
    string b = y+x;
    if (a>b) return true;
    if (a==b && a>b) return true;
    return false;
}
void QuickSort(int l,int r){
    string x = arr[(l+r)/2];
    int i = l;int j = r;
    while (i<=j){
        while (Comp(x,arr[i])) i++;
        while (Comp(arr[j],x)) j--;
        if (i<=j){
            string t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) QuickSort(i,r);
    if (l<j) QuickSort(l,j);
}
void XuLi(){
    Input();
    QuickSort(1,N);
    for (int i = N;i>=1;i--){
        cout <<arr[i];
    }
}
int main(){
    freopen("numcon.inp","r",stdin);
    freopen("numcon.out","w",stdout);
    XuLi(); return 0;
}