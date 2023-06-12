#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int shortestPath(vector<vector<int>>& maze, int start_row, int start_col) {
    int rows = maze.size();
    int cols = maze[0].size();

    // Kiểm tra ô xuất phát có hợp lệ không
    if (maze[start_row][start_col] == 1) {
        return -1;
    }

    // Tạo ma trận visited để theo dõi các ô đã được duyệt
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[start_row][start_col] = true;

    // Tạo hàng đợi (queue) để duyệt theo chiều rộng
    queue<tuple<int, int, int>> q; // (row, col, distance)
    q.push(make_tuple(start_row, start_col, 0));

    // Các hướng di chuyển (lên, xuống, trái, phải)
    vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while (!q.empty()) {
        int curr_row, curr_col, distance;
        tie(curr_row, curr_col, distance) = q.front();
        q.pop();

        // Kiểm tra ô hiện tại có phải là ô thoát ra khỏi mê cung không
        if (curr_row == 0 || curr_row == rows - 1 || curr_col == 0 || curr_col == cols - 1) {
            return distance;
        }

        // Duyệt qua các ô lân cận
        for (auto direction : directions) {
            int next_row = curr_row + direction.first;
            int next_col = curr_col + direction.second;

            // Kiểm tra ô lân cận có hợp lệ không
            if (next_row >= 0 && next_row < rows && next_col >= 0 && next_col < cols && maze[next_row][next_col] == 0 && !visited[next_row][next_col]) {
                visited[next_row][next_col] = true;
                q.push(make_tuple(next_row, next_col, distance + 1));
            }
        }
    }

    // Không tìm thấy đường đi thoát ra khỏi mê cung
    return -1;
}

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    freopen("test3.txt","r",stdin);
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    // Tìm đường ngắn nhất
    int result = shortestPath(maze, r - 1, c - 1);

    // In kết quả
    cout << result << endl;

    return 0;
}
