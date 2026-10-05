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
                    }
                    count = other.count;
                    data = other.data;
                    (*count)++;
                }
            }
            return *this;
        }

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