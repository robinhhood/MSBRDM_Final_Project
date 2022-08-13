%This file was automatically generated by the function --Generate_DifFK--
%The input vector is:
%u=[q1 q2 q3 qp1 qp2 qp3 L1 L3 L8 L2 L4 L5 L6 ]
function Xp=DifFK_ur10_3DOF(u)
q1=u(1);
q2=u(2);
q3=u(3);
qp1=u(4);
qp2=u(5);
qp3=u(6);
%Kinematic Parameters
L1=u(7);
L2=u(8);
L4=u(9);
L6=u(10);
L7=u(11);
L9=u(12);
L3=u(13);
L5=u(14);
L8=u(15);
L10=u(16);

% Joint velocities

Qp = [qp1; qp2; qp3];

% THETA ALPHA a d
DH = [q1, -pi/2, 0, L1;
    q2+pi/2, pi, -L3, L2;
    q3, 0, -L5, 0;
    q1, 0, 0, L6; % CM1
    q2+pi/2, 0, -L8, L7; % CM2
    q3, 0, -L10, 0.5*L7]; % CM3

% Specify the Robot Base (with respect to the world coordinate frame in ROS)
T0_W=eye(4);

% Compute the Homogeneous Transformations

T1_0= Relative_H(DH(1,:));

T2_1= Relative_H(DH(2,:));

T3_2= Relative_H(DH(3,:));

Tcm1_0= Relative_H(DH(4,:));

Tcm2_1= Relative_H(DH(5,:));

Tcm3_2= Relative_H(DH(6,:));

% Stack of Transformations
%T1_0=0;
T2_0= T1_0*T2_1;
T3_0= T2_0*T3_2;

%Tcm1_0=0;
Tcm2_0= T1_0*Tcm2_1;
Tcm3_0= T2_0*Tcm3_2;

T1_W= T1_0;
T2_W= T2_0;
T3_W= T3_0;

Tcm1_W= Tcm1_0;
Tcm2_W= Tcm2_0;
Tcm3_W= Tcm3_0;

% Get the position of the end-effector
Xef_W=T3_W(1:3,4);


z0= [0;0;1];
z1= T1_0(1:3,3);
z2= T2_0(1:3,3);
  
% Jcm1_0= [[cross(z0,Tcm1_0(1:3,4));z0] [0 0 0 0 0 0]' [0 0 0 0 0 0]' [0 0 0 0 0 0]'];
% Jcm2_0= [cross(z0, Tcm2_0(1:3,4)), z1, [0;0;0], [0;0;0] ; z0, [0;0;0], [0;0;0], [0;0;0]]; % Jacobian of cm2
% Jcm3_0= [cross(z0, Tcm3_0(1:3,4)), z1, z2, [0;0;0]; z0, [0;0;0], [0;0;0], [0;0;0]];

% Jacobians for CoM1, CoM2 and CoM3
Jcm1_0 = [[cross(z0, Tcm1_0(1:3,4));z0] [0 0 0 0 0 0]' [0 0 0 0 0 0]' ];
Jcm2_0 = [[cross(z0, Tcm2_0(1:3,4));z0] [cross(z1, Tcm1_0(1:3,4)) ; z1] [0 0 0 0 0 0]' ];
Jcm3_0 = [[cross(z0, Tcm3_0(1:3,4));z0] [cross(z1, Tcm2_0(1:3,4)) ; z1] [cross(z2, Tcm1_0(1:3,4)) ; z2]];

% Jacobian for the end effector 
J3_0= [cross(z0,T3_0(1:3,4)), cross(z1,T3_0(1:3,4)-T1_0(1:3,4)), cross(z2, T3_0(1:3,4)-T2_0(1:3,4));
z0, z1, z2 ];

% Complete the Jacobian Matrix (symbolic form)
Jef=J3_0;

% Compute the vector of cartesian velocities for the end-effector (using
% the Jacobian)
Xp=J3_0 * Qp;
