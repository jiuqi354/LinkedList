#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int DuListEmpty(DuLinkedList L);

int main(){
    ElemType e=0;
    char choice,num[1024];
    int data=0;
    DuLinkedList head=NULL;//这里不能直接建立2级指针，要用&，不然会出现一堆意想不到的段错误T_T
    DuLinkedList p=NULL,q=NULL;
    for(;;){
    puts("————————————双链表ADT——————————————");
    puts("1.创建空链表\n");
    puts("2.销毁链表\n");
    puts("3.在某一结点处插入一个新的结点\n");
    puts("4.删除链表中的某一结点\n");
    puts("5.遍历双链表\n");
    puts("6.输入数据（按顺序）\n");
    puts("7.清空屏幕\n");
    puts("8.退出\n");
    puts("请输入你的选择所对应的数字（1-8）:");
    scanf("%s",&choice);
    switch (choice) {
        case '1':
            if(DuListEmpty(head)!=0){
                break;
            }
            if(InitList_DuL(&head)==SUCCESS)
                puts("创建链表成功\n");
            else{puts("创建链表失败\n");}
            break;
        case '2':
            DestroyList_DuL(&head);
            puts("摧毁成功\n");
            break;
        case '3':
            if(DuListEmpty(head)==0){
                break;
            }
            printf("请输入你要插入的结点的数据来创建该结点：");
            scanf("%d",&data);
            q=(DuLinkedList)malloc(sizeof(DuLinkedList));
            q->data=data;
            printf("请输入需要插入的位置对应的结点的数据：");
            scanf("%d",&data);
        A:  printf("若要插到该结点后面请按1，要插到前头请按2:");
            scanf("%s",&choice);
            //因为search函数仅返回status，所以这里我只能再来一个遍历
            p=head;//用p来指向插入点
            for(int i=0;p;i++){
                if(p->data==data){
                    break;
                    }
                p = p->next;
            }
            if(!p){
                puts("不存在该结点");
                break;
            }
            switch (choice) {
                case '1':
                    if(InsertAfterList_DuL(p,q)==SUCCESS){
                    printf("插入成功");
                    break;}
                    puts("插入失败");
                    break;
                case '2':
                    if(InsertBeforeList_DuL(p,q)==SUCCESS){
                    printf("插入成功");
                    break;}
                    printf("插入失败");
                    break;
                default:
                    printf("输入错误，请输入数字1或2\n");
                    goto A;
            }
            break;
        case '4':
            if(DuListEmpty(head)==0){
                break;
            }
            puts("请输入需要删除的结点对应的数据：");
            scanf("%d",&data);
            //因为search函数仅返回status，所以这里我只能再来一个遍历
            p=head;//用p来指向插入点
            for(int i=0;p;i++){
                if(p->data==data){
                    break;
                }
                p = p->next;
            }
            if(!p){
                puts("不存在该结点\n");
                break;
            }
            DeleteList_DuL(p,&e);
            break;
        case '5':
            if(DuListEmpty(head)!=1){
                break;
            }
            TraverseList_DuL(head, (void (*)(ElemType)) &e);
            puts("\n遍历结束\n");
            break;
        case '6'://暂时只能添加一次，循环的话用getchar会吃了我的数据所以不行……
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
         */int i;
         for(;;){
            printf("请输入要加入的数据,要退出请直接按回车：\n");
            fflush(stdin);
            strcpy(num,"");
            scanf("%[^\n]",&num);
            if(num[0]=='\0'){
                break;
            }
            i=sscanf(num,"%d",&data);
            if(i==0||i==-1){
                puts("你的输入有误，请重新输入");
                continue;}
            q=(DuLinkedList)malloc(sizeof(DuLinkedList));
            p->next=q;
            q->data=data;
            q->prior=p;
            q->next=NULL;
            p=q;
            puts("添加成功");}
            break;
        case '7':
            system("cls");
            break;
        case '8':
            exit(0);
        default:
            printf("输入错误，返回菜单\n");
            break;
        }
    }
}
/**
 *  @name        : int DuListEmpty(DuLinkedList L)
 *	@description :judge whether the linked list is empty
 *	@param		 : L(the head node)
 *	@return		 : int
 *  @notice      : None
 */
int DuListEmpty(DuLinkedList L) {
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