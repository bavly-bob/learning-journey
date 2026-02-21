#include <vector>
using namespace std;

void go_right(const vector<vector<int>>& m, vector<int>& res,
              int row, int left, int right)
{
    for (int i = left; i <= right; i++)
        res.push_back(m[row][i]);
}

void go_down(const vector<vector<int>>& m, vector<int>& res,
             int col, int top, int bottom)
{
    for (int i = top; i <= bottom; i++)
        res.push_back(m[i][col]);
}

void go_left(const vector<vector<int>>& m, vector<int>& res,
             int row, int right, int left)
{
    for (int i = right; i >= left; i--)
        res.push_back(m[row][i]);
}

void go_up(const vector<vector<int>>& m, vector<int>& res,
           int col, int bottom, int top)
{
    for (int i = bottom; i >= top; i--)
        res.push_back(m[i][col]);
}

vector<int> snail(const vector<vector<int>>& snail_map)
{
    vector<int> result;
    int rows = static_cast<int>(snail_map.size());
    if (rows == 0) return result;

    int cols = static_cast<int>(snail_map[0].size());
    if (cols == 0) return result;

    for (const auto& row : snail_map)
    {
        if (static_cast<int>(row.size()) != cols) return result;
    }

    result.reserve(static_cast<size_t>(rows) * static_cast<size_t>(cols));

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right)
    {
        go_right(snail_map, result, top, left, right);
        top++;

        go_down(snail_map, result, right, top, bottom);
        right--;

        if (top <= bottom)
        {
            go_left(snail_map, result, bottom, right, left);
            bottom--;
        }

        if (left <= right)
        {
            go_up(snail_map, result, left, bottom, top);
            left++;
        }
    }

    return result;
}
