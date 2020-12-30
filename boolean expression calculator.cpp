#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<math.h>
using namespace std;

class node{
	public:
		char data;
		long long int value; 
		node* next;
		node* prev;
		
	
		node(char d){
			data=d;
			value=0;
			next=0;
			prev=0;
		}
		node (char d,node* n,node* p){
			data=d;
			value=0;
			next=n;
			prev=p;
		}
};

class dlist{
	private: 
	
	node *head,*tail;
	
	public: 
	
	dlist(){
		head=tail=0;
	}
	
	void addnode(char d){
		if(head==0){

			head=new node(d);
			tail=head;
		}
		else{
			tail->next=new node(d);
			tail->next->prev=tail;
			tail=tail->next;
		}
	}
	
	void display(){
		node* temp;
		for(temp=head;temp!=0;temp=temp->next){
			cout<<temp->data<<"=>";
		}
		
		cout<<endl;
	}

	void buildlist (string exp)
	{
		for(int i=0;i<exp.length();i++)
		{
			char data=exp[i];
			addnode(data);
		}
		display();
	}
	
	void assignval1 (char *a, long long int *b, int limit)
	{
		node *temp=head;
		int safe;
		
		for( ; temp != NULL ; temp=temp->next)
		{
			//cout<<"hello1"<<endl;
			
			if ( ((temp->data >= 'a') && (temp->data <= 'z')) || ((temp->data >= 'A') && (temp->data <= 'Z')) )
			{
				//cout<<"hello"<<endl;
				
				for (int i=0; i<limit ; i++)
				{
					if (temp->data == a[i])
					{
						safe=i;
						break;
					}
				}
				
				temp->value=b[safe];
			}
		}
	}
	
	void displayval ()
	{
		node* temp;
		for(temp=head;temp!=0;temp=temp->next)
		{
			cout<<temp->value<<"=>";
		}
		
		cout<<endl;
	}
	
	long long int solve ()
	{
		node *temp=head;
		long long int result=0;
		long long int temp1;
		long long int temp2;
		
		for ( ; temp!=NULL ; temp=temp->next)
		{
			if (temp->data == '+')
			{
				//cout<<"plus"<<endl;
				temp1=temp->prev->value;
				temp2=temp->prev->prev->value;
				result = add (temp1, temp2);
				//cout<<result<<endl;
				deletion (temp->prev->prev);
				deletion (temp->prev);
				temp->value=result;
			}
			else if (temp->data == '-')
			{
				//cout<<"minus"<<endl;
				temp1=temp->prev->value;
				temp2=temp->prev->prev->value;
				result = sub (temp1, temp2);
				//cout<<result<<endl;
				deletion (temp->prev->prev);
				deletion (temp->prev);
				temp->value=result;
			}
			else if (temp->data == '*')
			{
				//cout<<"multiply"<<endl;
				temp1=temp->prev->value;
				temp2=temp->prev->prev->value;
				result = mul (temp1, temp2);
				//cout<<result<<endl;
				deletion (temp->prev->prev);
				deletion (temp->prev);
				temp->value=result;
			}
			else if (temp->data == '/')
			{
				//cout<<"devide"<<endl;
				temp1=temp->prev->value;
				temp2=temp->prev->prev->value;
				result = div (temp1, temp2);
				//cout<<result<<endl;
				deletion (temp->prev->prev);
				deletion (temp->prev);
				temp->value=result;
			}
			else if (temp->data == '%')
			{
				//cout<<"mod"<<endl;
				temp1=temp->prev->value;
				temp2=temp->prev->prev->value;
				result = mod (temp1, temp2);
				//cout<<result<<endl;
				deletion (temp->prev->prev);
				deletion (temp->prev);
				temp->value=result;
			}
			else if (temp->data == '^')
			{
				//cout<<"power"<<endl;
				temp1=temp->prev->value;
				temp2=temp->prev->prev->value;
				result = power (temp1, temp2);
				//cout<<result<<endl;
				deletion (temp->prev->prev);
				deletion (temp->prev);
				temp->value=result;
			}
			else if (temp->data == '&')
			{
				//cout<<"and"<<endl;
				temp1=temp->prev->value;
				temp2=temp->prev->prev->value;
				result = andd (temp1, temp2);
				//cout<<result<<endl;
				deletion (temp->prev->prev);
				deletion (temp->prev);
				temp->value=result;
			}
			else if (temp->data == '|')
			{
				//cout<<"or"<<endl;
				temp1=temp->prev->value;
				temp2=temp->prev->prev->value;
				result = orr (temp1, temp2);
				//cout<<result<<endl;
				deletion (temp->prev->prev);
				deletion (temp->prev);
				temp->value=result;
			}
			else if (temp->data == '!')
			{
				//cout<<"not"<<endl;
				temp1=temp->prev->value;
				result = nott (temp1);
				//cout<<result<<endl;
				deletion (temp->prev);
				temp->value=result;
			}
		}
		
		cout<<result<<endl;
		return result;
	}
	
