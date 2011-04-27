/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2011 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#ifndef BYTEFIELDSOURCE_H
#define BYTEFIELDSOURCE_H

#include "FieldCacheSource.h"

namespace Lucene
{
    /// Obtains byte field values from the {@link FieldCache} using getBytes() and makes those values available 
    /// as other numeric types, casting as needed.
    ///
    /// @see FieldCacheSource for requirements on the field.
    ///
    /// NOTE: with the switch in 2.9 to segment-based searching, if {@link #getValues} is invoked with a composite 
    /// (multi-segment) reader, this can easily cause double RAM usage for the values in the FieldCache.  It's
    /// best to switch your application to pass only atomic (single segment) readers to this API.
    class LPPAPI ByteFieldSource : public FieldCacheSource
    {
    public:
        /// Create a cached byte field source with a specific string-to-byte parser.
        ByteFieldSource(const String& field, ByteParserPtr parser = ByteParserPtr());
        virtual ~ByteFieldSource();
    
        LUCENE_CLASS(ByteFieldSource);
    
    protected:
        ByteParserPtr parser;
    
    public:
        virtual String description();
        virtual DocValuesPtr getCachedFieldValues(FieldCachePtr cache, const String& field, IndexReaderPtr reader);
        virtual bool cachedFieldSourceEquals(FieldCacheSourcePtr other);
        virtual int32_t cachedFieldSourceHashCode();
    };
}

#endif