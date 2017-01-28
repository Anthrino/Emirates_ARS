/*This project simulates an airline reservation system. This program works solely in graphics mode.
Users can choose to do the following:
1.	sBOOK A TICKET
2.	CANCEL  A TICKET
3.	VIEW PREVIOUS BOOKINGS
4.	VIEW  DESTINATIONS
5.	VIEW ACCOUNT STATUS
Appropriate functions are invoked to carry out each of these functions.

System Credentials :
	
	Username : interpol101
	Password : cpp

=====================================================================================================================================
Project made by:
	       1.Jerin J John
	       2.Jay Vivarekar
=====================================================================================================================================*/

//HEADER FILES USED IN PROJECT
#include<stdlib.h>
#include<process.h>
#include<string.h>
#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<time.h>

//SOME IMPORTANT MOUSE AND BITMAP RELATED FUNCTIONS AND DECLARATIONS
union REGS in,out;
void mouseposi(int &xpos,int &ypos,int &click)
{       in.x.ax=3;
	int86(51,&in,&out);
	click=out.x.bx;
	xpos=out.x.cx;
	ypos=out.x.dx;
}
void setposi(int &xpos,int &ypos)
{	in.x.ax=4;
	in.x.cx=xpos;
	in.x.dx=ypos;
	int86(51,&in,&out);
}



void showmouse(int x2,int y2)
{	setcolor(5);
	pieslice(x2,y2,285,325,10);
}

int huge detectsvga()
{	return 5;}
struct A
{	char type[2];
	unsigned long size;
	unsigned short int reserved1, reserved2;
	unsigned long offset;
}  Header;
struct B
{ 	unsigned long size;
	long width,height;
	unsigned short int planes;
	unsigned short int bits;
	unsigned long compression;
	unsigned long imagesize;
	unsigned long xresolution,yresolution;
	unsigned long ncolours;
	unsigned long importantcolours;
}Infoheader;
char city[50],city1[50];

//CLASS USED IN PROJECT
class passenger
{	char name[100];
	int age;
	char classe;
	char origin[50],dest[50];
	char flight[6];
	long int fare;
	char date[10];
	public:
	passenger()
	{classe='E';
	 flight[0]='E';
	 flight[1]='K'; }
	void getpassenger();
	void showpassenger(int p);
	void setorigindest(char a[50],char b[50])
	{ strcpy(origin,a);
	  strcpy(dest,b);
	}
	void setflight(char a,int g)
	{ flight[g]=a;}
	void setfare(int w)
       {fare=((long int)w*1000)+999;
	}
       void setdate(char t[10])
       {strcpy(date,t); }
       void copydate(char u[10])
       {strcpy(u,date);  }
       void copyorigindest(char j[50],char k[50])
       {strcpy(j,origin);
	strcpy(k,dest); }
};

void passenger::getpassenger()
{       clrscr();
	setcolor(5);
	for(int i=0;i<14;i++)
	cout<<"\n";
	cout<<"\t\t\t\t\t    ";
	outtextxy(156,211,"Enter full name : ");
	gets(name);
	cout<<"\n\n\t\t\t\t\t    ";
	outtextxy(210,259,"Enter Age : ");
	cin>>age;
	setcolor(1);
	rectangle(570,150,980,350);
	setcolor(15);
	outtextxy(630,190,"Press E for Economy class ");
	outtextxy(630,245,"Press B for Buisness class ");
	outtextxy(620,285," (Total Fare + INR 20000)");
	a:classe=getch();
	if(!(classe=='e'||classe=='b'))
	{setcolor(11);
	outtextxy(250,600,"Select valid class");
	delay(1000);
	setcolor(0);
	outtextxy(250,600,"Select valid class");
	goto a;}

}
void passenger::showpassenger(int p)
{       settextstyle(1,0,3);
	if(p==0)
	{setcolor(1);
	line(0,50,1023,50);
	line(0,100,1023,100);
	setcolor(10);
	outtextxy(420,60,"TICKET DETAILS");
	setcolor(3);
	rectangle(150,150,875,610);}
	setcolor(4);
	outtextxy(300+p,200,"NAME : ");
	outtextxy(300+p,250,"AGE : ");
	outtextxy(300+p,300,"FROM : ");
	outtextxy(570+p,300,"TO : ");
	outtextxy(300+p,350,"DATE OF JOURNEY : ");
	outtextxy(300+p,400,"FLIGHT NO : ");
	outtextxy(300+p,450,"CLASS : ");
	outtextxy(300+p,500,"FARE : ");
	setcolor(14);
	outtextxy(390+p,200,name);
	char c[3];
	itoa(age,c,10);
	outtextxy(370+p,250,c);
	setcolor(15);
	outtextxy(385+p,300,origin);
	outtextxy(623+p,300,dest);
	setcolor(9);
	outtextxy(535+p,350,date);
	setcolor(2);
	if(classe=='e')
	  outtextxy(396+p,450,"Economy");
	else
	{outtextxy(396+p,450,"Buisness");
	 fare=fare+20000;}
	outtextxy(450+p,400,flight);
	char d[6];
	ltoa(fare,d,10);
	outtextxy(380+p,500,"INR ");
	outtextxy(430+p,500,d);
}

//FUNCTION DECLARATIONS
void showmouse(int,int);
void page();
void mouse();
void mouse1();
void mouse2();
void mouse3();
void creditcard();
void show(char a[]);
void pos(float,float);
void password();
void rev1(int a);
int book();
void final();
int  view();
void strata();
int checkey();
void title();
void accset();
void destinations();
void design(int a);
void console();
void check();
void transaction();
void ab();
void swipe(int a);
void delete1(int p);
void avail();
void disp(char[50]);
int check(int,int,int);

//GLOBAL DATA MEMBERS
int x,y,cl=0,temp1,temp2,c=1,h=135,fc=0;
int i2,e=0,flag=3,flag1=0,flags=1;
float x1,y1;
int ch,aq=0,cl1=0,a,at,at1;
char *buf,*buf1;
int list1[10];
char list[10][3];
int e1;
passenger p;

