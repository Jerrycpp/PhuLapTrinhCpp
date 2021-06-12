#include <iostream>
using namespace std;

int main(){
    long long first = 0;
    long long sec = 1;
    long long sum = 0;
    while (sec <= 4000000){
        long long t = first;
        first = sec;
        sec+=t;
        if (sec%2==0) sum+=sec;
    }
    cout <<sum <<endl;
    return 0;

}