	void deletion (node *tem)
	{
		//cout<<"hello"<<endl;
		if (tem == head)
		{
			head=head->next;
			head->prev=NULL;
			//delete tem;
		}
		else
		{
			tem->prev->next=tem->next;
			tem->next->prev=tem->prev;
		}
		delete tem;
		tem=NULL;
	}
	
	long long int add (long long int val2, long long int val1)
	{
		return (val1 + val2);
	}
	
	long long int sub (long long int val2, long long int val1)
	{
		return (val1 - val2);
	}
	
	long long int mul (long long int val2, long long int val1)
	{
		return (val1 * val2);
	}
	
	long long int div (long long int val2, long long int val1)
	{
		return (val1 / val2);
	}
	
	long long int mod (long long int val2, long long int val1)
	{
		return (val1 % val2);
	}
	
	long long int power (long long int val2, long long int val1)
	{
		return (pow(val1, val2));
	}
	
	long long int andd (long long int val2, long long int val1)
	{
		return ( val1 & val2 );
	}
	
	long long int orr (long long int val2, long long int val1)
	{
		return ( val1 | val2);
	}
	
	long long int nott ( long long int val1)
	{ 
	    long long int binaryNum[32]; 
	 
	    int i = 0; 
	    while (val1 > 0)
		{
	        binaryNum[i] = val1 % 2; 
	        val1 = val1 / 2; 
	        i++; 
	    }
	    
	    for (int j=0; j<=i ; j++)
	    {
	    	if (binaryNum[j] == 0)
	    	{
	    		binaryNum[j] = 1;
			}
			else
			{
				binaryNum[j] = 0;
			}
		}
		
//		for (int j = i - 1; j >= 0; j--) 
//	    	cout << binaryNum[j];
//	    	
//	    	cout<<endl;
	    	
		long long int decimalNumber = 0, l = 0, remainder;
		for (int k=i-1 ; k>=0 ; k--)
		{
		    remainder = binaryNum[k];
		    decimalNumber += remainder*pow(2,l);
		    ++l;
		}
		
		return (decimalNumber);
	}
};


class stack1
{
	private:
	string s;
	char *arr;
	signed int top1=-1;
	public:
	void getdata (string input)
	{
		arr=new char[input.length()];
		s=input;
	}
	
	int checksym ()
	{
		for(int i=0; i<s.length(); i++)
		{
			if((s[i] == '{') || (s[i] == '(') || (s[i] == '['))
			{
				if(s[i] == '{')
				{
					pushc ( '}');
				}
				else if (s[i] == '(')
				{
					pushc ( ')');
				}
				else if (s[i] == '[')
				{
					pushc ( ']');
				}
			}
		}
			
		for(int i=0; i<s.length(); i++)
		{
			if((s[i] == '}') || (s[i] == ')') || (s[i] == ']'))
			{
				char temp;
				temp = popc ();
				
				if(temp != s[i])
				{
					
					cout<<"EXPRESSION IS NOT SYMBOLICALLY CORRECTENTER AGAIN\n"<<endl;
					return 0;
				}
			}
			if( i==s.length()-1 && top1!=-1 )
			{
				cout<<"EXPRESSION IS NOT SYMBOLICALLY CORRECT ENTER AGAIN\n"<<endl;
				return 0;
			}
		}
		
		//cout<<"EXPRESSION IS SYMBOLICALLY CORRECT\n"<<endl;
		return 1;
	}
	
