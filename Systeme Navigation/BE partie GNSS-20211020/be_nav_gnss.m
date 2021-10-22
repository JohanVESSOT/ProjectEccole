clear all

%% Choix de l'algo
algoRef		= false ;		% {true , false}


%% Choix du scénario
iCase		= 1;

switch iCase

case 1
	% Exemple illustrant le mécanisme prediction/correction
	fileName		= 'GPS_S2.mat';
	snrOutGps	= 41;		% (dB)

case 11
	% Exemple illustrant le mécanisme prediction/correction :
	% quand le modèle d'état est très précis (quasi-déterministe), les mesures ne sont pas prises en compte
	fileName		= 'GPS_S1.mat';
	snrOutGps	= 61;		% (dB)

case 12
	% Exemple illustrant le mécanisme prediction/correction :
	% quand le modèle d'état est très précis (quasi-déterministe), les mesures ne sont pas prises en compte
	fileName		= 'GPS_S1.mat';
	snrOutGps	= 31;		% (dB)

case 13
	% Exemple illustrant le mécanisme prediction/correction :
	% les mesures (imprécises) ne sont pas prises en compte
	fileName		= 'GPS_S2.mat';
	snrOutGps	= 15;		% (dB)

case 14
	% Exemple illustrant le mécanisme prediction/correction :
	% les mesures (imprécises) ne sont pas prises en compte
	fileName		= 'GPS_S3.mat';
	snrOutGps	= 15;		% (dB)

case 15
	% Exemple illustrant le mécanisme prediction/correction :
	% les mesures (précises) sont prises en compte pour corriger la prédiction
	fileName		= 'GPS_S3.mat';
	snrOutGps	= 61;		% (dB)

case 21
	% Exemple illustrant le mécanisme prediction/correction : sur-estimation de Cw
	fileName		= 'GPS_S2.mat';
	snrOutGps	= 41;		% (dB)
	algoRef		= true;

case 22
	% Exemple illustrant le mécanisme prediction/correction : sous-estimation de Cw
	fileName		= 'GPS_S2.mat';
	snrOutGps	= 41;		% (dB)
	algoRef		= true;

case 23
	% Exemple illustrant le mécanisme prediction/correction : sur-estimation de Cv
	fileName		= 'GPS_S2.mat';
	snrOutGps	= 41;		% (dB)
	algoRef		= true;

case 24
	% Exemple illustrant le mécanisme prediction/correction : sous-estimation de Cv
	fileName		= 'GPS_S2.mat';
	snrOutGps	= 41;		% (dB)
	algoRef		= true;

end

%%%% Initialisations

be_nav_gnss_init

figure
plot(xMes,yMes,'.-c',xTrue,yTrue,'.-r')
grid, axis equal
xlabel('x (m)')
ylabel('y (m)')
legend('Measured Trajectory','True Trajectory')
title(['Robot Trajectory (',fileNameDisp,')'])
hold on

x0			= [xTrue(1); yTrue(1)];
Px0		= zeros(2,2);

%%%% Modèle d'évolution ("state model") du véhicule utilisant les données du capteur de vitesse

xkDisp	= zeros(2,K);

if (algoRef)
	modele_evolution
else
	mesInd	= 1:1:K;

    % Initialiser le tableau vide
    xMesurer = zeros(1,K) ;
    yMesurer = zeros(1,K) ;

    % Ajouter la position initale du systeme
    xMesurer(1) = x0(1) ;
    yMesurer(2) = x0(2);


    for i = mesInd(2:1:K)
            xMesurer(i) = eye(1) * xMesurer(i-1) + eye(1) * VxMes(i) ;
            yMesurer(i) = eye(1) * yMesurer(i-1) + eye(1) * VyMes(i) ;
  
    end
    % Affichage du resultat
    xkDisp = [xMesurer;yMesurer];

end

if (sum(abs(xkDisp(:))) ~= 0)
	plot(xkDisp(1,mesInd),xkDisp(2,mesInd),'.-g')
	grid, axis equal
	legend('Measured','True','State Model')
end

%%%% Modèle d'évolution ("state model") du véhicule utilisant utiliser les mesures ("measurement model") de distance aux balises

xkDisp	= zeros(2,K);
xkPDisp	= zeros(2,K);

if (algoRef)
	filtre_kalman
else
	
	
	% A faire filtre de kalman

    % Initialisation des variables :
    xAfficher = zeros(1:1:K) ;
    YAfficher = zeros(1:1:K) ;

     F = eye(2) ;
     % Sigma dans l'énoncé de TD

    
    for i = mesInd(2:1:K)


    end
end

if ((sum(abs(xkDisp(:))) ~= 0) && (sum(abs(xkPDisp(:))) ~= 0))
	plot(xkPDisp(1,mesInd),xkPDisp(2,mesInd),'.-k')
	plot(xkDisp(1,mesInd),xkDisp(2,mesInd),'.-b')
	grid, axis equal
	legend('Measured','True','State Model','KPred (x^b_k_|_k_-_1)','KFilt (x^b_k_|_k)')
end

hold off