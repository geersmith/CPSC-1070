#include <stdio.h>
#include <math.h>

double calcAngleRadians(int numSides){
    return (double) (2 * M_PI) / numSides;
}

double calcAngleDegrees(int numSides){
    return (double) 360/numSides;
}

double calcSideLength(int gonRadius, double angleRadians){
    double sideLengthSquared = (gonRadius * gonRadius) +
                               (gonRadius * gonRadius) -
                               ((2 * gonRadius * gonRadius) *
                               cos(angleRadians));
    return (double) sqrt(sideLengthSquared);
}

double calcPerimeter(double sideLength, int numSides){
    return (double) sideLength * numSides;
}

int main(void){
    int sides, radius;
    printf("Enter sides: ");
    scanf("%d", &sides);
    printf("Enter radius (in): ");
    scanf("%d", &radius);

    double angleRadians = calcAngleRadians(sides);
    printf("Angle is %.2f radians (%.1f degrees)\n",
           angleRadians, 
           calcAngleDegrees(sides));

    double sideLength = calcSideLength(radius, angleRadians);
    printf("Side is %.2f inches\n", sideLength);

    double perimeterInches = calcPerimeter(sideLength, sides);
    double perimeterFeet = perimeterInches / 12;
    printf("Perimeter is %.2f inches and %.2f feet.\n", perimeterInches, perimeterFeet);
    
    return 0;
}

