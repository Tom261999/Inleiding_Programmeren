clear, close all;

%Data
iter_50 = [1 , 26 ;
2 , 14.92307692 ;
3 , 10.81205393 ;
4 , 10.0304952 ;
5 , 10.00004636 ;
6 , 10];

iter_1 = [1 , 50.5 ;
2 , 26.24009901 ;
3 , 15.02553012 ;
4 , 10.84043467 ;
5 , 10.03257851 ;
6 , 10.0000529 ;
7 , 10];

% Parabolische Curve Fits

p_50 = polyfit(iter_50(:,1),iter_50(:,2),2);
p_1 = polyfit(iter_1(:,1),iter_1(:,2),2);

x_50 = linspace(1,iter_50(end,1));
y_50 = polyval(p_50,x_50,25);

x_1 = linspace(1,iter_1(end,1));
y_1 = polyval(p_1,x_1,25);


% Plots

figure(1)
subplot(2,1,1);

plot(iter_50(:,1),iter_50(:,2),'b.','Markersize',12), hold on
grid on, xlabel('Iteratie'), ylabel('Gevonden waarde')
title('Startwaarde = 50')
plot(x_50,y_50,'r--')
legend('data','2de graads fit')

subplot(2,1,2);
plot(iter_1(:,1),iter_1(:,2),'b.','Markersize',12), hold on
grid on, xlabel('Iteratie'), ylabel('Gevonden waarde')
title('Startwaarde = 1')
plot(x_1,y_1,'r--')
legend('data','2de graads fit')