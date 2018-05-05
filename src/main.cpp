/*
 * main.cpp
 *
 *  Created on: 05-May-2018
 *      Author: abhinema
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <cstdint>
#include <vector>

using namespace std;

#include "random_number_gen.h"
#include "findRepeatedNumber.h"

//Enable to get debug logs
//#define DEBUG

/* Template functions */
template unsigned int findRepeateNumber(vector<unsigned int>& data);
template string findRepeateNumber(vector<string>& data);
template void randomNumGen (unsigned int &);
template void randomNumGen (string &);

template<class T> T main_check(int argc, char **argv,T a){
//initialization
	vector <T> data;
	typename vector <T>::iterator i;
	T val;
	T repeatedNum;
	unsigned int indexFromCopy = 0;
	unsigned int indexToCopy = 0;

	int count = atoi(argv[1]);
// Open and clear content of file
	ofstream myfile;
	myfile.open(argv[2],std::ofstream::out | std::ofstream::trunc);

#ifdef DEBUG
	cout<<"Calling random num gen for count:"<<count<<endl;
#endif
//Random number generation function call with count and data buffer
	for(int c = 0; c < count; c++){
		randomNumGen(val);
		data.push_back(val);
	}
//Get index from where element to copy
	randomNumGen(indexFromCopy);
	indexFromCopy = indexFromCopy % count;

//Get index to where element to copy
	randomNumGen(indexToCopy);
	indexToCopy = indexToCopy % count;

//Index to copy and index from copy should not be same....
	while(indexFromCopy == indexToCopy){
		randomNumGen(indexToCopy);
		indexToCopy = indexToCopy%count;
	}
//If Index from copy is greater than index to copy. swap the values
	if(indexFromCopy > indexToCopy)
		swap(indexFromCopy,indexToCopy);

//Copy data index from copy to index to copy
    data[indexToCopy] = data[indexFromCopy];

//Get Repeated Number
    repeatedNum = findRepeateNumber(data);

//Write data in file
    for (int c = 0; c < count ; c++) {
    	myfile<<"Val - "<<c<<" :"<<data[c]<<endl;
    	if (myfile.fail())  {
    		cout << "Error writing to data file\n";
    		myfile.clear();
    		exit(0);
    	}
    }
//Debug
#ifdef DEBUG
    cout<<"indexFromCopy: "<<indexFromCopy<< "  indexToCopy :"<<indexToCopy<<endl;
    for (int c = 0; c < count ; c++) {
    	cout<<"Val - "<<c<<" :"<<data[c]<<endl;
    }
//    cout<<"End of Program"<<endl;

    cout<<"==================   Summary   =================="<<endl;
    cout<<"Count: "<<count<<endl;
    cout<<"Repeated Val: "<<repeatedNum<<endl;
    cout<<"================== Summary Ends=================="<<endl;
#endif
    myfile<<"==================   Summary   =================="<<endl;
    myfile<<"Count: "<<count<<endl;
    myfile<<"Repeated Val: "<<repeatedNum<<endl;
    myfile<<"================== Summary Ends=================="<<endl;
    cout<<endl;
//Remove acquired resources
	myfile.close();
return repeatedNum;
}

template unsigned int main_check(int argc, char **argv,unsigned int a);
template string main_check(int argc, char **argv,string a);

/* ************************************************************************* */

int main(int argc, char **argv){
	unsigned int count = atoi(argv[1]);
	string check;
	char c;
	long l;
	long long ll;

	cout<<"Details of Program"<<endl;
	cout<<"========================================================================="<<endl;
	cout<<"To find two same numbers in given list of Random Number of same data type\n"
		  "First Random data generated and repeated number is found\n"
		  "And then data is stored in file(for future use) and displayed over console if DEBUG is enable"<<endl;
	cout<<"Please use command ./app <count> <data file>\n"
		  "Please check data file for data which can be used for future purpose"<<endl;
	cout<<"========================================================================="<<endl;


	if(argc != 3){
		cerr<<"\033[1;31mUse command wisely\n ,./test <num> <outputDataFile.txt>\033[0m"<<endl;;
		return 0;
	}
#if 0
	if(count > MAX_NUMBER_OF_PATTERN){
		cout<<  "\033[1;31mRecompile code with updated value for MAX_NUMBER_OF_PATTERN\033[0m \n"
				"\033[1;31m#define MAX_NUMBER_OF_PATTERN <NEW COUNT VALUE>\033[0m \n"
				"\033[1;31mg++ -std=c++11 -DMAX_NUMBER_OF_PATTERN=1000 -D DEBUG -o test  main.cpp -lcrypto\033[0m \n"
				"\033[1;31mWith INT_MAX count program is not working properly\033[0m\n"<<endl;
		exit(0);
	}
#endif
//	main_unsigned_int_check(argc, argv);

//	cout<<"Repeated Val:"<<main_check(argc, argv,count)<<endl;  //for unsigned int
//	cout<<"Repeated Val:"<<main_check(argc, argv,c)<<endl;      //for char...this wont give you more(1000) unique char and count should be less than 20
	cout<<"Repeated Val:"<<main_check(argc, argv,check)<<endl;  // for string
//	cout<<"Repeated Val:"<<main_check(argc, argv,l)<<endl;  // for long
//	cout<<"Repeated Val:"<<main_check(argc, argv,ll)<<endl;  // for long long
return 0;
}
/* End of File */
