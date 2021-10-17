#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *Next;
};

void append (struct ListNode** head, int val){
    
    struct ListNode* new = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *back = *head;
    new->val = val;
    new->Next = NULL;
    if (*head ==NULL){
        *head = new;
        return;
    }
    while (back->Next!=NULL){
        back = back->Next;
    }
    back->Next = new;
    return;
    
}

struct ListNode* addNode(int val, struct ListNode* node){
    struct ListNode* new = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->Next = new;
    new->Next = NULL;
    new->val = val;
    return node->Next;
}

struct ListNode* addTwo (struct ListNode* L1, struct ListNode* L2){
    int carry = 0;
    struct ListNode* new = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode* result =new;
    while (L1!=NULL || L2!=NULL){
        int sum = L1->val +L2->val +carry;
        printf("L %d %d %d\n",L1->val,L2->val,sum );
        if (sum>9){
            carry = 1;
        }
        else {
            carry=0;
        }
        sum = sum%10;
        result = addNode(sum, result);
        printf("L %d %d %d\n",L1->val,L2->val,sum );
        L1=L1->Next;
        L2=L2->Next;
    }
    if(carry){
        result = addNode(1, result);
    }
    return new->Next;
}

void printList (struct ListNode* node){
    while (node!=NULL){
        printf ("%d", node->val);
        node =node->Next;
        }
    }
void reverseprint (struct ListNode* node){
        if (node==NULL){return;}
        reverseprint(node->Next); 
        printf("%d", node->val);
}

int main()
{
    printf("Hello World \n");
    struct ListNode* head1 = NULL;
    struct ListNode* front = head1;
    append (&head1, 1);
    addNode(2, head1);
    append (&head1, 3);
    printList(head1);
    printf ("\n");
    struct ListNode* head2 =NULL;
    append (&head2, 9);
    addNode(1, head2);
    append (&head2, 7);
    printList(head2);
    printf ("\n");
    struct ListNode* result = addTwo(head1, head2);
   
    reverseprint(result);
    return 0;
}
