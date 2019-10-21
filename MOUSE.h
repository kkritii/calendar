int button;      // for mouse handling
/********* MOUSE HANDLING PROGRAM************/
void show_mouse()              //IF call shows mouse pointer
{
	in.x.ax=1;
	int86(0x33,&in,&out);
}
void hide_mouse()             //If call hide mouse pointer
{
	in.x.ax=2;
	int86(0x33,&in,&out);
}
void getmousepos(int *button,int *x,int *y)   //gives button clicked & pos
{
	in.x.ax=3;
	int86(0x33,&in,&out);
	*button=out.x.bx;
	*x=out.x.cx;
	*y=out.x.dx;
}
