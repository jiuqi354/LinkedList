#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ListEmpty(LinkedList L);

int main() {
    char num[1024];
    ElemType e = 0;
    char choice ;
    int data = 0;
    LinkedList head = NULL;//���ﲻ��ֱ�ӽ���2��ָ�룬Ҫ��&����Ȼ�����һ�����벻���Ķδ���T_T
    LinkedList p = NULL, q = NULL;
    for (;;) {
        puts("������������������������������ADT����������������������������");
        puts("1.����������\n");
        puts("2.��������\n");
        puts("3.��ĳһ�������һ���µĽ��\n");
        puts("4.ɾ�������е�ĳһ���\n");
        puts("5.����������\n");
        puts("6.�������ݣ���˳��\n");
        puts("7.�����Ļ\n");
        puts("8.�˳�\n");
        puts("���������ѡ������Ӧ�����֣�1-8��:");
        scanf("%s", &choice);
        switch (choice) {
            case '1':
                if (ListEmpty(head) != 0) {
                    break;
                }
                if (InitList(&head) == SUCCESS)
                    puts("��������ɹ�\n");
                else { puts("��������ʧ��\n"); }
                break;
            case '2':
                DestroyList(&head);
                puts("�ݻٳɹ�\n");
                break;
            case '3':
                if (ListEmpty(head) == 0) {
                    break;
                }
                printf("��������Ҫ����Ľ��������������ý�㣺");
                scanf("%d", &data);
                q = (LinkedList) malloc(sizeof(LinkedList));
                q->data = data;
                printf("��������Ҫ�����λ�ö�Ӧ�Ľ������ݣ�");
                scanf("%d", &data);
                //��Ϊsearch����������status������������ֻ������һ������
                p = head;//��p��ָ������
                for (int i = 0; p; i++) {
                    if (p->data == data) {
                        break;
                    }
                    p = p->next;
                }
                if (!p) {
                    puts("�����ڸý��");
                    break;
                }
                if (InsertList(p, q) == SUCCESS) {
                    printf("����ɹ�");
                    break;
                }
                puts("����ʧ��");
                break;
            case '4':
                if (ListEmpty(head) == 0) {
                    break;
                }
                puts("��������Ҫɾ���Ľ���Ӧ�����ݣ�");
                scanf("%d", &data);
                //��Ϊsearch����������status������������ֻ������һ������
                p = head;//��p��ָ������
                for (int i = 0; p; i++) {
                    if (p->data == data) {
                        break;
                    }
                    p = p->next;
                }
                if (!p) {
                    puts("�����ڸý��\n");
                    break;
                }
                DeleteList(p, &e);
                break;
            case '5':
                if (ListEmpty(head) != 1) {
                    break;
                }
                TraverseList(head, (void (*)(ElemType)) &e);
                puts("��������\n");
                break;
            case '6':
                if(!head){
                    puts("δ�����������ȴ�������\n");
                    break;
                }
                p=head;
                while (p->next){
                    p=p->next;
                }
                int i;
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
                    q=(LinkedList)malloc(sizeof(LinkedList));
                    p->next=q;
                    q->data=data;
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
 *  @name        : int ListEmpty(LinkedList L)
 *	@description :judge whether the linked list is empty
 *	@param		 : L(the head node)
 *	@return		 : int
 *  @notice      : None
 */
int ListEmpty(LinkedList L) {
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