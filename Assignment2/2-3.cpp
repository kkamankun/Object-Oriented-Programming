#include<iostream>
#define _CRT_SECURE_NO_WARNINGS  

using namespace std;

//three functions
double calculates_area_of_rectangle(int width, int height)
{
	return width * height;
}
double calculates_area_of_triangle(int width, int height)
{
	return (width*height) / 2.0;
}
double calculates_area_of_diamond(int width, int height)
{
	return (width*height) / 2.0;
}

int main(void) {

	int width; int height;
	cout << "Width: "; cin >> width;
	cout << "Height: "; cin >> height;
	cout << endl;

	double(*Figurearea[3])(int width, int height);

	Figurearea[0] = calculates_area_of_rectangle;
	Figurearea[1] = calculates_area_of_triangle;
	Figurearea[2] = calculates_area_of_diamond;

	/*printing the result*/
	cout << "Area of the rectangular : " << Figurearea[0](width, height) <<endl;
	cout << fixed; cout.precision(1);
	cout << "Area of the triangle : " << Figurearea[1](width, height) <<endl;
	cout << "Area of the diamond : " << Figurearea[2](width, height) <<endl;
	
	system("pause");
	return 0;
}