#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter un nœud d'une liste chaînée
struct Node {
    int data;           // Donnée stockée dans le nœud
    struct Node* next;  // Pointeur vers le prochain nœud
};

// Fonction pour créer un nouveau nœud d'une liste chaînée
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour insérer un nœud au début d'une liste chaînée
void insertNodeAtBeginning(struct Node** head, int data) {
    // Créer un nouveau nœud
    struct Node* newNode = createNode(data);
    
    // Mettre à jour le prochain pointeur du nouveau nœud pour qu'il pointe vers l'ancienne tête de liste
    newNode->next = *head;
    
    // Mettre à jour la tête de liste pour qu'elle pointe vers le nouveau nœud
    *head = newNode;
}

// Fonction pour insérer un nœud à la fin d'une liste chaînée
void insertNodeAtEnd(struct Node** head, int data) {
    // Créer un nouveau nœud
    struct Node* newNode = createNode(data);
    
    // Si la liste est vide, le nouveau nœud devient la tête de liste
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Sinon, parcourir la liste jusqu'à atteindre le dernier nœud
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        
        // Mettre à jour le prochain pointeur du dernier nœud pour qu'il pointe vers le nouveau nœud
        current->next = newNode;
    }
}

// Fonction pour insérer un nœud après un nœud donné dans une liste chaînée
void insertNodeAfterNode(struct Node* prevNode, int data) {
    // Vérifier si le nœud précédent est NULL
    if (prevNode == NULL) {
        printf("Le nœud précédent ne peut pas être NULL.");
        return;
    }
    
    // Créer un nouveau nœud
    struct Node* newNode = createNode(data);
    
    // Mettre à jour le prochain pointeur du nouveau nœud pour qu'il pointe vers le nœud suivant
    newNode->next = prevNode->next;
    
    // Mettre à jour le prochain pointeur du nœud précédent pour qu'il pointe vers le nouveau nœud
    prevNode->next = newNode;
}

// Fonction pour supprimer un nœud donné d'une liste chaînée
void deleteNode(struct Node** head, int data) {
    // Stocker la tête de liste dans un nœud temporaire
    struct Node* temp = *head;
    
    // Cas particulier : si le nœud à supprimer est la tête de liste
    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Mettre à jour la tête de liste pour qu'elle pointe vers le nœud suivant
        free(temp);          // Libérer la mémoire du nœud supprimé
        return;
    }
    
    // Parcourir la liste jusqu'à trouver le nœud à supprimer
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;         // Garder une référence vers le nœud précédent
        temp = temp->next;   // Avancer vers le prochain nœud
    }
    
    // Si le nœud à supprimer n'existe pas dans la liste
    if (temp == NULL) {
        printf("Le nœud avec la donnée spécifiée n'existe pas dans la liste.");
        return;
    }
    
    // Mettre à jour le prochain pointeur du nœud précédent pour qu'il pointe vers le nœud suivant
    prev->next = temp->next;
    
    // Libérer la mémoire du nœud supprimé
    free(temp);
}

// Fonction pour afficher les éléments d'une liste chaînée
void displayList(struct Node* head) {
    struct Node* current = head;
    
    // Parcourir la liste et afficher chaque élément
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    printf("\n");
}

int main() {
    struct Node* head = NULL;  // Initialiser la tête de liste à NULL
    
    // Insérer des nœuds dans la liste chaînée
    insertNodeAtEnd(&head, 1);
    insertNodeAtEnd(&head, 2);
    insertNodeAtEnd(&head, 3);
    insertNodeAtBeginning(&head, 0);
    insertNodeAfterNode(head->next, 5);
    
    // Afficher la liste chaînée
    printf("Liste chaînée : ");
    displayList(head);
    
    // Supprimer un nœud de la liste chaînée
    deleteNode(&head, 2);
    
    // Afficher la liste chaînée après suppression
    printf("Liste chaînée après suppression : ");
    displayList(head);
    
    return 0;
}