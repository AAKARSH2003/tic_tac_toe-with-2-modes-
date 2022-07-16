#include<iostream>
using namespace std;

char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
void board_display();
void first_player_turn();
void second_player_turn();
void computer_turn();

int count_board(char symbol);
char check_winner();
void computer_vs_player();
void player_vs_player();

int main()
{   
   
    cout<<"Mode 1:Computer vs player"<<endl;
    cout<<"Mode 2:Player vs Player"<<endl;
    cout<<"enter which mode you want to play"<<endl;
    int mode;
    cin>>mode;
    if(mode==1){
        computer_vs_player();
        
        
    }
    else if(mode==2){
        player_vs_player();
        
    }
    else {
        cout<<"please enter a valid mode i.e. either 1 or 2"<<endl;
        
    }
    
    
    board_display();
    return 0;
}



void computer_turn(){
    srand(time(0));
    int choice;
    do{
        choice=rand()%10;
        }
    while(board[choice] != ' ');
    board[choice] ='O';
}


void first_player_turn(){
    while(true){
        cout<<"select your position from 1 to 9";
        int choice;
        cin>>choice;
        choice--;

        if(choice < 0 || choice> 8){
            cout<<"please select your choice from 1 to 9"<<endl;

        }
        else if(board[choice] !=' '){
            cout<<"please select an empty position"<<endl;
        }
        else{
            board[choice]='X';
            break;
        }
    }
}


void second_player_turn(){
    while(true){
        cout<<"select your position from 1 to 9";
        int choice;
        cin>>choice;
        choice--;

        if(choice <0 || choice >8 ){
            cout<<"please select your choice from 1 to 9"<<endl;

        }
        else if(board[choice] !=' '){
            cout<<"please select an empty position"<<endl;
        }
        else{
            board[choice]='O';
            break;
        }
    }
}

int count_board(char symbol){
    int total=0;
    for(int i=0;i<9;i++){
        if(board[i] == symbol)
        total+=1;
    }
    return total;
}


char check_winner(){

    if(board[0] ==board[1] && board[1]==board[2] && board[0] != ' ')
    return board[0];
    if(board[3] ==board[4] && board[4]==board[5] && board[3] !=' ')
    return board[3];
    if(board[6] ==board[7] && board[7]==board[8] && board[6] !=' ')
    return board[6];



    if(board[0] ==board[3] && board[3]==board[6] && board[0] !=' ')
    return board[0];
    if(board[1] ==board[4] && board[4]==board[7] && board[1] !=' ')
    return board[1];
    if(board[2] ==board[5] && board[5]==board[8] && board[2] !=' ')
    return board[2];


    if(board[0] ==board[4] && board[4]==board[8] && board[0] !=' ')
    return board[0];
    if(board[2] ==board[4] && board[4]==board[6] && board[2] !=' ')
    return board[2];
    if(count_board('X') +count_board('O')< 9)
    return 'C';
    else
    return 'D';
}


void computer_vs_player(){
    string player_name;
    cout<<"enter your name:";
    cin>>player_name;
    while(true){
        
        board_display();
        if(count_board('X')==count_board('O')){
            cout<<player_name<<"s Turn."<<endl;
            first_player_turn();

        }

        else{
            computer_turn();
        }
        char winner =check_winner();
        if(winner =='X'){
            
            board_display();
            cout<<player_name<<"won the game."<<endl;
            break;

        }

        else if(winner == 'O'){
            
           board_display();
            cout<< "computer won the game."<<endl;
            break;
        }
        else if (winner =='D'){
            cout<<"game is a draw."<<endl;
            break;
        }
    }
}


void player_vs_player(){
    
    string x_player_name,o_player_name;
    cout<<"enter X Player name";
    cin>>x_player_name;
    cout<<"enter O player name";
    cin>>o_player_name;
    while(true) {
      
        board_display();
        if(count_board('X') == count_board('O')){
            cout<<x_player_name<<"'s Turn."<<endl;
            first_player_turn();
            
        }
        else{
            cout<<o_player_name<<"'s Turn."<<endl;
           second_player_turn();
            
            
        }
        char winner =check_winner();
        if (winner =='X'){
           
            board_display();
            cout<<x_player_name<<"Won the game."<<endl;
            break;
        }
        
        else if(winner=='O'){
           
            board_display();
            cout<<o_player_name<<"won the game."<<endl;
            break;
        }
        else if (winner=='D'){
            cout<<"it is a draw."<<endl;
            break;
            
        }
    }
    
}
void board_display(){
    cout<<"--------------------"<<endl;
    cout<<"   "<<"   |   "<<"   |   "<<endl;
    cout<<"   "<<board[0] <<"  |   "<<board[1]<<"  |   "<<board[2]<<endl;
    cout<<"   "<<"   |    "<<"  |   "<<endl;
    cout<<"--------------------"<<endl;
    cout<<"  "<<"    | "<<"     |  "<<endl;
    cout<<"  "<<board[3]<<"   | "<<board[4]<<"    |  "<<board[5]<<endl;
    cout<<"  "<<"    | "<<"     |  "<<endl;
    cout<<"--------------------"<<endl;
    cout<<"  "<<"    | "<<"     |  "<<endl;
    cout<<"  "<<board[6]<<"   | "<<board[7]<<"    |  "<<board[8]<<endl;
    cout<<"  "<<"    | "<<"     |  "<<endl;
    cout<<"--------------------"<<endl;
}
