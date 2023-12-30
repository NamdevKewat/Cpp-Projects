#include<iostream>
#include<cstdlib>
#include<ctime>
#define Rock 1
#define Paper 2 
#define Scizor 3 
using namespace std;

int main(){
    srand((unsigned int)time(NULL));//srand function will make sure always computer will not win and records time 

    cout<<"Enter Your Choice :"<<endl;
    cout<<"a) 1 for Rock "<<endl;
    cout<<"b) 2 for Paper "<<endl;
    cout<<"c) 3 for Scizor"<<endl;

    int user;
    int comp;
    bool draw=false;

    do{
        cin>>user;
        comp=(rand()%3)+1;//rand() will random integer using modulus % 3 will give us the  reminder between 0,1 and 2  adding 1 to will give us 3
        if(comp==Rock){
            cout<<"Compuer Chooses Rock !"<<endl;
        }
        else if(comp==Paper){
            cout<<"Computer Chooses Paper !"<<endl;
        }
        else if(comp==Scizor){
            cout<<"Computer Chooses Scizor !"<<endl;
        }
        
        if(user==Rock && comp==Rock){
            cout<<"Its a Draw ! Try Again"<<endl;
            draw=true;
        }
        else if(user==Rock && comp==Paper){
            cout<<"Paper defeats Rock ! You lose";
            break;
        }
        else if(user==Rock && comp==Scizor){
            cout<<"Rock defeats Scizor ! You Won";
            break;
        }

        if(user==Paper && comp==Paper){
             cout<<"Its a Draw ! Try Again"<<endl;
            draw=true;
        }
        else if(user==Paper && comp==Rock){
            cout<<"Paper defeats Rock ! You Won"<<endl;
            break;
        }
        else if(user==Paper && comp==Scizor){
            cout<<"Scizor defeats Paper ! You Lose "<<endl;
            break;
        }

        if(user==Scizor && comp==Scizor){
             cout<<"Its a Draw ! Try Again"<<endl;
            draw=true;
        }
        else if(user==Scizor && comp==Paper){
            cout<<"Scizor defeats Paper ! You Won"<<endl;
            break;
        }
        else if(user==Scizor && comp==Rock){
            cout<<"Rock defeats Scizor ! You Lose"<<endl;
            break;
        }


    }while(draw!=false);
    return 0;
}
