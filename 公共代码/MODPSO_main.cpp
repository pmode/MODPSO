
/*==================================================================================================*/
// Please find details of the method from:
//
//	 Maoguo Gong, Qing Cai, Xiaowei Chen, and Lijia Ma, "Complex Network Clustering by Multiobjective
//             Discrete Particle Swarm Optimization Based on Decomposition", IEEE Trans. Evolutionary 
//             Computation, 2013 (accepted).
/*==================================================================================================*/
// The source codes are free for research work. If you have any problem with the source codes, please 
// contact with:

//	Maoguo Gong, 
//		Key Laboratory of Intelligent Perception and Image Understanding of Ministry of Education,
//		University of Xidian,
//		Xi’an, Shaanxi Province 710071, China.
//		http://web.xidian.edu.cn/mggong/index.html
//		Email: gong@ieee.org or mggong@mail.xidian.edu.cn

//    Qing Cai
//		Key Laboratory of Intelligent Perception and Image Understanding of Ministry of Education,
//		University of Xidian,
//		Xi’an, Shaanxi Province 710071, China.
//		Email: 2008_jammy@163.com
/*==================================================================================================*/
// Programmer:		
//		Qing Cai
// Last Update:
//		Nov. 11, 2012
/*==================================================================================================*/
// The package is passed compiling under: MS Visual C++ in Windows XP. 
// After running the program, please find the final results in the corresponding document archives.
// All the network topology structures shown in the paper are drawn with the software Pajek.
/*==================================================================================================*/

#include "global.h"
#include "dmoea.h"
	

