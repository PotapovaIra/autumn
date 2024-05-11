#include <iostream>
#include<algorithm>
#include<chrono>
#include <iomanip>
#include <cmath>
#include <random>
#include <algorithm>
#include <thread>
#include <vector>
#include <functional>
#include <SFML/Graphics.hpp>
class Point
{
public:
    double x;
    double y;
    Point(double x_coord, double y_coord) :x(x_coord), y(y_coord) {}
};
std::vector<Point> generate(int n) {//generator
    std::vector<Point> points;
    for (int i = 0; i < n; ++i) {
        static constexpr std::size_t numInstances = 100'000;
        std::mt19937_64 gen(static_cast<unsigned long>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
        std::uniform_real_distribution<double> dist(0.0, 100.0);
        double x = dist(gen);
        double y = dist(gen);
        points.emplace_back(Point(x, y));
    }
    return points;
}
double T(double T0, double alpha, int i) {//new temperature via formula t = t0*a^i, alpha = coolingRate
    // Ti = T0 * pow(alpha, i)
    return T0 * pow(alpha, i);
}
double Dist(const Point& point1, const Point& point2) {//calculate distance
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}
double Energy(const std::vector<Point>& points) {//calculate energy
    double totaldist = 0.0;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        totaldist += Dist(points[i], points[i + 1]);
    }
    totaldist += Dist(points.back(), points.front());//add distance back to the starting city
    return totaldist;
}
void simulate(std::vector<Point>& points, double T0, double alpha) {
    double T_new = T0;
    std::vector<Point> Sol = points;
    double En0 = Energy(Sol);
    int iteration = 1;
    while (T_new > 0.0001)
    {
        std::vector<Point>newSol = Sol;
        int point1 = rand() % points.size();
        int point2 = rand() % points.size();
        if (point1 != point2) {
            std::reverse(newSol.begin() + std::min(point1, point2), newSol.begin() + std::max(point1, point2));
            double newEn = Energy(newSol);
            if (newEn < En0 || exp((En0 - newEn) / T_new) > static_cast<double>(rand()) / RAND_MAX) {
                Sol = newSol;
                En0 = newEn;
            }
        }
        T_new = T(T0, alpha, iteration);
        iteration++;

    }
    points = Sol;
}
//std::vector<Point>
int main() {
    int n = 10;
    double T0 = 10.0;
    double alpha = 0.999;

    std::vector<Point> points = generate(n);

    simulate(points, T0, alpha);
    sf::RenderWindow window(sf::VideoMode(800, 600), "visualization");
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
    auto X1 = [](double x) {return x*8;}; //transform points to show
    auto Y1 = [](double y) {return y*6;};

    //draw point
    for (const auto& point : points) {
        sf::CircleShape circle(5);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(X1(point.x),Y1(point.y));
        window.draw(circle);
    }
    for (const auto& point : points) {
        std::cout << point.x << point.y << std::endl;
    }
    std::cout << Energy(points);
    window.display();
    system("pause");

    return 0;
}
