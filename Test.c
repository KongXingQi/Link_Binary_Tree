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
		printf("此树不为空 根为: %c \n",LBiTreeRoot(&T));
		printf("此树的深度为 : %d \n",LBiTreeDepth(&T));
	}
	else
	{
		printf("此树为空 无根\n");
	}

	cur = LBiTreeFind(&T, 'C');

	printf("该节点是: %c \n",'C');
	printf("该节点的双亲是: %c \n",LBiTreeParent(cur));
	printf("该节点的左孩子是: %c \n", LBiTreeLeftChild(cur));
	printf("该节点的右孩子是: %c \n", LBiTreeRightChild(cur));
	printf("该节点的左兄弟是: %c \n", LBiTreeLeftSibling(cur));
	printf("该节点的右兄弟是: %c \n", LBiTreeRightSibling(cur));


	printf("前序遍历: ");
	LBiTreePreOrderTraverse(&T);
	printf("\n");

	printf("中序遍历: ");
	LBiTreeInOrderTraverse(&T);
	printf("\n");

	printf("后序遍历: ");
	LBiTreePostOrderTraverse(&T);
	printf("\n");

	LBiTreeDestroy(&T);

	if (!LBiTreeEmpty(&T))
	{
		printf("此树不为空 根为: %c \n", LBiTreeRoot(&T));
		printf("此树的深度为 : %d \n", LBiTreeDepth(&T));
	}
	else
	{
		printf("此树为空 无根\n");
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
		printf("此树不为空 根为: %c \n", LBiTreeRoot(&T));
		printf("此树的深度为 : %d \n", LBiTreeDepth(&T));
	}
	else
	{
		printf("此树为空 无根\n");
	}

	cur = LBiTreeFind(&T, 'F');

	printf("该节点是: %c \n", 'F');
	printf("该节点的双亲是: %c \n", LBiTreeParent(cur));
	printf("该节点的左孩子是: %c \n", LBiTreeLeftChild(cur));
	printf("该节点的右孩子是: %c \n", LBiTreeRightChild(cur));
	printf("该节点的左兄弟是: %c \n", LBiTreeLeftSibling(cur));
	printf("该节点的右兄弟是: %c \n", LBiTreeRightSibling(cur));

	printf("前序遍历: ");
	LBiTreePreOrderTraverse(&T);
	printf("\n");

	printf("中序遍历: ");
	LBiTreeInOrderTraverse(&T);
	printf("\n");

	printf("后序遍历: ");
	LBiTreePostOrderTraverse(&T);
	printf("\n");

	LBiTreeDestroy(&T);

	if (!LBiTreeEmpty(&T))
	{
		printf("此树不为空 根为: %c \n", LBiTreeRoot(&T));
		printf("此树的深度为 : %d \n", LBiTreeDepth(&T));
	}
	else
	{
		printf("此树为空 无根\n");
	}

}
int main()
{
	//LBiTreeTest1();
	LBiTreeTest2();
	return 0;
}