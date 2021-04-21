#include <iostream>
#include <sqlite3.h>
using namespace std;

int main(){
    sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("example.db",&DB);

    if (exit){
        cerr << "Error open DB: " <<sqlite3_errmsg(DB) <<endl;
        return (-1);
    }
    else{
        cout <<"Open succesfully! " <<endl;
        sqlite3_close(DB);
    }
    return 0;
}