#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
int ListEmpty(LinkedList L);

int main() {
    ElemType e = 0;
    int choice = 0, data = 0;
    LinkedList head = NULL;//这里不能直接建立2级指针，要用&，不然会出现一堆意想不到的段错误T_T
    LinkedList p = NULL, q = NULL;
    for (;;) {
        puts("————————————单链表ADT——————————————");
        puts("1.创建空链表\n");
        puts("2.销毁链表\n");
        puts("3.在某一结点后插入一个新的结点\n");
        puts("4.删除链表中的某一结点\n");
        puts("5.遍历单链表\n");
        puts("6.输入数据（按顺序）\n");
        puts("7.清空屏幕\n");
        puts("8.退出\n");
        puts("请输入你的选择所对应的数字（1-8）:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (ListEmpty(head) != 0) {
                    break;
                }
                if (InitList(&head) == SUCCESS)
                    puts("创建链表成功\n");
                else { puts("创建链表失败\n"); }
                break;
            case 2:
                DestroyList(&head);
                puts("摧毁成功\n");
                break;
            case 3:
                if (ListEmpty(head) == 0) {
                    break;
                }
                printf("请输入你要插入的结点的数据来创建该结点：");
                scanf("%d", &data);
                q = (LinkedList) malloc(sizeof(LinkedList));
                q->data = data;
                printf("请输入需要插入的位置对应的结点的数据：");
                scanf("%d", &data);
                //因为search函数仅返回status，所以这里我只能再来一个遍历
                p = head;//用p来指向插入点
                for (int i = 0; p; i++) {
                    if (p->data == data) {
                        break;
                    }
                    p = p->next;
                }
                if (!p) {
                    puts("不存在该结点");
                    break;
                }
                if (InsertList(p, q) == SUCCESS) {
                    printf("插入成功");
                    break;
                }
                puts("插入失败");
                break;
            case 4:
                if (ListEmpty(head) == 0) {
                    break;
                }
                puts("请输入需要删除的结点对应的数据：");
                scanf("%d", &data);
                //因为search函数仅返回status，所以这里我只能再来一个遍历
                p = head;//用p来指向插入点
                for (int i = 0; p; i++) {
                    if (p->data == data) {
                        break;
                    }
                    p = p->next;
                }
                if (!p) {
                    puts("不存在该结点\n");
                    break;
                }
                DeleteList(p, &e);
                break;
            case 5:
                if (ListEmpty(head) != 1) {
                    break;
                }
                TraverseList(head, (void (*)(ElemType)) &e);
                puts("遍历结束\n");
                break;
            case 6:
                if(!head){
                    puts("未创建链表，请先创建链表！\n");
                    break;
                }
                p=head;
                while (p->next){
                    p=p->next;
                }
                /*
                 * for(;;){
                 * printf("请输入要加入的数据：\n");
                 * fflush(stdin);
                 * if(getchar()=='\n')
                    break;
                    scanf("%d",&data);
                    q=(DuLinkedList)malloc(sizeof(DuLinkedList));
                    p->next=q;
                    q->data=data;}
                    这个会吃数据，已舍弃
                 */
                printf("请输入要加入的数据：\n");
                scanf("%d",&data);
                q=(LinkedList)malloc(sizeof(LinkedList));
                p->next=q;
                q->data=data;
                puts("添加成功");
                break;
            case 7:
                system("cls");
                break;
            case 8:
                exit(0);
            default:
                printf("输入错误，返回菜单\n");
                break;
        }
    }
}

/**
 *  @name        : int ListEmpty(LinkedList L)
 *	@description :judge whether the linked list is empty
 *	@param		 : L(the head node)
 *	@return		 : int
 *  @notice      : None
 */
int ListEmpty(LinkedList L) {
    if (L && L->next){
        return 1;}    //非空
    if(L){
        puts("存在空链表，建议先加入数据") ;  //空链表
        return 2;}
    else {
        puts("未创建链表");
        return 0;   //链表不存在
    }
}