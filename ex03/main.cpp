#include "Point.hpp" // Include your Point class header file

int main()
{
   /* Let us check whether the point P(10, 15) lies inside the triangle 
      formed by A(0, 0), B(20, 0) and C(10, 30) */
    Point a(0, 0);
    Point b(20, 0);
    Point c(10, 30);
    Point to_check(10, 15);
   if (bsp(a, b, c, to_check))
     std::cout <<"Inside" << std::endl;
   else
     std::cout <<"Not Inside" << std::endl;
  
   return 0;
}
