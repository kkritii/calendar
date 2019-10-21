/*              NOTE        */
//char *input1(int,int);
void update();
void note();
void add_note();
void all_note();
void note_buttons();
void extend_current();
void extend_all();
void note_choices();
void current_note();
void delete_note();
void delete_end();
void no();
void border();
void notemessage();
void date();     //prints date (it is called inside digital_clock function)

int note_flag=0,note_flag1=0;
int month_end[]={31,28,31,30,31,30,31,31,30,31,30,31};

struct dostime_t t1;          //get system time
struct dosdate_t d1;         //get system date


struct note
{
	int year;
	int month;
	long tag;
	int day;
	char data[100];
};
struct note n;
FILE *fp,*fpo,*fpt;

void gt(int x,int y)
{
gotoxy(x,y);
}

void tc(int x)
{
textcolor(x);
}


/*char *input(int limit,int c)
{
 char result[50]=" ";
 char ch;
 int i=0;
 int j=0;
 int index=0;
 do
 {
ch=getch();
if(index<limit)
{
if(isalpha(ch)||ch==' ')
{
 result[index++]=ch;
 if(index<15)
 {
  gotoxy(22+i,15);
  cprintf("%c",ch);
  i++;
 }
 else
 {
  gotoxy(22+j,16);
  cprintf("%c",ch);
  j++;
 }
}
}
if(ch==8&&index>0)
{
 result[index--]=NULL;
 printf("\b \b");
 }
}
while((ch!=13||index<1)&&ch!=27);
result[index]=0;
return ch==27 ? "00" : result;
}
  */
/*char *input1(int limit,int c)
{
char result[50]="";
char ch;
int i=0;
int j=0;
int index=0;
do{
textcolor(0);
ch=getch();
if(index<limit)
{
if(isalpha(ch)||ch==' ')
{
 result[index++]=ch;
 if(index<40)
 {
 gotoxy(22+i,15);
 cprintf("%c",ch);
 i++;
 }
 else
 {
 gotoxy(22+j,16);
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
/* if(index<40)
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
 gotoxy(22+i,15);
/* i--;
 if(j>0)
 j--;
 if(index==40)
 gotoxy(22+i,15);

 printf("\b \b");
 if(index==1)
  {i=0;j=0; }    */
/*}
}
while((ch!=13||index<1)&&ch!=27);
result[index]=0;
return ch==27?"00":result;

} */



void no()
{
clrscr();
int v=0;
 char ch;
_dos_getdate(&d1);
textcolor(0);
gotoxy(24,1);
//cprintf("** Notes of current month **");
fp=fopen("C:\\turboc3\\bin\\project\\note.txt","rb")  ;
fread(&n,sizeof(n),1,fp);
while(!feof(fp))
{
if(n.year == d1.year && n.month == d1.month&&n.day==d1.day)
{
_setcursortype(_NOCURSOR);
gotoxy(24,1);
	textcolor(RED);
	textbackground(15);
cprintf("** Notes Set For Today **");
gotoxy(3,3);
textcolor(BLUE);
cprintf("SN.");
gotoxy(10,3);
textcolor(BLUE);
cprintf("Date");
gotoxy(30,3);
textcolor(BLUE);
cprintf("Notes");
textcolor(0);
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
  gotoxy(65,1);
	textbackground(15);
//cprintf("Date: ") ;
date();

	  gotoxy(3,5+v) ;
			textbackground(15);
		cprintf("%d",v+1);
		gotoxy(10,5+v);
			textbackground(15);
		cprintf("%d-%d-%d",n.year,n.month,n.day);
		gotoxy(30,5+v);
		cprintf("%s",n.data);
		v++;
		gotoxy(60,22);
		textattr(RED+128);
		textbackground(15);
	       cprintf("press x to exit");

}

		fread(&n,sizeof(n),1,fp);

}

fclose(fp);

ch=getch();
if(ch=='x')
{
clrscr();
main_page();
}
else
{
 no();
}
}



void note_buttons()
{
	gotoxy(3,3);
cprintf("SN.");
gotoxy(10,3);
cprintf("Date");
gotoxy(25,3);
cprintf("TAG");

gotoxy(40,3);
cprintf("Notes");
textcolor(0);
int i;
for( i=0;i<80;i++)
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

gotoxy(33,2);
printf("Â");
for(i=0;i<20;i++)
{ textcolor(0);
if(i==1)
{
gotoxy(33,3+i);
cprintf("Å");
}
else
{
 gotoxy(33,3+i);
 cprintf("³");
}
}

gotoxy(20,2);
printf("Â");
for(i=0;i<20;i++)
{ textcolor(0);
 if(i==1)
{
gotoxy(20,3+i);
cprintf("Å");
 }
 else
 {
gotoxy(20,3+i);
cprintf("³");
 }
 }

gotoxy(20,23);
cprintf("Á");

  gotoxy(7,23);
 cprintf("Á");

  gotoxy(33,23);
 cprintf("Á");

 gotoxy(7,2);
printf("Â");
for(i=0;i<20;i++)
{ textcolor(0);
 if(i==1)
{
gotoxy(7,3+i);
cprintf("Å");
 }
 else
 {
gotoxy(7,3+i);
cprintf("³");
 }
 }

/*************CALLS DATE**********************/
gotoxy(62,1);
textbackground(14);
cprintf("Date: ") ;

date();
textbackground(14);
/************ ADD NOTE BUTTON ********************/
	gotoxy(4,24);
	textcolor(15);
	cprintf(" A");
	textcolor(0);
	cprintf("dd Note ");
/************ DELETE NOTE BUTTON ******************/
	gotoxy(19,24);
	textcolor(15);
	cprintf(" D");
	textcolor(0);
	cprintf("elete Note ");

	gotoxy(35,24);
	textcolor(15);
	cprintf(" M");
	textcolor(0);
	cprintf("odify Note ");

/************* ALL note button ********************/
	gotoxy(50,24);
	textcolor(15);
	cprintf(" C");
	textcolor(0);
	cprintf("urrent Notes ");
/************ ESC BUTTON**********************/
	gotoxy(66,24);
	textcolor(15);
	cprintf(" Q");
	textcolor(0);
	cprintf("=All Notes ");

       //	textbackground(14);
	gotoxy(1,1);
	cprintf("%c",27);
	textcolor(15);
	cprintf(" B");
	textcolor(0);
	cprintf("ack");
	cprintf(" º                    ");

	textbackground(15)     ; textcolor(8) ;
	gotoxy(14,24) ; cprintf("Ü") ;
	gotoxy(5,25)  ; cprintf("ßßßßßßßßßß")     ;
	gotoxy(32,24) ; cprintf("Ü") ;
	gotoxy(20,25) ; cprintf("ßßßßßßßßßßßßß")   ;
	gotoxy(47,24) ; cprintf("Ü") ;
	gotoxy(36,25) ; cprintf("ßßßßßßßßßßßß") ;
	gotoxy(64,24) ; cprintf("Ü") ;
	gotoxy(52,25) ; cprintf("ßßßßßßßßßßßßß")     ;
	gotoxy(79,24) ; cprintf("Ü") ;
	gotoxy(67,25) ; cprintf("ßßßßßßßßßßßßß")     ;

}

