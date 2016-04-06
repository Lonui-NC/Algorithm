#include <stdio.h>
//author:Nic github 
//求二叉树深度

typedef struct Node
{
    char data;
    struct Node *LChild;
    struct Node *RChild;
    struct Node *Parent;
}BNode,*BTree;

//后序遍历求二叉树深度算法
int PostTreeDepth(BTree root)
{
    int leftheight,rightheight,max;
    if(root!=NULL)
    {
        leftheight=PostTreeDepth(root->LChild);
        rightheight=PostTreeDepth(root->RChild);
        max=leftheight>rightheight?leftheight:rightheight;
        return(max+1);
    }
    else
        return 0;
}

int GetMax(int a,int b)
{
    return a>b?a:b;
}


//非递归形式求二叉树深度
int GetTreeHeightPreorder(const BTree root)
{
    struct Info
    {
        const BTree TreeNode;
        int level;
    };
    deque<Info> dq;
    //双端队列，两端弹出
    int level=-1;
    int TreeHeight=-1;
    while(1)
    {
        while(root)
        {
            ++level;
            if(root->RChild)
            {
                //调用结构体，实现push，有右子树，push进去先处理左子树
                Info info={root->RChild,level};
                dq.push_back(info);
            }
            root=root->LChild;
        }
        TreeHeight=GetMax(TreeHeight,level);
        //此时表示对应仅有左子树处理完，无右子树，并且前面的数据都已经弹出
        if(dq.empty())
            break;
        //info的地址是dq.back()，即info是最后一个元素
        const Info &info=dq.back();
        root=info.TreeNode;
        level=info.level;
        dq.pop_back();//将对应内容设置好后，再弹出数据，取右子树
        //每次保存两个数，当前最新与之前最新
    }
    return TreeHeight;
}

int GetTreeHeightPreorder2(const BTree root)
{
    deque<const BTree> dq;
    int TreeHeight=-1;
    while(-1)
    {
        for(;root!=NULL;root=root->LChild)
        {
            dq.push_back(root);
        }
        TreeHeight=GetMax(TreeHeight,(int)dq.size()-1);
        while(1)
        {
            //若该节点无新的子树，表示已经到头
            if(dq.empty()) return TreeHeight;
            //否则，调用实现，取其右子树
            const BTree parrent=dq.back();
            const BTree RChild=parrent->RChild;
            if(RChild && root !=RChild)
            {
                root=RChild;
                break;
            }
            //每次都要从左边起，都要判断
            root=parrent;
            dq.pop_back();
        }
    }
    return TreeHeight;
}