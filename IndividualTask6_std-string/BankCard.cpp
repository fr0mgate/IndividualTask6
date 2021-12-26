#include "BankCard.h"

BankCard::BankCard(std::string holderName, std::string holderSurname,
                   std::string number, std::string validityPeriodMonth,
                   std::string validityPeriodYear)
    : holderName_(std::move(holderName))
    , holderSurname_(std::move(holderSurname))
    , number_(std::move(number))
    , validityPeriodMonth_(std::move(validityPeriodMonth))
    , validityPeriodYear_(std::move(validityPeriodYear))
{}

BankCard& BankCard::operator=(const BankCard& other)
{
    if (this != &other) {
        holderName_ = other.holderName_;
        holderSurname_ = other.holderSurname_;
        number_ = other.number_;
        validityPeriodMonth_ = other.validityPeriodMonth_;
        validityPeriodYear_ = other.validityPeriodYear_;
    }
    return *this;
}

void BankCard::setHolderName(const std::string& holderName)
{
    holderName_ = holderName;
}

std::string BankCard::getHolderName() const
{
    return holderName_;
}

void BankCard::setHolderSurname(const std::string& holderSurname)
{
    holderSurname_ = holderSurname;
}

[[nodiscard]] std::string BankCard::getHolderSurname() const
{
    return holderSurname_;
}

void BankCard::setNumber(const std::string& number)
{
    number_ = number;
}

[[nodiscard]] std::string BankCard::getNumber() const
{
    return number_;
}

[[nodiscard]] char BankCard::getFinancialInstitutionTypeID() const
{
    return number_[0];
}

void BankCard::setValidityPeriodMonth(const std::string& validityPeriodMonth)
{
    validityPeriodMonth_ = validityPeriodMonth;
}

[[nodiscard]] std::string BankCard::getValidityPeriodMonth() const
{
    return validityPeriodMonth_;
}

void BankCard::setValidityPeriodYear(const std::string& validityPeriodYear)
{
    validityPeriodYear_ = validityPeriodYear;
}

[[nodiscard]] std::string BankCard::getValidityPeriodYear() const
{
    return validityPeriodYear_;
}

std::ostream& operator<<(std::ostream& output, const BankCard& card)
{
    output << card.holderName_ << ' ' << card.holderSurname_ << ' ' << card.number_
           << ' ' << card.validityPeriodMonth_ << '/' << card.validityPeriodYear_;

    return output;
}

bool BankCard::operator==(const BankCard& other) const
{
    return holderName_ == other.holderName_
        && holderSurname_ == other.holderSurname_
        && number_ == other.number_
        && validityPeriodMonth_ == other.validityPeriodMonth_
        && validityPeriodYear_ == other.validityPeriodYear_;
}

bool BankCard::operator!=(const BankCard& other) const
{
    return !(holderName_ == other.holderName_
        && holderSurname_ == other.holderSurname_
        && number_ == other.number_
        && validityPeriodMonth_ == other.validityPeriodMonth_
        && validityPeriodYear_ == other.validityPeriodYear_);
}

bool BankCard::operator<(const BankCard& other) const
{
    if (holderName_ != other.holderName_)
        return holderName_ < other.holderName_;
    if (holderSurname_ != other.holderSurname_)
        return holderSurname_ < other.holderSurname_;
    if (number_ != other.number_)
        return number_ < other.number_;
    if (validityPeriodMonth_ != other.validityPeriodMonth_)
        return validityPeriodMonth_ < other.validityPeriodMonth_;
    else
        return validityPeriodYear_ < other.validityPeriodYear_;
}

bool BankCard::operator>(const BankCard& other) const
{
    if (holderName_ != other.holderName_)
        return holderName_ > other.holderName_;
    if (holderSurname_ != other.holderSurname_)
        return holderSurname_ > other.holderSurname_;
    if (number_ != other.number_)
        return number_ > other.number_;
    if (validityPeriodMonth_ != other.validityPeriodMonth_)
        return validityPeriodMonth_ > other.validityPeriodMonth_;
    else
        return validityPeriodYear_ > other.validityPeriodYear_;
}

bool BankCard::operator<=(const BankCard& other) const
{
    if (holderName_ != other.holderName_)
        return holderName_ < other.holderName_;
    if (holderSurname_ != other.holderSurname_)
        return holderSurname_ < other.holderSurname_;
    if (number_ != other.number_)
        return number_ < other.number_;
    if (validityPeriodMonth_ != other.validityPeriodMonth_)
        return validityPeriodMonth_ < other.validityPeriodMonth_;
    if (validityPeriodYear_ != other.validityPeriodYear_)
        return validityPeriodYear_ < other.validityPeriodYear_;
    return true;
}

bool BankCard::operator>=(const BankCard& other) const
{
    if (holderName_ != other.holderName_)
        return holderName_ > other.holderName_;
    if (holderSurname_ != other.holderSurname_)
        return holderSurname_ > other.holderSurname_;
    if (number_ != other.number_)
        return number_ > other.number_;
    if (validityPeriodMonth_ != other.validityPeriodMonth_)
        return validityPeriodMonth_ > other.validityPeriodMonth_;
    if (validityPeriodYear_ != other.validityPeriodYear_)
        return validityPeriodYear_ > other.validityPeriodYear_;
    return true;
}