void note()
{
hide_mouse();
//char ch;
int v=0;
_setcursortype(_NOCURSOR);
clrscr();
textcolor(0);
textbackground(15);
/********************FIRST DISPLAY CURRENT MONTH NOTE********/
current_note();
textcolor(0);
getmouseposs(&button,&x,&y);
//delay(10);
//show_mouse();
start:
while(!kbhit())
{
  show_mouse();
  getmouseposs(&button,&x,&y);
  if(button == 1)
  {
	button=0;
	gotoxy(10,1);
 // printf("%dx %d",x,y);
   if(x>=24 && y>=183 && x<=104 && y<=188)
   {
    add_note();
   }
   else if(x>=149 && y>=183 && x<=245 && y<=188)
   {
    hide_mouse();
    delete_note();
   }
  else if(x>=275 && y>=183 && x<=371 && y<=188)
   {
    update();
   }
   else if(x>=522 && y>=183 && x<=619 && y<=188)
   {
      all_note();
   }
   else if(x>=392 && y>=183 && x<=502 && y<=188)
   {
	hide_mouse();
	current_note();
   }
   else if(x>=10 && y>=0 && x<=53 && y<=9)
   {
	hide_mouse();
	 main_page();
   }
  /* option=-1;
   hidemouse();
   switch(option)
   {
    case 1: hidemouse();  add_note(); note(); break;
    case 2:  hide_mouse(); delete_note(); hide_mouse();  note(); break;
    case 3:  hide_mouse(); update();  delay(100); note(); break;
    case 4:  delay(100); all_note(); break;
    case 5:  hide_mouse(); delay(100); note(); break;
    case 6:  hide_mouse(); delay(200); main_page(); end=0; break;
    default: callmouse(); break;
   }
   b=-1; */
  }
  else if(button ==2) {
  button=0;
   note();
  }
}
char ch;
//start:
ch=getch();
	if(ch == 'A' || ch == 'a')
	{
		hide_mouse();
		add_note();
	}
	else if(ch=='d')
	{
	 hide_mouse();
	 delete_note();
	}
	else if(ch == 'D')
	{
		delete_end();
	}
	else if(ch == 'm')// || ch == 'M')
	{
		hide_mouse();
		update();
		all_note();
	}
	else if(ch == 27 || ch == 'b')
	{
		clrscr();
		hide_mouse();
		main_page();
	}
	else if(ch == 'c' || ch == 'C')
	{
	       //	hide_mouse();
		current_note();
		goto start;
	}
	else if(ch == 'q' || ch=='Q')
	{
		all_note();
		goto start;
	}
	else if((ch == 77) && note_flag == 1 && ch!='m')
	{
		clrscr();
		 extend_current();
		 goto start;
	}
	//extend();
	else if(ch == 75 && note_flag == 2)
	{
		note();
		goto start;
	}
	else if((ch == 77) && note_flag1 == 1)
	{
		 clrscr();
		 extend_all();
		 goto start;
	}
		//extend();
	else if(ch == 75 && note_flag1 == 2)
	{
		all_note();
		goto start;
	}
	else
	{
	       //	hide_mouse();
		goto start;
	}

//note_choices();

//start:
textcolor(0);

}

void note_choices()
{
char ch;
start:
ch=getch();
	if(ch == 'A' || ch == 'a')
	{
		hide_mouse();
		add_note();
	}
	else if(ch=='d')
	{
	 hide_mouse();
	 delete_note();
	}
	else if(ch == 'D')
	{
		delete_end();
	}
	else if(ch == 'm')// || ch == 'M')
	{
		hide_mouse();
		update();
		all_note();
	}
	else if(ch == 27 || ch == 'b')
	{
		clrscr();
		hide_mouse();
		main_page();
	}
	else if(ch == 'c' || ch == 'C')
	{
	       //	hide_mouse();
		current_note();
		goto start;
	}
	else if(ch == 'q' || ch=='Q')
	{
		all_note();
		goto start;
	}
	else if((ch == 77) && note_flag == 1 && ch!='m')
	{
		clrscr();
		 extend_current();
		 goto start;
	}
	//extend();
	else if(ch == 75 && note_flag == 2)
	{
		note();
		goto start;
	}
	else if((ch == 77) && note_flag1 == 1)
	{
		 clrscr();
		 extend_all();
		 goto start;
	}
		//extend();
	else if(ch == 75 && note_flag1 == 2)
	{
		all_note();
		goto start;
	}
	else
	{
	       //	hide_mouse();
		goto start;
	}

}

void extend_current()
{
note_flag=2;
int v=0;
note_buttons();
textcolor(0);
gt(66,3);
cprintf("2 of 2");

gotoxy(24,1);
textbackground(14);
cprintf("** Notes of current month **          ");  // º
textbackground(14);
gt(73,3);
cprintf(" <-- ");
textbackground(15);
fp=fopen("C:\\turboc3\\bin\\project\\temp1.txt","rb")  ;
fread(&n,sizeof(n),1,fp);
while(!feof(fp))
{
textcolor(0);
	gotoxy(3,5+v) ;
		cprintf("%d",v+1+18);
		gotoxy(10,5+v);
		cprintf("%d-%d-%d",n.year,n.month,n.day);
		gotoxy(25,5+v);
		cprintf("%ld",n.tag);
		 gotoxy(35,5+v);
		cprintf("%s",n.data);
		v++;
		fread(&n,sizeof(n),1,fp);
		textcolor(0);
}
fclose(fp);
note_choices();
}

void current_note()
{
note_flag1=0;
clrscr();
char ch;
int v=0;
n.tag=0;
gt(66,3);
cprintf("1 of 2");
textbackground(14);
gt(73,3);
cprintf(" --> ");
textbackground(15);

//delay(80);
note_buttons();
_dos_getdate(&d1);
textcolor(0);
gotoxy(24,1);
textbackground(14);
cprintf("** Notes of current month **          ");
  textcolor(0);
  textbackground(15);

fp=fopen("C:\\turboc3\\bin\\project\\note.txt","rb")  ;
fread(&n,sizeof(n),1,fp);
fpo=fopen("C:\\turboc3\\bin\\project\\temp1.txt","wb");
while(!feof(fp))
{
	    textcolor(0);
	   if(n.year == d1.year && n.month == d1.month)
	   {
		if(n.year == d1.year && n.month == d1.month&&n.day==d1.day)
		{
			textcolor(BLUE);
		}
		else
		{
			textcolor(0);
		}
		if(v<18)
		{
		gotoxy(3,5+v) ;
		cprintf("%d",v+1);
		gotoxy(10,5+v);
		cprintf("%d-%d-%d",n.year,n.month,n.day);
		gotoxy(25,5+v);
		cprintf("%ld",n.tag);
		gotoxy(35,5+v);
		cprintf("%s",n.data);
		}
		v++;
		if(v>18)
		{
			note_flag=1;
			fwrite(&n, sizeof(n), 1, fpo);
		}

	     }
    /*	else{
	 gt(60,4);
	 cprintf("     ");
	} */
	textcolor(0);
	fread(&n,sizeof(n),1,fp);
}
fclose(fp);
fclose(fpo);
show_mouse();
}

