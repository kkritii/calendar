//#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
//#include <graphics.h>
#include <time.h>
#include <dos.h>
#include<ctype.h>
#include<string.h>
#include<dir.h>
//#include <string.h>
union REGS in,out;
int b,x,y,option,end=1;
char *input1(int,int,int,int);
long input();
void main_page();
void main_page1();
void menu();
void display1();
void display2();
void bstoad();
void adtobs();
void Exit();
void Graphics();
void intro_graphics();
//void Exit1();
//void alwaysdisplay();
/*void Graphics()
{
 int gd,gm;
 gd=DETECT;
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");
} */

int callmouse()
{
in.x.ax=1;
int86(51,&in,&out);
return 1;
}

void hidemouse()
{
in.x.ax=2;
int86(51,&in,&out);
}

void getmouseposs(int *b,int *x,int *y)
{
 in.x.ax=3;
 int86(51,&in,&out);
 *b=out.x.bx;
 *x=out.x.cx;
 *y=out.x.dx;
}
void restrict(int x1,int y1,int x2,int y2)
{
 in.x.ax=7;
 in.x.cx=x1;
 in.x.dx=x2;
 int86(51,&in,&out);
 in.x.ax=8;
 in.x.cx=y1;
 in.x.dx=y2;
 int86(51,&in,&out);

}

char *input1(int limit,int type,int xc,int yc)
{
char result[50]="";
char ch;
int i=0;
int j=0;
int index=0;
do{
textcolor(0);
ch=getch();
if(type==2&&index<limit)
{
if(isalpha(ch)||ch==' ')
{
 result[index++]=ch;
 if(index<40)
 {
 gotoxy(xc+i,yc);
 cprintf("%c",ch);
 i++;
 }
 else
 {
 gotoxy(xc+j,yc+1);
  cprintf("%c",ch);
  j++;
  }
}
}


if(ch==8&&index>0)
{
/* if(index==1)
 {
  i=0;j=0;
 }
 if(index<40)
 {
 result[index--]=NULL;
 i--;
 printf("\b \b");
 }
 else
 {
 j--;
 printf("\b \b");
 }*/
 if(index<40)
 {
 result[index--]=NULL;
 i--;
 printf("\b \b");
 }
 else
 {
 result[index--]=NULL;
 j--;
 printf("\b \b");
 }
 if(index==39)
 gotoxy(xc+i,yc);
/* i--;
 if(j>0)
 j--;
 if(index==40)
 gotoxy(22+i,15);

 printf("\b \b");
 if(index==1)
  {i=0;j=0; }    */
}

if(type==1&&index<limit)
{
 if(ch>=40&&ch<=57)
 {
  result[index++]=ch;
  cprintf("%c",ch);
 }

}

}
while((ch!=13||index<1)&&ch!=27);
result[index]=0;
return ch==27?"00":result;

}




int leap(int iey);

//void bstoad(void)
//{
//}

int leap(int iey)/* function to check leap or not */
{
	int l;
		if(((iey%4==0)&&(iey%100!=0))||(iey%400==0))
		l=1;
		else
		l=0;
	return l;
}

void loop1()
{
start:
textcolor(0);

   int l;
	gotoxy(15,22);
	textcolor(0);
	cprintf("       Ü");
	gotoxy(15,23);
	cprintf(" ßßßßßßß");
	gotoxy(15,22);
	textcolor(0);
	textbackground(GREEN);
	cprintf(" Again ");
	textbackground(15);
	gotoxy(55,22);
	textcolor(0);
	cprintf("      Ü");
	gotoxy(55,23);
	cprintf(" ßßßßßß");
	gotoxy(55,22);
	textbackground(GREEN);
	textcolor(0);
	 cprintf(" Back ");

    textcolor(0);
    textbackground(15);
   restrict(20,20,620,188);

   getmouseposs(&b,&x,&y);
    delay(10);
   callmouse();
   while(!kbhit())
 {
   getmouseposs(&b,&x,&y);
   if(b==1)
   {gotoxy(30,3);
    printf(" %d - %d ",x,y);
    if(x>=114&&x<=163&&y>=168&&y<=175)
    {option=1;
    }
    else if(x>=434&&y>=170&&x<=488&&y<=176)
    {option=2;
     }
    else
    option=-1;
    hidemouse();

    switch(option)
    {
     case 1:bstoad();break;
     case 2: clrscr(); display2(); break;
     default: callmouse(); break;
     }
     b=-1;
   }
}
char ch=getche();
if(ch==27)
{
  clrscr();
  hidemouse();
  display2();
}
   //delay(20);
// goto start;
 }

