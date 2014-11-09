#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
	int capacity;
	int ins_pos=0,del_pos=0;
	
	int sz=0;

	cin>>capacity;
	vector<string> buff(capacity,"");
	bool done=false;
	while(done==false){
		string cmd;
		cin>>cmd;
		int num_words;
		int j=0;	
		if(cmd=="A"){
					
					cin>>num_words;
					getline(cin, cmd);
					for(int i=0;i<num_words;i++){	
						string word;	
						getline(cin, word);
						//cout<<word<<endl;	
						//addword
						if(ins_pos==capacity){ 
							ins_pos=0; 	
						}	
						if(sz==capacity){
							del_pos++;
							del_pos=del_pos%capacity;
						}
						buff[ins_pos]=word;	
						ins_pos++;	
						if(sz<capacity)	
							sz++;	
					}
		}else if(cmd=="R"){
					
					cin>>num_words;	
				for(int i=0;i<num_words;i++){	
						if(sz==0)	
							continue;	
						if(del_pos==capacity)
							del_pos=0;	
						buff[del_pos]="";	
						del_pos++;	
						if(sz>0)	
							sz--;	
					}
		}else if(cmd=="L"){
					if(sz==0)	
						continue;	
					j=del_pos;	
					if(del_pos<ins_pos){	
						while(j<ins_pos){	
							cout<<buff[j++]<<endl;	
						}	
					}	
					else{	
						while(j<capacity){	
							cout<<buff[j++]<<endl;	
						}	
						j=0;	
						while(j<ins_pos){	
							cout<<buff[j++]<<endl;	
						}	
					}	
		}else if(cmd=="Q"){
					buff.clear();
					done=true;
		}
	}
	return 0;
}