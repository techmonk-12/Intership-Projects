//tictactoe game
#include <iostream>

using namespace std;

class TicTacToe
{
    private:
        char board[3][3];
        char currentPlayer;

    public:
        TicTacToe();
        void displayBoard();
        void makeMove(int row, int col);
        bool checkWin();
        bool checkDraw();
        void switchPlayer();
        void playGame();
};

TicTacToe::TicTacToe()
{
    currentPlayer = 'X';
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void TicTacToe::displayBoard()
{
    cout << "-------------" << endl;
    for(int i=0; i<3; i++)
    {
        cout << "| ";
        for(int j=0; j<3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

void TicTacToe::makeMove(int row, int col)
{
    if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
    {
        board[row][col] = currentPlayer;
    }
    else
    {
        cout << "Invalid move! Try again." << endl;
        int newRow, newCol;
        cout << "Enter row (0-2): ";
        cin >> newRow;
        cout << "Enter column (0-2): ";
        cin >> newCol;
        makeMove(newRow, newCol);
    }
}

bool TicTacToe::checkWin()
{
    // Check rows and columns
    for(int i=0; i<3; i++)
    {
        if((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
           (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer))
        {
            return true;
        }
    }
    // Check diagonals
    if((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
       (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer))
    {
        return true;
    }
    return false;
}

bool TicTacToe::checkDraw()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void TicTacToe::switchPlayer()
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void TicTacToe::playGame()
{
    int row, col;
    while(true)
    {
        cout<<endl;
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        makeMove(row, col);
        if(checkWin())
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        if(checkDraw())
        {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }
        switchPlayer();
    }
}

int main()
{
    TicTacToe game;
    game.playGame();
    return 0;
}