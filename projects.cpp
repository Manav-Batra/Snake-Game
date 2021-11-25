#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int x,y,fruitx,fruity,score;
int tailx[100],taily[100];
int ntail;

enum isdirection{STOP=0,UP,DOWN,LEFT,RIGHT};
isdirection dir;
void setup()
{
gameover=false;
dir=STOP;
x=width/2;
y=height/2;
fruitx=rand()%width;
fruity=rand()%height;
score=0;
}
void draw()
{
system("cls");
// system clear
for(int i=0;i<width+2;i++)
cout<<"*";
cout<<endl;
for(int i=0;i<height;i++)
{
    for(int j=0;j<width;j++)
    {
        if(j==0)
        cout<<"*";
     if(i==y&&j==x)
     cout<<"O";
     else if(i==fruity&&j==fruitx)
cout<<"F";
     else
     {
bool print=false;
         for(int k=0;k<ntail;k++)
         {
             
             if(tailx[k]==j&&taily[k]==i)
             {
                 cout<<"o";
                 print=true;
             }
             
         }
         if(!print)
             cout<<" ";
        

     }
        
        if(j==width-1)
        cout<<"*";
    }
    cout<<endl;
}

for(int i=0;i<width+2;i++)
cout<<"*";
cout<<endl;
cout<<"score"<<score;
cout<<endl;
}
void input()
{
if(_kbhit())
{
    switch(_getch())
    {
        case 'a':
        dir=LEFT;
        break;
        case 's':
        dir=DOWN;
        break;
        case 'd':
        dir=RIGHT;
        break;
        case 'w':
        dir=UP;
        break;
        case '0':
        gameover=true;
        break;

    }
}

}
void logic()
{
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=x;
    taily[0]=y;
    for(int i=1;i<ntail;i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        taily[i]=prevy;
        tailx[i]=prevx;
        prevx=prev2x;
        prevy=prev2y;
    }
switch(dir)
{
    case LEFT:
    x--;
    break;
    case RIGHT:
    x++;
    break;
    case UP:
y--;
    break;
    case DOWN:
y++;
    break;
}
if(x>width||x<0||y>height||y<0)
{
    gameover=true;
}

  if(x==fruitx&&y==fruity)
  {
     
      score+=10;
      fruitx=rand()%width;
      fruity=rand()%height;
       ntail++;

  }

}
int main()
{setup();
while(!gameover)
{
    draw();
    input();
    logic();
    Sleep(30);
}
    return 0;
}