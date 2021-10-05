t1=linspace(-4,5);
f1=5.*sin(4.*pi.*t1)+exp(t1./2);
t2=linspace(-5,4);
f2=5.*t2.^2 + 2.*t2 + sqrt(30);

t3=linspace(-2*pi,2*pi);
f3=abs(t3.^3)./10 - 10.*cos(3.*pi.*t3);
t4=linspace(-10,10);
f4=log(abs(t4.^3))+t4-2;


subplot(1,1,1)
plot(t1,f1,'r:', t2,f2,'g-.'), grid on;
figure;
subplot(2,2,1)
plot(t3,f3), xlabel('t'), ylabel('f3(t)'), grid on;
subplot(2,2,4)
plot(t4,f4), xlabel('t'), ylabel('f4(t)'), grid on;