#include<stdio.h>   //putch
#include<conio.h>   //getch, kbhit
#include<stdlib.h>  //rand
#include<string.h>  //memset



class Object{
	char shape;
public:
	Object(char _shape) : shape(_shape) {}
	int get_shape() { return shape; }
	virtual void update(char* world_map, int world_width, int world_height) = 0;
};
class Game {
	int game_speed;
	int world_width;
	int world_height;
	const static int screen_height = 25;
	char* world_map;
	Object* objs[50];
	int num_obj;
	bool terminal_condition;
public:
	Game(int width, int height, int speed) : game_speed(speed), world_width(width), world_height(height), num_obj(0), terminal_condition(false)
	{
		world_map = new char [width*height];
	}
	void add_object(Object* p) { objs[num_obj++] = p; }
	void update();
	void reset_world() { memset(world_map, 0, world_width*world_height); }
	void draw_world();
	void sleep(int t) { for(int i=0;i<t;i++) for( int j=0;j<t;j++) ; }
	void go();
};
void Game::update()
{
	for(int i=0; i<num_obj; i++)
		objs[i]->update(world_map, world_width, world_height);
}
void Game::draw_world()
{
	for(int i=0; i<world_height; i++)
	{
		putch('\n');
		for(int j=0; j<world_width; j++)
			putch( world_map[ i*world_width + j ]);
	}
	for(int k=0; k<screen_height-world_height; k++)
		putch('\n');
}
void Game::go()
{
	reset_world();
	while(terminal_condition==false)
	{
		update();
		draw_world();
		sleep(game_speed);
	}
}

//----------------------------------Car클래스----------------------------------------//
class Car : public Object{
	int hp;
	int x_pos;
public:
	Car(char shape, int _hp, int pos) : Object(shape), hp(_hp), x_pos(pos) {}
	void update(char* world_map, int world_width, int world_height);
};
void Car::update(char* world_map, int world_width, int world_height)
{
	int ch;
	if(kbhit()==true)
	{
		ch = getch();
		if(ch=='z' && x_pos>1)		//x_pos==0일때는 왼쪽벽에 파묻힌다
			x_pos--;
		else if(ch=='x' && x_pos<world_width-2)		//x_pos==world_width-1일때는 오른쪽벽에 파묻힌다
			x_pos++;
	}
	world_map[ world_width*(world_height-1) + x_pos ] = get_shape();		//car의 y_pos는 항상 마지막줄(world_height-1) 이다
}
//----------------------------------Car클래스----------------------------------------//

//---------------------------------Road클래스----------------------------------------//
class Road : public Object {
	char wall_shape;
	char barrier_shape;
public:
	Road(char _wall_shape, char shape, char _barrier_shape) : Object(shape), wall_shape(_wall_shape), barrier_shape(_barrier_shape) {}
	void update(char* world_map, int world_width, int world_height);
};
void Road::update(char* world_map, int world_width, int world_height)
{
	for(int i=0; i<world_height; i++)
		world_map[ i*world_width ] = world_map[ (i+1)*world_width - 1 ] = wall_shape;
	for(int i=world_height-1; i>0; i--)
	{
		for(int j=1; j<world_width-1; j++)
			world_map[ i*world_width + j ] = world_map[ (i-1)*world_width + j ];
	}
	for(int j=1; j<world_width-1; j++)
		if(rand()%10>7)
			world_map[j] = barrier_shape;
		else
			world_map[j] = get_shape();
}
//---------------------------------Road클래스----------------------------------------//


void main()
{
	Game safe_driving(15+2, 20, 10000);
	
	safe_driving.add_object( new Road('%', ' ', '*') );	
	safe_driving.add_object( new Car('@',10, 3) );

	safe_driving.go();
}