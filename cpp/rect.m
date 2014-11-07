clc
clf
    m_Xc = 5;
    m_Yc = 5;
    width = 10;
    height=10;
    angle=pi/2;
    j=width*sin(angle)/2;
    k=height*sin(angle)/2;
    l=width*cos(angle)/2;
    m=height*cos(angle)/2;
    a(1)=m_Xc-l+k;
    b(1)=m_Xc-l-k;
    c(1)=m_Xc+l-k;
    d(1)=m_Xc+l+k; 
    a(2)=m_Yc-j-m;
    b(2)=m_Yc-j+m;
    c(2)=m_Yc+j+m;
    d(2)=m_Yc+j-m;
hold on
plot(a(1),a(2),'*r')
plot(b(1),b(2),'*r')
plot(c(1),c(2),'*r')
plot(d(1),d(2),'*r')
plot([a(1) b(1)],[a(2) b(2)])
plot([c(1) b(1)],[c(2) b(2)])
plot([a(1) d(1)],[a(2) d(2)])
plot([c(1) d(1)],[c(2) d(2)])


%**************************

    m_Xc = 5;
    m_Yc = 5;
    width = 4;
    height=2;
    angle=pi/4;
    j=width*sin(angle)/2;
    k=height*sin(angle)/2;
    l=width*cos(angle)/2;
    m=height*cos(angle)/2; 
    a(1)=m_Xc-l+k;
    b(1)=m_Xc-l-k;
    c(1)=m_Xc+l-k;
    d(1)=m_Xc+l+k; 
    a(2)=m_Yc-j-m;
    b(2)=m_Yc-j+m;
    c(2)=m_Yc+j+m;
    d(2)=m_Yc+j-m;

hold on
plot(m_Xc,m_Yc,'*g')

plot(a(1),a(2),'*r')
plot(b(1),b(2),'*r')
plot(c(1),c(2),'*r')
plot(d(1),d(2),'*r')

plot([a(1) b(1)],[a(2) b(2)])
plot([c(1) b(1)],[c(2) b(2)])
plot([a(1) d(1)],[a(2) d(2)])
plot([c(1) d(1)],[c(2) d(2)])

%**************************

p1(1)=4;
p1(2)=8;
p2(1)=8;
p2(2)=4;
plot(p1(1),p1(2),'*g')
plot(p2(1),p2(2),'*g')

x=p1(1);
y=p1(2);

t=x-m_Xc;
z=y-m_Yc;
theta=atan(t/z);
hip=(t^2+z^2)^0.5
dx=(hip*cos(theta+angle))
dy=abs(hip*sin(theta+angle))
if dx>=width/2 && dy>=height/2 
	plot(x,y,'.r')
end

x=p2(1);
y=p2(2);

t=x-m_Xc;
z=y-m_Yc;
theta=atan(t/z);
hip=(t^2+z^2)^0.5
dx=(hip*cos(theta+angle))
dy=abs(hip*sin(theta+angle))
if dx>=width/2 && dy>=height/2 
	plot(x,y,'.r')
end

axis equal