//Задача 1.2 Создать очередь, информационными полями которой являются: длины катетов прямоугольного треугольника (два вещественных числа). Добавить в очередь сведения о новом треугольнике. Организовать просмотр данных очереди. Определить периметр треугольника в начале очереди
#include <iostream>
#include <queue>

struct Triangle {
    double cathetus1;
    double cathetus2;
};

void printTrianglePerimeter(const Triangle& triangle) {
    double hypotenuse = std::sqrt(triangle.cathetus1 * triangle.cathetus1 + triangle.cathetus2 * triangle.cathetus2);
    double perimeter = triangle.cathetus1 + triangle.cathetus2 + hypotenuse;
    std::cout << "Perimeter: " << perimeter << std::endl;
}

int main() {
    std::queue<Triangle> triangleQueue;

    Triangle triangle1{ 3.0, 4.0 };
    Triangle triangle2{ 5.0, 12.0 };
    Triangle triangle3{ 8.0, 15.0 };

    triangleQueue.push(triangle1);
    triangleQueue.push(triangle2);
    triangleQueue.push(triangle3);

    Triangle frontTriangle = triangleQueue.front();
    printTrianglePerimeter(frontTriangle);

    return 0;
}
