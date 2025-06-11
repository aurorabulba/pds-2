#include <iostream>
#include "list.hpp"

void List::insertNode(int data) {
  Node* aux = new Node;
  aux->data = data;
  aux->next = nullptr;
  if (head == nullptr) {
    head = aux;
    tail = aux;
  } else {
    tail->next = aux;
    tail = aux;
  }
}

void List::display() {
  Node *aux = head;
  while (aux != nullptr) {
    cout << aux->data << " ";
    aux = aux->next;
  }
  cout << endl;
}

// Você deverá implementar apenas esse método
void List::inverte() {
  Node* anterior = nullptr;
  Node* atual = head;
  Node* prox = nullptr;

  tail = head; // O antigo head se tornará o tail

  while (atual != nullptr) {
    prox = atual->next;   // Salva o próximo
    atual->next = anterior;   // Inverte o ponteiro
    anterior = atual;         // Move o prev adiante
    atual = prox;         // Move o current adiante
  }

  head = anterior; // O novo head será o último nó visitado
}


