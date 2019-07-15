#include <graphics.h>
#include <time.h>
#include <conio.h>

#define MAXSTAR 700

class STAR {
public:
	double x;
	int y;
	double step;
	int color;
};

STAR star[MAXSTAR];

bool quilkly = false,slowly=false;

void InitStar(int i) {
	star[i].x = 0;
	star[i].y = rand() % 480;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

void MoveStar(int i) {
	putpixel((int)star[i].x, star[i].y, 0);
	quilkly?star[i].x = star[i].x+star[i].step+5: slowly? star[i].x = star[i].x + star[i].step -2 :star[i].x+= star[i].step;
	if (star[i].x > 640)
		InitStar(i);
	putpixel((int)star[i].x, star[i].y, star[i].color);
}

// 主函数
int main() {
	MOUSEMSG m;

	srand((unsigned)time(NULL));
	initgraph(640, 480);

	for (int i = 0; i < MAXSTAR; i++) 	{
		InitStar(i);
		star[i].x = rand() % 640;
	}

	while (!_kbhit()) {
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
			quilkly = !quilkly;
		if (m.uMsg == WM_RBUTTONDOWN)
			slowly = !slowly;
		for (int i = 0; i < MAXSTAR; i+=2)
			MoveStar(i);
		Sleep(20);
	}

	closegraph();
}