	char popc ()
	{
		char t;
		
		t=arr[top1];
		top1--;
		return t;
	}
	
	void pushc (char p)
	{
		
		top1++;
		arr[top1]=p;
	}
	

};

int prec(char c) 
{ 	
	
	if(c == '!' || c=='^') 
	return 3; 
	else if(c == '*' || c == '/' || c=='%' ) 
	return 2; 
	else if(c == '+' || c == '-' || c=='&' || c=='|') 
	return 1; 
	else
	return -1; 
} 

// The  function to convert infix expression to postfix expression 
string infixToPostfix(string s) 
{ 
	std::stack<char> st; 
	st.push('N'); 
	int l = s.length(); 
	string ns; 
	for(int i = 0; i < l; i++) 
	{ 
		// If the scanned character is an operand, add it to output string. 
		if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z') || (s[i]>='0' && s[i]<='9' )) 
		ns+=s[i]; 

		// If the scanned character is an ‘(‘, push it to the stack. 
		else if(s[i] == '(') 
		
		st.push('('); 
		
		// If the scanned character is an ‘)’, pop and to output string from the stack 
		// until an ‘(‘ is encountered. 
		else if(s[i] == ')') 
		{ 
			while(st.top() != 'N' && st.top() != '(') 
			{ 
				char c = st.top(); 
				st.pop(); 
			ns += c; 
			} 
			if(st.top() == '(') 
			{ 
				char c = st.top(); 
				st.pop(); 
			} 
		} 
	//same as () bracket
		else if(s[i] == '{') 
		
		st.push('{'); 
		
		// If the scanned character is an ‘{’, pop and to output string from the stack 
		// until an ‘}‘ is encountered. 
		else if(s[i] == '}') 
		{ 
			while(st.top() != 'N' && st.top() != '{') 
			{ 
				char c = st.top(); 
				st.pop(); 
			ns += c; 
			} 
			if(st.top() == '{') 
			{ 
				char c = st.top(); 
				st.pop(); 
			}
			
			 
		} 
	
		
		else if(s[i] == '[') 
		
		st.push('['); 
		
		// If the scanned character is an ‘[’, pop and to output string from the stack 
		// until an ‘]‘ is encountered. 
		else if(s[i] == ']') 
		{ 
			while(st.top() != 'N' && st.top() != '[') 
			{ 
				char c = st.top(); 
				st.pop(); 
			ns += c; 
			} 
			if(st.top() == '[') 
			{ 
				char c = st.top(); 
				st.pop(); 
			}
			
			 
		} 
		
			
	
		//If an operator is scanned 
		else{ 
			while(st.top() != 'N' && prec(s[i]) <= prec(st.top())) 
			{ 
				char c = st.top(); 
				st.pop(); 
				ns += c; 
			} 
			st.push(s[i]); 
		} 

	} 
	//Pop all the remaining elements from the stack 
	while(st.top() != 'N') 
	{ 
		char c = st.top();
		st.pop(); 
		ns += c; 
	} 
	
	return ns; 

}

class converter
{
	public:
		