//MAIN FUNCTION
void main()
{	int gd,gm;
	gd=installuserdriver("SVGA256",&detectsvga);
	gd=DETECT;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	getch();
	password();
	settextstyle(4,0,5);
	int ch1,ch2;
	cleardevice();
	show("logo.bmp");
	int xc=imagesize(0,0,200,85);
	buf1=new char[xc];
	getimage(0,0,200,85,buf1);
	cleardevice();
	a:closegraph();
	gd=installuserdriver("SVGA256",&detectsvga);
	gd=DETECT;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	page();
	if(flags==0)
	goto a;
}

//PASSWORD FUNCTION
void password()
{       title();
	char useract[100]={"interpol101"};
	char userent[100];
	char passent[30];
	setcolor(15);
	line(0,200,1023,200);
	setcolor(4);
	line(0,205,1023,205);
	settextstyle(4,0,4);
	setcolor(11);
	outtextxy(155,210," Welcome To Emirates >>> The World's Best Airline ");
	setcolor(4);
	line(0,255,1023,255);
	setcolor(15);
	line(0,260,1023,260);
	settextstyle(3,0,3);
	setcolor(10);
	outtextxy(10,300," Please login with your Emirates account below :-  ");
	d:for(int q=0;q<23;q++)
	cout<<"\n";
	cout<<"\t\t\t\t\t\t             ";
	setcolor(YELLOW);
	outtextxy(350,356,"Username : ");
	cin>>userent;
	if( strcmp(useract,userent)!=0 )
	{ a:setcolor(RED);
	     outtextxy(350,450,"Incorrect Username ...... ACCESS DENIED");
	  outtextxy(350,500,"Press Q/q to quit...");
	  outtextxy(350,550,"Press T/t to try again...");
	  char ch1;
	  ch1=getch();
	  if(ch1=='t'||ch1=='T')
	  {setcolor(0);
	  outtextxy(350,450,"Incorrect Username ...... ACCESS DENIED");
	  outtextxy(350,500,"Press Q/q to quit...");
	  outtextxy(350,550,"Press T/t to try again...");
	  setfillstyle(1,0);
	  bar(350,370,1000,390);
	   clrscr();
	   goto d;
	  }
	  else if(ch1=='q'||ch1=='Q')
	  {swipe(1);
	   exit(0); }
	  else
	  {setcolor(0);
	  outtextxy(350,450,"Incorrect Username ...... ACCESS DENIED");
	  outtextxy(350,500,"Press Q/q to quit...");
	  outtextxy(350,550,"Press T/t to try again...");
	  setcolor(YELLOW);
	  outtextxy(350,450,"Enter valid choice");
	  getch();
	  setcolor(0);
	  outtextxy(350,450,"Enter valid choice");
	  goto a;
	   }  }
	delay(500);
	d1:setcolor(YELLOW);
	   settextstyle(3,0,3);
	   outtextxy(353,390,"Password : ");
	moveto(488,395);
	int i=0;
	char ch;
	fflush(stdin);
	while(2)
	  {  ch=getch();
	    if(ch=='\r')
	     break;
	     else
	    {passent[i]=ch;
	    outtext("*");
	     i++;  }
	      }
	  passent[i]='\0';
	setcolor(1);
	settextstyle(1,0,4);
	line(0,450,1024,450);
	line(0,600,1024,600);
	setcolor(4);
	outtextxy(85,500,"             Verifying Password        ");
	for(int j=0;j<4;j++)
	{rev1(2);
	 rev1(0);}
	setcolor(0);
	outtextxy(85,500,"             Verifying Password        ");
	setcolor(2);
	if(strcmp(passent,"cpp")==0)
	{outtextxy(380,500,"Access Granted");
	 delay(60);
	 swipe(1);
	 }
	else
	{outtextxy(390,500,"Access Denied");
	 delay(700);
	 settextstyle(3,0,3);
	 setfillstyle(1,0);
	 bar(0,452,1023,598);
	 a1:setcolor(RED);
	   outtextxy(350,500,"Press Q/q to quit...");
	   outtextxy(350,550,"Press T/t to try again...");
	  char ch2;
	  ch2=getch();
	  if(ch2=='t'||ch2=='T')
	  {setcolor(0);
	  outtextxy(350,500,"Press Q/q to quit...");
	  outtextxy(350,550,"Press T/t to try again...");
	  line(0,450,1024,450);
	  line(0,600,1024,600);
	  setfillstyle(1,0);
	  bar(340,400,1000,420);
	  goto d1;
	  }
	  else if(ch2=='q'||ch2=='Q')
	  {swipe(1);
	   exit(0); }
	  else
	  {setcolor(0);
	   outtextxy(350,500,"Press Q/q to quit...");
	   outtextxy(350,550,"Press T/t to try again...");
	   setcolor(YELLOW);
	   outtextxy(350,450,"Enter valid choice");
	   getch();
	   setcolor(0);
	   outtextxy(350,450,"Enter valid choice");
	   goto a1;
	   }
	  }
	}

//MAIN MENU
void page()
{       setcolor(4);
	line(0,45,1023,45);
	setcolor(4);
	line(0,145,1023,145);
	cleardevice();
	title();
	setcolor(4);
	line(60,365,340,365);
	line(60,375,340,375);
	line(680,365,960,365);
	line(680,375,960,375);
	line(505,200,505,300);
	line(515,200,515,300);
	line(505,440,505,600);
	line(515,440,515,600);
	setcolor(14);
	line(510,200,510,300);
	line(510,440,510,600);
	line(60,370,340,370);
	line(680,370,960,370);
	setcolor(14);
	setfillstyle(1,1);
	settextstyle(1,0,4);
	delay(100);
	bar(60,200,360,300);
	bar(660,200,960,300);
	delay(90);
	fillellipse(510,370,170,70);
	delay(80);
	bar(60,440,360,540);
	bar(660,440,960,540);
	delay(70);
	fillellipse(510,650,100,50);
	rectangle(60,200,360,300);
	setcolor(14);
	rectangle(60,440,360,540);
	rectangle(660,200,960,300);
	rectangle(660,440,960,540);
	setcolor(2);
	delay(60);
	outtextxy(95,228,"BOOK A TICKET");
	outtextxy(682,228,"CANCEL A TICKET");
	delay(50);
	outtextxy(400,348,"DESTINATIONS");
	delay(40);
	outtextxy(95,450,"VIEW PREVIOUS");
	outtextxy(95,490,"   BOOKINGS  ");
	outtextxy(745,450,"EMIRATES");
	outtextxy(745,490,"ACCOUNT");
	delay(30);
	outtextxy(455,630,"LOGOUT");
	mouse();
	swipe(1);
	switch (i2)
	{case 0: book();
		 break;
	 case 1 : fc=1;
		  view();
		  break;
	 case 2:  fc=0;
		  view();
		  break;
	 case 3:  accset();
	  break;
	 case 4:  destinations();
	  break;
	 case 5:  final();
		   }
	swipe(2);
}


