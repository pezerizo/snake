#ifndef apple_class
	#define apple_class
	
	#include <vector>
	#include <cstdlib>
	#include <ctime>
	
class Apple{
	public:
		Apple() = delete;
		Apple(const int _x, const int _y);
		Apple(const int _x_min, const int _x_max, const int _y_min, const int _y_max);
		
		const int* getAppleCoordinations() const;
		void setNewAppleCoordinations(const int _x, const int _y);
		void setNewAppleCoordinations();
		
	private:
		int* current_position;
		int x_min, x_max, y_min, y_max;
};

Apple::Apple(const int _x, const int _y) : current_position(new int[2]), x_min(0), 
																		 x_max(_x),
																		 y_min(0),
																		 y_max(_y){
	this->current_position[0] = _x;
	this->current_position[1] = _y;
}

Apple::Apple(const int _x_min, const int _x_max, const int _y_min, const int _y_max) : current_position(new int[2]),
																					   x_min(_x_min),
																					   x_max(_x_max),
																					   y_min(_y_min),
																					   y_max(_y_max){
	srand(unsigned(time(0)));
	this->current_position[0] = rand() % (_x_max-1) + (_x_min+1);
	this->current_position[1] = rand() % (_y_max-1) + (_y_min+1);
}

const int* Apple::getAppleCoordinations() const{
	return this->current_position;
}

void Apple::setNewAppleCoordinations(const int _x, const int _y){
	this->current_position[0] = _x;
	this->current_position[1] = _y;
}
void Apple::setNewAppleCoordinations(){
	srand(unsigned(time(0)));
	this->current_position[0] = rand() % ((this->x_max)-1) + ((this->x_min)+1);
	this->current_position[1] = rand() % ((this->y_max)-1) + ((this->y_min)+1);
}
	
#endif
