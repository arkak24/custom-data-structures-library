#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

namespace custom {

      template <typename T>
            class Vector{
                  private:
                        T* data;
                        std::size_t no_of_current_elements; // sz
                        std::size_t curr_capacity; // cap

                  public:
                        Vector(){
                              no_of_current_elements = 0;
                              curr_capacity = 5;
                              data = new T[curr_capacity];
                        };

                        Vector(const T& original_vec){
                              no_of_current_elements = original_vec.no_of_current_elements;
                              curr_capacity = original_vec.curr_capacity;
                              data = new T[curr_capacity];
                              for(std::size_t i = 0; i < no_of_current_elements; i++){
                                    data[i] = original_vec.data[i];
                              }
                        }

                        Vector& operator=(const Vector& original_vec){
                              if(this != &original_vec){    // 'this' point to the curent object
                                    delete[] data;
                                    no_of_current_elements = original_vec.no_of_current_elements;
                                    curr_capacity = original_vec.curr_capacity;
                                    data = new T[curr_capacity];
                                    for(std::size_t i = 0; i < no_of_current_elements; i++){
                                          data[i] = original_vec.data[i];
                                    }
                              }
                              return *this;
                        }

                        ~Vector(){
                              delete[] data;
                        };

                        void push_back(const T& value){
                              if(no_of_current_elements == curr_capacity){
                                    std::size_t new_capacity = curr_capacity*2;
                                    T* new_data = new T[new_capacity];
                                    for(std::size_t i = 0; i < no_of_current_elements; i++){
                                          new_data[i] = data[i];
                                    }
                                    delete[] data;
                                    data = new_data;
                                    curr_capacity = new_capacity;
                              }
                              data[no_of_current_elements] = value;
                              no_of_current_elements += 1;
                        };

                        void pop_back(){
                              if(no_of_current_elements > 0){
                                    no_of_current_elements -= 1;
                              }
                        };

                        T& operator[](std::size_t index){
                              return data[index];
                        };

                        const T& operator[](std::size_t index) const{
                              return data[index];
                        };

                        std::size_t size() const{
                              return no_of_current_elements;
                        };

                        std::size_t capacity() const{
                              return curr_capacity;
                        };

                        bool is_empty() const{
                              if(no_of_current_elements == 0){
                                    return true;
                              }
                              else{
                                    return false;
                              }
                        };
                        
                        // use the iterator like while accessing
                        // for(auto it : arr.begin(); it != arr.end(); ++it){}
                        T* begin(){       // returns the address of the first index element
                              return data;
                        }

                        T* end(){         // returns the address of the last index element
                              return (data + no_of_current_elements);
                        }

                        const T* begin() const{
                              return data;
                        }

                        const T* end() const{
                              return (data + no_of_current_elements);
                        }
            };
}

#endif
