/////////////////////////////////////////////////////////////////////////////
// Name:        rdg.cpp
// Author:      Laurent Pugin
// Created:     2018
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#include "rdg.h"
#include "functorparams.h"
#include "page.h"
#include "pages.h"
#include "doc.h"
#include "system.h"
#include "pb.h"

//----------------------------------------------------------------------------

#include <assert.h>

//----------------------------------------------------------------------------

#include "vrv.h"

namespace vrv {

//----------------------------------------------------------------------------
// Rdg
//----------------------------------------------------------------------------

Rdg::Rdg() : EditorialElement("rdg-"), AttSource()
{
    RegisterAttClass(ATT_SOURCE);

    Reset();
}

Rdg::~Rdg() {}

void Rdg::Reset()
{
    EditorialElement::Reset();
    ResetSource();
}

//----------------------------------------------------------------------------
// functor methods
//----------------------------------------------------------------------------

int Rdg::CastOffEncoding(FunctorParams *functorParams)
{
    CastOffEncodingParams *params = dynamic_cast<CastOffEncodingParams *>(functorParams);
    assert(params);

    if (!m_children.empty()) {
        Pb *pb = dynamic_cast<Pb*>(*m_children.begin());
        if (pb) {
            pb->CastOffEncoding(functorParams);
        }
    }

    return FUNCTOR_SIBLINGS;
}

} // namespace vrv
