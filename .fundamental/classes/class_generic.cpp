#include <iostream>;

class Rectangle {

	// If not specifically declared, the class objects will be private
	// private objects can only be accessed by another class' objects
	int width, height;

	// Make some of the class objects public
	public:
		void set_values(int, int);
		int area() {
			return height * width;
		}
};

class Triangle {

	int surface, height;

	public:
		// This is the constructor
		// The constructor was initialized just like any normal function but with a name that matches the class
		// A constructor will be automatically called everytime new object of this class is created
		// A constructor has no return type, not even void type. It only initialize the object
		Triangle(int, int);

		// Overload the constructor
		// The compiler will automatically choose the appropriate one based on it arguments
		Triangle();

		int area() {
			return 0.5 * (surface * height);
		}
};

// Scope operator (::) specifies the class to which the member being defined belong
// This will assign value to the set_values method inside Rectangle class
void Rectangle::set_values(int x, int y) {

	// This width and height refer to the private variable inside Rectangle class
	width = x;
	height = y;
}

// Assign value to the constructor
Triangle::Triangle(int x, int y) {
	surface = x;
	height = y;
}

// You can overload the constructor
// The compiler will automatically choose the appropriate one based on its arguments
Triangle::Triangle() {
	surface = 6;
	height = 2;
}

int main() {
	// Declare the Rectangle class, and class is considered as a type hence we can declare multiple objects of it
	// After declaration, all of the public objects will be accessible by 'recta' and 'rectb' variable
	Rectangle recta, rectb;

	recta.set_values(3, 4);
	rectb.set_values(5, 5);
	
	std::cout << "Rectangle A: " << recta.area() << std::endl;
	std::cout << "Rectangle B: " << rectb.area() <<std::endl;


	// Declare the constructor
	// Constructor cannot be called explicitly like regular functions and still considered as a type, 
	// it only executed once which when the new object of the class was created
	Triangle tria(10, 5);
	Triangle trib(20, 10);

	// Declare the second constructor that has no arguments
	Triangle tric;

	std::cout << "Triangle A: " << tria.area() << std::endl;
	std::cout << "Triangle B: " << trib.area() << std::endl;
	std::cout << "Triangle C: " << tric.area() << std::endl;

	return 0;
}