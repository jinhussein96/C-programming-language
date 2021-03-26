#include <stdio.h>
#include <math.h>
#define PI 3.14 

double circle_area(double radius);
double calc_hypotenuse(int side1, int side2);
double calc_radius_of_smallest_circle(int side1, int side2);
double calc_radius_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_circle(int side1, int side2);
double calc_area_of_largest_circle(int side1, int side2);
double calc_area_of_smallest_square(int side1, int side2);
double calc_area_of_largest_square(int side1, int side2);
double calc_area_of_square (int side);
void display_results(
double largest_circle,
double largest_square,
double smallest_circle,
double smallest_square
);


double circle_area(double radius){
	double area;
	area = PI * pow(radius,2.0);
	return area;
}
double calc_hypotenuse(int side1, int side2){
	double hypotenuse;
	hypotenuse = sqrt(pow(side1,2.0)+pow(side2,2.0));
	return hypotenuse;
}
double calc_radius_of_largest_circle(int side1, int side2){
	double radius_of_largest_circle;
	if(side2<side1){
		radius_of_largest_circle = side2 /2.0;
		}
	else 
		radius_of_largest_circle = side1 /2.0;

	return radius_of_largest_circle;
}
double calc_radius_of_smallest_circle(int side1, int side2){
	double hypotenuse,radius_of_smallest_circle;
	hypotenuse=calc_hypotenuse(side1,side2);
	radius_of_smallest_circle=hypotenuse/2.0;
	return radius_of_smallest_circle;

}
double calc_area_of_largest_circle(int side1, int side2){
	double area_of_largest_circle ;
	double radius ;
	radius = calc_radius_of_largest_circle(side1,side2);
	area_of_largest_circle = circle_area(radius);
	return area_of_largest_circle;
}
double calc_area_of_smallest_circle(int side1, int side2){
	double area_of_smallest_circle;
	double radius;
	radius=calc_radius_of_smallest_circle(side1,side2);
	area_of_smallest_circle=circle_area(radius);
	return area_of_smallest_circle;
}
double calc_area_of_largest_square(int side1, int side2){
	double area_of_largest_square;
	if (side2<side1){
	 area_of_largest_square = calc_area_of_square(side2);
		}
	else 
		area_of_largest_square = calc_area_of_square(side1);
		
	return area_of_largest_square;

}
double calc_area_of_smallest_square(int side1, int side2){
	double area_of_smallest_square ;
	if(side1>side2){
	 area_of_smallest_square = calc_area_of_square(side1);
	 		}
	 else 
	 	area_of_smallest_square = calc_area_of_square(side2);
	return area_of_smallest_square;
}
double calc_area_of_square (int side){
	double area_of_square;
	area_of_square = pow(side,2.0);
	return area_of_square;
}
void display_results(double largest_circle,double largest_square,double smallest_circle,double smallest_square){
	printf("the area of the largest circle that fits inside the rectangle : %.2lf \n",largest_circle );
	printf("the area of the largest square that fits inside the rectangle : %.2lf \n",largest_square );
	printf("the area of the smallest circle that fits inside the rectangle : %.2lf \n",smallest_circle );
	printf("the area of the smallest square that fits inside the rectangle : %.2lf \n",smallest_square );

}

int main(){
	int side1,side2;
	double largest_circle;
	double largest_square;
	double smallest_circle;
	double smallest_square;
	printf("Enter first side for rectangle:");
	scanf("%d",&side1);
	printf("Enter seconde side for rectangle :");
	scanf("%d",&side2);
	largest_circle = calc_area_of_largest_circle(side1,side2);
	largest_square=calc_area_of_largest_square(side1,side2);
	smallest_circle=calc_area_of_smallest_circle(side1,side2);
	smallest_square=calc_area_of_smallest_square(side1,side2);
	display_results(largest_circle,largest_square,smallest_circle,smallest_square);


	return 0;
}

