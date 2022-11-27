#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<dirent.h>
#include<unistd.h>
#define cls system("cls");
#define Utc 8
#define GT_YEA 0x000000
#define GT_MON 0x000001
#define GT_DAY 0x000002
#define GT_HOU 0x000003
#define GT_MIN 0x000004
#define GT_SEC 0x000005
using namespace std;
string bts(string str){
	int a,len=str.size();
	for(a=0;a<len;a++){
		if(str[a]>='A'&&str[a]<='Z'){
			str[a]=str[a]+32;
		}
	}
	return str;
}
extern string char_to_str(char ch[]){
	string s;
	for(int i=0;i<strlen(ch);i++){
		s.push_back(ch[i]);
	}
	return s;
}
extern string GetCmd(string str,int num){
	int space=0,zb=0;
	string nowstr;
	for(int i=str.size()-1;str[i]==' ';i--){
		str.erase(i);
	}//抹除尾部空格
	int numj=0;
	for(int i=0;str[i]==' ';i++){
		if(i==0){
			str[i]='\0';
			numj=1;
		}else{
			str.erase(i);
		}
	}
	if(numj==1){
		for(int i=1;i<str.size();i++){
			str[i-1]=str[i];
		}
		str.erase(str.size()-1);
	}
	if(num==0){
		for(int i=0,j=0;i<str.size();i++){
			if(str[i]==' '){
				break;
			}
			nowstr.push_back(str[i]);
			j++;
		}
		return nowstr;
	}
	for(int i=0;i<str.size();i++){
		if(str[i]==' '){
			space++;
		}
		if(space==num){
			zb=i+1;
			break;
		}
	}
	if(space==0){
		return str;
	}
	for(int i=zb,j=0;i<str.size();i++){
		if(str[i]==' '){
			break;
		}
		nowstr.push_back(str[i]);
		j++;
	}
	return nowstr;
}
extern void color(int a,int b){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a*16+b);
}
int GetTimes(int lei){
	time_t now_time;
	now_time = time(NULL);
	tm* timer=gmtime(&now_time);
	if(lei==0){
		return 1900+timer->tm_year;
	}else if(lei==1){
		return 1+timer->tm_mon;
	}else if(lei==2){
		return timer->tm_mday;
	}else if(lei==3){
		return timer->tm_hour+Utc;
	}else if(lei==4){
		return timer->tm_min;
	}else if(lei==5){
		return timer->tm_sec;
	}else{
		return now_time;
	}
}
