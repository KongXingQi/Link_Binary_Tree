#include"LinkBiTree.h"

int nodenum = 1;

//初始化一个树（节点）
void LBiTreeInit(BiTNode* LBT)
{
	assert(LBT);
	LBT->data = NIL;
	LBT->parent = NULL;
	LBT->lchild = NULL;
	LBT->rchild = NULL;

}

//打印当前位置的数据
void LBiTreePrint(BiTNode* LBT)
{
	if (LBT->data != '#')
	printf("%c ",LBT->data);

}

BiTNode* LBITreeBuyNode(LBTElemType e)
{

	BiTNode* newnode = (BiTNode*)malloc(sizeof(BiTNode));
	newnode->data = e;
	newnode->lchild = NULL;
	newnode->parent = NULL;
	newnode->rchild = NULL;
	return newnode;
}


//给当前节点赋值
void LBiTreeCurAssign(BiTNode* LBT, LBTElemType e)
{
	assert(LBT);

	LBT->data = e;
}



//给这个节点插入左孩子
void LBiTreeLeftInsert(BiTNode* LBT, LBTElemType e)
{
	assert(LBT);

	BiTNode* newnode = LBITreeBuyNode(e);
	newnode->parent = LBT;
	LBT->lchild = newnode;
	nodenum++;

}

//给这个节点插入右孩子
void LBiTreeRightInsert(BiTNode* LBT, LBTElemType e)
{
	assert(LBT);

	BiTNode* newnode = LBITreeBuyNode(e);
	newnode->parent = LBT;
	LBT->rchild = newnode;
	nodenum++;
}

void PreOrderTraverse(BiTNode* cur, LBTElemType e, BiTNode** p)
{
	if (cur->data == e)
	{
		flag = 1;
		*p = cur;
	}

	if (cur->lchild != NULL && flag == 0)
	{
		PreOrderTraverse(cur->lchild, e,p);
	}

	if (cur->rchild != NULL && flag == 0)
	{
		PreOrderTraverse(cur->rchild, e,p);
	}

}




//返回e 这个元素的地址
BiTNode* LBiTreeFind(BiTNode* LBT, LBTElemType e)
{
	assert(LBT);

	BiTNode* cur = LBT;
	BiTNode* p = NULL;
	PreOrderTraverse(cur, e, &p);
	flag = 0;
	return p;
}


//检测树是否为空
bool LBiTreeEmpty(BiTNode* LBT)
{
	assert(LBT);

	if (LBT->lchild == NULL && LBT->rchild == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//返回树的深度
int LBiTreeDepth(BiTNode* LBT)
{
	assert(LBT);

	int k = 1;
	while (pow(2, k) - 1 < nodenum)
	{
		k++;
	}

	return k;
}

//返回树的根
LBTElemType LBiTreeRoot(BiTNode* LBT)
{
	assert(LBT);

	return LBT->data;
}

//返回当前节点的值
LBTElemType LBiTreeValue(BiTNode* LBT)
{
	assert(LBT);

	return LBT->data;
}


//返回当前节点的双亲
LBTElemType LBiTreeParent(BiTNode* LBT)
{
	assert(LBT);

	return LBT->parent->data;
}

//返回当前节点的左孩子
LBTElemType LBiTreeLeftChild(BiTNode* LBT)
{
	assert(LBT);

	if (LBT->lchild->data != '#')
		return LBT->lchild->data;
	else
		return NIL;
}

//返回当前节点的右孩子
LBTElemType LBiTreeRightChild(BiTNode* LBT)
{
	assert(LBT);

	if (LBT->rchild->data != '#')
		return LBT->rchild->data;
	else
		return NIL;
}

//返回当前节点的左兄弟
LBTElemType LBiTreeLeftSibling(BiTNode* LBT)
{
	assert(LBT);

	if (LBT->parent->lchild != LBT && LBT->parent->rchild->data != '#')
	{
		return LBT->parent->lchild->data;
	}
	else
	{
		return NIL;
	}
}

//返回当前节点的右兄弟
LBTElemType LBiTreeRightSibling(BiTNode* LBT)
{
	assert(LBT);

	if (LBT->parent->rchild != LBT && LBT->parent->rchild->data != '#')
	{
		return LBT->parent->rchild->data;
	}
	else
	{
		return NIL;
	}

}



//前序遍历
void LBiTreePreOrderTraverse(BiTNode* LBT)
{
	LBiTreePrint(LBT);
	if (LBT->lchild != NULL)
	{
		LBiTreePreOrderTraverse(LBT->lchild);
	}
	if (LBT->rchild != NULL)
	{
		LBiTreePreOrderTraverse(LBT->rchild);
	}
}

//中序遍历
void LBiTreeInOrderTraverse(BiTNode* LBT)
{
	if (LBT->lchild != NULL)
	{
		LBiTreeInOrderTraverse(LBT->lchild);
	}

	LBiTreePrint(LBT);

	if (LBT->rchild != NULL)
	{
		LBiTreeInOrderTraverse(LBT->rchild);
	}
	
}

//后序遍历
void LBiTreePostOrderTraverse(BiTNode* LBT)
{

	if (LBT->lchild != NULL)
	{
		LBiTreePostOrderTraverse(LBT->lchild);
	}


	if (LBT->rchild != NULL)
	{
		LBiTreePostOrderTraverse(LBT->rchild);
	}

	LBiTreePrint(LBT);


}



//销毁树
void LBiTreeDestroy(BiTNode* LBT)
{
	if (LBT->lchild != NULL)
	{
		LBiTreeDestroy(LBT->lchild);
	}

	if (LBT->rchild != NULL)
	{
		LBiTreeDestroy(LBT->rchild);
	}

	//第一个根不是 malloc 出来的
	if (LBT->data == 'A')
	{
		LBT->data = NIL;
		LBT->lchild = LBT->rchild = LBT->parent = NULL;
		return;
	}
	LBT->data = NIL;
	LBT->lchild = LBT->rchild = LBT->parent = NULL;
	free(LBT);
}