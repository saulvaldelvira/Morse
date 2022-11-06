#include "main.h"
Morse morse;

int main() {
    presentation();
    string choice = "-1";
    do{
        showOptions();
        cout<<"Choice: ";
        cin >> choice;
        processOption(choice);
    }while(choice!="0");
    return 0;
}

void presentation(){
    cout << endl << 
    "**********MORSE decoder*************************************"    << endl <<
    "* Made by Saul Valdelvira (\xB8 2022)                         *" << endl <<
    "* More info at https://www.github.com/saulvaldelvira/morse *"    << endl <<
    "************************************************************"    << endl;
}

void showOptions(){
    cout<<"\n1)Decode Morse" <<endl;
    cout<<"2)Encode Morse" <<endl;
    cout<<"0)Exit" <<endl;
}

void processOption(string option){
    if(option == "1"){
        decode();
    }else if(option == "2"){
        encode();
    }else if(option=="0"){
        terminate();
    }else{
        cout<<"Invalid choice, try again"<<endl;;
    }
}

void decode(){
    char choice = fileOrTerminal();
    if(choice=='1'){
        operateFile([](string s) -> string {return morse.morseDecode(s);}, "_decoded.txt");
    }else if(choice=='2'){ //TODO: No va!
        operateTerminal([](string s) -> string {return morse.morseDecode(s);}, "Decoded: ");
    }
}

void encode(){
    char choice = fileOrTerminal();
    if(choice=='1'){
        operateFile([](string s) -> string {return morse.morseEncode(s);}, "_encoded.txt");
    }else if(choice=='2'){ //TODO: No va!
        operateTerminal([](string s) -> string {return morse.morseEncode(s);}, "Encoded: ");
    }
}

char fileOrTerminal(){
    cout<<"Do you want to input the text froma file or the terminal?"<<endl;
    cout<< "1)File \n2)Terminal\nOption: ";
    char choice;
    cin >> choice;
    return choice;
}

//Operates from a file. The function passed as a parameter is the one that will transform the content
void operateFile(function<string(string)> f, string addToFile){
    string source, target;
    cout<<"Enter the filename: ";
    cin >> source;
    target = source +  addToFile;
    cout<<"The result file will be: " << target <<endl;
    writeFile(target, f(readFile(source)));
    //TODO: No funciona bien. Si cortas una palabra a la mitad se jode. Hacer por lineas mejor
    //processContent(source, target, f);
}

//Operates from the terminal. The function passed as a parameter is the one that will transform the content
void operateTerminal(function<string(string)> f, string msgOut){
    string info;
    cout<<"Input: ";
    cin.ignore();
    std::getline(cin, info);
    cout<<endl<<msgOut << f(info) <<endl;
}

void terminate(){
    morse.~Morse();
}