// بسم الله الرحمن الرحيم //

// Program: Q6 sheet 2
// Purpose: Assignment 3
// Author:  Abdallah Gasem
// ID :  20221101
// Date: 8 DEC 
// Version: 1.0

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

class Universe
{

public:
    int grid_gen1[20][20] ;
    int grid_gen2[20][20] ;
    vector<pair<int,int>>user_input;
    int count = 0 ;
    int alive_neighbors_count = 0 ; 
    int control = 0 ;

public:
    void intialize();           // genrates a starting layout.  (done)
    void reset();               // sets all cells as dead. (done)
    int  count_neighbors(int sqr_row_no , int sqr_col_no); // returns the number of alive neighbors , AKA , the surrounding 8 squares. allocates squres by its ij no in grid_gen1 (done) 
    void display_now();             // shows the game status on the console.  (done)
    void display_then();             // shows the game status on the console.  (done)
    void next_generation(int row_no , int col_no);     // produces a new state of the game based on the transition rules. (done)
    void run();         // to start the game for a certain number of runs.
    // bool check();               // checks if all cells are dead after each iteration.
    // void survived();            // returns the survived cells after each iteration.
    void set();    // sets the living cells selected by user in the first of the game. (done)
    
};


// grids intialization 
void Universe :: intialize()
{
    for (int i = 0 ; i < 20 ; i++)
    {
        for (int j = 0 ; j < 20 ; j++)
        {
            grid_gen1[i][j] = 0 ;
        }
        
    }

    for (int i = 0 ; i < 20 ; i++)
    {
        for (int j = 0 ; j < 20 ; j++)
        {
            grid_gen2[i][j] = 0 ;
        }
        
    }

}


// Restting all live cells to dead ones 
void Universe :: reset()
{
    for (int i = 0 ; i < 20 ; i++)
    {
        for (int j = 0 ; j < 20 ; j++)
        {
            if (grid_gen1[i][j] == 1)
            {
                grid_gen1[i][j] = 0 ;
            }

            else
            {
                continue ;
            }
            
        }
        
    }
}


// returns the number of alive neighbors
int Universe ::  count_neighbors(int sqr_row_no , int sqr_col_no)
{
    alive_neighbors_count = 0;
    /* the alocated sqr is ij (skipping its count) */

    // sqr no i-1 , j-1
    if (grid_gen1[sqr_row_no-1][sqr_col_no-1] == 1 )
    {
        alive_neighbors_count++ ;
    }

    // sqr no i-1 , j
    if (grid_gen1[sqr_row_no-1][sqr_col_no] == 1)
    {
        alive_neighbors_count++ ;
        
    }

    // sqr no i-1 , j+1
    if (grid_gen1[sqr_row_no-1][sqr_col_no+1] == 1 )
    {
        alive_neighbors_count++ ;
    }

    // sqr no i , j-1
    if (grid_gen1[sqr_row_no][sqr_col_no-1] == 1)
    {
        alive_neighbors_count++ ;
        
    }

    // sqr no i , j+1
    if (grid_gen1[sqr_row_no][sqr_col_no+1] == 1 )
    {
        alive_neighbors_count++ ;
    }

    // sqr no i+1 , j-1
    if (grid_gen1[sqr_row_no+1][sqr_col_no-1] == 1)
    {
        alive_neighbors_count++ ;
        
    
    }
    // sqr no i+1 , j
    if (grid_gen1[sqr_row_no+1][sqr_col_no] == 1 )
    {
        alive_neighbors_count++ ;
    }

    // sqr no i+1 , j+1
    if (grid_gen1[sqr_row_no+1][sqr_col_no+1] == 1)
    {
        alive_neighbors_count++ ;
        
    }

    return  alive_neighbors_count ;
}


// displays the Current grid_gen1 state
void Universe :: display_now() 
{
    cout << "current generation : \n";
    cout << endl;
    for (int i = 0 ; i < 20 ; i++)
    {
        for (int j = 0 ; j < 20 ; j++)
        {
            if (count == 20)
            {
                cout << endl;
                count = 0 ;
            }

            count++;
            cout << grid_gen1[i][j] ;
        }
        
    }
    count = 0 ;
    cout << endl ;
    cout << endl ;
}

// displays the Current grid_gen2 state
void Universe :: display_then() 
{
    cout << "next generation state :\n";
    cout << endl;
    for (int i = 0 ; i < 20 ; i++)
    {
        for (int j = 0 ; j < 20 ; j++)
        {
            if (count == 20)
            {
                cout << endl;
                count = 0 ;
            }

            count++;
            cout << grid_gen2[i][j] ;
        }
        
    }
    count = 0 ;
    cout << endl;
    cout << endl;
}

// sets the edm
void Universe :: set()
{
    int num , a , b , row , col ;
    cout << "\n enter how many squares you are going to set as alive ones : \n" ;
    cin >> num;

    for (int i = 0 ; i < num ; i++)
    {
        cout <<"locate square no. " << i+1 << " seperated by a space : " << endl;
        cin >> a >> b ;
        user_input.push_back(make_pair(a,b)) ;


    }

    for (int x = 0 ; x < num ; x++)
    {
        row = user_input[x].first ;
        col = user_input[x].second ;

        grid_gen1[row][col] = 1 ;

    }
    
    



}


// produces a new state of the game based on the transition rules for each square allocated by user
void Universe :: next_generation(int row_no , int col_no)
{
    control = count_neighbors(row_no , col_no) ;

    /* RULES APPLIED WITHEN THE RANGE OF 8 SQUARES SURROUNDING THE ALLOCATED ONE */
    // under population:
    if (control < 2 )
    {
        grid_gen2[row_no][col_no] = 0 ;
    }

    // over population:
    if (control > 3)
    {
        grid_gen2[row_no][col_no] = 0 ;
    }

    // reproduction :
    if (control == 3)
    {
        grid_gen2[row_no][col_no] = 1 ;
    }
    
}


// to start the game for a certain number of runs
void Universe :: run()
{
    for (int i = 1 ; i < 19 ; i++)
    {
        for (int j = 1 ; j < 19 ; j++)
        {
            next_generation(i,j) ;
            
        }
        
    }

}


    

























// Application
int main()
{
    Universe a ;
    // intializing the grid and displaying its state(0s):
    a.intialize();
    // seting the living cells :
    a.set();
    a.display_now();
    a.run();
    a.display_then();


    return 0 ;
}