//FUNCTION TO BOOK A TICKET
int book()
{	cleardevice();
	settextstyle(1,0,3);
	setcolor(3);
	outtextxy(280,100," >>  SELECT ORIGIN & DESTINATION  << ");
	delay(50);
	show("world1.bmp");
	do
	{console();
	 mouse1();}
	while(flag!=0);
	swipe(3);
	p.setorigindest(city,city1);
	cl1=0;
	e=0;
	avail();
	settextstyle(3,0,3);
	setcolor(2);
	line(0,50,1023,50);
	line(0,110,1023,110);
	setcolor(4);
	outtextxy(350,65,"ENTER PASSENGER DETAILS");
	p.getpassenger();
	setcolor(2);
	line(0,598,1023,598);
	setcolor(4);
	line(0,602,1023,602);
	setfillstyle(1,1);
	bar(112,550,460,650);
	bar(564,550,912,650);
	setcolor(14);
	rectangle(112,550,460,650);
	rectangle(564,550,912,650);
	settextstyle(1,0,4);
	setcolor(4);
	outtextxy(315,460," ||  PAYMENT OPTIONS  || ");
	settextstyle(1,0,4);
	setcolor(2);
	outtextxy(123,580," EMIRATES ACCOUNT ");
	outtextxy(573,580," CREDIT/DEBIT CARD");
	mouse3();
	if(at1==1)
	{ creditcard();}
	swipe(0);
	cleardevice();
	transaction();
	cleardevice();
	p.showpassenger(0);
	outtextxy(270,650,"PRESS ENTER TO RETURN TO MAIN MENU");
	getch();
	fstream file;
	 file.open("RECORD.DAT",ios::binary|ios::in|ios::out);
	 file.seekg(0,ios::end);
	 file.write((char*)&p,sizeof(p));
	 file.close();
	 swipe(1);
	 flags=0;
	 return 1;

}


//FUNCTION TO VIEW AND CANCEL TICKETS
int view()
{       o:c=1;
	cleardevice();
	passenger s;
	setcolor(1);
	line(400,0,400,767);
	line(0,70,400,70);
	line(0,100,1023,100);
	line(200,70,200,767);
	settextstyle(1,0,4);
	setcolor(4);
	outtextxy(135,13,"TICKETS");
	outtextxy(610,25,"TICKET DETAILS");
	settextstyle(1,0,3);
	outtextxy(60,70,"ORIGIN");
	outtextxy(232,70,"DESTINATION");
	setcolor(2);
	ifstream file;
	h=130;
	settextstyle(3,0,3);
	file.open("RECORD.DAT",ios::binary);
	int i=1;
	while(file&&i<13)
	 {file.read((char*)&s,sizeof(s));
	  char origin1[50];
	  char dest1[50];
	  s.copyorigindest(origin1,dest1);
	  outtextxy(35,h,origin1);
	  outtextxy(230,h,dest1);
	  h+=50;
	  i++;
	 }
	  h=145;
	 setcolor(14);
	 line(12,h-5,22,h);
	 line(12,h+5,22,h);
	  int a=0;
	 do
	 {if(fc==1)
	   setcolor(3);
	  else
	   setcolor(4);
	  outtextxy(430,300,"USE W AND S TO NAVIGATE THROUGH THE RECORDS");
	  outtextxy(430,360,"PRESS ENTER TO VIEW TICKET");
	  outtextxy(430,420,"PRESS E TO RETURN TO MAIN MENU");
	  a=checkey();
	  if(a==5)
	  {file.seekg(0,ios::beg);
	   setfillstyle(1,0);
	   bar(401,101,1024,767);
	   file.seekg((c-1)*sizeof(s));
	   file.read((char*)&s,sizeof(s));
	   s.showpassenger(200);
	   if(fc==0)
	   {  setcolor(3);
	      outtextxy(500,580,"PRESS ENTER TO RETURN TO RECORDS");
	      getch();
	      setfillstyle(1,0);
	      bar(401,101,1024,767);
	      continue;  }
	   else
	   {setcolor(14);
	    setfillstyle(1,1);
	    settextstyle(1,0,2);
	    delay(100);
	    fillellipse(713,620,150,60);
	    bar(450,715,580,750);
	    outtextxy(455,720," <<< BACK ");
	    settextstyle(1,0,3);
	    outtextxy(600,605,"CANCEL THIS TICKET");
	    mouse2();
	    if(at==0)
	    {setfillstyle(1,0);
	     bar(401,101,1024,767);
	     outtextxy(450,200,"PRESS Y TO COFIRM CANCELLATION..");
	     outtextxy(450,300,"PRESS N TO RETURN TO RECORDS..");
	     char dash;
	     dash=getch();
	     if(dash=='n'||dash=='N')
	     {setfillstyle(1,0);
	      bar(401,101,1024,767);
	      continue;}
	     else if(dash=='y'||dash=='Y')
	     {setfillstyle(1,0);
	      bar(401,101,1024,767);
	      file.close();
	      delete1(c);
	     goto o;
	     }


	    }
	    else if(at==1)
	    {setfillstyle(1,0);
	     bar(401,101,1024,767);

	     continue;}
		  } }
	      } while(a!=-1);
	 swipe(1);
	  c=1;
	  flags=0;
	  return 1;
	  }



