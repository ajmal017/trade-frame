/************************************************************************
 * Copyright(c) 2013, One Unified. All rights reserved.                 *
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

#include "stdafx.h"

#include "EventProviderConnected.h"

wxDEFINE_EVENT(EVENT_PROVIDER_CONNECTED, EventProviderConnected);

EventProviderConnected::EventProviderConnected( wxEventType eventType, int winid, pProvider_t pProvider ) 
  : wxEvent( winid, eventType ), m_pProvider( pProvider )
{
}

EventProviderConnected::~EventProviderConnected(void) {
}
