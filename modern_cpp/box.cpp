

#include "box.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

std::ostream& operator<<(std::ostream& os, const Boxx& box)
{
    os << "Box name: " << box.name_ << std::endl;
    return os;
}

Boxx::Boxx(const Boxx& other)
{
    /* Deep copy constructor */
    this->serial_number_ = new int(*other.serial_number_);
    /* Shallow copy constructor */
    // this->serial_number_ = case.serial_number_;
    this->length_ = other.length_;
    this->width_ = other.width_;
    this->height_ = other.height_;
    this->is_good_ = other.is_good_;
    this->color_ = other.color_;
    this->name_ = other.name_;
    std::cout << "Copy constructor" << std::endl;
}

Boxx::Boxx(Boxx&& other) noexcept
{
    this->serial_number_ = new int(*other.serial_number_);
    /* Shallow copy constructor */
    // this->serial_number_ = case.serial_number_;
    this->length_ = other.length_;
    this->width_ = other.width_;
    this->height_ = other.height_;
    this->is_good_ = other.is_good_;
    this->color_ = other.color_;
    this->name_ = other.name_;
    this->vec_ = std::move(other.vec_);
    std::cout << "Move constructor" << std::endl;
}

Boxx& Boxx::operator=(Boxx& other) noexcept
{
    this->serial_number_ = new int(*other.serial_number_);
    /* Shallow copy constructor */
    // this->serial_number_ = case.serial_number_;
    this->length_ = other.length_;
    this->width_ = other.width_;
    this->height_ = other.height_;
    this->is_good_ = other.is_good_;
    this->color_ = other.color_;
    this->name_ = other.name_;
    this->vec_ = std::move(other.vec_);
    std::cout << "Move assignment constructor" << std::endl;
    return *this;
}

void Boxx::message()
{
    cout << "The name of box is: " << this->name_ << endl;
    cout << "The serial number of box is: " << *this->serial_number_ << endl;
    cout << "The box is good: " << this->is_good_ << endl;
    cout << "The length, width and height of the box are: " << endl;
    cout << this->length_ << "; " << this->width_ << "; " << this->height_ << endl;
    cout << "The color of box is: " << this->color_ << endl;
}

string Boxx::get_name()
{
    cout << "Box name from get_name() function: " << this->name_ << endl;
    return this->name_;
}

void Boxx::set_name(string name) { this->name_ = name; }

Boxx& Boxx::change_length_ref(int length)
{
    this->length_ = length;
    return *this;
}

Boxx& Boxx::change_width_ref(int width)
{
    this->width_ = width;
    return *this;
}

Boxx& Boxx::change_height_ref(int height)
{
    this->height_ = height;
    return *this;
}

Boxx Boxx::change_length_copy(int length)
{
    this->length_ = length;
    return *this;
}

Boxx Boxx::change_width_copy(int width)
{
    this->width_ = width;
    return *this;
}

Boxx Boxx::change_height_copy(int height)
{
    this->height_ = height;
    return *this;
}

int Boxx::get_box_volume()
{
    this->volume = this->length_ * this->width_ * this->height_;
    cout << "This box volume is: " << volume << endl;
    return this->volume;
}

void Boxx::size_message()
{
    cout << "The length, width and height of the box are: " << endl;
    cout << this->length_ << "; " << this->width_ << "; " << this->height_ << endl;
    cout << "This box volume is: " << volume << endl;
}

Boxx::~Boxx()
{
    cout << "IN DESTRUCTOR" << endl;
    this->serial_number_ = nullptr;
    delete this->serial_number_;
}