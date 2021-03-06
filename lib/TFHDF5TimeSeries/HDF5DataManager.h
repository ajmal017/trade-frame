/************************************************************************
 * Copyright(c) 2009, One Unified. All rights reserved.                 *
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

#pragma once

// changed to lower case 2015/02/08
#include <hdf5/H5Cpp.h>

#include <boost/function.hpp>

namespace ou { // One Unified
namespace tf { // TradeFrame

class HDF5DataManager {
public:
  enum enumFileOptionType{ RDWR, RO };
  HDF5DataManager( enumFileOptionType );
  ~HDF5DataManager(void);
  H5::H5File *GetH5File( void ) { return &m_H5File; };
  bool GroupExists( const std::string &sGroup );
  void AddGroup( const std::string &sGroupPath );  // last group needs trailing '/'
  void AddGroupForSymbol( const std::string &sSymbol );
  static herr_t PrintH5ErrorStackItem( int n, H5E_error_t *err_desc, void *client_data );
//  static hsize_t H5ChunkSize( void ) { return 1024; };  // # elements to be shuffled/compressed in one block,  was 64
//  static hsize_t H5ChunkSize( void ) { return 32; };  // # elements to be shuffled/compressed in one block,  was 64
  static void DailyBarPath( const std::string &sSymbol, std::string &sPath );
  void Flush( void );

  typedef boost::function<void (const std::string& )> callbackIteratePath_t;
  void IteratePathParts( const std::string& sPath, callbackIteratePath_t object );
protected:
  static const char m_H5FileName[];
//  static unsigned int m_RefCount;
//  static H5::H5File m_H5File;
  H5::H5File m_H5File;
private:
};

} // namespace tf
} // namespace ou


/*
If you are only writing to very small datasets, then the default 
chunk cache size (1 MB) is most likely large enough, since this limit 
is applied to each dataset individually.  However, if you are regularly 
rewriting/reading the same portions of the dataset, and it can grow beyond 
1 MB then you may see a benefit  from increasing the cache size.  

Depending on your chunk size, you may also want to increase the number of 
elements in the chunk cache from the default 521 (make sure it stays a prime number).  
Be careful about having too many datasets open at once though, as the limit is 1 MB 
for each dataset.  So if you have several million datasets open  you potentially 
have several million megabytes of cache.

The chunk size should align as closely as possible to your typcial selection for 
writing (or reading).  This minimizes the amount of costly scattering as well as 
wasted space in the cache.  However you should not set it too small, in order to avoid excessive overhead.

Thanks,
-Neil Fortner
Neil Fortner [nfortne2@hdfgroup.org]
*/
