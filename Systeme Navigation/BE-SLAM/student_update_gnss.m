function [X, PX] = student_update_gnss(X, PX, GNSS, Pgnss)

%% Check if GNSS is available
if isnan(GNSS(1))
    return
end


%% Process innovation :
% inn = z_gnss - h(X)


%% Process update with classical Kalman equations
% X = ...
% PX = ...
