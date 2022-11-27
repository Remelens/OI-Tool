#include "command.hpp"
const char version[50]="0.0.01-beta";
const char ver[50]="2022/11/26 14:20:43 main";
const char copyright[50]="Copyright (c) 2022 HelloOSMe";
const char license[100]="This file is under GNU General Public License v3.0";
string oi=GetInfo('n');
string priOI(){
	if(oi=="\0"){
		return "NULL";
	}
	return oi;
}
//-----------------------
void start(){
	cout<<"OI-Tool v"<<version<<" ["<<ver<<"]"<<endl;
	cout<<"Type \"help\",\"copyright\" or \"license\" for more information."<<endl;
}
int run(string cmd){
	string ncmd=bts(cmd);
	string first=GetCmd(ncmd,0);
	if(first=="help"){
		help(GetCmd(cmd,1));
		cout<<endl;
	}else if(first=="cd"){
		cd((GetCmd(cmd,1)=="cd"?"\0":GetCmd(cmd,1)));
		cout<<endl;
	}else if(first=="ls"){
		ls((GetCmd(cmd,1)=="ls"?char_to_str(getcwd(NULL,0)):GetCmd(cmd,1)));
		cout<<endl;
	}else if(first=="config"){
		config();
		cout<<endl;
	}else if(first=="copyright"){
		cout<<copyright<<endl;
		cout<<endl;
	}else if(first=="license"){
		cout<<license<<endl;
		cout<<endl;
	}else if(first=="exit"){
		exit(0);
	}else if(first=="open"){
		open(GetCmd(ncmd,1),GetCmd(ncmd,2),GetCmd(ncmd,3));
		cout<<endl;
	}else if(first=="cls"||first=="clear"){
		cls;
		cout<<endl;
	}else if(first=="\0"){
		
	}else{
		color(0,12);
		cout<<"No command named \""<<GetCmd(cmd,0)<<"\" !"<<endl;
		color(0,7);
		cout<<endl;
	}
	return 0;
}
int main(int argc,char** argv){
	if(argc!=1){
		string s;
		for(int i=1;i<argc;i++){
			s=s+" "+char_to_str(argv[i]);
		}
		run(s);
	}else{
		start();
		string cmd;
		while(1){
			oi=GetInfo('n');
			color(0,11);
			cout<<getcwd(NULL,0);
			color(0,10);
			cout<<" ["<<priOI()<<"]"<<endl;
			color(0,14);
			cout<<"$ ";
			color(0,7);
			getline(cin,cmd);
			run(cmd);
		}
	}
	return 0;
}
