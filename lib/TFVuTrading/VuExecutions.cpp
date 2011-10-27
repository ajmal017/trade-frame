/************************************************************************
 * Copyright(c) 2011, One Unified. All rights reserved.                 *
 *                                                                      *
 * This file is provided as is WITHOUT ANY WARRANTY                     *
 *  without even the implied warranty of                                *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                *
 *                                                                      *
 * This software may not be used nor distributed without proper license *
 * agreement.                                                           *
 *                                                                      *
 * See the file LICENSE.txt for redistribution information.             *
 ************************************************************************/

#include "StdAfx.h"

#include "VuExecutions.h"


VuExecutions::VuExecutions(void): VuBase() {
  Construct();
}

VuExecutions::VuExecutions( wxWindow *parent, wxWindowID id, 
    const wxPoint &pos, const wxSize &size, long style, const wxValidator &validator )
  : VuBase( parent, id, pos, size, style, validator ) {
    Construct();
}

VuExecutions::~VuExecutions(void) {
}

void VuExecutions::Construct( void ) {
        
  m_pdvmdlExecutions = new dvmdlExecutions_t;
  AssociateModel( m_pdvmdlExecutions.get() );

  structPopulateColumns f( this );
  m_pdvmdlExecutions.get()->IterateColumnNames( f );

}