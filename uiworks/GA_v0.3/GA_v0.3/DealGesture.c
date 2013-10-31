#include"DealGesture.h"

double DtoInt(double o)
{
	double p=(int)o;
	if (o<0) p--;
	return p;
}

void DealTouch( int i , gtime gtmp , STATE *CallBack_c ,state tmp_s ,BOOL ReCal)
{
	// DoubleTap：Tap+1.5sIDLE+Down

	if ((gtmp.count!=1)||(ReCal==TRUE))
	{
		// 点数不为1
		if (ges_inf[i].touch_time>0) 
		{
			if ((gtmp.count>1))//||(ges_inf[i].touch_time<10)) 
			    {
					ges_inf[i].CurrentTouchType=CallBack_c->isTouched = TOUCH_UP;
			    }
			else 
			if (ges_inf[i].touch_time<LongTouchTime)
			{
				ges_inf[i].CurrentTouchType=CallBack_c->isTouched = TOUCH_TAP;
				//ges_inf[i].firstpoint=gtmp.buf[0];
				ges_inf[i].lasttap = -1;
			} // 形成tap
			else
			{
				ges_inf[i].CurrentTouchType=CallBack_c->isTouched = TOUCH_IDLE;
				ges_inf[i].touch_time = 0;
			}
		}
		else 
		{
			ges_inf[i].CurrentTouchType=CallBack_c->isTouched = TOUCH_IDLE;
		}
		ges_inf[i].touch_time=0;
		if (ges_inf[i].lasttap<=DoubleTouchTime) {
			if ((gtmp.count==0))
			{
				ges_inf[i].lasttap++;
			} else
			{
				ges_inf[i].lasttap = 10000;
			}}else
			{
				ges_inf[i].lasttap = 10000;
			}
	} else
	{
		// 如果Touch计时已经开始
 	    if (ges_inf[i].touch_time>0) 
	    {
			//double x=(int)(tmp_s.cent.x * (ScreenWidth - 1));
			//double y=(int)(tmp_s.cent.y * (ScreenHeight - 1));
			//if (fabs(ges_inf[i].old_x-x)+fabs(ges_inf[i].old_y-y)<1e-5)
			double x = ges_inf[i].firstpoint.ox;
			double y = ges_inf[i].firstpoint.oy;
			if (fabs(x-gtmp.buf[0].ox)+fabs(y-gtmp.buf[0].oy)<2.1)
			{
				// 如果点没有移动，则进行计时
	            ges_inf[i].old_x = DtoInt(tmp_s.cent.x * (ScreenWidth - 1));
	            ges_inf[i].old_y = DtoInt(tmp_s.cent.y * (ScreenHeight - 1));
				if (ges_inf[i].touch_time>=LongTouchTime) 
				{
					// 超时
					//if (ges_inf[i].touch_time == LongTouchTime) 
					if ((ges_inf[i].CurrentTouchType==TOUCH_LONG)||(ges_inf[i].CurrentTouchType==TOUCH_DOUBLETAP)) 
					{
						CallBack_c->isTouched=ges_inf[i].CurrentTouchType;
					}
					else
					{    ges_inf[i].CurrentTouchType=TOUCH_LONG;
						  CallBack_c->isTouched=TOUCH_LONG;
					      ges_inf[i].touch_time=LongTouchTime+1;
					}
				} else 
				{
					// 目前按下中
					ges_inf[i].CurrentTouchType=CallBack_c->isTouched=TOUCH_DOWN;
					ges_inf[i].touch_time++;
				}
			} else
			{
				// 点移动/放开
				ges_inf[i].CurrentTouchType=CallBack_c->isTouched = TOUCH_UP;
		        ges_inf[i].touch_time=0;
			}
		} else 
		if (ges_inf[i].old_size==0)
		{
			// Touch计时开始
			if ((ges_inf[i].lasttap<=DoubleTouchTime)
				&&(fabs(ges_inf[i].firstpoint.ox-gtmp.buf[0].ox)+fabs(ges_inf[i].firstpoint.oy-gtmp.buf[0].oy)<5.1))
			{
				CallBack_c->isTouched = TOUCH_DOUBLETAP;
				ges_inf[i].CurrentTouchType = TOUCH_DOUBLETAP;
			    ges_inf[i].touch_time=LongTouchTime+1;
				ges_inf[i].lasttap = 10000;
			}
			else 
			{
				ges_inf[i].CurrentTouchType=CallBack_c->isTouched = TOUCH_DOWN;
			    ges_inf[i].touch_time=1;
				ges_inf[i].firstpoint=gtmp.buf[0];
				ges_inf[i].lasttap = 10000;
			}
	        ges_inf[i].old_x = DtoInt(tmp_s.cent.x * (ScreenWidth - 1));
	        ges_inf[i].old_y = DtoInt(tmp_s.cent.y * (ScreenHeight - 1));
		} else 
		{
			ges_inf[i].CurrentTouchType=CallBack_c->isTouched = TOUCH_IDLE;
		}
	}
}

