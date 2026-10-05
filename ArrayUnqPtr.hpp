template <typename T>
class ArrayUnqPtr {
    private:
        T* data;
        int length;
    public:
        ArrayUnqPtr(T* p = nullptr, int l = 1): data(p), length(l) {}
        ArrayUnqPtr(const ArrayUnqPtr&) = delete;
        ArrayUnqPtr& operator=(const ArrayUnqPtr&) = delete;
        ArrayUnqPtr(ArrayUnqPtr&& other) noexcept : data(other.data) {
            other.data = nullptr;
        }
        ~ArrayUnqPtr() {delete[] data;}

        T& operator*() const { return *data; }

        T* operator+(int num) const {return (data + num);}

        T& operator[](int num) const {return *(data + num);}

        T* operator->() const { return data; }

        T* get() const {return data; }

        T* release() {
            T* tmp = data;
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