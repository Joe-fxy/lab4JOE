#include"getout.h"
#include<unistd.h>
char path[20][100];
char catalogue[20][20];
int cpp_num=0;
int cata_num=0;
void getFiles(char pofix_path[]) {
    DIR *dir;
    struct dirent *ptr;
    if ((dir = opendir(pofix_path)) == NULL) {
        perror("Open dir error...");
        return;
    }
    while ((ptr = readdir(dir)) != NULL) {
        if (ptr->d_type == 8){
            if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)    ///current dir OR parrent dir
            {continue;}
            for(int i=0;i<strlen(pofix_path);i++){
                path[cpp_num][i]=pofix_path[i];
            }
            path[cpp_num][strlen(pofix_path)]='/';
            for(int i=0;i<strlen(ptr->d_name);i++){
                path[cpp_num][i+strlen(pofix_path)+1]=ptr->d_name[i];
            }
            path[cpp_num][strlen(pofix_path)+1+strlen(ptr->d_name)]='\0';
            cpp_num++;

        } else {
            continue;
        }
    }
    closedir(dir);
}
void getcatalogue(char pofix_path[]){
    DIR *dir;
    struct dirent *ptr;
    if ((dir = opendir(pofix_path)) == NULL) {
        perror("Open dir error...");
        return;
    }
    while ((ptr = readdir(dir)) != NULL) {
        if (ptr->d_type == 4){
            if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0)    ///current dir OR parrent dir
            {continue;}
            for(int i=0;i<strlen(pofix_path);i++){
                catalogue[cata_num][i]=pofix_path[i];
            }
            catalogue[cata_num][strlen(pofix_path)]='/';
            for(int i=0;i<strlen(ptr->d_name);i++){
                catalogue[cata_num][i+strlen(pofix_path)+1]=ptr->d_name[i];
            }
            catalogue[cata_num][strlen(pofix_path)+1+strlen(ptr->d_name)]='\0';
            cata_num++;
        } else {
            continue;
        }
    }
    closedir(dir);
}
bool have_output(const char* out_file){
    return (access(out_file,F_OK)==0);
}