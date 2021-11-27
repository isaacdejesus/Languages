#include <stdio.h>
struct point {
    int x;
    int y;
};

struct rect{
    struct point pt1;
    struct point pt2;
};

int main()
{
    //rect is a nested structure.
    struct rect screen;
    screen.pt1.x = 25;
    screen.pt1.y = 30;
    screen.pt2.x = 60;
    screen.pt2.y = 90;

    printf("Cooordindates for pt1 are: %d,%d \n", screen.pt1.x , screen.pt1.y);
    printf("Cooordindates for pt2 are: %d,%d \n", screen.pt2.x , screen.pt2.y);
       
    return 0;
}


//struct can be defined in the following ways:
//struct name {
//  int x;
//  int y;
//  };
//
//alternative way:
//struct name { int a, int b} x, y, z;
//the above sets creates variables x, y, z of struct type
//the name of a struct is optional.
//But setting a name allows us to reuse the struct later on.
//struct point pt; declares a struct of type point
//struct point pt = {300, 300}; ;declares a struct of type point and ini
