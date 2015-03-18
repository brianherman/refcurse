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
void RE();
void RE2();
void K();
/**
 * parenthesis -> (parenthesis)
 */
void parenthesis(){
    RE();
    if (nextchar() == '('){
        match('(');
        RE();
        match(')');
        RE();
    }
    else
        ;

}
void K(){
    if(nextchar()=='*'){
        match('*');
    }
    parenthesis();
 }
void C(){
    if(nextchar()=='a'){
        match('a');
        C();
    }
    if(nextchar()=='b'){
        match('b');
        C();
    }
    if(nextchar()=='c'){
        match('c');
        C();
    }
    if(nextchar()=='d'){
        match('d');
        C();
    }
    else
        K();
}

void RE2(){
    C();
    RE();
}
void RE(){
    C();
    if(nextchar()=='|'){
        match('|');
        C();
        RE2();
    }else{
    }
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

