#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct
{
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
}

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d, rear=%d) : ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do{
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q)) 
	{
		error("Queue is full");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
	{
		error("Queue is empty");
		return -1;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int main()
{
	QueueType queue;
	int element, select;

	init_queue(&queue);
	while (1)
	{
		printf("========== M E N U ==========\n");
		printf("1. Input and Enqueue\n");
		printf("2. Dequeue and Print\n");
		printf("3. Print Queue\n");
		printf("4. Exit\n");
		printf("Select Number : ");
		scanf_s("%d", &select);
		printf("\n");

		if (select == 1)
		{
			if (!is_full(&queue))
			{
				printf("Enter Integer : ");
				scanf_s("%d", &element);
				enqueue(&queue, element);
				printf("Enqueue : %d", element);
			}
			else
				printf("Queue is full");
		}
		else if (select == 2)
		{
			element = dequeue(&queue);
			if (element == -1)
			{
				printf("\n");
				continue;
			}
			else
				printf("Dequeue : %d", element);
		}
		else if (select == 3)
		{
			queue_print(&queue);
		}
		else if (select == 4)
		{
			printf("Exit\n");
			exit(1);
		}
		else
		{
			printf("I think.. You pressed select 4, right? Here it is\n");
			exit(1);
		}
		printf("\n\n");
	}
	return 0;
}