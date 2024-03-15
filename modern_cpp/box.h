

#ifndef BOX_H_
#define BOX_H_

#include <string>
#include <ostream>
#include <iostream>
#include <vector>

class Boxx
{
    friend std::ostream& operator<<(std::ostream& os, const Boxx&);

public:
    int* serial_number_;
    int length_{};
    int width_;
    int height_;
    bool is_good_;
    std::string color_;

    int volume = 0;
    std::vector<std::string> vec_;

    Boxx(std::string name, int serial_number, int length, int width, int height, bool is_good,
         std::string color)
        : name_(name),
          serial_number_(new int(serial_number)),
          length_(length),
          width_(width),
          height_(height),
          is_good_(is_good),
          color_(color)
    {
        std::cout << "Customer initialization list constructor all" << std::endl;
    }
    Boxx(std::string name, int serial_number, int length, int width, int height, bool is_good)
        : Boxx(name, serial_number, length, width, height, is_good, "red")
    {
    }
    Boxx(std::string name, int length, int width, int height)
        : Boxx(name, length, width, height, true, "red")
    {
        std::cout << "Customer initialization list constructor optional" << std::endl;
    }

    /* copy constructor */
    Boxx(const Boxx& other);

    /* move constructor */
    Boxx(Boxx&& other) noexcept;

    /* move assignment constructor */
    Boxx& operator=(Boxx& other) noexcept;

    virtual void message();
    std::string get_name();
    void set_name(std::string name);

    Boxx& change_length_ref(int length);
    Boxx& change_width_ref(int width);
    Boxx& change_height_ref(int height);

    Boxx change_length_copy(int length);
    Boxx change_width_copy(int width);
    Boxx change_height_copy(int height);

    int get_box_volume();
    void size_message();
    void add_item(std::string);
    void print_all_contents();
    ~Boxx();

private:
    std::string name_;
};

#endif // BOX_H_