//FUNCTION TO CHECK POSITION OF MOUSE POINTER
int check(int x2,int y2,int d)
{	settextstyle(3,0,2);
	setcolor(2);
	if (d==0)
	if((x2>60&&x2<360)&&(y2>200&&y2<300))
	{i2=0;
	 return 0;}
	else if((x2>660&&x2<960)&&(y2>200&&y2<300))
	 {i2=1;
	 return 0;}
	else if((x2>60&&x2<360)&&(y2>440&&y2<540))
	 {i2=2;
	 return 0;}
	else if((x2>660&&x2<960)&&(y2>440&&y2<540))
	 {i2=3;
	  return 0;}
	else if((x2>340&&x2<680)&&(y2>300&&y2<440))
	 {i2=4;
	  return 0;
	 }
	else if((x2>410&&x2<610)&&(y2>600&&y2<700))
	 {i2=5;
	  return 0;
	   }
	else return 1;
	else if(d==1)
	if((cl==1)&&(x2>283&&x2<293)&&(y2>323&&y2<333))
	{disp("New York");
	 return 0; }
	if((cl==1)&&(x2>275&&x2<285)&&(y2>339&&y2<349))
	{disp("Washington DC");
	 return 0;}
	if((cl==1)&&(x2>275&&x2<285)&&(y2>299&&y2<309))
	{disp("Toronto");
	 return 0;}
	if((cl==1)&&(x2>249&&x2<259)&&(y2>311&&y2<321))
	{disp("Chicago");
	 return 0;}
	if((cl==1)&&(x2>169&&x2<179)&&(y2>263&&y2<273))
	{disp("Vancouver");
	 return 0;}
	if((cl==1)&&(x2>157&&x2<167)&&(y2>319&&y2<329))
	{disp("San Francisco");
	 return 0;}
	if((cl==1)&&(x2>163&&x2<173)&&(y2>343&&y2<353))
	{disp("Los Angelos");
	 return 0;}
	if((cl==1)&&(x2>209&&x2<219)&&(y2>413&&y2<423))
	{disp("Mexico City");
	 return 0;}
	if((cl==1)&&(x2>357&&x2<367)&&(y2>575&&y2<585))
	{disp("Rio De Janerio");
	 return 0;}
	if((cl==1)&&(x2>313&&x2<323)&&(y2>649&&y2<659))
	{disp("Buenos Aires");
	 return 0;}
	if((cl==1)&&(x2>519&&x2<529)&&(y2>623&&y2<633))
	{disp("Cape Town");
	 return 0;}
	if((cl==1)&&(x2>567&&x2<577)&&(y2>499&&y2<509))
	{disp("Nairobi");
	 return 0;}
	if((cl==1)&&(x2>615&&x2<625)&&(y2>395&&y2<405))
	{disp("Dubai");
	 return 0;}
	if((cl==1)&&(x2>501&&x2<511)&&(y2>321&&y2<331))
	{disp("Rome");
	 return 0;}
	if((cl==1)&&(x2>501&&x2<511)&&(y2>287&&y2<297))
	{disp("Frankfurt");
	 return 0;}
	if((cl==1)&&(x2>477&&x2<487)&&(y2>293&&y2<303))
	{disp("Paris");
	 return 0;}
	if((cl==1)&&(x2>467&&x2<477)&&(y2>271&&y2<281))
	{disp("London");
	 return 0;}
	if((cl==1)&&(x2>565&&x2<575)&&(y2>255&&y2<265))
	{disp("Moscow");
	 return 0;}
	if((cl==1)&&(x2>679&&x2<689)&&(y2>383&&y2<393))
	{disp("New Delhi");
	 return 0;}
	if((cl==1)&&(x2>667&&x2<677)&&(y2>419&&y2<429))
	{disp("Mumbai");
	 return 0;}
	if((cl==1)&&(x2>685&&x2<695)&&(y2>439&&y2<449))
	{disp("Chennai");
	 return 0;}
	if((cl==1)&&(x2>763&&x2<773)&&(y2>309&&y2<319))
	{disp("Beijing");
	 return 0;}
	if((cl==1)&&(x2>783&&x2<793)&&(y2>357&&y2<367))
	{disp("Shanghai");
	 return 0;}
	if((cl==1)&&(x2>771&&x2<781)&&(y2>401&&y2<411))
	{disp("Hong Kong");
	 return 0;}
	if((cl==1)&&(x2>747&&x2<757)&&(y2>469&&y2<479))
	{disp("Kuala Lumpur");
	 return 0;}
	if((cl==1)&&(x2>755&&x2<765)&&(y2>495&&y2<505))
	{disp("Singapore");
	 return 0;}
	if((cl==1)&&(x2>863&&x2<873)&&(y2>641&&y2<651))
	{disp("Sydney");
	 return 0;}
	if((cl==1)&&(x2>831&&x2<841)&&(y2>333&&y2<343))
	{disp("Tokyo");
	 return 0;}
	if((cl==1)&&(x2>880&&x2<980)&&(y2>10&&y2<30))
	{if (!strcmp(city1,city))
	 {setcolor(3);
	  outtextxy(400,1,"Select different locations");
	  delay(1000);
	  aq=1;
	  flag=1;
	  e=0;
	  cl1=0;}
	 else
	 {aq=1;
	  flag=0;
	  cl1++;}
	  return 0;}
	 if((cl==1)&&(x2>880&&x2<980)&&(y2>50&&y2<70))
	 {aq=1;
	  flag=1;
	  cl1=0;
	  e=0;
	  return 0;}
	 else if(d==2)
	 {  if((cl==1)&&(x2>413&&x2<1013)&&y2>560&&y2<680)
	    {at=0;
	     return 0;}
	 else if((cl==1)&&(x2>450&&x2<580)&&y2>715&&y2<750)
	  { at=1;
	    return 0;}

	  }
	 else if(d==3)
	 {  if((cl==1)&&(x2>112&&x2<460)&&y2>550&&y2<650)
	    {at1=0;
	     return 0;}
	 else if((cl==1)&&(x2>564&&x2<912)&&y2>550&&y2<650)
	    {at1=1;
	    return 0;}
	 }
	 return 1;

}

