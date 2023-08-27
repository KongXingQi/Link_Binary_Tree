#pragma once


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef char LBTElemType;

#define NIL 0 // ��Ч������Ϊ 0 


static flag = 0;//

// ��̬���� ��������

typedef struct BiTNode
{
	LBTElemType data;
	struct BiTNode* parent, *lchild, *rchild; //˫�� ���� �Һ���
}BiTNode;

//��ʼ��һ�������ڵ㣩
void LBiTreeInit(BiTNode* LBT);

//��ӡ��ǰλ�õ�����
void LBiTreePrint(BiTNode* LBT);

//������ڵ��������
void LBiTreeLeftInsert(BiTNode* LBT, LBTElemType e);

//������ڵ��������
void LBiTreeRightInsert(BiTNode* LBT, LBTElemType e);

//����e ���Ԫ�صĵ�ַ
BiTNode* LBiTreeFind(BiTNode* LBT, LBTElemType e);

//������Ƿ�Ϊ��
bool LBiTreeEmpty(BiTNode* LBT);

//�����������
int LBiTreeDepth(BiTNode* LBT);

//�������ĸ�
LBTElemType LBiTreeRoot(BiTNode* LBT);

//���ص�ǰ�ڵ��ֵ
LBTElemType LBiTreeValue(BiTNode* LBT);

// ����ǰ�ڵ㸳ֵ
void LBiTreeCurAssign(BiTNode* LBT, LBTElemType e);


// ����ô�о���Щ�е� ���� hello world �ĸо� ����������
//���ص�ǰ�ڵ��˫��
LBTElemType LBiTreeParent(BiTNode* LBT);

//���ص�ǰ�ڵ������
LBTElemType LBiTreeLeftChild(BiTNode* LBT);

//���ص�ǰ�ڵ���Һ���
LBTElemType LBiTreeRightChild(BiTNode* LBT);

//���ص�ǰ�ڵ�����ֵ�
LBTElemType LBiTreeLeftSibling(BiTNode* LBT);

//���ص�ǰ�ڵ�����ֵ�
LBTElemType LBiTreeRightSibling(BiTNode* LBT);



//ǰ�����
void LBiTreePreOrderTraverse(BiTNode* LBT);

//�������
void LBiTreeInOrderTraverse(BiTNode* LBT);

//�������
void LBiTreePostOrderTraverse(BiTNode* LBT);


//������
void LBiTreeDestroy(BiTNode* LBT);