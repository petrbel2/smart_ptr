template <typename T>
class SharedPtr {
    private:
        int* count;
        T data;
    public:
        SharedPtr(T* p = nullptr): data(p) {}
        ~SharedPtr() {
            (*count)--;
            if (*count == 0) {
                delete data;
            }
        }

        T operator*() { return *data; }

        T operator->() { return data; }

        T get() {return data; }
};