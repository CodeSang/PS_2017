#include<iostream>
#include<algorithm>
using namespace std;

struct paper {
	
	
	int color; // 0 WHITE , 1 BLACK
	int x,y, xx,yy;

	paper *A;
	paper *B;

	paper(int color, int x, int y, int xx, int yy)
	{
		this->color = color;
		this->x  = x;
		this->xx = xx;
		this->y  = y;
		this->yy = yy;

		this->A = NULL;
		this->B = NULL;
	}

};



int width, height;
int num;

void Cut(paper *A, int px, int py)
{
	if (A == NULL)return;

	if (A->x > px || px > A->xx || A->y > py || py > A->yy) return;
	
	if (A->A != NULL)
	{
		Cut(A->A, px, py);
		Cut(A->B, px, py);
		return;
	}

	if (A->x < px && px < A->xx && A->y < py && py < A->yy)
	{
		if (A->color == 0)
		{
			A->A = new paper(1, A->x, A->y, A->xx, py);
			A->B = new paper(1, A->x, py, A->xx, A->yy);
		}
		else
		{
			A->A = new paper(0, A->x, A->y, px, A->yy);
			A->B = new paper(0, px, A->y, A->xx, A->yy);
		}
	}

	return;
}

int m = 40000 * 40000;
int M = 0;

void mM(paper* p)
{
	if (p == NULL)return;

	if (p->A != NULL)
	{
		mM(p->A);
		mM(p->B);
		return;
	}

	m = min(m, (p->xx - p->x) * (p->yy - p->y));
	M = max(M, (p->xx - p->x) * (p->yy - p->y));
	return;
}

int main() {
	cin >> width >> height;

	cin >> num;
	paper MainPaper(0, 0, 0, width, height);
	for (int i = 0; i < num; i++)
	{
		int px, py;
		cin >> px >> py;
		Cut(&MainPaper, px, py);
	}

	mM(&MainPaper);

	cout << M << " " << m  << endl;
}