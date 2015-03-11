//
// Regular expression parser
//
// Brian James Herman
// U. of Illinois, Chicago
// CS301, Spring 2015: HW10
//

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

/**
 * parenthesis -> (parenthesis)
 */
void parenthesis(){
    if (nextchar() == '('){
        match('(');
        parenthesis();
        match(')');
    }
    else
        ;

}

int main(){
    cout << "> ";
    getline(cin, input);
    input = input + "$";
    index = 0;
    try{
        parenthesis();
        match('$');
        cout << " Yes" << endl;
    }catch(int n){
        cout << "No" << endl;
    }
    return 0;
}

