#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include<vector>
#include <iostream>
using namespace std;
char path[20][100];
char catalogue[20][20];
int cpp_num=0;
int cata_num=0;
void getFiles(char pofix_path[]);
void getcatalogue(char pofix_path[]);