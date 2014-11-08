#include<iostream>
#include<map>
#include<string>
#include<stdlib.h>
#include<vector>
#include<limits.h>

using namespace std;

int main(){
	int num_words;
	int i=0,k=0;
	int max_count=INT_MIN;
	string word;
	map<string,int> word_freq_map;
	map<int,vector<string> > freq_word_map;
	vector<string> res;
	cin>>num_words;



	for(i=0;i<num_words;i++){
		cin>>word;
		map<string,int>::iterator mit=word_freq_map.find(word);
		if(mit==word_freq_map.end()){
			word_freq_map[word]=1;
		}
		else{
			word_freq_map[word]++;	
		}
	}

	cin>>k;

	map<string,int>::iterator mit=word_freq_map.begin();
	while(mit!=word_freq_map.end()){
		max_count=max(max_count,mit->second);
		freq_word_map[mit->second].push_back(mit->first);
		++mit;
	}
	
	for(i=max_count;i>0;i--){
		if(freq_word_map[i].empty()==false){
			int sz=freq_word_map[i].size();
			for(int j=0;j<sz;j++){
				if(k==0)
					break;
				res.push_back(freq_word_map[i][j]);
				k--;
			}
		}
	}
	int rsz=res.size();
	for(i=0;i<rsz;i++){
		cout<<res[i]<<endl;
	}
	
return 0;
}