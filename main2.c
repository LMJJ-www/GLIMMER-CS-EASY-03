#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;

TreeNode* create_node(int value)
{
    TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

//前序遍历
void Pre_order(TreeNode *tree)
{
    if(tree == NULL)
    {
        return;
    }
    printf("%d ",tree->data); 
    Pre_order(tree->left);
    Pre_order(tree->right);
}

//中序遍历
void In_order(TreeNode *tree)
{
    if(tree == NULL)
    {
        return;
    }
    In_order(tree->left);
    printf("%d ",tree->data);
    In_order(tree->right);

}

//后序遍历
void Post_order(TreeNode *tree)
{
    if(tree == NULL)
    {
        return;
    } 
    Post_order(tree->left);
    Post_order(tree->right);
    printf("%d ",tree->data);
}

//统计深度
int depth(TreeNode *root, int current_depth, int max_depth)
{
    if(root == NULL)
    {
        return max_depth;
    }

    if(current_depth > max_depth)
    {
        max_depth = current_depth;
    }

    int leftmax = depth(root->left,current_depth + 1,max_depth);
    int rightmax = depth(root->right,current_depth + 1,max_depth);
    
    if(leftmax >= rightmax)
    {
        max_depth = leftmax;
    }
    else{
        max_depth = rightmax;
    }
    return max_depth;
}

//
typedef struct Stack {
    TreeNode **arr;
    int top;                                               //记录栈顶位置
    int capacity;
} Stack;
//创建栈并初始化
Stack *createStack(int capacity) {
    Stack *stack = malloc(sizeof(Stack));
    stack->arr = malloc(sizeof(TreeNode *) * capacity);
    stack->top = -1;                                       //栈为空
    stack->capacity = capacity;
    return stack;
}
//判断栈空
int isEmpty(Stack *stack) {
    return stack->top == -1;
}
//入栈
void push(Stack *stack, TreeNode *node) {
    if (stack->top == stack->capacity - 1) {
        return;
    }
    stack->arr[++stack->top] = node;
}
//出栈
TreeNode *pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->arr[stack->top--];
}

void preorderTraversal(TreeNode *root) // 补全这个函数
{
    if(root == NULL)
    {
        return;
    }
    Stack *st = createStack(100);
    TreeNode *p = root;

    while(p != NULL || !isEmpty(st))
    {
        while(p != NULL)
        {
            printf("%d ",p->data);
            push(st, p);
            p = p->left;
        }
        if(!isEmpty(st))
        {
            p = pop(st);
            p = p->right;
        }
    }
}



int main()
{
    TreeNode* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);

    TreeNode* leftchild = root->left;
    leftchild->left = create_node(4);
    leftchild->right = create_node(5);

    TreeNode* rightchild = root->right;
    rightchild->left = create_node(6);
    rightchild->right = create_node(7);

    Pre_order(root);
    printf("\n");
    In_order(root);
    printf("\n");
    Post_order(root);
    printf("\n");
    int tree_depth = depth(root,1,0);
    printf("最大深度=%d",tree_depth);
    printf("\n");
    preorderTraversal(root);

    return 0;
}