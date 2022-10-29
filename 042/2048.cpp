/**
 * Sample input:
 *      2     0     0     2
 *      4     16    8     2
 *      2     64    32    4
 *      1024  1024  64    0
 *
 *      [1]
 *
 * Sample output:
 *      2     16    8     4
 *      4     64    32    4
 *      2     1024  64    0
 *      1024  0     0     0
 */
#include <vector>

std::vector<std::vector<int>> run2048(std::vector<std::vector<int>> puzzle, int dir, int &scored)
{
    std::cout << std::endl;

    switch (dir)
    {
    case 0: // LEFT
        for (int row = 0; row < 4; row++)
        {
            int zero = -1, breakable = 0;
            for (int col = 0; col < 4; col++)
            {
                for (int t = col + 1; t < 4; t++)
                {
                    if (puzzle[row][t] == 0 && zero == -1)
                        zero = t;

                    if (puzzle[row][t] != 0 && puzzle[row][col] == 0)
                        puzzle[row][col] = puzzle[row][t], puzzle[row][t] = 0;

                    if (puzzle[row][t] != 0 && puzzle[row][t] == puzzle[row][col])
                        puzzle[row][col] = puzzle[row][col] * 2, puzzle[row][t] = 0, breakable = 1, scored = scored + 1;

                    if (puzzle[row][t] != 0 && puzzle[row][t] != puzzle[row][col])
                    {
                        if (zero != -1)
                            puzzle[row][zero] = puzzle[row][t], puzzle[row][t] = 0;
                        else if (zero == -1)
                            breakable = 1;
                    }

                    if (breakable == 1)
                        break;
                }
                zero = -1, breakable = 0;
            }
        }
        break;
    case 1: // UP
        for (int col = 0; col < 4; col++)
        {
            int zero = -1, breakable = 0;
            for (int row = 0; row < 4; row++)
            {
                for (int t = row + 1; t < 4; t++)
                {
                    if (puzzle[t][col] == 0 && zero == -1)
                        zero = t;

                    if (puzzle[t][col] != 0 && puzzle[row][col] == 0)
                        puzzle[row][col] = puzzle[t][col], puzzle[t][col] = 0;

                    if (puzzle[t][col] != 0 && puzzle[t][col] == puzzle[row][col])
                        puzzle[row][col] = puzzle[row][col] * 2, puzzle[t][col] = 0, breakable = 1, scored = scored + 1;

                    if (puzzle[t][col] != 0 && puzzle[t][col] != puzzle[row][col])
                    {
                        if (zero != -1)
                            puzzle[zero][col] = puzzle[t][col], puzzle[t][col] = 0;
                        else if (zero == -1)
                            breakable = 1;
                    }

                    if (breakable == 1)
                        break;
                }
                zero = -1, breakable = 0;
            }
        }
        break;
    case 2: // RIGHT
        for (int row = 0; row < 4; row++)
        {
            int zero = -1, breakable = 0;
            for (int col = 3; col >= 0; col--)
            {
                for (int t = col - 1; t >= 0; t--)
                {
                    if (puzzle[row][t] == 0 && zero == -1)
                        zero = t;

                    if (puzzle[row][t] != 0 && puzzle[row][col] == 0)
                        puzzle[row][col] = puzzle[row][t], puzzle[row][t] = 0;

                    if (puzzle[row][t] != 0 && puzzle[row][t] == puzzle[row][col])
                        puzzle[row][col] = puzzle[row][col] * 2, puzzle[row][t] = 0, breakable = 1, scored = scored + 1;

                    if (puzzle[row][t] != 0 && puzzle[row][t] != puzzle[row][col])
                    {
                        if (zero != -1)
                            puzzle[row][zero] = puzzle[row][t], puzzle[row][t] = 0;
                        else if (zero == -1)
                            breakable = 1;
                    }

                    if (breakable == 1)
                        break;
                }
                zero = -1, breakable = 0;
            }
        }
        break;
    case 3: // DOWN
        for (int col = 0; col < 4; col++)
        {
            int zero = -1, breakable = 0;
            for (int row = 3; row >= 0; row--)
            {
                for (int t = row - 1; t >= 0; t--)
                {
                    if (puzzle[t][col] == 0 && zero == -1)
                        zero = t;

                    if (puzzle[t][col] != 0 && puzzle[row][col] == 0)
                        puzzle[row][col] = puzzle[t][col], puzzle[t][col] = 0;

                    if (puzzle[t][col] != 0 && puzzle[t][col] == puzzle[row][col])
                        puzzle[row][col] = puzzle[row][col] * 2, puzzle[t][col] = 0, breakable = 1, scored = scored + 1;

                    if (puzzle[t][col] != 0 && puzzle[t][col] != puzzle[row][col])
                    {
                        if (zero != -1)
                            puzzle[zero][col] = puzzle[t][col], puzzle[t][col] = 0;
                        else if (zero == -1)
                            breakable = 1;
                    }

                    if (breakable == 1)
                        break;
                }
                zero = -1, breakable = 0;
            }
        }
        break;
    default:
        break;
    }

    std::cout << std::endl;
    return puzzle;
}