#include <array>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check; t: O(n^2), s: O(1)
        for (int r = 0; r < 9; r++)
        {
            std::array<int, 10> vals = {};
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                    continue;
                int val = board[r][c] - '0';
                vals[val]++;
            }

            for (const int &v : vals)
            {
                if (v > 1)
                    return false;
            }
        }

        // column check; t: O(n^2), s: O(1)
        for (int c = 0; c < 9; c++)
        {
            std::array<int, 10> vals = {};
            for (int r = 0; r < 9; r++)
            {
                if (board[r][c] == '.')
                    continue;
                int val = board[r][c] - '0';
                vals[val]++;
            }

            for (const int &v : vals)
            {
                if (v > 1)
                    return false;
            }
        }

        // sub-box check: t: O(n^2), s: O(1)
        for (int boxRow = 0; boxRow < 3; boxRow++)
        {
            for (int boxCol = 0; boxCol < 3; boxCol++)
            {
                std::array<int, 10> vals = {};

                for (int innerRow = 0; innerRow < 3; innerRow++)
                {
                    for (int innerCol = 0; innerCol < 3; innerCol++)
                    {
                        int r = boxRow * 3 + innerRow;
                        int c = boxCol * 3 + innerCol;

                        if (board[r][c] == '.')
                            continue;
                        int val = board[r][c] - '0';
                        vals[val]++;
                    }
                }

                for (const int &v : vals)
                {
                    if (v > 1)
                        return false;
                }
            }
        }

        return true;
    }
};
