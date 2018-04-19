#ifndef __MOEAD_H_
#define __MOEAD_H_

#include "global.h"
#include "common.h"
#include "individual.h"
#include "scalarfunc.h"
#include "recombination.h"
#include <time.h>
#include <numeric>
#include<iomanip>
class TMOEAD    
{
public:

	TMOEAD();
	virtual ~TMOEAD();

	void init_uniformweight(int sd);    // 给子问题的权重初始化
	void init_neighbourhood();          // 计算每个子问题的邻居
	void init_population();             // 初始化种群
	void init_velocity();               // 初始化速度
	void store_pbests(); /*保存每个粒子的pbest（包括变量和适应值）*/
	void update_pbests(int index);
	void update_pbests_child(TIndividual &ind, int index);
	void compute_velocity(int index, TIndividual &child, int gen);
	void update_reference(TIndividual &ind);           // update the approximation of ideal point
	void update_problem(TIndividual &child, int id);   // compare and update the neighboring solutions
	void evolution(int gen);                           // mating restriction, recombination, mutation, update
	void run(int sd, int nc, int mg, int rn);          // execute MOEAD
	void save_front(char *savefilename);               // save the pareto front into files
	void save_chrom(char *saveFilename);
	void save_results(char *archiveName);
	int aimed(int index);
    vector <TSOP>  population;  // current population     
	vector <TIndividual> pbest; // pbest population
	vector <TIndividual> gbest; // gbest population,

	TIndividual *indivpoint;    // reference point
	double **velocity;
	int  niche;                 // neighborhood size
	int  pops;                  // population   size	

	void operator=(const TMOEAD &emo);
};

TMOEAD::TMOEAD()
{
	velocity = new double *[popsize];
	for (int i = 0; i < popsize; i++)
		velocity[i] = new double[numVariables];

	idealpoint = new double[numObjectives];
	indivpoint = new TIndividual[numObjectives];    
	// initialize ideal point	
    for(int n=0; n<numObjectives; n++) 
	{
		if (optimization == 0)
		{
			idealpoint[n] = 1.0e+30;   // for min
		} 
		else if (optimization == 1)
		{
			idealpoint[n] = -1.0e+30;  // for max
		}
	
		indivpoint[n].rnd_init();
		indivpoint[n].obj_eval();
	}
}

TMOEAD::~TMOEAD()
{
// 	delete [] idealpoint;    
// 	delete [] indivpoint;
}


void TMOEAD::init_population()
{
    for(int i=0; i<pops; i++)
	{
		population[i].indiv.rnd_init();
		population[i].indiv.obj_eval();
		update_reference(population[i].indiv);
	}
}

void TMOEAD::init_velocity()
{
    for(int i=0; i<pops; i++)
		for (int j = 0; j < numVariables; j++)
 			velocity[i][j] = 0.0;			
}

void TMOEAD::store_pbests() /* Store personal bests (both variable and fitness values) of particles */
{
	unsigned int i, j;
	
	/* Store variable values of personal bests */
	for(i=0; i < pops; i++)
		pbest.push_back(population[i].indiv);
			
}