	long long int *val;
	char *var;
	int num;
	void getdata ()
	{
		int format;
		
		cout<<"Enter your number of literals:"<<endl;
		cin>>num;
		//cout<<num<<endl;
		val=new long long int [num];
		var=new char [num];
		
		for(int i=0; i<num; i++)
		{
			exp:
			cout<<"You Will Enter your entry in:"<<endl;
			cout<<"1)Binary."<<endl;
			cout<<"2)Octal."<<endl;
			cout<<"3)Decimal."<<endl;
			cout<<"4)Hexadecimal."<<endl;
			cin>> format;
			
			if (format==1)
			{
				cout<<"Variable:";
				cin>>var[i];
				cout<<"Entry:";
				cin>>val[i];
				bintodec ( val, i);
			}
			else if (format==2)
			{
				cout<<"Variable:";
				cin>>var[i];
				cout<<"Entry:";
				cin>>val[i];
				octtodec ( val, i);
			}
			else if (format==3)
			{
				cout<<"Variable:";
				cin>>var[i];
				cout<<"Entry:";
				cin>>val[i];
				continue;
			}
			else if (format==4)
			{
				string temp;
				cout<<"Variable:";
				cin>>var[i];
				cout<<"Entry:";
				cin>>temp;
				hextodec (temp, val, i);
			}
			else
			{
				cout<<"Invlaid Input"<<endl;
				goto exp;
			}
		}
	}
		void bintodec (long long int *a , int x)
		{
			long long int decimalNumber = 0,  remainder;
			long long int n;
			int i=0;
			
			n=a[x];
		    while (n!=0)
		    {
		        remainder = n%10;
		        //cout<<remainder<<endl;
		        getch();
		        n /= 10;
		        decimalNumber += remainder*pow(2,i);
		        ++i;
		    }
		    
		    a[x]=decimalNumber;
		}
		
		void octtodec (long long int *a , int x)
		{
		    long long int octal= 0, i = 0;
		    long long int decimal=0;
		    octal=a[x];
		    
		    while (octal != 0)
    		{
		        decimal =  decimal +(octal % 10)* pow(8, i++);
		        octal = octal / 10;
		    }
		    
		    a[x]=decimal;
		}
		
		void hextodec (string temp, long long int *a , int x)
		{
		    int len = temp.length(); 
		    
		    int base = 1; 
		      
		    long long int dec_val = 0; 
		      
		    for (int i=len-1; i>=0; i--) 
		    {    
			 
		        if (temp[i]>='0' && temp[i]<='9') 
		        { 
		            dec_val += (temp[i] - 48)*base; 
		            base = base * 16; 
		        } 
		   
		        else if (temp[i]>='A' && temp[i]<='F') 
		        { 
		            dec_val += (temp[i] - 55)*base;
		            base = base*16; 
		        } 
		    } 
		      
		    //cout<<dec_val<<endl;
		    //getch ();
		    a[x]=dec_val;
		    
		}
		
		void dectobin (long long int x )
		{
			
		}
		
		void show ()
		{
			for (int i=0; i<num; i++)
			{
				cout<<var[i]<<"  "<<val[i]<<endl;
			}
		}
		
		void assignvalues (dlist &l1)
		{
			l1.assignval1 (var, val, num);
		}
};

