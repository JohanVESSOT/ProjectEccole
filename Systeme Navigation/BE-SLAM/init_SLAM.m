function [X, PX, MAP_ID, measurements, covariances, simu_params, display] = init_SLAM(num_dataset)

addpath('./fct_display')
addpath('./fct_teacher/')
if num_dataset == 1
    load ./data/SLAM_1.mat
else
    load ./data/SLAM_2.mat
end




X = X0(1:3);
PX = PX0(1:3,1:3);
MAP_ID = [];

measurements.Vs = Vs;
measurements.ws = ws;
measurements.Zs = Zs;

covariances.Pz = [sigZ^2 0 ; 0 sigTheta^2]; % variance capteur distance / angle
covariances.Pu = [sigV^2 0; 0 sigw^2];      % matrice covariance capteur vitesse

% Nombre de landmarks
simu_params.Nb_Landmarks = length(sim.landmarks);
simu_params.Length_simu = length(sim.x);

simu_params.dt = 1;
simu_params.sim = sim;

% Display handle
display.h = display_world(X, PX, sim);      % cree la fenetre d'affichage et les handles


x_gps = simu_params.sim.x(50:50:end);
y_gps = simu_params.sim.y(50:50:end);


if num_dataset == 1
    sig_gnss = 1;
else
    sig_gnss = 3;
end
x_gps = x_gps+0.2*sig_gnss*randn(size(x_gps));
y_gps = y_gps+0.2*sig_gnss*randn(size(y_gps));
measurements.GNSS = NaN*zeros(2,length(simu_params.sim.x));
measurements.GNSS(:, 50:50:end) = [x_gps; y_gps];
covariances.Pgnss = [sig_gnss 0; 0 sig_gnss];
