#include<iostream>
#include<queue>
#include<stack>
using namespace std;



class Node{
	public:
		int data;
		Node*left;
		Node*right;
		
		Node(int d){
			data = d;
			left = NULL;
			right = NULL;
		}
};
		Node*buildTree(Node*root){
			cout<<"Enter the data for root:";
			int data;
			cin>>data;
			root = new Node(data);
		
		
		if(data ==-1){
			return NULL;
		}
		
		
		cout<<"Enter the value for left of:"<<data<<endl;
		root->left = buildTree(root->left);
		cout<<"Enter the value for right of"<<data<<endl;
		root->right = buildTree(root->right);
		
}
		

void levelOrder_traversal(Node*root){
	
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		
	
	Node*temp = q.front();
	q.pop();
	
	if(temp==NULL){
		cout<<endl;
		if(!q.empty()){
			q.push(NULL);
		}
	}
	else{
		cout<<temp->data<<" ";
		if(temp->left){
		q.push(temp->left);
	}
	if(temp->right){
		q.push(temp->right);
	}
		
	}
	
	
	
}
}

//void reverseLevelOrderTraversal(Node* root) {
//    if (root == NULL) return;
//
//    queue<Node*> q;
//    stack<Node*> s;
//    q.push(root);
//
//    while (!q.empty()) {
//        Node* temp = q.front();
//        q.pop();
//        s.push(temp);
//
//        // Push right before left to ensure left comes before right in stack
//        if (temp->right) {
//            q.push(temp->right);
//        }
//        if (temp->left) {
//            q.push(temp->left);
//        }
//    }
//
//    // Print nodes in reverse level order
//    while (!s.empty()) {
//        Node* temp = s.top();
//        cout << temp->data << " ";
//        s.pop();
//    }
//    cout << endl;
//}



void inorder(Node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}


int main()

{
	
	Node*root = NULL;
//	 Node*buildTree(root);
	root  = buildTree(root);
//	cout<<root->data;
levelOrder_traversal(root);
inorder(root);


return 0;

}
