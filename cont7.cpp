#include "image.hpp"
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_valid(int x, int y, int width, int height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

bool find_shortest_path(Image& img) {
    int width = img.GetWidth();
    int height = img.GetHeight();

    Point start(-1, -1), end(-1, -1);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Pixel p = img.GetPixel(x, y);
            if (p.r == 0 && p.g == 255 && p.b == 0) {
                start = Point(x, y);
            } else if (p.r == 255 && p.g == 0 && p.b == 0) {
                end = Point(x, y);
            }
        }
    }

    if (start.x == -1 || end.x == -1) {
        std::cerr << "Start or end point not found!\n";
        return false;
    }
    std::vector<std::vector<int>> dist(height, std::vector<int>(width, -1));
    std::vector<std::vector<Point>> parent(height, std::vector<Point>(width, Point(-1, -1)));

    std::queue<Point> q;
    q.push(start);
    dist[start.y][start.x] = 0;
    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        if (current == end) {
            break;
        }

        for (int i = 0; i < 8; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (is_valid(nx, ny, width, height)) {
                Pixel p = img.GetPixel(nx, ny);
                if ((p.r == 255 && p.g == 255 && p.b == 255) ||
                    (p.r == 0 && p.g == 255 && p.b == 0) ||
                    (p.r == 255 && p.g == 0 && p.b == 0)) {
                    if (dist[ny][nx] == -1) {
                        dist[ny][nx] = dist[current.y][current.x] + 1;
                        parent[ny][nx] = current;
                        q.push(Point(nx, ny));
                    }
                }
            }
        }
    }
    if (dist[end.y][end.x] == -1) {
        std::cerr << "Path not found!\n";
        return false;
    }
    Point current = end;
    while (!(current == start)) {
        if (!(current == end)) {
            img.SetPixel(current.x, current.y, Pixel(0, 0, 255));
        }
        current = parent[current.y][current.x];
    }

    return true;
}

int main() {
    try {
        Image img;
        if (!img.Load("input.ppm")) {
            std::cerr << "Failed to load image!\n";
            return 1;
        }

        if (find_shortest_path(img)) {
            if (img.Save("output.ppm")) {
                std::cout << "Path found and saved to output.ppm\n";
            } else {
                std::cerr << "Failed to save image!\n";
                return 1;
            }
        } else {
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
