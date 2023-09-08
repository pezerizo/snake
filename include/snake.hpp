#ifndef snake_class
	#define snake_class
	
	#include <vector>
	
	#define START_POSITION_X 4
	#define START_POSITION_Y 4

/*Direction of head moving enum with some kind of direction number*/
enum Direction{
	__up__    = 1,
	__right__ = 2,
	__down__  = 3,
	__left__  = 4
};
/*---------------------------------------------------------------*/


/*Main class Snake*/
class Snake{
	public:
		Snake() = delete;
		/*Create a body of snake*/
		Snake(const int _count_of_snake_part, const int _direction, const int _max_snake_parts);
		~Snake();
		
		
		/*For getting some kind of info about parts of snake*/
		const int* getPositionOfSnakePart   (const int _id) const;
		int        getNumberOfSnakeParts	() 			    const;
		int  	   getDirection		        () 			    const;
		int        getNumberOfEatenApples   () 			    const;
		const int  getMaxSnakeParts			()				const;
				
		void      setNewSnakePart           ();
		void 	  setNewNumberOfEatenApples (const int _number);
		void 	  setNewHeadPositionOfSnake (const int _x, const int _y);
		void 	  setNewHeadDirectionOfSnake(const int _direction);
		
		/*Moving of snake*/
		void      start();
	
	private:
		int eaten_apples;
		const int max_snake_parts;
		
		
		/*|||||||||||||||||||||||||||||||||||||||||*/
		/*This class needs for create snake parts*/
		class SnakePart{
			public:
				SnakePart() = delete;
				SnakePart(const int _id, const int _direction);
				~SnakePart();
		
				/*Getting some position value of head, this needs for body-parts*/
				const int*  getNextPositionOfPart    () const;
				const int*  getCurrentPositionOfPart () const;
				const int*  getPrevPositionOfPart	 () const;
				int 		getDirectionOfPart   	 () const;
				int 		getIdOfPart				 () const;
				
				/*For moving the head*/
				void  setNewPositionOfPart     (const int _x, const int _y, const int _replace_position);
				void  setNewDirectionOfPart	   (const int _direction);
				
				/*Some methods*/
				//void  setCurrentPosition	   (const int _x_pos, const int _y_pos);
			
			private:
				/*Some position and direction value*/
				int* next_position;
				int* curr_position;
				int* prev_position;
				
				int direction;
				/*This is id of part if this id equ 0 if meens that is the head of snake*/
				const int id;
		};
		/*|||||||||||||||||||||||||||||||||||||||||*/

	/*Some methods which needs for getting access to SnakePart class*/
	public:
		/*All parts of the snake save in vector container*/
		static std::vector<SnakePart> body;
		/*This is a body of snake known as vector array*/
		const SnakePart* getSnakePart (const int _id) const;
		
};

/*Create the Snake*/
Snake::Snake(const int _count_of_snake_part, const int _direction, const int _max_snake_parts) : max_snake_parts(_max_snake_parts){
	
	Snake::body.reserve(_max_snake_parts);
	
	/*Create a head know as the first element of vector*/
	Snake::body.push_back(Snake::SnakePart(Snake::body.size(), _direction));
	
	/*Create other parts of snake body know as other index of vector*/
	for(int _iter=1; _iter<_count_of_snake_part; ++_iter){
		int _id = static_cast<int>(Snake::body.size());
		Snake::body.push_back(Snake::SnakePart(_id, this->getDirection()));
	}

	this->eaten_apples = 0;
}

/*For getting posotion of every part of body snake*/
const int* Snake::getPositionOfSnakePart(const int _id = 0) const{
	return (Snake::body[_id]).getCurrentPositionOfPart();
}

/*For getting count of eaten apples during playing*/
int Snake::getNumberOfEatenApples() const{
	return this->eaten_apples;
}

/*For getting direction of the head*/
int Snake::getDirection() const{
	return Snake::body[0].getDirectionOfPart();
}

/*For getting count parts of snake*/
int Snake::getNumberOfSnakeParts() const{
	return Snake::body.size();
}

/*For getting each part of snake*/
const Snake::SnakePart* Snake::getSnakePart(const int _id = 0) const{
	return &(Snake::body[_id]);
}

/*For creating a new part of snake body*/
void Snake::setNewSnakePart(){
	int _id = static_cast<int>(Snake::body.size());
	Snake::body.push_back(Snake::SnakePart(_id, this->getDirection()));
}

/*For setting count of eaten apples by snake*/
void Snake::setNewNumberOfEatenApples(const int _number){
	this->eaten_apples+=_number;
}

