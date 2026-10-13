#ifndef UNQPTR_H 
#define UNQPTR_H

template <typename T>
class UnqPtr {
    private:
        T* data;
    public:
        UnqPtr(T* p = nullptr): data(p) {}
        UnqPtr(const UnqPtr&) = delete;
        UnqPtr& operator=(const UnqPtr&) = delete;
        UnqPtr(UnqPtr&& other) noexcept: data(other.data) {
            other.data = nullptr;
        }
        template <typename U>
        UnqPtr(UnqPtr<U>&& other) : data(dynamic_cast<T*>(other.release())) {}

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

template <typename T>
class UnqPtr<T[]> {
    private:
        T* data;
    public:
        UnqPtr(T* p = nullptr): data(p) {}
        UnqPtr(const UnqPtr&) = delete;
        UnqPtr& operator=(const UnqPtr&) = delete;
        UnqPtr(UnqPtr&& other) noexcept : data(other.data) {
            other.data = nullptr;
        }

        template <typename U>
        UnqPtr(UnqPtr<U>&& other) : data(dynamic_cast<T*>(other.release())) {}

        ~UnqPtr() {delete[] data;}

        T& operator*() const { return *data; }

        T* operator+(int num) const {
            return (data + num);
        }

        T& operator[](int num) const {
            return *(data + num);
        }

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

#endif