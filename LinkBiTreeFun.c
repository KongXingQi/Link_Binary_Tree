#include"LinkBiTree.h"

int nodenum = 1;

//��ʼ��һ�������ڵ㣩
void LBiTreeInit(BiTNode* LBT)
{
	assert(LBT);
	LBT->data = NIL;
	LBT->parent = NULL;
	LBT->lchild = NULL;
	LBT->rchild = NULL;

}

//��ӡ��ǰλ�õ�����
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


//����ǰ�ڵ㸳ֵ
void LBiTreeCurAssign(BiTNode* LBT, LBTElemType e)
{
	assert(LBT);

	LBT->data = e;
}



//������ڵ��������
void LBiTreeLeftInsert(BiTNode* LBT, LBTElemType e)
{
	assert(LBT);

	BiTNode* newnode = LBITreeBuyNode(e);
	newnode->parent = LBT;
	LBT->lchild = newnode;
	nodenum++;

}

//������ڵ�����Һ���
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




//����e ���Ԫ�صĵ�ַ
BiTNode* LBiTreeFind(BiTNode* LBT, LBTElemType e)
{
	assert(LBT);

	BiTNode* cur = LBT;
	BiTNode* p = NULL;
	PreOrderTraverse(cur, e, &p);
	flag = 0;
	return p;
}


//������Ƿ�Ϊ��
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

//�����������
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

//�������ĸ�
LBTElemType LBiTreeRoot(BiTNode* LBT)
{
	assert(LBT);

	return LBT->data;
}

//���ص�ǰ�ڵ��ֵ
LBTElemType LBiTreeValue(BiTNode* LBT)
{
	assert(LBT);

	return LBT->data;
}


//���ص�ǰ�ڵ��˫��
LBTElemType LBiTreeParent(BiTNode* LBT)
{
	assert(LBT);

	return LBT->parent->data;
}

//���ص�ǰ�ڵ������
LBTElemType LBiTreeLeftChild(BiTNode* LBT)
{
	assert(LBT);

	if (LBT->lchild->data != '#')
		return LBT->lchild->data;
	else
		return NIL;
}

//���ص�ǰ�ڵ���Һ���
LBTElemType LBiTreeRightChild(BiTNode* LBT)
{
	assert(LBT);

	if (LBT->rchild->data != '#')
		return LBT->rchild->data;
	else
		return NIL;
}

//���ص�ǰ�ڵ�����ֵ�
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

//���ص�ǰ�ڵ�����ֵ�
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



//ǰ�����
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

//�������
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

//�������
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



//������
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

	//��һ�������� malloc ������
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