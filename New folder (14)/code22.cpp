#include <iostream>
#include <string>

using namespace std;

int processes = 4, resources = 3, i, j, k;
string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
	int n = processes,
	    m = resources;

	cout << "Let the processes be:\n\t";
	for(int i=0; i<processes; i++){
		cout << "P" << i  << " ";


	}
	cout << "\nLet the resource types be named as:\n\t";
	for (i=0; i<resources; i++){
		cout << abc[i] << " ";
	}
	cout << "\n";


	int alloc[5][3] = { { 0, 1, 0 }, 
		{ 2, 0, 0 },
		{ 3, 0, 2 }, 
		{ 2, 1, 1 }, 
		{ 0, 0, 2 } },
	    max[5][3] = { { 7, 5, 3 }, 
		    { 3, 2, 2 }, 
		    { 9, 0, 2 },
		    { 2, 2, 2 }, 
		    { 4, 3, 3 } }, 


	    avail[3] = { 3, 3, 2 },
	    f[n], ans[n], ind = 0, need[n][m];

	
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}


	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}


	cout << "Need Matrix:\n";
	for (i=0; i<n; i++){
		for(j=0; j<m; j++){
			cout << need[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";


	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {            // Safety Algo

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){     // do not execute and go forward if need > available
						flag = 1;
						break;
					}
				}

				if (flag == 0) {               // need <= available
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];        // update the available
					f[i] = 1;
				}

			}
		}
	}



	cout << "Following is the SAFE Sequence" << endl;
	for (i = 0; i < n - 1; i++)
		cout << " P" << ans[i] << " ->";
	cout << " P" << ans[n - 1] <<endl;

	return (0);

}


