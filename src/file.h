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

#define FILE_NOT_FOUD -1

//Funcional (lambda)
#include <functional>
using std::function;

//Reads from file
string readFile(string);

//Writes to file
void writeFile(string, string);

void processContent(string, string, function<string(string)>);

#endif