//////////////////////////////////////////////////////////////////////////////////////////////

void extend_all()
{
note_flag1=2;
int v=0;
note_buttons();
textcolor(0);
gt(66,3);
cprintf("2 of 2");
gotoxy(22,1);
textcolor(0);
textbackground(14);
cprintf("           ** All Notes **              ");
//gotoxy(20,2);
textcolor(0);
textbackground(15);

textbackground(14);
gt(73,3);
cprintf(" <-- ");
textbackground(15);
fp=fopen("C:\\turboc3\\bin\\project\\temp2.txt","rb")  ;
fread(&n,sizeof(n),1,fp);
while(!feof(fp))
{
textcolor(0);
	gotoxy(3,5+v) ;
		cprintf("%d",v+1+18);
		gotoxy(10,5+v);
		cprintf("%d-%d-%d",n.year,n.month,n.day);
		gotoxy(25,5+v);
		cprintf("%ld",n.tag);
		 gotoxy(35,5+v);
		cprintf("%s",n.data);
		v++;
		fread(&n,sizeof(n),1,fp);
		textcolor(0);
}
fclose(fp);
note_choices();
}


//////////////////////////////////////////////////////////////////////////////////////////////


void all_note()
{
note_flag=0;
show_mouse();
char ch;
int v=0;
//delay(80);
clrscr();
gt(66,3);
cprintf("1 of 2");
textbackground(14);
gt(73,3);
cprintf(" --> ");
textbackground(15);

note_buttons();
gotoxy(22,1);
textcolor(0);
textbackground(14);
cprintf("           ** All Notes **              ");
//gotoxy(20,2);
textcolor(0);
textbackground(15);
fp=fopen("C:\\turboc3\\bin\\project\\note.txt","rb")  ;
fpo=fopen("C:\\turboc3\\bin\\project\\temp2.txt","wb");
fread(&n,sizeof(n),1,fp);
	while(!feof(fp))
	{
	      textcolor(0);

		if(n.year == d1.year && n.month == d1.month && n.day==d1.day)
		{
		textcolor(BLUE);
		}
		else
		{
		textcolor(0);
		}
		if(v<18)
		{
			gotoxy(3,5+v) ;
			cprintf("%d",v+1);
			gotoxy(10,5+v);
			cprintf("%d-%d-%d",n.year,n.month,n.day);
			gotoxy(25,5+v);
			cprintf("%ld",n.tag);
			gotoxy(35,5+v);
			cprintf("%s",n.data);
		}
	       //		fread(&n,sizeof(n),1,fp);
		 v++;

		if(v>18)
		{
			note_flag1=1;
			fwrite(&n, sizeof(n), 1, fpo);
		}
		fread(&n,sizeof(n),1,fp);
	}
	fclose(fp);
	fclose(fpo);
show_mouse();
  textcolor(0);
}

