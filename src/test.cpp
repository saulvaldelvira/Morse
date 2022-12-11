#include "main.h"
#include "file.h"
saulv::Morse morse;

void test(){

    string  decoded = readFile(".\\test\\testDecoded.txt"),
            encoded = readFile(".\\test\\testEncoded.txt");

    cout<<decoded<<endl<<"************"<<encoded<<endl;

    if(morse.morseDecode(encoded)==decoded)
        cout<<"Decode sucesfull\n";
    else
        cout<<"Decode un-sucesfull\n";
    if(morse.morseEncode(decoded)==encoded)
        cout<<"Encode sucesfull\n";
    else
        cout<<"Encode un-sucesfull\n";
}

int main() {
    test();
}