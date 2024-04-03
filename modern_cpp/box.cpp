

#include "box.h"
#include <iostream>
#include <utility>

using std::cout;
using std::endl;
using std::string;

std::ostream &operator<<(std::ostream &os, const Boxes &box) {
    os << "Box name: " << box.name_ << std::endl;
    return os;
}

Boxes::Boxes(const Boxes &other) {
    /* Deep copy constructor */
    this->serial_number_ = new int(*other.serial_number_);
    /* Shallow copy constructor */
    // this->serial_number_ = case.serial_number_;
    this->length_ = other.length_;
    this->width_ = other.width_;
    this->height_ = other.height_;
    this->name_ = other.name_;
    std::cout << "Copy constructor" << std::endl;
}

Boxes::Boxes(Boxes &&other) noexcept {
    this->serial_number_ = new int(*other.serial_number_);
    /* Shallow copy constructor */
    // this->serial_number_ = case.serial_number_;
    this->length_ = other.length_;
    this->width_ = other.width_;
    this->height_ = other.height_;
    this->name_ = other.name_;
    this->vec_ = std::move(other.vec_);
    std::cout << "Move constructor" << std::endl;
}

Boxes &Boxes::operator=(Boxes other) noexcept {
    this->serial_number_ = new int(*other.serial_number_);
    /* Shallow copy constructor */
    // this->serial_number_ = case.serial_number_;
    this->length_ = other.length_;
    this->width_ = other.width_;
    this->height_ = other.height_;
    this->name_ = other.name_;
    this->vec_ = std::move(other.vec_);
    std::cout << "Move assignment constructor" << std::endl;
    return *this;
}

void Boxes::message() {
    cout << "The name of box is: " << this->name_ << endl;
    cout << "The serial number of box is: " << *this->serial_number_ << endl;
    cout << "The length, width and height of the box are: " << endl;
    cout << this->length_ << "; " << this->width_ << "; " << this->height_ << endl;
}

string Boxes::get_name() {
    cout << "Box name from get_name() function: " << this->name_ << endl;
    return this->name_;
}

void Boxes::set_name(string name) { this->name_ = std::move(name); }

Boxes &Boxes::change_height_ref(int height) {
    this->height_ = height;
    return *this;
}

Boxes Boxes::change_height_copy(int height) {
    this->height_ = height;
    return *this;
}

int Boxes::get_box_volume() {
    this->volume_ = this->length_ * this->width_ * this->height_;
    cout << "This box volume is: " << this->volume_ << endl;
    return this->volume_;
}

void Boxes::size_message() {
    cout << "The length, width and height of the box are: " << endl;
    cout << this->length_ << "; " << this->width_ << "; " << this->height_ << endl;
    cout << "This box volume is: " << this->volume_ << endl;
}


void Boxes::add_item(const std::string &item) {
    this->vec_.push_back(item);
}

void Boxes::print_all_contents() {
    for (const auto &item: vec_) {
        cout << item << " ";
    }
    cout << endl;
}

Boxes::~Boxes() {
    cout << "IN DESTRUCTOR" << endl;
    this->serial_number_ = nullptr;
    delete this->serial_number_;
}