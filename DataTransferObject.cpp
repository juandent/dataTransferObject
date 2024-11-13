#include <iostream>

#include "BasicDTOClasses.h"
#include "StorageSchema.h"
#include "AssembledDTO.h"
#include "AssemblingLogic.h"


int main() {
    auto storage = initStorage("invoices.db");

    // Sync the schema to create tables if they don't exist
    storage.sync_schema();

    // Insert sample data (optional)
    Invoice invoice{ -1, "Alice Johnson", "2024-11-13" };
    int invoiceId = storage.insert(invoice);

    InvoiceLine line1{ -1, invoiceId, "Product A", 100.0 };
    InvoiceLine line2{ -1, invoiceId, "Product B", 200.0 };
    storage.insert(line1);
    storage.insert(line2);

    // Retrieve all assembled invoices
    auto assembledInvoices = getAllAssembledInvoices(storage);
    for (const auto& assembled : assembledInvoices) {
        std::cout << "Invoice ID: " << assembled.invoice.id
            << " Customer: " << assembled.invoice.customerName
            << " Date: " << assembled.invoice.date << "\n";

        for (const auto& line : assembled.lines) {
            std::cout << "  Line Description: " << line.description
                << " Amount: " << line.amount << "\n";
        }
    }

    return 0;
}
