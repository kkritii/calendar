	      /************** PROGRAM STARTS **************/


#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "conv.h"
#include "mouse.h"
#include "note.h"
//#include<not.h>

typedef struct Holiday{
	int month;
	int day;
	char data[100];
}Holiday;

int countevents=0,countsat=0,sat=0;
int workdays;
char *days[]={"SUN","MON","TUE","WED","THR","FRI","SAT"};
char *month[]={"Jan","Feb","Mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec"};
char *month_name[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
//already defined in note.h
//int month_end[]={31,28,31,30,31,30,31,31,30,31,30,31};

int lastday,temp,endday,to;        //T=for zellers algorithm
long T,startday;                   //end day==month ko end;  //startday=kun din dekhi month start hunxa
int y1,m1;       //globle because this variable is shared by search() & button_months() & calender()
int count=1,notice_flag=0;     //to count no of files made

/******PREDEFINE FUNCTION***************
//union REGS in,out;
//struct dostime_t t1;          //get system time
//struct dosdate_t d1;         //get system date*/





/******************USER DEFINE FUNCTION***************/


void main__page();
//void main_page1();
void show_buttons();        //Only prints button such as Converter,Esc,reminder
void calender(int ,int);    //contains zellers and leap algorith and print dates
int color_holidays(int ,int ,int );  //colorize the holidays(argument to pass month,year,days)
void digital_clock_N_mouse();  //shows time and date(upper right) & mouse pointer
void button_months(); //if called then only keyboard months work
//void button_months1();
void search();  //search page
void outro_graphics();
void holidays(int,int);
void no();
void holiday_border();
void holiday_day(int,int);
void event_holidays(int,int);
void holiday_buttons();
void holiday_mouse();
void holiday_choice(int,int);
int main()
{
	clrscr();
	textcolor(0);
	textbackground(15);
	main_page();
	 return 0;
}




////////////////////////////////////////////////////////////
void main_page()          // 2nd page
{
clrscr();
hide_mouse();
window(0,0,80,25);

//***************ACTUAL CALENDER FOR CURRENT DATE************//
_dos_getdate(&d1);
m1=d1.month;
y1=d1.year;

restrict(10,0,620,188);
calender(y1,m1);        //sends system date at first

//****************** Check whether today's note is present or not********//
if(notice_flag==0)
notemessage();

//***************BUTTONS SUCH AS ESC REMINDER******************//
show_buttons();

//************** Digital clock and mouse function ***************\
digital_clock_N_mouse();

//*************** KEYBOARD BUTTONS KO KAM *********************
button_months();   //(should be called after digital_clock_N_mouse())
}

void notemessage()
{
_dos_getdate(&d1);
m1=d1.month;
y1=d1.year;
restrict(10,0,620,188);
fp=fopen("C:\\turboc3\\bin\\project\\note.txt","rb");
fread(&n,sizeof(n),1,fp);
int count=0;
while(!feof(fp))
{
	       if(n.year == d1.year && n.month == d1.month&&n.day==d1.day)
		{
		count++;
		gotoxy(24,22);
		textcolor(0);
		textbackground(3);
		cprintf("You have set reminders:%d for today",count);
		gotoxy(35,23);
		textattr(RED+128);
		textbackground(15);
		cprintf("press V to view");
		notice_flag=1;
	       //	break;
		}
		fread(&n,sizeof(n),1,fp);

}

fclose(fp);

}

/*
void main_page1()          // 2nd page
{
clrscr();
hide_mouse();
restrict(10,0,620,188);
//***************ACTUAL CALENDER FOR CURRENT DATE************

notemessage();
//***************BUTTONS SUCH AS ESC REMINDER******************



	show_buttons();
//************** Digital clock and mouse function ***************\
	digital_clock_N_mouse();
//*************** KEYBOARD BUTTONS KO KAM *********************
	button_months1();   //(should be called after digital_clock_N_mouse())
}
*/
///////////////////////////start of calender function/////////////////
void calender(int year1,int month1)
{
hide_mouse();  // this is must because it will replace dates
clrscr();
int len;
int count=0;
_dos_getdate(&d1);
to=0;
lastday=0;
gotoxy(3,3);
/*Because d1.year is not long int so we have to use long to calculate (year*365)*/
long year=year1;
int month=month1;

/***********************To print month,year*************/
gotoxy(35,3);
textbackground(15);
textcolor(0);
for(int i=month;i<=month;i++)
{
		cprintf("%s",month_name[i-1]);
}
cprintf(",%ld",year);

gotoxy(32,2);
cprintf("KHWOPA CALENDAR ");

/*Formula to find the day of 1st january only */
T=((year-1)*365) + ((year-1)/4) - ((year-1)/100) + ((year-1)/400) +1;
startday= T % 7;/* Here start day is the day in which jan 1st lies */

/*Formula to find leap year  */
month_end[1]=(!((year%4) || !(year % 100) && (year % 400)))? 29 : 28;


/*****************Program to check if leap year or not********
if(month_end[1]==28)
{
	printf("\n%d leap year",month_end[1]);
} */
/*****If the month is not first january ***************/

if(month>1)
{
      for(i=0;i<month-1;i++)
      {
	to=to+month_end[i];
      }
      lastday=to%7;
}
startday = startday+lastday;  //startday is the day in which the 1st day of any month except january lies

/*Note
if startday=0  then sunday
if startday=1  then monday
*/

/************* Program to check the above conditions  *****************
printf("The first day of this month starts from : ")  ;
for(i=0;i<7;i++)
{
	if(startday==i)
	{
		printf(" %s ",days[i]);
	}
	else
	{
		continue;
	}
}*/

endday=month_end[month-1] ;   //-1 beacuse in array the data is in n-1 pos
int l,yy=0,y=0,flag=0;         //for loop
float j;      // for determining vertical hight of date

//***************PRINT DATES*****************

for(l=1;l<=endday;l++)

{
	flag=color_holidays(year,month,l);
	fp=fopen("c:\\turboc3\\bin\\project\\note.txt","rb");
	fread(&n,sizeof(n),1,fp);
	while(!feof(fp))
	{

	if(l == n.day && month==n.month && year == n.year )
	{
		yy=1;
	}

  /*     if((n.year == d1.year && n.month == d1.month &&  n.day == d1.day) && (d1.year == year && d1.month ==  month && d1.day == l))
	{


	       //	len=strlen(n.data);
		textcolor(15);
		gotoxy(1,22);
		//cprintf("                                                                                  ");
	      //	textbackground(YELLOW);
	       //	count++;
		//textcolor(1);
	   //	gotoxy(40-(33/2),22);
	     //	cprintf("You have set a note for today%d ",count);
       }*/
       //note panixa satueday pani ho bhane
	if((startday == 6 || flag == 1) && (l == n.day && month==n.month && year == n.year ))
	{
		y=1;
	}


	fread(&n,sizeof(n),1,fp);
	}
	fclose(fp);


	if(startday>6)
	{
		startday =startday-7;
		j=j+1.50;            //j== horizontal line
	}
	if(startday==6)
	{
		textcolor(4);

	}

	else if(startday<6)
	{
		textcolor(0);
	}
	if(l==1)
	{
		j=0;
	}
//***********COLORS HOLIDAYS**********************
	color_holidays(year,month,l);



       //	fclose(fp);

//////////////////////////////////////////////////////

	gotoxy(19+7*startday,7+(2*j));

	if(yy==1)
	{textcolor(1);
	yy=0;
	}

	if(y==1)
	{
	textcolor(5);
	y=0;
	}


  //***********COLORS CURRENT DATE***********************
if(l==d1.day && month==d1.month  && year==d1.year)
	{
		textbackground(11);
	    //	textattr(YELLOW + BLU);
	}
	else
	{
		textbackground(15);
	}

      //highvideo();
	if(l <10)
	{
		cprintf("0");
	}
	cprintf("%d",l);
	startday++;
}
}
//********************end of calender function***********************//

int color_holidays(int year,int m,int l)  //l==days
{
	    if(year==2019)
	    {
		if(m == 1 && (l == 11 || l==15 || l== 30 ))
		    {textcolor(4);
		    return 1;}
		if(m == 2 && (l == 5 ))
		    {textcolor(4);return 1;}
		if(m == 3 && (l == 4 || l == 7 || l== 8))
		    {textcolor(4);
		     return 1;}
		if(m == 4 && (l == 5 || l == 14))
		    {textcolor(4); return 1;}
		if(m == 5 && (l == 1 || l == 18 || l == 29)  )
		    {textcolor(4); return 1;}
		//if(m == 6 && l == 5)
		  //  {textcolor(4); return 1;}
		if(m == 8 && ( l == 15 || l == 19 || l == 23))
		     {textcolor(4);return 1;}
		if(m == 9  && (l == 1 || l == 3 || l == 6 || l == 7 || l == 12 || l == 29))
		    {textcolor(4); return 1;}
		if(m == 10 && (l == 5 || l>=6 && l<=10 || l == 27 ||  l== 28 || l == 29))
		   {textcolor(4);  return 1;}
		if(m == 11 && (l== 2 || l == 12))
		   {textcolor(4);  return 1;}
		if(m == 12 && (l == 12 || l == 25 ))
		    {textcolor(4); return 1;}
	    }
}

void border()
{
	//******************** print border line


for(int i=1;i<80;i++)
{
	gotoxy(0+i,1);
	textcolor(0);
	cprintf("%c   ",205);   //upper line
      //	gotoxy(0+i,25);
       //	cprintf("%c",205);   //below line
}
for(i=1;i<25;i++)
{
	gotoxy(1,0+i);
	cprintf("%c",186);           //left line
	gotoxy(80,0+i);
	cprintf("%c",186);           //right line
}
gotoxy(1,1);
cprintf("%c",201);  //topleft corner
gotoxy(80,1);
cprintf("%c",187);   //topright corner
/*gotoxy(1,25);
cprintf("%c",200);  //bottomleft corner
gotoxy(80,24);
cprintf("%c",186);   //bottomright corner    */
}

void show_buttons()
{
border();
/*********** PRINT DAYS OF THE WEEK*********/
for(int i=0;i<7;i++)
{
	gotoxy(18+7*i,5);
	if(i==6)
	{
		textcolor(4);
	}
	else{
		textcolor(0);
	}
	textbackground(15);
	cprintf("%s",days[i]);
}
textcolor(0);
for(i=0;i<47;i++)
{
	gotoxy(17+i,6);
	cprintf("Ä");
}


/*
gotoxy(68,3);
textcolor(0);
textbackground(15);
cprintf("ÄÄÄÄÄÄÄÄÄÄÄ"); */    //between digital clock  and date

textcolor(0);
for(i=0;i<47;i++)             //between days and date */
{
	gotoxy(17+i,4);
	cprintf("Ä");
}
//**************Arrow keys*****************
gotoxy(15,2);
textbackground(15);
cprintf("%c",196);    //line
cprintf("%c",26);     //right

gotoxy(3,2);
cprintf("%c",196);
gotoxy(4,2);
cprintf("%c",196);
gotoxy(3,2);
cprintf("%c",27);    //left

//**************Search BUTTON+*************
textbackground(14);
gotoxy(6,2);
//textattr(15); //red
   //    textbackground(14);
   textcolor(15);
	cprintf(" S");
	textcolor(0);
	cprintf("earch ");

//***************Converter Button***********

gotoxy(5,24);
textcolor(15); //red

	cprintf(" C");
	textcolor(0);
	cprintf("onverter ");

//***************REMINDER BUTTON************
gotoxy(27,24);
	textcolor(15); //red
	cprintf(" H");
	textcolor(0);
	cprintf("olidays ");
 //***************HOLIDAYS BUTTON************
gotoxy(49,24);
	textcolor(15); //red
	cprintf(" N");
	textcolor(0);
	cprintf("otes ");


//***************EXIT BUTTON*****************
gotoxy(70,24);
	textcolor(15);
	cprintf(" E");
	textcolor(0);
	cprintf("sc ");

	textbackground(15);


	textbackground(15)     ; textcolor(3) ;
	gotoxy(14,2) ; cprintf("Ü") ;
	gotoxy(7,3)  ; cprintf("ßßßßßßßß")     ;

	gotoxy(16,24) ; cprintf("Ü") ;
	gotoxy(6,25)  ; cprintf("ßßßßßßßßßßß")     ;
	gotoxy(37,24) ; cprintf("Ü") ;
	gotoxy(28,25) ; cprintf("ßßßßßßßßßß")   ;
	gotoxy(56,24) ; cprintf("Ü") ;
	gotoxy(50,25) ; cprintf("ßßßßßßß")     ;
	gotoxy(75,24) ; cprintf("Ü") ;
	gotoxy(71,25) ; cprintf("ßßßßß")     ;


}

void digital_clock_N_mouse()
{
_dos_getdate(&d1);

//int m1=d1.month,y1=d1.year;
	start:
	int hr,min,sec;
	getmousepos(&button,&x,&y);
	while(!kbhit())
	{
	       _setcursortype(_NOCURSOR);
       //	show_mouse();
//********if struct time t*****************
       //	gettime(&t1);
       //	hr=t1.ti_hour;
       //	min=t1.ti_min;
       //	sec=t1.ti_sec;

//*********if struct dos_time***************
		_dos_gettime(&t1);
		hr=t1.hour;
		min=t1.minute;
		sec=t1.second;

		textcolor(0);
		textbackground(15);
	if(hr>12)
	{
		gotoxy(76,2);
		cprintf(" pm");
		hr=hr-12;
	}
	else if(hr==12)
	{
		gotoxy(76,2);
		cprintf("pm");
		hr=12;


	}
	else
	{
		gotoxy(76,2);
		cprintf(" am");
	}
	gotoxy(68,2);
	textbackground(15);
	if(hr<=9)
	cprintf("0%d:",hr);
	else
	cprintf("%d:",hr);
	if(min<=9)
	cprintf("0%d:",min);
	else
	cprintf("%d:",min);

////////////////////////////////////////////////

      if(sec<=9)      //remove shuttering in second
      {
	cprintf("0%d",sec);
      }
      else
      cprintf("%d",sec);
/*************** Mouse click **************************/

	show_mouse();
	getmousepos(&button,&x,&y);
	textcolor(0);
	textbackground(15);
 //	cprintf("Mouse button clicked: %d",button);
	if(button == 1)
	{
	  //	delay(20); //delay is must
		button=0;
		gotoxy(54,2);
	//	cprintf("( %d x %d)",x,y);
		if(x>=539 && x<=592 && y>=183 && y<=195) // 528*175 600*185
		{
			button=0;
			outro_graphics();
		}
		else if(x>=35 && x<=119 && y>=183 && y<=195)
		{
		 button=0;
		 hidemouse();
		 display2();
		}
		else if(x>=208 && x<=286 && y>=183 && y<=188)
		{
			button=0;
			hide_mouse();
			holidays(y1,m1);
		}
		else if(x>=389 && x<=439 && y>=183 && y<=188)
		{
		  button=-1;
		  hide_mouse();
		  note();
		}
		else if(x>=48 && x<=93 && y>=9 && y<=20)
		{
			textbackground(15);
			hide_mouse();
			search();
		}
		else if(x>=108 && x<=132 && y>=7 && y<=15)
		{
			delay(190);

		       m1=m1+1;
		       textbackground(15);
		       //cprintf("%d,%d",y1,m1);

			if(m1>12)
			{
				m1=m1-12;
				y1=y1+1;
			}
				calender(y1,m1);
				show_buttons();      //to print(search only)
			if(m1!=d1.month || y1!=d1.year)
			{
				gotoxy(65,24) ; cprintf("Ü") ;
				gotoxy(46,25) ; cprintf("ßßßßßßßßßßßßßßßßßßßß") ;
				gotoxy(45,24);
				textcolor(15);
				hide_mouse();
				textbackground(14);
				cprintf(" G");
				textcolor(0);
				cprintf("o to current date ");


			}
			show_mouse();
			goto start;
		}
	else if(x>=17 && x<=26 && y>=7 && y<=15)
		{
			delay(190);

		       m1=m1-1;
		       textbackground(15);
		       //cprintf("%d,%d",y1,m1);

			if(m1<1)
			{
				m1=m1+12;
				y1=y1-1;
			}
				calender(y1,m1);
				show_buttons();
			if(m1!=d1.month || y1!=d1.year)
			{

				gotoxy(65,24) ; cprintf("Ü") ;
				gotoxy(46,25) ; cprintf("ßßßßßßßßßßßßßßßßßßßß") ;
				gotoxy(45,24);
				textcolor(15);
				hide_mouse();
				textbackground(14);
				cprintf(" G");
				textcolor(0);
				cprintf("o to current date ");


			}
			show_mouse();
			goto start;
		}
		}
	else if(button ==3)
	{

		clrscr();
		printf("Intresting facts");
		getch();
		main_page();
	}
	}
}

void date()
{
	int sys_year;
	char sys_day;
	char sys_mth;
		_setcursortype(_NOCURSOR);
		 _dos_getdate(&d1);
		 sys_year = d1.year;
		 sys_mth = d1.month;
		 sys_day = d1.day;
		 gotoxy(68,1);
		 textcolor(0);
		 textbackground(14);
		 cprintf("%d-",sys_day);
	       //	 for(int i=sys_mth;i<=sys_mth;i++)
		// {

			cprintf("%s",month[sys_mth-1]);
		// }
		 cprintf("-%d  ",sys_year);

}

void button_months()
{
char ch;
int temp;
_dos_getdate(&d1);
start:
	ch=getch();
	if(ch==27 || ch=='e' || ch=='E')
	{      hide_mouse();
		exit(0);
	       //	outro_graphics();
	}
	else if(ch=='S' || ch=='s')
	{
		hide_mouse();
		textbackground(15);
		search();
	}
	else if(ch=='c'||ch=='C' && ch!=67)
	{
	textbackground(15);
	clrscr();
	hidemouse();
	display2();

	}
	else if(ch=='g' || ch=='G')
	{
		hide_mouse();
		textbackground(15) ;
		main_page();
	}
	else if(ch == 'N' || ch == 'n')
	{
		hide_mouse();
		note();
	}
	else if(ch == 'H' || ch == 'h')
	{
		hide_mouse();
		holidays(y1,m1);
//		main_page();
	}
	else if(ch == 'v' && notice_flag == 1)
	{
	    no();
	    notice_flag=2;
	}
	else if(ch == 77 )      //77==right 72==up 75==left
	{       // printf("  %d",ch);
		textbackground(15);
		m1=m1+1;
		if(m1>12)
		{
			m1=m1-12;
			y1=y1+1;
		}
		calender(y1,m1);
		show_buttons();
		if(m1!=d1.month || y1!=d1.year)
		{

				gotoxy(65,24) ; cprintf("Ü") ;
				gotoxy(46,25) ; cprintf("ßßßßßßßßßßßßßßßßßßßß") ;
				gotoxy(45,24);
				textcolor(15);
				hide_mouse();
				textbackground(14);
				cprintf(" G");
				textcolor(0);
				cprintf("o to current date ");

		}
		show_mouse();
		digital_clock_N_mouse();
		goto start;
	}
	else if(ch == 75)
	{
		textbackground(15);
		m1=m1-1;
		if(m1<1)
		{
			m1=m1+12;
			y1=y1-1;
		}

		calender(y1,m1);
		//notemessage();
		show_buttons();
		if(m1!=d1.month || y1!=d1.year)
		{
			gotoxy(65,24) ; cprintf("Ü") ;
			gotoxy(46,25) ; cprintf("ßßßßßßßßßßßßßßßßßßßß") ;
			gotoxy(45,24);
			textcolor(15);
			hide_mouse();
			textbackground(14);
			cprintf(" G");
			textcolor(0);
			cprintf("o to current date ");
		}
		show_mouse();
		digital_clock_N_mouse();
		goto start;
	}
/***********************F1 F2 F3 ......F12************************/
      else if(ch >= 59 && ch<=68 && ch!='D')   //100 ==d   //68=D
	{
		textbackground(15);
		clrscr();
		temp=ch;
		temp=temp-58;
		//printf("%d",test);
	       calender(d1.year,temp);
	       ch=getch();
	       if(ch>=59 && ch<=68)
	       {
		goto start;
	       }
	       else
	       {
		main_page();
	       }
	}
	else if(ch == (-123))
	{
		textbackground(15);
		calender(d1.year,11);
		goto start;
	}
	else if(ch == (-122))
	{
		textbackground(15);
		calender(d1.year,12);
		goto start ;
	}
/////////////////////////////////////////////////////////////
	else
	{
		goto start;
	}
}

/*
void button_months1()
{
char ch;
int temp;
_dos_getdate(&d1);
//m1=d1.month;
//y1=d1.year;
start:
	ch=getch();
	if(ch==27 || ch=='e' || ch=='E')
	{      hide_mouse();
		exit(0);
	       //	outro_graphics();
	}
	else if(ch=='v'||ch=='V')
	{
	   hide_mouse();
	   textbackground(15);
	   no();
	}
	else if(ch=='S' || ch=='s')
	{
		hide_mouse();
		textbackground(15);
		search();
	}
	else if(ch=='c'||ch=='C' && ch!=67)
	{
	textbackground(15);
	clrscr();
	hidemouse();
	display2();

	}
	else if(ch=='g' || ch=='G')
	{
		hide_mouse();
		textbackground(15) ;
		main_page();
	}
	else if(ch == 'N' || ch == 'n')
	{
		hide_mouse();
		button=0 ;
		note();
	}
		else if(ch == 'H' || ch == 'h')
	{
		hide_mouse();
		holidays(y1,m1);
	}
	else if(ch == 77 )      //77==right 72==up 75==left
	{
		textbackground(15);
		m1=m1+1;
		if(m1>12)
		{
			m1=m1-12;
			y1=y1+1;
		}
		calender(y1,m1);
		//notemessage();
		show_buttons();
		if(m1!=d1.month || y1!=d1.year)
		{
			gotoxy(65,24) ; cprintf("Ü") ;
			gotoxy(46,25) ; cprintf("ßßßßßßßßßßßßßßßßßßßß") ;
			gotoxy(45,24);
			textcolor(15);
			hide_mouse();
			textbackground(14);
			cprintf(" G");
			textcolor(0);
			cprintf("o to current date ");
		}
		show_mouse();
		digital_clock_N_mouse();
		goto start;
	}
	else if(ch == 75)
	{
		textbackground(15);
		m1=m1-1;
		if(m1<1)
		{
			m1=m1+12;
			y1=y1-1;
		}

		calender(y1,m1);
	       //	notemessage();
		show_buttons();
		if(m1!=d1.month || y1!=d1.year)
		{
			gotoxy(65,24) ; cprintf("Ü") ;
			gotoxy(46,25) ; cprintf("ßßßßßßßßßßßßßßßßßßßß") ;
			gotoxy(45,24);
			textcolor(15);
			hide_mouse();
			textbackground(14);
			cprintf(" G");
			textcolor(0);
			cprintf("o to current date ");
		}
		show_mouse();
		digital_clock_N_mouse();
		goto start;
	}
/***********************F1 F2 F3 ......F12************************
	else if(ch >= 59 && ch<=68)
	{
	textbackground(15);
		clrscr();
		temp=ch;
		a:
		temp=temp-58;
		//printf("%d",test);
	       calender(d1.year,temp);
	       ch=getch();
	       if(ch>=59 && ch<=68)
	       {
		goto start;
	       }
	       else
	       {
		main_page();
	       }
	}
	else if(ch == (-123))
	{
		textbackground(15);
		calender(d1.year,11);
		goto start;
	}
	else if(ch == (-122))
	{
		textbackground(15);
		calender(d1.year,12);
		goto start ;
	}
/////////////////////////////////////////////////////////////
	else
	{
		goto start;
	}
}
*/
void search()
{
char ch;
//load_graphics();
clrscr();
hide_mouse();
//show_mouse();
_dos_getdate(&d1);
//int year1,month1;
/*****************Print Box in search screen***************/
textcolor(15);
for(int i=1;i<35;i++)
{
	gotoxy(23+i,8);
	textcolor(4);
	cprintf("%c   ",205);   //upper line
	gotoxy(23+i,16);
	cprintf("%c",205);   //below line
}
for(i=1;i<8;i++)
{
	gotoxy(23,8+i);
	cprintf("%c",186);           //left line
	gotoxy(58,8+i);
	cprintf("%c",186);           //right line
}
gotoxy(23,8);
cprintf("%c",201);  //topleft corner
gotoxy(58,8);
cprintf("%c",187);   //topright corner
gotoxy(23,16);
cprintf("%c",200);  //bottomleft corner
gotoxy(58,16);
cprintf("%c",188);   //bottomright corner
//////////
////////////////////End of box print ///////////////////

again1:
 y1=0;
textcolor(0);
gotoxy(30,11); clreol(); border();
gotoxy(30,11);
cprintf("Enter Year  : ");
gotoxy(30,13);
cprintf("Enter Month : ");
textcolor(4);
gotoxy(58,11);
cprintf("%c",186);
textcolor(0);
gotoxy(45,11);
_setcursortype(_NORMALCURSOR);
/*do
{
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		y1=y1*10+ch;
	}
	else if(ch == -40)      //back space
	{
		y1=y1/10;
		printf(" ");
		printf("\b") ;
		if(y1 == 0)
			goto again1;
	}

	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
	  main_page();
	}
	else
	 goto again1;
}
while(1) ; */

int r1;
r1=atoi(input1(4,1,45,11));
if(r1==0)
{
 main_page();
}
else
{
 y1=r1;
}

if(y1<=1999 || y1>=2031)
{
	goto again1;
}
again2:
m1=0;
textcolor(0);
gotoxy(30,13);clreol();
border();
//gotoxy(25,10);
gotoxy(30,13);
cprintf("Enter Month : ");
textcolor(4);
gotoxy(58,13);
cprintf("%c",186);
textcolor(15);
gotoxy(45,13);
_setcursortype(_NORMALCURSOR);

r1=atoi(input1(2,1,45,13));
if(r1==0)
{
 main_page();
}
else
{
m1=r1;
}


//m1=input(45,13);
/*do
{
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		m1=m1*10+ch;
	}
	else if(ch == -40)      //back space
	{
		m1=m1/10;
		printf(" ");
		printf("\b") ;
		if(m1 == 0)
		 goto again2;
	}
	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
	  main_page();
	}
	else
	 goto again2;
}
while(1) ;
*/
if(m1<=0 || m1>=13)
{
	goto again2;
}
	calender(y1,m1);
	show_buttons();
	gotoxy(43,24) ; cprintf("Ü") ;
	gotoxy(25,25) ; cprintf("ßßßßßßßßßßßßßßßßßßß") ;
	gotoxy(24,24);
	textcolor(15);
	hide_mouse();
	textbackground(14);
	cprintf(" G");
	textcolor(0);
	cprintf("o to current date");
	digital_clock_N_mouse();
	button_months();
}


void holidays(int year,int choice)
{/*int i, y_count = 9;char chh; char a;

	FILE *fp = fopen("HOLIDAYS.DAT", "rb");
	Holiday holiday;

	textcolor(0);
	if (y==2019){
		clrscr();
		border();
		/************ ESC BUTTON**********************/
	      /*	gotoxy(65,24);
		textcolor(4);
		cprintf("E");
		textcolor(0);
		cprintf("sc(holidays)");
		textcolor(0);

		gotoxy(7, 2);
		cprintf("The holidays for this month are on:");

		while(fread(&holiday, sizeof(Holiday), 1, fp) != 0){
			if(holiday.month == choice){
				textcolor(RED);
				gotoxy(7, y_count);
				cprintf("%d-%d: %s", holiday.day, holiday.month, holiday.data);
				y_count+=2;
			} */

int i;char chh; char a;
int y_count = 6,yy_count=6;
//char chh; char a;

	FILE *fp = fopen("c:\\turboc3\\bin\\project\\HOLIDAYS.DAT", "rb");
	Holiday holiday;

textcolor(0);
//long int year1=year;
//int choice1=choice;
if (year==2019)
{
clrscr();
//border();
holiday_border();
holiday_buttons();
 textcolor(RED);
 gotoxy(25,3);
cprintf("HOLIDAYS OF THE MONTH(%s) ARE",month_name[(choice-1)]);
while(fread(&holiday, sizeof(Holiday), 1, fp) != 0)
  {
		      if(holiday.month == choice)
			{
				textcolor(RED);
				  if(y_count>14)
				{ gotoxy(50,yy_count);
				cprintf("%d-%d:", holiday.month, holiday.day);
				printf("%s",holiday.data);
				yy_count+=2;
					y_count+=2;
					}
					else
					{
				gotoxy(7, y_count);
				cprintf("%d-%d:", holiday.month, holiday.day);
				printf("%s",holiday.data);
				y_count+=2; }

			}  }
if(choice == 7 || choice == 6)
 {gotoxy(7,6);
  printf("No events and holidays.");
	 }


  			  holiday_day(year,choice);
gotoxy(7,18);printf(" No. of working days: %d",workdays);
 gotoxy(8,20);printf("No. of holidays:%d",countsat+countevents);
 gotoxy(8,22); printf("No. of events:%d",countevents); countsat=0; countevents=0;

fclose(fp);

//holiday_choice(year,choice);
//  hide_mouse();
//char ch;
//int v=0;
_setcursortype(_NOCURSOR);
textcolor(0);
getmouseposs(&button,&x,&y);
//delay(10);
show_mouse();
//start:
while(!kbhit())
{
  show_mouse();
  getmouseposs(&button,&x,&y);
	gotoxy(10,1);
   //   printf("  %dx %d     ",x,y);

  if(button == 1)
  {
	button=0;
	hide_mouse();
	gotoxy(10,1);
    //printf("%dx %d",x,y);
   if(x>=10 && y>=16 && x<=42 && y<=22)
   { //clrscr();
     // if(year==2019 && (choice<=12 ||month>=1)
	choice=choice-1;
		if(choice<1)
		{
			choice=choice+12;
			year=year-1;
		}
	       /*	  gotoxy(20,1);
		cprintf("%d-%d",choice,year);
		getch();  */
	   delay(500);
       holidays(year,choice);
   //exit(0);
   }
   else if(x>=585 && y>=17 && x<=620 && y<=22)
   {
  // cprintf("g");
   button=0;
   hide_mouse();
   choice=choice+1;
		if(choice>12)
		{
			choice=choice-12;
			year=year+1;
		}

	  /*	gotoxy(20,1);
		cprintf("%d-%d",choice,year);
		getch();  */
	delay(500);
      holidays(year,choice);
     // main_page();
   }
   else if(x>=514 && y>=187 && x<=613 && y<=188)
   { // delay(2000);
   button=0;
      hidemouse();
      delay(100);
      main_page();
   }
  // else
  // { holidays(year1,month1);
  // }
   }
   else if(button ==2)
   { button=0;
     holidays(year,choice);
     }
}

char chhh=getch();
start:
 if(chhh=='e' || chhh == 'E' || chhh == 27)
  { main_page();}
   else if(chhh == 77 )      //77==right 72==up 75==left
	{
	      printf("  %d",chhh);
	       //	textbackground(15);
		choice=choice+1;
		if(choice>12)
		{
			choice=choice-12;
			year=year+1;
		}
		holidays(year,choice);

	       //	show_mouse();
		goto start;
	}
	else if(chhh == 75)
	{
	       //	textbackground(15);
		choice=choice-1;
		if(choice<1)
		{
			choice=choice+12;
			year=year-1;
		}

		holidays(year,choice);
		//notemessage();
	      goto start;
	}
 else
  { holidays(year,choice);
  goto start; }

}
else
{
if(year<2019)
{
clrscr();
gotoxy(10,20);
cprintf("NO DATA AVAILABLE FOR PREVIOUS YEARS");
delay(2000);
main_page();
}
else
{
clrscr();
gotoxy(10,20);
cprintf("COMING SOON.....");
delay(2000);
main_page();
}
}
}



void outro_graphics()                         //3rd page
{

	int x,y,z,i=2,j;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");		  //increase value of i to inscrease no of * while exiting
	char str[5],ch ;
	hide_mouse();
	show_mouse();
	x=getmaxx();
	y=getmaxy();
	z=(x/2-45) ;
	here:
	setbkcolor(BLUE);
	rectangle(1,1,x,y);
	rectangle(2,2,x-1,y-1);
	rectangle(9,9,x-9,y-9);
	settextstyle(2,0,7);
	outtextxy(x/2-150,y/2-20,"Prepared By :");
	settextstyle(2,0,5);
	setcolor(14);
	outtextxy(x/2-150,y/2+20,"Aman Mool");
	outtextxy(x/2-150,y/2+40,"Arun Prajapati");
	outtextxy(x/2-150,y/2+60,"Kriti Prajapati");
	outtextxy(x/2-150,y/2+80,"Manisha Gora");
	outtextxy(x/2-100,y-50,"Exiting");
	delay(700);
	//setbkcolor(RED);
		/*Print the exiting animation */
	for(j=1;j<70;j=j+10)
	{
			setcolor(i);
			outtextxy(z+j,y-50,"*");
			i++;
			delay(500);
	}
      exit(0);


}
void holiday_border()
{
for(int i=0;i<80;i++)
{
	gotoxy(1+i,4);
	cprintf("Ä");
	gotoxy(1+i,2);
	cprintf("Ä");

}

for(i=21 ;i<55;i++)
{
	gotoxy(i,2);
	cprintf("Ä");
}
for(i=0 ;i<80;i++)
{
	gotoxy(i,23);
	cprintf("Ä");
}
for(i=0 ;i<80;i++)
{
	gotoxy(i,17);
	cprintf("Ä");
}
 }
 void holiday_day(int year,int month)
 {int to=0;
 int lastday=0;
 T=((year-1)*365) + ((year-1)/4) - ((year-1)/100) + ((year-1)/400) +1;
startday= T % 7;/* Here start day is the day in which jan 1st lies */

/*Formula to find leap year1  */
month_end[1]=(!((year%4) || !(year % 100) && (year % 400)))? 29 : 28;
		  if(month>1)
{
      for(int i=0;i<month-1;i++)
      {
	to=to+month_end[i];
      }
      lastday=to%7;
}
startday = startday+lastday;  //startday is the day in which the 1st day of any month1 except january lies
endday=month_end[month-1] ; //-1 beacuse in array the data is in n-1 pos
int l;
for(l=1;l<=endday;l++)

{           if(startday>6)
	{
		startday =startday-7;
	}
	if(startday==6)
	{
		     countsat++;

	}
	else if(startday<6)
	{

	}


 startday++;
}
event_holidays( year,month);
workdays=endday-(countsat+countevents);
}
void event_holidays(int year,int m)  //l==days
{
	    if(year==2019)
	    {  endday=month_end[m-1] ;   //-1 beacuse in array the data is in n-1 pos
	   int l;
	     for(l=1;l<=endday;l++)
	      {	if(m == 1 && (l == 11 || l==15 || l== 30 ))
		    {
		    countevents++;
		    }
		if(m == 2 && (l == 5 ))
		    {countevents++;}
		if(m == 3 && (l == 4 || l == 7 || l== 8))
		    {
		    countevents++;}
		if(m == 4 && (l == 5 || l == 14 ))
		    { countevents++;}
		if(m == 5 && (l == 1 || l == 18 || l == 29)  )
		    { countevents++;}
	      //	if(m == 6 && l == 5)
		//    { countevents++;}
		if(m == 8 && (l == 12 || l == 15 || l == 19 || l == 23))
		     {countevents++;}
		if(m == 9  && (l == 1 || l == 3 || l == 6 || l == 7 || l == 12 || l == 29))
		    { countevents++;}
		if(m == 10 && (l == 5 || l>=6 && l<=10  || l == 27 ||  l== 28 || l == 29))
		   {  countevents++;}
		if(m == 11 && (l== 2 || l == 12))
		   {  countevents++;}
		if(m == 12 && (l == 12 || l == 25 ))
		    { countevents++;}
	    }
}
}
void holiday_buttons()
{

/*************CALLS DATE**********************/
/*gotoxy(62,1);
textcolor(0);
cprintf("Date: ") ;

date();
/************ ESC BUTTON**********************/
	gotoxy(65,24);
	textcolor(4);
	cprintf("E");
	textcolor(0);
	cprintf("sc(holidays)");
	textcolor(0);

	gotoxy(1,3);
       cprintf("<-");
	textcolor(0);
	cprintf("Prev");
	gotoxy(74,3);
       cprintf("next");
	textcolor(0);
	cprintf("->");

}
