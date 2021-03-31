#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    *L = (LinkedList)malloc(sizeof(LinkedList));//申请内存
    if(!(*L))			//若申请失败返回错误
        return ERROR;
    (*L)->next = NULL;//初始化头结点
    return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) //由于需要使用该函数后L的值发生改变即改变指针L的指向，所以用*L
{
    LNode *save;
    while(L!=NULL){
    save=(*L)->next;
    free(*L);
    *L=save;
    }
}


/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
    if (!p) {
        printf("您插入的位置无效\n");
        return ERROR;
    }
    q->next=p->next;//把q插在p后头
    p->next=q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    if(!p || !(p->next))//不存在p或者p后一个结点就报错
        return ERROR;
    LNode *q;//设置一个结点
    q = p->next;
    if (!*e)
        return ERROR;//若e没被分配内存就报错
    *e = q->data;//题目的意思是将值赋值给e指向的空间吧
    p->next = q->next;
    free(q);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
        LNode *p;
        p = L->next;//创建一个指针来遍历
        int data;
        while(p){
            data=p->data;
            printf("%d",data);
            p = p->next;}
    }

/**
 *  @name        : void visit(ElemType e)
 *	@description : print e
 *	@param		 : e
 *	@return		 : None
 *  @notice      : None
 */
void visit(ElemType e){
    printf("%d",e);
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
    LNode *p;
    p = L;//创建一个指针来遍历
    for(int i=0;p;i++){
        if(p->data==e){
            printf("该数据在链表的第%d个位置",i);
            return SUCCESS;}
        p = p->next;
    }
    return ERROR;//没找到
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    if(!*L||!(*L)->next){
        return ERROR;           //如果发现不是头结点或者只有头结点就报错
    }
    LNode *front, *middle, *Next;		//定义前中后三个指针
    front = *L;
    middle= (*L)->next;
    front->next = NULL;                 //先去掉头指针的next指针防止成环
    while(middle){
        Next = middle->next;            //后指针放最后
        middle->next = front;			//将中间的指针指向反转
        front=middle;					//前中指针后移,进入下一循环
        middle= Next;
    }
    *L=front;                           //头指针指向原来的尾部
    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {

}

