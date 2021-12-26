#ifndef INDIVIDUALTASK6_STRING_H
#define INDIVIDUALTASK6_STRING_H

#include <istream>
#include <ostream>
#include <cstddef>
#include "Vector.h"

class String
{
public:
    String() = default;
    String(const String&) = default;
    String(String&&) noexcept;
    explicit String(const char*);
    String& operator=(const String&);
    String& operator=(String&&) noexcept;
    String& operator=(const char*);

    [[nodiscard]] size_t length() const;
    [[nodiscard]] bool empty() const;
    void pushBack(char);
    void clear();
    const char* getCharsArray();
    String substr(size_t, size_t);
    Vector<String> split(char = ' ');
    Vector<String> split(const String&);

    char& operator[](size_t);
    char& operator[](size_t) const;
    friend std::istream& operator>>(std::istream&, String&);
    friend std::ostream& operator<<(std::ostream&, const String&);
    bool operator==(const String&) const;
    bool operator!=(const String&) const;
    bool operator<(const String&) const;
    bool operator>(const String&) const;
    bool operator<=(const String&) const;
    bool operator>=(const String&) const;

private:
    Vector<char> charsVector_;
    static const size_t LIMIT = 80;
};

#endif // INDIVIDUALTASK6_STRING_H
