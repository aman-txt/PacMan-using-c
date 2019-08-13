#include <graphics.h>
#include<conio.h>
#include <stdlib.h>
#include<dos.h>
//#include<iostream>

int m_right(int &a,int &b,int &c);
int m_left(int &a,int &b,int &c);
int m_up(int &a,int &b,int &c);
int m_down(int &a,int &b,int &c);
void grid();
void map();
void ghost(int &x,int &y,int &gx,int &gy);
char key;

int a,b,gx,gy;
int main(void)
{
	initwindow(640,480,"");
	setcolor(8);
	settextstyle(3,0,6);
	outtextxy(200,200,"Pacman");
	delay(1000);
	setcolor(1);
	settextstyle(3,0,6);
	outtextxy(200,200,"Pacman");
	delay(1000);
	setcolor(2);
	settextstyle(3,0,6);
	outtextxy(200,200,"Pacman");
	delay(1000);
	setcolor(3);
	settextstyle(3,0,6);
	outtextxy(200,200,"Pacman");
	delay(1000);
	setcolor(0);
	settextstyle(3,0,6);
	outtextxy(200,200,"Pacman");
	
	settextstyle(3,0,1);
	setcolor(1);
	outtextxy(100,100,"Rules");
	outtextxy(100,120,"(1)Press W for UP!");
	outtextxy(100,140,"(2)Press A for LEFT!");
	outtextxy(100,160,"(3)Press S for DOWN!");
	outtextxy(100,180,"(4)Press D for RIGHT!");
	outtextxy(100,200,"(5)If you press any other key except PAKA's"); 
	outtextxy(100,220,"favourite keys then he will leave you.");
	outtextxy(100,240,"(6)If Pakabhai crashes at walls then *HE WILL DIE*! :( ");
	delay(5000);
	setcolor(0);
	outtextxy(100,100,"Rules");
	outtextxy(100,120,"(1)Press W for UP!");
	outtextxy(100,140,"(2)Press A for LEFT!");
	outtextxy(100,160,"(3)Press S for DOWN!");
	outtextxy(100,180,"(4)Press D for RIGHT!");
	outtextxy(100,200,"(5)If you press any other key except PAKA's"); 
	outtextxy(100,220,"favourite keys then he will leave you.");
	outtextxy(100,240,"(6)If Pakabhai crashes at walls then *HE WILL DIE*! :( ");
	setcolor(4);
	outtextxy(100,240,"PAKABHAI ARRIVING SHORTYLY!");
	delay(4000);
	setcolor(0);
	outtextxy(100,240,"PAKABHAI ARRIVING SHORTYLY!");
	settextstyle(3,0,1);
	grid();
	a=320;
	b=240;
	int c=0;
	int d=480;
	int e=640;
	gx=600;
	gy=50;
	key='w';
	while(1)
	{
		
		switch(key)
		{
			case 'w':
				m_up(a,b,c);
				break;
			case 'a':
				m_left(a,b,c);
				break;
			case 's':
				m_down(a,b,d);
				break;
			case 'd':
				m_right(a,b,e);
				break;
			default:
				settextstyle(3,0,6);
				setcolor(15);
				outtextxy(150,200,"GAME OVER");
				delay(1000);
				setcolor(10);
				outtextxy(150,200,"GAME OVER");
				delay(1000);
				setcolor(9);
				outtextxy(150,200,"GAME OVER");
				delay(1000);
				setcolor(8);
				outtextxy(150,200,"GAME OVER");
				delay(1000);
				exit(0);	
		}
	}
	
	getch();
	return 0;
}
//=========FUNCTION FOR GRID FORMATION============//
void grid()
{ 
	
	setcolor(9);
//	for(int i=40;i<640;i++)
//	{	
//		for(int j=40;j<480;j++)
//		{
//			if(i%40==0&&j%40==0)
//			{
//				outtextxy(i,j,"*");
//			}
//		}
//	}
	map();
}
//=============FUNTION FOR MOVING RIGHT========//
int m_right(int &a,int &b,int &c)
{
int s,e;
s=30,e=330;
for(int k=a;k<c-18;k++)
{
	if(s==0)
	{
		s=30;e=330;
	}
	if(k==c-19)
	{
		key='d';
		a=0;
		b=b;
		return 0;
	}
	if(kbhit())
	{
		a=k;
		b=b;
		key=getch();
		return 0;
	}
	if(getpixel(k+19,b)==2 || getpixel(k+19,b+19)==2 || getpixel(k+19,b-19)==2)
	{
		a=k-1;
		b=b;
		key=getch();
		return 0;
	}
	ghost(k,b,gx,gy);
	setfillstyle(SOLID_FILL,14);
	pieslice(k,b,s,e,18);
	setfillstyle(SOLID_FILL,0);
	pieslice(k,b-10,0,360,5);
	setcolor(0);
	delay(15);
	circle(k,b,18);
	s=s-1;e=e+1;
}
}
//=========FUNCTION FOR MOVING LEFT===========//
int m_left(int &a,int &b,int &c)
{
int s,e;
s=150,e=210;
for(int k=a;k>c+18;k--)
{
	
	if(s==180)
	{
		s=150;e=210;
	}
	if(k==c+19)
	{
		key='z';
		return 0;
	}
	if(kbhit())
	{
		a=k;
		b=b;
		key=getch();
		return 0;
	}
	if(getpixel(k-19,b)==2 || getpixel(k-19,b+19)==2 || getpixel(k-19,b-19)==2)
	{
		a=k+1;
		b=b;
		key=getch();
		return 0;
	}
	ghost(k,b,gx,gy);
	setfillstyle(SOLID_FILL,14);
	pieslice(k,b,e,s,18);
	setfillstyle(SOLID_FILL,0);
	pieslice(k,b-10,0,360,5);
	setcolor(0);
	delay(15);
	circle(k,b,18);
	s=s+1;e=e-1;
	
}
}

