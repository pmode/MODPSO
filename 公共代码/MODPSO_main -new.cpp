#include "global.h"
#include "dmoea-new.h"
	

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
  
  char *ExtentionData[] = {"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\0.0.txt", "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\0.05.txt",	"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\0.1.txt",\
						  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\0.15.txt",	"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\0.2.txt",\
						  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\0.25.txt",	"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\0.3.txt",\
						  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\0.35.txt",	"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\0.4.txt",\
						  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\0.45.txt", "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\0.5.txt" };

/*--------------------labels of GN extended benchmark networks---------------------*/
  char *ExtentionDataLabel[] ={"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\real0.0.txt",  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\real0.05.txt",  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\real0.1.txt",\
							  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\real0.15.txt",	 "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\real0.2.txt",\
							  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\real0.25.txt",	 "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\real0.3.txt",\
							  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\real0.35.txt",	 "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\real0.4.txt",\
							  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\real0.45.txt",  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\GNExtend\\real0.5.txt" };

/*----------------------------unsigned real-world networks----------------------*/
  char *RealData[] = {  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\dFB50.txt",			"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\25_point.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\125_point.txt",		"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\karate.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\dolphin.txt",		"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\football.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\polbook.txt",		"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\celegansneural.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\SFI.txt",			"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\netscience.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\netscience_remove.txt",	"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\power.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\power_remove.txt",   "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\email.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\hepth_adj.txt",  "E:\\我搞定的程序\\SI\\DPSOCD\\PGP_adj.txt"};

/*---------------------nos. of nodes of the corresponding unsigned networks-------------------------*/
  int  nvars[]       = {50, 25, 125, 34, 62, 115, 105, 0, 118, 1589, 1461, 4941, 4941, 0, 8361, 10680};
 
/*-----real labels of the unsigned real-world networks----------*/
  char *RealDataLabel[] ={  "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\real_label_FB50.txt",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\real_label_25_point.txt",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\real_label_125_point.txt",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\real_label_karate.txt",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\real_label_dolphin.txt",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\real_label_football.txt",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\real_label_polbook.txt",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\RealWorld\\celegansneural_label.txt"};

/*----------------------------------the LFR benchmark networks------------------------------*/
	char *LFRData[] = { "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.00.txt", "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.05.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.10.txt", "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.15.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.20.txt", "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.25.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.30.txt", "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.35.txt",
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.40.txt", "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.45.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.50.txt", "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.55.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.60.txt", "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.65.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.70.txt", "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.75.txt",\
						"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.80.txt"};
	
/*-----------------------the real labels of the LFR benchmark networks-------------------------*/
	char *LFRDataLabel[] ={ "E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.00.CLU", 	"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.05.CLU",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.10.CLU",		"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.15.CLU",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.20.CLU",		"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.25.CLU",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.30.CLU",		"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.35.CLU",
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.40.CLU",		"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.45.CLU",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.50.CLU",		"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.55.CLU",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.60.CLU",		"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.65.CLU",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.70.CLU",		"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.75.CLU",\
							"E:\\毕设材料\\MODPSO_TEC2014\\数据集\\LFR\\0.80.CLU"};


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
//*
	int RealIndex = 4; //8--SFI, 10--netremove, 12--powerremove, 3-karate,4-dolphin,5-football
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
