#include "Point.hpp"

static float area(float x1, float y1, float x2, float y2, float x3, float y3){
    return (std::abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0));
}

bool bsp( Point const a, Point const b, Point const c, Point const point){

    const float ax = a.getX().toFloat();
    const float ay = a.getY().toFloat();
    const float bx = b.getX().toFloat();
    const float by = b.getY().toFloat();
    const float cx = c.getX().toFloat();
    const float cy = c.getY().toFloat();
    const float x = point.getX().toFloat();
    const float y = point.getY().toFloat();

    float A = area(ax, ay, bx, by, cx, cy);

    float A1 = area(x, y, bx, by, cx, cy);

    float A2 = area(ax, ay, x, y, cx, cy);

    float A3 = area(ax, ay, bx, by, x, y);

    float tolerance = 0.000001;

    return (std::abs(A - (A1 + A2 + A3)) < tolerance);
}
