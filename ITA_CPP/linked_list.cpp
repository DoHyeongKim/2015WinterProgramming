#include<iostream>
using namespace std;

struct STUDENT{
	char name[20];
	int ID;
	int score_Kor;
	int score_Eng;
	int score_math;
	double average;
	STUDENT* next;
};

STUDENT* head = NULL;

void add_student()
{
 STUDENT* p = new STUDENT;
 STUDENT* temp = head;

 cout<<"이름 : ";
 cin>>p->name;
 cout<<"ID : ";
 cin>>p->ID;
 cout<<"국어점수 : ";
 cin>>p->score_Kor;
 cout<<"영어점수 : ";
 cin>>p->score_Eng;
 cout<<"수학점수 : ";
 cin>>p->score_math;
 p->average = double(p->score_Eng+p->score_Kor+p->score_math) /3.0;
 p->next = 0;

 if(head==NULL)
 {
  head = p;
  return;
 }
 while( temp->next != NULL )
 {
  temp = temp->next;
 }
 temp->next = p;
}

void del_student()
{
 STUDENT* temp = head;
 STUDENT* temp2;
 int del_ID;
 bool find_ID = false;

 if( head == NULL )
 {
  cout<<"삭제할 data가 없습니다."<<endl;
  return;
 }

 cout<<"삭제할 학생의 ID를 입력하세요 : ";
 cin>>del_ID;
 
 if( head->ID == del_ID )
 {
  temp = head;
  head = head->next;
  delete temp;
  return;
 }
 while(temp->next!=NULL)
 {
  if( temp->next->ID == del_ID )
  {
   find_ID = true;
   break;
  }
  temp = temp->next;
 }
 if(find_ID)
 {
  temp2 = temp->next;
  temp->next = temp->next->next;
 }
 else
 {
  cout<<"찾으시는 ID가 없습니다!!"<<endl;
 }
}

void out_all()
{
 STUDENT* p = head;

 cout<<endl;
 cout<<"ID\t\t이름\t국어\t영어\t수학\t평균"<<endl;
 while( p != NULL )
 {
  cout<<p->ID<<'\t'
   <<p->name<<'\t'
   <<p->score_Kor<<'\t'
   <<p->score_Eng<<'\t'
   <<p->score_math<<'\t'
   <<p->average<<endl;

  p = p->next;
 }
 cout<<endl;
}

void main()
{
	int t;
	bool tt = true;


	while(tt)
	{
		cout<< "1.추가\t 2.삭제\t 3.종료 "<<endl;
		cin>>t;
		switch(t)
		{
		case 1:
			add_student();
			break;
		case 2:
			del_student();
		break;
			case 3:
			tt = false;
		continue;
		default:
		continue;
		}

	out_all();

	}
}
