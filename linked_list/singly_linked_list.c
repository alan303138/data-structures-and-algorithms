#include <stdio.h>
#include <stdlib.h>

// 定義一個 linked list node，有一個整數資料跟下一個node的指標，其中指標用了遞迴指向自己的型別
struct data
{
    int number;
    struct data *next;
};

// 定義 Data 為 struct data 的資料型別
typedef struct data Data;

// 初始化head，並定義為空，表示沒有第一筆資料，head為必要資料，不可free()，
// 有兩種linked list的head，第一種是第一項為head，第二種事第一項為head的下一項，這種head的值為null
Data *head = NULL;

// 在尾部建立一個新node，並帶入指定的值
void createNewNode(int number)
{

    // 做一個的值為number且指向null的新node
    Data *new_node = malloc(sizeof(Data));
    new_node->number = number;
    new_node->next = NULL;

    if (head == NULL)
    {
        // 如果head為NUll，表沒有任何node，為head建立第一個node
        head = new_node;
    }
    else
    {
        // 得到temp為此list最後一筆資料，再加上一筆新node
        Data *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// 找出linked list長度
void printLength()
{
    Data *temp = head;
    int counter = 0;
    while (temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    printf("the length of the list is %d\n", counter);
}

// 印出所有資料
void printAll(Data *start)
{
    if (head == NULL)
    {
        printf("No data!\n");
    }
    else
    {
        printf("Data : \n");
        while (start->next != NULL)
        {
            printf("%d->", start->number);
            start = start->next;
        }
        printf("%d \n", start->number);
    }

    printf("\n");

    printLength();
}

// 刪除第一筆資料
void deleteHead()
{
    if (head == NULL)
    {
        // 如果沒有任何一筆資料
        printf("Already delete all data!\n");
    }
    else
    {
        // head_node為第一筆資料
        Data *head_node = head;
        // next_node為head_node的下一筆，todo 此處沒初始化該存的大小
        Data *next_node = NULL;

        // 如果有第二筆資料，存在next_node中
        if (head->next)
        {
            next_node = head_node->next;
        }

        // 把head的值改為第二筆資料
        head = next_node;

        // 刪除原本第一筆資料head_node
        free(head_node);
    }
}

// 刪除最後一筆
void deleteTail()
{
    if (head == NULL)
    {
        // 如果沒有任何一筆資料
        printf("Already delete all data!\n");
    }
    else
    {
        // tail_node表最後一筆
        Data *tail_node = head;
        // pre_node倒數第二筆
        Data *pre_node = NULL;

        // 找出最後一筆和倒數第二筆
        while (tail_node->next != NULL)
        {
            pre_node = tail_node;
            tail_node = tail_node->next;
        }

        if (pre_node)
        {
            // 如果不止一筆，設定倒數第二筆指向NULL
            pre_node->next = NULL;
        }
        else
        {
            // 如果只有一筆，設定第一筆為NULL
            head = NULL;
        }

        free(tail_node);
    }
}

// 刪除所有資料
void deleteAll()
{
    if (head == NULL)
    {
        printf("Already delete all data!\n");
    }
    else
    {
        Data *temp = head;
        Data *delete_node;
        // 刪除了第一筆資料
        head = NULL;

        // 從第二筆刪除到最後一筆
        while (temp->next != NULL)
        {
            delete_node = temp;
            temp = temp->next;
            free(delete_node);
        }
        printf("Already delete all data!\n");
    }
}

/* Function to reverse the linked list */
void reverse()
{
    Data *prev = NULL;
    Data *current = head;
    Data *next = NULL;

    // current為NULL表示current的上一筆prev->NULL，為最後一筆資料
    while (current != NULL)
    {
        // Store next，因為當下node的next即將被替換掉，要先存起來
        next = current->next;

        // Reverse current node's pointer，把當下node的下一筆指向上一筆資料，反轉資料
        current->next = prev;

        // Move pointers one position ahead. 上一筆node存放現在這筆
        prev = current;
        // 現在這一筆node存放下一筆
        current = next;
    }
    // 把最後一筆資料帶入head完成反轉
    head = prev;
}

int main()
{
    while (1)
    {
        int choice, data;
        printf("\n");
        printf("-----Choose the function you want :-----\n");
        printf("1. Add data\n");
        printf("2. Print All datas\n");
        printf("3. Delete first data\n");
        printf("4. Delete last data\n");
        printf("5. Delete ALL datas\n");
        printf("6. Reverse All datas\n");
        printf("7. Exit\n");
        printf("----------------------------------------\n");
        printf("your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n");
            printf("Input data:");
            scanf("%d", &data);
            createNewNode(data);
            printf("-----Add data successfully!-----\n\n");
            printAll(head);
            break;
        case 2:
            printAll(head);
            break;
        case 3:
            deleteHead();
            printAll(head);
            break;
        case 4:
            deleteTail();
            printAll(head);
            break;
        case 5:
            deleteAll();
            break;
        case 6:
            reverse();
            printAll(head);
            break;
        case 7:
            // exit(0)會結束main程式，相當於return 0
            exit(0);
        default:
            printf("Error!\n");
            break;
        }
        printf("\n");
    }
    return 0;
}