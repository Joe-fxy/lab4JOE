#include"getres.h"

void getout(char file[],bool is){
    char rule[100];
    char qian[]="g++ ";
    char hou[]=" -o getres";
    int i;
    for(i=0;i<strlen(qian);i++){
        rule[i]=qian[i];
    }
    for(int ii=0;ii<strlen(file);ii++){
        rule[i++]=file[ii];
    }
    for(int ii=0;ii<strlen(hou);ii++){
        rule[i++]=hou[ii];
    }
    rule[i]='\0';
    system(rule);
    if(is){
        system("./getres <input.txt >output1.txt");
    }
    else system("./getres <input.txt >output.txt");
    return;
}
bool getres(){//1 eq,0 ieq
    FILE*one=fopen("output.txt","r");
    FILE*two=fopen("output1.txt","r");
    string ans1="",ans2="";
    char s;
    while(fscanf(one,"%c",&s)!=EOF)ans1+=s;
    fclose(one);
    while(fscanf(two,"%c",&s)!=EOF)ans2+=s;
    fclose(two);
    bool eq=0;
    if(ans1.size()!=ans2.size())eq=0;
    else{
        int i;
        for(i=0;i<ans1.size();i++){
            if(ans1[i]!=ans2[i])break;
        }
        if(i==ans1.size())eq=1;
        else eq=0;
    }
    return eq;
}
void writeres(char file1[],char file2[],bool eq){
    if(eq){FILE*res=fopen("equal.csv","a");
        fprintf(res,"%s,",file1);
        fprintf(res,"%s",file2);
        fputc('\n', res);
        fclose(res);
        cout<<"tiaoyong equal"<<endl;
    }
    else {FILE*res=fopen("inequal.csv","a");
        fprintf(res,"%s,%s",file1,file2);
        fputc('\n', res);
        fclose(res);
        cout<<"tiaoyong inequal"<<endl;
    }
}
void writeab(char file[]){
    FILE*ab=fopen("abnormal.csv","w");
    fprintf(ab,"%s",file);
    fputc('\n',ab);
    cout<<"tiaoyong abnormal"<<endl;
    fclose(ab);
}