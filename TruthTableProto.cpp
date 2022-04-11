#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
// + //
 char orGate(char a,char b){
    if(a == '1' || b == '1') return '1';
    else return '0';
}

// x //
 char andGate(char a,char b){
    if(a == '0' || b == '0') return '0';
    else return '1';
}

// ~ //
 char notGate(char a){
    if(a == '1')return '0';
    else return '1';
}

// (+) //
 char xorGate(char a,char b){
    if(a == b) return '0';
    else return '1';
}

 void repeater(char a,int b){
     for(int y = 0; y < b;y++){
     cout<<a;
    }
 }

static void exitThisShit(){
    cout<<"\n\n\t\tInvalid Operation\n";
    cout<<"\t\tProgram will now exit\n";
    cout<<"\t\tThank you!\n\n\n\n\n";
    cout<<"\t\t/$$$$$$$$ /$$   /$$ /$$$$$$ /$$$$$$$$\n";
    cout<<"\t\t| $$_____/| $$  / $$|_  $$_/|__  $$__/\n";
    cout<<"\t\t| $$      |  $$/ $$/  | $$     | $$   \n";
    cout<<"\t\t| $$$$$    \\  $$$$/   | $$     | $$   \n";
    cout<<"\t\t| $$__/     >$$  $$   | $$     | $$   \n";
    cout<<"\t\t| $$       /$$/\\  $$  | $$     | $$   \n";
    cout<<"\t\t| $$$$$$$$| $$  \\ $$ /$$$$$$   | $$   \n";
    cout<<"\t\t|________/|__/  |__/|______/   |__/   \n";
    cout<<"\n\n\t<< PROGRAM BY ARIF RAIHAN BIN AHMAD RIDZUAN @ ANAS  >>\n";

}

const int maxAdd = 7;

 //maximum addiArray is 7
