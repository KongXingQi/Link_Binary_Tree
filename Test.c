#include"LinkBiTree.h"


extern nodenum;

void LBiTreeTest1()
{
	BiTNode T;
	LBiTreeInit(&T);
	
	LBiTreeCurAssign(&T, 'A');
	LBiTreeLeftInsert(&T, 'B');
	LBiTreeRightInsert(&T, 'C');

	
	BiTNode* cur = LBiTreeFind(&T,'B');
	LBiTreeLeftInsert(cur, 'D');
	LBiTreeRightInsert(cur, 'E');

	cur = LBiTreeFind(&T, 'C');
	LBiTreeLeftInsert(cur, 'F');
	LBiTreeRightInsert(cur, 'G');

	cur = LBiTreeFind(&T, 'D');
	LBiTreeLeftInsert(cur, 'H');
	LBiTreeRightInsert(cur, 'I');

	cur = LBiTreeFind(&T, 'E');
	LBiTreeLeftInsert(cur, 'J');


	if (!LBiTreeEmpty(&T))
	{
		printf("������Ϊ�� ��Ϊ: %c \n",LBiTreeRoot(&T));
		printf("���������Ϊ : %d \n",LBiTreeDepth(&T));
	}
	else
	{
		printf("����Ϊ�� �޸�\n");
	}

	cur = LBiTreeFind(&T, 'C');

	printf("�ýڵ���: %c \n",'C');
	printf("�ýڵ��˫����: %c \n",LBiTreeParent(cur));
	printf("�ýڵ��������: %c \n", LBiTreeLeftChild(cur));
	printf("�ýڵ���Һ�����: %c \n", LBiTreeRightChild(cur));
	printf("�ýڵ�����ֵ���: %c \n", LBiTreeLeftSibling(cur));
	printf("�ýڵ�����ֵ���: %c \n", LBiTreeRightSibling(cur));


	printf("ǰ�����: ");
	LBiTreePreOrderTraverse(&T);
	printf("\n");

	printf("�������: ");
	LBiTreeInOrderTraverse(&T);
	printf("\n");

	printf("�������: ");
	LBiTreePostOrderTraverse(&T);
	printf("\n");

	LBiTreeDestroy(&T);

	if (!LBiTreeEmpty(&T))
	{
		printf("������Ϊ�� ��Ϊ: %c \n", LBiTreeRoot(&T));
		printf("���������Ϊ : %d \n", LBiTreeDepth(&T));
	}
	else
	{
		printf("����Ϊ�� �޸�\n");
	}
	
}

void LBiTreeTest2()
{

	BiTNode T;
	LBiTreeInit(&T);

	LBiTreeCurAssign(&T, 'A');
	LBiTreeLeftInsert(&T, 'B');
	LBiTreeRightInsert(&T, 'C');

	BiTNode* cur = LBiTreeFind(&T, 'B');
	LBiTreeLeftInsert(cur, 'D');
	LBiTreeRightInsert(cur, 'E');

	cur = LBiTreeFind(&T, 'D');
	LBiTreeLeftInsert(cur, 'H');
	LBiTreeRightInsert(cur, '#');

	cur = LBiTreeFind(&T, 'E');
	LBiTreeLeftInsert(cur, '#');
	LBiTreeRightInsert(cur, '#');


	cur = LBiTreeFind(&T, 'H');
	LBiTreeLeftInsert(cur, '#');
	LBiTreeRightInsert(cur, 'K');

	cur = LBiTreeFind(&T, 'C');
	LBiTreeLeftInsert(cur, 'F');
	LBiTreeRightInsert(cur, 'G');

	cur = LBiTreeFind(&T, 'F');
	LBiTreeLeftInsert(cur, 'I');
	LBiTreeRightInsert(cur, '#');

	cur = LBiTreeFind(&T, 'G');
	LBiTreeLeftInsert(cur, '#');
	LBiTreeRightInsert(cur, 'J');

	if (!LBiTreeEmpty(&T))
	{
		printf("������Ϊ�� ��Ϊ: %c \n", LBiTreeRoot(&T));
		printf("���������Ϊ : %d \n", LBiTreeDepth(&T));
	}
	else
	{
		printf("����Ϊ�� �޸�\n");
	}

	cur = LBiTreeFind(&T, 'F');

	printf("�ýڵ���: %c \n", 'F');
	printf("�ýڵ��˫����: %c \n", LBiTreeParent(cur));
	printf("�ýڵ��������: %c \n", LBiTreeLeftChild(cur));
	printf("�ýڵ���Һ�����: %c \n", LBiTreeRightChild(cur));
	printf("�ýڵ�����ֵ���: %c \n", LBiTreeLeftSibling(cur));
	printf("�ýڵ�����ֵ���: %c \n", LBiTreeRightSibling(cur));

	printf("ǰ�����: ");
	LBiTreePreOrderTraverse(&T);
	printf("\n");

	printf("�������: ");
	LBiTreeInOrderTraverse(&T);
	printf("\n");

	printf("�������: ");
	LBiTreePostOrderTraverse(&T);
	printf("\n");

	LBiTreeDestroy(&T);

	if (!LBiTreeEmpty(&T))
	{
		printf("������Ϊ�� ��Ϊ: %c \n", LBiTreeRoot(&T));
		printf("���������Ϊ : %d \n", LBiTreeDepth(&T));
	}
	else
	{
		printf("����Ϊ�� �޸�\n");
	}

}
int main()
{
	//LBiTreeTest1();
	LBiTreeTest2();
	return 0;
}