//ACCOUNT SETTINGS FUNCTIONS
void accset()
{	cleardevice();
	clrscr();
	settextstyle(1,0,4);
	setcolor(14);
	line(0,50,1023,50);
	line(0,120,1023,120);
	setcolor(1);
	line(0,45,1023,45);
	line(0,125,1023,125);
	setcolor(4);
	outtextxy(365,65,"EMIRATES ACCOUNT");
	settextstyle(1,0,3);
	setcolor(14);
	line(819,50,819,120);
	line(205,50,205,120);
	setcolor(1);
	line(200,50,200,120);
	line(824,50,824,120);
	setcolor(2);
	delay(40);
	outtextxy(290,220,"     Profile Name : Sean Parker");
	delay(40);
	outtextxy(293,250,"              Age : 25");
	delay(40);
	outtextxy(302,280,"City of Residence : Mumbai");
	delay(40);
	outtextxy(278,340,"        User Name : interpol101");
	delay(40);
	outtextxy(291,370,"         Password : cpp");
	delay(40);
	outtextxy(288,430,"Emirates Acct NO. : R23UX90");
	delay(40);
	outtextxy(286,460,"  Account Balance : INR 8,79,549");
	delay(40);
	outtextxy(283,490," EK Reward Points : 40,921");
	setcolor(1);
	delay(40);
	outtextxy(250,600,"Press any key to return to Main Menu...");
	getch();
	swipe(1);
	page();
}


//MISCELLANEOUS FUNCTIONS
void console()
{     	setfillstyle(1,0);
	bar(0,0,1024,85);
	setfillstyle(1,4);
	bar(880,10,980,30);
	bar(880,50,980,70);
	putimage(0,0,buf1,0);
	settextstyle(3,0,2);
	setcolor(6);
	outtextxy(300,30,"FROM : ");
	outtextxy(550,30,"TO : ");
	outtextxy(890,7,"CONFIRM");
	outtextxy(900,46,"CLEAR");
}
void ab()
{       a=375;
	if (cl1!=0)
	{setfillstyle(1,0);
	 bar(600,30,780,85);
	 a=600;}
}
void disp(char s[50])
{	if(e==0)
	 strcpy(city,s);
		else
	 strcpy(city1,s);
	e++;
	ab();
	outtextxy(a,30,s);
	aq=0;
	cl1++;
}

