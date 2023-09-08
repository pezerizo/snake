#include <iostream>
#include <vector>
//#include <thread>
#include <windows.h>
#include <conio.h>
//#include <unistd.h>

//#include <chrono>
#include <pthread.h>


#include "includesnake.hpp"
#include "include/map.hpp"
#include "include/apple.hpp"
#include "include/frame.hpp"

#define MINX 0
#define MINY 0
#define MAXX 20
#define MAXY 20
#define SNAKEPART 1
#define MSEC_SLEEP 50

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


static int gameover;
static int is_lose = 1;
static bool __key__[256];
static bool up;

#include "include/logic.hpp"
#include "include/moving.hpp"

int main(int argc, char** argv) {
	
	Snake snake(SNAKEPART, Direction::__right__, (MAXX*MAXY)-1);
	Map   map  (MAXX, MAXY);
	Apple apple(MINX, MAXX, MINY, MAXY);
	Frame frame(&map, &apple, &snake);

	/*Start of moving function in other thread of this game*/
	pthread_t moving_thread;
	int err_thread_create = pthread_create(&moving_thread, NULL, moving, (void*)&snake);
	if(err_thread_create){
		std::cout << "Thread creation is failed" << std::endl;
		return EXIT_FAILURE;
	}

	while(!::gameover){
		/*Reset of created matrix of all coordinates of all objects such as Map, Snake and Apple*/
		frame.resetMatrix();
		
		/*Draw ascii by coordinates of matrix*/
		frame.draw();
		
		/*Start moving of snake*/
		snake.start();
		
		/*Start logic function which will check the all coordinates*/
		logic(&map, &apple, &snake);
		
		/*Frame per milliseconds*/
		Sleep(MSEC_SLEEP);

		/*Show count of eaten apples*/
		gotoXY(0, MAXY+1);
		std::cout << "Count: " << snake.getNumberOfEatenApples() << std::endl;
	}
	
	gotoXY(0, MAXY+1);
	
	/*Gameover message ;)*/
	if(is_lose){
		std::cout << "Hahahahha You are loser xD" << std::endl;
	}else{
		std::cout << "Oh shit! you are winner :O" << std::endl;
	}

	
	pthread_join(moving_thread, NULL);
	
	return 0;
}
