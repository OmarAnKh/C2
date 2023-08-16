#include <iostream>
using namespace std;
void rollDices(int *first_number, int *seconde_number);
void rollProb(int dice[][6], int numberOfRolls);

int main()
{

    srand(time(NULL));
    int times;
    int dice[6][6] = {0};
    cout << " enter the number of times you want to test : \n";
    cin >> times;
    rollProb(dice, times);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << double(dice[i][j]) / times << "\t||\t";
        }
        cout << "\n";
    }
}

void rollDices(int *first_number, int *seconde_number)
{

    *first_number = rand() % 6 + 0;
    *seconde_number = rand() % 6 + 0;
}

void rollProb(int dice[][6], int numberOfRolls)
{
    for (int i = 0; i < numberOfRolls; i++)
    {
        int first_V, second_V;
        rollDices(&first_V, &second_V);
        dice[first_V][second_V]++;
    }
}