void TMOEAD::compute_velocity(int index, TIndividual &child, int gen) /* Compute new velocity of each particle in the population */
{
	unsigned int top, i, j, k, m, l, gBest;

	child = population[index].indiv;

	//int RandNum = rnd_uni(&rnd_uni_init) * population[index].table.size();
	//int RandNeighbor = population[index].table[RandNum];
	TIndividual NeighborBest = population[rand() % 99 + 1].indiv;	//*/
	
	for(j = 0; j < numVariables; j++)
	{
		int v1, v2;

		if (pbest[index].x_var[j] == population[index].indiv.x_var[j]) v1 = 0;
		else v1 = 1;

		if (NeighborBest.x_var[j] == population[index].indiv.x_var[j]) v2 = 0;
		else v2 = 1;
	
		velocity[index][j] = rnd_uni(&rnd_uni_init) * velocity[index][j] + 
							1.494 * rnd_uni(&rnd_uni_init) * v1 + 
							1.494 * rnd_uni(&rnd_uni_init) * v2;
									
		double sigmoid = 1.0/(1.0+exp(-velocity[index][j]));
		
		if (rnd_uni(&rnd_uni_init) < sigmoid)
			velocity[index][j] = 1;
 		else velocity[index][j] = 0;
		/*/
		if (v1 == 0 || v2 == 0)
		{
			velocity[index][j] = velocity[index][j];
		}
		else
			velocity[index][j] = 0;*/
	

	}

/*********************************************************************************************/
// select the dominated label indentifier 

	  for(j = 0; j < numVariables; j++)
	  {
		  if (velocity[index][j] == 1)
		  {
				int	sum = 0;
				int maxr = -1;//record index of i's neighbour which ...	//记录最大邻居出现的状态
				int label = -1;
				int	temp = 1;//记录最大邻居状态出现的次数
							
				if(node[j].neighbours.size() > 1)//对于第j个节点，如果他邻居非空
				{
					for ( m = 0;m < node[j].neighbours.size();m++ )//遍历第j个节点的邻居0,m-1
					{
						int counter = 1;//record no. of nodes that has same label with j
									
						for ( k = m + 1;k < node[j].neighbours.size();k++ )
						{
							int p = child.x_var[node[j].neighbours[m]];
							int q = child.x_var[node[j].neighbours[k]];
							if( p == q )  counter++;
						}//end k
									
						if ( temp < counter )
						{
							maxr = m;
							temp = counter;
						}
					}//end m
								
					for ( l = 0;l < node[j].neighbours.size();l++ )
					{
						int u = child.x_var[node[j].neighbours[l]];
						int v = child.x_var[j];
						if ( u == v )	label = u;
					}//end l
					if (label != -1 && maxr == -1)
					{
						child.x_var[j] = label;
					}
					else 
					{
						if (maxr != -1)
						{
							child.x_var[j] = child.x_var[node[j].neighbours[maxr]];
						} 
						else
						{
							double r3 = rnd_uni(&rnd_uni_init);
							int randneighbor = r3*node[j].neighbours.size();
							if (r3 == 1)
								child.x_var[j] = child.x_var[node[j].neighbours[randneighbor-1]];
							else  child.x_var[j] = child.x_var[node[j].neighbours[randneighbor]];				
						}			
					}

				}//end if node[i].neighbours.size() > 1
				else 
				{
					if (node[j].neighbours.size() == 1)
					{
						child.x_var[j] =  child.x_var[node[j].neighbours[0]];	
					} 
					else
					{
	//					cout<<"the "<<i+1<<"th node has no connections"<<endl;
	//					pos[i] = 0;
					}
				}				
		  }//end if velocity[i][j] == 1	 
	}//end j

/*********************************************************************************************/

}//end function

void TMOEAD::update_pbests(int index) /* Update personal bests of particles in the population .Based on Pareto Front Rules*/
{
	unsigned int j, sum, better = 0, counter;
	
	sum = 0; counter = 0;

	for(j = 0; j < numObjectives; j++)
	{
		if( ((population[index].indiv.y_obj[j] <= pbest[index].y_obj[j]) && (optimization == 0)) 
			|| ((population[index].indiv.y_obj[j] >= pbest[index].y_obj[j]) && (optimization == 1)))
			sum += 1;

		if( ((population[index].indiv.y_obj[j] < pbest[index].y_obj[j]) && (optimization == 0)) 
			|| ((population[index].indiv.y_obj[j] > pbest[index].y_obj[j]) && (optimization == 1)))
			counter += 1;
	}	
		
	if (sum == numObjectives) 		
	{ /* current pop dominates pbest */
		better = 0;
	} 
	else 
	{
		if (sum == 0)           /* pbest dominates current pop */
			better = 1;
		else if (counter == 1)
		{
			double temp1 = population[index].namda[0]*population[index].indiv.y_obj[0]+
							population[index].namda[1]*population[index].indiv.y_obj[1];
			double temp2 = population[index].namda[0]*pbest[index].y_obj[0]+
							population[index].namda[1]*pbest[index].y_obj[1];

			if (((temp1<temp2) && (optimization == 0)) || ((temp1>temp2) && (optimization == 1)))
				better = 0;//*/
		}
		//	better = rnd_uni(&rnd_uni_init); /* both are nondominated,randomly select one */
	}
		
	if (better == 0)
	{
		for(j = 0; j < numObjectives; j++)
			pbest[index].y_obj[j] = population[index].indiv.y_obj[j];
		for(j = 0; j < numVariables; j++)
 			pbest[index].x_var[j] = population[index].indiv.x_var[j];				
	}

}

