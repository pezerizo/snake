void logic(Map* _map, Apple* _apple, Snake* _snake){
	
	/*For checking board collision*/
	if(_snake->getPositionOfSnakePart(0)[0] == MAXX && _snake->getDirection() == Direction::__right__){
		int _y = _snake->getPositionOfSnakePart(0)[1];
		_snake->setNewHeadPositionOfSnake(0, _y);
		
	}else if(_snake->getPositionOfSnakePart(0)[0] == MINX-1 && _snake->getDirection() == Direction::__left__){
		int _y = _snake->getPositionOfSnakePart(0)[1];
		_snake->setNewHeadPositionOfSnake(MAXX-1, _y);
		
	}else if(_snake->getPositionOfSnakePart(0)[1] == MAXY && _snake->getDirection() == Direction::__down__){
		int _x = _snake->getPositionOfSnakePart(0)[0];
		_snake->setNewHeadPositionOfSnake(_x, 0);
		
	}else if(_snake->getPositionOfSnakePart(0)[1] == MINY-1 && _snake->getDirection() == Direction::__up__){
		int _x = _snake->getPositionOfSnakePart(0)[0];
		_snake->setNewHeadPositionOfSnake(_x, MAXY-1);
	}
	
	if(_snake->getPositionOfSnakePart(0)[0] == _apple->getAppleCoordinations()[0] &&
	   _snake->getPositionOfSnakePart(0)[1] == _apple->getAppleCoordinations()[1]){
	   	_snake->setNewSnakePart();
	   	_apple->setNewAppleCoordinations();
	   	_snake->setNewNumberOfEatenApples(1);
	   	std::cout << '\b';
	}
	
	for(int _iter_of_snake_part = 1; _iter_of_snake_part < _snake->body.size(); ++_iter_of_snake_part){
		if(_snake->body[0].getCurrentPositionOfPart()[0] == _snake->body[_iter_of_snake_part].getCurrentPositionOfPart()[0] &&
		   _snake->body[0].getCurrentPositionOfPart()[1] == _snake->body[_iter_of_snake_part].getCurrentPositionOfPart()[1]){
		    gameover = 1;
		    is_lose = 1;
		}
	}
	
	if(_snake->getNumberOfSnakeParts() == _snake->getMaxSnakeParts()){
		gameover = 1;
		is_lose = 0;
	}
}
