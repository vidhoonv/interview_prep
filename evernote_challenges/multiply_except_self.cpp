#include<iostream>
#include<vector>
#include<sys/types.h>

using namespace std;

int main(){
	int num_elements;
	cin>>num_elements;

	vector<int64_t> input_list(num_elements);
	int64_t all_nz_prod=1;
	int zcount=0,zindex=-1;
	int i=0;
	for(i=0;i<num_elements;i++)
	{
		cin>>input_list[i];
	}

	for(i=0;i<num_elements;i++)
	{
		if(input_list[i]==0){
			zcount++;
			zindex=i;
			continue;
		}
		all_nz_prod*=input_list[i];
	}

	if(zcount>1){
		for(i=0;i<num_elements;i++)
		{
			input_list[i]=0;
			cout<<input_list[i]<<endl;
		}
	}
	else if(zcount==1){
		for(i=0;i<num_elements;i++)
		{
			input_list[i]=0;
			if(i==zindex)
				input_list[i]=all_nz_prod;
			cout<<input_list[i]<<endl;
		}
	}
	else{
		for(i=0;i<num_elements;i++)
		{
			input_list[i]=all_nz_prod/input_list[i];
			cout<<input_list[i]<<endl;		
		}
	}
	

	return 0;
}