#ifndef map_class
	#define map_class
	
	#include <vector>

class Map{
	public:
		
		/*|||||||||*/
		class Matrix{
			public:
				
				/*|||||||||*/
				class Point{
					public:
						Point() = delete;
						Point(const int _x, const int _y);
						
						/*Needs for getting coordinates of eahc point*/
						const int* getCoordinatesOfPoint() const;
						
					private:
						int* _point_coordinates;
				};
				/*|||||||||*/
				
				static std::vector<Point> _mtrx;
				
				Matrix() = delete;
				Matrix(const int _x, const int _y, const int _count_of_points);
				
				/*For return matrix for the Map::getMatriOfPoint() interface*/
				const std::vector<Point>& getMatrix() const;
				
		};
		/*|||||||||*/
		Matrix* _own_matrix;
		
	public:
		Map() = delete;
		Map(const int _x, const int _y);
		
		/*For getting access to all point of map, this is a interface method*/
		const std::vector<Matrix::Point>& getMatrixOfPoint() const;
};


Map::Map(const int _x, const int _y) : _own_matrix(new Matrix(_x, _y, _x*_y)){}
Map::Matrix::Matrix(const int _x, const int _y, const int _count_of_points){	
	for(int _y_iter = 0; _y_iter < _y; ++_y_iter){
		for(int _x_iter = 0; _x_iter < _x; ++_x_iter){
			Matrix::_mtrx.push_back(Matrix::Point(_x_iter, _y_iter));
		}
	}
	
}
Map::Matrix::Point::Point(const int _x, const int _y) : _point_coordinates(new int[2]){
	this->_point_coordinates[0] = _x;
	this->_point_coordinates[1] = _y;
}

const std::vector<Map::Matrix::Point>& Map::getMatrixOfPoint() const{
	return this->_own_matrix->getMatrix();
}

const std::vector<Map::Matrix::Point>& Map::Matrix::getMatrix() const{
	return this->_mtrx;
}

const int* Map::Matrix::Point::getCoordinatesOfPoint() const{
	return this->_point_coordinates;
}

std::vector<Map::Matrix::Point> Map::Matrix::_mtrx;

#endif