// initialize a set of evenly-distributed weight vectors
void TMOEAD::init_uniformweight(int sd)
{   
    for(int i=0; i<=sd; i++)
	{
        TSOP sop;		   
		sop.array.push_back(i);
		sop.array.push_back(sd-i);
		for(int j=0; j<sop.array.size(); j++)
			sop.namda.push_back(1.0*sop.array[j]/sd);
		population.push_back(sop); 		
	}
	pops = population.size();
}

// initialize the neighborhood of subproblems based on the distances of weight vectors
void TMOEAD::init_neighbourhood()
{
    double *x   = new double[pops];
	int    *idx = new int[pops];
	for(int i=0; i<pops; i++)
	{	
		for(int j=0; j<pops; j++)
		{
		    x[j]    = distanceVector(population[i].namda,population[j].namda);
			idx[j]  = j;			
		}
		minfastsort(x,idx,pops,niche);   
		for(int k=0; k<niche; k++)   
			population[i].table.push_back(idx[k]);

	}
    delete [] x;
	delete [] idx;

}



void TMOEAD::update_problem(TIndividual &indiv, int id)
{
    for(int i=0; i<niche; i++)
	{
		int    k  = population[id].table[i];
		double f1, f2;
		f1 = scalar_func(population[k].indiv.y_obj, population[k].namda, indivpoint);
		f2 = scalar_func(indiv.y_obj, population[k].namda, indivpoint);

		if(f2<f1) population[k].indiv = indiv;		
	}
}


// update the reference point
void TMOEAD::update_reference(TIndividual &ind)
{
	for(int n=0; n<numObjectives; n++)    
	{
		if (optimization == 0)
		{
			if(ind.y_obj[n]<idealpoint[n])
			{
				idealpoint[n]  = ind.y_obj[n];
				indivpoint[n]  = ind;
			}
		} 
		else if (optimization == 1)
		{
			if(ind.y_obj[n]>idealpoint[n])
			{
				idealpoint[n]  = ind.y_obj[n];
					indivpoint[n]  = ind;
			}
		}		
	}
}



void TMOEAD::evolution(int gen)
{	
	//record neighbor
    for(int i=0; i<population.size(); i++)
	{			
		
		int   n  =  i; 		
		TIndividual child, child2;
		compute_velocity(n,child,gen);
// 		realbinarycrossover(population[n].indiv,child,child, child2);
		if (i < pops*mutate_posibility)  
		realmutation(child); 
		child.obj_eval();
//		LocalSeach(child,population[n].namda);
		update_reference(child);
		update_problem(child, n);
		update_pbests(n);
	}
}


void TMOEAD::run(int sd, int nc, int mg, int rn)
{
    // sd: integer number for generating weight vectors
	// nc: size of neighborhood
	// mg: maximal number of generations 

	long start, end;
	niche = nc;	
	init_uniformweight(sd);
    init_neighbourhood();
	//start = clock();
	init_population();	
	//end = clock();
	//cout << (double)(end - start) / CLOCKS_PER_SEC << "s\t\t\t\t\n";
	store_pbests();
	init_velocity();
	for(int gen = 2; gen <= mg; gen++)   

	//for (int gen = 2; gen <= 2; gen++)
	{
		//start = clock();
	//	cout<<"the "<<gen<<"th iteration finished"<<endl;
		evolution(gen); 
	
		//end = clock();
		//cout << (double)(end - start) / CLOCKS_PER_SEC<<"s\t\t\t\t";
	}

	char savefilename0[1024];
	sprintf(savefilename0, "ParetoFront/DMOEA_%s_PF%d.txt", strReal, rn);
	save_results(savefilename0);
	char savefilename1[1024];
    sprintf(savefilename1,"ParetoFront/MODPSO_%s_front%d.txt",strReal,rn);
	save_front(savefilename1);
	char savefilename2[1024];
    sprintf(savefilename2,"variable/MODPSO_%s_R%d.txt",strReal,rn);
	save_chrom(savefilename2);

	population.clear();
}


