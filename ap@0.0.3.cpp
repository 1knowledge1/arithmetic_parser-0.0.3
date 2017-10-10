#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	string string; 
	getline(cin, string);
	istringstream stream(string);
	int n = 0;
	float res;

	float *num = new float[n];
	char *sgn = new char[n];
	
	for (; stream >> num[n]; n++) if (!(stream >> sgn[n])) break;
	
	for (int i = 0; i < n; i++) {
		
		if (sgn[i] == '*') 
		{
			num[i] = num[i] * num[i+1];
			
			for (int j = i; j <(n-1); j++) {
				sgn[j] = sgn[j+1];
				num[j+1] = num[j+2];
			} 
			sgn[n - 1] = '+'; num[n] = 0.0; i--;
		}

		if (sgn[i] == '/')
		{	
			if (num[i + 1] == 0) {
				cout << "Can not divide by 0\n";
				return 0;
			}
			num[i] = num[i] / num[i + 1];

			for (int j = i; j <(n - 1); j++) {
				sgn[j] = sgn[j + 1];
				num[j + 1] = num[j + 2];
			}
			sgn[n - 1] = '+'; num[n] = 0.0; i--;
		}

	}
	res = num[0];
	for (int i = 0; i <= n; i++) {
		if (sgn[i] == '+') res = res + num[i+1];
		if (sgn[i] == '-') res = res - num[i+1];
	}
	cout << res << endl;

    return 0;
}
