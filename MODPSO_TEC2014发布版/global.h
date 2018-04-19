#ifndef __GLOBAL_H_
#define __GLOBAL_H_

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <memory.h>
#include <vector>
#include <windows.h>

using namespace std;


#define test_node 6
#define test_edge 7
#define test_QR 1.0/(2*test_edge)

#define realCommunityNum 19
#define FB50_nodes 50
#define FB50_edge 808
#define FB50_QR 1.0/(2*FB50_edge)
#define H13_4_nodes 256
#define H13_4_edge 4616
#define H13_4_QR 1.0/(2*H13_4_edge)
#define karate_nodes 34
#define karate_edge 78
#define karate_QR 1.0/(2*karate_edge)
#define dolphin_nodes 62
#define dolphin_edge 159
#define dolphin_QR 1.0/(2*dolphin_edge)
#define _20node_node 20
#define _20node_edge 28
#define _20node_QR 1.0/(2*_20node_edge)
#define SFI_nodes 118
#define SFI_edge 200
#define SFI_QR 1.0/(2*SFI_edge)
#define GNEx_nodes 128
#define GNEx_edge 1024
#define GNEx_QR 1.0/(2*GNEx_edge)
#define football_nodes 115
#define football_edge 613
#define football_QR 1.0/(2*football_edge)
#define netscience_nodes 1589
#define netscience_edge 2742
#define netscience_QR 1.0/(2*netscience_edge)
#define netscience_remove_nodes 1461
#define netscience_remove_edge 2742
#define netscience_remove_QR 1.0/(2*netscience_remove_edge)
#define power_nodes 4941
#define power_edge 6594
#define power_QR 1.0/(2*power_edge)
#define power_remove_nodes 4941
#define power_remove_edge 6594
#define power_remove_QR 1.0/(2*power_remove_edge)
#define hepth_nodes 6594
#define hepth_edge 4491
#define hepth_QR 1.0/(2*hepth_edge)
#define PGP_nodes 10680
#define PGP_edge 24340
#define PGP_QR 1.0/(2*hepth_edge)
#define MIDV30_nodes 986
#define MIDV30_edge 937
#define MIDV30_QR 1.0/(2*MIDV30_edge)
#define MIDV30_remove_nodes 158
#define MIDV30_remove_edge 937
#define MIDV30_remove_QR 1.0/(2*MIDV30_remove_edge)

#define INF 1.0e+30
#define archive_size 500   /* set capacity of archive */
 
 
// demensionality of variables and objectives
int     numVariables;
int     numObjectives;
int     popsize;


char    strFunctionType[256];
char    strReal[256];
char    strlabel[256];
char    strGNExtend[256];

// ideal point used in decomposition methods
double  *idealpoint;

// parameters for random number generation
int     seed = 237;
long    rnd_uni_init;
int count111 = 0;
vector<vector <int>> finalresult;
int optimization;	   /* set optimization type, 0 for min, 1 for max */
double alpha = 1.0;
double r = 1.0;
double delta = 2.0;
const double perterbation = 0.00001;
double mutate_posibility ;
const double cross_posibility = 0.9;
vector<vector<double> >front; // store removed PF
vector<vector<int> >chrom;    // store the corresponding chrom
vector<double> NMI;
vector<double> pm_NMI;
vector<double> pm_modularity;
vector<double> Thirty_Run_NMI;
vector<double> Thirty_Run_modularity;
vector<int> clusters;
double NMIavg;
double NMImax;
double Qmax;
double Qavg;
int SignedFlag;		//1 for signed networks, 0 for unsigned networks

vector<double> modularity;
unsigned int nondomCtr = 0;		/* number of nondominated solutions in archive */


struct network 
{
	vector<int> neighbours;		//positive neighbors
	vector<int> neighbours_n;	//negative neighbors
	int degree;					//positive links
	int degree_n;				//negative links
};

int **AdjacentMatrix ;
network *node ;



#include "random.h"

#endif