void TMOEAD::save_front(char saveFilename[1024])
{
	
	vector<vector<double> >pop_x;

	for (int i = 0; i < pops; i++)
		pop_x.push_back(population[i].indiv.y_obj);
	
	front = remove_same_point(pop_x);

	ofstream fout_front(saveFilename,std::ios::out);
	fout_front<<"front = [";

	for(int n=0; n<front.size(); n++)
	{
		for(int k=0;k<numObjectives;k++)
			fout_front<<front[n][k]<<"  ";
		fout_front<<endl;
	}

	fout_front<<"];"<<endl;
	fout_front<<"plot(front(:,1),front(:,2),'r.');"<<endl;
	
	fout_front.close();

}

void TMOEAD::save_chrom(char *saveFilename)
{
	ofstream fout_chrom(saveFilename,ios::out|ios_base::app);
	//double temp = 0.0;
	for(int kk = 0; kk < population.size(); kk++) 
	{
		if (check_label())	
		{
			double temp_nmi = calc_NMI(population[kk].indiv.x_var,strlabel);
			fout_chrom<<" NMI = "<<temp_nmi<<"   ";
			//temp = temp_nmi;
			NMI.push_back(temp_nmi);
		}
		
		double Q = calcQ(population[kk].indiv.x_var);
		
		vector<int> copylabel;
		copylabel = population[kk].indiv.x_var;		
		vector<vector<int> >A;  //the detected community		
		for ( int i = 0;i < numVariables;i++ ){	//calculate A				
			if ( copylabel[i] != -1 ){
				vector<int> s1;	//store every component in each cluster
				s1.push_back(i);
				for ( int j = i+1;j < numVariables;j++ ){
					if ( copylabel[i] == copylabel[j] ){
						s1.push_back(j);
						copylabel[j] = -1;
					}
				}//end j
				copylabel[i] = -1;
				A.push_back(s1);
			}//end if
		}
		
		fout_chrom<<"modularity = "<<Q<<"; 分成了 "<<A.size()<<" 类"<<endl;
		A.clear(); copylabel.clear();

		modularity.push_back(Q);
		for(int k=0;k<numVariables;k++)
			fout_chrom<<population[kk].indiv.x_var[k]<<' ';
		fout_chrom<<endl<<endl;
		//if (temp == 1)break;
	}	
	
	if (check_label())
	{
		cout << setiosflags(ios::fixed);
		cout << setprecision(5) << "max NMI = " << *max_element(NMI.begin(), NMI.end()) << "    minNMI = " << *min_element(NMI.begin(), NMI.end())<<"      ";
		double sumNMI =accumulate(NMI.begin(), NMI.end(), 0.0) ;
		double avgNMI = sumNMI / NMI.size();
		cout << setprecision(5) << "avg NMI = " << avgNMI << "    ";
		fout_chrom<<"max NMI = "<<*max_element(NMI.begin(),NMI.end())<<endl;
		pm_NMI.push_back(*max_element(NMI.begin(),NMI.end()));
		Thirty_Run_NMI.push_back(*max_element(NMI.begin(),NMI.end()));
	}
	
	cout<<"max modularity = "<<*max_element(modularity.begin(),modularity.end())<<endl;
	fout_chrom<<"max modularity = "<<*max_element(modularity.begin(),modularity.end())<<endl<<endl;
	pm_modularity.push_back(*max_element(modularity.begin(),modularity.end()));
	Thirty_Run_modularity.push_back(*max_element(modularity.begin(),modularity.end()));

	fout_chrom.close();
}


void TMOEAD::save_results(char *archiveName)  /* Write results to file */
{
	unsigned int i, j;
	ofstream fout_PF(archiveName,ios::out);
	for (i = 0;i < population.size(); i++ )
	{
		for (j = 0; j < numObjectives; j++)
		{
			fout_PF<<population[i].indiv.y_obj[j]<<" ";
		}fout_PF<<endl;
	}
	
	fout_PF.close();
}


void TMOEAD::operator=(const TMOEAD &emo)
{
    pops        = emo.pops;
	population  = emo.population;
	indivpoint  = emo.indivpoint;
	niche       = emo.niche;
} 


#endif