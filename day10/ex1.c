#include <stdio.h>
void draw_line(int n,char c)
{
	for(int i=0;i<n;i++) {
		putchar(c);
	}
}
void draw_line2(int n,char c)
{
	for(int i=11;i<n;i++) {
		putchar(c);
	}

}
void draw_tri2()
{
	int ix,iy;
	for(iy = 0;iy <10;iy++) {
		for(ix = iy;ix < 15 ;ix++) {
			putchar('*');
		}
		puts("");
	}
}

void draw_tri1()
{
	int ix,iy;
	for(iy = 0;iy < 10;iy++) {
		draw_line(iy,'*');
		puts("");
	}
}

void draw_tri3()
{
	int iy;
	for(iy = 0;iy<10;iy++) {
		draw_line(9-iy,' ');draw_line((iy*2)+1,'*');
	
		puts("");
	}
	for(iy = 0; iy < 5 ;iy++) {
		draw_line(7,' ');draw_line(4,'*');
		puts("");
	}
}

int main()
{
	draw_tri3();
	return 0;
} 