void add_note()
{
hide_mouse();
show_mouse();
_dos_getdate(&d1);
_dos_gettime(&t1);
char ch;
int i,rand;
char string1[30],string2[30],string3[30];
clrscr();
tc(0);
current_note();
fp=fopen("C:\\turboc3\\bin\\project\\note.txt","ab");
textbackground(15);
gotoxy(20,8);
cprintf("É");
gotoxy(62,8);
cprintf("»");
gotoxy(20,18);
cprintf("È");
gotoxy(62,18);
cprintf("¼");
for(i=0;i<9;i++)
{
	gotoxy(20,9+i);
	cprintf("º");
	gotoxy(21+41,9+i);
	cprintf("º");
}
for(i=0;i<41;i++)
{
	gotoxy(21+i,8);
	cprintf("Í");

	gotoxy(21+i,12);
	cprintf("Ä");
	gotoxy(21+i,14);
	cprintf("Ä");
	gotoxy(21+i,18);
	cprintf("Í");
}
//textbackground(15);
gt(21,9);
cprintf("             ");
gt(48,9);
cprintf("             ");
gotoxy(35,9);
textbackground(14);
cprintf(" PICK A DATE ") ;
textbackground(15);
gt(33,9);
cprintf("  ");
gt(33,10);
cprintf("  ");
gt(33,15);
cprintf("  ");
gt(33,16);
cprintf("  ");
gotoxy(33,17);
cprintf("  ");
gt(21,10);
cprintf("                                         ");
gotoxy(23,11);
cprintf("Year : ") ;
gt(21,13);
cprintf("                                         ");
textbackground(14);
gt(22,13);
cprintf(" NOTE : (<45 letters) ") ;
textbackground(15);
gt(21,15);
cprintf("                                         ");
gt(21,16);
cprintf("                                         ");
gt(21,17);
cprintf("                                        ");
	start1:
	tc(0);
	n.year=0;
	gotoxy(30,11);
	clreol();
	gt(37,11);
	cprintf("Month : ");
	gt(51,11);
	cprintf("Day : ");
	gt(62,11);
	cprintf("º");
	gt(30,11);
	_setcursortype(_NORMALCURSOR);

int r1;
r1=atoi(input1(4,1,30,11));
if(r1==0)
{
 note();
}
else
{
 n.year=r1;
}

/*do
{
textcolor(4);
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		n.year=n.year*10+ch;
	}
	else if(ch == -40)      //back space
	{
		n.year=n.year/10;
		printf(" ");
		printf("\b") ;
		if(n.year == 0)
		 goto start1;
	}
	else if(ch == -35 || ch == -39)
	break;

	else if(ch == -21)     //esc
	{
	  note();
	}
	else
	 goto start1;
}
while(1) ;   */

	if(n.year<d1.year)
	{
		gotoxy(23,22);
		textcolor(4);
		//textbackground(0);
		cprintf("* Note cannot be entered in past *") ;
		delay(1000);
		textcolor(0);
		add_note();
	}

start2:
	textcolor(0);
	gotoxy(45,11);
	clreol();
	gt(51,11);
	cprintf("Day : ");
	gt(62,11);
	cprintf("º");
	gotoxy(45,11);
	_setcursortype(_NORMALCURSOR);
	n.month=0;

r1=atoi(input1(2,1,45,11));
if(r1==0)
{
 note();
}
else
{
 n.month=r1;
}


   /*	do
	{
	textcolor(BLUE);
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		n.month=n.month*10+ch;
	}
	else if(ch == -40)      //back space
	{
		n.month=n.month/10;
		printf(" ");
		printf("\b") ;
		if(n.month == 0)
		 goto start2;
	}

	else if(ch == -35 || ch == -39)
	 break;
	else if(ch == -21)
	{
	//	exit(0);
	  note();
	}
	else
	 goto start2;
}
while(1) ; */

	if(n.month<1 || n.month>12 )
	{
		gotoxy(23,22);
		textcolor(4);
		//textbackground(0);
		cprintf("* please enter valid month *") ;
		gotoxy(23,22);
		delay(1000);
	      //	clreol();
		textcolor(0);
		goto start2;
	}
	if(n.year<=d1.year && n.month<d1.month)
	{
		gotoxy(23,22);
		textcolor(4);
		//textbackground(0);
		cprintf("* please enter future months *") ;
		gotoxy(23,22);
		delay(1000);
	      //	clreol();
		textcolor(0);
		goto start2;
	}

start3:
	tc(0);
	gotoxy(57,11);
	clreol();
	gt(62,11);
	cprintf("º");
	gotoxy(57,11);
	_setcursortype(_NORMALCURSOR);
	n.day=0;

r1=atoi(input1(2,1,57,11));
if(r1==0)
{
 main_page();
}
else
{
 n.day=r1;
}

    /*	do
	{
	tc(5);
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		n.day=n.day*10+ch;
	}
	else if(ch == -40)      //back space
	{
		n.day=n.day/10;
		printf(" ");
		printf("\b") ;
		if(n.day == 0)
		 goto start3;
	}
	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
      //	exit(0);
	  note();
	}
	else
	 goto start3;
}
while(1) ;
*/
/*Formula to find leap year  */

month_end[1]=(!((n.year%4) || !(n.year % 100) && (n.year % 400)))? 29 : 28;
	if(n.day<=0 || n.day>month_end[n.month-1])
	{
		goto start3;
	}
	gotoxy(22,15);
	fflush(stdin);


char u[50];
// clrscr();
gotoxy(22,15);
// printf("enter the string ");
 strcpy(u,input1(45,2,22,15));
 if(strcmp(u,"00")==0)
 {
 note();
 }
 else
 {
  strcpy(n.data,u);
// printf("\nthe content is %s",u);
 }


      //	gets(n.data);

/*signed int count;
       i=0;
       int flag=0,j=0;
	tc(0);
		gotoxy(45,13);
		cprintf("char count = ") ;
		gotoxy(58,13);
		count=45-i;
			printf("%d",count) ;
	  //
	fflush(stdin) ;
	do{
		if(i<37)
		{
			gotoxy(22+i,15);
			flag=0;
		}
		else
		{
			gotoxy(22+j,16);
			flag=1;
		}
		if(i>=45)
		{
			tc(4);
		}
		else
			tc(5);

		n.data[i]=getche();

		if(n.data[i]==13)
			break;

		else if(n.data[i] == 27)    //esc
		{
		//exit(0);
		     note();
		}
		else if(n.data[i] == 8)      //back space
		{
			printf(" ");
			printf("\b") ;
			if(flag == 0)
				i--;

			else if(flag == 1)   {
				j--;
				i--;
				}
			if(i == 36)
			{
			      gotoxy(24+36,13);
			      printf(" ");
			}
			n.data[i] = NULL;
		}
		else
		{
			if(flag == 0)
			i++;

			else if(flag == 1) {
			i++;
			j++;
			}
		}

	    //	gt(1,2);
	     //  printf("i=%d j=%d",i,j);
		tc(0);
		gotoxy(45,13);
		cprintf("char count = ") ;
		gotoxy(58,13);
		count=45-i;
	  //	gotoxy(30,1);
	       //	printf("%d",count) ;
		if(count<10 && count>=0)
		{
			printf("0%d",count);
			gotoxy(29,22);
			clreol();
			gotoxy(20,23);
			clreol();

		}
		else if(count<0)
		{
			textcolor(4) ;
			gotoxy(34,10);
			gotoxy(29,22);
			cprintf(" ** over flow ** ");
			gotoxy(20,23);
			cprintf("** Please delete some characters **");

		}
		else
		{	printf("%d",count) ;
			gotoxy(29,22);
			clreol();
			gotoxy(20,23);
			clreol();
		 }

	}
	while(1);
    /*	printf("\n",i);
	for(int j=0;j<=i;j++)
	{
		printf("%c",n.data[j]);
	}
	*/
       //	fflush(stdin) ;       //kina rakhnu parxa tha xaina tara rakhna chai parxa natra gets chaldaina
	//gets(n.data);
  /*	if(count<0)
	{
		gotoxy(29,22);
		textcolor(4);
		cprintf("***  NOT RECORDED ***");
		gotoxy(20,23);
		cprintf("** The character is longer than 45  char **");
		delay(2000);
		fclose(fp);
		note();
	}         */

	randomize();
	rand=random(100);
       itoa(n.month,string1,10);
       itoa(n.day,string2,10);
       itoa(rand,string3,10);
       strcat(string3,strcat(string1,string2));
       n.tag=atol(string3);
	fwrite(&n,sizeof(n),1,fp);
	gotoxy(12,22);
	textcolor(4);
	cprintf("* Note added successfull on %d/%d/%d with tag %ld *",n.year,n.month,n.day,n.tag);
	gotoxy(1,23);
	clreol();
       fclose(fp);
	_setcursortype(_NOCURSOR);
     //	delay(2000);
	textcolor(0);
	note();
}
/*
void add_note()
{
char ch;
int rand;
hide_mouse();
clrscr();
_dos_getdate(&d1);
_dos_gettime(&t1);
       char string1[30],string2[30],string3[30];
	fp=fopen("C:\\turboc3\\bin\\project\\note.txt","ab");
int i=0 ;
	textcolor(0);
	for(i=0;i<80;i++)
	{
		gotoxy(1+i,1);
		cprintf("Ä");
		gotoxy(1+i,9);
		cprintf("Ä");
	}
	gotoxy(1,2);
	textcolor(0);
	printf("Enter year  : ");
	gotoxy(1,3);
	printf("Enter month : ");
	gotoxy(1,4);
	printf("Enter day   : ");
//	gotoxy(1,5);
  //	printf("Enter tag   : ");

	gotoxy(1,10);
	cprintf("Enter your notes :(<50 letters) ");

	start1:
	n.year=0;
	gotoxy(16,2);
	clreol();
	_setcursortype(_NORMALCURSOR);

	do
	{
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		n.year=n.year*10+ch;
	}
	else if(ch == -40)      //back space
	{
		n.year=n.year/10;
		printf(" ");
		printf("\b") ;
		if(n.year == 0)
		 goto start1;
	}
	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
	  note();
	}
	else
	 goto start1;
}
while(1) ;

//	scanf("%d",&n.year);
	if(n.year<d1.year)
	{
		gotoxy(23,22);
		textcolor(4);
		//textbackground(0);
		cprintf("* Note cannot be entered in past *") ;
		delay(1000);
		textcolor(0);
		add_note();
	}

	start2:
	textcolor(0);
	gotoxy(16,3);
	clreol();
	_setcursortype(_NORMALCURSOR);
	n.month=0;
	do
	{
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		n.month=n.month*10+ch;
	}
	else if(ch == -40)      //back space
	{
		n.month=n.month/10;
		printf(" ");
		printf("\b") ;
		if(n.month == 0)
		 goto start2;
	}

	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
	  note();
	}
	else
	 goto start2;
}
while(1) ;

	//n.month=input(16,3);
	if(n.month<1 || n.month>12)
	{
		gotoxy(23,22);
		textcolor(4);
		//textbackground(0);
		cprintf("* please enter valid month *") ;
		gotoxy(23,22);
		delay(1000);
		clreol();
		textcolor(0);
		goto start2;
	}

	start3:
	textcolor(0);
	gotoxy(16,4);
	clreol();
	_setcursortype(_NORMALCURSOR);
	n.day=0;
	do
	{
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		n.day=n.day*10+ch;
	}
	else if(ch == -40)      //back space
	{
		n.day=n.day/10;
		printf(" ");
		printf("\b") ;
		if(n.day == 0)
		 goto start3;
	}
	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
	  note();
	}
	else
	 goto start3;
}
while(1) ;

/*Formula to find leap year  */   /*
month_end[1]=(!((n.year%4) || !(n.year % 100) && (n.year % 400)))? 29 : 28;
	if(n.day<=0 || n.day>month_end[n.month-1])
	{
		goto start3;
	}
	gotoxy(1,11) ;
	_setcursortype(_NORMALCURSOR);

signed int count;
       i=0;
	fflush(stdin) ;
	do{
		gotoxy(i+1,11);
		n.data[i]=getche();
		if(n.data[i]==13)
		 {
		      //	printf("\ngayo");
			break;
		 }
		else if(n.data[i] == 13)     // enter
		 break;

		else if(n.data[i] == 27)    //esc
		{
			note();
		}
		else if(n.data[i] == 8)      //back space
		{
		      //	printf("\n\ngayo");
		       //	break;
			printf(" ");
			printf("\b") ;
			i--;

		}
		else
		{
			i++;
		}
		gotoxy(34,10);
		cprintf("char count = ") ;
		gotoxy(48,10);
		count=50-i;
	  //	gotoxy(30,1);
	       //	printf("%d",count) ;
		if(count<10 && count>=0)
		{
			printf("0%d",count);
			gotoxy(29,22);
			clreol();
			gotoxy(20,23);
			clreol();

		}
		else if(count<0)
		{
			textcolor(0) ;
			gotoxy(34,10);
			gotoxy(29,22);
			cprintf(" ** over flow ** ");
			gotoxy(20,23);
			cprintf("** Please delete some characters **");

		}
		else
		{	printf("%d",count) ;
			gotoxy(29,22);
			clreol();
			gotoxy(20,23);
			clreol();
		 }

	}
	while(1);
      /*	printf("\n",i);
	for(int j=0;j<=i;j++)
	{
		printf("%c",n.data[j]);
	}
	*/
       //	fflush(stdin) ;       //kina rakhnu parxa tha xaina tara rakhna chai parxa natra gets chaldaina
	//gets(n.data);
   /*	if(count<0)
	{
		gotoxy(29,22);
		textcolor(4);
		cprintf("***  NOT RECORDED ***");
		gotoxy(20,23);
		cprintf("** The character is longer than 50  char **");
		delay(2000);
		fclose(fp);
		note();
	}

	randomize();
	rand=random(100);
       itoa(n.month,string1,10);
       itoa(n.day,string2,10);
       itoa(rand,string3,10);
       strcat(string3,strcat(string1,string2));
       n.tag=atol(string3);
	fwrite(&n,sizeof(n),1,fp);
	gotoxy(12,22);
	textcolor(4);
	cprintf("* Note added successfull on %d/%d/%d with tag %ld *",n.year,n.month,n.day,n.tag);
	gotoxy(1,23);
	clreol();
	fclose(fp);
	_setcursortype(_NOCURSOR);
	delay(2000);
	textcolor(0);
	note();
}
*/

