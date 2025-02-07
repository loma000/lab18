#include <iostream>
using namespace std;
#include <cmath>
struct Rect
{
	double x, y, w, h;
};

double overlap(Rect R1, Rect R2)
{
	double xleft = R1.x > R2.x ? R1.x : R2.x;
	double ybottom = R1.y > R2.y ? R1.y : R2.y;
	double xright = R1.x + R1.w > R2.x + R2.w ? R2.x + R2.w : R1.x + R1.w;
	double ytop = R1.y + R1.h > R2.y + R2.h ? R2.y + R2.h : R1.y + R1.h;

	double ovrwight = xright - xleft;
	double ovheight = ytop - ybottom;

	return ovrwight <= 0 || ovheight <= 0 ? 0 : ovrwight * ovheight;
}
