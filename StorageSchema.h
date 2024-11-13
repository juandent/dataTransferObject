#pragma once
#include "BasicDTOClasses.h"
#include "../../../latest/sqlite_orm/include/sqlite_orm/sqlite_orm.h"

using namespace sqlite_orm;

auto initStorage(const std::string& dbPath) {
    using namespace sqlite_orm;

    return make_storage(
        dbPath,

        // Define the Invoice table
        make_table("Invoices",
            make_column("id", &Invoice::id, primary_key().autoincrement()),
            make_column("customerName", &Invoice::customerName),
            make_column("date", &Invoice::date)
        ),

        // Define the InvoiceLine table with a foreign key reference to Invoice
        make_table("InvoiceLines",
            make_column("id", &InvoiceLine::id, primary_key().autoincrement()),
            make_column("invoiceId", &InvoiceLine::invoiceId),
            make_column("description", &InvoiceLine::description),
            make_column("amount", &InvoiceLine::amount),
            foreign_key(&InvoiceLine::invoiceId).references(&Invoice::id)
        )
    );
}
