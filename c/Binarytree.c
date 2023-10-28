//binary tree
#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype
{
	struct nodetype *left;
	int info;
	struct nodetype *right;
}node;
// get node
node *getnode()

	node *p;
	p=(node*)malloc(sizeof(node));
	return p;
}
//insert a node
void insertnode(node **bt,int x)
{
	node *p, *q, *nnode;
	nnode=getnode();
	nnode->left=nnode->right=NULL;
	nnode->info=x;
	if(*bt==NULL)*bt=nnode;
	else
	{
		q=*bt;
		while(q!=NULL)
		{
			p=q;
		  if(x<q->info)
			  q=q->left;
		  else
			   q=q->right;  
		}
		if(x<p->info) 
		   p->left=nnode;
		else p->right=nnode;
	}
}
//create node
node *create(node*bt, int n)
{
	int i,x;
	printf(" \n enter % d elements to create binarytree\n",n);
	for(i=0;i<n;i++)
	{  
	  scanf("%d",&x);
	  insertnode(&bt,x);
	}
	return(bt);
}
//preorder
void preorder(node*bt)
{
	if(bt!=NULL)
	{
		printf("%d\t",bt->info);
		preorder(bt->left);
		preorder(bt->right);
	}
}
//inorder
void inorder(node*bt)
{
	if(bt!=NULL)
	{
		inorder(bt->left);
		printf("%d\t",bt->info);
		inorder(bt->right);
	}
}
//postorder
void postorder(node*bt)
{
	if(bt!=NULL)
	{
	    postorder(bt->left);
		postorder(bt->right);
		printf("%d\t",bt->info);
	}
}
//search
void search(node* bt ,int x)
{
	node *q;
	q=bt;
	
	while(q!=NULL&&q->info!=x)
	{
		if(x<q->info)
		 	q=q->left;
	    else
		  	q=q->right;	 
	}
	if(q==NULL)
	   printf("node is not present");
	else 
	   printf(" node is present");
}
// count leaf
int countleafnodes(node*tree)
{
	if(tree==NULL) return 0;
	else if(tree->left==NULL&&tree->right==NULL)
	     return 1;
	else return (countleafnodes(tree->left) + countleafnodes(tree->right));     
}
//non leaf internal count
int internal(node*tree)
{
		if((tree==NULL)||(tree->left==NULL&&tree->right==NULL))
		  return 0;
		else
		      return (internal(tree->left) + internal(tree->right)+1);  
}
//total node
int totalnode(node*tree)
{
	if(tree==NULL)
	    return 0;
	else
	    return(totalnode(tree->left) + totalnode(tree->right)+1); 
		 
}
//maximum
int max(node* tree)
{
	if(tree==NULL)
	   return 0;
	else if(tree->right==NULL)
	     return (tree->info);
    else
	     max(tree->right);		    
}
//minimum tree
int min(node* tree)
{
	if(tree==NULL)
	   return 0;
	else if(tree->left==NULL)
	     return (tree->info);
    else
	     min(tree->right);		    
}


void main()
{
	node*bt ;
	bt=NULL; 
	int ch ,x,n;
	printf(" binary tree :");
    do
    {
      printf("\n 1.insert node 2.create 3.preorder 4. inorder 5.postorder 6.countleaf 7.internal 8.totalnode9.max 10.min 11.search");
      printf(" \n enter your choice \n:");
	  scanf("%d",&ch);	
	  switch(ch)
	  {
	  	  case 1: printf(" enter the element to be inserted");
	  	          scanf("%d",&x);
	  	          insertnode(&bt,x);
	  	          printf(" \n inorder \n");
		          inorder(bt);
		          printf(" \n inorder \n");
		          postorder(bt);
		          printf(" \n preorder \n");
		          preorder(bt);
	  	          break;
	  	          
	  	 case 2 : printf(" enter the size of tree");
	  	          scanf("%d",&n);
		          bt=create(bt,n);
		          printf(" \n inorder \n");
		          inorder(bt);
		          printf(" \n inorder \n");
		          postorder(bt);
		          printf(" \n preorder \n");
		          preorder(bt);
		          break;
		 case 3 : printf(" preorder nodes are ");
		          preorder(bt);
		          break;
		 case 4 : printf(" inorder nodes are ");
		          inorder(bt);
		          break;
		 case 5 : printf("postorder nodes are ");
		          postorder(bt);
		          break;
		 case 6 : x=countleafnodes(bt);
		          printf(" leaf nodes are %d",x);
		          break;
		 case 7 : x=internal(bt);
		          printf(" non leaf nodes are %d",x);
		          break;
		 case 8:  x=totalnode(bt); 
		          printf(" total nodes are %d",x);
		          break;  
		 case 9 : x=max(bt);
		          printf(" max node is %d",x);
				  break;  
	     case 10 : x=min(bt);
		          printf(" min tree is %d",x);
				  break;  
		 case 11 :printf(" enter the element to be searched ");
		          scanf("%d",&x);
		          search(bt,x);
		          printf(" \n inorder \n");
		          inorder(bt);
		          printf(" \n inorder \n");
		          postorder(bt);
		          printf(" \n preorder \n");
		          preorder(bt);
		          break;  		         
		 case 12 : printf(" thank you");break;
		 default : printf("invalid choice"); break;
	  	          
	   }
	}
	while(ch>=1&&ch<=11);

}
