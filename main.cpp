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
/*
    RE --> C
    RE --> RE "|" C
    C --> B
    C -->C "." B
    B --> Sim
    B -->B "*"
    B -->"(" RE ")"
    Sim --> a | b | c | "є"

 */
void C();
void C2();
void RE2();
void B();
void parenthesis();
void sym();

void RE(){
   cout << input;
   C();
   RE2();
}
void RE2(){
    cout << input;
    match('|');
    RE();
    C();     
}
void C(){
   cout << input;
   C2();
   RE2();
   //sym(;
}
void C2(){
   cout << input;
    match('*');
    RE();
    C();     
}
void sym(){
   cout << input;
   match('a');
   match('b');
   match('c');
   match('d');
}
/**
 * parenthesis -> (parenthesis)
 */
void parenthesis(){
    if (nextchar() == '('){
        match('(');
        RE();
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
        RE();
        match('$');
        cout << " Yes" << endl;
    }catch(int n){
        cout << "No" << endl;
    }
    return 0;
}

