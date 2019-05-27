/************************************************************************
 * Copyright(c) 2019, One Unified. All rights reserved.                 *
 * email: info@oneunified.net                                           *
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

/* 
 * File:    SpreadValidation.cpp
 * Author:  raymond@burkholder.net
 * Project: TFOptions
 * Created on May 27, 2019, 8:59 AM
 */

#include "SpreadValidation.h"

namespace ou {
namespace tf {

SpreadValidation::SpreadValidation( size_t nLegs ) {
  m_vSpreadCandidate.resize( nLegs );
}

void SpreadValidation::SetOption( size_t ixLeg, pWatch_t pCall ) {
  m_vSpreadCandidate[ ixLeg ].SetWatch( pCall );
}

SpreadValidation::pWatch_t SpreadValidation::GetOption( size_t ixLeg ) {
  //return boost::dynamic_pointer_cast<ou::tf::option::Option>( m_scCall.GetWatch() );
  return m_vSpreadCandidate[ ixLeg ].GetWatch();
}

bool SpreadValidation::IsActive() {
  bool bActive( true );
  for ( SpreadCandidate& candidate: m_vSpreadCandidate ) {
    bActive &= candidate.IsActive();
  }
  return bActive;
}

bool SpreadValidation::Validate( size_t nDuration ) {
  bool bValidation( true );
  for ( SpreadCandidate& candidate: m_vSpreadCandidate ) {
    bValidation &= candidate.ValidateSpread( nDuration );
  }
  return bValidation;
}

void SpreadValidation::ResetOptions() {
  for ( SpreadCandidate& candidate: m_vSpreadCandidate ) {
    candidate.Clear();
  }
}

} // namespace tf
} // namespace ou
