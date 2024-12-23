#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "../include/BoardGame_Classes.hpp"
using namespace std;


    pyramid_board::pyramid_board() {
        n_rows = 3;
        n_cols = 5;
        board = new char *[n_rows];
        for (int i = 0; i < n_rows; i++) {
            board[i] = new char[n_cols];
            for (int j = 0; j < n_cols; j++)
                board[i][j] = 0;
        }
    }
    bool pyramid_board::update_board(int x, int y, char mark) {
        // Only update if move is valid
        //fill the places that is out of the game to make sure
        //the player and the random player will not use this places
        board[0][0]='X';
        board[0][1]='X';
        board[1][0]='X';
        board[0][3]='X';
        board[0][4]='X';
        board[1][4]='X';
        if (((x == 0 && y == 2) || ((x == 1) && (y == 1 || y == 2 || y == 3)) ||
             ((x == 2) && (y == 0 || y == 1 || y == 2 || y == 3 || y == 4))) && (board[x][y] == 0)) {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        } else {
            return false;
        }
    }
        bool pyramid_board::is_winner()
        {
        //check if there is three places next making row or column or diagonal have 'X's or 'O's
        //to chech if one of the players wins and then it returns true if this condition occured
            if (( (board[1][1] == board[1][2])&& (board[1][2]==board[1][3])&& (board[1][3]!=0))
                ||((board[2][0] == board[2][1])&& (board[2][1]==board[2][2])&& (board[2][2]!=0))
                ||( (board[2][1] == board[2][2])&& (board[2][2]==board[2][3])&& (board[2][3]!=0))
                ||( (board[2][2] == board[2][3])&& (board[2][3]==board[2][4])&& (board[2][4]!=0))
                ||( (board[0][2] == board[1][2])&& (board[1][2]==board[2][2])&& (board[2][2]!=0))
                ||( (board[0][2] == board[1][1])&& (board[1][1]==board[2][0])&& (board[2][0]!=0))
                ||( (board[0][2] == board[1][3])&& (board[1][3]==board[2][4])&& (board[2][4]!=0)))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool pyramid_board::is_draw()
        {
        //if all the places is full and the is_winner() function returns false
        //then it returns true and this means its draw
            if (n_moves==9)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void pyramid_board::display_board()
        {
        //this function displays only the places needed in the game
        //and update each mark the player put in any place
        //this is the display of the first row
            cout<<"               |(0,2)"<<board[0][2]   <<"|\n";
            cout<<"        ";
        //this is the display of the second row
            for (int i=1;i<4;i++)
            {
                cout<<"|(1,"<<i<<")"<<board[1][i]<<"|";
            }
            cout<<endl;
        //this is the display of the third row
            for (int i=0;i<5;i++)
            {
                cout<<"|(2,"<<i<<")"<<board[2][i]<<"|";
            }
            cout<<endl;

        }
        bool pyramid_board::game_is_over()
        {
        //if the number of moves reaches 9 then the program will not accept any other inputs and will be terminated
        if (n_moves==9)
        {
            return true;
        }else
        {
            return false;
        }
        }