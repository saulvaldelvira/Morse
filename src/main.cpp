#include "main.h"
saulv::Morse morse;

#define ENCODE 1
#define DECODE 0

int main() {
    presentation();
    string choice = "-1";
    do{
        showOptions();
        cout<<"\nChoice: ";
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
    cout<<"\n***OPTIONS***"<<endl;
    cout<<"1)Decode Morse" <<endl;
    cout<<"2)Encode Morse" <<endl;
    cout<<"0)Exit" <<endl;
}

void processOption(string option){
    if(option == "1"){
        operate([](string s) -> string {return morse.morseDecode(s);}, DECODE);
    }else if(option == "2"){
        operate([](string s) -> string {return morse.morseEncode(s);}, ENCODE);
    }else if(option=="0"){
        terminate();
    }else{
        cout<<"Invalid choice, try again"<<endl;;
    }
}

void operate(function<string(string)> f, int op){
    char src = fileOrTerminal("\nDo you want to input the text from a file or the terminal?");
    
    string text, sugerence = "";
    if(src=='1'){
        try{
            text = getFromFile(sugerence);
        }catch(int err){
            cout<<"\nError reading the file, try again.\n";
            return;
        }
    }else if(src=='2')
        text = getFromTerminal();
    else{
        cout<<"INVALID CHOICE\n";
        return;
    }
        
    char dest = fileOrTerminal("Do you want to output the result to a file or the terminal?");

    if(dest=='1')
        writeToFile(f(text), sugerence, op);
    else if(dest=='2')
        writeToTerminal(f(text), op==ENCODE?"Encoded: ": "Decoded: ");
    else{
        cout<<"INVALID CHOICE\n";
        return;
    }
}

char fileOrTerminal(string msg){
    cout<<msg<<endl;
    cout<< "1)File \n2)Terminal\nOption: ";
    char choice;
    cin >> choice;
    return choice;
}

string getFromFile(string& source){
    cout<<"Enter the path to the file: ";
    cin>>source;
    cout<<endl;
    return readFile(source);
}

void writeToFile(string s, string sugerence, int op){
    string dest;
    if(sugerence=="")
        cout<<"Enter the path to store the result: ";
    else{
        sugerence += op==ENCODE?"_encoded.txt":"_decoded.txt";
        cout<<"Enter the path to store the result. Leave blank to use the suggested path : "<<sugerence<<endl
        <<"Path: ";
    }
    cin.ignore();
    std::getline(cin, dest);
    cout<<"\n"<<dest;
    if(dest.empty())
        dest = sugerence;
    writeFile(dest, s);
}

string getFromTerminal(void){
    string info="", aux=":)";
    cout<<"\nInput: ";
    cin.ignore();
    while(1){
        std::getline(cin, aux);
        if(aux.empty())
            break;
        info+=aux+"\n";
    }
    return info;
}

void writeToTerminal(string s, string msg){
    cout<<endl<<msg<<s<<endl;
}

/*//Operates from a file. The function passed as a parameter is the one that will transform the content
void operateFile(function<string(string)> f, string addToFile){
    string source, target;
    cout<<"Enter the filename: ";
    cin >> source;
    target = source +  addToFile;
    cout<<"The result file will be: " << target <<endl;
    processContent(source, target, f);
}

//Operates from the terminal. The function passed as a parameter is the one that will transform the content
void operateTerminal(function<string(string)> f, string msgOut){
    string info;
    cout<<"Input: ";
    cin.ignore();
    std::getline(cin, info);
    cout<<endl<<msgOut << f(info) <<endl;
}*/

void terminate(){
    morse.~Morse();
}