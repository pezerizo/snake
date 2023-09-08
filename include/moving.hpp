void* __cdecl moving(/*Snake* _snake*/ void* _snake_object){
	int c = 0;
	Snake* _snake = (Snake*)_snake_object;
    while(!::gameover)
    {
        c = 0;
		c = getch();
		
        if(c == KEY_UP && _snake->getDirection() != Direction::__down__){
			_snake->setNewHeadDirectionOfSnake(Direction::__up__);
		}else if(c == KEY_DOWN && _snake->getDirection() != Direction::__up__){
			_snake->setNewHeadDirectionOfSnake(Direction::__down__);
		}else if(c == KEY_LEFT && _snake->getDirection() != Direction::__right__){
			_snake->setNewHeadDirectionOfSnake(Direction::__left__);
		}else if(c == KEY_RIGHT && _snake->getDirection() != Direction::__left__){
			_snake->setNewHeadDirectionOfSnake(Direction::__right__);
		}
    }
}
