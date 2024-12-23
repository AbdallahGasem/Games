


#include <iostream>
#include<algorithm>
#include <random>
#include <iomanip>
#include"../include/BoardGame_Classes.hpp"

five_x_five_board :: five_x_five_board() {
    // setting the grid 5x5:
    n_rows = n_cols = 5 ;
    // intializing each postion in the 2d array with 0 :
    board = new char*[n_rows];  // as board is a ptr that points to a ptr
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }


}

bool five_x_five_board :: update_board(int x, int y, char mark) {

    // Only update if move is valid by checking if the input range is [0,4] :
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        // skiping square no (1,5) input :

//        if(x == 0 && y == 4){
//            board[x][y] = toupper(mark);
//        }

        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void five_x_five_board :: display_board() {

    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            // skiping square no (1,5)
            if (i == 0 && j == 4)
            {
                continue;
            }

            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n--------------------------------------------";
    }
    cout << endl;

}

bool five_x_five_board :: is_winner() {
    // considering that one point can be counted or appear more than once

    for (int i : {0,1,2}) {
        for (int j : {0,1,2}) {

            // detecting horizontal wins :
            if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2])
            {
                detect_wining_mark(char(board[i][j]));

            }

            // detecting vertical wins :
            if( board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] )
            {
                detect_wining_mark(char(board[i][j]));
            }

        }


    }
    /////////////////////////////////////////////////////////////////////////////////////////////////

    /* detecting right diagonals wins */
    // detecting main right diagonal wins : 3 probabilities :
    if(board[0][0]== board[1][1] && board[1][1]== board[2][2])
    {
        detect_wining_mark(char(board[0][0]));
    }

    if(board[1][1] == board[2][2] && board[2][2] == board[3][3]  )
    {
        detect_wining_mark(char(board[1][1]));
    }

    if(board[2][2]== board[3][3]  && board[3][3] == board[4][4])
    {
        detect_wining_mark(char(board[2][2]));
    }

    // detecting diagonal1 below the main one : 2 probabilities
    if (board[1][0]== board[2][1] && board[2][1] == board[3][2])
    {
        detect_wining_mark(char(board[1][0]));
    }

    if(board[2][1]== board[3][2] && board[3][2] == board[4][3])
    {
        detect_wining_mark(char(board[2][1]));
    }

    // detecting diagonal2 below the main one : 1 probability
    if (board[2][0]== board[3][1] && board[3][1] == board[4][2])
    {
        detect_wining_mark(char(board[2][0]));
    }

    // detecting diagonal1 above main one : 2 probabilities
    if (board[0][1]== board[1][2] && board[1][2] == board[2][3])
    {
        detect_wining_mark(char(board[0][1]));
    }

    if(board[1][2] == board[2][3] && board[2][3] == board[3][4])
    {
        detect_wining_mark(char(board[1][2]));
    }

    // detecting diagonal2 above main : 1 probability
    if(board[0][2]== board[1][3] && board[1][3]  == board[2][4])
    {
        detect_wining_mark(char(board[0][2]));
    }

    ///////////////////////////////////////////////////////////////////////////

    /* detecting left diagonals wins */
    // detecting main left diagonal wins : 2 probabilities
    if(board[1][3]== board[2][2] && board[2][2]== board[3][1])
    {
        detect_wining_mark(char(board[1][3]));
    }

    if(board[2][2] == board[3][1] && board[3][1] == board[4][0]  )
    {
        detect_wining_mark(char(board[2][2]));
    }

    // detecting diagonal1 below the main one : 2 probabilities
    if (board[1][4]== board[2][3] && board[2][3] == board[3][2])
    {
        detect_wining_mark(char(board[1][4]));
    }

    if(board[2][3]== board[3][2] && board[3][2] == board[4][1])
    {
        detect_wining_mark(char(board[2][3]));
    }

    // detecting diagonal2 below the main one : 1 probability
    if (board[2][4]== board[3][3] && board[3][3] == board[4][2])
    {
        detect_wining_mark(char(board[2][4]));
    }

    // detecting diagonal1 above main one : 2 probabilities
    if (board[0][3]== board[1][2] && board[1][2] == board[2][1])
    {
        detect_wining_mark(char(board[0][3]));
    }

    if(board[1][2] == board[2][1] && board[2][1] == board[3][0])
    {
        detect_wining_mark(char(board[1][2]));
    }

    // detecting diagonal2 above main : 1 probability
    if(board[0][2]== board[1][1] && board[1][1]  == board[2][0])
    {
        detect_wining_mark(char(board[0][2]));
    }



    /////////////////////////////////////////////////////////////////////////////////////////////

    if(n_moves == 24) {
        // declaring the winner :
        if (X_noof_wins > O_noof_wins) {
            cout << "\nplayer with x wins by the highest no of three in a row = " << X_noof_wins << endl;
        }

        else if (O_noof_wins > X_noof_wins) {
            cout << "\nplayer with O wins by the highest no of three in a row = " << O_noof_wins << endl;
        }

        else if (X_noof_wins == O_noof_wins)
        {
            cout << "error in calculation\n " ;
            cout << "x no of wins = "<< X_noof_wins << endl;
            cout << "o no of wins = "<< O_noof_wins << endl;

        }

        else{
            cout << "the Game is a Draw !\n" ;
        }


    }


    return false ;

}

void five_x_five_board :: detect_wining_mark(char x) {
    switch (x) {
        case 'x':
        case 'X':
            X_noof_wins++;
            break;

        case 'o':
        case 'O':
            O_noof_wins++;
            break;

        default:
            break;
    }

}

bool five_x_five_board :: is_draw() {
    return (n_moves == 24 && !is_there_a_winner()) ;
}

bool five_x_five_board :: game_is_over() {
    return n_moves >= 24 ;
}

bool five_x_five_board::is_there_a_winner() const {

    if ((X_noof_wins != 0 || O_noof_wins != 0) && (X_noof_wins != O_noof_wins) )
    {
        return true;
    }

    else
    {
        return false;
    }

}

