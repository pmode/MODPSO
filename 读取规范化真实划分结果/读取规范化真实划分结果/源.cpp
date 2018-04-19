#include <iostream>
using namespace std;

int main()
{

	FILE *fpReadCommunity;
	FILE *fpWriteCommutity;
	fpWriteCommutity = fopen("real_500node.txt", "wb+");
	fpReadCommunity = fopen("community-500node.dat", "r");
	int i = 0;
	int temp = 0;
	static int community[10000];

	for (int i = 0; i < 10000;i++)
	{
		community[i] = 0;
	}

	
	for (i = 0;!feof(fpReadCommunity); i++)
	{
		fscanf(fpReadCommunity, "%d%d", &temp, &community[i]);
	}
	cout << i << endl;
	for (int j = 0; j < i; j++)
		fprintf(fpWriteCommutity, "%d\t", community[j]);
	getchar();
	getchar();
	return 0;
}