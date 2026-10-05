template <typename T>
class ArraySharedPtr {
    private:
        int* count;
        T* data;
        int* length;
    public:
        ArraySharedPtr(T* p = nullptr, int l = 1): data(p), count(new int(1)), length(new int(1)) {}
        ArraySharedPtr(const ArraySharedPtr& other) {
            data = other.data;
            count = other.count;
            length = other.length;
            (*count)++;
        }
        ArraySharedPtr& operator=(const ArraySharedPtr& other) {
            if (this != &other) {
                if (*(other.count) == 0) {
                    delete[] data;
                    delete count;
                }
                else {
                    (*count)--;
                    if (*count == 0) {
                        delete[] data;
                        delete length;
                        delete count;
                    }
                    count = other.count;
                    data = other.data;
                    length = other.length;
                    (*count)++;
                }
            }
            return *this;
        }

        ~ArraySharedPtr() {
            (*count)--;
            if (*count == 0) {
                delete[] data;
                delete length;
                delete count;
            }
        }

        T& operator*() const { return *data; }

        T* operator->() const { return data; }

        T* operator+(int num) const {return (data + num);}

        T& operator[](int num) const {return *(data + num);}

        T* get() const {return data; }
};