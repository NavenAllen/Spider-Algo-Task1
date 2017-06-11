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

void prefFunc(string pat, int* f){
	int len=pat.size(), j=0;
	f[0]=0;
	for(int i=1; i<len; i++){
		while(j>=0&&(pat[j]!=pat[i])){
			if(j-1>=0){
				j=f[j-1];
			}
			else
				j=-1;
		}
		j++;
		f[i]=j;
	}
	return;
}

int main(){
	vector<string> lines = readPage(2);
	string pat="hellohello";	
	int f[pat.size()];
	prefFunc(pat, f);
        for(int i=0; i<pat.size(); i++){
		cout<<f[i]<<" ";
	}
		
}

