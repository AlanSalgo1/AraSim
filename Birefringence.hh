#include "TVector3.h"
#include "Vector.h"
#include "Position.h"
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
	
	//Constructor
	Birefringence(Detector *detector, Settings *settings1);

	//Variables
	vector<double> n1vec;
	vector<double> n2vec;
	vector<double> n3vec;
	vector<double> vdepths_n1;
	vector<double> vdepths_n2;
	vector<double> vdepths_n3;

	TVector3 p_e1;
    	TVector3 p_e2;

	TVector3 p_e1_src;
	TVector3 p_e2_src;

	int CONSTANTINDICATRIX=0; ///PLACEHOLDER! I don't think we'll ever need CONSTANTINDICATRIX = 1. Used in Birefringence::Read_Indicatrix_Par() inside Birefringence.cc
	const double CLIGHT=3.E8;
	const double HOWSMALLISTOOSMALL=1.e-8;
	const double PI=3.1415926;
	const double DEGRAD=180./PI;
	double angle_iceflow=(36.+ (46./60.) + (23./3600.) + 90.)/DEGRAD;
	const double MFT=1./100.*2.54/1.*12.; // (something in ft.)*1m/100cm*2.54cm/1in*12in

	//Functions
	void Read_Indicatrix_Par(string sn1file,string sn2file,string sn3file, Detector *detector, Settings *settings1 ); //reads in files and gets depth vectors
	void Smooth_Indicatrix_Par();//smooths vectors 1,2,3
	double Time_Diff_TwoRays(vector <double> res, vector <double> zs, double refl_angle, Position interaction_vertex, Settings *settings1);
	double getDeltaN(int BIAXIAL,vector<double> nvec,TVector3 rhat,double angle_iceflow, double n_e1, double n_e2,TVector3 &p_e1,TVector3 &p_e2);

	TVector3 Get_p_e1();
	TVector3 Get_p_e2();

	double Power_split_factor(Vector Pol_vector, int bire_ray_cnt, Settings *settings1);
	void Principal_axes_polarization(Vector &Pol_vector, int bire_ray_cnt, int max_bire_ray_cnt, Settings *settings1);
	void Time_shift_and_power_split(double *V_forfft, int size, int T_shift, double split_factor, int bire_ray_cnt, int max_bire_ray_cnt, Settings *settings1);
	void Store_V_forfft_for_interference(double *V_forfft, double *V_forfft_bire, int size, int bire_ray_cnt);
	void Two_rays_interference(double *V_forfft, double *V_forfft_bire_1, double *V_forfft_bire_2, int size, int max_bire_ray_cnt, Settings *settings1);
	int Reflected_ray_remove_bire(double refl_angle);

	//Destructor
	~Birefringence();
};

