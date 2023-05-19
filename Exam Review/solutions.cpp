#include <iostream>
#include <stack>
struct node{
	int data;
	node* next;
};
struct tree_node{
	int data;
	tree_node* left_child;
	tree_node* right_child;
}
int ret_sum(int[] int_arr, int size){
	int sum = 0;
	for(int i = 0; i < size; i++){
		if(int_arr[n] % 2 == 0){
			sum += int_arr[n];
		}
	}
	return sum;
}
int ret_length(node* head){
	node* aux = head;
	int length;
	while(aux != NULL){
		length++;
		aux = aux->next;
	}
}
char[] reverse_char_arr(char[] string){
	stack<char> myStack;
	int index = 0;
	while(string[index] != '\0'){
		myStack.push(string[index])
		index++;
	}

	int new_index = 0;
	char[index] = new_arr;
	while(index != 0){
		new_arr[new_index] = myStack.pop();
		index--;
		new_index++;
	}
	return new_arr;
}
tree_node* find_min(tree_node* root){
	if(root != NULL){
		if(root->left_child == NULL){
			return root->data;
		}else
		find_min(root->left_child);
	}
	
}
