//https://imois.in/posts/card-network/

#include <vector>
#include <cmath>
#include <stdio.h>

typedef float f;typedef std::vector<f> v;
f K=0.01,R=0.01;struct L{int w,h,i;v W,x,
z;L(int i,int o){W.resize(i*o);for(f&a:W)
a=(rand()/(1.1-(1<<31))-0.5)/sqrt(i+o+0.)
;w=i;h=o;}v F(v X){x=X;v a(h);i=h*w;while
(i--)a[i/w]+=W[i]*x[i%w];z=a;for(f&i:a)i=
K>i?K:i;return a;}v B(v Y){v X(w);i=w*h;
while(i--){f Z=Y[i/w]*(z[i/w]>0?1:K);X[i%
w]+=Z*W[i];W[i]-=R*Z*x[i%w];}return X;}};
int main(){L n[]{L(40,50),L(50,50),L(50,1
)};int l,z,k,i=500337;while(i--){z=242-i%
243;k=40;v x(k),y;while(k--)x[k]=sin((k%2
?z/27/3.:z%27/5.)+6.14*k/20);y=x;for(l=0;
l<3;l++)y=n[l].F(y);v Y{2*(y[0]-("\x1e\0\
\0\b\x01\0@H\374\377B\x12@\x18\x12G\302\
\x10@\x12\372\377\221\x10\0\0\200\0\0\0\
\x02"[z/8]>>z%8&1))};while(l--)Y=n[l].B(Y
);putchar(" .,-*oO##"[(int)(y[0]*8)%9]);
if(i%27<1)puts(i?i%243?"":"\033[9A":"\r\
   --- Oisin Carroll ---\n\
 gh:Oisincar  web:imois.in");}}