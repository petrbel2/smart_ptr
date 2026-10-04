template <typename T>
class ArrayUnqPtr {
    private:
        T* data;
    public:
        ArrayUnqPtr(T* p = nullptr): data(p) {}
        ArrayUnqPtr(const ArrayUnqPtr&) = delete;
        ArrayUnqPtr& operator=(const ArrayUnqPtr&) = delete;
        ~ArrayUnqPtr() {delete[] data;}

        T& operator*() const { return *data; }

        T* operator->() const { return data; }

        T* get() const {return data; }

        T* release() {
            T* tmp = data;
            delete[] data;
            data = nullptr;
            return tmp;
        }

        void reset(T* p = nullptr) {
            if (data != p) {
                delete[] data;
                data = p;
            }
        }
};