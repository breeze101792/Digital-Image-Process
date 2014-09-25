inline int round(double s)
{
	if(s>=0) s=s+0.5; else s=s-0.5;
	return((int)s);
}

inline int clip(double s)
{
	if(s>255) s=255;
	if(s<0)   s=0;
	if(s>=0)  s=s+0.5; else s=s-0.5;
	return((int)s);
}

void copy(int *f,int w,int h,int *g)
{
int i,j;

for(j=0;j<h;j++)
   {
   for(i=0;i<w;i++)
      {
      *g++=*f++;
      }
   }
}

void block_get(int *f,int wf,int hf,int *b,int wb,int hb,int i0,int j0)
{
int i,j;
int *ptf,wdiff;

ptf=f+i0+j0*wf;
wdiff=wf-wb;
for(j=0;j<hb;j++)
   {
   for(i=0;i<wb;i++)
      *b++=*ptf++;
   ptf+=wdiff;
   }
}

void block_put(int *b,int wb,int hb,int *g,int wg,int hg,int i0,int j0)
{
int i,j;

for(j=0;j<hb;j++)
   for(i=0;i<wb;i++)
      g[(i+i0)+((j+j0)*wg)]=b[i+(j*wb)];
}

void contrast_bright(int *f,int w,int h,double p,double q)
{
int i,j;
int pint,qint;

pint=p*65536;
qint=q*65536;

for(j=0;j<h;j++)
   {
   for(i=0;i<w;i++)
      {
//      tmpint=(p*(*f)+q)/65536;
//      if(tmpint<0) tmpint=0;
//      if(tmpint>255) tmpint=255;
//      *f=tmpint;
      *f=clip(p*(*f)+q);
      f++;
      }
   }
}

void contrast(int *f,int w,int h,int *g,double p)
{
int i,j;

for(j=0;j<h;j++)
   {
   for(i=0;i<w;i++)
      {
      *g++=clip(1.*(*f++)*p);
      }
   }
}

void bright(int *f,int w,int h,int *g, int q)
{
int i,j;

for(j=0;j<h;j++)
   {
   for(i=0;i<w;i++)
      {
      *g++=clip((*f++)+q);
      }
   }
}

void contrast(int *f,int w,int h,double p)
{
int *g;

g=new int[w*h];
contrast(f,w,h,g,p);
copy(g,w,h,f);
delete g;
}

void bright(int *f,int w,int h,int q)
{
int *g;

g=new int[w*h];
bright(f,w,h,g,q);
copy(g,w,h,f);
delete g;
}

int SE(int *f,int w,int h,int *g)
{
int i,j;
int tmpint;
int sum;

sum=0;
for(j=0;j<h;j++)
   {
   for(i=0;i<w;i++)
      {
      tmpint=(*f++)-(*g++);
      sum+=tmpint*tmpint;
      }
   }
return sum;
}

double MSE(int *f,int w,int h,int *g)
{
return(((double)SE(f,w,h,g))/w/h);
}

