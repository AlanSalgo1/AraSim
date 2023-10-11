#include "TVector3.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Birefringence;

class Birefringence {

     public:

	Birefringence(Settings *settings1);



/***
double getDeltaN(int BIAXIAL,vector<double> &nvec,TVector3 rhat,double angle_iceflow,
                 double &n_e1, double &n_e2,TVector3 &p_e1,TVector3 &p_e2); // finds indices of refraction of two rays and unit vectors in the direction of the eigenvectors of D
TVector3 rotateD(TVector3 epsilon, double angle_iceflow, TVector3 D); // given D, outputs E, given the epsilon tensor.
void getManyAnglesontheClock(int BIAXIAL,double crosspolangle_tx,
                             TVector3 rhat_thisstep,
                             TVector3 p_e1,TVector3 p_e2,
			     TVector3 E_e1,TVector3 E_e2,
                             double &theta_e1,double &theta_e2, // angles on the clock of the D eigenvectors from the perspective of k 
			     double &thetaE_e1,double &thetaE_e2, // angles on the clock of the E eigenvectors from the perspective of k 
                             double &theta_e1_Sclock,double &theta_e2_Sclock, // angles on the clock of the D eigenvectors from the perspective of S 
                             double &thetaE_e1_Sclock,double &thetaE_e2_Sclock, // angles on the clock of the E eigenvectors from the perspective of S (from these we get the epsilon angles) 
                             TVector3 &Shat_e1,TVector3 &Shat_e2,
                             double &E_e1_thetacomponent, double &E_e2_thetacomponent,
                             double &E_e1_phicomponent, double &E_e2_phicomponent); // this calculates angles on the clock from the perspective of a k vector and an S vector.
void getAnglesontheClock(TVector3 rhat_thisstep1, TVector3 rhat_thisstep2,
                         TVector3 p_e1, TVector3 p_e2,
                         double &theta_e1,double &theta_e2,
                         double &p_e1_thetacomponent,double &p_e2_thetacomponent,
                         double &p_e1_phicomponent,double &p_e2_phicomponent); // this is used many times by getManyAnglesontheClock
void thetastoEpsilons(double thetaE_e1_Sclock,double thetaE_e2_Sclock,
		      double &epsilon1,double &epsilon2); // converts angles on the clock to epsilon angles (relative to 12 o'clock and 3 o'clock)
double getV(vector<double> &nvec);
***/
//add my function declarations here!

	vector<double> n1vec;
	vector<double> n2vec;
	vector<double> n3vec;
	vector<double> vdepths_n1;
	vector<double> vdepths_n2;
	vector<double> vdepths_n3;

	TVector3 p_e1_start;
    	TVector3 p_e2_start;

	int CONSTANTINDICATRIX=0; ///PLACEHOLDER!!!
	const double CLIGHT=3.E8;
	const double HOWSMALLISTOOSMALL=1.e-8;
	const double PI=3.1415926;
	const double DEGRAD=180./PI;
	const double angle_iceflow=(36.+ (46./60.) + (23./3600.) + 90.)/DEGRAD;
	const double MFT=1./100.*2.54/1.*12.; // (something in ft.)*1m/100cm*2.54cm/1in*12in

	void Read_Indicatrix_Par(string sn1file,string sn2file,string sn3file, Settings *settings1 ); //reads in files and gets depth vectors
	void Smooth_Indicatrix_Par();//smooths vectors 1,2,3
	double Time_Diff_TwoRays(vector <double> &res, vector <double> &zs, Settings *settings1);
	double getDeltaN(int BIAXIAL,vector<double> nvec,TVector3 rhat,double angle_iceflow, double &n_e1, double &n_e2,TVector3 &p_e1,TVector3 &p_e2);

/**
double VAngle(vector<double> &nvec_tmp,vector<double> &vdepths_n1,vector<double> &vdepths_n2,vector<double> &vdepths_n3,int n)//finds the angles between the three vectors

void readDepthFiles(ifstream &myfile,ifstream &Dave5afile,int this_station, int this_day,int this_pol, double this_depth, double this_snrmax){ //take myfile and dave's data and read in values
***/
	~Birefringence();

};
