#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter un nœud d'une liste doublement chaînée
struct Node {
    int data;               // Donnée stockée dans le nœud
    struct Node* prev;      // Pointeur vers le nœud précédent
    struct Node* next;      // Pointeur vers le nœud suivant
};

// Fonction pour créer un nouveau nœud d'une liste doublement chaînée
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour insérer un nœud au début d'une liste doublement chaînée
void insertNodeAtBeginning(struct Node** head, int data) {
    // Créer un nouveau nœud
    struct Node* newNode = createNode(data);
    
    // Mettre à jour les pointeurs du nouveau nœud
    newNode->next = *head;
    newNode->prev = NULL;
    
    // Mettre à jour le nœud suivant de la tête de liste s'il existe
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    // Mettre à jour la tête de liste pour qu'elle pointe vers le nouveau nœud
    *head = newNode;
}

// Fonction pour insérer un nœud à la fin d'une liste doublement chaînée
void insertNodeAtEnd(struct Node** head, int data) {
    // Créer un nouveau nœud
    struct Node* newNode = createNode(data);
    
    // Si la liste est vide, le nouveau nœud devient la tête de liste
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Parcourir la liste jusqu'à atteindre le dernier nœud
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        
        // Mettre à jour les pointeurs du nouveau nœud
        current->next = newNode;
        newNode->prev = current;
    }
}

// Fonction pour insérer un nœud après un nœud donné dans une liste doublement chaînée
void insertNodeAfterNode(struct Node* prevNode, int data) {
    // Vérifier si le nœud précédent est NULL
    if (prevNode == NULL) {
        printf("Le nœud précédent ne peut pas être NULL.");
        return;
    }
    
    // Créer un nouveau nœud
    struct Node* newNode = createNode(data);
    
    // Mettre à jour les pointeurs du nouveau nœud
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    
    // Mettre à jour le nœud suivant du nœud précédent s'il existe
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    
    // Mettre à jour le nœud suivant du nœud précédent pour qu'il pointe vers le nouveau nœud
    prevNode->next = newNode;
}

// Fonction pour supprimer un nœud donné d'une liste doublement chaînée
void deleteNode(struct Node** head, struct Node* nodeToDelete) {
    // Cas particulier : si le nœud à supprimer est la tête de liste
    if (*head == nodeToDelete) {
        *head = nodeToDelete->next;  // Mettre à jour la tête de liste pour qu'elle pointe vers le nœud suivant
        
        // Mettre à jour le nœud précédent du nouveau nœud de tête s'il existe
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } else {
        // Mettre à jour le nœud suivant du nœud précédent
        nodeToDelete->prev->next = nodeToDelete->next;
        
        // Mettre à jour le nœud précédent du nœud suivant s'il existe
        if (nodeToDelete->next != NULL) {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }
    }
    
    // Libérer la mémoire du nœud supprimé
    free(nodeToDelete);
}

// Fonction pour afficher les éléments d'une liste doublement chaînée
void displayList(struct Node* head) {
    struct Node* current = head;
    
    // Parcourir la liste en partant de la tête de liste
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");
}

// Exemple d'utilisation des opérations de liste doublement chaînée
int main() {
    struct Node* head = NULL;
    
    // Insérer des nœuds au début de la liste
    insertNodeAtBeginning(&head, 3);
    insertNodeAtBeginning(&head, 2);
    insertNodeAtBeginning(&head, 1);
    
    printf("Liste après insertion au début : ");
    displayList(head);  // Résultat : 1 2 3
    
    // Insérer des nœuds à la fin de la liste
    insertNodeAtEnd(&head, 4);
    insertNodeAtEnd(&head, 5);
    
    printf("Liste après insertion à la fin : ");
    displayList(head);  // Résultat : 1 2 3 4 5
    
    // Insérer un nœud après un nœud donné
    struct Node* nodeToInsertAfter = head->next;
    insertNodeAfterNode(nodeToInsertAfter, 6);
    
    printf("Liste après insertion après un nœud donné : ");
    displayList(head);  // Résultat : 1 2 6 3 4 5
    
    // Supprimer un nœud donné
    struct Node* nodeToDelete = head->next->next;
    deleteNode(&head, nodeToDelete);
    
    printf("Liste après suppression d'un nœud donné : ");
    displayList(head);  // Résultat : 1 2 3 4 5
    
    return 0;
}