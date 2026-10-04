template <typename T>
class ArraySharedPtr {
    private:
        int* count;
        T* data;
    public:
        ArraySharedPtr(T* p = nullptr): data(p), count(new int(1)) {}
        ArraySharedPtr(const ArraySharedPtr& other) {
            data = other.data;
            count = other.count;
            (*count)++;
        }
        ArraySharedPtr* operator=(const ArraySharedPtr& other) {
            if (this != &other) {
                if (other.count == 0) {
                    delete[] data;
                    delete count;
                }
                else {
                    count = other.count;
                    data = other.data;
                    (*count)++;
                }
            }
            return *this;
        }

        ~ArraySharedPtr() {
            (*count)--;
            if (*count == 0) {
                delete[] data;
                delete count;
            }
        }

        T& operator*() const { return *data; }

        T* operator->() const { return data; }

        T* get() const {return data; }
};