#include<iostream>
#include<stack>
using namespace std;

class Node{
	public:
		char data;
		Node *right;
		Node *left;
		Node(char st)
		{
			data=st;
			right=left=NULL;
		}
};
bool isOperator(char c){
	return(c=='+'||c=='-'||c=='*'||c=='/');
}

void postor(Node *root)
{
	if (root==NULL)
	{
		return;
	}
	
	stack<Node*>s;
	stack<char>result;
	s.push(root);
	while(!s.empty())
	{
		Node *current=s.top();
		s.pop();
		result.push(current->data);
		if(current->left)
		{
			s.push(current->left);
		}
		if(current->right)
		{
			s.push(current->right);
		}
	}
	while(!result.empty())
	{
		cout<<result.top()<<" ";
		result.pop();
	}
}

Node *constexp(string exp)
{
 	stack<Node*>s;
 	for (int i=exp.size();i>=0;i--)
 	{
 		char c=exp[i];
 		if(isOperator(c))
 		{
 			Node *newNode= new Node(c);
 			newNode->left=s.top();
 			s.pop();
 			newNode->right=s.top();
 			s.pop();
 			s.push(newNode);
		}
		else
		{
		 	Node *newNode=new Node(c);
		 	s.push(newNode);
		}
	
    }
    return s.top();
	 
}

void del(Node* root)
{
 	if(root==NULL)
 	{
 		return ;
	 }
	 del(root->left);
	 del(root->right);
	 delete root;
	 
}

int main()
{
    string str;

    cout<<"enter the string";
    cin>>str;

    Node *root=constexp(str);
    cout<<"order\n";
    postor(root);
}