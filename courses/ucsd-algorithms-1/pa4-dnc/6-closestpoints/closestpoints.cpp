#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

typedef std::pair<long long int, long long int> Point;

double distance(Point a, Point b) {
    return hypot(b.first - a.first, b.second - a.second);
}

bool sorter(Point a, Point b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

double closest_pair(std::vector<Point> points_x, std::vector<Point> points_y) {
    if (points_x.size() <= 1) {
        return INFINITY;
    } else if (points_x.size() == 2) {
        return distance(points_x[0], points_x[1]);
    } else if (points_x.size() == 3) {
        return std::min(distance(points_x[0], points_x[1]),
                        std::min(distance(points_x[0], points_x[2]),
                                 distance(points_x[1], points_x[2])));
    }

    // (1) Split the set of points into two: [0...mid-1] and [mid...N-1]
    int mid = points_x.size() / 2;
    long long int x_mid = points_x[mid].first, y_mid = points_x[mid].second;
    std::vector<Point> points_x_left, points_x_right, points_y_left,
        points_y_right;
    for (int i = 0; i < points_x.size(); i++) {
        if (i < mid) {
            points_x_left.push_back(points_x[i]);
        } else {
            points_x_right.push_back(points_x[i]);
        }
        if (points_y[i].first < x_mid ||
            (points_y[i].first == x_mid && points_y[i].second > y_mid)) {
            points_y_left.push_back(points_y[i]);
        } else {
            points_y_right.push_back(points_y[i]);
        }
    }

    // (2) get the closest pair on both sides
    double dl = closest_pair(points_x_left, points_y_left),
           dr = closest_pair(points_x_right, points_y_right),
           d = std::min(dl, dr);

    // Free up some memory
    points_x_left.clear();
    points_y_left.clear();
    points_x_right.clear();
    points_y_right.clear();

    // (3) Get the list of points $d$ away from the middle x_value
    double dmid_lo = x_mid - d, dmid_hi = x_mid + d;
    std::vector<Point> dmid_points;
    for (int i = 0; i < points_y.size(); i++) {
        if (dmid_lo <= points_y[i].first && points_y[i].first <= dmid_hi) {
            dmid_points.push_back(points_y[i]);
        }
    }
    double dmid = d;
    for (int i = 0; i < dmid_points.size(); i++) {
        for (int j = i + 1; j <= std::min(i + 7, int(dmid_points.size() - 1));
             j++) {
            // std::cout << i << " " << j << " "
            //           << distance(dmid_points[i], dmid_points[j]) <<
            //           std::endl;
            dmid = std::min(dmid, distance(dmid_points[i], dmid_points[j]));
        }
    }
    dmid_points.clear();
    // for (auto p : dmid_points) {
    //     std::cout << "(" << p.first << ", " << p.second << ") ";
    // }
    // std::cout << dmid_lo << " " << dmid_hi << "*" << std::endl;
    // for (auto p : points_x) {
    //     std::cout << "(" << p.first << ", " << p.second << ") ";
    // }
    // std::cout << d << " " << dmid << std::endl;
    return std::min(d, dmid);
}

int main() {
    int N;
    std::cin >> N;
    std::vector<Point> points_x(N), points_y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> points_x[i].first >> points_x[i].second;
        points_y[i].first = points_x[i].first;
        points_y[i].second = points_x[i].second;
    }
    std::sort(points_x.begin(), points_x.end());
    std::sort(points_y.begin(), points_y.end(), sorter);
    for (int i = 1; i < N; i++) {
        if (points_x[i - 1] == points_x[i]) {
            std::cout << "0.000000000" << std::endl;
            return 0;
        }
    }
    std::cout << std::fixed << std::setprecision(9)
              << closest_pair(points_x, points_y) << std::endl;
    return 0;
}
