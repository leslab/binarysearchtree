/** 2016/10/12    **/
/** Cygwinにてgcc **/

#include <stdio.h>

typedef struct _tree_node NODE;

struct _tree_node{
	int num;
	NODE *left;
	NODE *right;
};


NODE *create_tree( NODE *top, int input )
{
	/* top->num > inputなら右のノードを見る、逆なら左のノードを見る */
	/* 見た方が真なら再帰呼び出し、NULLならノードを作ってreturn */
	
	if( top->num > input ){
		if( top->left ){
			create_tree( top->left, input );
		}else{
			top->left = (NODE *)malloc( sizeof( NODE ) );
			top->left->num = input;
			top->left->left = NULL;
			top->left->right = NULL;
			
			return top;
		}
	}else if( top->num < input ){
		if( top->right ){
			create_tree( top->right, input);
		}else{
			top->right = (NODE *)malloc( sizeof( NODE ) );
			top->right->num = input;
			top->right->left = NULL;
			top->right->right = NULL;
			
			return top;
		}
	}
}

void read_tree( NODE *top )
{
	/*左が真なら左へ再帰呼び出し*/
	if( top->left ){
		read_tree( top->left );
	/*左から帰ってきたら、top->numを出力*/
		printf("   %d ", top->num);
	}else{
	/*左がNULLならtop->numを出力*/
		printf("   %d ",top->num);
	}
	
	/*右が真なら再帰呼び出し*/
	if( top->right ){
		read_tree( top->right );
	}
}

void memfree_tree( NODE *top )
{
	if( top->left ){ 
		memfree_tree(top->left);
	}else{
		if( top->right ){
			memfree_tree(top->right);
		}else{
			free( top );
		}
	}
	
}


int main( char *argv[], int argc )
{
	
	int input[] = {3,1101,21,-154,8,67,111,1,-256,33,0,57,-1};
	NODE top;
	int i,length;
	
	top.num   = input[0];
	top.left  = NULL;
	top.right = NULL;
	
	length = sizeof(input)/sizeof(int);
	
	for( i = 1; i<length; i++ ){
		create_tree( &top, input[i] );
	}
	
	printf("before sort: ");
	for (i = 0; i<length; i++ ){
		printf("[%02d]:%d ",i,input[i]);
	}
	printf("\n");
	
	printf("after sort\n");
	read_tree( &top );
	
	memfree_tree( &top );
	
	return 1;
}

