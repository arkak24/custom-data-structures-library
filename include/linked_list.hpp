#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace custom {
      
      template<typename T>
      struct Node{
            T data;
            Node<T>* next;

            Node(const T& val){
                  data = val;
                  next = nullptr;
            }
      };
      
      template<typename T>
      class LinkedList{
            private:
                  Node<T>* head;
                  Node<T>* tail;    // for fast push_back
                  std::size_t current_size;

            public:
                  LinkedList(){
                        head = nullptr;
                        tail = nullptr;
                        current_size = 0;
                  }
                  ~LinkedList(){
                        Node<T>* current = head;
                        while(current != nullptr){
                              current = current -> next;
                              delete head;
                              head = current;
                        }
                  }

                  void push_back(const T& val){
                        Node<T>* temp = new Node<T>(val);
                        if(head == nullptr){
                              head = temp;
                              tail = temp;
                        }
                        else{
                              tail -> next = temp;
                              tail = temp;
                        }
                        current_size += 1;
                  }
                  void push_front(const T& val){
                        Node<T>* temp = new Node<T>(val);
                        if(head == nullptr){
                              head = temp;
                              tail = temp;
                        }
                        else{
                              temp -> next = head;
                              head = temp;
                        }
                        current_size += 1;
                  }
                  void pop_back(){
                        if(tail == nullptr){
                              std::cout << "No elements in the list!" << std::endl;
                              return;
                        }
                        Node<T>* temp_var = nullptr;
                        if(head -> next == nullptr){
                              temp_var = head;
                              head = nullptr;
                              tail = nullptr;
                              delete temp_var;
                        }
                        else{
                              temp_var = head;
                              while(temp_var -> next -> next != nullptr){
                                    temp_var = temp_var -> next;
                              }
                              tail = temp_var;
                              delete tail -> next;
                              tail -> next = nullptr;
                        }
                        current_size -= 1;
                  }
                  void pop_front(){
                        if(head == nullptr) std::cout << "No elements in the list!" << std::endl;
                        else if(head -> next == nullptr){
                              Node<T>* temp_var = head;
                              head = head -> next;
                              tail = nullptr;
                              delete temp_var;
                              current_size -= 1;
                        }
                        else{
                              Node<T>* temp_var = head;
                              head = head -> next;
                              delete temp_var;
                              current_size -= 1;
                        }
                  }
                  T& front(){
                        if(head == nullptr) throw std::runtime_error("List is empty!\n");
                        else return head -> data;
                  }
                  T& back(){
                        if(head == nullptr) throw std::runtime_error("List is empty!\n");
                        else return tail -> data;
                  }
                  std::size_t size() const{
                        return current_size;
                  }
                  bool empty() const{
                        if(head == nullptr) return true;
                        else return false;
                  }
                  void print_list() const{
                        if(head == nullptr) std::cout << "No elements in the list!" << std::endl;
                        else{
                              Node<T>* itr = head;
                              while(itr != nullptr){
                                    std::cout << itr -> data << "\t";
                                    itr = itr -> next;
                              }
                              std::cout << "\n";
                        }
                  }

                  void insert(const T& val, std::size_t position){
                        if(head == nullptr){
                              if(position == 1){
                                    head = new Node<T>(val);
                                    tail = head;
                              }
                              else{
                                    std::cout << "Invalid position!" << std::endl;
                              }
                              current_size += 1;
                        }
                        else{
                              Node<T>* temp_var = nullptr;
                              if(position == 1){
                                    temp_var = head;
                                    head = new Node<T>(val);
                                    head -> next = temp_var;
                              }
                              else if(position == current_size+1){
                                    temp_var = new Node<T>(val);
                                    tail -> next = temp_var;
                                    tail = temp_var;
                              }
                              else if(position > current_size+1){
                                    std::cout << "Invalid position!" << std::endl;
                                    return;
                              }
                              else{
                                    temp_var = head;
                                    for(int i = 1; i <= position-2; i++){
                                          temp_var = temp_var -> next;
                                    }
                                    Node<T>* new_node = new Node<T>(val);
                                    new_node -> next = temp_var -> next;
                                    temp_var -> next = new_node;
                              }
                              current_size += 1;
                        }
                  }
                  void remove(std::size_t position){
                        Node<T>* temp_var = nullptr;
                        if(head == nullptr){
                              std::cout << "List Empty!" << std::endl;
                              return;
                        }
                        if(position == 1){
                              temp_var = head;
                              head = head -> next;
                              if(current_size == 1) tail = head;
                              delete temp_var;
                        }
                        else if(position > current_size){
                              std::cout << "Invalid position!" << std::endl;
                              return;
                        }
                        else{
                              temp_var = head;
                              for(int i = 1; i <= position-2; i++){
                                    temp_var = temp_var -> next;
                              }
                              Node<T>* del_node = temp_var -> next;
                              temp_var -> next = temp_var -> next -> next;
                              delete del_node;
                              if(position == current_size){
                                    tail = temp_var;
                              }
                        }
                        current_size -= 1;
                  }
                  Node<T>* find(const T& val){  // return the address with the val(first occurence)
                        if(head == nullptr) return nullptr;
                        Node<T>* temp_var = head;
                        while(temp_var != nullptr){
                              if(temp_var -> data == val){
                                    return temp_var;
                              }
                        }
                        return nullptr;
                  }
      };
}

#endif
