#include "ConvexPolyCross.h"


line ConvexPolygenCross::GetLine(point p1,point p2)
{
    line Ans;
    if (p2.getY()>p1.getY())
    {
        Ans.x1=p1.getX();Ans.y1=p1.getY();
        Ans.x2=p2.getX();Ans.y2=p2.getY();
        Ans.dir=false;
    } else
    if (p2.getY()<p1.getY())
    {
        Ans.x2=p1.getX();Ans.y2=p1.getY();
        Ans.x1=p2.getX();Ans.y1=p2.getY();
        Ans.dir=true;
    } else
    {
        if (p2.getX()>p1.getX())
        {
            Ans.x1=p1.getX();Ans.y1=p1.getY();
            Ans.x2=p2.getX();Ans.y2=p2.getY();
            Ans.dir=false;
        } else
        {
            Ans.x2=p1.getX();Ans.y2=p1.getY();
            Ans.x1=p2.getX();Ans.y1=p2.getY();
            Ans.dir=true;
        }
    }
    return Ans;
}

vector< point > ConvexPolygenCross::getCPC(vector< point > Cov1,vector< point >Cov2)
{
    vector< point > Ans;Ans.clear();
	if (Cov2.size()*Cov1.size()==0) return Ans;
    vector< line > hL;hL.clear();
    for (int i=0;i<Cov1.size();i++)
    if (i==Cov1.size()-1) hL.push_back(GetLine(Cov1[i],Cov1[0]));
    else hL.push_back(GetLine(Cov1[i],Cov1[i+1]));
    for (int i=0;i<Cov2.size();i++)
    if (i==Cov2.size()-1) hL.push_back(GetLine(Cov2[i],Cov2[0]));
    else hL.push_back(GetLine(Cov2[i],Cov2[i+1]));
    sort(hL.begin(),hL.end());
    vector< line > uC,lC;uC.clear();lC.clear();
    for (int i=0;i<hL.size();i++)
    if (((hL[i].dir)&&(hL[i].x2>hL[i].x1))||((!hL[i].dir)&&(hL[i].x2<hL[i].x1))) uC.push_back(hL[i]);
    else lC.push_back(hL[i]);
    int j=0;
    while ((j<lC.size())&&(!lC[j].dir)) j++;
	if (lC.size()==0)
	{
		int o=0;
	}
    if (j>0) reverse(lC.begin(),lC.begin()+j);
    if (j<lC.size()) reverse(lC.begin()+j,lC.end());
    vector< line > uCP = GetHalfPoly(uC,true), lCP = GetHalfPoly(lC,false);
	if ((lCP.size()==0)||(uCP.size()==0)) return Ans;
    int us=0,ut=uCP.size()-1,ls=0,lt=lCP.size()-1;

    if (lCP[ls].x1==lCP[ls].x2)
    {
        while (ut>us)
        {
            point la=lCP[ls].CrossPoint(lCP[ls+1]),ua=uCP[us].CrossPoint(uCP[us+1]);
            if (!la.xless(ua)) break;
            us++;
        }
        if (lt>ls)
        {
            point la=lCP[ls].CrossPoint(lCP[ls+1])
                 ,aa=uCP[us].CrossPoint(lCP[ls]);
            if (aa.yless(la)) ls++;
        }
    }
    if (lCP[lt].x1==lCP[lt].x2)
    {
        while (ut>us)
        {
            point la=lCP[lt].CrossPoint(lCP[lt-1]),ua=uCP[ut].CrossPoint(uCP[ut-1]);
            if (la.xless(ua)) break;
            ut--;
        }
        if (lt>ls)
        {
            point la=lCP[lt].CrossPoint(lCP[lt-1])
                 ,aa=uCP[ut].CrossPoint(lCP[lt]);
            if (aa.yless(la)) lt--;
        }
    }

    while ((lt>ls)&&(ut>us))
    {
		if (lCP[lt].checkPal(uCP[ut])) return Ans;
        point la=lCP[lt].CrossPoint(lCP[lt-1]),ua=uCP[ut].CrossPoint(uCP[ut-1]),
              aa=lCP[lt].CrossPoint(uCP[ut]);
        if ((!la.xless(aa))&(!ua.xless(aa))) break;
        if (la.xless(aa)) lt--;
        if (ua.xless(aa)) ut--;
    }
    while ((lt>ls)&&(ut>us))
    {
		if (lCP[ls].checkPal(uCP[us])) return Ans;
        point la=lCP[ls].CrossPoint(lCP[ls+1]),ua=uCP[us].CrossPoint(uCP[us+1]),
              aa=lCP[ls].CrossPoint(uCP[us]);
        if ((!aa.xless(la))&&(!aa.xless(ua))) break;
        if (aa.xless(la)) ls++;
        if (aa.xless(ua)) us++;
    }
    if (lt>ls)
    {
		if (lCP[lt].checkPal(uCP[ut])) return Ans;
        point la=lCP[lt].CrossPoint(lCP[lt-1]),
              aa=lCP[lt].CrossPoint(uCP[ut]);
        if (!aa.xless(la)) return Ans;
        while ((lt>ls))
        {
		    if (lCP[lt].checkPal(uCP[ut])) return Ans;
            point la=lCP[lt].CrossPoint(lCP[lt-1]),
                  aa=lCP[lt].CrossPoint(uCP[ut]);
            if (aa.xless(la)) break;
            if (!aa.xless(la)) lt--;
        }
        while ((lt>ls))
        {
		    if (lCP[ls].checkPal(uCP[us])) return Ans;
            point la=lCP[ls].CrossPoint(lCP[ls+1]),
                  aa=lCP[ls].CrossPoint(uCP[us]);
            if ((la.xless(aa))) break;
            if (!la.xless(aa)) ls++;
        }

    } else
	if (ut>us)
    {
		if (lCP[lt].checkPal(uCP[ut])) return Ans;
        point ua=uCP[ut].CrossPoint(uCP[ut-1]),
              aa=lCP[lt].CrossPoint(uCP[ut]);
        if (!aa.xless(ua)) return Ans;
        while ((ut>us))
        {
		    if (lCP[lt].checkPal(uCP[ut])) return Ans;
            point ua=uCP[ut].CrossPoint(uCP[ut-1]),
                  aa=lCP[lt].CrossPoint(uCP[ut]);
            if (aa.xless(ua)) break;
            if (!aa.xless(ua)) ut--;
        }
        while ((ut>us))
        {
		    if (lCP[ls].checkPal(uCP[us])) return Ans;
            point ua=uCP[us].CrossPoint(uCP[us+1]),
                  aa=lCP[ls].CrossPoint(uCP[us]);
            if ((ua.xless(aa))) break;
            if (!ua.xless(aa)) us++;
        }
    }

    Ans.push_back(lCP[lt].CrossPoint(uCP[ut]));
    for (int i=lt;i>ls;i--) Ans.push_back(lCP[i].CrossPoint(lCP[i-1]));
    Ans.push_back(lCP[ls].CrossPoint(uCP[us]));
    for (int i=us;i<ut;i++) Ans.push_back(uCP[i].CrossPoint(uCP[i+1]));
    return Ans;
}