void loop2(void)
{

start:
textcolor(0);

   int l;
	gotoxy(15,22);
	textcolor(0);
	cprintf("       Ü");
	gotoxy(15,23);
	cprintf(" ßßßßßßß");
	gotoxy(15,22);
	textcolor(0);
	textbackground(GREEN);
	cprintf(" Again ");
	textbackground(15);
	gotoxy(55,22);
	textcolor(0);
	cprintf("      Ü");
	gotoxy(55,23);
	cprintf(" ßßßßßß");
	gotoxy(55,22);
	textbackground(GREEN);
	textcolor(0);
	 cprintf(" Back ");

    textcolor(0);
    textbackground(15);
   restrict(20,20,620,188);

   getmouseposs(&b,&x,&y);
    delay(10);
   callmouse();
   while(!kbhit())
 {
   getmouseposs(&b,&x,&y);
   if(b==1)
   {gotoxy(30,3);
    printf(" %d - %d ",x,y);
    if(x>=114&&x<=163&&y>=168&&y<=175)
    {option=1;
    }
    else if(x>=434&&y>=170&&x<=488&&y<=176)
    {option=2;
     }
    else
    option=-1;
    hidemouse();

    switch(option)
    {
     case 1:adtobs();break;
     case 2: clrscr(); display2(); break;
     default: callmouse(); break;
     }
     b=-1;
   }
}
char ch=getche();
if(ch==27)
{
clrscr();
hidemouse();
display2();

}
   //delay(20);
// goto start;







       /*	 gotoxy(15,20);
	printf("Press 'y' to continue and 'n' to go back to main menu... ");
	switch(getch())
	{
		case 'y': adtobs();break;
		case 'n':clrscr();display2();break;
	    default:printf("\aInvalid Input!!!");

delay(1000);

adtobs(); */
}



void menu()
{
clrscr();
_setcursortype(_NOCURSOR);
textcolor(BLACK);
gotoxy(30,3); printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»  ");
gotoxy(30,4); printf("º		     º  ");
gotoxy(30,5); printf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼  ");
 gotoxy(32,4);
 textcolor(RED);
 cprintf("Convertor Page");
  textcolor(0);
	gotoxy(8,7);
	cprintf("         Ü");
	gotoxy(8,8);
	cprintf("ßßßßßßßßßß");
gotoxy (5,7);
printf("1)");
textcolor(0);
textbackground(14);
cprintf(" BS to AD ");
textbackground(15);
    //   textcolor(0);
	gotoxy(8,9);
	cprintf("        Ü");
	gotoxy(8,10);
	cprintf("ßßßßßßßßß");

 gotoxy (5,9);
printf("2)");
textbackground(14);
cprintf(" AD to BS");
textbackground(15);
       textcolor(0);
	gotoxy(8,11);
	cprintf("     Ü");
	gotoxy(8,12);
	cprintf("ßßßßßß");
gotoxy (5,11);
printf("3)");
textbackground(14);
cprintf(" Exit ");

textbackground(15);
}

void table()
{
for( int i=2;i<=75;i++)
{gotoxy(i+1,2);printf("Ä"); }
gotoxy(2,2); printf("Ú");
for( i=2;i<=23;i++)
{gotoxy(2,i+1);printf("³"); }
gotoxy(2,24); printf("À");
for( i=2;i<=75;i++)
{gotoxy(i+1,24);printf("Ä"); }
gotoxy(76,2
); printf("¿");
for( i=2;i<=23;i++)
{gotoxy(76,i+1);printf("³"); }
gotoxy(76,24); printf("Ù");

}
void display1()
{
table();
callmouse();
restrict(20,20,620,188);
}

void display2()
{//textbackground();
clrscr();
textcolor(0);
   //setbkcolor(BLUE);
 //  rectangle(20,30,620,433);
  // rectangle(22,32,622,435);

   restrict(20,20,620,188);

   getmouseposs(&b,&x,&y);

   menu();
   table();
   delay(10);
   callmouse();
   while(!kbhit())
   {

   getmouseposs(&b,&x,&y);
   if(b==1)
   {//gotoxy(30,3);
   // printf(" %d %d ",x,y);
    if(x>=36&&x<=119&&y>=50&&y<=54)
    {option=1;
    }
    else if(x>=35&&y>=64&&x<=119&&y<=69)
    {option=2;
     }
    else if(x>=33&&y>=75&&x<=88&&y<=86)
    {option=3;}
    else
    option=-1;
    hidemouse();
    switch(option)
    {
     case 1:bstoad();break;
     case 2:adtobs(); break;
     case 3:hidemouse(); Exit();
     default: callmouse(); break;
     }
     b=-1;
     }
   //delay(20);
 }
	char ch=getche();
	if(ch==27)
	{
	 hidemouse();
	 Exit();
	}
     //clrscr();
      //delay(20);
  }