void delete_note()
{

char ch;
 int y, m,d,s,t;
 int ny,nm,nd,tag1;
 textcolor(0);
 textbackground(15);
//tagborder();
 for(int i=0;i<17;i++)
{
	gotoxy(17+i,23);
	cprintf("%c",205);
	gotoxy(17+i,25);
	cprintf("%c",205);
}

gotoxy(16,24);
cprintf("%c",186);
gotoxy(34,24);
cprintf("%c",186);
gotoxy(16,23);
cprintf("%c",201);
gotoxy(34,23);
cprintf("%c",187);
gotoxy(16,25);
cprintf("%c",200);
gotoxy(34,25);
cprintf("%c",188);
textcolor(0);
gotoxy(17,24);
cprintf(" TAG : #         ");
gotoxy(1,1);
textcolor(0);
textbackground(14);
cprintf("       ****     HINT : Shift + d to delete notes of all past months    ****     ");
textcolor(0);
textbackground(15);
gotoxy(26,24);
_setcursortype(_NORMALCURSOR);
textcolor(0);
      int c=0;
start1:
	t=0;
	gotoxy(26,24);
	cprintf("        ");
	gotoxy(26,24);
       _setcursortype(_NORMALCURSOR);
	do
	{
	ch=getche()-48;
	if(ch == 'D')    //D=68 -48 = 20
	{
		delete_end();
	}
	else if(ch>=0 && ch<10)
	{       c++;
		t=t*10+ch;
		if(c>7)
		{ c=0;
		  gotoxy(26,24);
		  cprintf("Overflow");
		  delay(300);
		  goto start1;

		}
	}
	else if(ch == -40)      //back space
	{
		t=t/10;
		printf(" ");
		printf("\b") ;
		if(t == 0)
		 goto start1;
	}
	else if(ch == -35)
	 break;
	else if(ch == -21 && ch!='D')
	{
	  note();
	}
	else
	 goto start1;
}
while(1) ;

  textcolor(0);
  int ss=0;
  _setcursortype(_NOCURSOR);
  fpo = fopen("C:\\turboc3\\bin\\project\\note.txt","rb");
  fpt = fopen("C:\\turboc3\\bin\\project\\temp.txt", "wb");

  fread(&n, sizeof(n), 1, fpo);
  while (!feof(fpo))
  {
  tag1=n.tag;
  if(tag1==t)
  {
       ss=1;
  }
  else
   {
	fwrite(&n, sizeof(n), 1, fpt);
   }
    fread(&n, sizeof(n), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);

  if(ss==1)
  {
  gotoxy(18,24);
 textcolor(RED);
   cprintf(" RECORD DELETED ");
   delay(1000);
   all_note();
  }
  else
  {
  gotoxy(18,24);
 textcolor(RED);
  cprintf("Match not found");
  delay(1000);
  all_note();
  }
 /* fp=fopen("c:\\turboc3\\bin\\project\\temp.txt","rb");
  fread(&n,sizeof(n),1,fp);
  while(!feof(fp))
  {
   cprintf("\nthe data in temp file is");
   cprintf("%d-%d-%d",n.year,n.month,n.day);
fread(&n,sizeof(n),1,fp);
 }
 fclose(fp);
getch();
   */
//			getch();
  fpo = fopen("C:\\turboc3\\bin\\project\\note.txt", "wb");
  fpt = fopen("C:\\turboc3\\bin\\project\\temp.txt", "rb");
  fread(&n, sizeof(n), 1, fpt);
  while(!feof(fpt))
  {
  fwrite(&n, sizeof(n), 1, fpo);
  fread(&n, sizeof(n), 1, fpt);
  }

  fclose(fpo);
  fclose(fpt);
  note();
}

void delete_end()
{
clrscr();
hide_mouse();
_dos_getdate(&d1);
int v=0,ss=0;
char ch;
note_buttons();
textcolor(0);
gotoxy(24,1);
textbackground(14);
cprintf("** Notes of Previous Months  **       ");
textbackground(15);
textcolor(0);
fp=fopen("C:\\turboc3\\bin\\project\\note.txt","rb")  ;
fread(&n,sizeof(n),1,fp);
while(!feof(fp))
{
	    textcolor(0);
	   if(n.year<=d1.year && n.month< d1.month)
		{
		if(n.year == d1.year && n.month == d1.month&&n.day==d1.day)
		{
		textcolor(BLUE);
		}
		else
		{
		textcolor(0);
		}
		gotoxy(3,5+v) ;
		cprintf("%d",v+1);
		gotoxy(10,5+v);
		cprintf("%d-%d-%d",n.year,n.month,n.day);
		gotoxy(25,5+v);
		cprintf("%ld",n.tag);
		 gotoxy(35,5+v);
		cprintf("%s",n.data);
		v++;
		}
		textcolor(0);
		fread(&n,sizeof(n),1,fp);

}
fclose(fp);
//delay(300);
hide_mouse();
show_mouse();
      textcolor(0);
      textbackground(14);
      gotoxy(2,24);
      cprintf("  Do you want to Delete all the notes of previous months ? ");
	textbackground(15);
	cprintf("   ");
	textbackground(14);
      textcolor(15);
    cprintf(" Y");
	textcolor(0);
	cprintf("es ");
	textbackground(15);
	cprintf("      ");
	// gotoxy(50,14);
	textbackground(14);
	textcolor(15);
	cprintf(" N");
	textcolor(0);
	cprintf("o ");
	textbackground(15);
	cprintf("          ");
	gotoxy(2,25);
	textbackground(15);
	cprintf("                                                                             ");

	gotoxy(69,24) ; cprintf("Ü") ;
	gotoxy(65,25)  ; cprintf("ßßßßß");
	gotoxy(79,24) ; cprintf("Ü") ;
	gotoxy(76,25)  ; cprintf("ßßßß");
start:
getmousepos(&button,&x,&y);
	while(!kbhit())
	{
	       _setcursortype(_NOCURSOR);
       //	show_mouse();
/*************** Mouse click **************************/

	show_mouse();
	getmousepos(&button,&x,&y);
	textcolor(0);
	textbackground(15);
	if(button == 1)
	{
	  //	delay(20); //delay is must
		button=0;
		gotoxy(4,1);
	      //	cprintf("( %d x %d)",x,y);
		if(x>=507 && x<=541 && y>=186 && y<=189) // 528*175 600*185
		{
			button=0;
			goto here;
		}
		if(x>=592 && x<=620 && y>=186 && y<=189) // 528*175 600*185
		{
			button=0;
			note();
		}

		 else if(x>=10 && y>=0 && x<=53 && y<=9)
		 {
			button=0;
			hide_mouse();
			note();
			//main_page();
		 }
	}
	}
	ch=getch();
	if(ch=='y')
	{
		here:
		fp = fopen("C:\\turboc3\\bin\\project\\note.txt","rb");
		fpt = fopen("C:\\turboc3\\bin\\project\\temp.txt", "wb");

		fread(&n, sizeof(n), 1, fp);
		while (!feof(fp))
		{
		if(n.month<d1.month || n.year<d1.year)
		{
		 ss=1;
		}
		else
		{
			fwrite(&n, sizeof(n), 1, fpt);
		}
			fread(&n, sizeof(n), 1, fp);
		}
		fclose(fp);
		fclose(fpt);
		textbackground(15);
		 clrscr();
		 textbackground(15);
		 if(ss==1)
		{
			gotoxy(18,11);
			textcolor(RED);
			cprintf("**     RECORD DELETED OF PREVIOUS MONTHS    **");
			delay(1500);
			all_note();
		}
		else
		{
			gotoxy(22,11);
			 textcolor(RED);
			cprintf("***    NO ANY PREVIOUS NOTE WERE FOUND    *** ");
			delay(1500);
			all_note();
		}
		fp = fopen("C:\\turboc3\\bin\\project\\note.txt", "wb");
		fpt = fopen("C:\\turboc3\\bin\\project\\temp.txt", "rb");
		fread(&n, sizeof(n), 1, fpt);
		while(!feof(fpt))
		{
			  fwrite(&n, sizeof(n), 1, fp);
			  fread(&n, sizeof(n), 1, fpt);
		}

		fclose(fp);
		fclose(fpt);
	}
	else if(ch == 'n')
	{
		note();
	}
	else
	{
		goto start;
	}
	note();
}

void update()
{
hide_mouse();
_dos_getdate(&d1);
 char che;
 int s=0;
 int month,year;
 month=d1.month;
 year=d1.year;
 int y, m, d,tag;
 int ch;
 int y1,m1,d1,tag1;

  textcolor(0);
  int t;


//tagborder();
for(int i=0;i<17;i++)
{
	gotoxy(33+i,23);
	cprintf("%c",205);
	gotoxy(33+i,25);
	cprintf("%c",205);
}

gotoxy(32,24);
cprintf("%c",186);
gotoxy(50,24);
cprintf("%c",186);
gotoxy(32,23);
cprintf("%c",201);
gotoxy(50,23);
cprintf("%c",187);
gotoxy(32,25);
cprintf("%c",200);
gotoxy(50,25);
cprintf("%c",188);
textcolor(0);
gotoxy(33,24);
cprintf(" TAG : #        ");

//gotoxy(42,24);
//	_setcursortype(_NORMALCURSOR);

gotoxy(42,24);
_setcursortype(_NORMALCURSOR);
textcolor(0);

start1:
	t=0;
	gotoxy(42,24);
	cprintf("        ");
	gotoxy(42,24);
       _setcursortype(_NORMALCURSOR);
	int c=0;
	do
	{
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{       c++;
		t=t*10+ch;
			if(c>7)
		{ c=0;
		  gotoxy(42,24);
		  cprintf("Overflow");
		  delay(300);
		  goto start1;

		}
	}
	else if(ch == -40)      //back space
	{
		t=t/10;
		printf(" ");
		printf("\b") ;
		if(t == 0)
		 goto start1;
	}
	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
	  note();
	}
	else
	 goto start1;
}
while(1) ;




//	    t=input(42,24);

textcolor(0);
  fpo = fopen("C:\\turboc3\\bin\\project\\note.txt", "rb");
  fpt = fopen("C:\\turboc3\\bin\\project\\temp.txt", "wb");
  fread(&n, sizeof(n), 1, fpo);
  while (!feof(fpo))
  {
   y1=n.year;
   m1=n.month;
   d1=n.day;
   tag1=n.tag;

   //if ( y1==y && m1==m && d1==d && tag1==tag)
   if(tag1==t)
   { s=	1;
   back:
   clrscr();
   border();
_setcursortype(_NORMALCURSOR);
textcolor(BLACK);
gotoxy(30,3); printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»  ");
gotoxy(30,4); printf("º	       	          º  ");
gotoxy(30,5); printf("ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼  ");
 gotoxy(32,4);
 textcolor(RED);
 cprintf(" Modification Page");
  textcolor(0);

       gotoxy(8,7);
	cprintf("            Ü");
	gotoxy(8,8);
	cprintf("ßßßßßßßßßßßßß");
gotoxy (5,7);
printf("1)");
textcolor(0);
textbackground(14);
cprintf(" Update Year ");
textbackground(15);
    //   textcolor(0);

	gotoxy(8,9);
	cprintf("             Ü");
	gotoxy(8,10);
	cprintf("ßßßßßßßßßßßßßß");

 gotoxy (5,9);
printf("2)");
textbackground(14);
cprintf(" Update Month ");
textbackground(15);
       textcolor(0);

	gotoxy(8,11);
	cprintf("           Ü");
	gotoxy(8,12);
	cprintf("ßßßßßßßßßßßß");
gotoxy (5,11);
printf("3)");
textbackground(14);
cprintf(" Update Day ");
textbackground(15);

textcolor(0);

	gotoxy(8,13);
	cprintf("            Ü");
	gotoxy(8,14);
	cprintf("ßßßßßßßßßßßßß");
gotoxy (5,13);
printf("4)");
textbackground(14);
cprintf(" Update Data ");
textbackground(15);

textcolor(0);

	gotoxy(8,15);
	cprintf("     Ü");
	gotoxy(8,16);
	cprintf("ßßßßßß");
gotoxy (5,15);
printf("5)");
textbackground(14);
cprintf(" Exit ");
textbackground(15);


start:
getmousepos(&button,&x,&y);
	while(!kbhit())
	{
	       _setcursortype(_NOCURSOR);
       //	show_mouse();
/*************** Mouse click **************************/

	show_mouse();
	getmousepos(&button,&x,&y);
	textcolor(0);
	textbackground(15);
	if(button == 1)
	{
	  //	delay(20); //delay is must
		button=0;
		gotoxy(4,1);
		cprintf("( %d x %d)",x,y);
		if(x>=55 && x<=147 && y>=50 && y<=55) // 528*175 600*185
		{
		hidemouse();
		//note();
	       //	clrscr();
		//border();

		  gotoxy(3,20);
     cprintf("Enter New year:");
      gotoxy(18,9);
_setcursortype(_NORMALCURSOR);
textcolor(0);
start3:
	n.year=0;
	gotoxy(18,20);
	cprintf("        ");
	gotoxy(18,20);
       _setcursortype(_NORMALCURSOR);
int r1;
r1=atoi(input1(4,1,18,20));
if(r1==0)
{
 goto back;
}
else
{
 n.year=r1;
}



       /*	do
	{
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		n.year=n.year*10+ch;
	}
	else if(ch == -40)      //back space
	{
		n.year=n.year/10;
		printf(" ");
		printf("\b") ;
		if(n.year == 0)
		 goto start3;
	}
	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
	//clrscr();
	goto back;

	}
	else
	 goto start3;
}
while(1) ;  */
if(n.year<year || n.year>2030)
{
      //	cprintf("%d",s);
      // getch();
	goto start3;
}
/*if(s==1)
{
  gotoxy(25,20);
 textcolor(RED);
 cprintf("RECORD updated!!!");
 goto  m;
} */
   goto m;
 // delay(1000);
 // note();
}

if(x>=51 && x<=159 && y>=66 && y<=71) // 528*175 600*185
		{
		hidemouse();

  gotoxy(3,20);
cprintf("Enter New Month : ");
gotoxy(20,9);
_setcursortype(_NORMALCURSOR);
textcolor(0);
start4:
	n.month=0;
	gotoxy(20,20);
	cprintf("           ");
	gotoxy(20,20);
       _setcursortype(_NORMALCURSOR);
int r1;
r1=atoi(input1(2,1,20,20));
if(r1==0)
{
 note();
}
else
{
 n.month=r1;
}

if(n.month<=0 || n.month>=13)
{
 goto start4;
}


   goto m;
}


if(x>=49 && x<=140 && y>=83 && y<=87) // 528*175 600*185
		{
		hidemouse();

  gotoxy(3,20);
cprintf("Enter New day : ");
gotoxy(20,9);
_setcursortype(_NORMALCURSOR);
textcolor(0);
start5:
	n.month=0;
	gotoxy(20,20);
	cprintf("            ");
	gotoxy(20,20);
       _setcursortype(_NORMALCURSOR);
int r1;
r1=atoi(input1(2,1,20,20));
if(r1==0)
{
 note();
}
else
{
 n.day=r1;
}
n.month=m1;
month_end[1]=(!((n.year%4) || !(n.year % 100) && (n.year % 400)))? 29 : 28;
if(n.day<=0 || n.day>month_end[n.month-1])
{
//cprintf("\nn.day=%d  n.year=  %d  r1=   %d  monthend=%d   n.month=%d",n.day,n.year,r1,month_end[n.month-1],m1);
//getch();
	goto start5;
}
   goto m;
}


if(x>=49 && x<=148 && y>=96 && y<=103) // 528*175 600*185
{
hidemouse();
gotoxy(3,20);
     cprintf("Enter New data: ");
fflush(stdin) ;       //kina rakhnu parxa tha xaina tara rakhna chai parxa natra gets chaldaina
char u[50];
// clrscr();
gotoxy(20,20);
_setcursortype(_NORMALCURSOR);
// printf("enter the string ");
 strcpy(u,input1(45,2,20,20));
 if(strcmp(u,"00")==0)
 {
 goto back;
 }
 else
 {
  strcpy(n.data,u);
// printf("\nthe content is %s",u);
 }


   goto m;
}


if(x>=49 && x<=95 && y>=113 && y<=119) // 528*175 600*185
{
hidemouse();
note();
}

}
}
 che=getche();
if(che==27)
{
 note();
}
else
{
goto back;
}





/*    gotoxy(30,2); textcolor(BLUE);textbackground(GREEN); cprintf(" Modification Page ");
    textcolor(0);
    textbackground(15);
    gotoxy(3,3);
    cprintf("1. Update year" );
 gotoxy(3,4);   cprintf("2. Update Month");
 gotoxy(3,5);   cprintf("3. Update day");
 gotoxy(3,6);   cprintf("4: Update data");
 gotoxy(3,7);   cprintf("5: Exit");
		textcolor(RED);
 gotoxy(3,8); cprintf("Enter your choice:");
    textcolor(0);
    gotoxy(25,8);
_setcursortype(_NORMALCURSOR);
textcolor(0);
*/

/*char chh;
start2:
	t=0;
	gotoxy(25,8);
	cprintf("        ");
	gotoxy(25,8);
       _setcursortype(_NORMALCURSOR);

       int r1;
r1=atoi(input1(1,1,25,8));
if(r1==0)
{
 note();
}
else
{
 chh=r1;
}


       /*	do
	{
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		chh=ch;
	}
else if(ch == -40)      //back space
	{
		chh=chh/10;
		printf(" ");
		printf("\b") ;
		if(chh == 0)
		 goto start2;
	}
	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
	  note();
	}
	else
	 goto start2;
}
while(1) ; */
/* switch (chh)
    {
    case 1:
      gotoxy(3,9);
     cprintf("Enter New year:");
      gotoxy(18,9);
_setcursortype(_NORMALCURSOR);
textcolor(0);

start3:
	n.year=0;
	gotoxy(18,9);
	cprintf("        ");
	gotoxy(18,9);
       _setcursortype(_NORMALCURSOR);

r1=atoi(input1(4,1,18,9));
if(r1==0)
{
 note();
}
else
{
 n.year=r1;
}


      /*	do
	{
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		n.year=n.year*10+ch;
	}
	else if(ch == -40)      //back space
	{
		n.year=n.year/10;
		printf(" ");
		printf("\b") ;
		if(n.year == 0)
		 goto start3;
	}
	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
	  note();
	}
	else
	 goto start3;
}
while(1) ; */
/*if(n.year<year || n.year>2030)
{
	goto start3;
}
break;

case 2:
gotoxy(3,9);
cprintf("Enter New Month : ");
gotoxy(20,9);
_setcursortype(_NORMALCURSOR);
textcolor(0);
start4:
	n.month=0;
	gotoxy(20,9);
	cprintf("        ");
	gotoxy(20,9);
       _setcursortype(_NORMALCURSOR);

r1=atoi(input1(2,1,20,9));
if(r1==0)
{
 note();
}
else
{
 n.month=r1;
}


      /*	do
	{
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		n.month=n.month*10+ch;
	}
	else if(ch == -40)      //back space
	{
		n.month=n.month/10;
		printf(" ");
		printf("\b") ;
		if(n.month == 0)
		 goto start4;
	}
	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
	  note();
	}
	else
	 goto start4;
}
while(1) ; */

/*if(n.month<=0 || n.month>=13)
{
 goto start4;
}
break;

case 3:
gotoxy(3,9);
cprintf("Enter New day: ");
gotoxy(20,9);
_setcursortype(_NORMALCURSOR);
textcolor(0);

start5:
	n.day=0;
	gotoxy(20,9);
	cprintf("        ");
	gotoxy(20,9);
       _setcursortype(_NORMALCURSOR);

    // int r1;
r1=atoi(input1(2,1,20,9));
if(r1==0)
{
 note();
}
else
{
 n.day=r1;
}

     /*	do
	{
	ch=getche()-48;
	if(ch>=0 && ch<10)
	{
		n.day=n.day*10+ch;
	}
		else if(ch == -40)      //back space
	{
		n.day=n.day/10;
		printf(" ");
		printf("\b") ;
		if(n.day == 0)
		 goto start5;
	}
	else if(ch == -35)
	 break;
	else if(ch == -21)
	{
	  note();
	}
	else
	 goto start5;
}
while(1) ; */

/*Formula to find leap year  */
/*month_end[1]=(!((n.year%4) || !(n.year % 100) && (n.year % 400)))? 29 : 28;
if(n.day<=0 || n.day>month_end[n.month-1])
{
	goto start5;
}

break;
     case 4:
      gotoxy(3,9);
     cprintf("Enter New data: ");
fflush(stdin) ;       //kina rakhnu parxa tha xaina tara rakhna chai parxa natra gets chaldaina
char u[50];
// clrscr();
gotoxy(20,9);
// printf("enter the string ");
 strcpy(u,input1(45,2,20,9));
 if(strcmp(u,"00")==0)
 {
 note();
 }
 else
 {
  strcpy(n.data,u);
// printf("\nthe content is %s",u);
 }



	//gets(n.data);

     break;
     case 5:
     note();
     break;
    default:
     gotoxy(2,20);
     printf("Invalid Selection");
     goto back;
     break;
    } */
     m:
     fwrite(&n, sizeof(n), 1, fpt);
    }

   else
   {
   fwrite(&n, sizeof(n), 1, fpt);
  }
    fread(&n,sizeof(n),1,fpo);

  }
  fclose(fpo);
  fclose(fpt);

  _setcursortype(_NOCURSOR);
   if(s==1)
  {
  gotoxy(25,24);
 textcolor(RED);
 cprintf("RECORD updated!!!");
  }
  else
  {
  gotoxy(33,24);
 textcolor(RED);
  cprintf("Match not found!!");
  }

 fpo = fopen("C:\\turboc3\\bin\\project\\note.txt", "wb");
  fpt = fopen("C:\\turboc3\\bin\\project\\temp.txt", "rb");

  fread(&n, sizeof(n), 1, fpt);
  while (!feof(fpt))
  {
   fwrite(&n, sizeof(n), 1, fpo);
  fread(&n, sizeof(n), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);

  delay(1000);
  note();
 }

