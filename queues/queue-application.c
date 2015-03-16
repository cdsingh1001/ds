#include "queue.h"


typedef struct my_data {
    char name[20];
    int age;
} Myd;

void printData(void* my_data)
{
    Myd *data = (Myd*)my_data;
    if (data)
        printf("\n (%s, %d)\n",data->name, data->age);
}

int main()
{
    unsigned int choice = 0;
    int ret = 0;
    queue_t *queue = NULL;
    Myd data;
    Myd *datap = NULL;

    while (1) {
        printf("\n1. Print Q    :\n");
        printf("2. Enqueue    :\n");
        printf("3. Dequeue    :\n");
        printf("4. Create Q   :\n");
        printf("5. Delete Q   :\n");
        printf("9. Quit       :\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_queue(queue,printData);
                break;
            case 2:
                printf("Enter Name:");
                scanf("%s", data.name);
                printf("Enter Age:");
                scanf("%d", &data.age);
                ret = enqueue(queue,(void*)&data,sizeof(Myd));
                if (ret != 0) {
                    printf("ENQUEUE ERROR !!!\n");
                }
                break;
            case 3:
                datap = (Myd*) dequeue(queue);
                if (!datap)
                    printf("EMPTY QUEUE !!!");
                else {
                    printData(datap);
                }
                free(datap);
                datap = NULL;
                break;
            case 4:
                create_queue(&queue);
                printf("Queue created\n");
                break;
            case 5:
                delete_queue(queue,sizeof(Myd));
                queue = NULL;
                printf("Queue deleted\n");
                break;
            case 9:
                delete_queue(queue,sizeof(Myd));
                printf("Queue deleted\n");
                exit(0);
                break;
            default:
                printf("Try again...\n");
                break;
        }
    }

    return 0;
}
