#pragma once

#include<string.h>
#include"convexhull.h"

typedef int GESTURE_FLAGS;     // 当前手势符号
#define isSlide 1              // 移动标志
#define isPinch 2              // 缩放标志
#define isRotate 4             // 旋转标志
#define isTouch 8              // 单击标志
#define isInertia 16           // 模拟惯量

typedef int TOUCH_TYPE;
#define TOUCH_IDLE 0     
#define TOUCH_DOWN 1     
#define TOUCH_UP 2     
#define TOUCH_TAP 3
#define TOUCH_DOUBLETAP 4
#define TOUCH_LONG 5

#define MAX_POINT 1000                                     // 单点集点数上限
#define MAX_SET 50                                        // 点集数上限
#define MAX_TOTAL_POINT 20000                              // 总点数上限
#define MAX_P_NUM 10

#pragma pack(1)

typedef struct _POINT_INFO {   // socket接受单点信息结构
	unsigned short PointID;
	float X,Y,W,H;
} POINT_INFO, *PPOINT_INFO;

typedef struct _FRAME_INFO {   // socket接受帧信息结构
	int FrameID;
	unsigned short XLength;
	unsigned short YLength;
	float XA,XB,YA,YB;
	unsigned char XYSwap;
	unsigned char PointCount;
} FRAME_INFO, *PFRAME_INFO;

typedef struct _STATE          // 返回信息结构
{
    double x,y;                // 位移向量
	double prop;               // 变换比例
	double angle;              // 旋转角度
	TOUCH_TYPE isTouched;      // 是否被按
	double dx,dy;              // 模拟惯量
} STATE;

typedef struct _Pair_Dis       // 点对距离
{
	int x,y;
	double val;
} Pair_Dis;

typedef struct _GROUP_INFO
{
	double x,y;                // 手势中心
	double r;                  // 手势半径
	int size;                  // 手势点集大小
	unsigned short PointIDs[100];   // 手势点集点编号
	int touch_time;            // 单点不动时间
	int lasttap;               // 上一次tap到现在的时间
	GESTURE_FLAGS flags;       // 手势识别信息
	TOUCH_TYPE CurrentTouchType;
	
	// 该手势前一帧信息缓存
	double old_x,old_y;
	int old_size;
	Tpoint old_point[MAX_POINT];
	Tpoint firstpoint;
	int old_pID[MAX_POINT];

	// 模拟惯量信息缓存
	int cent_size;
	Tpoint cent_point[10];
    Tpoint direct;
	BOOL glide;
	double Cx,o_Cx;
} GROUP_INFO,*PGROUP_INFO;

#pragma pack(4)