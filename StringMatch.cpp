#include<string>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

vector<string> readPage(int pgno){
	vector<string> lines;	
	char linesin[1000][1000];
	string filename = "page_1.txt";
	filename[5]='0'+pgno;
	//filename+=(string)pgno;
	int i=0;
	ifstream ifile;
	ifile.open(filename.c_str(), ios::in);
	if(!ifile){
		cout<<"File "<<filename<<" not opened properly!";
		return lines;
	}
	while(ifile.getline(linesin[i], 1000)){
		lines.push_back(linesin[i]);
		i++;
	}
	
	return lines;
}

int* prefFunc(string pat){
	int len=pat.size();
	int f[len];
	int j=0;
}

int main(){
	vector<string> lines = readPage(2);
	for(int i=0; i<lines.size(); i++){
		cout<<lines[i]<<"\n";
	}
}

