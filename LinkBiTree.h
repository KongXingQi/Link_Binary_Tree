#pragma once


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef char LBTElemType;

#define NIL 0 // 无效的数据为 0 


static flag = 0;//

// 动态的树 三叉链表

typedef struct BiTNode
{
	LBTElemType data;
	struct BiTNode* parent, *lchild, *rchild; //双亲 左孩子 右孩子
}BiTNode;

//初始化一个树（节点）
void LBiTreeInit(BiTNode* LBT);

//打印当前位置的数据
void LBiTreePrint(BiTNode* LBT);

//给这个节点插入左孩子
void LBiTreeLeftInsert(BiTNode* LBT, LBTElemType e);

//给这个节点插入左孩子
void LBiTreeRightInsert(BiTNode* LBT, LBTElemType e);

//返回e 这个元素的地址
BiTNode* LBiTreeFind(BiTNode* LBT, LBTElemType e);

//检测树是否为空
bool LBiTreeEmpty(BiTNode* LBT);

//返回树的深度
int LBiTreeDepth(BiTNode* LBT);

//返回树的根
LBTElemType LBiTreeRoot(BiTNode* LBT);

//返回当前节点的值
LBTElemType LBiTreeValue(BiTNode* LBT);

// 给当前节点赋值
void LBiTreeCurAssign(BiTNode* LBT, LBTElemType e);


// 我怎么感觉这些有点 额额额 hello world 的感觉 哈哈、。。
//返回当前节点的双亲
LBTElemType LBiTreeParent(BiTNode* LBT);

//返回当前节点的左孩子
LBTElemType LBiTreeLeftChild(BiTNode* LBT);

//返回当前节点的右孩子
LBTElemType LBiTreeRightChild(BiTNode* LBT);

//返回当前节点的左兄弟
LBTElemType LBiTreeLeftSibling(BiTNode* LBT);

//返回当前节点的右兄弟
LBTElemType LBiTreeRightSibling(BiTNode* LBT);



//前序遍历
void LBiTreePreOrderTraverse(BiTNode* LBT);

//中序遍历
void LBiTreeInOrderTraverse(BiTNode* LBT);

//后序遍历
void LBiTreePostOrderTraverse(BiTNode* LBT);


//销毁树
void LBiTreeDestroy(BiTNode* LBT);