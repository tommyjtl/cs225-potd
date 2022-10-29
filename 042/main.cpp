#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "2048.cpp"

int keypress()
{
    int c;
    system("/bin/stty raw"), system("/bin/stty -echo");
    c = getc(stdin);
    system("/bin/stty echo");
    system("/bin/stty cooked");
    return c;
}

std::vector<std::vector<int>> generate(std::vector<std::vector<int>> game, bool &failed)
{
    int find[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int it = 0, itt = 0;

    while (it < 16)
    {
        if (game[(int)(4 * ((double)it / (double)16))][(it % 4)] == 0)
            find[itt] = it, itt = itt + 1;
        it++;
    }

    if (itt == 0)
    {
        failed = true;
    }
    else
    {
        int ju = rand() % itt + 0;
        game[(int)(4 * ((double)find[ju] / (double)16))][(find[ju] % 4)] = 2;
    }

    return game;
}

void print_board(std::vector<std::vector<int>> game)
{
    for (int i = 0; i < 4; i++)
    {
        if (i >= 0 && i < 3)
        {
            std::cout << "+-------------------------------+" << std::endl;
            std::cout << "| "
                      << game[i][0] << "\t| " << game[i][1] << "\t| "
                      << game[i][2] << "\t| " << game[i][3] << "\t|"
                      << std::endl;
        }
        else
        {
            std::cout << "+-------------------------------+" << std::endl;
            std::cout << "| "
                      << game[i][0] << "\t| " << game[i][1] << "\t| "
                      << game[i][2] << "\t| " << game[i][3] << "\t|"
                      << std::endl;
            std::cout << "+-------------------------------+" << std::endl;
        }
    }
}

void print_failed(int score)
{
    std::cout << "+-------+-------+-------+-------+" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (i == 3)
            std::cout << "|          GAME OVER!           |" << std::endl;
        else
            std::cout << "|                               |" << std::endl;
    }
    std::cout << "+-------+-------+-------+-------+" << std::endl;
    std::cout << "TOTAL SCORE: " << score << "\n"
              << std::endl;
}

int main()
{
    std::vector<std::vector<int>> game = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int score = 0;
    bool failed = false;

    game = generate(game, failed);
    std::cout << "\033[2J\033[1;1H";
    std::cout << "Press WASD to move, Q to quit." << std::endl;
    print_board(game);

    do
    {
        int key = keypress();

        if (key == 119)
        {
            int scored = 0;
            game = run2048(game, 1, scored);
            print_board(game);
            score = score + scored;
        }
        else if (key == 97)
        {
            int scored = 0;
            game = run2048(game, 0, scored);
            print_board(game);
            score = score + scored;
        }
        else if (key == 115)
        {
            int scored = 0;
            game = run2048(game, 3, scored);
            print_board(game);
            score = score + scored;
        }
        else if (key == 100)
        {
            int scored = 0;
            game = run2048(game, 2, scored);
            print_board(game);
            score = score + scored;
        }

        std::cout << "\033[2J\033[1;1H";
        std::cout << "Press WASD to move, Q to quit." << std::endl;
        game = generate(game, failed);
        if (!failed)
        {
            print_board(game);
            std::cout << "Score: " << score * 100 << std::endl;
        }
        else
        {
            print_failed(score * 100);
            break;
        }

        if (key == 113)
            break;
    } while (true);

    return 0;
}