int main(){
    int maxOriArray,amountOfInputs,addiArray = 0,i,j,number,currBaseValue,addiArrayCursor = 0,total,count;
    string addiName[maxAdd];
    char operation,keluar,dah = '0';
    int c1,c2;
    cout <<"\n\n"<<setw(40)<<""<<"Welcome to the Truth Table Program !!!\n\n\n";
    cout<<setw(46)<<""<<"Made by : Arif Raihan\n\n\n";
    cout<<"Enter the amount of inputs : ";
    cin>>amountOfInputs;
    maxOriArray = pow(2,amountOfInputs);
    //ARRAY DECLARATION
    char Original[maxOriArray][amountOfInputs + maxAdd];

    //START SETTING THE ORIGINAL ARRAY WITH THE CORRECT VALUE
    for(i = 0; i < maxOriArray;i++){
        number = i;
        for(j = 0;j < amountOfInputs;j++){
            currBaseValue = pow(2,amountOfInputs - 1 - j);
            if(number >= currBaseValue){
                Original[i][j] = '1';
                number = number - currBaseValue;
            }
            else Original[i][j] = '0';
        }
    }
    //END SETTING THE ORIGINAL ARRAY WITH THE CORRECT VALUE

    while(true){

    total = amountOfInputs + addiArray;
    //START DISPLAYING THE ORI AND ADDI ARRAY
    //|1. A |2. B |
    //   7     6
    cout<<"\n\t\t";
    for(i = 0; i < total;i++){
        if(i < amountOfInputs){
        if(i == total - 1 )cout<<"________";
        else cout<<"_______";
        }
        else{
            count = addiName[i - amountOfInputs].length();
            repeater('_',count + 5);
        }
    }

    cout<<"\n\t\t|";
    for(i = 0; i < total;i++){

        if(i < amountOfInputs)cout<<i + 1<<"."<<(char)(65 + i)<<"   |";
        else cout<<i + 1<<". "<<addiName[i - amountOfInputs]<<"|";
    }

    cout<<"\n\t\t";
    for(i = 0; i < total;i++){
        if(i < amountOfInputs){
            if(i == 0)cout<<"+======";
            else if(i == total - 1)cout<<"=======+";
            else cout<<"=======";
        }
        else {
            count = addiName[i - amountOfInputs].length();
            if(i == total - 1){
                repeater('=',count + 4);
                cout<<'+';
            }
            else repeater('=',count + 4);
        }
    }
    cout<<"\n";
    for(i = 0; i < maxOriArray;i++){
        cout<<"\t\t|";
        for(j = 0;j < total;j++){
            if(j < amountOfInputs){
             cout<<"  "<<Original[i][j]<<"   |";
                }
            else{
                    count = addiName[j - amountOfInputs].length();
                    cout<<"  "<<Original[i][j]<<setw(count + 1)<<"|";
                }
            }
            cout<<"\n";
        }
        cout<<"\n\n";
        if(dah == '1'){
            cout<<"Exit this program ? (Y/N)  : ";
            cin>>keluar;
            if(keluar == 'Y' || keluar == 'y'){
                break;
            }
        }
    char choices;
    int column1,column2;
    cout<<"Column available : "<<maxAdd - addiArray<<"\n\n";
    cout<<"Operation : \n\n\n";
    cout<<"1.Remove a column \n";
    cout<<"2.Create a column \n\n\n";

    cout<<"Choice : ";
    cin>>choices;
    if(choices != '1' && choices != '2'){
        exitThisShit();
        exit(0);
    }

    //YANG NI JE TAK SIAP LAGI MUNGKIN SENANG JE :)
    if(choices == '1'){
        int remColumn;
        cout<<"Enter the column that you want removed : ";
        cin>>remColumn;
        if(remColumn <= amountOfInputs || remColumn > total){
            exitThisShit();
            exit(0);
        }
        if(remColumn == total){
            addiName[remColumn - 1] = "";
            for(i = 0; i < maxOriArray;i++){
                Original[i][remColumn - 1] = '\0';
            }
        }
        else {
            for(i = remColumn - amountOfInputs - 1; i < total - amountOfInputs;i++)addiName[i] = addiName[i + 1];

            for(i = remColumn - 1;i < total - 1;i++){
                for(j = 0;j < maxOriArray;j++){
                    Original[j][i] = Original[j][i + 1];
                }
            }

            }


















        addiArrayCursor--;
        addiArray--;

    }

    else if(choices == '2' && addiArray == maxAdd){
        exitThisShit();
        exit(0);
    }
    else {
        cout<<"Operation : \n\n";
        cout<<"1.AND \n";
        cout<<"2.OR\n";
        cout<<"3.XOR\n";
        cout<<"4.NOT\n";
        cout<<"Choices : ";
        cin>>operation;
        if(operation > 52 || operation < 49){
            exitThisShit();
            exit(0);
        }
        else if(operation != '4'){
            cout<<"Enter column 1 : ";
            cin >> c1;
            if(c1 > total || c1 < 1){
                exitThisShit();
                exit(0);
            }
            cout<<"Enter column 2 : ";
            cin >> c2;
            if(c2 > total || c2 < 1){
                exitThisShit();
                exit(0);
            }
            char nama,nama1;
            if(operation == '1'){
            if(c1 > amountOfInputs  || c2 > amountOfInputs){

                if(c1 > amountOfInputs && c2 > amountOfInputs){
                    addiName[addiArrayCursor] = "(" + addiName[c1 - amountOfInputs - 1] + "x" +  addiName[c2 - amountOfInputs - 1] + ")";
                }
                else if(c1 > amountOfInputs){
                    nama = 64 + c2;
                    addiName[addiArrayCursor] = "(" + addiName[c1 - amountOfInputs - 1] + "x" + nama + ")";

                }
                else {
                    string anjing = "";
                    nama = 64 + c1;
                    addiName[addiArrayCursor] = "(" + anjing +nama + "x" + addiName[c2 - amountOfInputs - 1] + ")";
                }
                    }
            else{
                string anjing = "";
                nama = 64 + c1;
                nama1 = 64 + c2;
                addiName[addiArrayCursor] = anjing + "(" + nama + "x" + nama1 + ")";
            }



                for(i = 0; i < maxOriArray;i++){
                    Original[i][addiArrayCursor + amountOfInputs] = andGate(Original[i][c1 - 1],Original[i][c2 - 1]);
                }

            }
            if(operation == '2'){


                if(c1 > amountOfInputs  || c2 > amountOfInputs){

                    if(c1 > amountOfInputs && c2 > amountOfInputs){
                        addiName[addiArrayCursor] = "(" + addiName[c1 - amountOfInputs - 1] + "+" +  addiName[c2 - amountOfInputs - 1] + ")";
                    }
                    else if(c1 > amountOfInputs){
                        nama = 64 + c2;
                        addiName[addiArrayCursor] = "(" + addiName[c1 - amountOfInputs - 1] + "+" + nama + ")";

                    }
                    else {
                        string anjing = "";
                        nama = 64 + c1;
                        addiName[addiArrayCursor] = "(" + anjing +nama + "+" + addiName[c2 - amountOfInputs - 1] + ")";
                    }
                        }
                else{
                    string anjing = "";
                    nama = 64 + c1;
                    nama1 = 64 + c2;
                    addiName[addiArrayCursor] = anjing + "(" + nama + "+" + nama1 + ")";
                }


                for(i = 0; i < maxOriArray;i++){
                    Original[i][addiArrayCursor + amountOfInputs] = orGate(Original[i][c1 - 1],Original[i][c2 - 1]);

                }

            }


            if(operation == '3'){

                if(c1 > amountOfInputs  || c2 > amountOfInputs){

                    if(c1 > amountOfInputs && c2 > amountOfInputs){
                        addiName[addiArrayCursor] = "(" + addiName[c1 - amountOfInputs - 1] +"^" +  addiName[c2 - amountOfInputs - 1] + ")";
                    }
                    else if(c1 > amountOfInputs){
                        nama = 64 + c2;
                        addiName[addiArrayCursor] = "(" + addiName[c1 - amountOfInputs - 1] +"^" + nama + ")";

                    }
                    else {
                        string anjing = "";
                        nama = 64 + c1;
                        addiName[addiArrayCursor] = "(" + anjing +nama +"^" + addiName[c2 - amountOfInputs - 1] + ")";
                    }
                        }
                else{
                    string anjing = "";
                    nama = 64 + c1;
                    nama1 = 64 + c2;
                    addiName[addiArrayCursor] = anjing + "(" + nama +"^" + nama1 + ")";
                }
                for(i = 0; i < maxOriArray;i++){
                    Original[i][addiArrayCursor + amountOfInputs] = xorGate(Original[i][c1 - 1],Original[i][c2 - 1]);

                }

            }



        }
        else {
            cout<<"Enter column 1 : ";
            cin >> c1;
            if(c1 > total || c1 < 1){
                exitThisShit();
                exit(0);
            }
            string anjing;
            char kimak = 64 + c1;
            if(c1 > amountOfInputs){

                addiName[addiArrayCursor] = "~(" + anjing + addiName[c1 - amountOfInputs - 1] + ")";
            }
            else addiName[addiArrayCursor] = "~(" + anjing + kimak + ")";

            for(i = 0;i < maxOriArray;i++) Original[i][addiArrayCursor + amountOfInputs] = notGate(Original[i][c1 - 1]);



        }

        addiArrayCursor++;
        addiArray++;
    }
    dah = '1';
}
exitThisShit();











 return 0;
}