void DealSlide( int i , gtime gtmp , STATE *CallBack_c ,state tmp_s ,BOOL ReCal)
{   
	if (gtmp.count==0)
	{
		// 当前帧无点
		CallBack_c->x=CallBack_c->y=0;
		ges_inf[i].old_x=ges_inf[i].old_y=0;
	} else
	if (ReCal==TRUE)
	{	
		// 获取初始位置
	    ges_inf[i].old_x=DtoInt(tmp_s.cent.x * (ScreenWidth - 1));
	    ges_inf[i].old_y=DtoInt(tmp_s.cent.y * (ScreenHeight - 1));
	    CallBack_c->x=CallBack_c->y=0;
	} else
	if (ges_inf[i].old_size==gtmp.count) 
	{
		// 计算移动位移
	    CallBack_c->x=DtoInt(tmp_s.cent.x * (ScreenWidth - 1))-ges_inf[i].old_x;
	    CallBack_c->y=DtoInt(tmp_s.cent.y * (ScreenHeight - 1))-ges_inf[i].old_y;
	    ges_inf[i].old_x = DtoInt(tmp_s.cent.x * (ScreenWidth - 1));
	    ges_inf[i].old_y = DtoInt(tmp_s.cent.y * (ScreenHeight - 1));
	}
    else
	{
		// 获取初始位置
	    ges_inf[i].old_x=DtoInt(tmp_s.cent.x * (ScreenWidth - 1));
	    ges_inf[i].old_y=DtoInt(tmp_s.cent.y * (ScreenHeight - 1));
	    CallBack_c->x=CallBack_c->y=0;
    }
}

void DealPinch( int i , gtime gtmp , STATE *CallBack_c ,state tmp_s ,BOOL ReCal)
{
	if ((gtmp.count<2)||(ReCal==TRUE))
	{
		// 当前点过少
		CallBack_c->prop=1.0;
		if (gtmp.count>=2) ges_inf[i].r=tmp_s.r;
	} else
	{
		// 计算当前缩放比例
		if (tmp_s.r<1e-3) {CallBack_c->prop=1.0;} else
		if (ges_inf[i].old_size<2)
		{
			// 新手势
			ges_inf[i].r=tmp_s.r;
		    CallBack_c->prop=1.0;
		} else 
		{
			// 计算比例
			CallBack_c->prop=tmp_s.r/ges_inf[i].r;
			ges_inf[i].r=tmp_s.r;
		}
	}
}

