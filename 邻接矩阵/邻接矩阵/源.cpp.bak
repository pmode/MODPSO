#include<iostream>
using namespace std;

int main()
{
	FILE* fp,*fpout;
	fp = fopen("network-500node.dat", "r");
	fpout = fopen("test-500.txt", "w+");
	static int network[10000][2], networkdata[1000][1000] ;
	for (int i = 0; i < 10000; i++)
	for (int j = 0; j < 2; j++)
		network[i][j] = 0; 
	for (int i = 0; i < 1000; i++)
	for (int j = 0; j < 1000; j++)
		network[i][j] = 0;

	int link_i = 0;
	if (fp!=NULL)
	for (link_i = 0; !feof(fp); link_i++)
		fscanf(fp, "%d%d", &network[link_i][0], &network[link_i][1]);
	else "err";
	int node_num = 0;
	if (network[link_i - 1][0])
		node_num = network[link_i - 1][0];
	else
		node_num = network[link_i - 2][0];

	for (int i = 0; i < link_i; i++)
		networkdata[network[i][0]][network[i][1]]=1;

	for (int i = 1; i <= node_num; i++){
		for (int j = 1; j <= node_num; j++)
			fprintf(fpout, "%d\t", networkdata[i][j]);
		fprintf(fpout, "\n");
	}
	getchar();
	getchar();
	return 0;
}