class boolean_calculator 
{
	public:
		void heading(){
	cout<<"\t\t\t  ____   ___   ___        _____    _____              ____  _____         ____               _____  _________  ___   ___ \n";
	cout<<"\t\t\t |    | |   | |   | |     |       |     | |\\   |     |     |     | |     |     |    | |     |     |     |     |   | |   |\n";
	cout<<"\t\t\t |____| |   | |   | |     |____   |     | | \\  |     |     |     | |     |     |    | |     |     |     |     |   | |___|\n";
	cout<<"\t\t\t |    | |   | |   | |     |       |_____| |  \\ |     |     |_____| |     |     |    | |     |_____|     |     |   | |\\    \n";
	cout<<"\t\t\t |____| |___| |___| |____ |_____  |     | |   \\|     |____ |     | |____ |____ |____| |____ |     |     |     |___| | \\   \n";
	cout<<"\t\t\t=========================================================================================================================\n";
}
void expsol(){
	cout<<"\t\t\t\t        ___        ___   __   ___  ___  ___  _____   ___           ___   ___             ___  __ \n";		
	cout<<"\t\t\t\t    |  |___   \\/  |___| |__| |___ |___ |___    |    |   | |\\ |    |___  |   | |    \\  / |___ |__|\n";
	cout<<"\t\t\t\t    |. |___   /\\  |     |\\   |___  ___| ___| __|__  |___| | \\|     ___| |___| |___  \\/  |___ |\\ \n";
}
void expcomp(){
	cout<<"\t\t\t\t __     ___        ___   __   ___  ___  ___  _____   ___          __  __        ___   __   __   ___   __\n";		
	cout<<"\t\t\t\t __|   |___   \\/  |___| |__| |___ |___ |___    |    |   | |\\ |   |   |  | |\\/| |___| |__| |__| |___  |__|\n";
	cout<<"\t\t\t\t|__  . |___   /\\  |     |\\   |___  ___| ___| __|__  |___| | \\|   |__ |__| |  | |     |  | |\\   |___  |\\ \n";
	
}
int chooseoption1(){
    system("cls");
	heading();
	cout<<"\n\n";	
	expsol();
	cout<<"\n\n";
	expcomp();
	
	cout<<"choose the option\n";
	int op;
	cin>>op;
	if(op!=1 && op!=2){
		system("cls");
		chooseoption1();
	}
	return op;
}
void equality(){
	cout<<"\t\t\t\t\t       ___  ___          ___        ___       _____ _____     \n";
	cout<<"\t\t\t\t\t    | |___ |   |  |   | |___| \\  / |___| |      |     |   |__| \n";
	cout<<"\t\t\t\t\t    |.|___ |___|  |___| |   |  \\/  |   | |___ __|__   |    __| \n";
	cout<<"\t\t\t\t\t                      \\ \n";
}
void notequality(){
	cout<<"\t\t\t\t\t ___        ___ _____    ___  ___          ___        ___       _____ _____     \n";
	cout<<"\t\t\t\t\t ___| |\\ | |   |  |     |___ |   |  |   | |___| \\  / |___| |      |     |   |__| \n";
	cout<<"\t\t\t\t\t|___ .| \\| |___|  |     |___ |___|  |___| |   |  \\/  |   | |___ __|__   |    __| \n";
	cout<<"\t\t\t\t\t                                 \\ \n";
}

int chooseoption2(){
    system("cls");
	heading();
	cout<<"\n\n";	
	equality();
	cout<<"\n\n";
	notequality();
	
	cout<<"choose the option\n";
	int op;
	cin>>op;
	if(op!=1 && op!=2){
		system("cls");
		chooseoption2();
	}
	return op;
}
void interface(){
	int op=chooseoption1();
	if(op==1){
		expression_solver();
	}
	if(op==2){
		chooseoption2();
	}
}
		
		long long int expression_solver ()
		{
			
			long long int x;
			system("cls");
			expsol();
			string input;
			string exp;
			stack1 s1;
			
			l:
			cout<<"enter the expression \n";
			cin>>input;
			s1.getdata(input);
			int ans=s1.checksym();
			if(ans==0){
				goto l;
			}
			exp=infixToPostfix(input);
			cout<<exp<<"\n";
			
			converter c1;
			c1.getdata ();
			c1.show();
			
			dlist l1;
			l1.buildlist(exp);
			c1.assignvalues(l1);
			l1.displayval();
			x=l1.solve();
			return x;
		}
		void expression_comparer()
		{
			long long int l, m;
			l = expression_solver();
			m = expression_solver();
			
			cout<<"1-GREATER THAN."<<endl;
			cout<<"2-LESSER THAN."<<endl;
			cout<<"3-LESSER THAN AND EQUAL TO."<<endl;
			cout<<"4-GREATER THAN AND EQUAL TO."<<endl;
			cout<<"enter the comparison.\n";
			int op;
			cin>>op;
			if(op==1){
				if(l>m){
					cout<<"true\n".
				}
				else{
					cout<<"false\n"
				}
			}
			else if(op==2){
				if(l<m){
					cout<<"true\n".
				}
				else{
					cout<<"false\n"
				}
			}
			else if(op==3){
				if(l<=m){
					cout<<"true\n".
				}
				else{
					cout<<"false\n"
				}
			}
			else if(op==4){
				if(l>=m){
					cout<<"true\n".
				}
				else{
					cout<<"false\n"
				}
			}
		}
};


int main()
{
	boolean_calculator b1;
	//b1.expression_solver();
	b1.interface();
}
