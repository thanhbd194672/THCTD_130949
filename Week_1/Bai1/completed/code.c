#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Data{
    char word[10];
    int* line;
    int* col;
    int count;
}Data;

typedef struct Node{
    struct Node *left;
    struct Node *right;
    Data data;
}Node;

Node* make_new_node(Data data){
    Node * tmp = (Node*)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data.count = 0;
    return tmp;
}

Node* add_root(Data add_item,Node *root){
    if(root == NULL){
        root = make_new_node(add_item);
        root->data.count = 1;
    }
    else{
        if(strcmp(root->data.word,add_item.word) > 0){
            root->left = add_root(add_item,root->left);
        }
        else if(strcmp(root->data.word,add_item.word) < 0){
            root->right = add_root(add_item,root->right);
        }
        else{
            root->data.count += 1;
        }
    }
    return root;
}

Node* scan_file(char *file_name, Node* root){
    FILE *fp = fopen(file_name,"r");
    if(fp == NULL){
        printf("File not found !\n");
        return NULL;
    }
    else{
        char str[1000];
        while(fgets(str,1000,fp)){
        // printf("%s",str);
        
        char  word[100];
        int length_word = 0;
        for(int i = 0 ; i < strlen(str) ; i++){
            
            if( ('a' <= str[i] && str[i] <= 'z')  ){
                word[length_word] = str[i];
                length_word += 1;
            }
            else if(('A' <= str[i] && str[i] <= 'Z')){
                if(str[i-1] != '.' && i != 0){
                    int j = i+1;
                   
                    while(str[j] != ' '){
                        j+=1;
                    }

                    i = j;
                }
                else{
                    word[length_word] = str[i] + 32;
                    length_word += 1;
                }
                
            }
            else{
                if(length_word!=0){
                    char *word_add = (char*)malloc(sizeof(char) * length_word + 2);
                    
                    for(int j = 0 ; j < length_word ;j ++){
                        // printf("%c",word[j]);
                        word_add[j] = word[j]; 
                    }
                    word_add[length_word] = '\0';
                
                    printf("%s \n",word_add);
                    length_word = 0;
                }
            }
        }
        }
        return root;
    }
    
}


int main(void){
    Node* root = NULL;
    Data tmp ;
   

    root = scan_file("C:\\Users\\Thanh\\OneDrive\\Documents\\GitHub\\THCTD_130949\\Week_1\\Bai1\\completed\\vanban.txt",root);
    

}