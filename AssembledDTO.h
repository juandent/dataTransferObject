#pragma once
#include "BasicDTOClasses.h"

struct AssembledInvoice {
    Invoice invoice;  // The main invoice
    std::vector<InvoiceLine> lines;  // All lines associated with this invoice
};
