#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <map>

using namespace std;

double log2( double n )  
{  
    // log(n)/log(2) is log2.  
    return log( n ) / log( 2 );  
}  

int main(void){
	setlocale(LC_ALL, "rus");
	fstream inputFile("inputEnglish.txt"); // открыл файл для чтения
	char ch;
	double sumSymbols = 0;
	int sumAlphabet = 0;
	double probability = 0;
	double entropy = 0;
	double hartley = 0;
	multimap<char,int> alphabet;
	multimap<char,int>::iterator alphabetIter;
	cout.precision(10);

	if (!inputFile.is_open()){
		cout << "File could't be open..." << endl;
	}
	else {
		while (inputFile){
					inputFile >> ch;
					//cout << ch;
					alphabetIter = alphabet.find(ch);
					if (alphabetIter != alphabet.end() ){ // если нашёл в алфавите
						(alphabetIter->second)++;
						sumSymbols++;
					}
					else {
						alphabet.insert (pair<char,int>(ch,1));
						sumSymbols++;
					}		
		}
	}

	inputFile.close();
	cout << endl << endl;
	for (alphabetIter = alphabet.begin(); alphabetIter != alphabet.end(); alphabetIter++){
		cout << alphabetIter->first << "\t" << alphabetIter->second;
		probability = (alphabetIter->second)/sumSymbols;
		cout << fixed <<  "\t" << probability  << endl;
		entropy = (probability * log(probability)) + entropy;
	}

	
	cout << "\n\nSymbols in alphabet: " << alphabet.size() << endl;
	cout.precision(0);
	cout  << "Sum of Symbols: " << sumSymbols << endl;
	hartley  = log2(alphabet.size());
	cout << "Hartley formula log2N: " << hartley << endl;
	cout.precision(4);
	cout << "Entropy of file: " << -entropy << endl;

	return 0;
}