long input(int x,int y)
{
/* long aa;
 int flag;
 char ch[30];
 again:
 textcolor(0);
 flag=1;
 gotoxy(x,y);
/* gets(ch);
 if(ch[0]==NULL)
 {
  flag=0;
 }
 for(int i=0;ch[i]!='\0';i++)
 {
  if(!isdigit(ch[i]))
  {
  flag=0;
  break;
  }
 }

 if(flag==0)
 {
  gotoxy(x,y);
  printf("                                            ");
 goto again;
 }
 aa=atol(ch); */
char ch;

start1:
textcolor(0);
gotoxy(x,y);
//ch=getche()-48;

long aa=0;
 do
{
textcolor(0);

       //	gotoxy(x,y);
	 ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		aa=aa*10+ch;
	}
	else if(ch == -40)      //back space
	{
		aa=aa/10;
		printf(" ");
		printf("\b") ;
	       if(aa == 0)
	       goto start1;
	}
	else if(ch == -35 || ch == -39)
	break;

	else if(ch == -21)     //esc
	{
	  display2();
	}
	else
	return(0);
}
while(1) ;





 return(aa);
}



void bstoad()
{
  clrscr();
  _setcursortype(_NORMALCURSOR);
  int y=0,m=0,d=0;
  char n;
  //cleardevice();
display1();
 hidemouse();
int sny=2050,snm=1,snd=1,sey=1993,sem=4,sed=13,i,j,k,totaldayscount=0,nepyear,nepmonth,nepday,nepdiff,months,iey,iem,ied,endday=0,l,day=1;
/*months of nepali year from 2000 to 2090*/
int nepdays[]={31,32,31,32,31,30,30,30,29,30,29,31,31,31,31,32,31,31,30,29,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,30,31,32,31,32,31,30,30,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,31,32,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,30,32,31,32,31,30,30,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,30,32,31,32,31,31,29,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,29,30,30,29,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,29,30,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,30,29,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,30};
int monthsofengyear[]={0,31,28,31,30,31,30,31,31,30,31,30,31 };/*months of english year*/
int monthsofengleapyear[]={0,31,29,31,30,31,30,31,31,30,31,30,31 };/*months of english leap year*/
//system("cls");/*stops overlapping of boxes while giving input in main menu*/
gotoxy(6,22);/* positioning time function at 6,22)*/
//time();
here1:
gotoxy(30,2);
textcolor(RED);
cprintf("BS to AD Converter");
/* displaying input info inside the rectangular box*/
gotoxy(6,5);
textcolor(BLUE);
cprintf("Enter the Nepali Date in BS:\n");
//leftrect();/* calling drawing function*/
textcolor(0);
gotoxy(6,8);
printf("\t Enter the Year: ");
gotoxy(6,8);
printf("\xb2\xb2");
gotoxy(26,8);   /*moving cursor to the input point*/
int r1;
r1=atoi(input1(4,1,26,8));
if(r1==0)
{
 display2();
}
//r1=input(26,8);
/*if(r1==0)
{
   textcolor(0);
    gotoxy(26,8); clreol();     table();
     goto here1;
} */
else
{
nepyear=r1;
//scanf("%d",&nepyear);
if(nepyear<2050||nepyear>2075)
{
	//system("cls");
    //	printf("\a\n\n\n\n\n\n\n\n\n\n\n\t*_* GIGO!!! THIS CONVERTER SUPPORTS THE YEAR FROM 2000 BS-2090 BS *_*\n");
    //	printf("\n\n\n\n\n\n\n\tStarting BS TO AD Converter in 5 seconds.....");
	//Sleep(5000);
      //	bstoad();
    textcolor(0);
    gotoxy(26,8); clreol();     table();
     goto here1;
}
}

 here2:
gotoxy(30,2);
textcolor(RED);
cprintf("BS to AD Converter");
/* displaying input info inside the rectangular box*/
gotoxy(6,5);
textcolor(BLUE);
cprintf("Enter the Nepali Date in BS:\n");
 textcolor(0);
gotoxy(6,10);
printf("\t Enter the Month: ");
gotoxy(6,10);
printf("\xb2\xb2");

gotoxy(27,10);

r1=atoi(input1(2,1,27,10));
if(r1==0)
{
 display2();
}
//scanf("%d",&nepmonth);
/*r1=input(27,10);
if(r1==0)
{

   textcolor(0);
    gotoxy(27,10); clreol();     table();
     goto here2;

} */
else
{
nepmonth=r1;
if(nepmonth<=0||nepmonth>=13)
{
	//system("cls");
       //	printf("\a\n\n\n\n\n\n\n\n\n\n\n\t*_* Sorry! There are only 12 months in a year *_*\n");
	//printf("\n\n\n\n\n\n\n\tStarting BS TO AD Converter in 5 seconds.....");
	//Sleep(5000);
       //	bstoad();
       textcolor(0);
      gotoxy(27,10);clreol(); table(); goto here2;
}
}

here3:
gotoxy(30,2);
textcolor(RED);
cprintf("BS to AD Converter");
/* displaying input info inside the rectangular box*/
gotoxy(6,5);
textcolor(BLUE);
cprintf("Enter the Nepali Date in BS:\n");

 textcolor(0);
gotoxy(6,12);
printf("\t Enter the Day: ");
gotoxy(6,12);
printf("\xb2\xb2");

gotoxy(26,12);
r1=atoi(input1(2,1,26,12));
if(r1==0)
{
 display2();
}


/*r1=input(26,12);
if(r1==0)
{

   textcolor(0);
    gotoxy(26,12); clreol();     table();
     goto here3;
} */
else
{
nepday=r1;
if(nepday<=0||nepday>=33)
{
	//system("cls");
	//printf("\a\n\n\n\n\n\n\n\n\n\n\n\t*_* Sorry! You have entered invalid number of days *_*\n");
	//printf("\n\n\n\n\n\n\n\tStarting BS TO AD Converter in 5 seconds.....");
	//Sleep(5000);
       //	bstoad();
      gotoxy(26,12);clreol();table();goto here3;
}
}
/*calculating the no of days between two nepali years*/
nepdiff=nepyear-sny;
if(nepdiff==0)/*when the entered day is equal to the starting limit of the array*/
{for(k=0;k<(nepmonth-1);k++)
{totaldayscount+=nepdays[k];
}
totaldayscount+=nepday-snd;
}
else
{
months=(nepdiff)*12;
for(i=0;i<months;i++)
{
	totaldayscount+=nepdays[i];


}
for(j=i;j<(i+(nepmonth-1));j++)/*here nepmonth is -1 because we need not to add complete month eg if it is ashar 20 the entire day of ashar is not added infact only days upto ashar 20 is added*/
{/*adding the remaining months to the totaldayscount*/
totaldayscount+=nepdays[j];
}
totaldayscount+=nepday-snd;/*here subtracting the snd bcoz it is already added at the beginning of the counting*/

}

/*FINDING EQUIVALENT ENGLISH DATE*/
iey=sey;/*assigning sey sem and sed to different variables because we need to alter the value of sey sem and sed in further programming*/
iem=sem;
ied=sed;
while(totaldayscount!=0)
{
	l=leap(iey);
	if(l==1)
	{
	endday=monthsofengleapyear[iem];}
	else
	{
	endday=monthsofengyear[iem];
	}

	ied++;
	day++;     /*day is initialized as 1*/
	if(ied>endday)
	{iem++;
	ied=1;                /*here dropping the value of ied to 1 because it is the start of new month and we count from 1*/
	if(iem>12)
	{iey++;
	iem=1;                 /* here dropping the value of iem to 1 because it is the start of new year and we start counting from 1 of first month*/
	}
	}
     day=ied;
		if(day>7)
		{day=1;
		}
	totaldayscount--;
}
gotoxy(44,5);
textcolor(BLUE);
cprintf("The Converted Date in AD:\n");
//printf("%dand %d",ied,day);
/* declaration of the day of week since the starting date is from wednesday we define 1 as wednesday*/
    textcolor(0);//rightrect();

    gotoxy(50,12);/* moving cursor behind the point where day is printed*/
    if(day==1)
	printf("\tWednesday");
	if(day==2)
	printf("\tThursday");
	if(day==3)
	printf("\tFriday");
	if(day==4)
	printf("\tSaturday");
	if(day==5)
	printf("\tSunday");
	if(day==6)
	printf("\tMonday");
	if(day==7)
	printf("\tTuesday");
	/* printing months in letters */
	gotoxy(50,10);
	if(iem==1)
	printf("\t January");
	if(iem==2)
	printf("\t February");
	if(iem==3)
	printf("\t March");
	if(iem==4)
	printf("\t April");
	if(iem==5)
	printf("\t May");
	if(iem==6)
	printf("\t June");
	if(iem==7)
	printf("\t July");
	if(iem==8)
	printf("\t August");
	if(iem==9)
	printf("\t September");
	if(iem==10)
	printf("\t October");
	if(iem==11)
	printf("\t November");
	if(iem==12)
	printf("\t December");
	gotoxy(43,8);
printf("\tYear:%d AD",iey);
gotoxy(43,8);
printf("\xb2\xb2");
gotoxy(43,10);
printf("\tMonth:%d,",iem);
gotoxy(43,10);
printf("\xb2\xb2");
gotoxy(43,12);
printf("\tDay:%d,",ied);
gotoxy(43,12);
printf("\xb2\xb2");
gotoxy(20,18);
printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
gotoxy(20,20);
loop1();/* intialing loop*/
getch();


 // clrscr();

  display2();
}



