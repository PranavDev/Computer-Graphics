#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<graphics.h>
#include<math.h>

class transform
{
    private:
	    float input[10][2];
    public :
	    void accept(int edges);
	    void plot(float mat[20][2],int edges);
	    void translate(float tx,float ty,int edges);
	    void scale(float Sx,float Sy,int edges);
	    void rotate(float theta,int edges,int rot);
};

void transform::accept(int edges)
{
  int i,j;
  cleardevice();

  cout<<"\nEnter the co-ordinates for Matrix : \n";
  for(i=1;i<=edges;i++)
  {
    for(j=1;j<=2;j++)
    {
      cout<<"\nA["<<i<<"]["<<j<<"] = ";
      cin>>input[i][j];
    }
  }
  cleardevice();
  plot(input,edges);
}

void transform::plot(float mat[10][2],int edges)
{
  int i=1;
  int j,k;

  for(j=1;j<=edges;j++)
  {
    line(mat[i][1],mat[i][2],mat[i+1][1],mat[i+1][2]);
    i++;
  }
}

void transform::translate(float tx,float ty,int edges)
{
  int i;
  for(i=1;i<edges;i++)
  {
    input[i][1] = input[i][1]+tx;
    input[i][2] = input[i][2]+ty;
  }
  cleardevice();
  plot(input,edges);
}

void transform::scale(float Sx,float Sy,int edges)
{
  int i;
  for(i=1;i<=edges;i++)
  {
    input[i][1] = input[i][1] * Sx;
    input[i][2] = input[i][2] * Sy;
  }
  cleardevice();
  plot(input,edges);
}

void transform::rotate(float theta,int edges,int rot)
{
  int i;
  if(rot==1)
  {
      cout<<"\n\nYou Have Chosen Clockwise Rotation\n";
      input[1][1] = input[1][1] * cos(theta);
      input[2][2] = input[2][2] * cos(theta);
      input[1][2] = input[1][2] * -sin(theta);
      input[2][1] = input[2][1] * sin(theta);
  }
  else if(rot==2)
  {
      cout<<"\n\nYou Have Chosen Anti-Clockwise Rotation\n";
      input[1][1] = input[1][1] * cos(theta);
      input[2][2] = input[2][2] * cos(theta);
      input[1][2] = input[1][2] * sin(theta);
      input[2][1] = input[2][1] * -sin(theta);
  }
  cleardevice();
  plot(input,edges);
}

int main()
{
  int edges,ch,rot;
  float tx,ty,Sx,Sy,theta;

  int gd = DETECT,gm;
  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

  transform tf;

  cout<<"Enter the no. of Edges : ";
  cin>>edges;

  tf.accept(edges);

  while(1)
  {
    cout<<"\nEnter the Choice of Operation Now : \n";
    cout<<"\n1.Translate Matrix";
    cout<<"\n2.Scale Matrix";
    cout<<"\n3.Rotate Matrix";

    cout<<"\n\nEnter Choice : ";
    cin>>ch;

    switch(ch)
    {
      case 1 : cout<<"\n\nTranslate Matrix!";
	       cout<<"\nEnter the Tx and Ty : ";
	       cin>>tx>>ty;
	       cout<<"\nNow We Perform Translation..";
	       tf.translate(tx,ty,edges);
	       break;

      case 2 : cout<<"\n\nScale Matrix!";
	       cout<<"\nEnter the Sx and Sy";
	       cin>>Sx>>Sy;
	       cout<<"\nNow We Perform Scaling..";
	       tf.scale(Sx,Sy,edges);
	       break;

      case 3 : cout<<"\n\nRotate Matrix!";
	       cout<<"\nEnter the Angle of Rotation : ";
	       cin>>theta;
	       cout<<"\nEnter 1 for Clockwise and 2 for Anti-Clockwise : ";
	       cin>>rot;
	       tf.rotate(theta,edges,rot);
	       break;

      default : cout<<"\n\nWrong Choice..!";
		break;

    }
  }

  closegraph();

  return 0;
}
