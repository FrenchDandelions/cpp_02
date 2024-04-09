#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {

    const float ax = a.getX().toFloat();
    const float ay = a.getY().toFloat();
    const float bx = b.getX().toFloat();
    const float by = b.getY().toFloat();
    const float cx = c.getX().toFloat();
    const float cy = c.getY().toFloat();
    const float x = point.getX().toFloat();
    const float y = point.getY().toFloat();

    // Check if the point coincides with any of the vertices
    if ((x == ax && y == ay) || (x == bx && y == by) || (x == cx && y == cy))
        return false;

    // Calculate the areas of the triangles formed by the point and each edge of the triangle
    // float areaABC = ((ax - cx) * (by - cy) - (ay - cy) * (bx - cx));
    float areaABP = ((ax - x) * (by - y) - (ay - y) * (bx - x));
    float areaBCP = ((bx - x) * (cy - y) - (by - y) * (cx - x));
    float areaCAP = ((cx - x) * (ay - y) - (cy - y) * (ax - x));

    // Check if the point lies on any of the edges
    if (areaABP == 0 || areaBCP == 0 || areaCAP == 0)
        return false;

    // Check if the point lies strictly inside the triangle
    return (areaABP > 0 && areaBCP > 0 && areaCAP > 0) || (areaABP < 0 && areaBCP < 0 && areaCAP < 0);
}