// 距离
double dist(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

// 叉积
double p_mul(double x1,double y1,double x2,double y2)
{
	if ((dist(x1,y1,0,0)<1e-10)||(dist(x2,y2,0,0)<1e-10)) return 0;
	return (x1*y2-x2*y1)/(dist(x1,y1,0,0)*dist(x2,y2,0,0));
}

void DealRotate( int i , gtime gtmp , STATE *CallBack_c ,state tmp_s ,BOOL ReCal)
{
	double tmp_r;
	double ang=0;
	int j,k,l;

	// 进行最近点匹配
	/*
	for (j=0;j<gtmp.count;j++)
	{
		tmp_r=1000000;
		for (k=0;k<ges_inf[i].old_size;k++)
		if (dist(ges_inf[i].old_point[k].x
			    ,ges_inf[i].old_point[k].y
				,gtmp.buf[j].x,gtmp.buf[j].y)<tmp_r)
		{
			tmp_r=dist(ges_inf[i].old_point[k].x,ges_inf[i].old_point[k].y,gtmp.buf[j].x,gtmp.buf[j].y);
			l=k;
		}
		    // 偏移角累加
			ang+=asin(p_mul(ges_inf[i].old_point[l].x-tmp_s.cent.x//ges_inf[i].x
				           ,ges_inf[i].old_point[l].y-tmp_s.cent.y//ges_inf[i].y
						   ,gtmp.buf[j].x-tmp_s.cent.x
						   ,gtmp.buf[j].y-tmp_s.cent.y));
	}
	*/

	if ((ges_inf[i].old_size==2)&&(gtmp.count==2)&&(ReCal==FALSE))
	{
		ang=asin(p_mul(ges_inf[i].old_point[1].x-ges_inf[i].old_point[0].x
			          ,ges_inf[i].old_point[1].y-ges_inf[i].old_point[0].y
					  ,gtmp.buf[1].x-gtmp.buf[0].x
					  ,gtmp.buf[1].y-gtmp.buf[0].y));
	}

	// 计算平均偏移角
	//ang/=(double)gtmp.count;
	CallBack_c->angle=ang;
}

void DealInertia( int i , gtime gtmp , STATE *CallBack_c ,state tmp_s ,BOOL ReCal)
{
	if (gtmp.count==0)
	{
		// 当前帧无点
		if (ges_inf[i].glide==FALSE)
		{
			if (ges_inf[i].cent_size<2)
			{
		        CallBack_c->x=CallBack_c->y=0;
		        ges_inf[i].old_x=ges_inf[i].old_y=0;
			} 
			else
			{
				double dx,dy,tmpdist;
				double len=0,ang=0;
				int j;
				ges_inf[i].glide=TRUE;
				for (j=1;j<ges_inf[i].cent_size;j++) 
					len+=dist(ges_inf[i].cent_point[j].x,ges_inf[i].cent_point[j].y
					         ,ges_inf[i].cent_point[j-1].x,ges_inf[i].cent_point[j-1].y);
				for (j=2;j<ges_inf[i].cent_size;j++) 
					ang+=p_mul(ges_inf[i].cent_point[j].x-ges_inf[i].cent_point[j-1].x,ges_inf[i].cent_point[j].y-ges_inf[i].cent_point[j-1].y
					          ,ges_inf[i].cent_point[j-1].x-ges_inf[i].cent_point[j-2].x,ges_inf[i].cent_point[j-1].y-ges_inf[i].cent_point[j-2].y);
				len/=(double)(ges_inf[i].cent_size-1);
				ang/=(double)(ges_inf[i].cent_size-2);
				ges_inf[i].direct.x=ges_inf[i].cent_point[ges_inf[i].cent_size-1].x-ges_inf[i].cent_point[ges_inf[i].cent_size-2].x;
				ges_inf[i].direct.y=ges_inf[i].cent_point[ges_inf[i].cent_size-1].y-ges_inf[i].cent_point[ges_inf[i].cent_size-2].y;
				tmpdist=dist(0,0,ges_inf[i].direct.x,ges_inf[i].direct.y);
				ges_inf[i].direct.x*=len/tmpdist;
				ges_inf[i].direct.y*=len/tmpdist;
				dx=ges_inf[i].direct.x*cos(ang)+ges_inf[i].direct.y*sin(ang);
				dy=-ges_inf[i].direct.x*sin(ang)+ges_inf[i].direct.y*cos(ang);
				ges_inf[i].direct.x=dx;
				ges_inf[i].direct.y=dy;
				ges_inf[i].Cx = ges_inf[i].o_Cx;
				//dx=(int)(dx * (ScreenWidth - 1));
				//dy=(int)(dy * (ScreenHeight - 1));
		        CallBack_c->x=CallBack_c->y=0;
				CallBack_c->dx=dx;
				CallBack_c->dy=dy;
			}
		} else
		{
			double len,ol,da,lx,t,ux,uy;
			ges_inf[i].Cx*=(1+ges_inf[i].Cx/100.0);
		    CallBack_c->x=CallBack_c->y=0;
			CallBack_c->dx=ges_inf[i].direct.x;//(int)(ges_inf[i].direct.x * (ScreenWidth - 1));
			CallBack_c->dy=ges_inf[i].direct.y;//(int)(ges_inf[i].direct.y * (ScreenHeight - 1));
			len=sqrt(ges_inf[i].direct.x*ges_inf[i].direct.x+ges_inf[i].direct.y*ges_inf[i].direct.y);
			ol=len;
			da=len*ges_inf[i].Cx;
			lx=(len-da);
			if (lx*len<0.0) {lx=0.0;da=len;}
			t=(len*len-lx*lx)/(2.0*da);
			/*
			{
				double da=ges_inf[i].direct.x*ges_inf[i].Cx;
				//if (fabs(da)>1e-15) 
				{
					double lx=(ges_inf[i].direct.x-da);
					if (lx*ges_inf[i].direct.x<0.0) {lx=0.0;da=ges_inf[i].direct.x;}
				    CallBack_c->x=(ges_inf[i].direct.x*ges_inf[i].direct.x-lx*lx)/(2.0*da);
				} //else CallBack_c->x=ges_inf[i].direct.x;
				ges_inf[i].old_x+=CallBack_c->x;
				//ges_inf[i].direct.x-=da;
			}
			{
				double da=ges_inf[i].direct.y*ges_inf[i].Cx;
				//if (fabs(da)>1e-15) 
				{
					double ly=(ges_inf[i].direct.y-da);
					if (ly*ges_inf[i].direct.y<0.0) {ly=0.0;da=ges_inf[i].direct.y;}
				    CallBack_c->y=(ges_inf[i].direct.y*ges_inf[i].direct.y-ly*ly)/(2.0*da);
				} //else CallBack_c->y=ges_inf[i].direct.y;
				ges_inf[i].old_y+=CallBack_c->y;
				//ges_inf[i].direct.y-=da;
			}*/
			//ges_inf[i].Cx*=(1+ges_inf[i].Cx/100.0);
			len=len*(1.0-ges_inf[i].Cx)*(1.0-ges_inf[i].Cx);
			//if (len<0) len=0;
			CallBack_c->x=t*ges_inf[i].direct.x/ol;
			CallBack_c->y=t*ges_inf[i].direct.y/ol;
			ges_inf[i].direct.x=ges_inf[i].direct.x*(1.0-ges_inf[i].Cx);
			ges_inf[i].direct.y=ges_inf[i].direct.y*(1.0-ges_inf[i].Cx);
			ux=DtoInt(ges_inf[i].old_x);
			uy=DtoInt(ges_inf[i].old_y);
			ges_inf[i].old_x+=CallBack_c->x * (ScreenWidth - 1);
			ges_inf[i].old_y+=CallBack_c->y * (ScreenHeight - 1);
			CallBack_c->x=DtoInt(ges_inf[i].old_x-ux);
			CallBack_c->y=DtoInt(ges_inf[i].old_y-uy);
			/*
		    if (ges_inf[i].direct.x!=0)
			{
				double da=ges_inf[i].direct.x*ges_inf[i].Cx;
				if (fabs(da)>1e-10) 
				{
					double lx=(ges_inf[i].direct.x-da);
					if (lx*ges_inf[i].direct.x<0.0) {lx=0.0;da=ges_inf[i].direct.x;}
				    CallBack_c->x=(ges_inf[i].direct.x*ges_inf[i].direct.x-lx*lx)/(2.0*da);
				} else CallBack_c->x=ges_inf[i].direct.x;
				ges_inf[i].old_x+=CallBack_c->x;
				ges_inf[i].direct.x-=da;
			}
		    if (ges_inf[i].direct.y!=0)
			{
				double da=ges_inf[i].direct.y*ges_inf[i].Cx;
				if (fabs(da)>1e-10) 
				{
					double ly=(ges_inf[i].direct.y-da);
					if (ly*ges_inf[i].direct.y<0.0) {ly=0.0;da=ges_inf[i].direct.y;}
				    CallBack_c->y=(ges_inf[i].direct.y*ges_inf[i].direct.y-ly*ly)/(2.0*da);
				} else CallBack_c->y=ges_inf[i].direct.y;
				ges_inf[i].old_y+=CallBack_c->y;
				ges_inf[i].direct.y-=da;
			}*/
		}
	} else
	if (ReCal==TRUE)
	{	
		// 获取初始位置
	    ges_inf[i].old_x=DtoInt(tmp_s.cent.x * (ScreenWidth - 1));
	    ges_inf[i].old_y=DtoInt(tmp_s.cent.y * (ScreenHeight - 1));
	    CallBack_c->x=CallBack_c->y=0;
		ges_inf[i].cent_size = 1;
		ges_inf[i].cent_point[0].x=tmp_s.cent.x;
		ges_inf[i].cent_point[0].y=tmp_s.cent.y;
		ges_inf[i].glide=FALSE;
	} else
	if (ges_inf[i].old_size==gtmp.count) 
	{
		// 计算移动位移
	    CallBack_c->x=DtoInt(tmp_s.cent.x * (ScreenWidth - 1))-ges_inf[i].old_x;
	    CallBack_c->y=DtoInt(tmp_s.cent.y * (ScreenHeight - 1))-ges_inf[i].old_y;
	    ges_inf[i].old_x = DtoInt(tmp_s.cent.x * (ScreenWidth - 1));
	    ges_inf[i].old_y = DtoInt(tmp_s.cent.y * (ScreenHeight - 1));
		
		if (
			(ges_inf[i].cent_size==0)
		  ||(fabs(ges_inf[i].cent_point[ges_inf[i].cent_size-1].x-ges_inf[i].old_x)+fabs(ges_inf[i].cent_point[ges_inf[i].cent_size-1].y-ges_inf[i].old_y)>-0.1))
		if (ges_inf[i].cent_size==MAX_P_NUM) 
		{
			int j;
			for (j=1;j<MAX_P_NUM;j++) ges_inf[i].cent_point[j-1]=ges_inf[i].cent_point[j];
			ges_inf[i].cent_point[MAX_P_NUM-1].x=tmp_s.cent.x;
			ges_inf[i].cent_point[MAX_P_NUM-1].y=tmp_s.cent.y;
		} else 
		{
			ges_inf[i].cent_point[ges_inf[i].cent_size].x=tmp_s.cent.x;
			ges_inf[i].cent_point[ges_inf[i].cent_size++].y=tmp_s.cent.y;
		}
	}
    else
		if (ges_inf[i].glide==FALSE)
	    {
		    // 获取初始位置
	        ges_inf[i].old_x=DtoInt(tmp_s.cent.x * (ScreenWidth - 1));
	        ges_inf[i].old_y=DtoInt(tmp_s.cent.y * (ScreenHeight - 1));
	        CallBack_c->x=CallBack_c->y=0;
			if ((ges_inf[i].cent_size==0)
		  ||(fabs(ges_inf[i].cent_point[ges_inf[i].cent_size-1].x-ges_inf[i].old_x)+fabs(ges_inf[i].cent_point[ges_inf[i].cent_size-1].y-ges_inf[i].old_y)>-0.1))
			{
		        //ges_inf[i].cent_point[ges_inf[i].cent_size].x=tmp_s.cent.x;
			    //ges_inf[i].cent_point[ges_inf[i].cent_size++].y=tmp_s.cent.y;
				if (ges_inf[i].cent_size==MAX_P_NUM) 
		        {
		        	int j;
			        for (j=1;j<MAX_P_NUM;j++) ges_inf[i].cent_point[j-1]=ges_inf[i].cent_point[j];
			        ges_inf[i].cent_point[MAX_P_NUM-1].x=tmp_s.cent.x;
			        ges_inf[i].cent_point[MAX_P_NUM-1].y=tmp_s.cent.y;
		        } else 
		        {
			        ges_inf[i].cent_point[ges_inf[i].cent_size].x=tmp_s.cent.x;
			        ges_inf[i].cent_point[ges_inf[i].cent_size++].y=tmp_s.cent.y;
		        }
			}
        }
		else
		{	
		    // 获取初始位置
	        ges_inf[i].old_x=DtoInt(tmp_s.cent.x * (ScreenWidth - 1));
	        ges_inf[i].old_y=DtoInt(tmp_s.cent.y * (ScreenHeight - 1));
	        CallBack_c->x=CallBack_c->y=0;
		    ges_inf[i].cent_size = 1;
		    ges_inf[i].cent_point[0].x=tmp_s.cent.x;
		    ges_inf[i].cent_point[0].y=tmp_s.cent.y;
		    ges_inf[i].glide=FALSE;
	    }
}