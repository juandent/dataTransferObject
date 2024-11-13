#pragma once
#include <sqlite_orm/sqlite_orm.h>
#include <string>
#include <vector>

struct Invoice {
    int id;
    std::string customerName;
    std::string date;
};

struct InvoiceLine {
    int id;
    int invoiceId;  // Foreign key reference to Invoice
    std::string description;
    double amount;
};
