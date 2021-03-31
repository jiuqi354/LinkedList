#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
int ListEmpty(LinkedList L);

int main() {
    ElemType e = 0;
    int choice = 0, data = 0;
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
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (ListEmpty(head) != 0) {
                    break;
                }
                if (InitList(&head) == SUCCESS)
                    puts("��������ɹ�\n");
                else { puts("��������ʧ��\n"); }
                break;
            case 2:
                DestroyList(&head);
                puts("�ݻٳɹ�\n");
                break;
            case 3:
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
            case 4:
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
            case 5:
                if (ListEmpty(head) != 1) {
                    break;
                }
                TraverseList(head, (void (*)(ElemType)) &e);
                puts("��������\n");
                break;
            case 6:
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
                 */
                printf("������Ҫ��������ݣ�\n");
                scanf("%d",&data);
                q=(LinkedList)malloc(sizeof(LinkedList));
                p->next=q;
                q->data=data;
                puts("��ӳɹ�");
                break;
            case 7:
                system("cls");
                break;
            case 8:
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