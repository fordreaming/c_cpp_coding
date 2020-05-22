// intersection.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "opencv.hpp"
#include <vector>
#include <windows.h>

using namespace cv;
using namespace std;

//�ų�ʵ��
bool IsRectCross(const Point &p1, const Point &p2, const Point &q1, const Point &q2)
{
	bool ret = min(p1.x, p2.x) <= max(q1.x, q2.x) &&
		min(q1.x, q2.x) <= max(p1.x, p2.x) &&
		min(p1.y, p2.y) <= max(q1.y, q2.y) &&
		min(q1.y, q2.y) <= max(p1.y, p2.y);
	return ret;
}

//�����ж�
bool IsLineSegmentCross(const Point &pFirst1, const Point &pFirst2, const Point &pSecond1, const Point &pSecond2)
{
	double v1 = 0.0;
	double v2 = 0.0;
	double v3 = 0.0;
	double v4 = 0.0;

	//�������Ĳ��ֵ,��ֵΪ��ʱ��ʾ����ת,��ʱ��ʾ����ת������������һ��һ����תʱ��ʾ�߶��ཻ
	v1 = (pFirst1.x - pSecond2.x)*(pSecond1.y - pSecond2.y) - (pFirst1.y - pSecond2.y)*(pSecond1.x - pSecond2.x);
	v2 = (pFirst2.x - pSecond2.x)*(pSecond1.y - pSecond2.y) - (pFirst2.y - pSecond2.y)*(pSecond1.x - pSecond2.x);

	if (v1*v2 > 0.00000001)
	{
		return false;
	}

	v3 = (pSecond1.x - pFirst2.x)*(pFirst1.y - pFirst2.y) - (pSecond1.y - pFirst2.y)*(pFirst1.x - pFirst2.x);
	v4 = (pSecond2.x - pFirst2.x)*(pFirst1.y - pFirst2.y) - (pSecond2.y - pFirst2.y)*(pFirst1.x - pFirst2.x);

	if (v3*v4 > 0.00000001)
	{
		return false;
	}

	return true;
}

bool GetCrossPoint(const Point &p1, const Point &p2, const Point &q1, const Point &q2, long &x, long &y)
{
	if (IsRectCross(p1, p2, q1, q2))
	{
		if (IsLineSegmentCross(p1, p2, q1, q2))
		{
			//�󽻵�
			long tmpLeft, tmpRight;
			tmpLeft = (q2.x - q1.x) * (p1.y - p2.y) - (p2.x - p1.x) * (q1.y - q2.y);
			tmpRight = (p1.y - q1.y) * (p2.x - p1.x) * (q2.x - q1.x) + q1.x * (q2.y - q1.y) * (p2.x - p1.x) - p1.x * (p2.y - p1.y) * (q2.x - q1.x);

			x = (int)((double)tmpRight / (double)tmpLeft);

			tmpLeft = (p1.x - p2.x) * (q2.y - q1.y) - (p2.y - p1.y) * (q1.x - q2.x);
			tmpRight = p2.y * (p1.x - p2.x) * (q2.y - q1.y) + (q2.x - p2.x) * (q2.y - q1.y) * (p1.y - p2.y) - q2.y * (q1.x - q2.x) * (p2.y - p1.y);
			y = (int)((double)tmpRight / (double)tmpLeft);
			return true;
		}
	}
	return false;
}

