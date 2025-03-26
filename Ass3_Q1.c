#include <stdio.h>
#include <conio.h>
#include <string.h>
struct treenode
{
char info;
struct treenode *left;
struct treenode *right;
}*temp,*a,*b,*c,*d,*temp1,*root;
typedef struct treenode node;
node * proc_e(char input[]);
node * proc_t(char input[]);
node * proc_v(char input[]);
void traversal(node *temp);
int ssm=0;
void main()
{
char input[20];
//ssm=0;
clrscr();
printf("Enter String:");
gets(input);
root=proc_e(input);
printf("Parser Tree: ");
traversal(root);
getch();
}
node * proc_e(char input[])
{
char ch;
a=proc_t(input);
while(input[ssm]=='+' || input[ssm]=='-')
{
ch=input[ssm];
ssm++;
b=proc_t(input);
temp=(node *)malloc(sizeof(node));
temp->info=ch;
temp->left=a;
temp->right=b;
a=temp;
}
return a;
}
node * proc_t(char input[])
{
char ch;
c=proc_v(input);
ssm+=1;
while(input[ssm]=='*' || input[ssm]=='/')
{
ch=input[ssm];
ssm++;
d=proc_v(input);
temp=(node *)malloc(sizeof(node));
temp->info=ch;
temp->left=c;
temp->right=d;
c=temp;
ssm+=1;
}
return c;
}
node * proc_v(char input[])
{
if(isalpha(input[ssm]))
{
temp=(node *)malloc(sizeof(node));
temp->info=input[ssm];
temp->left=NULL;
temp->right=NULL;
return temp;
}
else
{
printf("Error %c",input[ssm]);
exit(0);
}
}
void traversal(node *temp1)
{
if(temp1!=NULL)
{
traversal(temp1->left);
printf("%c",temp1->info);
traversal(temp1->right);
}
}