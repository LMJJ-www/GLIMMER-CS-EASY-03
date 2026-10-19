#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//#include<math.h>

#define MAX_TREE_SIZE 100
/*
 * 顺序存储二叉树结点
 * - data：结点数据
 * - used：当前位置是否有结点
 */
typedef struct {
    int data;
    bool used;
} SeqTreeNode;

/*
 * 顺序存储二叉树
 * - nodes：结点数组
 * - size：数组最大容量
 */
typedef struct {
    SeqTreeNode nodes[MAX_TREE_SIZE];
    int size;
} SeqBiTree;

void init_tree(SeqBiTree *tree)
{
    tree->size = MAX_TREE_SIZE;
    for(int i = 1; i < MAX_TREE_SIZE;i++ )
    {
       tree->nodes[i].data = 0;
        tree->nodes[i].used = false;
    }
}

bool set_root(SeqBiTree *tree, int value)
{
    tree->nodes[1].data = value;
    tree->nodes[1].used = true;
    return true;
}

bool set_left_child(SeqBiTree *tree, int parent_node, int value)
{
    int j;
    j = parent_node * 2;
    if(j <= MAX_TREE_SIZE - 1)
    {
        tree->nodes[j].data = value;
        tree->nodes[j].used = true;
        return true;
    }else{
        printf("failure");
        return false;
    }
}

bool set_right_child(SeqBiTree *tree, int parent_node, int value)
{
    int j;
    j = parent_node * 2 + 1;
    if(j < MAX_TREE_SIZE)
    {
        tree->nodes[j].data = value;
        tree->nodes[j].used = true;
        return true;

    }else{
        printf("failure");
        return false;
       }
}

/*
void level_order(SeqBiTree *tree)
{
   for(int n = 1;n <= ceil(log(MAX_TREE_SIZE)/log(2));n++)
   {
     for(int i = pow(2,n - 1); i <= pow(2, n) - 1; i++)
    {
        int j = -1;
        if(tree->nodes[i].used == false)
        {
            printf("%d",j);
        }
        else if(tree->nodes[i].used == true)
        {
            printf("%d",tree->nodes[i].data);
        }
    }
   }    
}
*/
void level_order(SeqBiTree *tree)
{for(int i = 1;i < MAX_TREE_SIZE ; i = 2 * i)
    {
        for(int j = i; j < 2 * i && j < MAX_TREE_SIZE;j++)
        {
            if(tree->nodes[j].used == false)
            {
                printf("-1 ");
            }else if(tree->nodes[j].used == true)
            {
                printf("%d ",tree->nodes[j].data);
            }
        }
        printf("\n");
    }

  
}


int main()
{
    SeqBiTree *tree1 = (SeqBiTree *)malloc(sizeof(SeqBiTree));  
    init_tree(tree1);
    set_root(tree1,1);
    set_left_child(tree1,1,2);
    set_right_child(tree1,1,3);
    set_left_child(tree1,2,4);
    set_right_child(tree1,2,5);
    set_left_child(tree1,3,6);
    level_order(tree1);
    free(tree1);
    tree1 = NULL;
    return 0;
}