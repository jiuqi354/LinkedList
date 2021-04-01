#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int DuListEmpty(DuLinkedList L);

int main(){
    ElemType e=0;
    char choice,num[1024];
    int data=0;
    DuLinkedList head=NULL;//���ﲻ��ֱ�ӽ���2��ָ�룬Ҫ��&����Ȼ�����һ�����벻���Ķδ���T_T
    DuLinkedList p=NULL,q=NULL;
    for(;;){
    puts("������������������������˫����ADT����������������������������");
    puts("1.����������\n");
    puts("2.��������\n");
    puts("3.��ĳһ��㴦����һ���µĽ��\n");
    puts("4.ɾ�������е�ĳһ���\n");
    puts("5.����˫����\n");
    puts("6.�������ݣ���˳��\n");
    puts("7.�����Ļ\n");
    puts("8.�˳�\n");
    puts("���������ѡ������Ӧ�����֣�1-8��:");
    scanf("%s",&choice);
    switch (choice) {
        case '1':
            if(DuListEmpty(head)!=0){
                break;
            }
            if(InitList_DuL(&head)==SUCCESS)
                puts("��������ɹ�\n");
            else{puts("��������ʧ��\n");}
            break;
        case '2':
            DestroyList_DuL(&head);
            puts("�ݻٳɹ�\n");
            break;
        case '3':
            if(DuListEmpty(head)==0){
                break;
            }
            printf("��������Ҫ����Ľ��������������ý�㣺");
            scanf("%d",&data);
            q=(DuLinkedList)malloc(sizeof(DuLinkedList));
            q->data=data;
            printf("��������Ҫ�����λ�ö�Ӧ�Ľ������ݣ�");
            scanf("%d",&data);
        A:  printf("��Ҫ�嵽�ý������밴1��Ҫ�嵽ǰͷ�밴2:");
            scanf("%s",&choice);
            //��Ϊsearch����������status������������ֻ������һ������
            p=head;//��p��ָ������
            for(int i=0;p;i++){
                if(p->data==data){
                    break;
                    }
                p = p->next;
            }
            if(!p){
                puts("�����ڸý��");
                break;
            }
            switch (choice) {
                case '1':
                    if(InsertAfterList_DuL(p,q)==SUCCESS){
                    printf("����ɹ�");
                    break;}
                    puts("����ʧ��");
                    break;
                case '2':
                    if(InsertBeforeList_DuL(p,q)==SUCCESS){
                    printf("����ɹ�");
                    break;}
                    printf("����ʧ��");
                    break;
                default:
                    printf("�����������������1��2\n");
                    goto A;
            }
            break;
        case '4':
            if(DuListEmpty(head)==0){
                break;
            }
            puts("��������Ҫɾ���Ľ���Ӧ�����ݣ�");
            scanf("%d",&data);
            //��Ϊsearch����������status������������ֻ������һ������
            p=head;//��p��ָ������
            for(int i=0;p;i++){
                if(p->data==data){
                    break;
                }
                p = p->next;
            }
            if(!p){
                puts("�����ڸý��\n");
                break;
            }
            DeleteList_DuL(p,&e);
            break;
        case '5':
            if(DuListEmpty(head)!=1){
                break;
            }
            TraverseList_DuL(head, (void (*)(ElemType)) &e);
            puts("\n��������\n");
            break;
        case '6'://��ʱֻ�����һ�Σ�ѭ���Ļ���getchar������ҵ��������Բ��С���
        if(!head){
            puts("δ�����������ȴ�������\n");
            break;
        }
        p=head;
        while (p->next){
            p=p->next;
        }
        /*
         * for(;;){
         * printf("������Ҫ��������ݣ�\n");
         * fflush(stdin);
         * if(getchar()=='\n')
            break;
            scanf("%d",&data);
            q=(DuLinkedList)malloc(sizeof(DuLinkedList));
            p->next=q;
            q->data=data;}
            ���������ݣ�������
         */int i;
         for(;;){
            printf("������Ҫ���������,Ҫ�˳���ֱ�Ӱ��س���\n");
            fflush(stdin);
            strcpy(num,"");
            scanf("%[^\n]",&num);
            if(num[0]=='\0'){
                break;
            }
            i=sscanf(num,"%d",&data);
            if(i==0||i==-1){
                puts("���������������������");
                continue;}
            q=(DuLinkedList)malloc(sizeof(DuLinkedList));
            p->next=q;
            q->data=data;
            q->prior=p;
            q->next=NULL;
            p=q;
            puts("��ӳɹ�");}
            break;
        case '7':
            system("cls");
            break;
        case '8':
            exit(0);
        default:
            printf("������󣬷��ز˵�\n");
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
        return 1;}    //�ǿ�
    if(L){
        puts("���ڿ����������ȼ�������") ;  //������
        return 2;}
    else {
        puts("δ��������");
        return 0;   //��������
    }
}