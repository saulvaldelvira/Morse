#pragma once
#include "morse.h"
#include "file.h"

//IOSTREAM
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

//Funciones
char fileOrTerminal(string msg);
void terminate();
void presentation();
void showOptions();
void processOption(string option);
string getFromFile(string&);
void writeToFile(string, string, int);
string getFromTerminal(void);
void writeToTerminal(string, string);
void operate(function<string(string)>, int);