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


struct Rel_coordinate {
	int x1, y1;
	int x2, y2;
	int x3, y3;
};
Rel_coordinate coor[7][4] = { 
	{ 
		{0,-1, 1,0, 2,0}, {1,0 ,0,1, 0,2}, {0,1, -1,0, -2,0}, {-1,0, 0,-1, 0,-2} // ¦¦ ->¦£ -> ¦¤ -> ¦¥
	} 
};

class Block : public Object{
	int x_pos, y_pos;
	int direction;
	int block_shape;
public:
	Block(char shape, int x, int y) : Object(shape), x_pos(x), y_pos(y), direction(0), block_shape(0) {}
	void update(char* world_map, int world_width, int world_height);
};
void Block::update(char* world_map, int world_width, int world_height)
{
	int ch;
	world_map[ (x_pos) + (y_pos)*world_width ] = ' ';
	world_map[ (coor[block_shape][direction].x1 + x_pos) + (coor[block_shape][direction].y1 + y_pos)*world_width ] = ' ';
	world_map[ (coor[block_shape][direction].x2 + x_pos) + (coor[block_shape][direction].y2 + y_pos)*world_width ] = ' ';
	world_map[ (coor[block_shape][direction].x3 + x_pos) + (coor[block_shape][direction].y3 + y_pos)*world_width ] = ' ';
	if(kbhit()==true)
	{
		ch = getch();
		if(ch=='z')
			direction = (direction+1)%4;
	}
	y_pos++;
	world_map[ (x_pos) + (y_pos)*world_width ] = get_shape();
	world_map[ (coor[block_shape][direction].x1 + x_pos) + (coor[block_shape][direction].y1 + y_pos)*world_width ] = get_shape();
	world_map[ (coor[block_shape][direction].x2 + x_pos) + (coor[block_shape][direction].y2 + y_pos)*world_width ] = get_shape();
	world_map[ (coor[block_shape][direction].x3 + x_pos) + (coor[block_shape][direction].y3 + y_pos)*world_width ] = get_shape();
}



void main()
{
	Game tetris(10+2, 20, 10000);
	
	tetris.add_object( new Block('#', 3, 3) );
	
	tetris.go();
}