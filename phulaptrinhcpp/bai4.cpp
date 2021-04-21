#include <iostream>
#include <string>
using namespace std;

string S;
string arr[100000];

string rev(string s){
    string a = "";
    for (int i = s.size()-1;i>=0;i--){
        a+=s[i];
    }
    return a;
}
bool checkRev(string s){
    if (rev(s)==s) return true;
    else return false;
}
void sort(int l,int r){
    string x = arr[(l+r)/2];
    int i = l;
    int j = r;
    while (i<=j){
        while (arr[i]<x) i++;
        while (arr[j]>x) j--;
        if (i<=j){
            string t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }
    if (i<r) sort(i,r);
    if (l<j) sort(l,j);
}

int main(){
    getline(cin,S);
    string name = "";
    int j = 0;
    for (int i = 0;i<S.size();i++){
        if (S[i]!=' ') name+=S[i];
        else{
            arr[j] = name;
            j++;
            name = "";
        }
    }
    arr[j] = name;
    sort(0,j);
    /*for (int i = 0;i<=j;i++){
        cout <<arr[i] <<endl;
    }*/
    int c1 = 0;
    int c2 = 0;

    for (int i = 0;i<=j;i++){
        if (arr[i]!=arr[i-1] && arr[i] != arr[i+1]) c1++;
        if (checkRev(arr[i])==true) c2++;
    }
    cout <<c1 <<endl <<c2;

}