#include<stdio.h>
//#include "klee/klee.h"

#define INVAILD -1
#define NOT_TRIANGLE -2
#define TRIANGLE 0
#define EQUILATERAL 1
#define ISOSCELES 2

void swap(int t, int x, int y){
     t = x;
     x = y;
     y = t;
}


int triangle_type(int x, int y, int z){
    //check invaild
    if (1 > x || x > 200 )
       return INVAILD;
    if (1 > y || y > 200 )
       return INVAILD;
    if (1 > z || z > 200 )
       return INVAILD;
    
    //sort 3 value
    int t;

    if (x > y)
       swap(t, x, y);
    if (y > z)
       swap(t, y, z);
    if (x > y)
       swap(t, x, y);

    //not_triangle
    if (z >= x + y )
       return NOT_TRIANGLE;

    //equilateral
    if (x == y && y == z)
       return EQUILATERAL;
    //isosceles
    if (x == y || y == z)
       return ISOSCELES;
       
    return TRIANGLE;
    
} 

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    //klee_make_symbolic(&a, sizeof(a), "a");
    //klee_make_symbolic(&b, sizeof(b), "b");
    //klee_make_symbolic(&c, sizeof(c), "c");
    int ans;
    ans = triangle_type(a, b, c);

    printf("%d\n", ans);
    return 0;
}
            