//========FUNCTION FOR MOVING UP=============//
int m_up(int &a,int &b,int &c)
{ 
int s,e;
s=60,e=120;
	for(int l=b;l>c+18;l--)
	{
		if(s==90)
		{
			s=60;e=120;
		}
		if(l==(c+19))
		{
			key='z';
			return 0;
		}
		if(kbhit())
		{
			a=a;
			b=l;
			key=getch();
			return 0;
		}
		if(getpixel(a,l-19)==2 || getpixel(a+19,l-19)==2 || getpixel(a-19,l-19)==2)
		{
			a=a;
			b=l+1;
			key=getch();
			return 0;
		}
		ghost(a,l,gx,gy);
		setfillstyle(SOLID_FILL,14);

		pieslice(a,l,e,s,18);
		setfillstyle(SOLID_FILL,0);
		pieslice(a-10,l,0,360,5);
		setcolor(0);
		delay(15);
		circle(a,l,18);
		s=s+1;e=e-1;
			
	}
}

//========FUNCTION FOR MOVING DOWN==============//
int m_down(int &a,int &b,int &c)
{ 
	int s,e;
	s=240,e=300;
	for(int l=b;l<c-18;l++)
	{
		if(s==270)
		{
			s=240;e=300;
		}
		if(l==(c-19))
		{
			key='z';
			return 0;
		}
		if(kbhit())
		{
			a=a;
			b=l;
			key=getch();
			return 0;
		
		}
		if(getpixel(a,l+19)==2 || getpixel(a-19,l+19)==2 || getpixel(a+19,l+19)==2)
		{
			a=a;
			b=l-1;
			key=getch();
			return 0;
		}		
		ghost(a,l,gx,gy);
		setfillstyle(SOLID_FILL,14);
		
		pieslice(a,l,e,s,18);
		setfillstyle(SOLID_FILL,0);
		pieslice(a-10,l,0,360,5);
		
		setcolor(0);
		delay(15);
		circle(a,l,18);
		s=s+1;e=e-1;
		
	}
}


void ghost(int &x,int &y,int &gx,int &gy)
{	
	if(abs(gx-x)>abs(gy-y))
	{
		if((gx-x)>0)
		{
			if(getpixel(gx-18,gy)==2 || getpixel(gx-18,gy+18)==2 || getpixel(gx-18,gy-18)==2)
			{
				if((gy-y)>0)
				{
					gx=gx;
					gy=gy-1;	
				}	
				else
				{
					gx=gx;
					gy=gy+1;
				}
			}
			else
			{
				gx=gx-1;	
			}
		}
		else
		{
			if(getpixel(gx+18,gy)==2 || getpixel(gx+18,gy+18)==2 || getpixel(gx+18,gy-18)==2)
			{
				if((gy-y)>0)
				{
					gx=gx;
					gy=gy-1;	
				}	
				else
				{
					gx=gx;
					gy=gy+1;
				}
			}
			else
			{
				gx=gx+1;	
			}
		}
	}
	else
	{
		if((gy-y)>0)
		{
			
			if(getpixel(gx,gy-18)==2 || getpixel(gx-18,gy-18)==2 || getpixel(gx+18,gy-18)==2)
			{
				if((gx-x)>0)
				{
					gx=gx+1;
					gy=gy;	
				}	
				else
				{
					gx=gx-1;
					gy=gy;
				}
			}
			else
			{
				gy=gy-1;	
			}
			
		}
		else
		{
			
			if(getpixel(gx,gy+18)==2 || getpixel(gx-18,gy+18)==2 || getpixel(gx+18,gy+18)==2)
			{
				if((gx-x)>0)
				{
					gx=gx+1;
					gy=gy;	
				}	
				else
				{
					gx=gx-1;
					gy=gy;
				}
			}
			else
			{
				gy=gy+1;	
			}
		}
	}
	setfillstyle(SOLID_FILL,4);
	pieslice(gx,gy,30,330,18);
}

void map()
{
	setcolor(2);
	int arr[]={80,80,80,120,120,120,120,160,160,160,160,120,200,120,200,80,80,80};
	setfillstyle(8,1);
	fillpoly(9,arr);
	bar(240,40,280,120);
	rectangle(240,40,280,120);
	line(200,160,280,160);
	int arr1[]={360,80,440,80,440,120,400,120,400,160,320,160,320,120,360,120,360,80};
	fillpoly(9,arr1);
	int arr2[]={480,40,560,40,560,120,520,120,520,80,480,80,480,40};
	fillpoly(7,arr2);
	bar(40,200,120,240);
	rectangle(40,200,120,240);
	bar(200,200,280,240);
	rectangle(200,200,280,240);
	bar(360,200,440,240);
	rectangle(360,200,440,240);
	bar(520,200,600,240);
	rectangle(520,200,600,240);
	line(480,160,480,280);
	line(440,280,480,280);
	line(40,280,80,280);
	line(200,320,280,320);
	int arr3[]={120,320,160,320,160,360,200,360,200,400,80,400,80,360,120,360,120,320};
	fillpoly(9,arr3);
	line(280,400,280,440);
	int arr4[]={320,320,400,320,400,400,360,400,360,360,320,360,320,320};
	fillpoly(7,arr4);
    int arr5[]={520,320,560,320,560,400,480,400,480,360,520,360,520,320};
    fillpoly(7,arr5);
    rectangle(0,0,640,480);
    rectangle(1,1,639,479);
    rectangle(2,2,638,478);
}
