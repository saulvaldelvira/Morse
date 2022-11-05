#pragma once
#include "morse.h"
#include "file.h"

//IOSTREAM
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

//Funcional (lambda)
#include <functional>
using std::function;

//Funciones
char fileOrTerminal();
void operateFile(function<string(string)> f, string addToFile);
void operateTerminal(function<string(string)> f, string msgOut);
void decode();
void encode();
void terminate();
void showOptions();
void processOption(string option);