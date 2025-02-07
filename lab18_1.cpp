#include <iostream>
using namespace std;
#include <cmath>
struct Rect
{
	double x, y, w, h;
};

double overlap(Rect R1, Rect R2)
{
	if (R1.x <= R2.x && R1.x + R1.w >= R2.x + R2.w && R1.y >= R2.y && R1.y - R1.h <= R2.y - R2.h)
	{
		return R2.w * R2.h;
	}
	else if (R1.x > R2.x && R1.x + R1.w < R2.x + R2.w && R1.y < R2.y && R1.y - R1.h > R2.y - R2.h)
	{
		return R1.w * R1.h;
	}else{

	double xleft = R1.x > R2.x ? R1.x : R2.x;
	double ytop = R1.y > R2.y ? R2.y : R1.y;
	double xright = R1.x + R1.w > R2.x + R2.w ? R2.x + R2.w : R1.x + R1.w;
	double ybottom= R1.y - R1.h > R2.y - R2.h ?  R1.y - R1.h : R2.y - R2.h ;

	double ovrwight = xright - xleft;
	double ovheight = ytop - ybottom;

	return ovrwight <= 0 || ovheight <= 0 ? 0 : ovrwight * ovheight;}
}


int main(){Rect R1 = {1,1,5,5};
Rect R2 = {2,2,5,5};	
cout << overlap(R1,R2);	}