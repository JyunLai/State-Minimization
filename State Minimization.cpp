#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

struct IT1{
    int TF=0;
    string leftstate;
    string downstate;
    string leftstate0;
    string downstate0;
    string leftstate1;
    string downstate1;
};
struct IT2{
    int TF=0;
    string leftstate;
    string downstate;
    string leftstate00;
    string downstate00;
    string leftstate01;
    string downstate01;
    string leftstate10;
    string downstate10;
    string leftstate11;
    string downstate11;
};
int main(int argc, const char * argv[]) {
    ifstream ifs;
    ifs.open(argv[1]);
    ofstream ofs1;
    ofs1.open("input.dot");
    ofstream ofs2;
    ofs2.open(argv[2]);
    ofstream ofs3;
    ofs3.open(argv[3]);
    string input;
    char table[100][14]={' '};
    if(!ifs.is_open()){
        cout<<"Fail To Open File"<<endl;
        return 0;
    }
    else{
        getline(ifs,input);
        int inputnum=0,outputnum=0,commandnum=0,variablenum=0,variablelen=0;
        string startvariable;
        while(input!=".end_kiss"){
            if(input==".start_kiss"){
                
            }
            else if(input[0]=='.'&&input[1]=='i'){
                int i=0;
                while(input[3+i]>=48&&input[3+i]<=57){
                    i++;
                }
                for(int j=0;j<i;j++){
                    inputnum+=((int)input[3+j]-48)*pow(10,i-j-1);
                }
            }
            else if(input[0]=='.'&&input[1]=='o'){
                int i=0;
                while(input[3+i]>=48&&input[3+i]<=57){
                    i++;
                }
                for(int j=0;j<i;j++){
                    outputnum+=((int)input[3+j]-48)*pow(10,i-j-1);
                }
            }
            else if(input[0]=='.'&&input[1]=='p'){
                int i=0;
                while(input[3+i]>=48&&input[3+i]<=57){
                    i++;
                }
                for(int j=0;j<i;j++){
                    commandnum+=((int)input[3+j]-48)*pow(10,i-j-1);
                }
                getline(ifs,input);
                if(input[0]=='.'&&input[1]=='s'){
                    int i=0;
                    while(input[3+i]>=48&&input[3+i]<=57){
                        i++;
                    }
                    for(int j=0;j<i;j++){
                        variablenum+=((int)input[3+j]-48)*pow(10,i-j-1);
                    }
                }
                string input1;
                ifs>>input1;
                if(input1==".r"){
                    ifs>>startvariable;
                }
                if(inputnum==1){
                    for(int i=0;i<commandnum/2;i++){
                        string input1;
                        string input2;
                        string input3;
                        ifs>>input>>input1>>input2>>input3;
                        variablelen=(int)input1.size();
                        for(int j=0;j<variablelen;j++){
                            table[i][j]=input1[j];
                        }
                        for(int j=0;j<variablelen;j++){
                            table[i][variablelen+j]=input2[j];
                        }
                        table[i][2*variablelen]=input3[0];
                        ifs>>input>>input1>>input2>>input3;
                        for(int j=0;j<variablelen;j++){
                            table[i][2*variablelen+1+j]=input2[j];
                        }
                        table[i][3*variablelen+1]=input3[0];
                    }
                }
                else if(inputnum==2){
                    for(int i=0;i<commandnum/4;i++){
                        string input1;
                        string input2;
                        string input3;
                        ifs>>input>>input1>>input2>>input3;
                        variablelen=(int)input1.size();
                        for(int j=0;j<variablelen;j++){
                            table[i][j]=input1[j];
                        }
                        for(int j=0;j<variablelen;j++){
                            table[i][variablelen+j]=input2[j];
                        }
                        table[i][2*variablelen]=input3[0];
                        ifs>>input>>input1>>input2>>input3;
                        for(int j=0;j<variablelen;j++){
                            table[i][2*variablelen+1+j]=input2[j];
                        }
                        table[i][3*variablelen+1]=input3[0];
                        ifs>>input>>input1>>input2>>input3;
                        for(int j=0;j<variablelen;j++){
                            table[i][3*variablelen+2+j]=input2[j];
                        }
                        table[i][4*variablelen+2]=input3[0];
                        ifs>>input>>input1>>input2>>input3;
                        for(int j=0;j<variablelen;j++){
                            table[i][4*variablelen+3+j]=input2[j];
                        }
                        table[i][5*variablelen+3]=input3[0];
                    }
                }
            }
            getline(ifs,input);
        }
        ofs1<<"digraph STG {\n\trankdir=LR;\n\n\tINIT [shape=point];\n";
        if(variablelen==1){
            for(int i=0;i<variablenum;i++){
                ofs1<<"\t"<<table[i][0]<<" [label=\""<<table[i][0]<<"\"];\n";
            }
            ofs1<<"\n\tINIT -> "<<startvariable<<";\n";
            if(inputnum==1){
                for(int i=0;i<variablenum;i++){
                    ofs1<<"\t"<<table[i][0]<<" -> "<<table[i][1]<<" [label=\"0/"<<table[i][2]<<"\"];\n\t"<<table[i][0]<<" -> "<<table[i][3]<<" [label=\"1/"<<table[i][4]<<"\"];\n";
                }
            }
            else if(inputnum==2){
                for(int i=0;i<variablenum;i++){
                    ofs1<<"\t"<<table[i][0]<<" -> "<<table[i][1]<<" [label=\"00/"<<table[i][2]<<"\"];\n\t"<<table[i][0]<<" -> "<<table[i][3]<<" [label=\"01/"<<table[i][4]<<"\"];\n\t"<<table[i][0]<<" -> "<<table[i][5]<<" [label=\"10/"<<table[i][6]<<"\"];\n\t"<<table[i][0]<<" -> "<<table[i][7]<<" [label=\"11/"<<table[i][8]<<"\"];\n";
                }
            }
        }
        else if(variablelen==2){
            for(int i=0;i<variablenum;i++){
                ofs1<<"\t"<<table[i][0]<<table[i][1]<<" [label=\""<<table[i][0]<<table[i][1]<<"\"];\n";
            }
            ofs1<<"\n\tINIT -> "<<startvariable<<";\n";
            if(inputnum==1){
                for(int i=0;i<variablenum;i++){
                    ofs1<<"\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][2]<<table[i][3]<<" [label=\"0/"<<table[i][4]<<"\"];\n\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][5]<<table[i][6]<<" [label=\"1/"<<table[i][7]<<"\"];\n";
                }
            }
            else if(inputnum==2){
                for(int i=0;i<variablenum;i++){
                    ofs1<<"\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][2]<<table[i][3]<<" [label=\"00/"<<table[i][4]<<"\"];\n\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][5]<<table[i][6]<<" [label=\"01/"<<table[i][7]<<"\"];\n\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][8]<<table[i][9]<<" [label=\"10/"<<table[i][10]<<"\"];\n\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][11]<<table[i][12]<<" [label=\"11/"<<table[i][13]<<"\"];\n";
                }
            }
        }
        ofs1<<"}\n";
        if(inputnum==1){
            vector<IT1> IT;
            IT1 start1;
            for(int i=0;i<variablenum-1;i++){
                for(int j=0;j<=i;j++){
                    if(variablelen==1){
                        start1.leftstate=table[1+i][0];
                        start1.downstate=table[j][0];
                        if(table[1+i][2]!=table[j][2]||table[1+i][4]!=table[j][4]){
                            start1.TF=1;
                        }
                        else{
                            start1.downstate0=table[j][1];
                            start1.downstate1=table[j][3];
                            start1.leftstate0=table[1+i][1];
                            start1.leftstate1=table[1+i][3];
                            start1.TF=0;
                        }
                    }
                    else if(variablelen==2){
                        start1.leftstate=table[1+i][0];
                        start1.leftstate+=table[1+i][1];
                        start1.downstate=table[j][0];
                        start1.downstate+=table[j][1];
                        if(table[1+i][4]!=table[j][4]||table[1+i][7]!=table[j][7]){
                            start1.TF=1;
                        }
                        else{
                            start1.downstate0=table[j][2];
                            start1.downstate0+=table[j][3];
                            start1.downstate1=table[j][5];
                            start1.downstate1+=table[j][6];
                            start1.leftstate0=table[1+i][2];
                            start1.leftstate0+=table[1+i][3];
                            start1.leftstate1=table[1+i][5];
                            start1.leftstate1+=table[1+i][6];
                            start1.TF=0;
                        }
                    }
                    IT.push_back(start1);
                }
            }
            int totalTF=1;
            while(totalTF==1){
                totalTF=0;
                for(int i=0;i<IT.size();i++){
                    if(IT[i].TF!=1){
                        if(IT[i].leftstate0!=IT[i].downstate0){
                            int TF=0,j=0;
                            while(TF==0){
                                if((IT[i].leftstate0==IT[j].leftstate&&IT[i].downstate0==IT[j].downstate)||(IT[i].leftstate0==IT[j].downstate&&IT[i].downstate0==IT[j].leftstate)){
                                    TF=1;
                                }
                                else{
                                    j++;
                                }
                            }
                            if(IT[j].TF==1){
                                IT[i].TF=1;
                                totalTF=1;
                            }
                        }
                        if(IT[i].leftstate1!=IT[i].downstate1){
                            int TF=0,j=0;
                            while(TF==0){
                                if((IT[i].leftstate1==IT[j].leftstate&&IT[i].downstate1==IT[j].downstate)||(IT[i].leftstate1==IT[j].downstate&&IT[i].downstate1==IT[j].leftstate)){
                                    TF=1;
                                }
                                else{
                                    j++;
                                }
                            }
                            if(IT[j].TF==1){
                                IT[i].TF=1;
                                totalTF=1;
                            }
                        }
                    }
                }
            }
            for(int i=0;i<IT.size();i++){
                if(IT[i].TF==0){
                    string a=IT[i].downstate;
                    string b=IT[i].leftstate;
                    int k=0;
                    if(variablelen==1){
                        while(table[k][0]!=b[0]){
                            k++;
                        }
                        for(int l=k;l<variablenum-1;l++){
                            for(int m=0;m<5;m++){
                                table[l][m]=table[l+1][m];
                            }
                        }
                        variablenum--;
                        for(int l=0;l<variablenum;l++){
                            for(int m=1;m<5;m+=2){
                                if(table[l][m]==b[0]){
                                    table[l][m]=a[0];
                                }
                            }
                        }
                    }
                    else if(variablelen==2){
                        while(table[k][0]!=b[0]||table[k][1]!=b[1]){
                            k++;
                        }
                        for(int l=k;l<variablenum-1;l++){
                            for(int m=0;m<8;m++){
                                table[l][m]=table[l+1][m];
                            }
                        }
                        variablenum--;
                        for(int l=0;l<variablenum;l++){
                            for(int m=2;m<8;m+=3){
                                if(table[l][m]==b[0]&&table[l][m+1]==b[1]){
                                    table[l][m]=a[0];
                                    table[l][m+1]=a[1];
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(inputnum==2){
            vector<IT2> IT;
            IT2 start1;
            for(int i=0;i<variablenum-1;i++){
                for(int j=0;j<=i;j++){
                    if(variablelen==1){
                        start1.leftstate=table[1+i][0];
                        start1.downstate=table[j][0];
                        if(table[1+i][2]!=table[j][2]||table[1+i][4]!=table[j][4]||table[1+i][6]!=table[j][6]||table[1+i][8]!=table[j][8]){
                            start1.TF=1;
                        }
                        else{
                            start1.downstate00=table[j][1];
                            start1.downstate01=table[j][3];
                            start1.downstate10=table[j][5];
                            start1.downstate11=table[j][7];
                            start1.leftstate00=table[1+i][1];
                            start1.leftstate01=table[1+i][3];
                            start1.leftstate10=table[1+i][5];
                            start1.leftstate11=table[1+i][7];
                            start1.TF=0;
                        }
                    }
                    else if(variablelen==2){
                        start1.leftstate=table[1+i][0];
                        start1.leftstate+=table[1+i][1];
                        start1.downstate=table[j][0];
                        start1.downstate+=table[j][1];
                        if(table[1+i][4]!=table[j][4]||table[1+i][7]!=table[j][7]||table[1+i][10]!=table[j][10]||table[1+i][13]!=table[j][13]){
                            start1.TF=1;
                        }
                        else{
                            start1.downstate00=table[j][2];
                            start1.downstate00+=table[j][3];
                            start1.downstate01=table[j][5];
                            start1.downstate01+=table[j][6];
                            start1.downstate10=table[j][8];
                            start1.downstate10+=table[j][9];
                            start1.downstate11=table[j][11];
                            start1.downstate11+=table[j][12];
                            start1.leftstate00=table[1+i][2];
                            start1.leftstate00+=table[1+i][3];
                            start1.leftstate01=table[1+i][5];
                            start1.leftstate01+=table[1+i][6];
                            start1.leftstate10=table[1+i][8];
                            start1.leftstate10+=table[1+i][9];
                            start1.leftstate11=table[1+i][11];
                            start1.leftstate11+=table[1+i][12];
                            start1.TF=0;
                        }
                    }
                    IT.push_back(start1);
                }
            }
            int totalTF=1;
            while(totalTF==1){
                totalTF=0;
                for(int i=0;i<IT.size();i++){
                    if(IT[i].TF!=1){
                        if(IT[i].leftstate00!=IT[i].downstate00){
                            int TF=0,j=0;
                            while(TF==0){
                                if((IT[i].leftstate00==IT[j].leftstate&&IT[i].downstate00==IT[j].downstate)||(IT[i].leftstate00==IT[j].downstate&&IT[i].downstate00==IT[j].leftstate)){
                                    TF=1;
                                }
                                else{
                                    j++;
                                }
                            }
                            if(IT[j].TF==1){
                                IT[i].TF=1;
                                totalTF=1;
                            }
                        }
                        if(IT[i].leftstate01!=IT[i].downstate01){
                            int TF=0,j=0;
                            while(TF==0){
                                if((IT[i].leftstate01==IT[j].leftstate&&IT[i].downstate01==IT[j].downstate)||(IT[i].leftstate01==IT[j].downstate&&IT[i].downstate01==IT[j].leftstate)){
                                    TF=1;
                                }
                                else{
                                    j++;
                                }
                            }
                            if(IT[j].TF==1){
                                IT[i].TF=1;
                                totalTF=1;
                            }
                        }
                        if(IT[i].leftstate10!=IT[i].downstate10){
                            int TF=0,j=0;
                            while(TF==0){
                                if((IT[i].leftstate10==IT[j].leftstate&&IT[i].downstate10==IT[j].downstate)||(IT[i].leftstate10==IT[j].downstate&&IT[i].downstate10==IT[j].leftstate)){
                                    TF=1;
                                }
                                else{
                                    j++;
                                }
                            }
                            if(IT[j].TF==1){
                                IT[i].TF=1;
                                totalTF=1;
                            }
                        }
                        if(IT[i].leftstate11!=IT[i].downstate11){
                            int TF=0,j=0;
                            while(TF==0){
                                if((IT[i].leftstate11==IT[j].leftstate&&IT[i].downstate11==IT[j].downstate)||(IT[i].leftstate11==IT[j].downstate&&IT[i].downstate11==IT[j].leftstate)){
                                    TF=1;
                                }
                                else{
                                    j++;
                                }
                            }
                            if(IT[j].TF==1){
                                IT[i].TF=1;
                                totalTF=1;
                            }
                        }
                    }
                }
            }
            for(int i=0;i<IT.size();i++){
                if(IT[i].TF==0){
                    string a=IT[i].downstate;
                    string b=IT[i].leftstate;
                    int k=0;
                    if(variablelen==1){
                        while(table[k][0]!=b[0]){
                            k++;
                        }
                        for(int l=k;l<variablenum-1;l++){
                            for(int m=0;m<9;m++){
                                table[l][m]=table[l+1][m];
                            }
                        }
                        variablenum--;
                        for(int l=0;l<variablenum;l++){
                            for(int m=1;m<9;m+=2){
                                if(table[l][m]==b[0]){
                                    table[l][m]=a[0];
                                }
                            }
                        }
                    }
                    else if(variablelen==2){
                        while(table[k][0]!=b[0]||table[k][1]!=b[1]){
                            k++;
                        }
                        for(int l=k;l<variablenum-1;l++){
                            for(int m=0;m<14;m++){
                                table[l][m]=table[l+1][m];
                            }
                        }
                        variablenum--;
                        for(int l=0;l<variablenum;l++){
                            for(int m=2;m<14;m+=3){
                                if(table[l][m]==b[0]&&table[l][m+1]==b[1]){
                                    table[l][m]=a[0];
                                    table[l][m+1]=a[1];
                                }
                            }
                        }
                    }
                }
            }
        }
        ofs3<<"digraph STG {\n\trankdir=LR;\n\n\tINIT [shape=point];\n";
        if(variablelen==1){
            for(int i=0;i<variablenum;i++){
                ofs3<<"\t"<<table[i][0]<<" [label=\""<<table[i][0]<<"\"];\n";
            }
            ofs3<<"\nINIT -> "<<startvariable<<";\n";
            if(inputnum==1){
                ofs2<<".start_kiss\n.i "<<inputnum<<"\n.o "<<outputnum<<"\n.p "<<variablenum*2<<"\n.s "<<variablenum<<"\n.r "<<startvariable<<"\n";
                for(int i=0;i<variablenum;i++){
                    ofs2<<"0 "<<table[i][0]<<" "<<table[i][1]<<" "<<table[i][2]<<"\n1 "<<table[i][0]<<" "<<table[i][3]<<" "<<table[i][4]<<"\n";
                    ofs3<<"\t"<<table[i][0]<<" -> "<<table[i][1]<<" [label=\"0/"<<table[i][2]<<"\"];\n\t"<<table[i][0]<<" -> "<<table[i][3]<<" [label=\"1/"<<table[i][4]<<"\"];\n";
                }
            }
            else if(inputnum==2){
                ofs2<<".start_kiss\n.i "<<inputnum<<"\n.o "<<outputnum<<"\n.p "<<variablenum*4<<"\n.s "<<variablenum<<"\n.r "<<startvariable<<"\n";
                for(int i=0;i<variablenum;i++){
                    ofs2<<"00 "<<table[i][0]<<" "<<table[i][1]<<" "<<table[i][2]<<"\n01 "<<table[i][0]<<" "<<table[i][3]<<" "<<table[i][4]<<"\n10 "<<table[i][0]<<" "<<table[i][5]<<" "<<table[i][6]<<"\n11 "<<table[i][0]<<" "<<table[i][7]<<" "<<table[i][8]<<"\n";
                    ofs3<<"\t"<<table[i][0]<<" -> "<<table[i][1]<<" [label=\"00/"<<table[i][2]<<"\"];\n\t"<<table[i][0]<<" -> "<<table[i][3]<<" [label=\"01/"<<table[i][4]<<"\"];\n\t"<<table[i][0]<<" -> "<<table[i][5]<<" [label=\"10/"<<table[i][6]<<"\"];\n\t"<<table[i][0]<<" -> "<<table[i][7]<<" [label=\"11/"<<table[i][8]<<"\"];\n";
                }
            }
        }
        else if(variablelen==2){
            for(int i=0;i<variablenum;i++){
                ofs3<<"\t"<<table[i][0]<<table[i][1]<<" [label=\""<<table[i][0]<<table[i][1]<<"\"];\n";
            }
            ofs3<<"\nINIT -> "<<startvariable<<";\n";
            if(inputnum==1){
                ofs2<<".start_kiss\n.i "<<inputnum<<"\n.o "<<outputnum<<"\n.p "<<variablenum*2<<"\n.s "<<variablenum<<"\n.r "<<startvariable<<"\n";
                for(int i=0;i<variablenum;i++){
                    ofs2<<"0 "<<table[i][0]<<table[i][1]<<" "<<table[i][2]<<table[i][3]<<" "<<table[i][4]<<"\n1 "<<table[i][0]<<table[i][1]<<" "<<table[i][5]<<table[i][6]<<" "<<table[i][7]<<"\n";
                    ofs3<<"\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][2]<<table[i][3]<<" [label=\"0/"<<table[i][4]<<"\"];\n\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][5]<<table[i][6]<<" [label=\"1/"<<table[i][7]<<"\"];\n";
                }
            }
            else if(inputnum==2){
                ofs2<<".start_kiss\n.i "<<inputnum<<"\n.o "<<outputnum<<"\n.p "<<variablenum*4<<"\n.s "<<variablenum<<"\n.r "<<startvariable<<"\n";
                for(int i=0;i<variablenum;i++){
                    ofs2<<"00 "<<table[i][0]<<table[i][1]<<" "<<table[i][2]<<table[i][3]<<" "<<table[i][4]<<"\n01 "<<table[i][0]<<table[i][1]<<" "<<table[i][5]<<table[i][6]<<" "<<table[i][7]<<"\n10 "<<table[i][0]<<table[i][1]<<" "<<table[i][8]<<table[i][9]<<" "<<table[i][10]<<"\n11 "<<table[i][0]<<table[i][1]<<" "<<table[i][11]<<table[i][12]<<" "<<table[i][13]<<"\n";
                    ofs3<<"\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][2]<<table[i][3]<<" [label=\"00/"<<table[i][4]<<"\"];\n\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][5]<<table[i][6]<<" [label=\"01/"<<table[i][7]<<"\"];\n\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][8]<<table[i][9]<<" [label=\"10/"<<table[i][10]<<"\"];\n\t"<<table[i][0]<<table[i][1]<<" -> "<<table[i][11]<<table[i][12]<<" [label=\"11/"<<table[i][13]<<"\"];\n";
                }
            }
        }
        ofs3<<"}\n";
        ofs2<<".end_kiss\n";
    }
    return 0;
}
