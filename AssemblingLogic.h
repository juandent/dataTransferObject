#pragma once

#include <vector>
#include "AssembledDTO.h"
#include "StorageSchema.h"

std::vector<AssembledInvoice> getAllAssembledInvoices(decltype(initStorage(""))& storage) {
    std::vector<AssembledInvoice> result;

    // Query all invoices
    auto invoices = storage.get_all<Invoice>();
    for (const auto& inv : invoices) {
        AssembledInvoice assembled;
        assembled.invoice = inv;

        // Query all lines related to the current invoice
        assembled.lines = storage.get_all<InvoiceLine>(where(c(&InvoiceLine::invoiceId) == inv.id));

        result.push_back(std::move(assembled));
    }

    return result;
}

std::optional<AssembledInvoice> getAssembledInvoice(decltype(initStorage(""))& storage, int id)
{
    auto invoice = storage.get_optional<Invoice>(where(c(&Invoice::id) == id));
    if(invoice)
    {
        AssembledInvoice assinv;
        assinv.invoice = *invoice;
        assinv.lines = storage.get_all<InvoiceLine>(where(c(&InvoiceLine::invoiceId) == id));
        return assinv;
    }
    return std::nullopt;
}
