#include <iostream>
using namespace std;

void print(char board[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 'Q')
                cout << board[i][j] << " ";
            else
                cout << "_ ";
        }
        cout << endl;
    }
}
bool safe(char board[8][8], int row, int j)
{
    // row check
    for (int i = row; i >= 0; i--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    int r = row;
    int c = j;
    // checking for left uppr
    // check both row and column till row and column is greater than 0
    while (r >= 0 && c >= 0)
    {
        if (board[r][c] == 'Q')

            return false;
        r--;
        c--;
    }
    r = row;
    c = j;
    // right uppp diagn
    while (r >= 0 && c < 8)
    {
        if (board[r][c] == 'Q')
        {
            return false;
        }
        r--;
        c++;
    }
    return true;
}
// declaring the function
bool solvenqueens(char board[8][8], int row, int n)
{
    // base case
    if (row == n)
    {
        // if row is filled then print
        print(board);
        return true;
    }
    // go to column
    for (int j = 0; j < 8; j++)
    {
        if (safe(board, row, j))
        {
            // place the queen
            board[row][j] = 'Q';
            // we call the next row because i clear the previous row
            int ans = solvenqueens(board, row + 1, n);
            if (ans == true)
            {
                return true;
            }
            // if it is not placing on write then changing queen position to blank
            board[row][j] = ' ';
        }
    }
    // after checking all the column of row if true then no problem upper part will run
    // but if false it will return false
    return false;
}
int main()
{
    // board of 8x8
    char board[8][8];
    // calling the function 0 = first row and 8 is total no. of cells
    solvenqueens(board, 0, 8);
}