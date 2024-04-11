#include <stdio.h>
#include <stdlib.h>

/* Structure de base pour un élément de la pile ou de la file */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Structure pour la pile */
typedef struct Stack {
    Node* top;
} Stack;

/* Structure pour la file */
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

/* Initialiser une pile */
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

/* Vérifier si la pile est vide */
int isStackEmpty(Stack* stack) {
    return (stack->top == NULL);
}

/* Empiler un élément sur la pile */
void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d a été empilé sur la pile.\n", data);
}

/* Dépiler un élément de la pile */
int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Erreur : La pile est vide.\n");
        return -1;
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void displayPop(Stack* stack) {
    Node* currentNode = stack->top;
    // Parcourir la liste et afficher chaque élément
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    
    printf("\n");
}

/* Initialiser une file */
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/* Vérifier si la file est vide */
int isQueueEmpty(Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

/* Enfiler un élément dans la file */
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d a été enfilé dans la file.\n", data);
}

/* Défiler un élément de la file */
int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Erreur : La file est vide.\n");
        return -1;
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;


}

void displayQueue(Queue* queue) {
    Node* currentNode = queue->front;
    
    // Parcourir la liste et afficher chaque élément
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    
    printf("\n");
}


int main() {
    // Exemple d'utilisation de la pile
    Stack* stack = createStack();
    push(stack, 10);
    displayPop(stack);
    push(stack, 20);
    displayPop(stack);
    push(stack, 30);
    displayPop(stack);
    printf("%d a été dépilé de la pile.\n", pop(stack));
    displayPop(stack);
    printf("%d a été dépilé de la pile.\n", pop(stack));
    displayPop(stack);
    // Exemple d'utilisation de la file
    Queue* queue = createQueue();
    enqueue(queue, 100);
    displayQueue(queue);
    enqueue(queue, 200);
    displayQueue(queue);
    enqueue(queue, 300);
    displayQueue(queue);
    printf("%d a été défifé de la file.\n", dequeue(queue));
    displayQueue(queue);
    printf("%d a été défifé de la file.\n", dequeue(queue));
    displayQueue(queue);

    return 0;
}