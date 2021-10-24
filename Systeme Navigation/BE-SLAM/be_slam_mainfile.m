%% Clean workspace
clear all
close all
clc

%% Get all data and variables required for processing the SLAM
[X, PX, MAP_ID, meas, cov, simu, display] = init_SLAM(1);  %% use data {1 : SLAM_1.mat, x : SLAM_2.mat}


%% Choose the algorithm to be launched : true mean "solution" algorithm
algoRef = false;		% {true , false}


%%========================================================================
%% Launch SLAM loop
%% For each step of the simulation
for step= 1:simu.Length_simu

    
    
    %%=========================================================================
    %% Prediction phase
    %% - At the current time, we get proprioceptive sensors inputs V and w
    %% representing linear velocity and angular velocity
    %% - Sensors are uncertain so we have associated covariances Pu
    %% - We have to use these inputs to predict the state of the robot at
    %% current time t from last time t-dt = t-1 (dt=1 for this simulation)
    %%=========================================================================
    if algoRef
        [X, PX] = predict_state(X, PX, meas.Vs(step), meas.ws(step), simu.dt, cov.Pu);
    else
        % Function to be edited
        [X, PX] = student_predict_state(X, PX, meas.Vs(step), meas.ws(step), simu.dt, cov.Pu);
    end
    
    
    
    %%=========================================================================
    %% Mapping and Update phase
    %% - At the current time, we get exteroceptive sensors inputs Z
    %% representing the LiDAR detection in polar coordinates (rho, theta)
    %% - Sensors are uncertain so we have associated covariances Pz
    %% - We have to use these inputs to : map the environnement if the object
    %% is unknown or to update the map and robot state if the object is already
    %% known
    %%=========================================================================
    if algoRef
        [X, PX, MAP_ID] = update_state(X, PX, MAP_ID, meas.Zs{step}, cov.Pz);
    else
        % Function to be edited
        [X, PX, MAP_ID] = student_update_state(X, PX, MAP_ID, meas.Zs{step}, cov.Pz);
    end
    
    % Update with GNSS if available
    if algoRef
        [X, PX] = update_gnss(X, PX, meas.GNSS(:,step), cov.Pgnss);
    else
        [X, PX] = student_update_gnss(X, PX, meas.GNSS(:,step), cov.Pgnss);
    end
    
    
    %%=========================================================================
    %% Results display
    display.h = display_pose(X, PX, display.h);      % affiche la pose estimée et son incertitude
    display.h = display_landmarks(X, PX, display.h); % affiche les amers estimés et leurs incertitudes
    drawnow                          % force l'affichage à chaque itération
    %%=========================================================================
end