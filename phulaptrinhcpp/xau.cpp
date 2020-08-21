#include <iostream>
#include <string>
using namespace std;

/* char Compare(string x,string y){
    if (x>y) return '>';
    else if (x<y) return '<';
    else return '='; 
}
string match (string x,string y){
    return x+y;
}
int differ(string x,string y){
    return x.length()-y.length();
}
void End(string x,string y){
    int counter = 0;
    for (int i = 0;i<x.length();i++){
        if (x[i]==y.back()) counter++;
    }
    cout <<y.back() <<" " <<counter;
} */

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    freopen("xau.inp","r",stdin);
    freopen("xau.out","w",stdout);
    string a,b;
    fflush(stdin);
    getline(cin, a);
    fflush(stdin);
    getline(cin,b); 
    int countera = a.length();
    int counterb = b.length();
    int soa = (int)a[0]; int sob = (int)b[0];
    if (soa>sob) cout <<">\n";
    else if (soa<sob) cout <<"<\n";
    else cout <<"=\n";
    cout <<a <<" " <<b <<"\n";
    cout <<countera-counterb <<"\n";
    char endb = b[counterb-1]; int counter = 0;
    
    for (int i = 0;i<countera;i++){
        if (a[i]==endb) counter++;
    }
    cout <<endb <<" " <<counter;
    return 0;
    

}