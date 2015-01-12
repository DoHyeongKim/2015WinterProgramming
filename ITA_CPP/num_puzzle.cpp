#include<iostream>
using namespace std;
#define SPACE 0

class NumPuzzle{
 int size;
 int* buff;
 int spaceX;
 int spaceY;
public:
 NumPuzzle(int _size = 5);
 ~NumPuzzle();
 void print();
 void go();
 void update(int in);
 bool match();
};

NumPuzzle::NumPuzzle(int _size)
{
 size = _size;
 spaceX = spaceY = size-1;
 buff = new int[size*size];
 
 int* temp = new int[size*size-1];
 int t;
 for(int i=0;i<size*size-1; i++)
  temp[i] = i+1;
 for(i=0; i<size*size-1; i++)
 {
  t = rand()%(size*size-1-i);
  buff[i] = temp[ t ];
  for(int j=t+1; j<size*size-1-i; j++)
   temp[j-1] = temp[j];
 }
 buff[size*size-1] = SPACE;
}
NumPuzzle::~NumPuzzle()
{
 delete[] buff;
}
void NumPuzzle::print()
{
 for(int i=0; i<size; i++)
 {
  for(int j=0; j<size; j++)
  {
   if(buff[size*i+j] == SPACE)
    cout<<' '<<' '<<' ';
   else if(buff[size*i+j] < 10)
    cout<<' '<<buff[size*i+j]<<' ';
   else
    cout<<buff[size*i+j]<<' ';
  }
  cout<<endl;
 }
}
void NumPuzzle::update(int in)
{
 if(spaceX>0)
 {
  if( in == buff[size*(spaceX-1) + spaceY] )
  {
   buff[size*spaceX + spaceY] = buff[size*(spaceX-1) + spaceY];
   buff[size*(spaceX-1) + spaceY] = SPACE;
   spaceX--;
   return;
  }
 }
 if(spaceY>0)
 {
  if( in == buff[size*spaceX + spaceY-1] )
  {
   buff[size*spaceX + spaceY] = buff[size*spaceX + spaceY-1];
   buff[size*spaceX + spaceY-1] = SPACE;
   spaceY--;
   return;
  }
 }
 if(spaceX<size-1)
 {
  if( in == buff[size*(spaceX+1) + spaceY] )
  {
   buff[size*spaceX + spaceY] = buff[size*(spaceX+1) + spaceY];
   buff[size*(spaceX+1) + spaceY] = SPACE;
   spaceX++;
   return;
  }
 }
 if(spaceY<size-1)
 {
  if( in == buff[size*spaceX + spaceY+1] )
  {
   buff[size*spaceX + spaceY] = buff[size*spaceX + spaceY+1];
   buff[size*spaceX + spaceY+1] = SPACE;
   spaceY++;
   return;
  }
 }
 cout<<in<<"는 옮길 수 없습니다"<<endl;
}
bool NumPuzzle::match()
{
 for(int i=0;i<size*size-1; i++)
 {
  if(buff[i] != i+1)
   return false;
 }
 return true;
}
void NumPuzzle::go()
{
 int in;
 int count = 0;

 print();
 while(1)
 {
  cout<<++count<<"번째 시도, 옮길 숫자를 입력하세요 : ";
  cin>>in;
  update(in);
  cout<<endl;
  print();
  if(match())
  {
   cout<<"축하합니다!! 총"<<count<<"번이 걸리셨습니다~"<<endl;
   break;
  }
 }
}

void main()
{
 int size;

 cout<<"퍼즐의 크기를 입력하세요 : ";
 cin>>size;
 cout<<endl;

 NumPuzzle pzl(size);
 pzl.go();

}
