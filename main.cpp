#include <iostream>
using namespace std;
string input;
int index;
char nextchar(){
    return input[index];
}
void consume(){
    index++;
}
void match(char c){
    if (c == nextchar())
        consume();
    else
        throw -1;
}
void S(){
    if (nextchar() == 'a'){
        match('a');
        S();
        match('b');
    }
    else
        ;

}
int main(){
    getline(cin, input);
    input = input + "$";
    index = 0;

    try{
        S();
        match('$');
        cout << " Yes";
    }catch(int n){
        cout << "No";
    }
    return 0;
}

