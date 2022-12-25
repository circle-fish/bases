
#include<iostream>
#include<cstring>
#include <queue>
using namespace std;

char room[25][25];
int dir[4][2] = {
    {-1,0},
    {0,-1},
    {1,0},
    {0,1}
};
int Wx,Hy,num;
#define CHECK(x,y) (x < Wx  && x >= 0 && y < Hy &&  y >= 0)

struct node{int x , y ; };



void bfs(int dx,int dy )
{
   num = 1;
   node start,next;
   start.x  = dx;
   start.y  = dy;
   queue<node> q;
   q.push(start);
   while(!q.empty())
   {
    start = q.front();
    q.pop();
    for(int i  = 0 ;i < 4 ;i ++)
    {
        next.x = start.x + dir[i][0];
        next.y = start.x + dir[i][1];
        if(CHECK (next.x,next.y) && room[next.x][next.y] == '.')
        {
            room[next.x][next.y] = '#';
            num ++;
            q.push(next);
        }
    }
   }

}
 

int main(){
	int dx,dy,Wx,Hy;
    while(cin>>Wx >> Hy )
    {
        if(!(Wx > 0 && Hy > 0)) 
            break;
        for(int y = 0 ; y < Hy ; y++)
            for(int x = 0; x < Wx ; x++ )
            {
                cin>>room[x][y];

                if(room[x][y] == '@')
                {
                    dx = x;
                    dy = y;

                } 
            }
        num = 0;
        bfs(dx,dy);
        cout<< num <<endl;

    }
}