bool ConvexPolygenCross::checkLin(line a,line b,bool up)
{
    if (a.x2==a.x1) return (((a.dir)&&(a.x1>b.x1))||((!a.dir)&&(a.x1<b.x1)));
    if (a.y2==a.y1) return (((up)&&(a.y2<b.y2))||((!up)&&(a.y2>b.y2)));
    bool ans=((b.x2-b.x1)*((a.x2-a.x1)*a.y1+a.x1*(a.y1-a.y2))
            ==(a.x2-a.x1)*((b.x2-b.x1)*b.y1+b.x1*(b.y1-b.y2)));
    if (!up) ans=(!ans);
    return ans;
}

bool ConvexPolygenCross::checkPLeft(line a,line b,line c)
{
    point a1=a.CrossPoint(b),a2=b.CrossPoint(c);
    return a1.xless(a2);
}

vector< line > ConvexPolygenCross::GetHalfPoly(vector< line > C,bool mark)
{
    vector< line > Ans;Ans.clear();
	Ans.push_back(C[0]);
    for (int i=1;i<C.size();i++)
    {
        while ((Ans.size()>0)&&
               (((C[i].checkPal(Ans[Ans.size()-1]))&&(checkLin(C[i],Ans[Ans.size()-1],mark)))
              ||((!C[i].checkPal(Ans[Ans.size()-1]))&&(Ans.size()>1)&&(!checkPLeft(C[i],Ans[Ans.size()-1],Ans[Ans.size()-2]))))
               ) Ans.pop_back();
		if ((Ans.size()==0)&&(C[i].x1==C[i].x2)&&(C[i].dir)) return Ans;
		if ((Ans.size()==0)||(!C[i].checkPal(Ans[Ans.size()-1]))) Ans.push_back(C[i]);
    }
    return Ans;
}
