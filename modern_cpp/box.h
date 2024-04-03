

#ifndef BOX_H_
#define BOX_H_

#include <string>
#include <ostream>
#include <iostream>
#include <utility>
#include <vector>

class Boxes {
    friend std::ostream &operator<<(std::ostream &os, const Boxes &);

public:
    int *serial_number_;
    int length_;
    int width_;
    int height_;

    int volume_ = 0;
    std::vector<std::string> vec_;

    /* why is the string name should use the std::move? */
    Boxes(std::string name, int serial_number, int length, int width, int height)
            : name_(std::move(name)),
              serial_number_(new int(serial_number)),
              length_(length),
              width_(width),
              height_(height) {
        std::cout << "Customer initialization list constructor all" << std::endl;
    }

    Boxes(std::string name, int serial_number)
            : Boxes(std::move(name), serial_number, 1, 1, 1) {
    }

    /* copy constructor */
    Boxes(const Boxes &other);

    /* move constructor */
    Boxes(Boxes &&other) noexcept;

    /* move assignment constructor */
    Boxes &operator=(Boxes other) noexcept;

    Boxes &operator+(const Boxes &other) {
        std::cout << "in operator+: " << std::endl;
        this->height_ += other.height_;
        return *this;
    }

    bool operator==(const Boxes &other) const {
        // std::cout << "in operator== " << std::endl;
        return (this->volume_ == other.volume_);
    }

    bool operator!=(const Boxes &other) const {
        std::cout << "in operator!= " << std::endl;
        return this->volume_ != other.volume_;
    }

    Boxes &operator++() // prefix
    {
        this->height_ += 1;
        std::cout << "prefix current height is " << this->height_ << std::endl;
        return *this;
    }

    Boxes operator++(int) // postfix
    {
        this->height_ += 1;
        std::cout << "postfix current height is " << this->height_ << std::endl;
        return *this;
    }


    int *operator->() const {
        std::cout << "in operator->" << std::endl;
        return this->serial_number_;
    }

    int operator()() {
        std::cout << "in int operator()()" << std::endl;
        return (this->height_ + 1);
    }

    int operator()(int a) const {
        std::cout << "in int operator()(int a)" << std::endl;
        return (this->height_ + a);
    }

    std::string operator()(int a, int b) const {
        std::cout << "in string operator()(int a, int b)" << std::endl;
        int res = (this->height_ + a + b);
        return std::to_string(res);
    }


    virtual void message();

    std::string get_name();

    void set_name(std::string name);

    Boxes &change_height_ref(int height);

    Boxes change_height_copy(int height);

    int get_box_volume();

    void size_message();

    void add_item(const std::string &);

    void print_all_contents();

    ~Boxes();

private:
    std::string name_;
};

#endif // BOX_H_