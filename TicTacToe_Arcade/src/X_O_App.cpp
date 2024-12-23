// program: X_O_App.cpp
// purpose: X_O_Variation Games
// Authors names & IDs : Ahmed Karam(20221012) - Mohamed Abdelhamid(20220294) - Abdallah Gassem (20221101)
// Email: ahmedkaram2@hotmail.com 
// Date: November 2023 
// version:1.0
// section: S25
// TA : Maya Ahmed 

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int gamechoosing;
    cout << "Welcome to Tic Tac Toe!" << endl<<"Choose your desired game:"<<endl<<"1-Tic Tac Toe"<<endl<<"2-ConnectFour"<<endl<<"3-pyramid Tic Tac Toe"<<endl<<"4-FiveXFive"<<endl;
    cin>>gamechoosing;
    if (gamechoosing==1)
    {
        int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer else choose 2: ";
    while(true)
    {
    try
    {
        cin >> choice;
        if(choice != 1 && choice!=2)
        {throw std::invalid_argument("Invalid Input! Please enter either 1 or 2.");}

        else break;
    }
    
    catch(std::invalid_argument &e){cout<<e.what()<<'\n';}
    }
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new X_O_Board, players);
    x_o_game.run();
    system ("pause");
    }
    else if(gamechoosing==2)
    {
        int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer else choose 2: ";
    while(true)
    {
    try
    {
        cin >> choice;
        if(choice != 1 && choice!=2)
        {throw std::invalid_argument("Invalid Input! Please enter either 1 or 2.");}

        else break;
    }
    
    catch(std::invalid_argument &e){cout<<e.what()<<'\n';}
    }
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 7);

    GameManager x_o_game (new connectfour, players);
    x_o_game.run();
    system ("pause");
    }
    else if(gamechoosing==3)
    {
        int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer else choose 2: ";
    while(true)
    {
    try
    {
        cin >> choice;
        if(choice != 1 && choice!=2)
        {throw std::invalid_argument("Invalid Input! Please enter either 1 or 2.");}

        else break;
    }
    
    catch(std::invalid_argument &e){cout<<e.what()<<'\n';}
    }
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);

    GameManager x_o_game (new pyramid_board, players);
    x_o_game.run();
    system ("pause");
    }
    // else
    // {
    //     int choice;
    // Player* players[2];
    // players[0] = new Player (1, 'x');

    // cout << "Welcome to FCAI X-O Game. :)\n";
    // cout << "Press 1 if you want to play with computer else choose 2: ";
    // while(true)
    // {
    // try
    // {
    //     cin >> choice;
    //     if(choice != 1 && choice!=2)
    //     {throw std::invalid_argument("Invalid Input! Please enter either 1 or 2.");}

    //     else break;
    // }
    
    // catch(std::invalid_argument &e){cout<<e.what()<<'\n';}
    // }
    // if (choice != 1)
    //     players[1] = new Player (2, 'o');
    // else
    //     //Player pointer points to child
    //     players[1] = new RandomPlayer ('o', 5);

    // GameManager x_o_game (new five_x_five_board, players);
    // x_o_game.run();
    // system ("pause");

    // }
    //     cout<<"hi"<<endl;
}
