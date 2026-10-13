#ifndef SHAREDPTR_H 
#define SHAREDPTR_H

template <typename T>
class SharedPtr {
    private:
        int* count;
        T* data;
    public:
        SharedPtr(T* p = nullptr): data(p), count(new int(1)) {}
        SharedPtr(const SharedPtr& other) {
            data = other.data;
            count = other.count;
            (*count)++;
        }
        SharedPtr& operator=(const SharedPtr& other) {
            if (this != &other) {
                if (*(other.count) == 0) {
                    delete data;
                    delete count;
                }
                else {
                    (*count)--;
                    if (*count == 0) {
                        delete data;
                        delete count;
                    }
                    count = other.count;
                    data = other.data;
                    (*count)++;
                }
            }
            return *this;
        }

        template <typename U>
        SharedPtr(const SharedPtr<U>& other) : count(other.count), data(dynamic_cast<T*>(other.get())) {(*count)++;}

        ~SharedPtr() {
            (*count)--;
            if (*count == 0) {
                delete data;
                delete count;
            }
        }

        T& operator*() const { return *data; }

        T* operator->() const { return data; }

        T* get() const {return data; }
};

template <typename T>
class SharedPtr<T[]> {
    private:
        int* count;
        T* data;
    public:
        SharedPtr(T* p = nullptr): data(p), count(new int(1)) {}
        SharedPtr(const SharedPtr& other) {
            data = other.data;
            count = other.count;
            (*count)++;
        }
        SharedPtr& operator=(const SharedPtr& other) {
            if (this != &other) {
                if (*(other.count) == 0) {
                    delete[] data;
                    delete count;
                }
                else {
                    (*count)--;
                    if (*count == 0) {
                        delete[] data;
                        delete count;
                    }
                    count = other.count;
                    data = other.data;
                    (*count)++;
                }
            }
            return *this;
        }

        template <typename U>
        SharedPtr(const SharedPtr<U>& other) : count(other.count), data(dynamic_cast<T*>(other.get())) {(*count)++;}

        ~SharedPtr() {
            (*count)--;
            if (*count == 0) {
                delete[] data;
                delete count;
            }
        }

        T& operator*() const { return *data; }

        T* operator->() const { return data; }

        T* operator+(int num) const {
            return (data + num);
        }

        T& operator[](int num) const {
            return *(data + num);
        }

        T* get() const {return data; }
};

#endif