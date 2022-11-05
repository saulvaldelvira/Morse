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

void writeFile(string filename, string content){
    fstream file(filename, std::ios::out);
    if(!file){
        cout<<"File could not be created"<<endl;
        return;
    }
    file<<content;
    file.close();
}

#endif