void avail()
{	closegraph();
	int gd,gm;
	 char s[3];
	 char s1[3];
	 char s2[3];
	char s3[3];
	char s4[3];
	gd=installuserdriver("SVGA256",&detectsvga);
	gd=DETECT;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	settextstyle(3,0,3);
	char list[10][3];
	for(int q=0;q<23;q++)
	  cout<<"\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t  ";
	setcolor(14);
	line(0,50,1023,50);
	outtextxy(400,60,"FLIGHTS AVAILABLE");
	line(0,100,1023,100);
	setcolor(4);
	outtextxy(150,130,"FROM : ");
	setcolor(11);
	outtextxy(237,130,city);
	setcolor(4);
	outtextxy(176,160,"TO : ");
	setcolor(11);
	outtextxy(237,160,city1);
	outtextxy(175,355,"ENTER DATE OF JOURNEY(dd/mm/yyyy) :");
	char date3[10];
	gets(date3);
	p.setdate(date3);
	setfillstyle(1,0);
	bar(70,330,1023,390);
	setcolor(4);
	outtextxy(150,190,"DATE :");
	setcolor(11);
	p.copydate(date3);
	outtextxy(237,190,date3);
	setcolor(15);
	line(85,270,935,270);
	line(85,320,935,320);
	line(85,270,85,767);
	line(135,270,135,767);
	line(935,270,935,767);
	line(85,767,935,767);
	line(155,270,155,270);
	line(285,270,285,767);
	line(510,270,510,767);
	line(610,270,610,767);
	line(710,270,710,767);
	int h=370;
	for(int i=0;i<8;i++)
	{line(85,h,935,h);
	  h=h+50;}
	randomize();
	int l=random(9)+2;
	setcolor(3);
	h=330;
	for(int y=1;y<l;y++)
	{char w[2];
	 itoa(y,w,10);
	 outtextxy(105,h,w);
	 h+=50;}
	setcolor(10);
	outtextxy(155,279,"FLIGHT NO.");
	h=330;
	setcolor(3);
	for(y=0;y<l-1;y++)
	{ char c[3];
	 int x=random(100)+200;
	 itoa(x,c,10);
	 list[y][0]=c[0];
	 list[y][1]=c[1];
	 list[y][2]=c[2];
	 outtextxy(170,h,"EK");
	 outtextxy(196,h,c);
	 int e=random(50)+10;
	 itoa(e,s,10);
	 outtextxy(380,h,s);
	 int u,f,m,n;
	 f=random(9)+1;
	 u=random(24)+1;
	 m=random(50)+10;
	 n=random(50)+10;
	 itoa(f,s1,10);
	 itoa(u,s2,10);
	 itoa(m,s3,10);
	 itoa(n,s4,10);
	 outtextxy(565,h,s3);
	 outtextxy(665,h,s4);
	 if(f>=10)
	 outtextxy(522,h,s1);
	 else
	 outtextxy(530,h,s1);
	 outtextxy(555,h,":");
	 if(u>=10)
	 outtextxy(622,h,s2);
	 else
	 outtextxy(630,h,s2);
	 outtextxy(655,h,":");
	 int r=random(20)+30;
	 long int t=((long int)r*1000)+999;
	 list1[y]=r;
	 char s5[6];
	 ltoa(t,s5,10);
	 outtextxy(760,h,"INR");
	 outtextxy(800,h,s5);
	 h+=50;
	}
	setcolor(10);
	outtextxy(305,279,"SEATS AVAILABLE");
	outtextxy(538,279,"E.T.D");
	outtextxy(638,279,"E.T.A");
	outtextxy(755,279,"TOTAL FARE");
	int flag=1;
	while(5)
	{if(flag==0)
	 {setcolor(0);
	  outtextxy(455,150,"PLEASE CHOOSE VALID FLIGHT NUMBER");
	  outtextxy(500,160,"PRESS Y TO CONFIRM...");
	  outtextxy(500,190,"PRESS N TO RESELECT...");
	  outtextxy(500,220,"PRESS E TO RETURN TO MAIN MENU...");
	  outtextxy(500,120,"CONFIRM TICKET ON FLIGHT ");
	  flag=1;}
	 setcolor(10);
	 outtextxy(455,150,"ENTER THE DESIRED FLIGHT'S SERIAL NO.");
	 char cha=getch();
	 char chg[1];
	 chg[0]=cha;
	 setcolor(0);
	 outtextxy(455,150,"ENTER THE DESIRED FLIGHT'S SERIAL NO.");
	 e1=atoi(chg);
	 e1=e1%10;
	 if(e1>=l)
	 {setcolor(10);
	  outtextxy(455,150,"PLEASE CHOOSE VALID FLIGHT NUMBER");
	  flag=0;
	  getch();
	  continue;}
	 else
	 {setcolor(10);
	  outtextxy(500,120,"CONFIRM TICKET ON FLIGHT ");
	  itoa(e1,chg,10);
	  outtextxy(800,120,chg);
	  setcolor(9);
	  outtextxy(500,160,"PRESS Y TO CONFIRM...");
	  outtextxy(500,190,"PRESS N TO RESELECT...");
	  outtextxy(500,220,"PRESS E TO RETURN TO MAIN MENU...");
	  char chb=getch();
	  setcolor(10);
	  if(chb=='E'||chb=='e')
	       { swipe(1);
	       page(); }
	  else if(chb=='Y'||chb=='y')
		break;
	 }
	 setcolor(0);
	 outtextxy(800,120,chg);
	 flag=0;
	}
	p.setflight(list[e1-1][0],2);
	p.setflight(list[e1-1][1],3);
	p.setflight(list[e1-1][2],4);
	p.setfare(list1[e1-1]);
	swipe(2);

}
void destinations()
{	setcolor(4);
	settextstyle(1,0,5);
	line(0,50,1023,50);
	setcolor(3);
	outtextxy(370,55,"DESTINATIONS");
	setcolor(4);
	line(0,110,1023,110);
	setcolor(1);
	line(12,180,12,680);
	line(262,180,262,680);
	line(512,180,512,680);
	line(762,180,762,680);
	line(1012,180,1012,680);
	line(12,180,1012,180);
	line(12,230,1012,230);
	line(12,680,1012,680);
	settextstyle(1,0,3);
	setcolor(14);
	outtextxy(340,120,"Centre of Operations : Dubai");
	settextstyle(1,0,4);
	outtextxy(30,185,"THE AMERICAS");
	outtextxy(293,185,"ASIA PACIFIC");
	outtextxy(580,185,"AFRICA");
	outtextxy(835,185,"EUROPE");
	settextstyle(3,0,3);
	setcolor(2);
	outtextxy(840,250,"Frankfurt");
	outtextxy(840,280,"Paris");
	outtextxy(840,310,"London");
	outtextxy(840,340,"Rome");
	outtextxy(840,370,"Moscow");
	outtextxy(580,250,"Cape Town");
	outtextxy(580,280,"Nairobi");
	outtextxy(310,250,"Mumbai");
	outtextxy(310,280,"Delhi");
	outtextxy(310,310,"Chennai");
	outtextxy(310,340,"Shanghai");
	outtextxy(310,370,"Hong Kong");
	outtextxy(310,400,"Beijing");
	outtextxy(310,430,"Kuala Lumpur");
	outtextxy(310,460,"Singapore");
	outtextxy(310,490,"Tokyo");
	outtextxy(310,520,"Sydney");
	outtextxy(40,250,"New York");
	outtextxy(40,280,"Washington DC");
	outtextxy(40,310,"Chicago");
	outtextxy(40,340,"Los Angelos");
	outtextxy(40,370,"San Fransisco");
	outtextxy(40,400,"Vancouver");
	outtextxy(40,430,"Toronto");
	outtextxy(40,460,"Mexico City");
	outtextxy(40,490,"Buenos Aires");
	outtextxy(40,520,"Rio de Janerio");
	settextstyle(3,0,2);
	outtextxy(245,700,"Press any key to return to the main menu... ");
	getch();
	page();
}
void final()
{       cleardevice();
	show("end8.bmp");
	setfillstyle(1,0);
	bar(0,665,1024,768);
	settextstyle(4,0,5);
	setcolor(2);
	outtextxy(195,675," Thank You for Choosing Emirates ");
	getch();
	swipe(1);
	closegraph();
	exit(0);
}

void show(char a[])
{	fstream f;
	f.open(a,ios::in);
	unsigned char Ch;
	f.read((char*)&Header,14);
	f.read((char*)&Infoheader,40);
	unsigned int i;
	char ColorBytes[4];
	char *PaletteData;
	PaletteData=new char[256*3];
	if(PaletteData)
	{for(i=0;i<256;i++)
	 {	f.read(ColorBytes,4);
		PaletteData[(int)(i*3+2)]=ColorBytes[0]>>2;
		PaletteData[(int)(i*3+1)]=ColorBytes[1]>>2;
		PaletteData[(int)(i*3+0)]=ColorBytes[2]>>2;
	 }
	 outp(0x03c8,0);
	 for(i=0;i<256*3;i++)
	 {	outp(0x03c9,PaletteData[i]); }
	 delete[]PaletteData;
	}
	for(i=0;i<Infoheader.height;i++)
	{ for(int j=0;j<Infoheader.width;j++)
	  {	f.read(&Ch,1);
		putpixel(j,Infoheader.height-i-1,Ch);
	  }
	}

  f.close();

 }

