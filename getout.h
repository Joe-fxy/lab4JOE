#pragma once
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include<vector>
#include <iostream>
using namespace std;

void getFiles(char pofix_path[]);
void getcatalogue(char pofix_path[]);
bool have_output(const char* out_file);
