#include <iostream>
using namespace std;


long long sodao(long long a){
    long long n = a;
    long long k = 0;
    while (n>0){
        k = k*10+(n%10);
        n/=10;
    }
    return k;
}
bool checkDoiXung(long long a){
    if (sodao(a)==a) return true;
    return false;
}
int main(){
    long long n;
    long long c = 0;
    cin >>n;
    while (checkDoiXung(n)==false){
        c++;
        n+=sodao(n);
    }
    cout <<"So doi xung = " <<n <<endl;
    cout <<"So lan bien doi = " <<c <<endl;
    return 0;
}