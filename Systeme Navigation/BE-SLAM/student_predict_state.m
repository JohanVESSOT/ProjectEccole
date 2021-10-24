function [X, PX] = student_predict_state(X, PX, V, w, dt, Pu)

%% The objective of this function is to estimate the position of the robot 
%% X(t) at the current time t given the previous pose X(t-1) at time t-1. 
%% In order to be able to predict the pose, we use the proprioceptive information
%% of linear and angular velocities.
%% As we are dealing with uncertain states and sensors measurements, we also 
%% have to deal with the undertainties (covariances)
%
% X(t+1|t) = f(X(t|t), V, w)
% PX(t+1|t) = Jfx PX(t|t) Jfx' + Jfu Pu Jfu'
% - Jfx is the jacobian of function f with reference to variables in X
% - Jfu is the jacobian of function f with reference to control inputs (V,w)



%% State prediction (mean value of the gaussian distribution)
% X(t+1) = f(X(t), V, w)
X = [X(1)+V*dt*cos(X(3));X(2)+V*dt*sin(X(3));X(3)+w*dt];


%% Covariance prediction
% Be carefull that we will add objects (landmarks) into the map, the size
% of X and PX will grow. The calculation of PX prediction need to be done
% considering the entire size of PX. : 
% Help : Jfx should be of size length(X) by length(X), Jfu of size length(X) by 2
%
% PX(t+1) = Jfx PX(t) Jfx' + Jfu Pu Jfu'


Jfx = [1 , 0 ,-V*dt*sin(X(3)) ;  0 ,1 ,V*dt*cos(X(3)) ; 0 ,0 ,1   ] ;
Jfu = [dt*cos(X(3)),0 ; dt*sin(X(3)),0 ; 0 ,dt] ;
PX = Jfx*PX*Jfx' + Jfu*Pu*Jfu';

