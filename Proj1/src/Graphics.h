#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#include <limits>

//MENUS
void opening_menu();
int start_menu();

//UTILS
void center_string(char* s);
int getCols();
void print_centered(std::string s);
