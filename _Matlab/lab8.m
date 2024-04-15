%M-file to plot the terminal characteristics of the generator of Example 5-4 with lagging load. 
%First , initialize the current amplitudes (21 values 
%in the range 0-60 A) 
i_a = (0:1:20)* 3; 

% Now initialize all other values 
v_phase1 = zeros(1,21); 
v_phase2 = zeros(1,21); 
v_phase3 = zeros(1,21); 
v_phase4 = zeros(1,21); 
e_a = 277.0; 
x_s = 1.0; 
theta1 = 78.46 *(pi/180) ;% pf=0.2x
theta2 = 66.42 *(pi/180) ;% pf=0.4
theta3 = 53.13 *(pi/180) ;% pf=0.6
theta4 = 36.87 *(pi/180) ;% pf=0.6

% Now calculate v-phase for each current level 
for ii = 1:21
    v_phase1(ii)=sqrt(e_a^2 -(x_s * i_a(ii) * cos(theta1))^2)....
                           -(x_s * i_a(ii) * sin(theta1));

end

for ii = 1:21
    v_phase2(ii)=sqrt(e_a^2 -(x_s * i_a(ii) * cos(theta2))^2)....
                           -(x_s * i_a(ii) * sin(theta2));
end

for ii = 1:21
    v_phase3(ii)=sqrt(e_a^2 -(x_s * i_a(ii) * cos(theta3))^2)....
                           -(x_s * i_a(ii) * sin(theta3));
end

for ii = 1:21
    v_phase4(ii)=sqrt(e_a^2 -(x_s * i_a(ii) * cos(theta4))^2)....
                           -(x_s * i_a(ii) * sin(theta4));
end

%calculate terminal Voltage from phase voltage
v_t1=sqrt(3)*v_phase1;
v_t2=sqrt(3)*v_phase2;
v_t3=sqrt(3)*v_phase3;
v_t4=sqrt(3)*v_phase4;
%plot the terminal charecteristics, remembering the line current is same
%as i_a
plot(i_a,v_t1,'Color','b',LineWidth=2.0);
hold on
plot(i_a,v_t2,'Color','r',LineWidth=2.0);
plot(i_a,v_t3,'Color','g',LineWidth=2.0);
plot(i_a,v_t4,'Color','y',LineWidth=2.0);

ylabel('terminal Volatge(V)', 'Fontweight','bold');
xlabel('Line current (A)','Fontweight','bold' );
title('Terminal Charecteristics for a load ','Fontweight','bold');
grid on;
axis([0 60 400 550])
