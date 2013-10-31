#pragma once

#include<string.h>
#include"convexhull.h"

typedef int GESTURE_FLAGS;     // ��ǰ���Ʒ���
#define isSlide 1              // �ƶ���־
#define isPinch 2              // ���ű�־
#define isRotate 4             // ��ת��־
#define isTouch 8              // ������־
#define isInertia 16           // ģ�����

typedef int TOUCH_TYPE;
#define TOUCH_IDLE 0     
#define TOUCH_DOWN 1     
#define TOUCH_UP 2     
#define TOUCH_TAP 3
#define TOUCH_DOUBLETAP 4
#define TOUCH_LONG 5

#define MAX_POINT 1000                                     // ���㼯��������
#define MAX_SET 50                                        // �㼯������
#define MAX_TOTAL_POINT 20000                              // �ܵ�������
#define MAX_P_NUM 10

#pragma pack(1)

typedef struct _POINT_INFO {   // socket���ܵ�����Ϣ�ṹ
	unsigned short PointID;
	float X,Y,W,H;
} POINT_INFO, *PPOINT_INFO;

typedef struct _FRAME_INFO {   // socket����֡��Ϣ�ṹ
	int FrameID;
	unsigned short XLength;
	unsigned short YLength;
	float XA,XB,YA,YB;
	unsigned char XYSwap;
	unsigned char PointCount;
} FRAME_INFO, *PFRAME_INFO;

typedef struct _STATE          // ������Ϣ�ṹ
{
    double x,y;                // λ������
	double prop;               // �任����
	double angle;              // ��ת�Ƕ�
	TOUCH_TYPE isTouched;      // �Ƿ񱻰�
	double dx,dy;              // ģ�����
} STATE;

typedef struct _Pair_Dis       // ��Ծ���
{
	int x,y;
	double val;
} Pair_Dis;

typedef struct _GROUP_INFO
{
	double x,y;                // ��������
	double r;                  // ���ư뾶
	int size;                  // ���Ƶ㼯��С
	unsigned short PointIDs[100];   // ���Ƶ㼯����
	int touch_time;            // ���㲻��ʱ��
	int lasttap;               // ��һ��tap�����ڵ�ʱ��
	GESTURE_FLAGS flags;       // ����ʶ����Ϣ
	TOUCH_TYPE CurrentTouchType;
	
	// ������ǰһ֡��Ϣ����
	double old_x,old_y;
	int old_size;
	Tpoint old_point[MAX_POINT];
	Tpoint firstpoint;
	int old_pID[MAX_POINT];

	// ģ�������Ϣ����
	int cent_size;
	Tpoint cent_point[10];
    Tpoint direct;
	BOOL glide;
	double Cx,o_Cx;
} GROUP_INFO,*PGROUP_INFO;

#pragma pack(4)