template <typename T>
class UnqPtr {
    private:
        T* data;
    public:
        UnqPtr(T* p = nullptr): data(p) {}
        UnqPtr(const UnqPtr&) = delete;
        UnqPtr& operator=(const UnqPtr&) = delete;
        ~UnqPtr() {delete data;}

        T& operator*() const { return *data; }

        T* operator->() const { return data; }

        T* get() const {return data; }

        T* release() {
            T* tmp = data;
            data = nullptr;
            return tmp;
        }

        void reset(T* p = nullptr) {
            if (data != p) {
                delete data;
                data = p;
            }
        }
};