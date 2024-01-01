#include<iostream>
#include<string>
using namespace std;

char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
string str1;
string str2;
int row;
int column;
char token;
bool draw;

void shape(){
    cout<<"Enter name of 1st Player :";
    getline(cin,str1);
    cout<<"Enter name of 2nd PLayer :";
    getline(cin,str2);
    
    cout<<str1<<" is 1st player ! so he/she will play first"<<endl;
    cout<<str2<<" is 2nd player ! so he/she will play second"<<endl;
    cout<<arr[0][0]<<"  |"<<arr[0][1]<<" |"<<arr[0][2]<<endl;
    cout<<" __|__|__"<<endl;
    cout<<arr[1][0]<<"  |"<<arr[1][1]<<" |"<<arr[1][2]<<endl;
    cout<<" __|__|__"<<endl;
    cout<<arr[2][0]<<"  |"<<arr[2][1]<<" |"<<arr[2][2]<<endl;
    cout<<"   |  |  "<<endl;
}

void val(){
    int digit;
    cout<<"Enter token (x/0) :";
    cin>>token;
    if(token=='x'){
        cout<<str1<<" Please Make a move !"<<endl;
        cout<<"Choose Position !"<<endl;
        cin>>digit;
    }
    if(token=='0'){
        cout<<str2<<" Please Make a move !"<<endl;
        cout<<"Choose Position !"<<endl;
        cin>>digit;
    }

    if(digit==1){
        row=0;
        column=0;
    }
    if(digit==2){
        row=0;
        column=1;
    }
     if(digit==3){
        row=0;
        column=2;
    }
     if(digit==4){
        row=1;
        column=0;
    }
     if(digit==5){
        row=1;
        column=1;
    }
     if(digit==6){
        row=1;
        column=2;
    }
     if(digit==7){
        row=2;
        column=0;
    }
     if(digit==8){
        row=2;
        column=1;
    }
     if(digit==9){
        row=2;
        column=2;
    }
    else if(digit>9 || digit<1){
        cout<<"Invalid Selection !"<<endl;
    }

    if(token=='x' && arr[row][column]!='0' && arr[row][column]!='x'){
        arr[row][column]='x';
        token='0';
        val();
    }

   else if(token=='0' && arr[row][column]!='0' && arr[row][column]!='x'){
        arr[row][column]='0';
        token='x';
        val();
    }
    else{
        cout<<"There is no empty space left !"<<endl;
        return;
    }
}

bool end(){
    for(int i=0;i<3;i++){
        if(arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2] || arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i]){
            return true;
        }
        if(arr[0][0]==arr[1][1]==arr[2][2] || arr[0][2]==arr[1][1]==arr[2][0]){
            return true;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]!='x' && arr[i][j]!='0'){
                return false;
            }
        }
    }
    draw=true;
    return false;
}

int main(){
   while(!end()){
    shape();
    val();
    end();
   }
   if(token=='x' && draw==false){
    cout<<str1<<"Wins !!"<<endl;
   }
   else if(token=='0' && draw==false){
    cout<<str2<<"Wins !!"<<endl;
   }
   else{
    cout<<"The game is draw ! "<<endl;
   }

}