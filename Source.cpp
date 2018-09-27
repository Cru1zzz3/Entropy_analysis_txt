#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <map>

using namespace std;

int main(void){
	setlocale(LC_ALL, "rus");
	ifstream inputFile("input.txt"); // открыл файл для чтения
	string line;
	string::iterator lineIt;
	char ch;
	double sumSymbols = 0;
	int sumAlphabet = 0;
	double probability;
	multimap<char,int> alphabet;
	multimap<char,int>::iterator alphabetIter;
	cout.precision(10);
	
	if (!inputFile.is_open()){
		cout << "File could't be open..." << endl;
	}
	else {
		while (getline(inputFile,line)){
			if (line == ""){
			//	cout << endl;
			}
			else {
				//cout << line << endl;
				for (lineIt = line.begin(); lineIt != line.end(); ++lineIt){ // посимвольное считывание из строки
					//cout << *lineIt;
					ch = *lineIt; // символ из итератора
					alphabetIter = alphabet.find(ch);
					if (alphabetIter != alphabet.end()){ // если нашёл в алфавите
						//cout << " Found in alphabet" << endl;
						(alphabetIter->second)++;
						sumSymbols = alphabetIter->second + sumSymbols;
					}
					else {
						//cout << " Not found " << endl; // не нашёл в алфавите
						alphabet.insert (pair<char,int>(ch,1));
					}

					
				}
			}
		}
	}

	inputFile.close();
	cout << endl << endl;
	for (alphabetIter = alphabet.begin(); alphabetIter != alphabet.end(); alphabetIter++){
		cout << alphabetIter->first << "\t" << alphabetIter->second;
		probability = (alphabetIter->second)/sumSymbols;
		cout << fixed <<  "\t" << probability  << endl;
	}
	
	cout << "\n\nSymbols in alphabet: " << alphabet.size() << endl;
	cout << "Sum of Symbols: " << sumSymbols << endl;

	return 0;
}
