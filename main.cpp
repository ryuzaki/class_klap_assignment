#include<bits/stdc++.h>
using namespace std;

#define nl cout<<"\n"
#define take_input freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

struct car{
	string reg_no;
	string color;
};

class Park{
	
	car* arr[100];
	int ind[100];
	int n;
	public:
    	Park(int n)
		{
        	for(int i=0;i<n;i++)
        	{
            	ind[i]=0;
            	arr[i]=NULL; 
       		}
        	this->n = n;
    	}     

		int allocate(string res,string col);
		int freeslot(int slot);
		void status();
		void findr(string color); 
		void finds(string);
		void findrr(string);
};

void Park::findrr(string reg)
{
	bool found = true;
	for(int i=0;i<n;i++)
  	{
    	if(ind[i] != 0)
    	{
    		if(((arr[i])->reg_no) ==reg)
       		{ 
       			found = false; 
		   		cout<<(i+1);
        		break ;
       		}
   	 	}
  	} 
  	if(found)
  		cout<<"Not found";

  	nl; 
}

void Park::finds(string color)
{
	bool found = true;
	for(int i=0;i<n;i++)
	{
		if(ind[i] != 0)
		{
			if(((arr[i])->color) ==color){
				found = false;
				cout<<(i+1)<<", ";
			}
		}
  	}
  	if(found)
  		cout<<"Not found";

	nl;
}
void Park::findr(string color)
{
	bool found = true;
	for(int i=0;i<n;i++)
	{
		if(ind[i] != 0)
    	{
			if(((arr[i])->color) ==color){
				found = false;
				cout<<((arr[i])->reg_no)<<", ";
			}
    	}
	}
	if(found)
		cout<<"Not found";

	nl;
}

void Park::status()
{ 
	cout<<"Slot No. Registration No. Color\n";
	for(int i=0;i<n;i++)
	{   
		if(ind[i] != 0)
		{
			cout<<(i+1)<<"\t "; 
			cout<<((arr[i])->reg_no)<<"\t  "<<((arr[i])->color)<<endl;
    	}
      	else	
   		{
    		
   		}
    }
}

int Park::freeslot(int slot)
{
	if(slot <= n)
	{
    	ind[slot-1]=0;
    	arr[slot-1]=NULL;
    	return slot;
  	}
}

int Park::allocate(string res, string col)
{  
	int flag =-1; 
   	for(int i = 0 ; i<n ; i++)
	{
     	if(ind[i] == 0)
      	{
	        ind[i] = 1;
	        arr[i] = (car *)new car;
	        (arr[i])->reg_no = res;
	        (arr[i])->color = col;
	        flag = i;
	        break;
      	}
   	}
    return flag;   
}

int main(){
		
	take_input;
	fast;
	int n;
	string k;
	cin>>k;
    cin>>n;
  	cout<<k<<"\t"<<n<<endl;
  	Park p1(n);
  	cout<<"Created a parking lot with "<<n<<" slots"<<endl;
   	string s1,s2,s3;
   	while(cin>>s1) // taking input till the end of input file 
	{  
		if(s1 == "park")
  		{
    		cin>>s2>>s3;  
			int flag = p1.allocate(s2,s3); 
				if(flag == -1)
					cout<<"Sorry,parking lot is full\n";
				else
					cout<<"Allocated slot number: "<<(flag+1)<<endl;
  		}
  		if(s1 == "leave")
  		{  
			int ss2;
     		cin>>ss2;
     		int flag = p1.freeslot(ss2);
     		cout<<"slot number "<<flag<<" free\n";
		}
 		if(s1 == "status")
  		{  
     		p1.status();
  		}
 		if(s1 == "registration_numbers_for_cars_with_colour")
 		{  
			cin>>s2;
    		p1.findr(s2);
 		}  
 		if(s1 =="slot_numbers_for_cars_with_colour")
 		{
   			cin>>s2;
   			p1.finds(s2);
  		}
  		if(s1 == "slot_number_for_registration_number")
  		{
    		cin>>s2;
   			p1.findrr(s2);
  		}
	}
	return 0;
}
