#ifndef INDIVIDUALTASK6_BANKCARD_H
#define INDIVIDUALTASK6_BANKCARD_H

#include <ostream>
#include <string>

class BankCard
{
public:
    BankCard() = default;
    BankCard(std::string, std::string, std::string,
             std::string, std::string);
    BankCard& operator=(const BankCard&);

    void setHolderName(const std::string&);
    [[nodiscard]] std::string getHolderName() const;
    void setHolderSurname(const std::string&);
    [[nodiscard]] std::string getHolderSurname() const;

    void setNumber(const std::string&);
    [[nodiscard]] std::string getNumber() const;
    [[nodiscard]] char getFinancialInstitutionTypeID() const;

    void setValidityPeriodMonth(const std::string&);
    [[nodiscard]] std::string getValidityPeriodMonth() const;
    void setValidityPeriodYear(const std::string&);
    [[nodiscard]] std::string getValidityPeriodYear() const;

    friend std::ostream& operator<<(std::ostream&, const BankCard&);
    bool operator==(const BankCard&) const;
    bool operator!=(const BankCard&) const;
    bool operator<(const BankCard&) const;
    bool operator>(const BankCard&) const;
    bool operator<=(const BankCard&) const;
    bool operator>=(const BankCard&) const;

private:
    std::string holderSurname_;
    std::string holderName_;
    std::string number_;
    std::string validityPeriodMonth_;
    std::string validityPeriodYear_;
};

#endif // INDIVIDUALTASK6_BANKCARD_H