int checkey()
{	char w;
	w=getch();
	int x=(int)w;
	if((w=='w'||w=='W')&&c!=1)
	{setcolor(0);
	 line(12,h-5,22,h);
	 line(12,h+5,22,h);
	 h-=50;
	 setcolor(14);
	 line(12,h-5,22,h);
	 line(12,h+5,22,h);
	 c--;
	 return 0;
	}
	else if((w=='s'||w=='S')&&c!=12)
	{setcolor(0);
	 line(12,h-5,22,h);
	 line(12,h+5,22,h);
	 h+=50;
	 setcolor(14);
	 line(12,h-5,22,h);
	 line(12,h+5,22,h);
	 c++;
	  return 1;
	}
	else if(w=='e'||w=='E')
	 return -1;
	else if(x==13)
	 return 5;
	else
	 return 4;
}
void mouse()
{	setcolor(4);
	temp1=200; temp2=200;
	setposi(temp1,temp2);
	int xa=imagesize(200,200,210,210);
	buf=new char[xa];
	getimage(200,200,210,210,buf);
	putimage(temp1,temp2,buf,0);
	showmouse(200,200);
	int q;
	delete buf;
	while(!kbhit())
	{mouseposi(x,y,cl);
	 x1=x<<2;
	 y1=y<<2;
	 if(x1==temp1&&y1==temp2)
	 {if (cl==1)
	 q=check(x1,y1,0);
	  if(q==0)
	  break;
	  continue;     }
	 else
	 {buf=new char[xa];
	 putimage(temp1,temp2,buf,0);
	 getimage(x1,y1,x1+10,y1+10,buf);
	 showmouse(x1,y1);
	 temp1=x1;
	 temp2=y1;
	 }
	 delete buf; }
}
void mouse1()
{       setcolor(4);
	temp1=200; temp2=200;
	int xa1=imagesize(200,200,210,210);
	buf=new char[xa1];
	getimage(200,200,210,210,buf);
	putimage(temp1,temp2,buf,0);
	showmouse(200,200);
	int q1;
	delete buf;
	while(2)
	{mouseposi(x,y,cl);
	 x1=x<<1;
	 y1=y<<2;
	 if(x1==temp1&&y1==temp2)
	 {if (cl==1)
	  q1=check(x1,y1,1);
	  if(q1==0&&aq==0)
	  continue;
	  else if(q1==0&&aq==1)
	  break;
	  continue; }
	 else
	 {buf=new char[xa1];
	 putimage(temp1,temp2,buf,0);
	 getimage(x1,y1,x1+10,y1+10,buf);
	 showmouse(x1,y1);
	 temp1=x1;
	 temp2=y1;
	 }
	  delete buf;
	   }

 }
void mouse2()
{       setcolor(4);
	temp1=200; temp2=200;
	int xa1=imagesize(200,200,210,210);
	buf=new char[xa1];
	getimage(200,200,210,210,buf);
	putimage(temp1,temp2,buf,0);
	showmouse(200,200);
	int q1;
	delete buf;
	while(2)
	{mouseposi(x,y,cl);
	 x1=x<<1;
	 y1=y<<2;
	 if(x1==temp1&&y1==temp2)
	 {if (cl==1)
	  q1=check(x1,y1,2);
	  if(q1==0)
	  break;
	  continue; }
	 else
	 {buf=new char[xa1];
	 putimage(temp1,temp2,buf,0);
	 getimage(x1,y1,x1+10,y1+10,buf);
	 showmouse(x1,y1);
	 temp1=x1;
	 temp2=y1;
	 }
	  delete buf;
	   }

 }
void mouse3()
{       setcolor(4);
	temp1=200; temp2=200;
	int xa1=imagesize(200,200,210,210);
	buf=new char[xa1];
	getimage(200,200,210,210,buf);
	putimage(temp1,temp2,buf,0);
	showmouse(200,200);
	int q1;
	delete buf;
	while(2)
	{mouseposi(x,y,cl);
	 x1=x<<1;
	 y1=y<<2;
	 if(x1==temp1&&y1==temp2)
	 {if (cl==1)
	  q1=check(x1,y1,3);
	  if(q1==0)
	  break;
	  continue; }
	 else
	 {buf=new char[xa1];
	 putimage(temp1,temp2,buf,0);
	 getimage(x1,y1,x1+10,y1+10,buf);
	 showmouse(x1,y1);
	 temp1=x1;
	 temp2=y1;
	 }
	  delete buf;
	   }

 }
void delete1(int p)
{ 	int f=1;
	ifstream g;
	ofstream e;
	passenger y;
	g.open("RECORD.DAT",ios::binary|ios::in);
	e.open("TEMP.DAT",ios::binary|ios::out);
	while(g)
	{if(f!=p)
	 { g.read((char*)&y,sizeof(y));
	   e.write((char*)&y,sizeof(y));
	 }
	 else
	 g.seekg(sizeof(y),ios::cur);
	 f++;
	}
	g.close();
	e.close();
	remove("RECORD.DAT");
	rename("TEMP.DAT","RECORD.DAT");
}
void rev1(int a)
{ 	float y2,n,m,z;
	for(float x=-20.00;x<=20.00;x=x+1.00)
	{n=500-pow(x,2);
	 m=450-pow(x,2);
	 y2=sqrt(n);
	 z=sqrt(m);
	 delay(5);
	 putpixel((int)x+625,(int)y2+520,a);
	 putpixel((int)x+625,(int)z+520,a); }
	for(x=20.00;x>=-20.00;x=x-1.00)
	{n=500-pow(x,2);
	 m=450-pow(x,2);
	 y2=-(sqrt(n));
	 z=-(sqrt(m));
	 delay(5);
	  putpixel((int)x+625,(int)y2+520,a);
	  putpixel((int)x+625,(int)z+520,a); }
}