void main()
{

	strcpy(strFunctionType,"_TCH1"); // _TCH1, _TCH2, _PBI

/*----------------------------------------parameters setting-----------*/
	int  max_gen         = 100;       // maximal number of generations
	int  niche           = 40;        // neighborhood size 
	int  sd				 = 99;		  // population size 100
	int  rn              = 30;		  // run times
	popsize = sd + 1;
	numObjectives = 2;
	int runtimes = rn;

/*-----------------------------GN benchmark networks--------------*/
  char *BenchmarkData[] = {   "out0.txt",		    "out1.txt",\
							  "out2.txt",			"out3.txt",\
							  "out4.txt",			"out5.txt",\
							  "out6.txt",			"out7.txt",\
							  "out8.txt"};

/*-------------real labels of GN benchmark networks------*/
  
  char *BenchmarkDataLabel[] ={"real_label_out0.txt",\
							  "real_label_out1.txt",\
							  "real_label_out2.txt",\
							  "real_label_out3.txt",\
							  "real_label_out4.txt",\
							  "real_label_out5.txt",\
							  "real_label_out6.txt",\
							  "real_label_out7.txt",\
							  "real_label_out8.txt" };

/*-------------------GN extended benchmark networks-----------------*/
  
  char *ExtentionData[] = {"GNExtend\\0.0.txt", "GNExtend\\0.05.txt",	"GNExtend\\0.1.txt",\
						  "GNExtend\\0.15.txt",	"GNExtend\\0.2.txt",\
						  "GNExtend\\0.25.txt",	"GNExtend\\0.3.txt",\
						  "GNExtend\\0.35.txt",	"GNExtend\\0.4.txt",\
						  "GNExtend\\0.45.txt", "GNExtend\\0.5.txt" };

/*--------------------labels of GN extended benchmark networks---------------------*/
  char *ExtentionDataLabel[] ={"GNExtend\\real0.0.txt",  "GNExtend\\real0.05.txt",  "GNExtend\\real0.1.txt",\
							  "GNExtend\\real0.15.txt",	 "GNExtend\\real0.2.txt",\
							  "GNExtend\\real0.25.txt",	 "GNExtend\\real0.3.txt",\
							  "GNExtend\\real0.35.txt",	 "GNExtend\\real0.4.txt",\
							  "GNExtend\\real0.45.txt",  "GNExtend\\real0.5.txt" };

/*----------------------------unsigned real-world networks----------------------*/
  char *RealData[] = {  "RealWorld\\dFB50.txt",			"RealWorld\\25_point.txt",\
						"RealWorld\\125_point.txt",		"RealWorld\\karate.txt",\
						"RealWorld\\dolphin.txt",		"RealWorld\\football.txt",\
						"RealWorld\\polbook.txt",		"RealWorld\\celegansneural.txt",\
						"RealWorld\\SFI.txt",			"RealWorld\\netscience.txt",\
						"RealWorld\\netscience_remove.txt",	"RealWorld\\power.txt",\
						"RealWorld\\power_remove.txt",   "RealWorld\\email.txt",\
						"RealWorld\\hepth_adj.txt",  "E:\\我搞定的程序\\SI\\DPSOCD\\PGP_adj.txt"};

/*---------------------nos. of nodes of the corresponding unsigned networks-------------------------*/
  int  nvars[]       = {50, 25, 125, 34, 62, 115, 105, 0, 118, 1589, 1461, 4941, 4941, 0, 8361, 10680};
 
/*-----real labels of the unsigned real-world networks----------*/
  char *RealDataLabel[] ={  "RealWorld\\real_label_FB50.txt",\
							"RealWorld\\real_label_25_point.txt",\
							"RealWorld\\real_label_125_point.txt",\
							"RealWorld\\real_label_karate.txt",\
							"RealWorld\\real_label_dolphin.txt",\
							"RealWorld\\real_label_football.txt",\
							"RealWorld\\real_label_polbook.txt",\
							"RealWorld\\celegansneural_label.txt"};

/*----------------------------------signed real-world and artificial networks--------------------*/
	char *SignedData[] = {   "RealWorld\\slovene1.txt",  "RealWorld\\gahuku2.txt",\
							 "RealWorld\\data1.txt",	 "RealWorld\\data.txt",\
							 "RealWorld\\matrixfull.txt","RealWorld\\matrixfull_remove.txt",\
							 "RealWorld\\matrixfull_remove_remove.txt",\
							 "RealWorld\\GFull_remove_remove_remove.txt",\
							 "RealWorld\\new1000-6.txt",\
							 "EGFR.txt",       "Macrophage.txt",\
							 "yeast.txt",      "ecoli.txt",\
							 "wiki.txt"};

/*--------------------------real labels of the signed networks------------------------------*/  
	char *SignedDataLabel[] ={"RealWorld\\sloeven1label.txt", "RealWorld\\gahuku2label.txt",\
							  "RealWorld\\datalabel.txt", 	  "RealWorld\\datalabel.txt",\
							  "RealWorld\\datalabel.txt",     "RealWorld\\datalabel.txt",\
							  "RealWorld\\datalabel.txt",     "RealWorld\\datalabel.txt",\
							  "RealWorld\\new1000-6label.txt",\
							  "RealWorld\\datalabel.txt",\
							  "RealWorld\\datalabel.txt",\
							  "RealWorld\\datalabel.txt",\
							  "RealWorld\\datalabel.txt",\
							  "RealWorld\\datalabel.txt"};

/*-----------nodes of the signed networks--------------------*/
	int nnodes[] = {10, 16, 28, 28, 987, 180, 162, 120, 1000,\
					329, 678, 690, 1461, 7114};

/*----------------------------------the LFR benchmark networks------------------------------*/
	char *LFRData[] = { "LFR\\0.00.txt", "LFR\\0.05.txt",\
						"LFR\\0.10.txt", "LFR\\0.15.txt",\
						"LFR\\0.20.txt", "LFR\\0.25.txt",\
						"LFR\\0.30.txt", "LFR\\0.35.txt",
						"LFR\\0.40.txt", "LFR\\0.45.txt",\
						"LFR\\0.50.txt", "LFR\\0.55.txt",\
						"LFR\\0.60.txt", "LFR\\0.65.txt",\
						"LFR\\0.70.txt", "LFR\\0.75.txt",\
						"LFR\\0.80.txt"};
	
/*-----------------------the real labels of the LFR benchmark networks-------------------------*/
	char *LFRDataLabel[] ={ "LFR\\0.00.CLU", 	"LFR\\0.05.CLU",\
							"LFR\\0.10.CLU",		"LFR\\0.15.CLU",\
							"LFR\\0.20.CLU",		"LFR\\0.25.CLU",\
							"LFR\\0.30.CLU",		"LFR\\0.35.CLU",
							"LFR\\0.40.CLU",		"LFR\\0.45.CLU",\
							"LFR\\0.50.CLU",		"LFR\\0.55.CLU",\
							"LFR\\0.60.CLU",		"LFR\\0.65.CLU",\
							"LFR\\0.70.CLU",		"LFR\\0.75.CLU",\
							"LFR\\0.80.CLU"};


/*------------------------------------------------------------------*/
/* for benchmark testing */
/*------------------------------------------------------------------
  int ExtentionIndex = 8;
  optimization = 0;
  numVariables  = 128;
  mutate_posibility = 0.1;
  SignedFlag = 0;  // unsigned network
	AdjacentMatrix = new int *[numVariables];
	for ( int i = 0;i < numVariables;i++ )
	{
		AdjacentMatrix[i] = new int [numVariables];
	}
	node = new network[numVariables];
	strcpy(strGNExtend,ExtentionData[ExtentionIndex]);
	ReadFile(strGNExtend,AdjacentMatrix,numVariables,numVariables); 
	strcpy(strlabel,ExtentionDataLabel[ExtentionIndex]);
//*-----------------------------------------------------------------/ 


//////////////////////////////////////////////////////////////////////
/// testing for GN extended networks ///////////////////////////////*/
/*
	int ExtentionIndex = 4;
	optimization = 0;
	numVariables  = 128;
	SignedFlag = 0;  // unsigned network
	mutate_posibility = 0.1;
	AdjacentMatrix = new int *[numVariables];
	for ( int i = 0;i < numVariables;i++ )
	{
		AdjacentMatrix[i] = new int [numVariables];
	}
	node = new network[numVariables];
	strcpy(strGNExtend,ExtentionData[ExtentionIndex]);
	ReadFile(strGNExtend,AdjacentMatrix,numVariables,numVariables); 
	strcpy(strlabel,ExtentionDataLabel[ExtentionIndex]);
/////////////////////////////////////////////////////////////////////


/*==========================================================================================*/
/*==================testing for unsigned real world networks================================*/
/*
	int RealIndex = 8; //8--SFI, 10--netremove, 12--powerremove, 3-karate,4-dolphin,5-football
	numVariables  = nvars[RealIndex];
	optimization = 0;
	SignedFlag = 0;  // unsigned network
	mutate_posibility = 0.1;
	AdjacentMatrix = new int *[numVariables];
	for ( int i = 0;i < numVariables;i++ )
	{
		AdjacentMatrix[i] = new int [numVariables];
	}
	node = new network[numVariables];
	strcpy(strReal,RealData[RealIndex]);
	ReadFile(strReal,AdjacentMatrix,numVariables,numVariables);  

	strcpy(strlabel,RealDataLabel[RealIndex]);
//===========================================================================================



/**************************************************************/
//*  testing for signed networks
	int RealIndex = 9; 
	optimization = 0;
	numVariables  = nnodes[RealIndex];
	SignedFlag = 1;  // signed network 
	mutate_posibility = 0.9;
	AdjacentMatrix = new int *[numVariables];
	for ( int i = 0;i < numVariables;i++ )
	{
		AdjacentMatrix[i] = new int [numVariables];
	}
	node = new network[numVariables];
	strcpy(strReal,SignedData[RealIndex]);
	ReadFile(strReal,AdjacentMatrix,numVariables,numVariables);  

	strcpy(strlabel,SignedDataLabel[RealIndex]);
/**************************************************************/


//////////////////////////////////////////////////////////////////////
/*  testing for LFR
	int ExtentionIndex = 1;
	optimization = 0;
	numVariables  = 1000;
	SignedFlag = 0;  // unsigned network
	mutate_posibility = 0.1;
	AdjacentMatrix = new int *[numVariables];
	for ( int i = 0;i < numVariables;i++ )
	{
		AdjacentMatrix[i] = new int [numVariables];
	}
	node = new network[numVariables];
	strcpy(strGNExtend,LFRData[ExtentionIndex]);
	ReadFile(strGNExtend,AdjacentMatrix,numVariables,numVariables); 
	strcpy(strlabel,LFRDataLabel[ExtentionIndex]);
  //*/
////////////////////////////////////////////////////////////////////


/*------------------------------------------------------------------------------*/
/*-------- do not change the following codes unless u really know them ---------*/
/*------------------------------------------------------------------------------*/
	NodeInformation();	//right

	seed = (seed + 111)%1235;	
	rnd_uni_init = -(long)seed;	

	TMOEAD  MOEAD;      
	
	for (int mg = 0; mg < runtimes; mg++)
	{
		
		cout<<"第 "<<mg+1<<"次运行";
		MOEAD.run(sd, niche, max_gen, rn);
		
	}
	for (int j = 0; j < runtimes; j++)
	{
		cout<<"Q = "<<Thirty_Run_modularity[j]<<"  ";
		if (check_label())	cout<<"NMI = "<<Thirty_Run_NMI[j]<<endl;
	}
	if (check_label())	NMImax = *max_element(Thirty_Run_NMI.begin(),Thirty_Run_NMI.end());
	Qmax = *max_element(Thirty_Run_modularity.begin(),Thirty_Run_modularity.end());
	for (int k = 0; k < runtimes; k++)
	{
		if (check_label())	NMIavg += Thirty_Run_NMI[k];
		Qavg += Thirty_Run_modularity[k];
	}

	Qavg = Qavg/Thirty_Run_modularity.size();
	if (check_label())
	{
		NMIavg = NMIavg/Thirty_Run_NMI.size();
		cout<<"max NMI = "<<NMImax<<"   "<<"avg NMI = "<<NMIavg<<endl;
	}
	cout<<"max Q = "<<Qmax<<"    "<<"avg Q = "<<Qavg<<endl<<endl;;
	cout<<"The end of the algorithm! Find the detailed results in the document archives"<<endl;
}
