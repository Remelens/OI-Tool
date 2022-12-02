#include "easy-project.hpp"
const char* path=getcwd(NULL,0);
extern void help(string cd){
	string cmd=bts(cd);
	if(cmd=="help"){
		cout<<"OI-Tool helps"<<endl;
		cout<<"usage: help [command-name] / help"<<endl<<endl;
		cout<<"cat\t\t\tOpen the file."<<endl;
		cout<<"cd\t\t\tGet into the floder."<<endl;
		cout<<"cls/clear\t\tClean screen."<<endl;
		cout<<"config\t\t\tConfig the software."<<endl;
		cout<<"copyright\t\tSee the copyright."<<endl;
		cout<<"help\t\t\tGet helps."<<endl;
		cout<<"license\t\t\tSee the license."<<endl;
		cout<<"ls\t\t\tSee the floders."<<endl;
		cout<<"open\t\t\tOpen the website."<<endl;
		//cout<<"downld\t\t\tDownload the data point.[buliding]"<<endl;//pre
		cout<<"update\t\t\tUpdate the Software."<<endl;
		//-----------------
	}else if(cmd=="cd"){
		cout<<"usage: cd [floder]"<<endl;
	}else if(cmd=="config"){
		cout<<"usage: config"<<endl;
	}else if(cmd=="copyright"){
		cout<<"usage: copyright"<<endl;
	}else if(cmd=="license"){
		cout<<"usage: license"<<endl;
	}else if(cmd=="ls"){
		cout<<"usage: ls [floder]"<<endl;
	}else if(cmd=="open"){
		cout<<"usage: open [command -p/-t/-c/-r/-d/-h] [data]"<<endl;
		cout<<"  -p/problem [ProblemID]"<<endl;
		cout<<"    Open the problem numbered [ProblemID]."<<endl;
		cout<<"  -t/training [PLID]"<<endl;
		cout<<"    Open the problem list numbered [PLID]."<<endl;
		cout<<"  -c/contest [ContestID]"<<endl;
		cout<<"    Open the contest numbered [ContestID]"<<endl;
		cout<<"  -r/record [UserID] [ProblemID]"<<endl;
		cout<<"    Open record pages."<<endl;
		cout<<"  -d/discuss [DiscussID]"<<endl;
		cout<<"    See the discuss numbered [DiscussID]."<<endl;
		cout<<"  -h/--help/help"<<endl;
		cout<<"    Get helps."<<endl;
	}/*else if(cmd=="downld"){
		cout<<"usage: downld [ProblemID]"<<endl;
	}*/else if(cmd=="update"){
		cout<<"usage: update"<<endl;
	}else if(cmd=="cls"||cmd=="clear"){
		cout<<"usage: cls/clear"<<endl;
	}else if(cmd=="cat"){
		cout<<"usage cat [FileName]"<<endl;
	}else{
		color(0,12);
		cout<<"No command named \""<<cd<<"\" !"<<endl;
		color(0,7);
	}
}
extern void cd(string floder){
	if(floder=="\0"){
		cout<<"usage: cd [floder]"<<endl;
		return;
	}
	if(floder=="-h"||floder=="--help"){
		cout<<"usage: cd [floder]"<<endl;
	}
	char floder2[256]={'\0'};
	for(int i=0;i<floder.size();i++){
		floder2[i]=floder[i];
	}
	if(chdir(floder2)==-1){
		color(0,12);
		cout<<"Failed! No floder named \""<<floder<<"\" in \""<<getcwd(NULL,0)<<"\" !"<<endl;
		color(0,7);
	}
}
extern bool have_file(const char* f2){
	ifstream fin (f2);
	return fin.is_open();
}
extern int ls(string floder){
	if(floder=="-h"||floder=="--help"){
		cout<<"usage: ls [floder]"<<endl;
	}
	cout<<"Floder:";
	color(0,11);
	cout<<floder<<endl<<endl;
	color(0,7);
	char argv[256]={'\0'};
	for(int i=0;i<floder.size();i++){
		argv[i]=floder[i];
	}
	DIR *dp;
	struct dirent *dirp;
	if(strlen(argv)==0){
		printf("Usage:dir directory_name\n");
		return 1;
	}
	if((dp=opendir(argv))==NULL){
		printf("Cannot open%s.\n",argv);
		printf("Try to use sudo.\n");
		return 1;
	}
	int num=0;
	while((dirp=readdir(dp))!=NULL){
		if(!have_file(dirp->d_name)){
			cout<<"/";
			color(0,14);
			printf("%-24s ",dirp->d_name);
			color(0,7);
			num++;
		}
		if(num==3){
			num=0;
			cout<<endl;
		}
	}
	dp=opendir(argv);
	while((dirp=readdir(dp))!=NULL){
		if(have_file(dirp->d_name)){
			color(0,15);
			printf("%-25s ",dirp->d_name);
			color(0,7);
			num++;
		}
		if(num==3){
			num=0;
			cout<<endl;
		}
	}
	closedir(dp);
	return 0;
}
extern string GetInfo(char a){
	char cff[1024];
	sprintf(cff,"%s/oi.tool",path);
	ifstream fin (cff);
	string name,p,t,c,r,d;
	getline(fin,name);
	getline(fin,p);
	getline(fin,t);
	getline(fin,c);
	getline(fin,r);
	getline(fin,d);
	fin.close();
	switch(a){
	case 'n':
		return name;
	case 'p':
		return p;
	case 't':
		return t;
	case 'c':
		return c;
	case 'r':
		return r;
	case 'd':
		return d;
	default:
		return "NULL";
	}
}
extern string inputnet(){
	cout<<"Example:https://www.luogu.com.cn/"<<endl;
	string s;
	cout<<"> ";
	getline(cin,s);
	return s;
}
extern string inputoj(){
	cout<<"OJ"<<endl;
	string s;
	cout<<"> ";
	getline(cin,s);
	return s;
}
extern void savedata(string name,string p,string t,string c,string r,string d){
	ofstream fout ("oi.tool");
	fout<<name<<endl;
	fout<<p<<endl;
	fout<<t<<endl;
	fout<<c<<endl;
	fout<<r<<endl;
	fout<<d<<endl;
}
extern void config(){
	char cff[1024];
	sprintf(cff,"%s/oi.tool",path);
	if(!have_file(cff)){
		ofstream fout (cff);
		fout.close();
	}
	ifstream fin (cff);
	string name,p,t,c,r,d;
	getline(fin,name);
	getline(fin,p);
	getline(fin,t);
	getline(fin,c);
	getline(fin,r);
	getline(fin,d);
	fin.close();
	while(1){
		cout<<"Config:"<<endl;
		cout<<"[1]Config OJ name"<<endl;
		cout<<"[2]Config Problem net"<<endl;
		cout<<"[3]Config ProblemList net"<<endl;
		cout<<"[4]Config Contest net"<<endl;
		cout<<"[5]Config Record net"<<endl;
		cout<<"[6]Config Discuss net"<<endl;
		cout<<"[7]Set"<<endl;
		cout<<"[8]Help"<<endl;
		cout<<"[0]exit"<<endl;
		char n;
		cout<<"> ";
		n=getchar();
		getchar();
		if(n=='1'){
			name=inputoj();
			savedata(name,p,t,c,r,d);
			cout<<"Successfully."<<endl;return;
		}else if(n=='2'){
			p=inputnet();
			savedata(name,p,t,c,r,d);
			cout<<"Successfully."<<endl;return;
		}else if(n=='3'){
			t=inputnet();
			savedata(name,p,t,c,r,d);
			cout<<"Successfully."<<endl;return;
		}else if(n=='4'){
			c=inputnet();
			savedata(name,p,t,c,r,d);
			cout<<"Successfully."<<endl;return;
		}else if(n=='5'){
			r=inputnet();
			savedata(name,p,t,c,r,d);
			cout<<"Successfully."<<endl;return;
		}else if(n=='6'){
			d==inputnet();
			savedata(name,p,t,c,r,d);
			cout<<"Successfully."<<endl;return;
		}else if(n=='7'){
			while(1){
				cout<<"Config:SetOJ:"<<endl;
				cout<<"[1]Luogu"<<endl;
				cout<<"[2]CodeForces"<<endl;
				cout<<"[9]BackToConfig"<<endl;
				cout<<"[0]exit"<<endl;
				char m;
				cout<<"> ";
				m=getchar();
				getchar();
				if(m=='1'){
					name="Ве№И/Luogu";
					p="https://www.luogu.com.cn/problem/";
					t="https://www.luogu.com.cn/training/";
					c="https://www.luogu.com.cn/contest/";
					r="https://www.luogu.com.cn/record/";
					d="https://www.luogu.com.cn/discuss/";
					savedata(name,p,t,c,r,d);
					cout<<"Successfully."<<endl;return;
				}else if(m=='2'){
					name="Codeforces";
					p="https://codeforces.com/problem/";
					t="https://codeforces.com/";
					c="https://codeforces.com/contest";
					r="https://codeforces.com/";
					d="https://codeforces.com/";
					savedata(name,p,t,c,r,d);
					cout<<"Successfully."<<endl;return;
				}else if(m=='9'){
					savedata(name,p,t,c,r,d);
					break;
				}else if(m=='0'){
					savedata(name,p,t,c,r,d);
					return;
				}else{
					color(0,12);
					cout<<"InputERROR:"<<n<<endl;
					color(0,7);
				}
			}
		}else if(n=='8'){
			cout<<"usage: config"<<endl;
		}else if(n=='0'){
			savedata(name,p,t,c,r,d);
			return;
		}else{
			color(0,12);
			cout<<"InputERROR:"<<n<<endl;
			color(0,7);
		}
	}
}
extern void open(string s,string id,string id2){
	char cff[1024];
	sprintf(cff,"%s/oi.tool",path);
	if(!have_file(cff)){
		color(0,12);
		cout<<"ConfigERROR: Don't find the config file.";
		color(0,15);
		cout<<"Try to config again?[y/n]>";
		color(0,7);
		char ch;
		ch=getchar();
		getchar();
		if(ch=='y'||ch=='Y'){
			config();
			cout<<"Jumping to \"open\" ..."<<endl;
		}else if(ch=='n'||ch=='N'){
			color(0,12);
			cout<<"Failed:Did not config."<<endl;
			color(0,7);
			return;
		}else{
			color(0,12);
			cout<<"InputERROR:"<<ch<<endl;
			color(0,7);
			return;
		}
	}
	ifstream fin (cff);
	string name,p,t,c,r,d;
	getline(fin,name);
	getline(fin,p);
	getline(fin,t);
	getline(fin,c);
	getline(fin,r);
	getline(fin,d);
	char url[1024]={'\0'};
	if(s=="-h"||s=="--help"||s=="help"){
		cout<<"usage: open [command -p/-t/-c/-r/-d/-h] [data]"<<endl;
		cout<<"  -p/problem [ProblemID]"<<endl;
		cout<<"    Open the problem numbered [ProblemID]."<<endl;
		cout<<"  -t/training [PLID]"<<endl;
		cout<<"    Open the problem list numbered [PLID]."<<endl;
		cout<<"  -c/contest [ContestID]"<<endl;
		cout<<"    Open the contest numbered [ContestID]"<<endl;
		cout<<"  -r/record [UserID] [ProblemID]"<<endl;
		cout<<"    Open record pages."<<endl;
		cout<<"  -d/discuss [DiscussID]"<<endl;
		cout<<"    See the discuss numbered [DiscussID]."<<endl;
		cout<<"  -h/--help/help"<<endl;
		cout<<"    Get helps."<<endl;
	}else if(s=="-p"||s=="problem"){
		string a="start "+p+id;
		for(int i=0;i<a.size();i++){
			url[i]=a[i];
		}
		system(url);
	}else if(s=="-t"||s=="training"){
		string a="start "+t+id;
		for(int i=0;i<a.size();i++){
			url[i]=a[i];
		}
		system(url);
	}else if(s=="-c"||s=="contest"){
		string a="start "+c+id;
		for(int i=0;i<a.size();i++){
			url[i]=a[i];
		}
		system(url);
	}else if(s=="-r"||s=="record"){
		string a;
		if(id2=="*"||id2=="."){
			a="start \"\" \""+r+"list?user="+id;
		}else if(id=="*"||id=="."){
			a="start \"\" \""+r+"list?pid="+id2+"\"";
		}else{
			a="start \"\" \""+r+"list?user="+id+"&pid="+id2+"\"";
		}
		for(int i=0;i<a.size();i++){
			url[i]=a[i];
		}
		//cout<<url<<endl;
		system(url);
	}else if(s=="-d"||s=="discuss"){
		string a="start "+d+id;
		for(int i=0;i<a.size();i++){
			url[i]=a[i];
		}
		system(url);
	}else{
		cout<<"usage: open [command -p/-t/-c/-r/-d/-h] [data]"<<endl;
		cout<<"  -p/problem [ProblemID]"<<endl;
		cout<<"    Open the problem numbered [ProblemID]."<<endl;
		cout<<"  -t/training [PLID]"<<endl;
		cout<<"    Open the problem list numbered [PLID]."<<endl;
		cout<<"  -c/contest [ContestID]"<<endl;
		cout<<"    Open the contest numbered [ContestID]"<<endl;
		cout<<"  -r/record [UserID] [ProblemID]"<<endl;
		cout<<"    Open record pages."<<endl;
		cout<<"  -d/discuss [DiscussID]"<<endl;
		cout<<"    See the discuss numbered [DiscussID]."<<endl;
		cout<<"  -h/--help/help"<<endl;
		cout<<"    Get helps."<<endl;
	}
	fin.close();
}
extern bool is_num(string s){
	if(s[0]=='0'&&s[1]=='x'){
		for(int i=2;i<s.size();i++){
			if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f')||(s[i]>='A'&&s[i]<='F')||(s[i]=='l'&&i>2)){
				
			}else{
				return 0;
			}
		}
		return 1;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			
		}else{
			return 0;
		}
	}
	return 1;
}
extern void readfile(string filename){
	char file[2048];
	for(int i=0;i<filename.size();i++){
		file[i]=filename[i];
	}
	ifstream fin (file);
	if(!fin.is_open()){
		cout<<file<<endl;
		//cout<<"No file named "<<filename<<" or you are not the Administrator!"<<endl;
		//return;
	}
	string s;
	int zs=0;
	int hang=1;
	while(getline(fin,s)){
		string s2,s3;
		s+=" ";
		if(zs==2) zs=0;
		color(0,7);
		printf("%-5d| ",hang);
		for(int i=0;i<s.size();i++){
			if(s[0]=='#'){
				color(0,14);
				cout<<s;
				color(0,7);
				break;
			}if(!(s[i]=='_'||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9'))){
				if(s[i]=='/'){
					zs=1;
				}else if(s2=="alignas"||s2=="alignof"||s2=="constexpr"||s2=="char16_t"||s2=="char32_t"||s2=="decltype"||s2=="nullptr"||s2=="noexcept"||s2=="static_assert"||s2=="auto"||s2=="const_cast"||s2=="dynamic_cast"||s2=="reinterpret_cast"||s2=="static_cast"||s2=="bool"||s2=="true"||s2=="flase"
					||s2=="break"||s2=="continue"||s2=="goto"||s2=="case"||s2=="switch"||s2=="break"||s2=="catch"||s2=="throw"||s2=="try"||s2=="char"||s2=="wchar"||s2=="wchar_t"||s2=="volatile"||s2=="const"||s2=="struct"||s2=="class"||s2=="union"||s2=="delete"||s2=="new"||s2=="do"||s2=="for"||s2=="while"||s2=="if"
					||s2=="else"||s2=="enum"||s2=="explicit"||s2=="export"||s2=="extern"||s2=="friend"||s2=="inline"||s2=="mutable"||s2=="namespace"||s2=="operator"||s2=="private"||s2=="protected"||s2=="register"||s2=="return"||s2=="static"||s2=="sizeof"||s2=="template"||s2=="this"||s2=="typedef"||s2=="virtual"||s2=="typeid"
					||s2=="typename"||s2=="using"||s2=="void"||s2=="int"||s2=="short"||s2=="long"||s2=="double"||s2=="float"||s2=="char"||s2=="public"||s2=="exit"
					){
					color(0,2);
				}else if(s[i]=='('){
					color(0,3);
				}else if(s3=="bool"||s3=="int"||s3=="short"||s3=="long"||s3=="double"||s3=="float"||s3=="char"||s3=="string"){
					color(0,4);
				}else if(s2=="or"||s2=="and"||s2=="not"||s2=="or_eq"||s2=="xor"||s2=="xor_eq"){
					color(0,5);
				}else if(s2=="vector"||s2=="string"||s2=="std"||s2=="cin"||s2=="cout"||s2=="endl"||s2=="pair"||s2=="queue"||s2=="priority_queue"||s2=="stack"||s2=="deque"||s2=="set"||s2=="map"||s2=="multiset"||s2=="multimap"||s2=="unordered_set"||s2=="unordered_map"||s2=="unordered_multiset"||s2=="unordered_multimap"||s2=="bitset"){
					color(0,6);
				}else if(is_num(s2)){
					color(0,11);
				}
				cout<<s2;
				color(0,7);
				if(zs){
					zs=0;
					color(0,8);
					if(s[i+1]=='/'){
						while(i<s.size()){
							cout<<s[i];
							i++;
						}
						color(0,7);
						break;
					}else if(s[i+1]=='*'){
						bool ex=0;
						while(i<s.size()){
							if(s[i]=='*'&&s[i+1]=='/'){
								cout<<"*/";
								ex=1;
								break;
							}
							cout<<s[i];
							i++;
						}
						if(ex!=1){
							hang++;
							color(0,8);
							cout<<endl;
							while(getline(fin,s)){
								color(0,7);
								printf("%-5d| ",hang);
								color(0,8);
								s+=" ";
								for(int j=0;j<s.size();j++){
									i=j;
									if(s[j]=='*'&&s[j+1]=='/'){
										cout<<"*/";
										ex=1;
										break;
									}
									cout<<s[j];
								}
								if(ex){
									break;
								}
								cout<<endl;
								hang++;
							}
						}
					}
				}else if(s[i]=='"'){
					bool ex=0;
					color(0,9);
					cout<<"\"";
					i++;
					while(i<s.size()){
						if(s[i]=='"'&&s[i-1]!='\\'){
							cout<<"\"";
							ex=1;
							break;
						}
						cout<<s[i];
						i++;
					}
					color(0,7);
				}else if(s[i]=='\''){
					color(0,9);
					cout<<"'";
					i++;
					while(i<s.size()){
						if(s[i]=='\''&&!(s[i-1]=='\\'&&s[i-2]!='\\')){
							cout<<"'";
							break;
						}
						cout<<s[i];
						i++;
					}
				}else if(s[i]=='\t'){
					cout<<"    ";
				}else{
					cout<<s[i];
				}
				s3=s2;
				s2="";
			}else{
				s2.push_back(s[i]);
			}
		}
		cout<<endl;
		hang++;
	}
}
