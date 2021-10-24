function [X, PX, MAP_ID] = student_update_state(X, PX, MAP_ID, Z, Pz)


%% For each measurement (as the LiDAR can detect multiple objects)
for iz=1:size(Z,2)
    
    %% Get the current detection
    rho = Z(1,iz);      % distance to the sensor
    theta = Z(2,iz);    % angle in the sensor frame (different from the robot frame)
    ID = Z(3,iz);       % Identifier of the object (to make it easier for this classe)
    
    
    %% 1) Express the landmark coordinates in (x,y) in the world coordinate frame 
    %% process also the uncertainty of this pose (covariance)
    
    Landmark_pose = [ X(1)  + rho * cos(theta + X(3)) ;  X(2)  + rho * sin (theta + X(3)) ] ;

    Jgx = [1,0,-rho*sin(theta+X(3)); 0,1,rho*cos(theta+X(3)) ] ;
    Jgi = [cos(theta+X(3)), -rho*sin(theta+X(3));sin(theta+X(3)), rho*cos(theta+X(3))];
    

    Landmark_cov = Jgx*PX*Jgx' + Jiu*Pz*Jgi';
    
    X = [X ; Landmark_pose];

    PX = [PX,PX*Jgx';Jgx*PX,Landmark_cov];


    %% 2) Check if the landmark is already in the map. Two cases:
    %% - the landmark is NOT in the map, this is a new landmark, we have to
    %% add it in the map -> Mapping step
    %% - the landmark is already in the map, we have a new observation of 
    %% something we have estimated, we need to update its state
    
    %%if(isempty(find(ID==MAP_ID))==1)   
        % Case 1:
        % - The pose of the landmark has to be added at the end of the X
        % vector
        % - The landmark pose covariance has also to be added at the bottom right of the
        % state covariance matrix BUT the statistical link between the
        % landmark and the robot pose has to be computed !
    
        
    % else
        % Case 2:
        % - The innovation between what is detected z=(rho, theta) and what
        % should be detected if the current state was true h(X) has to be
        % computed -> Innovation = z - h(X)
        % h is the observation/measurement function
        % Help: Be carefull that the innovation for angle has to be checked (0 and 2pi
        % don't have a difference of 2pi...)
        
        
        % Classical Kalman update can then be processed (see equations on
        % the classe slide)
        
        
    % end
    
    
    
    
end % end of the loop over all the detections  