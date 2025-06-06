#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int data;
    int height;
    struct node *rchild;
};

struct node *root = NULL;

int nheight(struct node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int l = p->lchild ? p->lchild->height : 0;
    int r = p->rchild ? p->rchild->height : 0;
    return (l > r ? l : r) + 1;
}

int balfac(struct node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int l = p->lchild ? p->lchild->height : 0;
    int r = p->rchild ? p->rchild->height : 0;
    return l - r;
}

struct node *ll(struct node *p)
{
    struct node *pl = p->lchild;
    p->lchild = pl->rchild;
    pl->rchild = p;
    p->height = nheight(p);
    pl->height = nheight(pl);

    if (p == root)
    {
        root = pl;
    }
    return pl;
}

struct node *rr(struct node *p)
{
   return NULL;
}


struct node *lr(struct node *p)
{
	return NULL;
}


struct node *rl(struct node *p)
{
	return NULL;
}

struct node *insert(struct node *p, int key)
{
    struct node *t = NULL;

    
    if (p == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
    {
        p->lchild = insert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = insert(p->rchild, key);
    }
    else
    {
        return p; 
    }

   
    p->height = nheight(p);

   
    int balance = balfac(p);


  
    if (balance > 1 && key < p->lchild->data)
    {
        return ll(p);
    }

    
    if (balance < -1 && key > p->rchild->data)
    {
        return rr(p);
    }

    
    if (balance > 1 && key > p->lchild->data)
    {
        return lr(p);
    }

   
    if (balance < -1 && key < p->rchild->data)
    {
        return rl(p);
    }

    return p; 
}

void inorder(struct node *p)
{
    if (p != NULL)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

int main()
{
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 2);
    
    printf("Display: ");
    inorder(root);
    printf("\n");
    
    return 0;
}