/*Setting a new position for head*/
void Snake::setNewHeadPositionOfSnake (const int _x, const int _y){
	this->body[0].setNewPositionOfPart(_x, _y, 1);
}

/*I hope name of this function says you more then i am ;)*/
void Snake::setNewHeadDirectionOfSnake (const int _direction){
	this->body[0].setNewDirectionOfPart(_direction);
}

const int Snake::getMaxSnakeParts() const{
	return this->max_snake_parts;
}


/*Create head or some part of snake and set position and other needed value*/
Snake::SnakePart::SnakePart(const int _id, const int _direction) : id(_id), 
																   next_position(new int[2]),
													   			   curr_position(new int[2]),
													   			   prev_position(new int[2]){
	this->direction = _direction;
	
	if(_id == 0){
		this->curr_position[0] = START_POSITION_X;
		this->curr_position[1] = START_POSITION_Y;
		
		this->next_position[0] = START_POSITION_X;
		this->next_position[1] = START_POSITION_Y;
	}
	else{
		if(this->direction == Direction::__up__){
			this->curr_position[0] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[0];
			this->curr_position[1] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[1]+1;
		}
		else if(this->direction == Direction::__down__){
			this->curr_position[0] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[0];
			this->curr_position[1] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[1]-1;
		}
		else if(this->direction == Direction::__left__){
			this->curr_position[0] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[0]+1;
			this->curr_position[1] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[1];
		}
		else if(this->direction == Direction::__right__){
			this->curr_position[0] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[0]-1;
			this->curr_position[1] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[1];
		}
		else{
			this->curr_position[0] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[0];
			this->curr_position[1] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[1]-1;
		}
		
		this->next_position[0] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[0];
		this->next_position[1] = ( Snake::body[_id-1] ).getCurrentPositionOfPart()[1];
	}
}

/*For getting next position of the current SnakePart*/
const int* Snake::SnakePart::getNextPositionOfPart() const{
	return this->next_position;
}

/*For getting current position of the current SnakePart*/
const int* Snake::SnakePart::getCurrentPositionOfPart() const{
	return this->curr_position;
}

/*For getting prev position of the current SnakePart*/
const int* Snake::SnakePart::getPrevPositionOfPart() const{
	return this->prev_position;
}

/*For getting direction value of the current SnakePart*/
int Snake::SnakePart::getDirectionOfPart() const{
	return this->direction;
}

/*For getting ID value of the current SnakePart
If ID == 0 it meens that is the head of snake*/
int Snake::SnakePart::getIdOfPart() const{
	return this->id;
}

void Snake::SnakePart::setNewDirectionOfPart(const int _direction){
	this->direction = _direction;
}


/*Set new position for snake part*/
void Snake::SnakePart::setNewPositionOfPart(const int _x = 0, const int _y = 0, const int _replace_position = 0){
	if(this->id == 0 && _replace_position == 0){
		
		(this->next_position[0]) += _x;
		(this->next_position[1]) += _y;
		
	}else if(this->id == 0 && _replace_position == 1){
		
		(this->next_position[0]) = _x;
		(this->next_position[1]) = _y;
		
	}else{
		
		(this->next_position[0]) = ( Snake::body[ (this->id)-1 ] ).getPrevPositionOfPart()[0];
		(this->next_position[1]) = ( Snake::body[ (this->id)-1 ] ).getPrevPositionOfPart()[1];	
		
	}
	
	this->prev_position[0] = this->curr_position[0];
	this->prev_position[1] = this->curr_position[1];
	
	this->curr_position[0] = this->next_position[0];
	this->curr_position[1] = this->next_position[1];
}

/*Moving of snake function*/
void Snake::start(){
	/*Set new position for head*/
	if(this->getDirection() == Direction::__up__){
		this->body[0].setNewPositionOfPart(0, -1);
	}else if(this->getDirection() == Direction::__down__){
		this->body[0].setNewPositionOfPart(0, 1);
	}else if(this->getDirection() == Direction::__left__){
		this->body[0].setNewPositionOfPart(-1, 0);
	}else{
		this->body[0].setNewPositionOfPart(1, 0);
	}
	
	for(int _iter_of_parts = 1; _iter_of_parts < this->getNumberOfSnakeParts(); ++_iter_of_parts){
		this->body[_iter_of_parts].setNewPositionOfPart();
	}
	
}

/*Destructors*/
Snake::SnakePart::~SnakePart(){
	//delete[] this->next_position;
	//delete[] this->curr_position;
	//delete[] this->prev_position;
}
Snake::~Snake(){}
/*For fix the undefined reference error ;)*/
std::vector<Snake::SnakePart> Snake::body;

#endif
