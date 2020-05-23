#ifndef SDDS_NUMBERSBOX_H__
#define SDDS_NUMBERSBOX_H__
#include <cstring>
using namespace std;
namespace sdds {
template <typename T>
class NumbersBox{
    char name[16];
    int size = 0;
    T* items;
public:
    NumbersBox(){
         name[0] = '\0';
         size = 0;
        items = nullptr;
    }
   NumbersBox(int bSize, const char* bName){
        if (bSize > 0) {
            items = new T[bSize];
            size = bSize;
            strcpy(name, bName);
        } else {
            name[0] = '\0';
                    size = 0;
                   items = nullptr;
        }
        }
    ~NumbersBox(){
        delete [] items;
    }
    

    T& operator[](int i){
        return items[i];
    }
    
    NumbersBox<T>& operator*=(const NumbersBox<T>& other){
        if (this->size == other.size) {
            for (int i = 0; i < size; i++) {
                this->items[i]*=other.items[i];
            }
        }
        
        return *this;
    }
    

    NumbersBox<T>& operator+=(T num){
        T* temp = nullptr;
        temp = new T[size + 1];
        
        for (int i = 0; i < size; i++) {
            temp[i] = this->items[i];
        }
         
        temp[size] = num;

        delete [] this->items;
        items = nullptr;
        items = new T[size+1];
        
        for (int i = 0; i < size+1; i++) {
           this->items[i] = temp[i];
        }
        size++;
        delete [] temp;
        temp=nullptr;
        
        return *this;
    }
    
    ostream& display(ostream& os) const{
        int count = 0;
        if (name[0] == '\0' || size == 0 || items == nullptr) {
            os << "Empty Box" << endl;
        } else {
            os << "Box name: ";
            os << name << endl;
            for (int i = 0; i < size; i++) {
                os << items[i];
                ++count;
                if (size != count) {
                    os << ", ";
                }
            }
            os << endl;
        }
    return os;
    }

   friend ostream& operator<<(ostream& os, NumbersBox<T>& box){
        box.display(os);
        return os;
    }
};

}

#endif /* NumberBox_h */
