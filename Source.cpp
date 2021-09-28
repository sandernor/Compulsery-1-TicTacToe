#include "declare.h"


void playerInput()
{
    std::cin >> ans;        // defining ans as the number the player inserted

    switch (ans)            // using the ans (answer) to find out what coordinates on the board to use
    {
    case '1':
        x = 0;
        y = 0;

        break;

    case '2':
        x = 0;
        y = 1;
        break;

    case '3':
        x = 0;
        y = 2;

        break;
    case '4':
        x = 1;
        y = 0;

        break;
    case '5':
        x = 1;
        y = 1;

        break;
    case '6':
        x = 1;
        y = 2;

        break;
    case '7':
        x = 2;
        y = 0;

        break;
    case '8':
        x = 2;
        y = 1;

        break;
    case '9':
        x = 2;
        y = 2;

        break;

    // in case the player does not choose a number form 1-9, the default case tells the player what went wrong and runs this function again
    default:
        std::cout << " That is not a space on the board " << std::endl << std::endl;
        playerInput();
    }

    if (boardCords[x][y] != 'X' && boardCords[x][y] != 'O')         // checks if the space on the board is empty
    {
        boardCords[x][y] = letter;              // Then sets the space to letter, which by default is "X"
    }

    //if the space is not empty, the game tells the player and runs the function again
    else
    {
        std::cout << " Dont you even try, go again " << std::endl << std::endl;
        playerInput();
    }

    // switches the letter variable back and forth from X and O and the win variable from one and two every time the function runs
    if (letter == 'O')
    {
        letter = 'X';
        win = "two";
    }
    else
    {
        letter = 'O';
        win = "one";
    }
}

bool winner()
{
    // this for loop runs 3 times and adding the value of 1 to the variable i every time
    for (int i = 0; i < 3; i++)
    {
        //checks every row for a winning letter
        if (boardCords[i][0] == boardCords[i][1] && boardCords[i][1] == boardCords[i][2])
        {
            return true;
        }

        //checks every collumn for a winning letter
        else if (boardCords[0][i] == boardCords[1][i] && boardCords[1][i] == boardCords[2][i])
        {
            return true;
        }
    }
    //checks one diagonal for a winning letter
    if (boardCords[0][0] == boardCords[1][1] && boardCords[1][1] == boardCords[2][2])
    {
        return true;
    }

    // checks the other diagonal for a winning letter
    else if (boardCords[0][2] == boardCords[1][1] && boardCords[1][1] == boardCords[2][0])
    {
        return true;
    }
        
}

void ticTacToe()
{
    for (int i = 1; i < 10; i++)    //this will run the function 9 times, unless a player wins before that
    {
       

        playerInput();              // calls the player input function
        // draws board by using a for loop and the boardCords array
        for (int i = 0; i < 3; i++)
        {
            std::cout << " | " << boardCords[i][0] << " | " << boardCords[i][1] << " | " << boardCords[i][2] << " | " << std::endl;
        }

        // calls the winner function and if a player has won it exits this function and continues the main function
        if (winner() == true) 
        {
            break;
        }

    }
}

int main()
{
    
    do      // making a loop that runs as long as the player hasn't said no to keep playing
    {
        //resetting variables, array and boolean
        char nmbr = '0';
        for (int i = 0; i < 3; i++)
        {

            for(int z = 0; z < 3; z++)
            {
                nmbr++;
                boardCords[i][z] = nmbr;
            }
        }

        x = {};
        y = {};
        letter = 'X';
        win = {};
        playAgain = true;

        ans = {};
        ansTwo = {};
        
        //printing welcome text, then draws board and calls the tic tac toe function
        std::cout << std::endl << " ******** Welcome to Tic Tac Toe ******** " << std::endl << std::endl;
        for (int i = 0; i < 3; i++)
        {
            std::cout << " | " << boardCords[i][0] << " | " << boardCords[i][1] << " | " << boardCords[i][2] << " | " << std::endl;
        }

        ticTacToe();

        //runs winner function and if there's a winner, tell who the player is and ask if they want to play again
        //if they do, run from do loop, if not exit code
        if (winner() == true)
        {
            std::cout << " Player " << win << " is the winner!" << std::endl;
            std::cout << " Wanna play again? (answer with y or n) " << std::endl << std::endl;
            std::cin >> ansTwo;
            if (ansTwo == 'n')
            {
                playAgain = false;
                exit(0);
            }
        }
        // if there's no winner, tell the player it's a draw and ask if they want to play again
        //if they do, run from do loop, if not exit code
        else
        {
            std::cout << std::endl << " It is a draw!";

            std::cout << " Wanna play again? (answer with y or n) " << std::endl << std::endl;
            std::cin >> ansTwo;
            if (ansTwo == 'n')
            {
                playAgain = false;
            }
        }
    } while (playAgain == true);

    //return 0 tho for real you feel yes yes im tired of writing now emoticon emoticon, earth calls, should i answer
    return 0;
}

