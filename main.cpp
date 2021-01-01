//Find the key

#include <iostream>
#include <string>
#include <random>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
using namespace std;

void draw_map(int r,int c,int n){
for(int x=0;x<n;x++){
    cout<<" _";
}
cout<<endl;
for(int i=1;i<=n;i++){
    cout<<"|";
    for(int j=1;j<=n;j++){
        if(i==r && j==c)
            cout<<"X|";
        else
            cout<<"_|";
    }
    cout<<endl;
}
}

string valid_move(int r,int c,int n){
vector<string> moves;
string move;
if(r != 1)
    moves.push_back("up");
if(r != n)
    moves.push_back("down");
if(c != 1)
    moves.push_back("left");
if(c != n)
    moves.push_back("right");
cout<<endl;
again:{
    cout<<"Choose any one move:"<<endl;
    for(string x:moves)
        cout<<x<<endl;
    cout<<"Enter your move:";
    cin>>move;
    for(string x:moves){
        if(move==x)
            return move;
    }
            cout<<"Please enter a valid move from the given choices!!"<<endl;
            goto again;
    }
}

int main()
{

    system("cls");
    srand(time(0));
    int size_of_map;

    system("color 8");
    cout<<"WELCOME!!Let's see if you can find the KEY or hit the DRAGON"<<endl;
    sleep(2);
    cout<<"Enter the size of the map in which you want to play:";
    cin>>size_of_map;
    int user_r=(rand()%size_of_map)+1;
    int user_c=(rand()%size_of_map)+1;
    int dragon_r=(rand()%size_of_map)+1;
    int dragon_c=(rand()%size_of_map)+1;
    int key_r=(rand()%size_of_map)+1;
    int key_c=(rand()%size_of_map)+1;
    while(true){
    system("cls");
    system("color 3");
    draw_map(user_r,user_c,size_of_map);
    string move=valid_move(user_r,user_c,size_of_map);
    if(move=="up")
        user_r-=1;
    if(move=="down")
        user_r+=1;
    if(move=="left")
        user_c-=1;
    if(move=="right")
        user_c+=1;
    if(user_r==key_r && user_c==key_c){
        system("color 2");
        cout<<"Hurray!! You Won ,You got the KEY";
        break;
    }
    else if(user_r==dragon_r && user_c==dragon_c){
        system("color 4");
        cout<<"Ooops!! You hit the DRAGON";
        break;
    }
    }
    return 0;
}
