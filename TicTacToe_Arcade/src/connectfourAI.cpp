//بِسْمِ اللَّـهِ الرَّحْمَـٰنِ الرَّحيمِ
/*
                     " وَأَن لَّيْسَ لِلْإِنسَانِ إِلَّا مَا سَعَى ﴿39﴾ وَأَنَّ سَعْيَهُ سَوْفَ يُرَى ﴿40﴾ ثُمَّ يُجْزَاهُ الْجَزَاء الْأَوْفَى "
*/
// program: connectfourAI.cpp
// purpose: AI for connect four
// Author name & ID : Ahmed Karam(20221012)
// Email: ahmedkaram2@hotmail.com 
// Date: December 2023 
// version:1.0
// section: S25
// TA : Maya Ahmed

#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include<bits/stdc++.h>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

// Implementation of connectfourAI class
connectfourAI::connectfourAI(char symbol , int dimension) :Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

void connectfourAI::get_move(int & x , int & y)
{
    x = (int) ((rand()/(RAND_MAX + 1.0) * ((dimension-1)))+1);
    y = (int) ((rand()/(RAND_MAX + 1.0) * ((dimension-1)))+1);
    if ((Board::board[x-1][y]!=0 &&board[x-1][y]==symbol))
    {
        x=x;
        y=y;
    }
    else if((Board::board[x][y-1]!=0 &&board[x][y-1]==symbol))
    {
        x=x;
        y=y;
    }
    else if((Board::board[x+1][y]!=0 &&board[x+1][y]==symbol))
    {
        x=x;
        y=y;
    }
    else if((Board::board[x][y+1]!=0 &&board[x][y+1]==symbol))
    {
        x=x;
        y=y;
    }
    else if((Board::board[x+1][y+1]!=0 &&board[x+1][y+1]==symbol))
    {
        x=x;
        y=y;
    }
    else if((Board::board[x+1][y-1]!=0 &&board[x+1][y-1]==symbol))
    {
        x=x;
        y=y;
    }
    else if((Board::board[x-1][y+1]!=0 &&board[x-1][y+1]==symbol))
    {
        x=x;
        y=y;
    }
    else if((Board::board[x-1][y-1]!=0 &&board[x-1][y-1]==symbol))
    {
        x=x;
        y=y;
    }
    else
    {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    }
    
}

   bool connectfourAI :: update_board (int x, int y, char mark)
   {
         // Only update if move is valid
   if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0 )) 
   {
         //Hard coding the drop move
   if(x==5)
   {
   board[x][y] = toupper(mark);
   n_moves++;
   return true;
   }
   if(x==4)
   {
      if (board[5][y]==0)
      {
         board[5][y] = toupper(mark);
         n_moves++;
         return true;
      }
      else
      {
         board[x][y] = toupper(mark);
         n_moves++;
         return true;
      }
   }
   if(x==3)
   {
      if (board[4][y]==0)
      {
         if (board[5][y]==0)
         {
            board[5][y] = toupper(mark);
            n_moves++;
            return true;
         }
         else
         {
            board[4][y] = toupper(mark);
            n_moves++;
            return true;
         }
      }
   else 
   {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   }
   if(x==2)
   {
      if(board[3][y]==0)
      {
      if (board[4][y]==0)
      {
         if (board[5][y]==0)
         {
            board[5][y] = toupper(mark);
            n_moves++;
            return true;
         }
         else
         {
            board[4][y] = toupper(mark);
            n_moves++;
            return true;
         }
      }
      else
      {
         board[3][y]= toupper(mark);
         n_moves++;
         return true;
      }
      }
   else
   {
   board[x][y] = toupper(mark);
   n_moves++;
   return true;
   }
   }
   if(x==1)
   {
      if(board[2][y]==0)
      {
      if(board[3][y]==0)
      {
      if (board[4][y]==0)
      {
         if (board[5][y]==0)
         {
            board[5][y] = toupper(mark);
            n_moves++;
            return true;
         }
         else
         {
            board[4][y] = toupper(mark);
            n_moves++;
            return true;
         }
      }
      else
      {
         board[3][y]= toupper(mark);
         n_moves++;
         return true;
      }
      }
      else
      {
         board[2][y]= toupper(mark);
         n_moves++;
         return true;
      }
      }
   else
   {
   board[x][y] = toupper(mark);
   n_moves++;
   return true;
   }
}
if(x==0)
{
   if(board[1][y]==0)
   {
      if(board[2][y]==0)
      {
      if(board[3][y]==0)
      {
      if (board[4][y]==0)
      {
         if (board[5][y]==0)
         {
            board[5][y] = toupper(mark);
            n_moves++;
            return true;
         }
         else
         {
            board[4][y] = toupper(mark);
            n_moves++;
            return true;
         }
      }
      else
      {
         board[3][y]= toupper(mark);
         n_moves++;
         return true;
      }
      }
      else
      {
         board[2][y]= toupper(mark);
         n_moves++;
         return true;
      }
      }
      else
      {
         board[1][y]= toupper(mark);
         n_moves++;
         return true;
      }
   }
   else
   {
   board[x][y] = toupper(mark);
   n_moves++;
   return true;
   }  
}
}
   else 
   return false;
}
   void connectfourAI ::display_board()
   {
   for (int i: {0,1,2,3,4,5}) {
      cout << "\n| ";
      for (int j: {0,1,2,3,4,5,6}) 
      {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n-----------------------------------------------------------------";
   }
   cout << endl;

   }
   bool connectfourAI ::is_winner()
   {
   if (n_moves<7)
   {
      return false;
   }
   
   //Checks on Rows  
   for(int i = 5 ; i >= 0 ; i--)
   {
      for(int j = 0 ; j < 4 ; j++)
   {
   if 
   ( ( (board[i][j]==board[i][j+1])&&(board[i][j+1]==board[i][j+2])&&(board[i][j+2]==board[i][j+3])&&(board[i][j+3])!=0)  )
   {
      return true;
   }
   }
   }
   //Checks on Columns
   for (int j = 0 ; j < 7 ; j++)
   {
      for (int i = 5; i >=3 ; i--)
      {
      if 
      ( ( (board[i][j]==board[i-1][j])&&(board[i-1][j]==board[i-2][j])&&(board[i-2][j]==board[i-3][j])&&(board[i-3][j])!=0)  )
      {
         return true;
      }
      }
   }
   if(n_moves > 9)
   {
      for(int i = 0 ; i < 3 ; i++)
      {
         for (int j = 0; j < 4; j++)
         {
            if ( (board[i][j] == board[i+1][j+1]) && (board[i+1][j+1]== board[i+2][j+2])&& (board[i+2][j+2] == board[i+3][j+3]) && (board[i+3][j+3] != 0) )
            {
               return true;
            }
         }         
      }

      for(int i = 0 ; i < 3 ; i++)
      {
         for (int j = 6; j >= 3; j--)
         {
            if ( (board[i][j] == board[i+1][j-1]) && (board[i+1][j-1]== board[i+2][j-2])&& (board[i+2][j-2] == board[i+3][j-3]) && (board[i+3][j-3] != 0) )
            {
               return true;
            }
         }         
      }

   }
   return false;
   }
   bool connectfourAI ::is_draw()
   {
      return (n_moves == 42 && !is_winner());
   }
   bool connectfourAI :: game_is_over()
   {
   //number of possible moves 7x6 
    return n_moves >= 42;
   }