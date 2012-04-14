// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#include <a_samp>
#define _DEBUG 1
//#define RUN_TESTS

#include <YSI\y_bintree>
#include <YSI\y_testing>

Test:addtwice()
{
	new
		BinaryTree:tree<20>;
	Bintree_Add(tree, 31, 100, 0);
	Bintree_Add(tree, 42, 100, 1);
	new
		pos,
		leaf;
	while ((pos = Bintree_FindValue(tree, 100, leaf)) != BINTREE_NOT_FOUND)
	{
		printf("%d %d", pos, leaf);
		//ASSERT
	}
}

Test:addtwiceremove()
{
	new
		BinaryTree:tree<20>;
	Bintree_Add(tree, 31, 100, 0);
	Bintree_Add(tree, 42, 100, 1);
	Bintree_Delete(tree, 0, 2);
	new
		pos,
		leaf;
	while ((pos = Bintree_FindValue(tree, 100, leaf)) != BINTREE_NOT_FOUND)
	{
		printf("%d %d", pos, leaf);
		//ASSERT
	}
}

