#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define INIFINITY 4000

char Maze[203][80];
int W,H;
int Queue[3800][2],front,rear;
int MaxDistance=0,temp;
int tx,ty;
int Exit[2][2],Ec=0;  //记录出口坐标 
int Dist1[102][40];
int Dist2[102][40];

int Min(int a,int b)
{
  return a>b?b:a;
}

void Enqueue()
{
  Queue[rear][0]=tx;
  Queue[rear][1]=ty;
  rear++;	
}

void Dequeue()
{
  tx=Queue[front][0];
  ty=Queue[front][1];
  front++;
}

int Search(int x,int y,int (*Dist)[40])
{
  tx=x,ty=y;
  Dist[tx][ty]=1;
  front=0;
  rear=0;
  Enqueue();
  while(front!=rear){
    Dequeue();
    if(Maze[2*tx+1][2*ty]!='-'&&Dist[tx+1][ty]==INIFINITY){
      Dist[tx+1][ty]=Dist[tx][ty]+1;
      tx++;
      Enqueue();
      tx--;
    }
    if(Maze[2*tx-1][2*ty]!='-'&&Dist[tx-1][ty]==INIFINITY){
      Dist[tx-1][ty]=Dist[tx][ty]+1;
      tx--;
      Enqueue();
      tx++;
    }
    if(Maze[2*tx][2*ty+1]!='|'&&Dist[tx][ty+1]==INIFINITY){
      Dist[tx][ty+1]=Dist[tx][ty]+1;
      ty++;
      Enqueue();
      ty--;
    }
    if(Maze[2*tx][2*ty-1]!='|'&&Dist[tx][ty-1]==INIFINITY){
      Dist[tx][ty-1]=Dist[tx][ty]+1;
      ty--;
      Enqueue();
      ty++;
    }						
  }
}

void InitialDist(int (*Dist)[40])
{
  int i,j;
  for(i=1;i<=H;i++)
    for(j=1;j<=W;j++)
      Dist[i][j]=INIFINITY;
}

int main()
{
  FILE *fin,*fout;
  int Dist[2][101][39];
  int i,j;
  fin=fopen("maze1.in","r");
  fout=fopen("maze1.out","w");

  fscanf(fin,"%d %d",&W,&H);
  fscanf(fin,"\n");
  for(i=1;i<=2*H+1;i++){
    for(j=1;j<=2*W+2;j++){
      Maze[i][j]=fgetc(fin);
      if((j==1||j==2*W+1||i==1||i==2*H+1)&&Maze[i][j]==' '){
        if(i==1){
          Exit[Ec][0]=i;
          Exit[Ec][1]=j/2;
          Ec++;
        }
        if(i==2*H+1){
          Exit[Ec][0]=(i-1)/2;
          Exit[Ec][1]=j/2;
          Ec++;
        }
        if(j==1){
          Exit[Ec][0]=i/2;
          Exit[Ec][1]=j;
          Ec++;
        }
        if(j==2*W+1){
          Exit[Ec][0]=i/2;
          Exit[Ec][1]=(j-1)/2;
          Ec++;
        }					
      }
    }
  }
  InitialDist(Dist1);
  InitialDist(Dist2);
  //读取完毕 
  Search(Exit[0][0],Exit[0][1],Dist1);
  Search(Exit[1][0],Exit[1][1],Dist2);

  for(i=1;i<=H;i++){
    for(j=1;j<=W;j++){
      if(MaxDistance<Min(Dist1[i][j],Dist2[i][j]))
        MaxDistance=Min(Dist1[i][j],Dist2[i][j]);
    }
  }

  fprintf(fout,"%d\n",MaxDistance);
  return 0;
}