void swipe(int a)
{	setcolor(0);
	int x,y;
	if(a==0)
	{x=0;
	 while(x<1025)
	 {line(x,0,x,767);
	  x++;
	  delay(1);}}
	if(a==1)
	{y=0;
	 while(y<767)
	 {line(0,y,1024,y);
	  y++;
	  delay(1);}}
	if(a==2)
	{x=1024;
	 while(x>0)
	 {line(x,0,x,767);
	  x--;
	  delay(1);}}
	if(a==3)
	{y=767;
	 while(y>0)
	 {line(0,y,1024,y);
	  y--;
	  delay(1);}}
}
void transaction()
{	setcolor(2);
	settextstyle(3,0,6);
	moveto(600,50);
	for(int n=0;n<3;n++)
	{setcolor(2);
	 moveto(600,75);
	 outtext("VERIFYING");
	 design(2);
	 moveto(600,135);
	 outtext("TRANSACTION...");
	 delay(3);
	 moveto(600,75);
	 setcolor(4);
	 outtext("VERIFYING");
	 design(4);
	 moveto(600,135);
	 outtext("TRANSACTION...");}
	 delay(6);
	 setcolor(0);
	 design(0);
	 moveto(600,75);
	 outtext("VERIFYING");
	 moveto(600,135);
	 outtext("TRANSACTION...");
	 settextstyle(1,0,5);
	 setcolor(2);
	 moveto(120,300);
	 outtext(" >>  TRANSACTION SUCCESSFULL  << ");
	 delay(2000);
	 cleardevice();
	 settextstyle(1,0,4);
	 moveto(50,300);
	 outtext(" Your ticket has been booked successfully....");
	 delay(2000);
	 swipe(2);
}
void design(int a)
{       setcolor(a);
	int c=0,d=0;
	while(d<1024)
	{ delay(10);
	  line(c,d,1024-c,768-d);
	  c=c+10;
	  d=d+10;}
}

void strata()
{       int x=0,y=80;
	while(x<1024)
	{if(x<600||x>952)
	   putpixel(x,y-30,15);
	 if(x<592||x>960)
	   putpixel(x,y-25,4);
	 if(x<586||x>966)
	   putpixel(x,y-20,2);
	 if(x<581||x>971)
	   putpixel(x,y-15,0);
	 if(x<577||x>975)
	   putpixel(x,y-10,15);
	 if(x<574||x>978)
	   putpixel(x,y-5,14);
	 if(x<572||x>980)
	   putpixel(x,y,4);
	 if(x<570||x>982)
	   putpixel(x,y+5,2);
	 if(x<569||x>983)
	   putpixel(x,y+10,1);
	 if(x<568||x>984)
	   putpixel(x,y+15,0);
	 if(x<569||x>983)
	   putpixel(x,y+20,15);
	 if(x<570||x>982)
	   putpixel(x,y+25,2);
	 if(x<572||x>980)
	   putpixel(x,y+30,4);
	 if(x<574||x>978)
	   putpixel(x,y+35,14);
	 if(x<577||x>975)
	   putpixel(x,y+40,1);
	 if(x<581||x>971)
	   putpixel(x,y+45,0);
	 if(x<586||x>966)
	   putpixel(x,y+50,2);
	 if(x<592||x>960)
	   putpixel(x,y+55,4);
	 if(x<600||x>952)
	   putpixel(x,y+60,15);
	 delay(2);
	 x++;
	}
}
void title()
{       strata();
	settextstyle(4,0,9);
	int b;
	for(int a=0;a<6;a++)
	{for(int n=0;n<15;n++)
	 {  if(a%3==0)
	       b=9;
	    if(a%3==1)
	       b=4;
	    if(a%3==2)
	       b=14;
	    if(n==0)
	     moveto(615,27);
	    if(n==5)
	     moveto(615,27);
	    if(n==6)
	     {setcolor(b);
	      outtext("E");}
	    if(n==7)
	    {setcolor(b);
	     outtext("m");
	    }
	    if(n==8)
	    {setcolor(b);
	     outtext("i");
	    }
	    if(n==9)
	    {setcolor(b);
	     outtext("r");
	    }
	    if(n==10)
	    {setcolor(b);
	     outtext("a");
	    }
	    if(n==11)
	    {setcolor(b);
	     outtext("t");
	    }
	    if(n==12)
	    {setcolor(b);
	     outtext("e");
	    }
	    if(n==13)
	    {setcolor(b);
	     outtext("s");
	    }
	    delay(17);}}

}
void creditcard()
{       swipe(1);
	clrscr();
	char bank[50];
	char acctno[10];
	char pin[6];
	settextstyle(3,0,3);
	setcolor(2);
	line(0,50,1023,50);
	line(0,110,1023,110);
	setcolor(4);
	outtextxy(360,65,"ENTER PAYMENT DETAILS");
	for(int i=0;i<15;i++)
	cout<<"\n";
	cout<<"\t\t\t\t\t\t\t ";
	setcolor(14);
	outtextxy(200,228,"Enter Name of Bank : ");
	gets(bank);
	cout<<"\n\n\t\t\t\t\t\t  ";
	outtextxy(200,275,"Enter Card No. : ");
	gets(acctno);
	cout<<"\n\n\t\t\t\t\t\t     ";
	outtextxy(200,324,"Enter 5-Digit PIN : ");
	gets(pin);
	setcolor(4);
	settextstyle(1,0,4);
	line(0,450,1024,450);
	line(0,600,1024,600);
	setcolor(2);
	outtextxy(160,500,"             Verifying PIN        ");
	for(int j=0;j<2;j++)
	{rev1(2);
	 rev1(0);
	 rev1(4);}
	setcolor(0);
	outtextxy(160,500,"             Verifying PIN        ");
	setcolor(2);
	outtextxy(280,480,"   Authenticating  ");
	outtextxy(300,520,"   Transaction     ");
	for(j=0;j<2;j++)
	{rev1(2);
	 rev1(4);
	 rev1(2);
	 rev1(0);}
	setcolor(0);
	outtextxy(280,480,"   Authenticating  ");
	outtextxy(300,520,"   Transaction     ");
	settextstyle(3,0,4);
	setcolor(1);
	outtextxy(220,500,"Press ENTER to confirm payment ... ");
	getch();
}