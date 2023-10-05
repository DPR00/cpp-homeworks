namespace ipb
{
    template <typename T>
    struct named_vector : public std::vector<T>
    {
        std::string name_;

        named_vector() : name_("") {}
        named_vector(const std::string &n) : name_(n) {}
        named_vector(const std::string &n, std::initializer_list<T> l) : name_(n), std::vector<T>(l) {}
        named_vector(const std::string &n, const std::vector<T> &elements) : name_(n), std::vector<T>(elements.begin(), elements.end()) {}

        inline std::string &name()
        {
            return name_;
        }

        inline std::vector<T> vector()
        {
            return *this;
        }

        inline bool empty()
        {
            return name_.empty() || std::vector<T>::empty();
        }

        inline std::size_t size()
        {
            return name_.size() + std::vector<T>::size();
        }

        inline std::size_t capacity()
        {
            return std::vector<T>::capacity();
        }

        void resize(std::size_t new_size)
        {
            if (new_size > std::vector<T>::size())
            {
                reserve(new_size);
                return std::vector<T>::resize(new_size);
            }
            else if (new_size < std::vector<T>::size())
            {
                if (new_size == 0)
                {
                    return std::vector<T>::resize(0);
                }
                return std::vector<T>::resize(new_size);
            }
        }

        void reserve(std::size_t new_capacity)
        {
            if (new_capacity > capacity())
            {
                return std::vector<T>::reserve(new_capacity);
            }
        }
    };
}
