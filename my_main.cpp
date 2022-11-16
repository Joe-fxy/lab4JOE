#include"getin.h"
#include"getout.h"
#include"getres.h"
extern char path[20][100];
extern char catalogue[20][20];
extern int cpp_num;
extern int cata_num;
int main(){
    char input[]="input";
    getcatalogue(input);
    for(int i=0;i<cata_num;i++){
        getFiles(catalogue[i]);
        int txt=0;
        for(int j=0;j<cpp_num;j++){
            int lenth=strlen(path[j]);
            if(path[j][lenth-1]=='t'&&path[j][lenth-3]=='t'&&path[j][lenth-2]=='x'){
                txt=j;
                break;
            }
        }
        bool res=1;
        bool o1=1,o0=1;
        for(int a=0;a<cpp_num;a++){
            if(a==txt)continue;
            if(a==cpp_num-1)break;
            for(int b=a+1;b<cpp_num;b++){
                if(b==txt)continue;
                for(int trytime=0;trytime<10;trytime++){
                    getinput(path[txt]);
                    remove("output.txt");
                    remove("output1.txt");
                    getout(path[a],1);
                    getout(path[b],0);
                    if(have_output("output1.txt")==0){o1=0;break;}
                    if(have_output("output.txt")==0){o0=0;break;}
                    res=res&getres();  
                    if(res==0)break;         
                }
                if(o0==0)continue;
                if(o1==0)break;
                writeres(path[a],path[b],res);
                res=1;
            }
            if(o1==0){
                writeab(path[a]);
                continue;
            }
        }
        cpp_num=0;
    }
    return 0;
}
