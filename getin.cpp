#include"getin.h"
using namespace std;
#define random(a,b) (rand()%(b-a+1)+a);
const int N = 100;

void getinput() {
    srand((int)time(0));
    FILE* fp = fopen("yes.txt", "r");
    if (fp == NULL)return;
    FILE* infp = fopen("input.txt", "w");
    char type[100][N];
    int type_num = 0;
    while (!feof(fp)) {
        fscanf(fp, "%s", type[type_num]);
       
        type_num++;
        
    }
    fclose(fp);
    for (int i = 0; i < type_num; i++) {
        cout << type[i]<<endl;
        char tx[10];
        int j;
        int qk = 0, dh = 0, hk = 0;
        for (j = 0; type[i][j] != '('&&j<strlen(type[i]); j++) {
            tx[j] = type[i][j];
        }
        tx[j] = '\0';
        qk = j;
        if (strcmp(tx, "int") == 0) {//int(a,b)
            int a = 0, b = 0;
            char numa[10]; char numb[10];
            j++;
            for (j; type[i][j] != ','; j++) {
                numa[j - qk - 1] = type[i][j];
            }
            numa[j - qk - 1] = '\0';
            dh = j;
            j++;
            for (j; type[i][j] != ')'; j++) {
                numb[j - dh - 1] = type[i][j];
            }
            numb[j - dh - 1] = '\0';
            hk = j;
            for (int ia = 0; ia < strlen(numa); ia++) {
                a = a * 10 + (numa[ia] - '0');
            }
            for (int ib = 0; ib < strlen(numb); ib++) {
                b = b * 10 + (numb[ib] - '0');
            }
            int res = random(a, b);
            fprintf(infp, "%d ", res);
            cout << res << endl;
        }
        else if (strcmp(tx, "char") == 0) {//char
            int d = random(1, 2);
            char res;
            if (d == 1) { res = 'a' + random(0, 26); }
            else { res = 'A' + random(0, 26); } cout << res << endl;
            fprintf(infp, "%c ", res);
           
        }
        else {//string (a,b)
            int a = 0, b = 0;
            char numa[10]; char numb[10];
            j++;
            for (j; type[i][j] != ','; j++) {
                numa[j - qk - 1] = type[i][j];
            }
            numa[j - qk - 1] = '\0';
            dh = j;
            j++;
            for (j; type[i][j] != ')'; j++) {
                numb[j - dh - 1] = type[i][j];
            }
            numb[j - dh - 1] = '\0';
            hk = j;
            for (int ia = 0; ia < strlen(numa); ia++) {
                a = a * 10 + (numa[ia] - '0');
            }
            for (int ib = 0; ib < strlen(numb); ib++) {
                b = b * 10 + (numb[ib] - '0');
            }

            int len = random(a, b);
            char resc[N];
            for (int i = 0; i < len; i++) {
                int d = random(1, 2);
                if (d == 1) { resc[i] = 'a' + random(0, 26); }
                else { resc[i] = 'A' + random(0, 26); }
            }
            resc[len] = '\0';
            fprintf(infp, "%s ", resc);
            cout << resc << endl;
        }
    }
    fputc('\n', infp);
    fclose(infp);
}
