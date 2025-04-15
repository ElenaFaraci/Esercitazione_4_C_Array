#include<iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	std::ifstream fstr("data.txt");
	std::ofstream oFile("result.txt");

	if(fstr.fail())
	{
		std::cerr << "File not found" << std::endl;
		return 1;
	}
	
	// leggo il valore di S
	string line0;
	getline(fstr,line0);
	string S_str;
	int i = line0.length();
	int j=0;
	string elt;
	while (j<i)
	{
		elt = line0[j];
		if (elt==";"){
			for (int k=j+1;k<i;k++){
				S_str = S_str + line0[k];
				}
		}
			
		j++;
			}
	double S = stod(S_str);
	
	// leggo il valore di n
	string line1;
	getline(fstr,line1);
	string n_str;
	int i1 = line1.length();
	int j1=0;
	string elt1;
	while (j1<i1)
	{
		elt1 = line1[j1];
		if (elt1==";"){
			for (int k1=j1+1;k1<i1;k1++){
				n_str = n_str + line1[k1];
				}
		}
			
		j1++;
			}
	int n = stod(n_str);
	
	string line2;
	getline(fstr, line2);

	// ricavo i vettori di double w, r e trovo il valore di V
	string line;
	double w[8];
	double r[8];
	int line_number = 0;
	double V = 0;
	
	while(fstr >> line)
	{
		int sep;
		string w_str;
		string r_str;
		string elt_line;
		int l = line.length();
		for (int i=0; i<l; i++){
			elt_line = line[i];
			if (elt_line==";"){
				sep = i;}
			}
		for (int i=0; i<sep; i++){
			w_str = w_str + line[i];
			}
		for (int i=sep+1; i<l; i++){
			r_str = r_str + line[i];
			}
		double w_prov = stod(w_str);
		double r_prov = stod(r_str);
		V = V + (1+r_prov)*S*w_prov;

		w[line_number] = w_prov;
		r[line_number] = r_prov;
		line_number ++;
		}
		
		// stampo i risultati
		cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
		oFile << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
		
		cout << "w = [ ";
		oFile << "w = [ ";
		for (int i = 0; i < n; i++){
			cout << w[i] << " ";
			oFile << w[i] << " ";
			}
		cout << "]" << endl;
		oFile << "]" << endl;

		
		cout << "r = [ ";
		oFile << "r = [ ";
		for (int i = 0; i < n; i++){
			cout << r[i] << " ";
			oFile << r[i] << " ";
			}
		cout << "]" << endl;
		oFile << "]" << endl;
		
		cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << V/S - 1 << endl;
		oFile << "Rate of return of the portfolio: " << fixed << setprecision(4) << V/S - 1 << endl;

		cout << "V: " << fixed << setprecision(2) << V << endl;
		oFile << "V: " << fixed << setprecision(2) << V << endl;

	return 0;
}
