#ifndef INDIVIDUALTASK6_BANKCARD_H
#define INDIVIDUALTASK6_BANKCARD_H

#include <ostream>
#include "String.h"

class BankCard
{
public:
    BankCard() = default;
    BankCard(String, String , String,
             String, String);
    BankCard& operator=(const BankCard&);

    void setHolderName(const String&);
    [[nodiscard]] String getHolderName() const;
    void setHolderSurname(const String&);
    [[nodiscard]] String getHolderSurname() const;

    void setNumber(const String&);
    [[nodiscard]] String getNumber() const;
    [[nodiscard]] char getFinancialInstitutionTypeID() const;

    void setValidityPeriodMonth(const String&);
    [[nodiscard]] String getValidityPeriodMonth() const;
    void setValidityPeriodYear(const String&);
    [[nodiscard]] String getValidityPeriodYear() const;

    friend std::ostream& operator<<(std::ostream&, const BankCard&);
    bool operator==(const BankCard&) const;
    bool operator!=(const BankCard&) const;
    bool operator<(const BankCard&) const;
    bool operator>(const BankCard&) const;
    bool operator<=(const BankCard&) const;
    bool operator>=(const BankCard&) const;

private:
    String holderSurname_;
    String holderName_;
    String number_;
    String validityPeriodMonth_;
    String validityPeriodYear_;
};

#endif // INDIVIDUALTASK6_BANKCARD_H
