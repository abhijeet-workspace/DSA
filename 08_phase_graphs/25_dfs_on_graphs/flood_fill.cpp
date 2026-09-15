// Flood Fill — https://leetcode.com/problems/flood-fill/
// Recolor the 4-connected component containing (sr, sc) to color.
#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>>& image, int r, int c, int oldColor, int newColor) {
    if (r < 0 || c < 0 || r >= static_cast<int>(image.size())
        || c >= static_cast<int>(image[0].size()) || image[r][c] != oldColor) {
        return;
    }
    image[r][c] = newColor;
    dfs(image, r - 1, c, oldColor, newColor);
    dfs(image, r + 1, c, oldColor, newColor);
    dfs(image, r, c - 1, oldColor, newColor);
    dfs(image, r, c + 1, oldColor, newColor);
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> image, int sr, int sc,
                                        int color) {
    const int oldColor = image[sr][sc];
    if (oldColor != color) {
        dfs(image, sr, sc, oldColor, color);
    }
    return image;
}

int main() {
    std::vector<std::vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    const auto out = floodFill(image, 1, 1, 2);
    std::cout << "result:\n";
    for (const auto& row : out) {
        for (int x : row) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
    std::cout << "(expected [[2,2,2],[2,2,0],[2,0,1]])\n";
    return 0;
}
