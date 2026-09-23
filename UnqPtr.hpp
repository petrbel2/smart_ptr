template <typename T>
class UnqPtr {
    private:
        T* data;
    public:
        UnqPtr(T* p = nullptr): data(p) {}
        ~UnqPtr() {delete data;}

        T operator*() { return *data; }

        T operator->() { return data; }

        T get() {return data; }
};