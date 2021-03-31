#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L)//L为指针的指针
{
    *L= (DuLinkedList)malloc(sizeof(DuLinkedList));//申请内存
    if(!(*L))			//若申请失败返回错误
        return ERROR;
    (*L)->next = NULL;//初始化头结点
    (*L)->prior= NULL;
    return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L)//L为指针的指针
{
    if(*L){
        DuLNode *save1;//用于储存*L的值
        save1=(*L)->prior;
        while(save1){                //找到头指针，因为不确定用户传入的是否是头指针
            *L=save1;
            save1=save1->prior;
        }
        for(;*L;){
        free(*L);//
        *L=(*L)->next;}
    }
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
    if (!p) {
        printf("您插入的位置无效\n");
        return ERROR;
    }
    q->prior=p->prior;//把p的前一个变成q的前一个
    q->next=p;//把q插在p前面
    p->prior=q;
    return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
    if (!p) {
        printf("您插入的位置无效\n");
        return ERROR;
    }
    q->next=p->next;//把q插在p后头
    q->prior=p;
    p->next=q;
    return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if(!p || !(p->next))//不存在p或者p后一个结点就报错
        return ERROR;
    DuLNode *q;//设置q来指向p的后一个结点
    q = p->next;
    p->next=q->next;//把q分离出链表
    q->next->prior=p;
    if (!*e)
        return ERROR;//若e没被分配内存就报错
    *e = q->data;//题目的意思是将值赋值给e指向的空间吧
    free(q);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))//L为指向结构体的指针
{
    DuLNode *p;
    p = L->next;//创建一个指针来遍历
    int data;
    while(p){
        data=p->data;
        printf(data);//这里就是打印不出来，有段错误，为什么？
        p = p->next;}
    }



