#include "String.h"
#include <utility>

String::String()
{
    charsVector_.pushBack('\0');
}

String::String(String&& other) noexcept
    : charsVector_(std::move(other.charsVector_))
{}

String::String(const char* charsArray)
{
    size_t i = 0;
    while (charsArray[i] != '\0') {
        charsVector_.pushBack(charsArray[i]);
        i++;
    }
    charsVector_.pushBack('\0');
}

String& String::operator=(const String& other)
{
    if (this != &other)
        charsVector_ = other.charsVector_;
    return *this;
}

String& String::operator=(String&& other) noexcept
{
    charsVector_ = std::move(other.charsVector_);
    return *this;
}

String& String::operator=(const char* charsArray)
{
    size_t i = 0;
    while (charsArray[i] != '\0') {
        charsVector_.pushBack(charsArray[i]);
        i++;
    }
    charsVector_.pushBack('\0');
    return *this;
}

[[nodiscard]] size_t String::length() const
{
    return charsVector_.size() - 1;
}

[[nodiscard]] bool String::empty() const
{
    return charsVector_.size() == 1;
}

void String::pushBack(char element)
{
    charsVector_.popBack();
    charsVector_.pushBack(element);
    charsVector_.pushBack('\0');
}

void String::clear()
{
    charsVector_.clear();
    charsVector_.pushBack('\0');
}

const char* String::getCharsArray()
{
    return charsVector_.getArrayLink();
}

String String::substr(size_t beginIndex, size_t endIndex)
{
    String subString;
    for (size_t i = beginIndex; i < endIndex; i++)
        subString.pushBack(charsVector_[i]);
    return subString;
}

Vector<String> String::split(char divider)
{
    Vector<String> stringsList;
    String temp;
    for (size_t i = 0; i < length(); i++) {
        if (charsVector_[i] == divider) {
            if (!temp.empty()) {
                stringsList.pushBack(temp);
                temp.clear();
            }
        }
        else
            temp.pushBack(charsVector_[i]);
    }
    if (!temp.empty())
        stringsList.pushBack(temp);
    return stringsList;
}

Vector<String> String::split(const String& dividers)
{
    Vector<String> stringsList;
    String temp;
    bool isDivider = false;
    for (size_t i = 0; i < length(); i++) {
        for (size_t j = 0; j < dividers.length(); j++) {
            if (charsVector_[i] == dividers[j]) {
                isDivider = true;
                if (!temp.empty()) {
                    stringsList.pushBack(temp);
                    temp.clear();
                }
                break;
            }
        }
        if (!isDivider)
            temp.pushBack(charsVector_[i]);
        isDivider = false;
    }
    if (!temp.empty())
        stringsList.pushBack(temp);
    return stringsList;
}

char& String::operator[](size_t index)
{
    return charsVector_[index];
}

char& String::operator[](size_t index) const
{
    return charsVector_[index];
}

std::istream& operator>>(std::istream& input, String& string)
{
    string.clear();
    char* temp = new char[String::LIMIT];
    input.get(temp, String::LIMIT);
    if (input) {
        size_t i = 0;
        while (temp[i] != '\0') {
            string.pushBack(temp[i]);
            i++;
        }
    }
    while (input && input.get() != '\n')
        continue;
    return input;
}

std::ostream& operator<<(std::ostream& output, const String& string)
{
    for (size_t i = 0; i < string.charsVector_.size(); i++)
        output << string.charsVector_[i];
    return output;
}

bool String::operator==(const String& other) const
{
    return charsVector_ == other.charsVector_;
}

bool String::operator!=(const String& other) const
{
    return charsVector_ != other.charsVector_;
}

bool String::operator<(const String& other) const
{
    return charsVector_ < other.charsVector_;
}

bool String::operator>(const String& other) const
{
    return charsVector_ > other.charsVector_;
}

bool String::operator<=(const String& other) const
{
    return charsVector_ <= other.charsVector_;
}

bool String::operator>=(const String& other) const
{
    return charsVector_ >= other.charsVector_;
}
