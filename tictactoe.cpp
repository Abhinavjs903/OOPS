
#include <iostream>
#include <memory>
#include <string>
#include <limits>
using namespace std;

// Abstract Base Class
class Player
{
protected:
    string name;
    char symbol;

public:
    Player(string n, char s) : name(n), symbol(s) {}

    virtual void makeMove() = 0;

    virtual ~Player() = default;

    string getName() const
    {
        return name;
    }

    char getSymbol() const
    {
        return symbol;
    }
};

// Derived Class
class HumanPlayer : public Player
{
public:
    HumanPlayer(string n, char s) : Player(n, s) {}

    void makeMove() override
    {
        cout << name << "'s turn (" << symbol << ")\n";
        cout << "Enter row and column (1-3): ";
    }
};

// Board Class
class Board
{
private:
    char grid[3][3];

public:
    Board()
    {
        reset();
    }

    void reset()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                grid[i][j] = ' ';
            }
        }
    }

    void display() const
    {
        cout << "\n";

        for (int i = 0; i < 3; i++)
        {
            cout << " ";

            for (int j = 0; j < 3; j++)
            {
                cout << grid[i][j];

                if (j < 2)
                    cout << " | ";
            }

            cout << "\n";

            if (i < 2)
                cout << "---+---+---\n";
        }

        cout << "\n";
    }

    bool isValidMove(int row, int col) const
    {
        return row >= 0 && row < 3 &&
               col >= 0 && col < 3 &&
               grid[row][col] == ' ';
    }

    bool placeMove(int row, int col, char symbol)
    {
        if (!isValidMove(row, col))
            return false;

        grid[row][col] = symbol;
        return true;
    }

    bool checkWinner(char s) const
    {
        // Check rows and columns
        for (int i = 0; i < 3; i++)
        {
            if ((grid[i][0] == s &&
                 grid[i][1] == s &&
                 grid[i][2] == s) ||

                (grid[0][i] == s &&
                 grid[1][i] == s &&
                 grid[2][i] == s))
            {
                return true;
            }
        }

        // Check diagonals
        if (grid[0][0] == s &&
            grid[1][1] == s &&
            grid[2][2] == s)
            return true;

        if (grid[0][2] == s &&
            grid[1][1] == s &&
            grid[2][0] == s)
            return true;

        return false;
    }

    bool isFull() const
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] == ' ')
                    return false;
            }
        }

        return true;
    }
};

// Game Class
class Game
{
private:
    Board board;
    unique_ptr<Player> players[2];
    int currentPlayer;

public:
    Game() : currentPlayer(0)
    {
        string name1, name2;

        cout << "Enter Player 1 name: ";
        getline(cin, name1);

        cout << "Enter Player 2 name: ";
        getline(cin, name2);

        players[0] = make_unique<HumanPlayer>(name1, 'X');
        players[1] = make_unique<HumanPlayer>(name2, 'O');
    }

    void switchTurn()
    {
        currentPlayer = 1 - currentPlayer;
    }

    void play()
    {
        cout << "\n=== TIC-TAC-TOE ===\n";

        while (true)
        {
            board.display();

            Player *player = players[currentPlayer].get();

            int row, col;

            player->makeMove();

            if (!(cin >> row >> col))
            {
                cout << "Invalid input! Enter numbers only.\n";

                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                continue;
            }

            row--;
            col--;

            if (!board.placeMove(row, col, player->getSymbol()))
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (board.checkWinner(player->getSymbol()))
            {
                board.display();

                cout << "Winner: " << player->getName()
                     << " (" << player->getSymbol() << ")\n";

                break;
            }

            if (board.isFull())
            {
                board.display();
                cout << "Game Draw!\n";
                break;
            }

            switchTurn();
        }
    }
};

int main()
{
    Game game;
    game.play();

    return 0;
}
