/*
 * Tic-Tac-Toe Game 
 * Single Player Game
 * Not a very Smart Game but it is basic one
 * @author: M Santosh Dora
 * @reference: The Complete Reference (book)
 * 
 */
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class ticTacToe{
 char board[3][3];    //This is the Board

public:
    ticTacToe(){
     for(int i=0;i<3;i++){
      for(int j = 0;j<3;j++){
       board[i][j] = ' ';
      }
     }
    }
   void displayBoard();
   char check();
   void getPlayerMove();
   void getComputerMove();
};

void ticTacToe::displayBoard(){
 for(int i=0;i<3;i++){
  for(int j=0;j<3;j++){
   cout<<board[i][j]<<" ";
  }
  cout<<endl<<"-|-|-\n";
 }

}


char ticTacToe::check(){
 
//Check Row
   for(int i = 0;i<3;i++)
   {
     if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
         return board[i][0];    
     } 
   }

//Check Column
 for(int i=0;i<3;i++){
   if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
     return board[0][i]; 
   }
 }

//Check Diagonal
if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
   return board[0][0];
 }

//Check Second diagonal
if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
  return board[0][2];
}

return ' ';
}

void ticTacToe::getPlayerMove(){
  displayBoard();
  cout<<"Enter the Position: \n";
  int x; 
  int y;
  cin>>x>>y;
  if(board[x][y]!=' '){
   cout<<"Invalid Move!! Try Again..\n";
   getPlayerMove();
  }
  else
    board[x][y] ='X';
}

void ticTacToe::getComputerMove(){
  int i,j,ch=-1;
 for( i=0;i<3;i++){
   for(j=0;j<3;j++){
    if(board[i][j]==' '){
      board[i][j]='O';
      ch = 0;
     break;
    }
   }
if(ch==0){
 break;
}


 }


if(i*j==9){
 cout<<"DRAW\n";
 exit(0);
}
}

int main(){
 ticTacToe game;
 cout<<"This is the game of TicTacToe:\n";
 cout<<"Player Move=X and Computer Move = O\n";
 cout<<"Status of the Board\n";
 char done;
  done = ' ';
 while(done == ' '){
  cout<<"\nStatus of the Board\n";
 // game.displayBoard();
  game.getPlayerMove();
  done = game.check();
  if(done == ' '){
   cout<<"\nStatus of the Board:\n";
   game.displayBoard();
   game.getComputerMove();
   done = game.check();
  }
  else
    break;
 }

 cout<<"\nStatus of the board:\n";
 game.displayBoard();
 if(done == 'X'){
 
  cout<<"Player Wins\n";
 }else{
  cout<<"Computer Wins\n";
 }
 return 0;
}