void adtobs(void)
{
 clrscr();
 _setcursortype(_NORMALCURSOR);
  int y=0,m=0,d=0;
  char n;
 // cleardevice();
display1();
 hidemouse();
		int sey=1993,sem=4,sed=13,engmonth,engyear,totaldayscount=0,months,k,engdiff,i,j,nepdiff,engday,sny=2050,snm=1,snd=1,iny,inm,ind,endday=0,var=1,day=0;

// data of english year's months arranged according to leap and not leap from 1993-2018 AD*/


int engdays[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31 };

//2050-2075
int nepdays[]={0,31,32,31,32,31,30,30,30,29,30,29,31,31,31,31,32,31,31,30,29,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,30,31,32,31,32,31,30,30,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,31,32,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,30,32,31,32,31,30,30,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,30,32,31,32,31,31,29,30,29,30,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,29,30,30,29,29,31,31,31,32,31,31,31,30,29,30,29,30,30,31,31,32,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,29,30,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,31,31,31,31,32,31,31,30,29,30,29,30,30,31,31,32,31,31,31,30,29,30,29,30,30,31,32,31,32,31,30,30,30,29,29,30,30};
gotoxy(6,22);

here1:
gotoxy(30,2);
textcolor(RED);
cprintf("AD to BS Converter");
gotoxy(6,5);
textcolor(BLUE);
cprintf("Enter the English Date in AD:");
gotoxy(6,8);
textcolor(0);
printf("\t Enter the year: ");
gotoxy(6,8);
printf("\xb2\xb2");
gotoxy(26,8);

int r1;
r1=atoi(input1(4,1,26,8));
if(r1==0)
{
 display2();
}


/*int r1=input(26,8);
if(r1==0)
{
   textcolor(0);
    gotoxy(26,8); clreol();     table();
     goto here1;
} */
else
{
engyear=r1;
if(engyear<1993||engyear>2018)
{
     gotoxy(26,8);clreol(); table(); goto here1;
      //	adtobs();
}
}
here2:

gotoxy(30,2);
textcolor(RED);
cprintf("AD to BS Converter");
gotoxy(6,5);
textcolor(BLUE);
cprintf("Enter the English Date in AD:");
 textcolor(0);
gotoxy(6,10);
printf("\t Enter the Month: ");
gotoxy(6,10);
printf("\xb2\xb2");

gotoxy(27,10);
r1=atoi(input1(2,1,27,10));
if(r1==0)
{
 display2();
}
/*r1=input(27,10);
if(r1==0)
{

   textcolor(0);
    gotoxy(27,10); clreol();     table();
     goto here2;
} */
else
{
engmonth=r1;
if(engmonth<=0||engmonth>=13)
{
       gotoxy(27,10);clreol();table(); goto here2;
    //	adtobs();
}
}

here3:
gotoxy(30,2);
textcolor(RED);
cprintf("AD to BS Converter");
gotoxy(6,5);
textcolor(BLUE);
cprintf("Enter the English Date in AD:");
 textcolor(0);
gotoxy(6,12);
printf("\t Enter the Day: ");
gotoxy(6,12);
printf("\xb2\xb2");

gotoxy(26,12);
r1=atoi(input1(2,1,26,12));
if(r1==0)
{
 display2();
}

/*r1=input(26,12);
if(r1==0)
{

   textcolor(0);
    gotoxy(26,12); clreol();     table();
     goto here3;

} */
else
{
engday=r1;
if(engday<=0||engday>=33)
{
       gotoxy(26,12);clreol(); table();goto here3;
    //	adtobs();
}

}
engdiff=engyear-sey;
if(engdiff==0)/*when the entered day is equal to the starting element of the array*/
{for(k=3;k<(engmonth-1);k++)/*here starting with bcoz we have starting month 4 */
{totaldayscount+=engdays[k];
}

totaldayscount+=engday-sed;
}

else
{
months=(engdiff)*12;
for(i=3;i<months;i++)/*here initializing i=3 because we have starting english month 4 */
{
	totaldayscount+=engdays[i];


}
for(j=i;j<(i+(engmonth-1));j++)/*here engmonth is -1 because we need not to add complete month eg if it is july 4 the entire day of july is not added infact only days upto july 4 is added*/
{/*adding the remaining months to the totaldayscount*/
totaldayscount+=engdays[j];
}
totaldayscount+=engday-sed;/*here subtracting the sed bcoz it is already added at the beginning of the counting*/

}

/*printf("the days count is :%d\n",totaldayscount);  delete it at the end of the program */
/*FINDING EQUIVALENT NEPALI YEARS*/

iny=sny;
inm=snm;
ind=snd;
while(totaldayscount!=0)
{
	endday=nepdays[var];

	ind++;
	day++;
	if(ind>endday)
	{var++;/* here we have used var to call the elements of array because at the end we have used inm=1 which may cause malfunction of the converter*/
	inm++;
	ind=1;
	if(inm>12)
	{iny++;

	inm=1;
	}
	}
		if(day>7)
		{day=1;
		}
	totaldayscount--;

}
gotoxy(43,5);
textcolor(BLUE);
cprintf("The Converterd Date in BS:");
textcolor(0);
gotoxy(52,12);
	if(day==1)
	printf("\t Budhabar");
	if(day==2)
	printf("\t Bihibar");
	if(day==3)
	printf("\t Sukrabar");
	if(day==4)
	printf("\t Sanibar");
	if(day==5)
	printf("\t Aeetabar");
	if(day==6)
	printf("\t Sombar");
	if(day==7)
	printf("\t Mangalbar");
	/*to print the months in alphabet*/
		gotoxy(52,10);
	if(inm==1)
	printf("\t  Baishak");
	if(inm==2)
	printf("\t  Jestha");
	if(inm==3)
	printf("\t  Ashar");
	if(inm==4)
	printf("\t  Shrawan");
	if(inm==5) 
	printf("\t  Bhadau");
	if(inm==6)
	printf("\t  Asoj");
	if(inm==7)
	printf("\t  Kartik");
	if(inm==8)
	printf("\t  Mangsir");
	if(inm==9)
	printf("\t  Poush");
	if(inm==10)
	printf("\t  Magh");
	if(inm==11)
	printf("\t  Falgun");
	if(inm==12)
	printf("\t  Chaitra");
gotoxy(43,8);
printf("\t Year: %d AD",iny);
gotoxy(43,8);
printf("\xb2\xb2");
gotoxy(43,10);
printf("\t Month:%d,",inm);
gotoxy(43,10);
printf("\xb2\xb2");
gotoxy(43,12);
printf("\t Day:%d,",ind);
gotoxy(43,12);
printf("\xb2\xb2");
gotoxy(20,18);
printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
gotoxy(20,20);
loop2();
getch();

//clrscr();
display2();

}





/*void Exit1()
{
alwaysdisplay();
} */

  void Exit()
  {
  int i;
  hidemouse();
  /*
   clrscr();
   hidemouse();
   //display1();
  // outtextxy(50,50,"EXITING IN\n ");
   for(i=1;i>=0;i--)
   {
   delay(1000);
    clrscr();
    hidemouse();
  //  cleardevice();
    //display1();
    printf("\n\n\n\tExiting in %d",i);
    display1();
   } */
   clrscr();
   main_page();
   end=0;
  }
 /* void main()
  {
    textbackground(1);
     clrscr();

   _setcursortype(_NOCURSOR);
  // Graphics();
   display2();
  // closegraph();
   getch();
  }*/