#include "main.h"
#include <chrono>
using namespace std::chrono;
Morse morse;

void encodeTest(){
    auto start = high_resolution_clock::now();

    string filename = "..\\bin\\lor.txt", 
            dest = "..\\bin\\testEncode.txt";

    processContent(filename, dest, [](string s) -> string {return morse.morseEncode(s);});

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Encode duration: " << duration.count() << " microseconds" << endl;
}

void decodeTest(){
    auto start = high_resolution_clock::now();

    string dest = "..\\bin\\testDecode.txt", 
            filename = "..\\bin\\testEncode.txt";

    processContent(filename, dest, [](string s) -> string {return morse.morseDecode(s);});

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Decode duration: " << duration.count() << " microseconds" << endl;
}

int main() {
    encodeTest();
    decodeTest();
}