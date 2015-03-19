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
/* Left Recursion In place
    RE -> C
    RE -> RE "|" C
    B -> 'A'
        |'B'
        |'C'
        |'D'
    B ->B "*"
    B ->"(" RE ")"
    Left Recursion Removed
    P-> "(" RE ")" RE
        | E
    K -> '*' P
    C -> 'A'C
        |'B'C
        |'C'C
        |'D'C
        | K
    RE  -> C'*'C RE2
    RE2 -> C
        | RE2

 */
void C();
void RE();
void RE2();
void K();
void K2();
void P(){
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
    if(nextchar()=='|'){
        match('|');
        C();
        K2();
    }
    P();
 }
void K2(){
    C();
    K();
}
void C(){
    if(nextchar()=='a'){
        match('a');
        C();
    }else if(nextchar()=='b'){
        match('b');
        C();
    }else if(nextchar()=='c'){
        match('c');
        C();
    }else if(nextchar()=='d'){
        match('d');
        C();
    }
    else
        K();
}

void RE2(){
    //C();
    RE();
}

void RE(){
    if(nextchar()=='*'){
        C();
        match('*');
        RE2();
    }else{

    }
}

int main(){
    while (true){
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
    }
    return 0;
}