//  The function will return YES if the point x,y is inside the polygon, or
//  NO if it is not.  If the point is exactly on the edge of the polygon,
//  then the function may return YES or NO.
bool IsPointInPolygon(std::vector<Point> &poly, Point pt)
{
	int i, j;
	bool c = false;
	for (i = 0, j = poly.size() - 1; i < poly.size(); j = i++)
	{
		if ((((poly[i].y <= pt.y) && (pt.y < poly[j].y)) ||
			((poly[j].y <= pt.y) && (pt.y < poly[i].y)))
			&& (pt.x < (poly[j].x - poly[i].x) * (pt.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x))
		{
			c = !c;
		}
	}
	return c;
}

//����a���ڵ�b,����a�ڵ�b˳ʱ�뷽��,����true,���򷵻�false
bool PointCmp(const Point &a, const Point &b, const Point &center)
{
	if (a.x >= 0 && b.x < 0)
		return true;
	if (a.x == 0 && b.x == 0)
		return a.y > b.y;
	//����OA������OB�Ĳ��
	int det = (a.x - center.x) * (b.y - center.y) - (b.x - center.x) * (a.y - center.y);
	if (det < 0)
		return true;
	if (det > 0)
		return false;
	//����OA������OB���ߣ��Ծ����жϴ�С
	int d1 = (a.x - center.x) * (a.x - center.x) + (a.y - center.y) * (a.y - center.y);
	int d2 = (b.x - center.x) * (b.x - center.y) + (b.y - center.y) * (b.y - center.y);
	return d1 > d2;
}
void ClockwiseSortPoints(std::vector<Point> &vPoints)
{
	//��������
	cv::Point center;
	double x = 0, y = 0;
	for (int i = 0; i < vPoints.size(); i++)
	{
		x += vPoints[i].x;
		y += vPoints[i].y;
	}
	center.x = (int)x / vPoints.size();
	center.y = (int)y / vPoints.size();

	//ð������
	for (int i = 0; i < vPoints.size() - 1; i++)
	{
		for (int j = 0; j < vPoints.size() - i - 1; j++)
		{
			if (PointCmp(vPoints[j], vPoints[j + 1], center))
			{
				cv::Point tmp = vPoints[j];
				vPoints[j] = vPoints[j + 1];
				vPoints[j + 1] = tmp;
			}
		}
	}
}

//�����������Ľ���
bool getintersection(vector<Point> &poly1, vector<Point> &poly2, std::vector<Point> &interPoly)
{
	if (poly1.size() < 3 || poly2.size() < 3)
	{
		return false;
	}

	long x, y;
	//�������ν���
	for (int i = 0; i < poly1.size(); i++)
	{
		int poly1_next_idx = (i + 1) % poly1.size();
		for (int j = 0; j < poly2.size(); j++)
		{
			int poly2_next_idx = (j + 1) % poly2.size();
			if (GetCrossPoint(poly1[i], poly1[poly1_next_idx], poly2[j], poly2[poly2_next_idx], x, y))
			{
				interPoly.push_back(cv::Point(x, y));
			}
		}
	}

	//���������ڲ���
	for (int i = 0; i < poly1.size(); i++)
	{
		if (IsPointInPolygon(poly2, poly1[i]))
		{
			interPoly.push_back(poly1[i]);
		}
	}

	for (int i = 0; i < poly2.size(); i++)
	{
		if (IsPointInPolygon(poly1, poly2[i]))
		{
			interPoly.push_back(poly2[i]);
		}
	}

	if (interPoly.size() <= 0)
		return false;

	//�㼯���� 
	ClockwiseSortPoints(interPoly);
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Mat src = imread("./color2.JPG", CV_LOAD_IMAGE_COLOR);
	Mat Retsrc = imread("./color2.JPG", CV_LOAD_IMAGE_GRAYSCALE);

	Mat planes[] = { Mat::zeros(src.size(), CV_8UC1), Mat::zeros(src.size(), CV_8UC1), Mat::zeros(src.size(), CV_8UC1)};
	split(src, planes);

	for (int i = 0; i < planes[1].rows; i++)
	{
		for (int j = 0; j < planes[1].cols; j++)
		{
			if (planes[1].at<uchar>(i, j) >= 100)
			{
				planes[1].at<uchar>(i, j) = 255;
			}
		}
	}

	for (int i = 0; i < planes[2].rows; i++)
	{
		for (int j = 0; j < planes[2].cols; j++)
		{
			if (planes[2].at<uchar>(i, j) > 100)
			{
				planes[2].at<uchar>(i, j) = 255;
			}
		}
	}

	Mat red = planes[1];
	Mat green = planes[2];

	threshold(green, green, 100, 255, THRESH_BINARY);
	green = 255 - green;
	imshow("green", green); //R
	waitKey(0);

	threshold(red, red, 100, 255, THRESH_BINARY);
	morphologyEx(red, red, MORPH_OPEN, getStructuringElement(MORPH_RECT, Size(15, 15)));
	red = 255 - red;
	imshow("red", red); //R
	waitKey(0);

	vector<vector<Point>> contours_green;
	vector<vector<Point>> contours_red;

	findContours(green, contours_green, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	Mat draw = Mat::zeros(green.size(), CV_8UC1);

	findContours(red, contours_red, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	vector<Point> contours_det;
	DWORD start = GetTickCount();
	getintersection(contours_green[0], contours_red[0], contours_det);
	DWORD end = GetTickCount();
	printf("ʱ�䣺%dms\n", (end - start));
	
	vector<vector<Point>> contours_final;
	contours_final.push_back(contours_det);
	drawContours(Retsrc, contours_final, -1, Scalar(0), CV_FILLED);

	namedWindow("Retsrc",0);
	imshow("Retsrc", Retsrc);
	waitKey(0);

	return 0;
}

