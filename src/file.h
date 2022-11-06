#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using std::string;
using std::ifstream;
using std::fstream;
using std::vector;
using std::cout;
using std::endl;

//Funcional (lambda)
#include <functional>
using std::function;

//Reads from file
string readFile(string filename){
    ifstream my_file(filename);
    if(!my_file){
        cout<<"File not found"<<endl;
        return "";
    }
    my_file.seekg(0, std::ios_base::end); // Seek to end of file.
    const unsigned int file_length = my_file.tellg();
    my_file.seekg(0);
    std::vector<char> file_data(file_length);
    my_file.read(&file_data[0], file_length);
    my_file.close();
    return string(file_data.begin(), file_data.end());
}

//Writes to file
void writeFile(string filename, string content){
    fstream file(filename, std::ios::out);
    if(!file){
        cout<<"File could not be created"<<endl;
        return;
    }
    file<<content;
    file.close();
}

/*THIS IS NOT WORKING FOR NOW.
    The proble is that reading in chunks of n characters without taking in count that morse characters are divided by spaces, breaks the content
void processContent(string source, string target, function<string(string)> func, int chunkSize=10000){
    ifstream fileIn(source, std::ios::out);
    if(!fileIn){
        cout<<"Source file not found!"<<endl;
        return;
    }
    fstream fileOut(target);
    if(!fileOut){
        cout<<"File could not be created"<<endl;
        return;
    }

    char* buffer = new char[chunkSize];
    while(fileIn.read(buffer, chunkSize)){
        fileOut.write(func(string(buffer)).c_str(), chunkSize);
    }
    fileOut.write(func(string(buffer)).c_str(), fileIn.gcount());

    delete buffer;
    fileIn.close();
    fileOut.close();
}*/

#endif